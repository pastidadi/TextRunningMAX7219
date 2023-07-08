#include <MD_Parola.h>
#include <MD_MAX72xx.h>
#include <SPI.h>

// Definisikan pin SPI yang digunakan
#define HARDWARE_TYPE MD_MAX72XX::FC16_HW
#define MAX_DEVICES 4

#define CLK_PIN   13
#define DATA_PIN  11
#define CS_PIN    10

// Inisialisasi objek untuk modul dot matrix
MD_Parola myDisplay = MD_Parola(HARDWARE_TYPE, CS_PIN, MAX_DEVICES);

// Teks yang akan ditampilkan
char text1[] = "Channel";

char text2[] = "Pasti Dadi";

bool isFirstText = true;

void setup() {
  // Inisialisasi modul dot matrix
  myDisplay.begin();
  
  // Tampilkan tulisan pertama
  displayText(text1);
}

void loop() {
  // Perbarui tampilan modul dot matrix
  if (myDisplay.displayAnimate()) {
    myDisplay.displayReset();

    if (isFirstText) {
      // Ganti ke tulisan kedua setelah tulisan pertama selesai
      clearDisplay();
       delay(1000); 
      displayText(text2);
      isFirstText = false;
      
    } else {
      // Kembali ke tulisan pertama setelah tulisan kedua selesai
      clearDisplay();
       delay(1000); 
      displayText(text1);
      isFirstText = true;
  
    }
  }
}

void displayText(char* text) {
  // Tampilkan teks dengan efek scroll dari kiri ke kanan
  myDisplay.displayText(text, PA_LEFT, 200, 0, PA_SCROLL_LEFT);
 
}

void clearDisplay() {
  // Bersihkan tampilan pada modul dot matrix
  myDisplay.displayClear();
}
