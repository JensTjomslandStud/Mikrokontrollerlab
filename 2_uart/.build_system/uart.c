
// base address 0x40002000

#define GPIO ((NRF_UART_REG*)0x40002000)

typedef struct {

	volatile uint32_t TASKS_STARTRX;     // 0x000 
    volatile uint32_t TASKS_STOPRX;      // 0x004
    volatile uint32_t TASKS_STARTTX;     // 0x008
    volatile uint32_t TASKS_STOPTX;      // 0x2C-(0x00C+4)
    volatile uint32_t RESERVED0[3];
    volatile uint32_t TASKS_FLUSHRX;
    volatile uint32_t RESERVED1[5];
    volatile uint32_t EVENTS_CTS;
    volatile uint32_t EVENTS_NCTS;
                                        //offset for reserved felt
    volatile uint32_t EVENTS_RXDRDY;  
    volatile uint32_t EVENTS_ENDTX; 
    volatile uint32_t EVENTS_TXDRDY; 
    volatile uint32_t EVENTS_ERROR;

    volatile uint32_t EVENTS_RXTO;
    volatile uint32_t EVENTS_RXSTARTED;
    volatile uint32_t EVENTS_TXSTARTED;
    volatile uint32_t EVENTS_TXSTOPPED;

    volatile uint32_t SHORTS;

    volatile uint32_t INTEN;
    volatile uint32_t INTENSET;
    volatile uint32_t INTENCLR;

    volatile uint32_t ERRORSRC;
    volatile uint32_t ENABLE;

    volatile uint32_t PSEL.RTS;
    volatile uint32_t PSEL.TXD;
    volatile uint32_t PSEL.CTS;
    volatile uint32_t PSEL.RXD;

    volatile uint32_t BAUDRATE;

    volatile uint32_t RXD.PTR;
    volatile uint32_t RXD.MAXCNT;
    volatile uint32_t RXD.AMOUNT;

    volatile uint32_t TXD.PTR;
    volatile uint32_t TXD.MAXCNT;
    volatile uint32_t TXD.AMOUNT;

    volatile uint32_t CONFIFG;

} NRF_UART_REG;



void uart_init(){

}

void uart_send(char letter){

}

char uart_read(){

}
