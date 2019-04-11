#include "../inc/funcs.h"
#include <string.h>

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
    return ptr;

}
