/*
Made by MARDINI Alexandre
*/
void InitScreen (){
   
   ScreenLCD.InitLCD();
   ScreenLCD.setFont(SmallFont);
   ScreenLCD.fillScr(255,255,255);
   ScreenLCD.setContrast(32);
  

}

void ShowMessage(const char* msg1, const char* msg2 = 0) // Affiche un message
{
    ScreenLCD.setColor(255, 0, 0);
    ScreenLCD.fillRoundRect(50, 190, 270, 230);
    ScreenLCD.setColor(255, 255, 255);
    ScreenLCD.setBackColor(255, 0, 0);
    ScreenLCD.print(msg1, CENTER, 196);
    if (msg2) ScreenLCD.print(msg2, CENTER, 210);
}

void selectPage(int id){ // TEST PAGE ?
  ScreenLCD.setWritePage(id);
}
void drawPage(int id){
  ScreenLCD.setDisplayPage(id);
}

void DrawTestImage(){ // Dessine une image Ligne par ligne depuis un fichier .RAW
  
  if (SDOK==true){  
  File entry = SD.open("TEST.RAW");
    LoadImage(entry);
  }
}

void DrawMenu(){
  
  if (SDOK==true){  
  File entry = SD.open("legende.RAW");
    LoadImage(entry);
  }
}
