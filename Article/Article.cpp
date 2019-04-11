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
Article * init_Article(Article* a){
	
	a = NULL;
	return a;
}


 Article * add_Article(Article *a ){
  
 Article * nv_article = (Article*)malloc(sizeof (Article));
 if (nv_article == NULL) return 0; 
 
 nv_article->nom_clt =(char*) malloc(sizeof(char));
 if (nv_article->nom_clt == NULL) return 0;
 
  nv_article->suivant = a;
  
  
 printf("entre le nom du client");
 scanf("%s",&nv_article->nom_clt);
 
  
 printf("entre le numero : ");
 scanf("%d",&nv_article->number);
 
  
 printf("entre le id de la piece : ");
 scanf("%d",&nv_article->id_article);
 
  
 printf("entre le prix de la piece : ");
 scanf("%d",&nv_article->prix);
 
 

 
 
 
 FILE * f ;
 f = fopen("produit_ajouter.txt","w+");
 
 	if(f == NULL) return 0;
 	printf("\n confirme\n");
 	fprintf(f,"%s\n%d\n%d\n%d\n",nv_article->nom_clt,nv_article->number,nv_article->id_article,nv_article->prix);
 	printf("\n confirme\n");
 	fclose(f);
 
 
 
 
 return nv_article;
 
 }
 
 
 
 main(){
 	
 	Article *a = (Article*)malloc(sizeof(Article));
 	init_Article(a);
 	add_Article(a);
 	
 	
 }









