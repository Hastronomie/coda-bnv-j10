#include <stdlib.h>
#include <stdio.h>

int main()
{
    FILE *fp = fopen("exercice5.txt", "a+");
    char **tab = malloc(3 * sizeof(*tab));
    tab[0] = "Goodnight\n";
    tab[1] = "And thanks !\n";
    tab[2] = "For all the fish!\n";

    if (fp == NULL)
    {
        printf("Le fichier texte.txt n'a pas pu être ouvert\n");
        return EXIT_FAILURE;
    }
    for (int i = 0; i < 3; i++) 
    {
        fprintf(fp, "%s", tab[i]);
    }

    fclose(fp); // vraiment bien penser à fermer sinon les autres programmes peuvent pas use
    return 0;

    exit(0);
}
