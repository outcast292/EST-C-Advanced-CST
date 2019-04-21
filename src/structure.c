#include "../inc/structure.h"
#include "stdio.h"
#include "time.h"
void date_add(date *d)
{
    time_t now;
    time(&now);
    struct tm *local = localtime(&now);
    d->j=local->tm_mday;
    d->m=local->tm_mon+1;
    d->a=local->tm_year+1900;
    printf("la date d'aujourd'hui %02d/%02d/%02d\n\n",d->j,d->m,d->a);


}
