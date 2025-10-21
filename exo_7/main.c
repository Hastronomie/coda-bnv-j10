#include <stdlib.h>
#include <stdio.h>

int main()
{
    FILE *fp = fopen("exercice7.txt", "a+");
    char * mouton = ",---@>\n W-W'\n";

    if (fp == NULL)
    {
        printf("Le fichier texte.txt n'a pas pu être ouvert\n");
        return EXIT_FAILURE;
    }

    fprintf(fp, "%s\n", mouton);

    fclose(fp); // vraiment bien penser à fermer sinon les autres programmes peuvent pas use
    return 0;
    exit(0);
}

