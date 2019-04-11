#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct article{
	int taill;
	char etat[50];
	int id;
	char nom[50]; 
	int prix;
	struct article * suivant;
}article;

article * init_article(article *a){
	a->suivant=NULL;
	a->taill=0;
}

article * ajouter_article(article *a){
	
	article * nv=(article*)malloc(sizeof(article));
	if(nv == NULL) return NULL;
	
	printf("entre le nom de l'article : ");
	scanf("%s",nv->nom);
	
	printf("entre l'ID de l'article : ");
	scanf("%d",&nv->id);
	
	printf("entre le prix :  ");
	scanf("%d",&nv->prix);
	
	strcpy(nv->etat,"non reparé");
	
	
}


main(){
	article *a=(article*)malloc(sizeof(article));
	a=init_article(a);
	ajouter_article(a);
	
	
}

