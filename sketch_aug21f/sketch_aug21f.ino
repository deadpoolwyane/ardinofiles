#include <LedControl.h>


int ii = 0;

LedControl lclm=LedControl(7,5,6,2);

const uint64_t IMAGES[] = {0x0010107c10100000,0x0000003c00000000,0x006c38fe386c0000,0x00060c1830600000,0x60660c1830660600,0x00003c003c000000,0x000000365c000000};
const int IMAGES_LEN = sizeof(IMAGES)/8;


void displayImage(uint64_t image) {for (int ii = 0; ii < 8; ii++) { byte row = (image >> ii * 8) & 0xFF; for (int jj = 0; jj < 8; jj++) { lclm.setLed(1, ii, jj, bitRead(row, jj)); } } }

void setup() {

}

void loop() {
    lclm.setIntensity(0,15);
    lclm.setRow(0,0,B01111110);lclm.setRow(0,1,B10000001);lclm.setRow(0,2,B10011001);lclm.setRow(0,3,B10111101);lclm.setRow(0,4,B10111101);lclm.setRow(0,5,B10011001);lclm.setRow(0,6,B10000001);lclm.setRow(0,7,B01111110);
    lclm.setIntensity(1,15);
    lclm.setRow(1,0,B01111110);lclm.setRow(1,1,B10000001);lclm.setRow(1,2,B10011001);lclm.setRow(1,3,B10111101);lclm.setRow(1,4,B10111101);lclm.setRow(1,5,B10011001);lclm.setRow(1,6,B10000001);lclm.setRow(1,7,B01111110);
    lclm.setRow(0,0,B00000000);lclm.setRow(0,1,B00000011);lclm.setRow(0,2,B00000101);lclm.setRow(0,3,B00001001);lclm.setRow(0,4,B00010111);lclm.setRow(0,5,B00100111);lclm.setRow(0,6,B01000001);lclm.setRow(0,7,B01111111);
    lclm.setRow(1,0,B00000000);lclm.setRow(1,1,B11000000);lclm.setRow(1,2,B10100000);lclm.setRow(1,3,B10010000);lclm.setRow(1,4,B11101000);lclm.setRow(1,5,B11100100);lclm.setRow(1,6,B11000010);lclm.setRow(1,7,B11111110);
    displayImage(IMAGES[ii]);
    if (++ii >= IMAGES_LEN ) { ii = 0;}
    delay(2000);
    displayImage(IMAGES[ii]);
    if (++ii >= IMAGES_LEN ) { ii = 0;}
    delay(2000);

}
