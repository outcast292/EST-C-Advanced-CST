#include "../inc/pc_funcs.h"
#include "../inc/structure.h"
#include "stdio.h"
#include "time.h"
#include "stdlib.h"
#include "string.h"
#include "windows.h"
#include "../inc/screen_funcs.h"
time_t now;
//add a pc to the file

void add_pc()
{
    FILE* f=fopen("fl/pc_id","r");
    int n,id,num;
    date d;
    fscanf(f,"%d",&id);
    fclose(f);
    f=fopen("fl/pc","a");
    char nom[15];
    printf("\t\t\n\ncombien de article tu veux ajouter : ");
    scanf("%d",&n);
    for(int i=0; i<n ; i++)
    {
        system("cls");
        printf("\t\t\n\nentrer le nom de client : ");
        scanf("%s",nom);
        printf("\t\t\n\nentrer le numéro de client : ");
        scanf("%d",&num);
        date_add(&d);
        fprintf(f,"%d %s %010d %d %d %d/%d/%d 0/0/0 0/0/0\n",++id,nom,num,0,0,d.j,d.m,d.a);
        Sleep(500);

    }
    fclose(f);
    f=fopen("fl/pc_id","w");
    fprintf(f,"%d",id);
    fclose(f);
    printf("\n\n\tajouté avec sucçé!!!!!!!!!\n\n\n");
    system("PAUSE");
}
//show all the pcs
void shw_all_pc()
{
    printf("\ttous les articles reçus :\n\n ");
    FILE *f=fopen("fl/pc","r");
    int id,num,tarif,etat;
    date d_rep,d_rec,d_sort;
    char nom[15];
    while(!(feof(f)))
    {
        fscanf(f,"%d %s %010d %d %d %d/%d/%d %d/%d/%d %d/%d/%d\n",&id,strupr(nom),&num,&tarif,&etat,&d_rec.j,&d_rec.m,&d_rec.a,&d_rep.j,&d_rep.m,&d_rep.a,&d_sort.j,&d_sort.m,&d_sort.a);
        printf("\n\t\t%d. %s %010d ",id,nom,num);
        switch(etat)
        {
        case 0:
            printf("reçu le %02d/%02d/%02d\n",d_rec.j,d_rec.m,d_rec.a);
            break;
        case 1:
            printf("reçu le %02d/%02d/%02d,reparé le %02d/%02d/%02d pour un tarif de %d\n",d_rec.j,d_rec.m,d_rec.a,d_rep.j,d_rep.m,d_rep.a,tarif);
            break;
        case -1:
            printf("reçu le %02d/%02d/%02d,passé en reparation le %02d/%02d/%02d mais non reparé\n",d_rec.j,d_rec.m,d_rec.a,d_rep.j,d_rep.m,d_rep.a);
            break;
        case 2:
            printf("reçu le %02d/%02d/%02d ",d_rec.j,d_rec.m,d_rec.a);
            if(tarif!=0)
            {
                printf(",reparé le %02d/%02d/%02d pour un tarif de %d",d_rep.j,d_rep.m,d_rep.a,tarif);
            }
            else
            {
                printf("non reparé");
            }
            printf(", sortie le %02d/%02d/%02d\n",d_sort.j,d_sort.m,d_sort.a);
            break;
        default:
            break;
        }
    }
    fclose(f);
    printf("\n\t");
    system("PAUSE");

}

