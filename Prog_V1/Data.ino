/*
Made by MARDINI Alexandre
*/
int tableau[7][2] = {{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0}};


void AfficheTableau(){
 Serial.println("");
  for (int y = 0 ; y < 2 ; y++){
    for (int x = 0 ; x < 7 ; x++){
    int s = tableau[x][y];
    Serial.print(String(s) + "|");
    }
    Serial.println("");
  
}
Serial.println("");
}


void Recherchesommet(int first, int second){
int indexIncrement = 0;
int sInt = 0;
int chemin[7] = {0,0,0,0,0,0,0};
int sDeb = 0;
int sFin = 0;
int sIntermediaire = 0;
int distDeb = 0; // distance entre sommet du début et de la fin (0 au départ)
int minimum = 0;
int distance = 0;
int distance_totale = 0;
int prochain_sommet = 0;
int trueExiste = 7;

int infini = 100000;
int nbSommet = 7;
int sommetNonMarque[7] = {1,1,1,1,1,1,1};

int matrice[7][7]={{0,31,0,0,0,0,0},
                   {31,0,47,0,0,0,0},
                   {0,47,0,56,24,0,0},
                   {0,0,56,0,0,0,20},
                   {0,0,24,0,0,14,0},
                   {0,0,0,0,14,0,40},
                   {0,0,0,20,0,40,0}};
                  
sDeb = first;
sFin = second;
sIntermediaire = sDeb;
tableau[sDeb][1] = 0;
tableau[sDeb][2] = sDeb;
AfficheTableau();
delay(500);
sommetNonMarque[sDeb] = 0;


Serial.println("VARIABLES CHARGES");


delay(500);






while(trueExiste > 0){ 
  trueExiste = 7;
  minimum = infini;
  
  for (int k = 1; k < nbSommet; k++){
    if (k != sDeb){
      if (sommetNonMarque[k]==1){
        distance = matrice[k][sIntermediaire];
        distance_totale = distDeb + distance;
        if (distance != 0 && distance_totale < tableau[k][1]){
           tableau[k][1] = distance_totale;
           tableau[k][2] = sIntermediaire;
             
      }
        if (tableau[k][1] < minimum){
          minimum = tableau[k][1];
          prochain_sommet = k;
        }
      }
    }
  sIntermediaire = prochain_sommet;
  sommetNonMarque[sIntermediaire] = 0;
  distDeb = tableau[sIntermediaire][1];
  }
  
  for (int i=1; i<sizeof(sommetNonMarque); i++) {
   if (sommetNonMarque[i]==0) {
     trueExiste --;
   }
  }
}

sInt = sFin;

chemin[indexIncrement] = sFin + 1;
indexIncrement ++;
while (sInt != sDeb){
  sInt = tableau[1][sInt];
  chemin[indexIncrement] = sInt + 1;
  indexIncrement ++;
}

for (int l = 1 ; l <= sizeof(chemin); l++){
  int u = chemin[l];
  Serial.print(String(u) + ", ");
}

}


