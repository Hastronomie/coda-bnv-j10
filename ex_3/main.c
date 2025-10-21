#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    FILE *fp = fopen("exercice3.txt", "r");

    if (fp == NULL)
    {
        printf("Le fichier test.txt n'a pas pu être ouvert\n");
        return EXIT_FAILURE;
    }
    int i=0;
    int c;
    char lignes[256];
    int ligne = 0;



    while ((c = getc(fp)) != EOF)
    {
        if (c == '\n')
        {
            ligne++;
        }
    }
    rewind(fp);
    char **exemple=malloc(ligne *sizeof(char *));
    printf("%d\n", ligne);
    // while (fgets(lignes, sizeof(lignes),fp)!=NULL) 
    // {
    //     exemple = malloc(ligne * sizeof(char*));
    //     exemple[i-1] = malloc(strlen(lignes) + 1);
    //     // char **tmp = realloc(exemple, (i + 1) * sizeof(char *));
    //     strcpy(exemple[i], lignes);     
    //     i++;
    // }
        char buffer[256];
        while (fgets(buffer, sizeof(buffer), fp) && i < ligne) 
        {
        exemple[i] = malloc(strlen(buffer) + 1);
            if (!exemple[i]) 
            {
                perror("Erreur d'allocation");
                break;
            }
        strcpy(exemple[i], buffer);
        i++;
        }
    printf("%d",i);    
    int j= i;
    fclose(fp);

    for (int i=0 ; i < j; i++) 
    {
        printf("%s\n", exemple[i]);
        free(exemple[i]);
    }

    free(exemple);
  
    return 0;
}