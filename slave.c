#include <xc.h>

#define _XTAL_FREQ 20000000  // 20MHz Crystal

void SPI_SlaveInit() {
    TRISC5 = 1;  // SDO input
    TRISC3 = 1;  // SCK input
    TRISA5 = 1;  // SS input
    TRISC4 = 0;  // MISO output
    TRISB = 0x00; // PORTB as output
    
    SSPSTAT = 0x00;
    SSPCON = 0x34; // SPI Slave mode
}

char SPI_Read() {
    while(!SSPSTATbits.BF); // Wait for data reception
    return SSPBUF;  // Return received data
}

void main() {
    SPI_SlaveInit();
    
    while (1) {
        PORTB = SPI_Read(); // Display received data on PORTB
    }
} 