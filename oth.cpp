#include <iostream>
using namespace std;
const int MAX=10;  //taille du plateau de jeu
const char BLANC= 'X';
const char NOIR= 'O';
 
void initialisation (char jeu[MAX][MAX]) //Initialise le plateau
{
 
    for (int j=0; j<MAX; j++) // i ligne
    {  
         
        for (int i=0; i<MAX;i++) // j colonne
        {
             
            if (i==(MAX/2)-1 && j==(MAX/2)-1)
                jeu[i][j]='O';
            else if (i==MAX/2 && j==MAX/2)
                jeu[i][j]='O';
            else if (i==MAX/2 && j==(MAX/2)-1)
                jeu[i][j]='X';
            else if (i==(MAX/2)-1 && j==MAX/2)
                jeu[i][j]='X';
            else
                jeu[i][j]='.'; // Les . sont les cases vides
             
            cout<<jeu[i][j];
            cout<<" ";
             
        }
         
        cout<<endl;
    }
}


 
void affichage (char jeu[MAX][MAX]) // Affiche le plateau
{
for (int i=0; i<MAX; i++)
	{
	for (int j=0;j<MAX; j++)
		{
		cout<<jeu[i][j];
		cout<<" ";
		 }
	cout<<endl;
	}
                 
}



void retournement (char couleur, char jeu[MAX][MAX]) // fait placer le pion et retourne les pions concernes
{
int i=0, j=0; // position du pion place par le joueur
int k=0, h=0; // position dans les boucles for pour remonter les files de pions adverses
int di=0, dj=0; // directions de deplacement pour remonter les files de pions adverses
int canplayhere=0; // 0 s'il n'y a rien à capturer dans aucune des 8 directions



char couleur_adv; //couleur de l'adversaire
if (couleur==BLANC) couleur_adv = NOIR;
else couleur_adv = BLANC;

while (canplayhere==0) 
	{



	cout<<"Veuillez entrer une coordonnee selon x :"<<endl;
	cin>>i;
	cout<<"Veuillez entrer une coordonnee selon y :"<<endl;
	cin>>j;
	cout<<endl;

	if (jeu[i][j] != '.') cout<<"Cette case est deja occuppee, recommencez svp."<<endl<<endl;
	else 	
		{	

		for (di=-1; di<=1; di++)
			{
			for (dj=-1; dj<=1; dj++) // on check dans les 8 directions pour voir s'il y a une file de pions adverses à remonter
				{
				if (di!=0 || dj!=0) // inutile de checker le cas di=dj=0, c'est la position du pion à jouer
					{
					cout<<"DEBUG: di = "<<di<<", dj = "<<dj<<endl;
					if (jeu[i+di][j+dj] == couleur_adv)
						{
						cout<<"DEBUG: direction trouvee (jeu[i+di][j+dj] == couleur_adv) "<<endl;

						k=i+di;
						h=j+dj;
						while( k>0 && k<MAX && h>0 && h<MAX && jeu[k][h] == couleur_adv)
						// s'il y a un pion dans une direction, on remonte cette direction
						// jusqu'à ce qu'on trouve un pion de notre couleur de l'autre côté
						// ou que la fin du plateau soit atteinte
						// ATTENTION ça ne marche pas sur les bords pour l'instant
							{
							k+=di;
							h+=dj;
							cout<<"DEBUG: progression de la remontee: k = "<<k<<", h = "<<h<<endl;
							}
						if (jeu[k][h] == couleur)
						// dans le cas où la file de pions adverses se termine par un pion de notre couleur
							{
							cout<<"DEBUG: if (jeu[k][h] == couleur)"<<endl;
							// on valide le placement de pion
							canplayhere++;
							// on revient au début de la file
							k=i+di;
							h=j+dj;
							// puis on la re-remonte et on change la couleur de chaque pion adverse
							while( k>0 && k<MAX && h>0 && h<MAX && jeu[k][h] == couleur_adv)
								{
								jeu[k][h] = couleur;
								k+=di;
								h+=dj;
								}
							}
			
						}

					}
				}
			}


		if (canplayhere ==0) cout <<"Impossible de jouer ici: vous devez capturer au moins un pion."<<endl;
		else jeu[i][j] = couleur; // on n'oublie pas de poser le pion sur le plateau
		}	
	affichage(jeu);
	cout<<endl<<endl;
	}

/*
if (i==j+1) // À CHANGER !!! Ne marche pas pour toutes les positions !!!
	{
	jeu[i][j+1]='X';
	}
else if (j==i+1)
	{
	jeu[i+1][j]='X';
	}
     */
}
 

 
 
int main()
{
	char jeu[MAX][MAX],tour,couleur = BLANC;
	bool save_game;
	int score_blanc=0,score_noir=0,i=0,j=0;
	
	initialisation(jeu);

	retournement(couleur,jeu);
	affichage(jeu);
     
}
