/*
Made by MARDINI Alexandre
*/
#define SCREEN_WIDTH 320
#define SCREEN_HEIGHT 240

boolean TestSD(int SD_PIN){ // Definit si la SD est accessible
  
    if (!SD.begin(SD_PIN)) {
        
        ShowMessage("Probleme SD");
        Serial.println("Probleme SD. Please reboot with SD Card.");
        return false;  
}
    else{
      Serial.println("SD Initialized");    
      return true;
        
  }
}

void WalkDirectory(File dir) // Trouve le dossier dans lequelle le fichier se trouve
{
    for (;;) {
        File entry =  dir.openNextFile();
        if (! entry) {
            // no more files
            break;
        }
        if (entry.isDirectory()) {
            WalkDirectory(entry);
        } else {
            LoadImage(entry);
        }
        entry.close();
        // delay for a while between each image
        delay(2000);
    }
}

void LoadImage(File& file) // Suite pour charger une image ligne par ligne (lit ligne par ligne le .RAW)
{
    for (int y = 0; y < SCREEN_HEIGHT && file.available(); y++) {
        uint16_t buf[SCREEN_WIDTH];
        for (int x = SCREEN_WIDTH - 1; x >= 0; x--) {
            byte l = file.read();
            byte h = file.read();
            buf[x] = ((uint16_t)h << 8) | l;
           
        
      }
        
        ScreenLCD.drawPixelLine(0, y, SCREEN_WIDTH, buf);
     
  }
   Serial.println("EndImage"); 
}
