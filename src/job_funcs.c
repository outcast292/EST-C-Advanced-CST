#include "../inc/job_funcs.h"
#include "../inc/structure.h"
#include "stdio.h"
#include "string.h"
void add_job(int id_tech)
{
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
void afficher_job()
{
    int n;
    job tmp;
    printf("afficher tout les jobs : ");
    FILE* f=fopen("../fl/jobs","r");
    while(!feof(f))
    {
    	// here must use f not tmp;
        fscanf(tmp,"%d %d %s %d/%d/%d",&tmp.id,&tmp.id_tech,&tmp.nom_client,&tmp.et_job,&tmp.d_rep.j,&tmp.d_rec.m,&tmp.d_rec.a)
        printf("%d %d %s %d %d/%d/%d",tmp.id,tmp.id_tech,tmp.nom_client,tmp.et_job,tmp.d_rep.j,tmp.d_rec.m,tmp.d_rec.a)
    }
}


// initialiser pille

void init_pile(pile *p){

p->sommet = NULL;
p->taille = 0;
}


// fonction d'empilement 
void empilement(pile *p, int id){
 job_rep *n_ele = (job_rep*)malloc(sizeof(job_rep));

   if(n_ele == NULL) {printf("allocation impossibel !");
            exit(1);
}  else{
       

    	p->sommet->id = id;
        n_ele->suivant = p->sommet;
         p->sommet = n_ele;
         p->taille++;
}



// add jobs to the stack ( we gonna onmy add the id of the job to the stack and change the stat based on the id 

void go_to_stack(pile *p){
	
	job tmp;
	FILE *f= fopen("../fl/jobs","r");
	FILE *g =fopen("../fl/jobs2","w");
	
	 while(!feof(f))
    {
        fscanf(f,"%d %d %s %d/%d/%d",&tmp.id,&tmp.id_tech,&tmp.nom_client,&tmp.et_job,&tmp.d_rep.j,&tmp.d_rec.m,&tmp.d_rec.a);
        if (strcmp(tmp.et_job,"recieved")==0){
        	
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


int delet_job_from_stack(pile *p){
FILE *f =fopen("../fl/jobs","r");
FILE *g=fopen("../fl/finished_jobs","a+");
	job_rep tmp
    job_rep *sup_ele;
    if(p->taille == 0)  return -1;
    sup_ele = p->sommet;
    p->sommet = p->sommet->suivant;
    p->taille--;
    
    while(!(feof(f))){
    	 fscanf(f,"%d %d %s %d/%d/%d",&tmp.id,&tmp.id_tech,&tmp.nom_client,&tmp.et_job,&tmp.d_rep.j,&tmp.d_rec.m,&tmp.d_rec.a);
    	
    	if(tmp.id == sup_ele->id){
    	
		 fprintf(g,"%d %d %s %d/%d/%d",sup_ele.id,sup_ele.id_tech,sup_ele.nom_client,"fini",sup_ele.d_rep.j,sup_ele.d_rec.m,sup_ele.d_rec.a);
		}
		
		else
			fprintf(g,"%d %d %s %d/%d/%d",tmp.id,tmp.id_tech,tmp.nom_client,tmp.et_job,tmp.d_rep.j,tmp.d_rec.m,tmp.d_rec.a);
	}

	fclose(f);
	fclose(g);
	remove("../fl/jobs");
	rename("../fl/jobs2","../fl/jobs");

return 0;
}






