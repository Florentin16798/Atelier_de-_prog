// Imagine++ project
// Project:  Tennis
// Author:   renaud
// Date:     2007/10/9
// TP #2 du cours de C++ de l'ENPC

#include <Imagine/Graphics.h>
using namespace Imagine;

//////////////////////////////////////////////////////////////////
// Fonction de gestion du clavier
// Pour l'instant, utiliser sans se soucier du fontionnement
// Retourne dans sens1 (resp. sens2) -1, 1 ou 0 pour le joueur 1
// (resp. joueur 2) suivant qu'il appuie sur la touche gauche,
// droite ou sur aucune touche.
void Clavier(int& sens1, int& sens2) {
	static bool left1=false,right1=false,left2=false,right2=false;
	Event e;
	do {
		getEvent(0,e);
		if (e.type==EVT_KEY_ON || e.type==EVT_KEY_OFF) {
			bool push=(e.type==EVT_KEY_ON);
			switch (e.key) {
			case 's': case 'S':
				left1=push;
				break;
			case 'd': case 'D':
				right1=push;
				break;
			case 'k': case 'K':
				left2=push;
				break;
			case 'l': case 'L':
				right2=push;
				break;
			}
		}
	} while (e.type!=EVT_NONE);
	sens1=(left1?-1:(right1?1:0));
	sens2=(left2?-1:(right2?1:0));
}

//////////////////////////////////////////////////////////////////
// Fonction principale
int main()
{
	// Ouverture de la fenetre
	openWindow(256,256);
	// Position et vitesse de la balle
	int xb=128,
	    yb=20,
	    ub=2,
	    vb=3;
	// Boucle principale
	while (true) {
		// Affichage de la balle
		fillRect(xb-3,yb-3,7,7,RED);
		// Temporisation
		milliSleep(20);
		// Effacement de la balle
		fillRect(xb-3,yb-3,7,7,WHITE);
		// Rebond
		if (xb+ub>253)
			ub=-ub;
		// Mise a jour de la position de la balle
		xb+=ub;
		yb+=vb;
	}
	endGraphics();
	return 0;
}
