#include "../inc/structure.h"
#include "../inc/screen_funcs.h"
#include "../inc/pc_funcs.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
void menu(file *f)
{
    init_file(f);
    fil(f);
    int n;
    system("cls");
    printf("\n\n=====================================================MENU===============================================================\n"
           "\n\n\n\t\t\t1-ajouter un/des nouveau article"
           "\n\n\t\t\t2-afficher tout les article"
           "\n\n\t\t\t3-afficher les article d'une categorie specifié"
           "\n\n\t\t\t4-rechercher un article par son numero d'id"
           "\n\n\t\t\t5-faire retraire un article"
           "\n\n\t\t\t6-afficher toute la file de travail"
           "\n\n\t\t\t7-commencer le travail"
           "\n\n\t\t\t8-afficher total des transactions de mois dernier"
           "\n\n\t\t\t0-Pour quitter\n Votre choix : ");
    scanf("%d",&n);
    switch (n)
    {
    case 1:
        system("cls");
        add_pc();
        break;
    case 2:
        system("cls");
        shw_all_pc();
        break;
    case 3:
        system("cls");
        shw_pc();
        break;
    case 4:
        system("cls");
        srch_pc();
        break;
    case 5:
        system("cls");
        retrait();
        break;
    case 6:
        system("cls");
        printf("tous les articles recus et pas encore diagnostiqué : \n ");
        job *tmp=f->tete;
        for(int i=0; i<f->taille; i++)
        {
            printf("\n\n\t\t%d.%s 0%d    recu le %02d/%02d/%02d",tmp->pic->id,tmp->pic->nom,tmp->pic->num,tmp->pic->d_rec.j,tmp->pic->d_rec.m,tmp->pic->d_rec.a);
            tmp=tmp->suivant;
        }
        printf("\n\n");
        system("pause");
        break;
    case 7:
        system("cls");
        defiler(f);
        break;
    case 8:
        system("cls");
        stats();
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

void splash()
{


    printf("\n\n\n\t\t\t_____  _____ _____""\n"
           "\t\t\t/  __ \/  ___|_   _|""\n"
           "\t\t\t| /  \/\ `--.  | |""\n"
           "\t\t\t| |     `--. \ | |""\n"
           "\t\t\t| \__/\/\__/ / | |""\n"
           "\t\t\t\____/\____/  \_/""\n"
          );

    printf("\t\t  votre solution de gestion preferé");
    printf("\n\n\t\t\t");
    for (int i=0;i<19 ;i++){
            printf("*");
            Sleep(150);
        }


}