//searching for a pc using id
void srch_pc()
{
    FILE *f=fopen("fl/pc","r");
    int id,num,tarif,etat,s,s_i=0;
    date d_rep,d_rec,d_sort;
    char nom[15];
    printf("\t\tentrer le'id a chercher : ");
    scanf("%d",&s);
    while(!(feof(f)))
    {
        fscanf(f,"%d %s %010d %d %d %d/%d/%d %d/%d/%d %d/%d/%d",&id,nom,&num,&tarif,&etat,&d_rec.j,&d_rec.m,&d_rec.a,&d_rep.j,&d_rep.m,&d_rep.a,&d_sort.j,&d_sort.m,&d_sort.a);
        if(id==s)
        {
            s_i=1;
            printf("\n\t\t %d. %s 0%d ",id,nom,num);
            switch(etat)
            {
            case 0:
                printf(" reçu le %02d/%02d/%02d\n",d_rec.j,d_rec.m,d_rec.a);
                break;
            case 1:
                printf("reçu le %02d/%02d/%02d,reparé le %02d/%02d/%02d pour un tarif de %d\n",d_rec.j,d_rec.m,d_rec.a,d_rep.j,d_rep.m,d_rep.a,tarif);
                break;
            case -1:
                printf("reçu le %02d/%02d/%02d,passé en reparation le %02d/%02d/%02d mais non reparé\n",d_rec.j,d_rec.m,d_rec.a,d_rep.j,d_rep.m,d_rep.a);
                break;
            case 2:
                printf("reçu le %02d/%02d/%02d ",d_rec.j,d_rec.m,d_rec.a);
                if(tarif!=0)
                {
                    printf(",reparé le %02d/%02d/%02d pour un tarif de %d",d_rep.j,d_rep.m,d_rep.a,tarif);
                }
                else
                {
                    printf("non reparé");
                }
                printf(", sortie le %02d/%02d/%02d\n",d_sort.j,d_sort.m,d_sort.a);
                break;
            default:
                break;
            }
            break;
        }
    }
    if(s_i==0)
    {
        printf("\n\n\tarticle non trouvé");
    }
    fclose(f);
    system("\n\n\tpause");
}
//func tp show pcs due to it s categorie
void shw_pc()
{
    FILE *f=fopen("fl/pc","r");
    int id,num,tarif,etat,s_et=5,x=0;
    date d_rep,d_rec,d_sort;
    char nom[15];
    do
    {
        printf("\t\t\ttu veux afficher : \n\n\t\t0 ->les articles re\200us\n\n\t\t1 ->les articles reparé\n\n\t\t-1 -> les articles non reparé\n\n\t\t2 -> les articles déja pris\n\n\n\tvotre choix : ");
        scanf("%d",&s_et);
    }
    while(s_et!=0&&s_et!=1&&s_et!=-1&&s_et!=2);
    while(!(feof(f)))
    {
        fscanf(f,"%d %s %d %d %d %d/%d/%d %d/%d/%d %d/%d/%d\n",&id,nom,&num,&tarif,&etat,&d_rec.j,&d_rec.m,&d_rec.a,&d_rep.j,&d_rep.m,&d_rep.a,&d_sort.j,&d_sort.m,&d_sort.a);
        // for what this condition !!!!!
        if(etat==s_et)
        {
            x++;
            printf("\n\n\t\t %d. %s %010d ",id,nom,num);
            switch(etat)
            {
            case 0:
                printf(" reçu le %02d/%02d/%02d\n",d_rec.j,d_rec.m,d_rec.a);
                break;
            case 1:
                printf("reçu le %02d/%02d/%02d,reparé le %02d/%02d/%02d pour un tarif de %d\n",d_rec.j,d_rec.m,d_rec.a,d_rep.j,d_rep.m,d_rep.a,tarif);
                break;
            case -1:
                printf("reçu le %02d/%02d/%02d,passé en reparation le %02d/%02d/%02d mais non reparé\n",d_rec.j,d_rec.m,d_rec.a,d_rep.j,d_rep.m,d_rep.a);
                break;
            case 2:
                printf("reçu le %02d/%02d/%02d ",d_rec.j,d_rec.m,d_rec.a);
                if(tarif!=0)
                {
                    printf(",reparé le %02d/%02d/%02d pour un tarif de %d",d_rep.j,d_rep.m,d_rep.a,tarif);
                }
                else
                {
                    printf("non reparé");
                }
                printf(", sortie le %02d/%02d/%02d\n",d_sort.j,d_sort.m,d_sort.a);
                break;
            default:
                break;
            }
        }
    }
    printf("\n\n\til y'a %d entrés dans le systéme\n\n",x);
    fclose(f);
    system("pause");
}

