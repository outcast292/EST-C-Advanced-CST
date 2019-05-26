#include "../inc/tech_funcs.h"
#include "../inc/structure.h"
#include "stdio.h"
#include "string.h"
void pass_input(char pass[])
{
    int i=0;
        do{
        pass[i]=getch();
        if(pass[i]!='\r'){
            printf("*");
        }
        i++;
    }while(pass[i-1]!='\r');
     pass[i-1]='\0';
}
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
    system("COLOR 0C");
     tech t;
    FILE *tmp=fopen("fl/tech","r");
    printf("\n\n\t\tentrer votre login : ");
    char nom[50];
    scanf("%s",nom);
    while(!feof(tmp)){
        fscanf(tmp,"%d %s %s %s %s",&t.id,&t.nick,&t.prenom,&t.nom,&t.password);
        if(strcmp(t.nick,nom)==0){
            printf("\n\n\t\tentrer votre mot de passe : ");
            pass_input(nom);
            if(strcmp(nom,t.password)==0){
                fclose(tmp);
                return t;
            }
        }
    }

    fclose(tmp);
    printf("\n\n\t ERREUR: utilisateur non trouv\202 ,on va re-essayer");
    printf("\n\n\t\t\t*******************");
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
