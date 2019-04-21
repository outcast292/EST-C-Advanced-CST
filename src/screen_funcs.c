#include "../inc/structure.h"
#include "../inc/screen_funcs.h"
#include "../inc/pc_funcs.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void menu(file *f)
{
    init_file(f);
    fil(f);
    int n;
    printf("\n\n==============================MENU=======================\n"
           "\n\n1-ajouter un/des nouveau article"
           "\n2-afficher tout les article"
           "\n3-afficher les article d'une categorie specifi�"
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
        printf("tous les articles recus et pas encore diagnostiqu� : \n ");
    job *tmp=f->tete;
    for(int i=0; i<f->taille; i++)
    {
        printf(" %d %s 0%d    recu le %02d/%02d/%02d\n",tmp->pic->id,tmp->pic->nom,tmp->pic->num,tmp->pic->d_rec.j,tmp->pic->d_rec.m,tmp->pic->d_rec.a);
        tmp=tmp->suivant;
    }
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
// func to show la file

