#include "../inc/pc_funcs.h"
#include "../inc/structure.h"
#include "stdio.h"
#include "time.h"
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
        }
        break;
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
        printf("tu veux afficher : \n0-les article recus\n1-les article repare\n-1-les article non repare\n2-les article sortie , votre choix : ");
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
//fonction pour changer l'etat d'un pc (reparé ou non
void change(int x,int state)
{
    FILE *f=fopen("fl/pc","r"),*g=fopen("fl/pc_tmp","w");
    int id,num,tarif,etat;
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
            if(state==1){
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
//fun to retrieve a pc
void retrait()
{
    int x;
    time(&now);
    struct tm *local = localtime(&now);
    printf("\n entrer l'id de l'article a retraire : ");
    scanf("%d",&x);
    FILE *f=fopen("fl/pc","r"),*g=fopen("fl/pc_tmp","w");
    int id,num,tarif,etat;
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
            etat=2;
            fprintf(g,"\n\t%d %s %010d %d %d %d/%d/%d %d/%d/%d %d/%d/%d\n",id,nom,num,tarif,etat,d_rec.j,d_rec.m,d_rec.a,d_rep.j,d_rep.m,d_rep.a,local->tm_mday,local->tm_mon+1,local->tm_year+1900);
        }
    }
    fclose(f);
    fclose(g);
    remove("fl/pc");
    rename("fl/pc_tmp","fl/pc");
}

