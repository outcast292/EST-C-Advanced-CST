#include "../inc/funcs.h"
#include <string.h>
#include <stdio.h>
int save_tech(tech* ptr) {
    FILE* tmp=fopen("fl/tech.txt","a");
    fprintf(tmp,"%d %s %s",ptr->id,ptr->nom,ptr->prenom);
    fclose(tmp);
    return 0;

}
tech* add_tech(char* nom,*char prenom){
    FILE* tmp=fopen("fl/id","rb");
    if(tmp==NULL){
        return -1;
    }
    int id;
    fscanf(tmp,"%d",&id);
    tech* ptr=(tech*)malloc(sizeof(tech));
    if(ptr==NULL){
        return -1;
    }
    strcpy(ptr->nom,nom);
    strcpy(ptr->prenom,prenom);
    ptr->id=id;
    fclose(tmp);
    tmp=fopen("fl/id","wb");
    fprintf(tmp,"%d",id+1);
    fclose(tmp);
    if(save_tech(ptr)==1){
        return 0;
    }
    else{
        return -1:
    }
}
