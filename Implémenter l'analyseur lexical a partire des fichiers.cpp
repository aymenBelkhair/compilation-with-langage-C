#include <stdio.h>
#include <stdlib.h>
struct matri{int** m=NULL;int l=0;int c=0;
};
struct mote{char* t=NULL;int taille=0;
};


 matri saisireMatrice(){
 matri mat;
 int i,j,l,c;
 FILE *f;
 if (f == NULL) return mat;
 else {
 
 f=fopen("matrice.txt","r");
 fscanf(f,"%d\n",& mat.l);
 fscanf(f,"%d\n",& mat.c);
  mat.m=(int**)malloc( mat.l*sizeof(int**));
 for(i=0;i< mat.l;i++){
 	 mat.m[i]=(int*)malloc( mat.c*sizeof(int));
 	for(j=0;j< mat.c;j++){
 		fscanf(f,"%d/n",& mat.m[i][j]);
	                     }
                       }	
        return mat;     }
fclose(f);	
}
void afficheMatrice(matri mat){
	for(int i=0;i<mat.l;i++)
	for(int j=0;j<mat.c;j++) printf("t[%d][%d] = %d\n",i,j,mat.m[i][j]);
}
mote saisireMot(){
	FILE *f;
	mote mot;
	int i,n;
	f=fopen("mot.txt","r");
	
	if(f!=NULL){
	fscanf(f,"%d",&mot.taille);
		mot.t=(char*)malloc(mot.taille*sizeof(char));
		for(i=0;i<mot.taille;i++){
			fscanf(f,"%s\n",&mot.t[i]);
		}
		printf("le mot est : ");
		for(i=0;i<mot.taille+1;i++) {printf("%c",mot.t[i]);
		}fclose(f);
	return mot;		
	}
	else return mot;
	
}
int* convertire(mote mot){
	int* t;
	t=(int*)malloc(mot.taille*sizeof(int));

   for(int i=0;i<mot.taille;i++){
 
		   if(mot.t[i]=='0') t[i]=0;
		  else if(mot.t[i]=='1') t[i]=1;
		  else if(mot.t[i]=='2') t[i]=2;
		  else if(mot.t[i]=='3') t[i]=3;
		  else if(mot.t[i]=='4') t[i]=4;
		  else if(mot.t[i]=='5') t[i]=5;
		  else if(mot.t[i]=='6') t[i]=6;
		  else if(mot.t[i]=='7') t[i]=7;
		  else if(mot.t[i]=='8') t[i]=8;
		  else if(mot.t[i]=='9') t[i]=9;
		  else if(mot.t[i]=='+') t[i]=10;
		  else if(mot.t[i]=='x') t[i]=11;
		  
		  else printf("le mot n'apertienne pas au DF  ");	
  }
  return t;
	
}
int trace(matri mat,int* l,mote mot){
		
	int trace=mat.m[0][l[0]];
	int opt=0;
	
	while(trace!=-1&&opt<mot.taille){trace=mat.m[trace][l[opt]]; 
		opt++;
	}
	
	return trace;
	
}
int reconnaissence(int etat){
	if(etat==8) return 1;
	else return 0;
}



int main(){
	matri mat;
	int i,c,j,*l,etat;
	mote mot;
	char *t;
	mat=saisireMatrice();
	
	afficheMatrice(mat);
	
	mot=saisireMot();
	
	l=convertire(mot);
	
	//affiche mot
	
	for(i=0;i<mot.taille;i++) printf("\nt[%d]=%d",i,l[i]);
	
	etat=trace(mat,l,mot);
	
	if(reconnaissence(etat)) printf("\nle mot appartient au langage");
	
	else printf("\nle mot n'est pas reconnue");
	

	}
	











