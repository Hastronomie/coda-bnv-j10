#include <stdlib.h>
#include <stdio.h>
#include "h.h"

int main()
{
    FILE *fp = fopen("exercice6.txt", "a+");
    struct s_movie titanic;
    titanic.title = "Titanic";
    titanic.director = "James Cameron";
    titanic.year = 1997;

    if (fp == NULL)
    {
        printf("Le fichier texte.txt n'a pas pu être ouvert\n");
        return EXIT_FAILURE;
    }

    fprintf(fp, "Le film %s a pour réal' %s et date de %d\n", titanic.title, titanic.director, titanic.year);

    fclose(fp); // vraiment bien penser à fermer sinon les autres programmes peuvent pas use
    return 0;
    exit(0);
}
