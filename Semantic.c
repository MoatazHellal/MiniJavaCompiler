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
} Type_Identifier;

typedef enum
{
    variable,
    fonction,
    parametre,
    class,
} Class;

struct NOEUD
{
    char *nom;
    Type_Identifier type;
    Class class;
    int isInit;
    int isUsed;
    int nbParam;
    int line;
    Type_Identifier *paramsTypes;
    struct NOEUD *suivant;
};

Type_Identifier type, typeAffect;
typedef struct NOEUD *NOEUD;
typedef NOEUD TABLE_NOEUD;

TABLE_NOEUD table_global, table_local, actual_local, actual_global, table_total;

NOEUD noeudFonc, noeudClass, noeudFonctionCall;

char *fix;

int inFonctionCall = 0;
int isLocal = 0;
int inParameters;

void DisplaySymbolsTable(TABLE_NOEUD SymbolsTable)
{
    if (!SymbolsTable)
        return;
    NOEUD Node = SymbolsTable;
    while (Node)
    {
        switch (Node->type)
        {
        case tInt:
            printf("int ");
            break;

        case tBoolean:
            printf("boolean ");
            break;

        case tString:
            printf("string ");
            break;

        case tVoid:
            printf("void ");
            break;

        case tOther:
            switch (Node->class)
            {
            case class:
                printf("class ");
                break;

            default:
                break;
            }
            break;

        default:
            printf("unknown ");
        }

        switch (Node->class)
        {
        case variable:
            printf("variable ");
            break;

        case parametre:
            printf("parametre ");
            break;

        case fonction:
            printf("fonction ");
            break;
        case class:
            printf("class ");
            break;
        default:
            break;
        }

        if (Node->class == fonction)
        {
            for (int i = 0; i < Node->nbParam; i++)
            {
                Type_Identifier paramType = Node->paramsTypes[i];
                switch (paramType)
                {
                case tInt:
                    printf("int ");
                    break;

                case tBoolean:
                    printf("boolean ");
                    break;

                case tString:
                    printf("string ");
                    break;

                case tVoid:
                    printf("void ");
                    break;

                case tOther:
                    switch (Node->class)
                    {
                    case class:
                        printf("other ");
                        break;

                    default:
                        break;
                    }
                    break;

                default:
                    printf("Unknown ");
                }
            }
        }

        printf("%s %d %d %d", Node->nom, Node->isUsed, Node->isInit, Node->nbParam);
        printf("\n");

        Node = Node->suivant;
    }
}

char *concat(const char *s1, char *s2)
{
    char *message;
    message = malloc(strlen(s1) + strlen(s2) + 2);
    strcpy(message, s1);
    strcat(message, s2);
    return message;
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

NOEUD creer(const char *nom, Type_Identifier type, Class class, NOEUD suivant, int line)
{
    NOEUD noeud = (NOEUD)malloc(sizeof(struct NOEUD));
    noeud->nom = (char *)malloc(strlen(nom) + 2);
    strcpy(noeud->nom, nom);
    noeud->type = type;
    noeud->isUsed = 0;
    noeud->isInit = 0;
    noeud->class = class;
    if (class == fonction)
    {
        noeud->nbParam = 0;
        noeud->paramsTypes = malloc(1 * sizeof(Type_Identifier));
    }
    noeud->line = line;
    noeud->suivant = suivant;
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
        while (last->suivant)
        {
            last = last->suivant;
        }
        last->suivant = noeud;
        return table;
    }
}

NOEUD chercher(const char *nom, TABLE_NOEUD table)
{
    if (!table)
    {
        return NULL;
    }
    NOEUD noeud = table;
    while (noeud)
    {
        if ((strcmp(nom, noeud->nom)) == 0)
        {
            return noeud;
        }
        noeud = noeud->suivant;
    }
    return NULL;
}

NOEUD chercher2(const char *nom, TABLE_NOEUD table, int line)
{
    if (!table)
    {
        return NULL;
    }
    NOEUD noeud = table;
    NOEUD tmp = NULL;
    while (noeud)
    {
        if ((strcmp(nom, noeud->nom)) == 0)
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
        noeud = noeud->suivant;
    }
    return tmp;
}

NOEUD chercherWithLine(const char *nom, TABLE_NOEUD table, int line)
{
    if (!table)
    {
        return NULL;
    }
    NOEUD noeud = table;
    while (noeud)
    {
        if ((strcmp(nom, noeud->nom) == 0 && line == noeud->line))
        {
            return noeud;
        }
        noeud = noeud->suivant;
    }
    return NULL;
}

int getAddress(const char *nom, TABLE_NOEUD table)
{
    if (!table)
    {
        return -1;
    }
    NOEUD noeud = table;
    int pos = 0;
    while (noeud)
    {
        if (strcmp(nom, noeud->nom) == 0)
        {
            return pos;
        }
        pos++;
        noeud = noeud->suivant;
    }
    return -1;
}

