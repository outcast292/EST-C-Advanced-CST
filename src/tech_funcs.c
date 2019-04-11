#include "../inc/tech_funcs.h"
#include "../inc/structure.h"
#include "stdio.h"
int exist() { // func to teset if the file of the
    FILE *tmp;
    if((tmp = fopen("../fl/tech", "r"))!=NULL || feof(tmp)==1) {
        fclose(tmp);
        return 0;
        }
    return -1;
    }
tech get_tech() { // func to give back the info of the user
    tech t;
    FILE *tmp=fopen("../fl/tech","r");
    fscanf(tmp,"%d %s %s",&t.id,t.prenom,t.nom);
    fclose(tmp);
    return t;
    }
int add_tech() { //func to add tech to the file
    int id=1;
    char nom[30],prenom[30];
    printf("\n\tentrer votre nom : ");
    scanf("%s",nom);
    printf("\n\tentrer votre prenom : ");
    scanf("%s",prenom);
    FILE* tmp=fopen("fl/tech","w");
    if(tmp==NULL){
        printf("fichier non ouvert");
    }
    fprintf(tmp,"%d %s %s",id,nom,prenom);
    fclose(tmp);
    return 0;
    }