//fun to retrieve a pc
void retrait()
{
    int x;
    time(&now);
    struct tm *local = localtime(&now);
    printf("\n\n\n\t\t entrer l'id de l'article a retraire : ");
    scanf("%d",&x);
    FILE *f=fopen("fl/pc","r");
    FILE *g=fopen("fl/pc_tmp","w");
    int id,num,tarif,etat;
    date d_rep,d_rec,d_sort;
    char nom[15];
    while (!feof(f))
    {
        fscanf(f,"%d %s %010d %d %d %d/%d/%d %d/%d/%d %d/%d/%d\n",&id,nom,&num,&tarif,&etat,&d_rec.j,&d_rec.m,&d_rec.a,&d_rep.j,&d_rep.m,&d_rep.a,&d_sort.j,&d_sort.m,&d_sort.a);
        if(id==x)
        {
            etat=2;
            fprintf(g,"%d %s %010d %d %d %d/%d/%d %d/%d/%d %d/%d/%d\n",id,nom,num,tarif,etat,d_rec.j,d_rec.m,d_rec.a,d_rep.j,d_rep.m,d_rep.a,local->tm_mday,local->tm_mon+1,local->tm_year+1900);
        }
        else
        {
            fprintf(g,"%d %s %010d %d %d %d/%d/%d %d/%d/%d %d/%d/%d\n",id,nom,num,tarif,etat,d_rec.j,d_rec.m,d_rec.a,d_rep.j,d_rep.m,d_rep.a,d_sort.j,d_sort.m,d_sort.a);
        }
    }
    fclose(f);
    fclose(g);
    remove("fl/pc");
    if(!(rename("fl/pc_tmp","fl/pc")))
    {
        printf("\n\n\n\t\tsucçé\n\n\t");
    }
    else
    {
        printf("\n\n\n\terror\n\n\t");
    }
    system("pause");
}
// initialiser pille

void init_file(file *f)
{

    f->tete = NULL;
    f->que = NULL;
    f->taille = 0;
}
void fil(file *f)
{
    init_file(f);
    FILE *z=fopen("fl/pc","r");
    pc x;
    while(!(feof(z)))
    {
        fscanf(z,"%d %s %010d %d %d %d/%d/%d %d/%d/%d %d/%d/%d\n",&x.id,x.nom,&x.num,&x.tarif,&x.etat,&x.d_rec.j,&x.d_rec.m,&x.d_rec.a,&x.d_rep.j,&x.d_rep.m,&x.d_rep.a,&x.d_sort.j,&x.d_sort.m,&x.d_sort.a);
        if(x.etat==0)
        {
            enfiler(f,x);
        }
    }
    fclose(z);

}

// fonction d'enfilemennt
void enfiler(file *f,pc x)
{
    job *n = (job*)malloc(sizeof(job));

    if(n == NULL)
    {
        printf("allocation impossible !");
        exit(1);
    }
    n->pic=(pc*)malloc(sizeof(pc));
    if(n->pic == NULL)
    {
        printf("allocation impossible !");
        exit(1);
    }
    n->pic->id=x.id;
    n->pic->num=x.num;
    n->pic->tarif=x.tarif;
    n->pic->d_rec=x.d_rec;
    n->pic->etat=x.etat;
    strcpy(n->pic->nom,x.nom);
    if(f->taille==0)
    {
        f->tete=n;
        f->que=n;
        n->suivant=NULL;
    }
    else
    {
        f->que->suivant=n;
        f->que=n;
        n->suivant=NULL;
    }
    f->taille++;
}
// func to show la file

