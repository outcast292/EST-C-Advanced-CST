#include<stdlib.h>
#include<stdio.h>
#include<string.h>
// Article structur declaration with the add function 
typedef struct Article{
	
	int id_article;
	int number;
	char *nom_art;
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
 
 nv_article->nom_art =(char*) malloc(sizeof(char));
 if (nv_article->nom_art == NULL) return 0;
 
  nv_article->suivant = a;
  
  
 printf("entre le nom du piece");
 scanf("%s",nv_article->nom_art);
 
  
 printf("entre le numero : ");
 scanf("%d",&nv_article->number);
 
  
 printf("entre le id de la piece : ");
 scanf("%d",&nv_article->id_article);
 
  
 printf("entre le prix de la piece : ");
 scanf("%d",&nv_article->prix);
 
 

 
 
 
 FILE * f ;
 f = fopen("produit_ajouter.txt","a+");
 
 	if(f == NULL) return 0;
 
 	
 	fprintf(f,"\n%d\n%d\n%d\n%s\n",nv_article->prix,nv_article->number,nv_article->id_article,nv_article->nom_art);
 	
 
 	fclose(f);
 
 return nv_article;
 
 }
 

 
 
 // repared Articles :   structure repair article function
 
 typedef struct Article_repare{
int id_Article;
struct Article_repare *suivant;
}Article_repare;

typedef struct pile{

Article_repare *sommet;
int taille;
int Article_id;
}pile;

void init_pile(pile *p){
p->sommet=NULL;
p->taille =0;

}
 
 
 
  int go_to_repare(Article *a){
 	char nomp[50];
 	
 	printf("\nentre le nom de la piece a repare : ");
 	scanf("%s",nomp);
 	
int i;
 	Article * tmp = a;
 	for(i=0;i<4;i++){
 		
 		if(strcmp(tmp->nom_art,nomp) == 0) {
 			
 			FILE *g= fopen("go_to_repare.txt","w+");
 fprintf(g,"%d\n",tmp->id_article);
 fclose(g);
 printf("confirme");
 return 1;
		 }else{
		 	
		 	tmp = tmp->suivant;
		 	
		 }
 		
 		
	 }
 }
 
 
 int empilement(pile *p){
 	
 	Article_repare * nva=(Article_repare*)malloc(sizeof(Article_repare));
 	if (nva==NULL) return 0;
 	
 	FILE *m = fopen("go_to_repare.txt","r");
 	fscanf(m,"%d\n",p->Article_id);
 	
 	nva->suivant = p->sommet;
 	p->sommet=nva;
 	p->taille++;
 	
 	
 	return 1;
 }
 
 
 main(){
 	
 	Article *a = (Article*)malloc(sizeof(Article));
	pile *p = (pile*)malloc(sizeof(pile));
 	init_Article(a);
 	init_pile(p);
 	int i,n;
 	/*printf("entre le nombre des article a ajouter : ");
 	scanf("%d",&n);
 	
 	
 	for(i=0;i<n;i++)
 	add_Article(a);
 	*/
 	
 	//go_to_repare(a);
 	//empilement(p);
 	
 }









