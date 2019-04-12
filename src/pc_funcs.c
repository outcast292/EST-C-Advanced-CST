#include "../inc/pc_funcs.h"
#include "../inc/structure.h"
//add a pc to the file
void add_pc(){
    FILE* f=fopen("fl/pc_id","r");
    int n,id,num;
    date d;
    fscanf(f,"%d",&id);
    fclose(f);
    f=fopen("fl/pc","a");
    char nom[15];
    printf("combien de article tu veux ajouter : ");scanf("%d",&n);
    for (int i=0;i<n ;i++){
        printf("entrer le nom de client : ");scanf("%s",&nom);
        printf("entrer le numero de client : ");scanf("%d",&num);
        date_add(&d);
        fprintf(f,"%d %s 0%d %d %d/%d/%d 0/0/0 0/0/0 0",++id,nom,num,d.j,d.m,d.a);
    }
    fclose(f);
    f=fopen("fl/pc_id","w");
    fprintf(f,"%d",id);
    fclose(f);
}
//show all the pcs
void shw_all_pc(){
    printf("tous les articles recus : ")
    FILE *f=fopen("fl/pc","r");
    int id,num,tarif,etat;
    date d_rep,d_rec,d_sort;
    char nom[15];
    while(!(feof(f))){
        fscanf(f,"%d %s 0%d %d %d/%d/%d %d/%d/%d %d/%d/%d %d",&id,&nom,&num,&tarif,d_rec.j,d_rec.m,d_rec.a,d_rep.j,d_rep.m,d_rep.a,sort.j,d_sort.m,d_sort.a,&etat);
        printf("\n %d %s 0%d ",id,nom,num);
        switch (etat)
        {
        case 0:
            printf(" recu le %d/%d/%d\n",d_rec.j,d_rec.m,d_rec.a);
            break;
        case 1:
            printf("recu le %d/%d/%d,repare le %d/%d/%d pour un tarif de %d\n",d_rec.j,d_rec.m,d_rec.a,d_rep.j,d_rep.m,d_rep.a,tarif);
            break;
        case -1:
            printf("recu le %d/%d/%d,passe en reparation le %d/%d/%d mais non repare\n",d_rec.j,d_rec.m,d_rec.a,d_rep.j,d_rep.m,d_rep.a,);
            break;
        case 2:
            printf("recu le %d/%d/%d,repare le %d/%d/%d pour un tarif de %d, sortie le %d/%d/%d\n",d_rec.j,d_rec.m,d_rec.a,d_rep.j,d_rep.m,d_rep.a,tarif,d_sort.j,d_sort.m,d_sort.a,)
            break;
        default:
            break;
        }

    }

}
