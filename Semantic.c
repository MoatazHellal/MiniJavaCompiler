#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef enum
{
    tInt,
    tBoolean,
    tVoid,
    tString,
    tOther
} Type_ID;

typedef enum
{
    variable,
    fonction,
    parametre,
    class,
} Class;

struct NOEUD
{
    char *name;
    Type_ID type;
    Class class;
    int isInit;
    int isUsed;
    int nbParam;
    int line;
    Type_ID *paramsTypes;
    struct NOEUD *next;
};

Type_ID type, typeAffect;
typedef struct NOEUD *NOEUD;
typedef NOEUD TABLE_NOEUD;

TABLE_NOEUD table_global, table_local, actual_local, actual_global, table_total;

NOEUD noeudFonc, noeudClass, noeudFonctionCall;

int isLocal = 0;
int inFonctionCall = 0;
int inParameters;
char *fix;

char *concat(const char *s1, char *s2)
{
    char *str;
    str = malloc(strlen(s1) + strlen(s2) + 2);
    strcpy(str, s1);
    strcat(str, s2);
    return str;
}

void semanticError(char *msg, int line)
{
    if (line == 0)
    {
        fprintf(stderr, "Error : %s\n", msg);
    }
    else
    {
        fprintf(stderr, "Error : %s in line %d\n", msg, line);
    }
    exit(0);
}

void semanticWarning(char *msg, int line)
{
    if (line == 0)
    {
        fprintf(stderr, "Warning : %s\n", msg);
    }
    else
    {
        fprintf(stderr, "Warning : %s in line %d\n", msg, line);
    }
}

NOEUD create(const char *name, Type_ID type, Class class, NOEUD next, int line)
{
    NOEUD noeud = (NOEUD)malloc(sizeof(struct NOEUD));
    noeud->name = (char *)malloc(strlen(name) + 2);
    strcpy(noeud->name, name);
    noeud->type = type;
    noeud->isUsed = 0;
    noeud->isInit = 0;
    noeud->class = class;
    if (class == fonction)
    {
        noeud->nbParam = 0;
        noeud->paramsTypes = malloc(1 * sizeof(Type_ID));
    }
    noeud->line = line;
    noeud->next = next;
    return noeud;
}

NOEUD insert(NOEUD noeud, TABLE_NOEUD table)
{
    if (!table)
    {
        return noeud;
    }
    else
    {
        NOEUD last = table;
        while (last->next)
        {
            last = last->next;
        }
        last->next = noeud;
        return table;
    }
}

NOEUD search(const char *name, TABLE_NOEUD table)
{
    if (!table)
    {
        return NULL;
    }
    NOEUD noeud = table;
    while (noeud)
    {
        if ((strcmp(name, noeud->name)) == 0)
        {
            return noeud;
        }
        noeud = noeud->next;
    }
    return NULL;
}

NOEUD searchWithTemp(const char *name, TABLE_NOEUD table, int line)
{
    if (!table)
    {
        return NULL;
    }
    NOEUD noeud = table;
    NOEUD tmp = NULL;
    while (noeud)
    {
        if ((strcmp(name, noeud->name)) == 0)
        {
            if (!tmp)
            {
                tmp = noeud;
            }
            else if (line - tmp->line > line - noeud->line)
            {
                tmp = noeud;
            }
        }
        noeud = noeud->next;
    }
    return tmp;
}

NOEUD searchWithLine(const char *name, TABLE_NOEUD table, int line)
{
    if (!table)
    {
        return NULL;
    }
    NOEUD noeud = table;
    while (noeud)
    {
        if ((strcmp(name, noeud->name) == 0 && line == noeud->line))
        {
            return noeud;
        }
        noeud = noeud->next;
    }
    return NULL;
}

int getAddress(const char *name, TABLE_NOEUD table)
{
    if (!table)
    {
        return -1;
    }
    NOEUD noeud = table;
    int pos = 0;
    while (noeud)
    {
        if (strcmp(name, noeud->name) == 0)
        {
            return pos;
        }
        pos++;
        noeud = noeud->next;
    }
    return -1;
}

void fonctionEnd()
{
    isLocal = 0;
    noeudFonc = NULL;
    actual_local = NULL;
}

void classEnd()
{
    noeudClass = NULL;
    actual_global = NULL;
}

void fonctionCallStart(char *name, Type_ID type, int line)
{
    inFonctionCall = 1;
    noeudFonctionCall = create(name, type, fonction, NULL, line);
}

void fonctionCallParameter(Type_ID type, char *name, int line)
{
    if (inFonctionCall == 0)
        return;
    if (name != NULL)
    {
        NOEUD n = search(name, table_local);
        if (!n)
        {
            n = search(name, table_global);
        }
        
        noeudFonctionCall->paramsTypes = realloc(noeudFonctionCall->paramsTypes, (noeudFonctionCall->nbParam + 1) * sizeof(Type_ID));
        noeudFonctionCall->paramsTypes[noeudFonctionCall->nbParam] = n->type;
        noeudFonctionCall->nbParam++;
    }
    else
    {
        noeudFonctionCall->paramsTypes = realloc(noeudFonctionCall->paramsTypes, (noeudFonctionCall->nbParam + 1) * sizeof(Type_ID));
        noeudFonctionCall->paramsTypes[noeudFonctionCall->nbParam] = type;
        noeudFonctionCall->nbParam++;
    }
}

void initVar(char *name, int line)
{
    NOEUD noeud;
    if (isLocal)
    {
        noeud = searchWithTemp(name, table_local, line);
        if (!noeud)
        {
            noeud = searchWithTemp(name, table_global, line);
        }
    }
    else
    {
        noeud = searchWithTemp(name, table_global, line);
    }

    noeud->isInit = 1;
    NOEUD n2 = searchWithLine(name, table_total, noeud->line);
    n2->isInit = 1;
}

