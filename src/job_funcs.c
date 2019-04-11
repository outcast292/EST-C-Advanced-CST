#include "../inc/job_funcs.h"
#include "../inc/structure.h"
#include "stdio.h"
#include "string.h"
void add_job(int id_tech) {
    FILE *f=fopen("../fl/id","r");
    job tmp;
    fscanf(f,"%d",&tmp.id);
    tmp.id++;
    printf("entrer le nom de client");
    scanf("%s",&tmp.nom_client);
    date_add(&tmp.d_rec);
    tmp.et_job.t=0;
    fclose(f);
    f=fopen("../fl/job","a");
    fprintf("%d %d %s %d %d/%d/%d",tmp.id,tmp.id_tech,tmp.nom_client,tmp.et_job,tmp.d_rep.j,tmp.d_rec.m,tmp.d_rec.a);
    }
void afficher_job() {
    int n;
    job tmp;
    printf("afficher tout les jobs : ");
    FILE* f=fopen("../fl/jobs","r");
    while(!feof(f)) {
        fscanf(tmp,"%d %d %s %d/%d/%d",&tmp.id,&tmp.id_tech,&tmp.nom_client,&tmp.et_job,&tmp.d_rep.j,&tmp.d_rec.m,&tmp.d_rec.a)
        printf("%d %d %s %d %d/%d/%d",tmp.id,tmp.id_tech,tmp.nom_client,tmp.et_job,tmp.d_rep.j,tmp.d_rec.m,tmp.d_rec.a)
        }
    }
