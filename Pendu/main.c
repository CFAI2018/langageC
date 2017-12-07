#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void affiche_pendu(unsigned char);
unsigned char LetterSearch(unsigned int , char *);

char pendu[8][6]={
	{"|____ "},
	{"|// | "},
	{"|/  0 "},
	{"|  \\|/"},
	{"|   | "},
	{"|  / \\"},
	{"|_____"},
	{"|====="}
};

char affipendu[8][6]={
	{9,8,8,8,8,8},
	{9,7,7,10,6,10},
	{9,7,10,10,5,10},
	{9,10,10,3,4,2},
	{9,10,10,10,4,10},
	{9,10,10,1,10,0},
	{9,10,10,10,10,10},
	{10,10,10,10,10,10}
};

int main(int argc, char **argv)
{
	unsigned char nb_coup=10;
	char word[3][26]={"txomin"};
	char *p_word_readable=&word[0][0];
	char occurrence=0;
	unsigned int word_lenght=strlen(p_word_readable);
	do{
		*(p_word_readable+26)='_';
	}while(*(++p_word_readable)!='\0');
	p_word_readable=&word[0][0];
	affiche_pendu(nb_coup);
	printf("Bienvenue dans le jeu du Pendu\n");
	printf("Mot à trouver : %s\n",p_word_readable+26);
	do{
		printf("Il vous reste %d coup(s)\nSaississez votre lettre : ",nb_coup);
		occurrence=LetterSearch(tolower(getchar()),p_word_readable);
		if(occurrence){
			word_lenght-=occurrence;
		}else{
			nb_coup--;
		}
		//printf("\e[1;1H\e[2J");
		system("clear");
		affiche_pendu(nb_coup);
		//printf("vous avez précedemment saisi : %s\n",(p_word_readable+52));
		printf("Résultat : %s\n",(p_word_readable+26));
		while((getchar()) != '\n');
	}while(nb_coup&&word_lenght);
	if(word_lenght){
		printf(":( Vous avez perdu :(");
	}else{
		printf(":) Vous avez gagné :)");
	}
	printf("\nVoici le mot à trouver : %s \net vous avez trouvé : %s\n",p_word_readable,p_word_readable+26);
	return 0;
}

unsigned char LetterSearch(unsigned int letter, char *p_word_readable){
	unsigned char letterfound=0;
	unsigned char index=-1;
	do{
		index++;
		if(*(p_word_readable+52+index)==letter){
			printf("Lettre déjà saisie !\n");
			return 0;
		}
	}while(*(p_word_readable+52+index)!='\0');
	*(p_word_readable+52+index)=letter;
	do{
			if((*(p_word_readable)==letter)){
				*(p_word_readable+26)=letter;
				letterfound++;
			}
	}while(*(++p_word_readable)!='\0');
	return letterfound;
}

void affiche_pendu(unsigned char etat){
	unsigned char index_x=0;
	unsigned char index_y=0;
	for(index_y=0;index_y<8;index_y++){
		for(index_x=0;index_x<6;index_x++){
			if(affipendu[index_y][index_x]>=etat){
				printf("%c",pendu[index_y][index_x]);
			}
		}
		printf("\n");
	}
	return;
}