void useVar(char *name)
{
    NOEUD noeud;
    if (isLocal)
    {
        noeud = search(name, table_local);
        if (!noeud)
        {
            noeud = search(name, table_global);
        }
    }
    else
    {
        noeud = search(name, table_global);
    }
    noeud->isUsed = 1;
    NOEUD n2 = searchWithLine(name, table_total, noeud->line);
    n2->isUsed = 1;
}

void inParam()
{
    inParameters = 1;
}

void outParam()
{
    inParameters = 0;
}

void checkID(char *name, Type_ID type, Class classe, int line)
{
    int found = 0;
    if (isLocal == 0)
    {
        if (search(name, actual_global))
        {
            found = 1;
            semanticError(concat("ID already defined: ", name), line);
            return;
        }
    }
    else
    {
        if (search(name, actual_local))
        {
            found = 1;
            semanticError(concat("ID already defined: ", name), line);
            return;
        }
    }
    NOEUD n = NULL;
    NOEUD n2 = NULL;
    NOEUD n3 = NULL;
    if (found == 0)
    {
        if (classe == variable)
        {
            if (inParameters == 1)
            {
                classe = parametre;
                noeudFonc->paramsTypes = realloc(noeudFonc->paramsTypes, (noeudFonc->nbParam + 1) * sizeof(Type_ID));
                if (noeudFonc->nbParam)
                {
                    noeudFonc->paramsTypes[noeudFonc->nbParam] = type;
                    noeudFonc->nbParam++;
                }
                else
                {
                    noeudFonc->paramsTypes[noeudFonc->nbParam] = type;
                    noeudFonc->nbParam = 1;
                }
            }
            n = create(name, type, classe, NULL, line);
            n2 = create(name, type, classe, NULL, line);
            n3 = create(name, type, classe, NULL, line);
        }
        else if (classe == fonction)
        {
            n = create(name, type, classe, NULL, line);
            n2 = create(name, type, classe, NULL, line);
            n3 = create(name, type, classe, NULL, line);
            noeudFonc = n;
            isLocal = 1;
        }
        else if (classe == class)
        {
            n = create(name, tOther, classe, NULL, line);
            n2 = create(name, tOther, classe, NULL, line);
            n3 = create(name, tOther, classe, NULL, line);
            noeudClass = n;
        }
        else if (classe == parametre)
        {
            n = create(name, type, classe, NULL, line);
            n2 = create(name, type, classe, NULL, line);
            n3 = create(name, type, classe, NULL, line);
            if (noeudFonc->nbParam)
            {
                noeudFonc->nbParam++;
            }
            else
            {
                noeudFonc->nbParam = 1;
            }
        }
    }
    if (isLocal == 0)
    {
        table_global = insert(n, table_global);
        actual_global = insert(n2, actual_global);
        table_total = insert(n3, table_total);
    }
    else
    {
        table_local = insert(n, table_local);
        actual_local = insert(n2, actual_local);
        table_total = insert(n3, table_total);
    }
}

void CheckDeclared(char *name, int line)
{
    NOEUD noeud;
    noeud = search(name, actual_local);
    if (!noeud)
        noeud = search(name, actual_global);
    if (!noeud)
    {
        semanticError(concat("variable not declared: ", name), line);
    }
}

void CheckInitialise(char *name, int line)
{
    NOEUD noeud;
    if (isLocal)
    {
        noeud = search(name, table_local);
        if (!noeud)
        {
            noeud = search(name, table_global);
        }
    }
    else
    {
        noeud = search(name, table_global);
    }
    if (noeud && noeud->class == variable && !noeud->isInit)
    {
        if (noeud->type == tInt || noeud->type == tBoolean)
        {
            semanticWarning(concat("variable not initialised: ", name), line);
        }
        else
        {
            semanticError(concat("variable not initialised: ", name), line);
        }
    }
}

void CheckDeclaredIsUsed(char *name, NOEUD table, int line)
{
    NOEUD noeud;
    noeud = searchWithLine(name, table, line);
    if (noeud && noeud->class == variable && !noeud->isUsed)
        semanticWarning(concat("variable not used: ", name), line);
}

void endProgram()
{
    if (!table_total)
        return;
    TABLE_NOEUD table = table_total;
    while (table)
    {
        if (table->class == variable)
        {
            CheckDeclaredIsUsed(table->name, table, table->line);
        }
        table = table->next;
    }
}

void CheckFunctionParams(int line)
{
    inFonctionCall = 0;
    NOEUD n = search(noeudFonctionCall->name, table_local);
    if (!n)
    {
        n = search(noeudFonctionCall->name, table_global);
    }
    if (!n)
    {
        semanticError(concat("Function not defined yet: ", noeudFonctionCall->name), line);
        return;
    }
    if (noeudFonctionCall->name != "main")
    {
        if (n->nbParam != noeudFonctionCall->nbParam)
        {
            semanticError(concat("Parameters number not correct: ", n->name), line);
            return;
        }
        for (int i = 0; i < n->nbParam; i++)
        {
            if (n->paramsTypes[i] != noeudFonctionCall->paramsTypes[i])
                semanticError(concat("Parameter have wrong type: ", n->name), line);
        }
    }
}

void CheckAffectation(char *name, Type_ID type, int line)
{
    NOEUD n = search(name, actual_local);
    if (!n)
    {
        NOEUD n = search(name, actual_global);
    }
    if (n)
    {
        if (n->type != type)
            semanticError(concat("Affected value type is wrong : ", name), line);
    }
}