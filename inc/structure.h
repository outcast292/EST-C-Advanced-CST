
#ifndef STRUCTURE_H_INCLUDED
#define STRUCTURE_H_INCLUDED
typedef struct   //structure pour la date
{
    int j,m,a;
} date;
typedef struct   // structure pour le job
{
    int id,id_tech,id_article;
} job;

typedef struct pc
{

    int id_article;
    char nom_cl[15];
    char desc[50];
    int num_tele;
    int tarif;
    date d_rec,d_rep,d_sort; //d_rec pour la reception , d_rep pour la reparation , d_sort pour la sortie de l'article
    int etat;
} pc;

typedef struct
{
    int id;
    char nom[30];
    char prenom[30];
} tech;
void date_add(date *d);

#endif // STRUCTURE_H_INCLUDED
