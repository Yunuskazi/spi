#include <xc.h>

#define _XTAL_FREQ 20000000  // 20MHz Crystal

void SPI_MasterInit() {
    TRISC5 = 0;  // SDO output
    TRISC3 = 0;  // SCK output
    TRISA5 = 0;  // SS output
    
    SSPSTAT = 0x00;
    SSPCON = 0x30; // SPI Master mode, clock Fosc/4
}

void SPI_Write(char data) {
    SSPBUF = data;  // Load data into buffer
    while(!SSPSTATbits.BF);  // Wait for transmission to complete
}

void main() {
    SPI_MasterInit();
    
    while (1) {
        SPI_Write(0x55);
        __delay_ms(1000);
        
        SPI_Write(0xAA);
        __delay_ms(1000);
    }
} 
