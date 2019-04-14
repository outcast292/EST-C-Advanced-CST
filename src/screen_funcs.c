#include "../inc/job_funcs.h"
#include "../inc/structure.h"
#include "../inc/screen_funcs.h"
#include "../inc/pc_funcs.h"
#include "../inc/job_funcs.h"
#include <stdio.h>
#include <stdlib.h>

void menu(file *f)
{
    init_file(f);
    fil(f);
    int n;
    printf("\n\n==============================MENU=======================\n"
           "\n\n1-ajouter un/des nouveau article"
           "\n2-afficher tout les article"
           "\n3-afficher les article d'une categorie specifié"
           "\n4-rechercher un article par son numero d'id"
           "\n5-faire retraire un article"
           "\n6-afficher toute la file de travail"
           "\n7-commencer le travail"
           "\n0-Pour quitter\n Votre choix : ");
    scanf("%d",&n);
    switch (n)
    {
    case 1:
        add_pc();
        break;
    case 2:
        shw_all_pc();
        break;
    case 3:
        shw_pc();
        break;
    case 4:
        srch_pc();
        break;
    case 5:
        retrait();
        break;
    case 6:
        fil_aff(f);
        break;
    case 7:
        defiler(f);
        break;
    case 0:
        exit(0);
        break;
    default:
        printf("\n\tchoix indisponible\n");
        break;
    }

    menu(f);
}
