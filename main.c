#include <stdio.h>
#include <stdlib.h>
#include  "inc/tech_funcs.h"

int main() {
    if(exist()==-1){
        printf("aucun fichier technicien n'est present ");
        if(add_tech()==0){
            printf("le technicien a été ajouté avec succe ");
        }
    }
    }
