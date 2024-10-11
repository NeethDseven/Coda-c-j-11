#include <stdio.h>
#include "display.h"

void afficherCadre(int largeur, int longueur, int xO, int yO, int xX, int yX, int xP,int yP){

		for (int i = 0; i < longueur; i++){

			for (int j = 0; j < largeur; j++){
		
				if (i == 0 || i == longueur - 1 || j == 0 || j == largeur - 1) {
				printf("#");
				}
					else if (i == yO && j == xO){
						printf("O");
					}
					else if ( i == yX && j == xX){
						printf("X");
					}
					else if (i == yP && j == xP){
						printf(".");
					}
					else {
					printf(" ");
					}
				}
				printf("\n");
			}
}


void deplacerPersonnage(int *xO, int *yO, char choix, int largeur, int longueur){
	
	int newXO = *xO;
	int newYO = *yO;

	switch (choix) {

		case 'z' : 
			newYO--;
			break;

		case 's' : 
			newYO++;
			break;

		case 'q' : 
			newXO--;
			break;

		case 'd' : 
			newXO++;
			break;
		default: 
			printf("déplacement impossible!\n");
			return;
	}
		if (newXO > 0 && newXO < largeur - 1 && newYO > 0 && newYO < longueur -1){
	*xO = newXO;
	*yO = newYO;
}
 		else{
 			printf("déplacement impossible!\n");
 		}
}