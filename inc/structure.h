
#ifndef STRUCTURE_H_INCLUDED
#define STRUCTURE_H_INCLUDED
typedef struct   //structure pour la date
{
    int j,m,a;
} date;
typedef struct   // structure pour le job
{
    int id,id_tech,id_article;
    char et_job[50];
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


typedef struct job_rep{

    int id;
    struct job_rep * suivant;

}job_rep;

typedef struct pile{

 job_rep *sommet;
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

 
