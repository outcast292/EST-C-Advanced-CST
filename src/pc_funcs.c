#include "../inc/pc_funcs.h"
#include "../inc/structure.h"

void add_pc(){
    FILE* f=fopen("fl/pc_id","r");
    int n,id,num;
    date d;
    fscanf(f,"%d",&id);
    fclose(f);
    f=fopen("fl/pc","a");
    char nom[30];
    printf("combien de article tu veux ajouter : ");scanf("%d",&n);
    for (int i=0;i<n ;i++){
        printf("entrer le nom de client : ");scanf("%s",&nom);
        printf("entrer le numero de client : ");scanf("%d",&num);
        date_add(&d);
        fprintf(f,"%d %s 0%d %d %d/%d/%d 0",++id,nom,num,d.j,d.m,d.a);
    }
    fclose(f);
    f=fopen("fl/pc_id","w");
    fprintf(f,"%d",id);
    fclose(f);
}

void shw_pc(){
    FILE *f=fopen("fl/pc","r");
    while(!(feof(f))){
        fscanf(f,"%d %s 0%d %d %d/%d/%d %d", )


    }

}

// pc_delet function
// copie all the ids of all pieces except the id of the piece we want to delet to new file|| delet the old file and renam the new file with the same name  

void sup_pc(){
	int id,tmp;
	printf("entre l'id de la piece a supprimer : "); scanf("%d",&id);
	FILE *f= fopen("fl/pc_id","r");
	FILE *g= fopen("fl/pc_id2","a");
	
	while(!(feof(f))){
		fscanf(f,"%d",&tmp);
		
		if(tmp == id);
		else
		 fprintf(g,"%d",id);
		
	}
	remove("fl/pc_id2");
	rename("fl/pc_id2","fl/pc_id")
	fclose(f);
	fclose(g);
	
	
}