void destructSymbolsTable(TABLE_NOEUD table)
{
    if (!table)
    {
        return;
    }

    NOEUD noeud = table;
    while (noeud)
    {
        free(noeud->nom);
        free(noeud);
        noeud = noeud->suivant;
    }
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

void fonctionCallStart(char *nom, Type_Identifier type, int line)
{
    inFonctionCall = 1;
    noeudFonctionCall = creer(nom, type, fonction, NULL, line);
}

void fonctionCallParameter(Type_Identifier type, char *nom, int line)
{
    if (inFonctionCall == 0)
        return;
    if (nom != NULL)
    {
        NOEUD n = chercher(nom, table_local);
        if (!n)
        {
            n = chercher(nom, table_global);
        }
        if (!n)
        {
            semanticError("la fonction n'existe pas", line);
            return;
        }
        noeudFonctionCall->paramsTypes = realloc(noeudFonctionCall->paramsTypes, (noeudFonctionCall->nbParam + 1) * sizeof(Type_Identifier));
        noeudFonctionCall->paramsTypes[noeudFonctionCall->nbParam] = n->type;
        noeudFonctionCall->nbParam++;
    }
    else
    {
        noeudFonctionCall->paramsTypes = realloc(noeudFonctionCall->paramsTypes, (noeudFonctionCall->nbParam + 1) * sizeof(Type_Identifier));
        noeudFonctionCall->paramsTypes[noeudFonctionCall->nbParam] = type;
        noeudFonctionCall->nbParam++;
    }
}

void initVar(char *nom, int line)
{
    NOEUD noeud;
    if (isLocal)
    {
        noeud = chercher2(nom, table_local, line);
        if (!noeud)
        {
            noeud = chercher2(nom, table_global, line);
        }
    }
    else
    {
        noeud = chercher2(nom, table_global, line);
    }

    noeud->isInit = 1;
    NOEUD n2 = chercherWithLine(nom, table_total, noeud->line);
    n2->isInit = 1;
}

void useVar(char *nom)
{
    NOEUD noeud;
    if (isLocal)
    {
        noeud = chercher(nom, table_local);
        if (!noeud)
        {
            noeud = chercher(nom, table_global);
        }
    }
    else
    {
        noeud = chercher(nom, table_global);
    }
    noeud->isUsed = 1;
    NOEUD n2 = chercherWithLine(nom, table_total, noeud->line);
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

void checkIdentifier(char *nom, Type_Identifier type, Class classe, int line)
{
    int found = 0;
    if (isLocal == 0)
    {
        if (chercher(nom, actual_global))
        {
            found = 1;
            semanticError(concat("Identifier already defined: ", nom), line);
            return;
        }
    }
    else
    {
        if (chercher(nom, actual_local))
        {
            found = 1;
            semanticError(concat("Identifier already defined: ", nom), line);
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
                noeudFonc->paramsTypes = realloc(noeudFonc->paramsTypes, (noeudFonc->nbParam + 1) * sizeof(Type_Identifier));
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
            n = creer(nom, type, classe, NULL, line);
            n2 = creer(nom, type, classe, NULL, line);
            n3 = creer(nom, type, classe, NULL, line);
        }
        else if (classe == fonction)
        {
            n = creer(nom, type, classe, NULL, line);
            n2 = creer(nom, type, classe, NULL, line);
            n3 = creer(nom, type, classe, NULL, line);
            noeudFonc = n;
            isLocal = 1;
        }
        else if (classe == class)
        {
            n = creer(nom, tOther, classe, NULL, line);
            n2 = creer(nom, tOther, classe, NULL, line);
            n3 = creer(nom, tOther, classe, NULL, line);
            noeudClass = n;
        }
        else if (classe == parametre)
        {
            n = creer(nom, type, classe, NULL, line);
            n2 = creer(nom, type, classe, NULL, line);
            n3 = creer(nom, type, classe, NULL, line);
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

void verifierVarDeclared(char *nom, int line)
{
    NOEUD noeud;
    noeud = chercher(nom, actual_local);
    if (!noeud)
        noeud = chercher(nom, actual_global);
    if (!noeud)
    {
        semanticError(concat("variable not declared: ", nom), line);
    }
}

void verifierVarInitialise(char *nom, int line)
{
    NOEUD noeud;
    if (isLocal)
    {
        noeud = chercher(nom, table_local);
        if (!noeud)
        {
            noeud = chercher(nom, table_global);
        }
    }
    else
    {
        noeud = chercher(nom, table_global);
    }
    if (noeud && noeud->class == variable && !noeud->isInit)
    {
        if (noeud->type == tInt || noeud->type == tBoolean)
        {
            semanticWarning(concat("variable not initialised: ", nom), line);
        }
        else
        {
            semanticError(concat("variable not initialised: ", nom), line);
        }
    }
}

void verifierVarDeclaredIsUsed(char *nom, NOEUD table, int line)
{
    NOEUD noeud;
    noeud = chercherWithLine(nom, table, line);
    if (noeud && noeud->class == variable && !noeud->isUsed)
        semanticWarning(concat("variable not used: ", nom), line);
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
            verifierVarDeclaredIsUsed(table->nom, table, table->line);
        }
        table = table->suivant;
    }
}

void verifierFonctionArguments(int line)
{
    inFonctionCall = 0;
    NOEUD n = chercher(noeudFonctionCall->nom, table_local);
    if (!n)
    {
        n = chercher(noeudFonctionCall->nom, table_global);
    }
    if (!n)
    {
        semanticError(concat("Function not defined yet: ", noeudFonctionCall->nom), line);
        return;
    }
    if (noeudFonctionCall->nom != "main")
    {
        if (n->nbParam != noeudFonctionCall->nbParam)
        {
            semanticError(concat("Parameters number not correct: ", n->nom), line);
            return;
        }
        for (int i = 0; i < n->nbParam; i++)
        {
            if (n->paramsTypes[i] != noeudFonctionCall->paramsTypes[i])
                semanticError(concat("Parameter have wrong type: ", n->nom), line);
        }
    }
}

void verifierTypeAffectation(char *nom, Type_Identifier type, int line)
{
    NOEUD n = chercher(nom, actual_local);
    if (!n)
    {
        NOEUD n = chercher(nom, actual_global);
    }
    if (n)
    {
        if (n->type != type)
            semanticError(concat("Affected value type is wrong : ", nom), line);
    }
}