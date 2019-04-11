
typedef struct {
    int j,m,a;
}date;
typedef enum etat{
    RECU,EN_DIAG,REP,DEP
}etat;
typedef struct {
    int id,id_tech;
    char nom_client[30],desc[50];
    date d_rec,d_rep;
    etat et_job;
}job;

typedef struct article {

    int id_article;
    char nom_cl[30];
    int num_tele;
    int prix;

    } article;

typedef struct {
    int id;
    char nom[30];
    char prenom[30];
    } tech;

