
#ifndef STRUCTURE_H_INCLUDED
#define STRUCTURE_H_INCLUDED
typedef struct   //structure pour la date
{
    int j,m,a;
} date;

typedef struct pc
{
    int id;
    int num;
    char nom_clt[50];
    int tarif;
    date d_rec,d_rep,d_sort; //d_rec pour la reception , d_rep pour la reparation , d_sort pour la sortie de l'article
    int etat;
} pc;

typedef struct job  // structure pour le job
{
    struct job *suivant;
    pc *pic:
} job;

typedef struct file
{
    job *tete;
    job *que;
    int taille ;
} file;






typedef struct
{
    int id;
    char nom[30];
    char prenom[30];
} tech;
void date_add(date *d);

#endif // STRUCTURE_H_INCLUDED

// structure pille pour les jobs


