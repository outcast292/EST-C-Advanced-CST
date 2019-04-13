
#ifndef STRUCTURE_H_INCLUDED
#define STRUCTURE_H_INCLUDED
typedef struct   //structure pour la date
{
    int j,m,a;
} date;

typedef struct pc
{
    int id_article;
     int num_tele;
    char nom_clt[50];
    int tarif;
    date d_rec,d_rep,d_sort; //d_rec pour la reception , d_rep pour la reparation , d_sort pour la sortie de l'article
    int etat;
} pc;

typedef struct job  // structure pour le job
{
    int id,id_tech;
    struct job *suivant;
    pc *pic
} job;






typedef struct pile{

 job *sommet;
 int taille ;
}pile;






typedef struct
{
    int id;
    char nom[30];
    char prenom[30];
} tech;
void date_add(date *d);

#endif // STRUCTURE_H_INCLUDED

// structure pille pour les jobs

 
