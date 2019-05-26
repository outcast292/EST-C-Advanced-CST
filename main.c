#include <stdio.h>
#include <stdlib.h>
#include  "inc/tech_funcs.h"
#include  "time.h"
#include  "inc/screen_funcs.h"
#include  "inc/job_funcs.h"
#include  "inc/pc_funcs.h"
#include  "locale.h"
time_t now;
int hours, minutes, seconds, day, month, year;
file F;
int main()

{
    setlocale(LC_CTYPE,"");
    splash();
    time(&now);
    struct tm *local = localtime(&now);
    hours = local->tm_hour;      	// get hours since midnight (0-23)
    minutes = local->tm_min;     	// get minutes passed after the hour (0-59)
    seconds = local->tm_sec;     	// get seconds passed after minute (0-59)
    day = local->tm_mday;        	// get day of month (1 to 31)
    month = local->tm_mon + 1;   	// get month of year (0 to 11)
    year = local->tm_year + 1900;	// get year since 1900
    if(exist()==-1)
    {
        printf("aucun fichier technicien n'est present ");
        if(add_tech()==0)
        {
            printf("le technicien a ete ajouté avec succe\n ");
        }
    }
    tech t=get_tech();
    system("cls");
    system("color FC");
    printf("\n\n\t\t\t\t\t\t%s\n\n\t\t\t\t\t\tBonjour %s %s  ",ctime(&now),strupr(t.nom),strupr(t.prenom));
    menu(&F);
}
