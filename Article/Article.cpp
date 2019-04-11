#include<stdlib.h>
#include<stdio.h>
#include<string.h>

typedef struct Article{
	
	int id_article;
	int number;
	char *nom_clt;
	int prix;
	
	struct Article *suivant;
	
	
}Article;
Article * init_list(Article* a){
	
	a = NULL;
	return a;
}


 Article * add_Article(Article *a , char* nv_art, int num, int tele, int id, int prix){
 
 Article * nv_article = (Article*)malloc(sizeof (Article));
 if (nv_article == NULL) return 0; 
 
 nv_article->nom_clt =(char*) malloc(sizeof(char));
 if (nv_article->nom_clt == NULL) return 0;
 
 a->suivant = nv_article;
 strcpy(nv_article->nom_clt,a->nom_clt);
 
 nv_article->id_article = id;
 nv_article->number = a->number;
 nv_article->prix = prix;
 
 
 
 
 }









