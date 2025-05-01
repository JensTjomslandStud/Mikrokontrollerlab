


void LED_init() {
    for(int i = 17; i <= 20) {
        GPIO->PIN_CNF[i] |= (1<<0) | (3 << 2);
        GPIO->OUT |= (1<<i);
    }
}
void button_init() {
    GPIO->PIN_CNF[13]=(3<<2);
}

int main() {
    LED_init();
    button_init();
    GPIOTE_init();
    ppi_init();
    
    while(1);
    return 0;
}