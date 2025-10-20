#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char * get_file(FILE * fp)
{
    char * content;
    char buffer[10];

    content = malloc(sizeof(char));
    content[0] = '\0';

    while(fgets(buffer, 10, fp) != NULL) //lire tous les caractères pointés par fp jusqu'à épuisement, 10 par 10
    {
        content = realloc(content, (strlen(buffer) * sizeof(char)) + strlen(content) * sizeof(char)); //realloc réajoute 10 à chaque tours de la mémoire 
        content = strcat(content, buffer); //on va coller content à buffer
    }

    return content;
}

int main()
{
    FILE *fp = fopen("exercice1.txt", "r");
    char * file_content;

    if (fp == NULL)
    {
        printf("Le fichier test.txt n'a pas pu être ouvert\n");
        return EXIT_FAILURE;
    }

    file_content = get_file(fp);

    printf("%s\n", file_content);

    fclose(fp);
    return 0;
}

