/*************************************************** 
  This is a library for our I2C LED Backpacks

  Designed specifically to work with the Adafruit LED Matrix backpacks 
  ----> http://www.adafruit.com/products/872
  ----> http://www.adafruit.com/products/871
  ----> http://www.adafruit.com/products/870

  These displays use I2C to communicate, 2 pins are required to 
  interface. There are multiple selectable I2C addresses. For backpacks
  with 2 Address Select pins: 0x70, 0x71, 0x72 or 0x73. For backpacks
  with 3 Address Select pins: 0x70 thru 0x77

  Adafruit invests time and resources providing this open source code, 
  please support Adafruit and open-source hardware by purchasing 
  products from Adafruit!

  Written by Limor Fried/Ladyada for Adafruit Industries.  
  BSD license, all text above must be included in any redistribution
 ****************************************************/

#include <Wire.h>
#include "Adafruit_LEDBackpack.h"
#include "Adafruit_GFX.h"

Adafruit_8x8matrix matrix = Adafruit_8x8matrix();
Adafruit_8x8matrix matrix2 = Adafruit_8x8matrix();
Adafruit_8x8matrix matrix3 = Adafruit_8x8matrix();

int const ledMatrixCount = 3;
Adafruit_8x8matrix ledMatrix[ledMatrixCount];

void setup() {
  Serial.begin(9600);
  Serial.println("Multiple 8x8 LED Matrix Test");
  
  ledMatrix[0].begin(0x75);  
  ledMatrix[1].begin(0x71); 
  ledMatrix[2].begin(0x74); 
}

static const uint8_t PROGMEM
  smile_bmp[] =
  { B00111100,
    B01000010,
    B10100101,
    B10000001,
    B10100101,
    B10011001,
    B01000010,
    B00111100 },
  neutral_bmp[] =
  { B00111100,
    B01000010,
    B10100101,
    B10000001,
    B10111101,
    B10000001,
    B01000010,
    B00111100 },
  frown_bmp[] =
  { B00111100,
    B01000010,
    B10100101,
    B10000001,
    B10011001,
    B10100101,
    B01000010,
    B00111100 };

int x = 0;
void loop() {

  
  smilies();
  
  delay(500);

  /*
  matrix3.clear();
  matrix3.setRotation(3);
  matrix3.drawBitmap(0, 0, frown_bmp, 8, 8, LED_ON);
  matrix3.writeDisplay();
  delay(500);
  
  matrix2.clear();
  matrix2.setRotation(3);
  matrix2.drawBitmap(0, 0, smile_bmp, 8, 8, LED_ON);
  matrix2.writeDisplay();
  delay(500);  
  
  matrix.clear();
  matrix.drawBitmap(0, 0, smile_bmp, 8, 8, LED_ON);
  matrix.writeDisplay();
  delay(500);

  matrix.clear();
  matrix.drawBitmap(0, 0, neutral_bmp, 8, 8, LED_ON);
  matrix.writeDisplay();
  delay(500);

  matrix.clear();
  matrix.drawBitmap(0, 0, frown_bmp, 8, 8, LED_ON);
  matrix.writeDisplay();
  delay(500);

  matrix.clear();      // clear display
  matrix.drawPixel(0, 0, LED_ON);  
  matrix.writeDisplay();  // write the changes we just made to the display
  delay(500);

  matrix.clear();
  matrix.drawLine(0,0, 7,7, LED_ON);
  matrix.writeDisplay();  // write the changes we just made to the display
  delay(500);

  matrix.clear();
  matrix.drawRect(0,0, 8,8, LED_ON);
  matrix.fillRect(2,2, 4,4, LED_ON);
  matrix.writeDisplay();  // write the changes we just made to the display
  delay(500);

  matrix.clear();
  matrix.drawCircle(3,3, 3, LED_ON);
  matrix.writeDisplay();  // write the changes we just made to the display
  delay(500);

  matrix.setTextSize(1);
  matrix.setTextWrap(false);  // we dont want text to wrap so it scrolls nicely
  matrix.setTextColor(LED_ON);
  for (int8_t x=0; x>=-36; x--) {
    matrix.clear();
    matrix.setCursor(x,0);
    matrix.print("Hello");
    matrix.writeDisplay();
    delay(100);
  }
*/
  

  matrix.setRotation(0);
  }


    void clearAll() {
      for(uint8_t i=0; i<ledMatrixCount; i++) {
        ledMatrix[i].clear();
      }
    }

    void writeAllDisplays() {
      for(uint8_t i=0; i<ledMatrixCount; i++) {
        ledMatrix[i].writeDisplay();
      }
    }
    
  void smilies() {
    clearAll();  
    
    ledMatrix[0].setRotation(3);  
    ledMatrix[1].setRotation(3); 
    ledMatrix[2].setRotation(3); 
    
    if (x==0) {
      ledMatrix[0].drawBitmap(0, 0, frown_bmp, 8, 8, LED_ON);
    } else if (x==1) {
      ledMatrix[1].drawBitmap(0, 0, neutral_bmp, 8, 8, LED_ON);
    } else if (x==2) {
      ledMatrix[2].drawBitmap(0, 0, smile_bmp, 8, 8, LED_ON);
    }
    x++;
    if (x==3) { x = 0; }
    
    writeAllDisplays();  
    
  
    delay(500);
  }
  
  void scroll(char *string) {
    matrix.setRotation(3);
    matrix2.setRotation(3);
    matrix3.setRotation(3);
    
    
    for (int8_t x=7; x>=-36; x--) {
    matrix.clear();
    matrix2.clear();
    matrix3.clear();
    
      matrix.setCursor(x,0);
      matrix.print("World");
      matrix.writeDisplay();
  
      if (x+5 < 0) {
      matrix2.setCursor(x+5,0);
      matrix2.print("World");
      }
      matrix2.writeDisplay();
  
      /*
      matrix3.setCursor(x+11,0);
      matrix3.print("World");*/
      matrix3.writeDisplay();
      
      delay(500);
    }

}

