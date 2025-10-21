#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LIGNES 256

int main()
{
    char lignes[MAX_LIGNES];
    char **exemple=NULL;
    int i=0;
    FILE *fp = fopen("exercice3.txt", "r");

    if (fp == NULL)
    {
        printf("Le fichier test.txt n'a pas pu être ouvert\n");
        return EXIT_FAILURE;
    }
    while (fgets(lignes, sizeof(lignes),fp)!=NULL) 
    {
        i++;
        exemple = realloc(exemple, i * sizeof(char*));
        exemple[i-1] = malloc(strlen(lignes) + 1);
        strcpy(exemple[i-1], lignes);

    }

    for (int j =0; j < i; j++) 
    {
        printf("%s", exemple[j]);
        free(exemple[j]);
    }

    free(exemple);
    fclose(fp);
    return 0;
}
