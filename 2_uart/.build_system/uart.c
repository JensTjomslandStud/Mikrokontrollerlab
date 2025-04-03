#include "gpio.h"

// base address 0x40002000

#define UART ((NRF_UART_REG*)0x40002000)

typedef struct {

      /* 0x000: Tasks */
      volatile uint32_t TASKS_STARTRX;               // 0x000
      volatile uint32_t TASKS_STOPRX;                // 0x004
      volatile uint32_t TASKS_STARTTX;               // 0x008
      volatile uint32_t TASKS_STOPTX;                // 0x00C
      volatile uint32_t RESERVED0[3];                // 0x010..0x018
      volatile uint32_t TASKS_SUSPEND;               // 0x01C
  
      /* 0x020..0x0FC: Reserved */
      volatile uint32_t RESERVED1[56];  // 0x020..0x0FC
  
      /* 0x100: Events */
      volatile uint32_t EVENTS_CTS;                  // 0x100
      volatile uint32_t EVENTS_NCTS;                 // 0x104
      volatile uint32_t EVENTS_RXDRDY;
      volatile uint32_t RESERVED12[4];
      volatile uint32_t EVENTS_TXDRDY;     
               // 0x108
      volatile uint32_t RESERVED2;
                         // 0x10C               // 0x110
      volatile uint32_t EVENTS_ERROR;                // 0x124
      volatile uint32_t RESERVED4[7];  // 0x128..0x140
      volatile uint32_t EVENTS_RXTO;                 // 0x144
  
      /* 0x148..0x1FC: Reserved */
      volatile uint32_t RESERVED5[46];  // 0x148..0x1FC
  
      /* 0x200: Shorts */
      volatile uint32_t SHORTS;                      // 0x200
  
      /* 0x204..0x300: Reserved */
      volatile uint32_t RESERVED6[64];  // 0x204..0x300
  
      /* 0x304: Interrupts */
      volatile uint32_t INTENSET;                    // 0x304
      volatile uint32_t INTENCLR;                    // 0x308
  
      /* 0x30C..0x47C: Reserved */
      volatile uint32_t RESERVED7[93];  // 0x30C..0x47C
  
      volatile uint32_t ERRORSRC;                    // 0x480
  
      /* 0x484..0x4FC: Reserved */
      volatile uint32_t RESERVED8[31];  // 0x484..0x4FC
  
      volatile uint32_t ENABLE;                      // 0x500
  
      /* 0x504..0x504: Reserved */
      volatile uint32_t RESERVED9[1];  // 0x504
      volatile uint32_t RESERVED2;
  
      /* 0x508: Pin Select */
      volatile uint32_t PSELRTS;                     // 0x508
      volatile uint32_t PSELTXD;                     // 0x50C
      volatile uint32_t PSELRXD;                     // 0x510
      volatile uint32_t PSELCTS;                     // 0x514
  
      /* 0x518: Data Registers */
      volatile uint32_t RXD;                         // 0x518
      volatile uint32_t RESERVED2;
      volatile uint32_t TXD;                         // 0x51C
  
      /* 0x520..0x520: Reserved */
      volatile uint32_t RESERVED10; // 0x520
  
      volatile uint32_t BAUDRATE;                    // 0x524
  
      /* 0x528..0x568: Reserved */
      volatile uint32_t RESERVED11[17]; // 0x528..0x568
  
      volatile uint32_t CONFIG;                      // 0x56C


} NRF_UART_REG;



void uart_init(){

UART -> PSELRXD=6;
UART -> PSELTXD =8;

UART-> BAUDRATE = 0x00275000; //Baud9600

UART->PSELRTS = 0xFFFFFFFF;
UART->PSELCTS = 0xFFFFFFFF;

UART->ENABLE = 4;
UART->TASKS_STARTRX=1;


}

void uart_send(char letter){
    UART->EVE
    UART->TASKS_STARTRX=1;
    if (UART->TXD == 5) {
        UART->TASKS_STOPRX;
        UART->TXRDY=0;
    }

}

char uart_read(){

}
