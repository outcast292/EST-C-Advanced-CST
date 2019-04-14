#include "../inc/structure.h"
#include "stdio.h"
void date_add(date *d) {
    do {
        printf("saisire la date selon le formats suivant JJ/MM/AA");
        scanf("%d/%d/%d",&d->j,&d->m,&d->a);
        }
    while(d->j>31||d->m>12);
    }