//defilement + call pour changement d'etat
void defiler(file *f)
{
    system("cls");
    job *tmp=f->tete;
    int n=3;
    if(f->taille==0)
    {
        printf("\n\naucun job est disponible");
        exit(1);
    }
    printf("\n\n\t\t%d. %s 0%10d  recu le %02d/%02d/%02d\n\n",tmp->pic->id,tmp->pic->nom,tmp->pic->num,tmp->pic->d_rec.j,tmp->pic->d_rec.m,tmp->pic->d_rec.a);
    while(n!=1 && n!=2 && n!=0)
    {
       printf("\n\n\n\t\test-ce que l'article est reparé: \n\n\t1-oui\n\n\t2-non\n\n\n\t0-quitter \n\n\n\t\tvotre choix: ");
        scanf("%d",&n);
    }
    if(n==1)
    {
        change(tmp->pic->id,1);
    }
    else if(n==2)
    {
        change(tmp->pic->id,-1);
    }
    if(n==0){
        menu(f);
    }
    f->tete=f->tete->suivant;
    free(tmp);
    f->taille--;
    if(f->taille!=0)
    {
        defiler(f);
    }

}
//fonction pour changer l'etat d'un pc (reparé ou non
void change(int x,int state)
{
    FILE *f=fopen("fl/pc","r");
    FILE *g=fopen("fl/pc_tmp","w");
    int id,num,tarif,etat;
    time_t now;
    date d_rep,d_rec,d_sort;
    char nom[15];
    while (!feof(f))
    {
        fscanf(f,"%d %s %010d %d %d %d/%d/%d %d/%d/%d %d/%d/%d\n",&id,nom,&num,&tarif,&etat,&d_rec.j,&d_rec.m,&d_rec.a,&d_rep.j,&d_rep.m,&d_rep.a,&d_sort.j,&d_sort.m,&d_sort.a);
        if(id!=x)
        {
            fprintf(g,"%d %s %010d %d %d %d/%d/%d %d/%d/%d %d/%d/%d\n",id,nom,num,tarif,etat,d_rec.j,d_rec.m,d_rec.a,d_rep.j,d_rep.m,d_rep.a,d_sort.j,d_sort.m,d_sort.a);
        }
        else
        {
            etat=state;
            time(&now);
            struct tm *local = localtime(&now);
            if(state==1)
            {
                printf("\t\t\nmerci d'entrer le prix de service : ");
                scanf("%d",&tarif);
                fprintf(g,"%d %s %010d %d %d %d/%d/%d %d/%d/%d %d/%d/%d\n",id,nom,num,tarif,etat,d_rec.j,d_rec.m,d_rec.a,local->tm_mday,local->tm_mon+1,local->tm_year+1900,d_sort.j,d_sort.m,d_sort.a);
            }
            else{
               fprintf(g,"%d %s %010d %d %d %d/%d/%d %d/%d/%d %d/%d/%d\n",id,nom,num,tarif,etat,d_rec.j,d_rec.m,d_rec.a,local->tm_mday,local->tm_mon+1,local->tm_year+1900,d_sort.j,d_sort.m,d_sort.a);
            }

        }
    }
    fclose(f);
    fclose(g);
    remove("fl/pc");
    rename("fl/pc_tmp","fl/pc");
}

void stats(){
    FILE *f=fopen("fl/pc","r");
     int id,num,tarif,etat;
    date d_rep,d_rec,d_sort;
    char nom[15];
    int mois=0,ci=0;
    float pr=0;
    while(!(feof(f)))
    {
        fscanf(f,"%d %s %010d %d %d %d/%d/%d %d/%d/%d %d/%d/%d\n",&id,nom,&num,&tarif,&etat,&d_rec.j,&d_rec.m,&d_rec.a,&d_rep.j,&d_rep.m,&d_rep.a,&d_sort.j,&d_sort.m,&d_sort.a);
        ci+=tarif;
        if(d_sort.m>mois){
            mois=d_sort.m;
        }
    }
    printf("\n\n\n\tle total des transactions  : %d",ci);
    ci=0;
    fseek(f,0,SEEK_SET);
    while(!(feof(f)))
    {
        fscanf(f,"%d %s %010d %d %d %d/%d/%d %d/%d/%d %d/%d/%d\n",&id,nom,&num,&tarif,&etat,&d_rec.j,&d_rec.m,&d_rec.a,&d_rep.j,&d_rep.m,&d_rep.a,&d_sort.j,&d_sort.m,&d_sort.a);
        if(d_sort.m==mois){
            ci+=tarif;
            pr+=(float)tarif*0.25;
        }
    }
    float t=(float)ci-pr;
    printf("\n\n\n\tle total des transaction de mois precedent  : %d",ci);
    printf("\n\n\n\tle pourcentage des techniçiens  : %.2f",pr);
    printf("\n\n\n\t=======================================");
    printf("\n\n\n\tle Totale Net de profit  : %.2f\n\n",t);


    system("PAUSE");
}
