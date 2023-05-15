#include "stdio.h"
#include <stdlib.h>
#include <string.h>

typedef struct ENTREE_CODE
{
    char *code_op;
    int operande;
    char nom_fonc[256];
} ENTREE_CODE;

int indextab;
ENTREE_CODE tabCodeInt[5000];

ENTREE_CODE creerCode(const char *code, int op, char *nom_fonc)
{
    ENTREE_CODE entree;
    entree.code_op = (char *)malloc(strlen(code) + 2);
    strcpy(entree.code_op, code);
    if (nom_fonc != NULL)
    {
        strcpy(entree.nom_fonc, nom_fonc);
    }
    entree.operande = op;
    return entree;
}

int getFonctionLine(const char *nom_fonc)
{
    if (!tabCodeInt)
        return -1;
    for (int i = 0; i < indextab; i++)
    {
        if (tabCodeInt[i].nom_fonc != NULL && tabCodeInt[i].operande == -1 && strcmp(tabCodeInt[i].code_op, "ENTREE") == 0)
        {
            if (strcmp(tabCodeInt[i].nom_fonc, nom_fonc) == 0)
            {
                return i;
            }
        }
    }
    return -1;
}

void genererCode()
{
    FILE *file = fopen("E:\\GnuWin32\\bin\\Generator.txt","w");
    for (int f = 0; f < indextab; f++)
    {
        fprintf(file, "%s ", tabCodeInt[f].code_op);
        if (tabCodeInt[f].operande != -1)
            fprintf(file, "%d ", tabCodeInt[f].operande);
        fprintf(file, "\n");
    }
    fclose(file);
}