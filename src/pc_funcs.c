#include "../inc/pc_funcs.h"
#include "../inc/structure.h"
#include "stdio.h"
#include "time.h"
#include "stdlib.h"
#include "string.h"
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
    printf("combien de article tu veux ajouter : ");
    scanf("%d",&n);
    for(int i=0; i<n ; i++)
    {
        printf("entrer le nom de client : ");
        scanf("%s",nom);
        printf("entrer le numero de client : ");
        scanf("%d",&num);
        date_add(&d);
        fprintf(f,"%d %s %010d %d %d %d/%d/%d 0/0/0 0/0/0\n",++id,nom,num,0,0,d.j,d.m,d.a);
    }
    fclose(f);
    f=fopen("fl/pc_id","w");
    fprintf(f,"%d",id);
    fclose(f);
}
//show all the pcs
void shw_all_pc()
{
    printf("tous les articles recus :\n\n ");
    FILE *f=fopen("fl/pc","r");
    int id,num,tarif,etat;
    date d_rep,d_rec,d_sort;
    char nom[15];
    while(!(feof(f)))
    {
        fscanf(f,"%d %s %010d %d %d %d/%d/%d %d/%d/%d %d/%d/%d\n",&id,nom,&num,&tarif,&etat,&d_rec.j,&d_rec.m,&d_rec.a,&d_rep.j,&d_rep.m,&d_rep.a,&d_sort.j,&d_sort.m,&d_sort.a);
        printf("\n\t%d %s %010d ",id,nom,num);
        switch(etat)
        {
        case 0:
            printf("recu le %02d/%02d/%02d\n",d_rec.j,d_rec.m,d_rec.a);
            break;
        case 1:
            printf("recu le %02d/%02d/%02d,repare le %02d/%02d/%02d pour un tarif de %d\n",d_rec.j,d_rec.m,d_rec.a,d_rep.j,d_rep.m,d_rep.a,tarif);
            break;
        case -1:
            printf("recu le %02d/%02d/%02d,passe en reparation le %02d/%02d/%02d mais non repare\n",d_rec.j,d_rec.m,d_rec.a,d_rep.j,d_rep.m,d_rep.a);
            break;
        case 2:
            printf("recu le %02d/%02d/%02d,repare le %02d/%02d/%02d pour un tarif de %d, sortie le %02d/%02d/%02d\n",d_rec.j,d_rec.m,d_rec.a,d_rep.j,d_rep.m,d_rep.a,tarif,d_sort.j,d_sort.m,d_sort.a);
            break;
        default:
            break;
        }
    }
}

//searching for a pc using id
void srch_pc()
{
    FILE *f=fopen("fl/pc","r");
    int id,num,tarif,etat,s,s_i=0;
    date d_rep,d_rec,d_sort;
    char nom[15];
    printf("entrer le'id a chercher : ");
    scanf("%d",&s);
    while(!(feof(f)))
    {
        fscanf(f,"%d %s %010d %d %d %d/%d/%d %d/%d/%d %d/%d/%d",&id,nom,&num,&tarif,&etat,&d_rec.j,&d_rec.m,&d_rec.a,&d_rep.j,&d_rep.m,&d_rep.a,&d_sort.j,&d_sort.m,&d_sort.a);
        if(id==s)
        {
            s_i=1;
            printf("\n\t %d %s 0%d ",id,nom,num);
            switch(etat)
            {
            case 0:
                printf(" recu le %02d/%02d/%02d\n",d_rec.j,d_rec.m,d_rec.a);
                break;
            case 1:
                printf("recu le %02d/%02d/%02d,repare le %02d/%02d/%02d pour un tarif de %d\n",d_rec.j,d_rec.m,d_rec.a,d_rep.j,d_rep.m,d_rep.a,tarif);
                break;
            case -1:
                printf("recu le %02d/%02d/%02d,passe en reparation le %02d/%02d/%02d mais non repare\n",d_rec.j,d_rec.m,d_rec.a,d_rep.j,d_rep.m,d_rep.a);
                break;
            case 2:
                printf("recu le %02d/%02d/%02d,repare le %02d/%02d/%02d pour un tarif de %d, sortie le %02d/%02d/%02d\n",d_rec.j,d_rec.m,d_rec.a,d_rep.j,d_rep.m,d_rep.a,tarif,d_sort.j,d_sort.m,d_sort.a);
                break;
            default:
                break;
            }
            break;
        }
    }
    if(s_i==0)
    {
        printf("article non trouvé");
    }
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
        printf("tu veux afficher : \n\n\t0 ->les article recus\n\n\t1 ->les article repare\n\n\t-1 -> les article non repare\n\n\t2 -> les article sortie , votre choix : ");
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
            printf("\n\t %d %s %010d ",id,nom,num);
            switch(etat)
            {
            case 0:
                printf(" recu le %02d/%02d/%02d\n",d_rec.j,d_rec.m,d_rec.a);
                break;
            case 1:
                printf("recu le %02d/%02d/%02d,repare le %02d/%02d/%02d pour un tarif de %d\n",d_rec.j,d_rec.m,d_rec.a,d_rep.j,d_rep.m,d_rep.a,tarif);
                break;
            case -1:
                printf("recu le %02d/%02d/%02d,passe en reparation le %02d/%02d/%02d mais non repare\n",d_rec.j,d_rec.m,d_rec.a,d_rep.j,d_rep.m,d_rep.a);
                break;
            case 2:
                printf("recu le %02d/%02d/%02d,repare le %02d/%02d/%02d pour un tarif de %d, sortie le %02d/%02d/%02d\n",d_rec.j,d_rec.m,d_rec.a,d_rep.j,d_rep.m,d_rep.a,tarif,d_sort.j,d_sort.m,d_sort.a);
                break;
            default:
                break;
            }
        }
    }
    printf("\nil y'a %d entres dans le systeme",x);
}

//fun to retrieve a pc
void retrait()
{
    int x;
    time(&now);
    struct tm *local = localtime(&now);
    printf("\n entrer l'id de l'article a retraire : ");
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
            printf("le job a ete changé en etat de retrait ");
            break;
        }
        else{
            fprintf(g,"%d %s %010d %d %d %d/%d/%d %d/%d/%d %d/%d/%d\n",id,nom,num,tarif,etat,d_rec.j,d_rec.m,d_rec.a,d_rep.j,d_rep.m,d_rep.a,d_sort.j,d_sort.m,d_sort.a);
        }
    }
    fclose(f);
    fclose(g);
    remove("fl/pc");
    if(rename("fl/pc_tmp","fl/pc")){
            printf("tache passe avec succé");
}}
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
// func to show la file

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
