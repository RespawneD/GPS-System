/*
Made by MARDINI Alexandre
*/

void GetCoord(){ // Retourne les coordonnées de l'endroit appuyé sur l'écran
  ScreenTouch.read();
  TouchX=ScreenTouch.getX();
  TouchY=ScreenTouch.getY();
}

void InitTouchScreen(int state){ // Initialise la fonction tactile de l'écran
   ScreenTouch.InitTouch(state);
   ScreenTouch.setPrecision(PREC_LOW);
}

void ShowCoord(){ // Affiche les coordonnées sur l'écran
   ScreenLCD.setColor(VGA_WHITE);
   ScreenLCD.print(String(TouchX) + "/" + String(TouchY),5,30);
   delay(2000);// Efface les coord au bout de 2s
   ScreenLCD.setColor(VGA_BLACK);
   ScreenLCD.print(String(TouchX) + "/" + String(TouchY),5,30);
}
