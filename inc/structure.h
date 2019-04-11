
#ifndef STRUCTURE_H_INCLUDED
#define STRUCTURE_H_INCLUDED
typedef struct { //structure pour la date
    int j,m,a;
    } date;
typedef struct etat { //strucutre pour l'etat de job
    int t;
    } etat;
typedef struct { // structure pour le job
    int id,id_tech,id_article;
    date d_rep;
    } job;

typedef struct pc {

    int id_article;
    char nom_cl[30];
    int num_tele;
    int tarif;
    date d_rec;
    etat et;
    } pc;

typedef struct {
    int id;
    char nom[30];
    char prenom[30];
    } tech;
void date_add(date *d);

#endif // STRUCTURE_H_INCLUDED
