#include "../inc/structure.h"
#include "../inc/tech_funcs.h"
#include "stdio.h"
#include "stdlib.h"
#include "time.h"
#include "string.h"
#include "../inc/job_funcs.h"
#include "../inc/pc_funcs.h"
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

}

// fonction d'enfilemennt
void enfiler(file *f,pc x)
{
    job *n = (job*)malloc(sizeof(job));

    if(n == NULL)
    {
        printf("allocation impossibel !");
        exit(1);
    }
    n->pic=(pc*)malloc(sizeof(pc));
    if(n->pic == NULL)
    {
        printf("allocation impossibel !");
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

//defilement + call pour changement d'etat
void defiler(file *f)
{
    job *tmp=f->tete;
    int n=3;
    if(f->taille==0)
    {
        printf("aucun job est disponible");
        exit(1);
    }
    printf("%d %s %10d  recu le %02d/%02d/%02d\n",tmp->pic->id,tmp->pic->nom,tmp->pic->num,tmp->pic->d_rec.j,tmp->pic->d_rec.m,tmp->pic->d_rec.a);
    do
    {
        printf("est-que l'article est reparé: \n1-oui\n2-non : ");
        scanf("%d",&n);
    }
    while(n!=1 || n!=2);
    if(n==1)
    {
        change(tmp->pic->id,1);
    }
    else
    {
        change(tmp->pic->id,2);
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
    FILE *f=fopen("fl/pc","r"),*g=fopen("fl/pc_tmp","w");
    int id,num,tarif,etat;
    time_t now;
    date d_rep,d_rec,d_sort;
    char nom[15];
    while (!feof(f))
    {
        fscanf(f,"%d %s 0%d %d %d/%d/%d %d/%d/%d %d/%d/%d %d",&id,nom,&num,&tarif,&etat,&d_rec.j,&d_rec.m,&d_rec.a,&d_rep.j,&d_rep.m,&d_rep.a,&d_sort.j,&d_sort.m,&d_sort.a);
        if(id!=x)
        {
            fprintf(g,"%d %s 0%d %d %d/%d/%d %d/%d/%d %d/%d/%d %d",id,nom,num,tarif,etat,d_rec.j,d_rec.m,d_rec.a,d_rep.j,d_rep.m,d_rep.a,d_sort.j,d_sort.m,d_sort.a);
        }
        else
        {
            etat=state;
            time(&now);
            struct tm *local = localtime(&now);
            if(state==1)
            {
                printf("merci d'entrer le prix de service ");
                scanf("%d",&tarif);
            }
            fprintf(g,"%d %s 0%d %d %d/%d/%d %d/%d/%d %d/%d/%d %d",id,nom,num,tarif,etat,d_rec.j,d_rec.m,d_rec.a,local->tm_mday,local->tm_mon+1,local->tm_year+1900,d_sort.j,d_sort.m,d_sort.a);
        }
    }
    fclose(f);
    fclose(g);
    remove("fl/pc");
    rename("fl/pc_tmp","fl/pc");
}





