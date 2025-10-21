#include <stdlib.h>
#include <stdio.h>
#include "h.h"
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
    FILE * fp = fopen("exercice4.txt", "r");
    char * file_content; // obligatoire pour afficher
    user user;

    if (fp == NULL)
    {
        printf("Le fichier test.txt n'a pas pu être ouvert\n");
        return EXIT_FAILURE;
    }

    file_content = get_file(fp); //ne pas changer ou retier, c'est que ça permet d'écrire
    sscanf(file_content, "Prénom: %ms\nNom: %ms\nAge:%d",&user.first_name, &user.last_name, &user.age);
    printf("Je suis %s %s et j'ai %d ans", user.first_name, user.last_name, user.age);

    free(file_content);
    free(user.first_name);
    free(user.last_name);
    fclose(fp);
    return 0;
}