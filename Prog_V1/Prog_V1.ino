/*
Made by MARDINI Alexandre
*/
#include <PN532.h>
#include <SPI.h>
#include <UTFT.h>
#include <SD.h>
#include <UTouch.h>
#define  NFC_DEMO_DEBUG 1


PN532 nfc(10);
UTFT ScreenLCD(ITDB32S, 38, 39, 40, 41); // Initialisation du LCD
UTouch ScreenTouch(6, 5, 4, 3, 2);
extern uint8_t SmallFont[];
extern uint8_t BigFont[];

boolean SDOK = false;
int TouchX = 0;
int TouchY = 0;



void setup(void) {
  pinMode(53, OUTPUT); // PIN SD
  
  randomSeed(analogRead(0));
  Serial.begin(9600);
  
  InitScreen();  // Initialisation Ecran
  InitTouchScreen(0);  // Initialisation pavé tactile
  
  // ----------- TEST
  //Recherchesommet(1,6);
  //SearchWay(2,5);
  //selectPage(0); // selection de la page 0
  //----------------------------------------
  
  SDOK=TestSD(53); // Test SD
  
  
  Serial.println("Load !");
  //DrawTestImage();  //Dessin du menu 0
  DrawMenu();  //Dessin du test
  Serial.println("OK !");
  
  //drawPage(1); // Affichage du menu 0
 
 
 // selectPage(1); // selection de la page 1
 
  
  
  
  //StartNFC();  // Initialisation NFC
  
}

void loop(){
  while (true)
  {
  while (ScreenTouch.dataAvailable())
  {
   GetCoord();
   //ShowCoord();
   if ((TouchX >= 53) && (TouchX <= 68) && (TouchY >= 114) && (TouchY <= 205)){ // Definition zone Tactile
     Serial.println("Detected !");
     ScreenLCD.clrScr();
     Serial.println("Cleared !");
     Serial.println("Ok !");
     ScreenLCD.print("Ok !", 10, 10);  
 } 
        
  
  }
  
  if (NFCRead() != 0) {  // Affiche les informations sur L'ID NFC tagué
     int n = GetNumber(NFCRead());
     uint32_t id = NFCRead();
     ScreenLCD.setColor(VGA_WHITE);
     ScreenLCD.print("Tag ID : " + String(id), 10, 200);
     ScreenLCD.print("Tag Corresp : " + String(n), 20, 220);
     delay(4000);
     ScreenLCD.setColor(VGA_BLACK);
     ScreenLCD.print("Tag ID : " + String(id), 10, 200);
     ScreenLCD.print("Tag Corresp : " + String(n), 20, 220);
 
 } 
}
}
