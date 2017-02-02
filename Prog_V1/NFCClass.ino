/*
Made by MARDINI Alexandre
*/
void StartNFC(){ // Initialise le NFC
  nfc.begin();
  nfc.SAMConfig();
  Serial.print("NFC Loaded !");
}

int GetNumber(uint32_t ID){
   int r=0;
  #ifdef NFC_DEMO_DEBUG 
  switch(ID) {
    case(2375070565): {r=1 ;}break;  
    case(2906566518): {r=2 ;}break;
    case(887833076):  {r=3 ;}break;
    case(1195714081): {r=4 ;}break;
    case(862658969):  {r=5 ;}break;
    case(54337689):   {r=6 ;}break;
    case(3544130772): {r=7 ;}break;
    case(320284372):  {r=8 ;}break;
    case(2751080148): {r=9 ;}break;
    case(446379396):  {r=10 ;}break;
    case(446379392):  {r=11 ;}break;
    }   
#endif
return r;
} 

uint32_t NFCRead(){ // lis les informations NFC
  uint32_t id;
  // look for MiFare type cards
  id = nfc.readPassiveTargetID(PN532_MIFARE_ISO14443A);
  return id;
  
}
