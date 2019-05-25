#include "../inc/tech_funcs.h"
#include "../inc/structure.h"
#include "stdio.h"
#include "string.h"

int exist()   // dunc to test if the file exist or no, return -1 for no
{
    FILE *tmp=fopen("fl/tech", "r");
    if(tmp==NULL)
    {
        fclose(tmp);
        return -1;
    }
    else
    {
        return 0;
    }
}
tech get_tech()   // func to give back the info of the user
{
     tech t;
    FILE *tmp=fopen("fl/tech","r");
    printf("\n\tentrer votre login :");
    char nom[50];
    scanf("%s",nom);
    while(!feof(tmp)){
        fscanf(tmp,"%d %s %s %s %s",&t.id,&t.nick,t.prenom,t.nom,t.password);
        if(strcmp(t.nick,nom)==0){
            printf("entrer votre mot de passe");
            scanf("%s",nom);
            if(strcmp(nom,t.password)==0){
                fclose(tmp);
                return t;
            }
        }
    }

    fclose(tmp);
    printf("utilisateur non trouvé ,on va re-essayer");
    return get_tech();
}
int add_tech()   //func to add tech to the file
{
    int id=1;
    char nom[30],prenom[30];
    printf("\n\tentrer votre nom : ");
    scanf("%s",nom);
    printf("\n\tentrer votre prenom : ");
    scanf("%s",prenom);
    FILE* tmp=fopen("fl/tech","w");
    if(tmp==NULL)
    {
        printf("fichier non ouvert");
    }
    fprintf(tmp,"%d %s %s",id,nom,prenom);
    fclose(tmp);
    return 0;

}
