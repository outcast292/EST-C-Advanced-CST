#include "../inc/structure.h"
#include "../inc/tech_funcs.h"
#include "stdio.h"
#include "string.h"
#include "../inc/job_funcs.h"
//void add_job(int id_tech)
//{
//    FILE *f=fopen("../fl/pc","r");
//   job tmp;
//    fscanf(f,"%d",&tmp.id);
//    tmp.id++;
//    printf("entrer le nom de client");
//   scanf("%s",&tmp.nom_clt);
// date_add(&tmp.d_rec);
//   tmp.et_job.t=0;
// fclose(f);
// f=fopen("../fl/job","a");
// fprintf("%d %d %s %d %d/%d/%d",tmp.id,tmp.id_tech,tmp.nom_client,tmp.et_job,tmp.d_rep.j,tmp.d_rec.m,tmp.d_rec.a);
//}
//void afficher_job()
/*{
    int n;
    job tmp;
    printf("afficher tout les jobs : ");
    FILE* f=fopen("../fl/jobs","r");
    while(!feof(f))
    {

        fscanf(f,"%d %d %s %d/%d/%d",&tmp.id,&tmp.id_tech,&tmp.nom_client,&tmp.et_job,&tmp.d_rep.j,&tmp.d_rec.m,&tmp.d_rec.a)
        printf("%d %d %s %d %d/%d/%d",tmp.id,tmp.id_tech,tmp.nom_client,tmp.et_job,tmp.d_rep.j,tmp.d_rec.m,tmp.d_rec.a)
    }
}*/


// initialiser pille

void init_file(file *f)
{

    f->sommet = NULL;
    f->sommet = NULL;
    p->taille = 0;
}
void fil(file *f){
    init_file(f);
    FILE *z=fopen("fl/pc","r");
    pc x;
    while(!(feof(z))) {
        fscanf(f,"%d %s 0%d %d %d/%d/%d %d/%d/%d %d/%d/%d %d",x.id,x.nom,x.num,x.tarif,x.d_rec.j,x.d_rec.m,x.d_rec.a,x.d_rep.j,x.d_rep.m,x.d_rep.a,x.d_sort.j,x.d_sort.m,x.d_sort.a,x.etat);
        if(x.etat==0){
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
    n->pic->id=x->id;
    n->pic->num=x->num;
    n->pic->tarif=x->tarif;
    n->pic->d_rec=x->d_rec;
    n->pic->etat=x->etat;
    strcpy(n->pic->nom_clt,x->nom_clt);
    if(f->taille==0){
        f->tete=n;
        f->que=n;
        n->suivant=NULL;
    }
    else{
        f->que->suivant=n;
        f->que=n;
        n->suivant=NULL;
    }
    f->taille++;
}
/*
// add jobs to the stack ( we gonna only add the id of the job to the stack and change the stat based on the id

    void go_to_stack(pile *p)
    {

        job tmp;
        FILE *f= fopen("../fl/jobs","r");
        FILE *g =fopen("../fl/jobs2","w");

        while(!feof(f))
        {
            fscanf(f,"%d %d %s %d/%d/%d",&tmp.id,&tmp.id_tech,&tmp.nom_client,&tmp.et_job,&tmp.d_rep.j,&tmp.d_rec.m,&tmp.d_rec.a);
            if (strcmp(tmp.et_job,"recieved")==0)
            {

                empilement(p,tmp.id);
                strcpy(tmp.et_job,"outgoing");
                fprintf(f,"%d %d %s %d/%d/%d",tmp.id,tmp.id_tech,tmp.nom_client,tmp.et_job,tmp.d_rep.j,tmp.d_rec.m,tmp.d_rec.a);
            }

        }

        fclose(g);
        fclose(f);
        remove("../fl/jobs");
        rename("../fl/jobs2","../fl/jobs");

    }

// delete jobs from the stack


    int delet_job_from_stack(pile *p)
    {
        FILE *f =fopen("../fl/jobs","r");
        FILE *g=fopen("../fl/finished_jobs","a+");
        job tmp
        job *sup_ele;
        if(p->taille == 0)
            return -1;
        sup_ele = p->sommet;
        p->sommet = p->sommet->suivant;
        p->taille--;

        while(!(feof(f)))
        {
            fscanf(f,"%d %d %s %d/%d/%d",&tmp.id,&tmp.id_tech,&tmp.nom_client,&tmp.et_job,&tmp.d_rep.j,&tmp.d_rec.m,&tmp.d_rec.a);

            if(tmp.id == sup_ele->id)
            {

                fprintf(g,"%d %d %s %s %d/%d/%d",sup_ele.id,sup_ele.id_tech,sup_ele.nom_client,"fini",sup_ele.d_rep.j,sup_ele.d_rec.m,sup_ele.d_rec.a);
            }

            else
                fprintf(g,"%d %d %s %d/%d/%d",tmp.id,tmp.id_tech,tmp.nom_client,tmp.et_job,tmp.d_rep.j,tmp.d_rec.m,tmp.d_rec.a);
        }

        fclose(f);
        fclose(g);
        remove("../fl/jobs");
        rename("../fl/jobs2","../fl/jobs");

        return 0;
    }*/
// func to show la file
void file_aff(file *f) {
    printf("tous les articles recus et pas encore diagnostiqué : \n ");
    job *tmp=f->tete;
    for(int i=0;i<f->taille;i++){
            printf(" %d %s 0%d    recu le %02d/%02d/%02d\n",tmp->id,tmp->nom_clt,tmp->num,tmp->d_rec.j,tmp->d_rec.m,tmp->d_rec.a);
            tmp=tmp->suivant;
        }
}
//defilement + call pour changement d'etat
void defiler(file *f)
{
    job *tmp=f->tete;
    int n=3;
    if(f->taille==0){
        printf("aucun job est disponible");
        exit(1);
    }
    printf("%d %s 0%d    recu le %02d/%02d/%02d\n",tmp->id,tmp->nom_clt,tmp->num,tmp->d_rec.j,tmp->d_rec.m,tmp->d_rec.a);
    do{
            printf("est-que l'article est reparé: \n1-oui\n2-non : ");scanf("%d",&n);
    }while(n!=1 || n!=2);
    if(n==1){
        change(tmp->id,1);
    }else{
        change(tmp->id,2);
    }
    f->tete=f->tete->suivant;
    free(tmp);
    f->taille--;
    if(f->taille!=0){
        defiler(f);
    }

}





