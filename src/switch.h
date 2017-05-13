
#ifndef SWITCH_H
#define SWITCH_H

void initSwitchPB2();

#define READ_PIN(pin,bit) (!(PIN##pin & (1<<PIN##pin##bit)))

#define SET_READ(port,bit) do{ DDR##port &= ~(1<<DD##port##bit); }while(0)
#define SET_WRITE(port,bit) do{ DDR##port |= (1<<DD##port##bit); }while(0)
#define SET_DDR(port,bit,READ_WRITE) do{ SET_##READ_WRITE(port,bit); }while(0)

#define PULL_UP_ON(port,bit) do{ PORT##port |= (1<<PORT##port##bit); }while(0)
#define PULL_UP_OFF(port,bit) do{ PORT##port &= ~(1<<PORT##port##bit); }while(0)
#define SET_PULL_UP(port,bit,ON_OFF) do{ PULL_UP_##ON_OFF(port,bit); }while(0)

#define INIT_SWITCH(port,bit) do{ SET_DDR(port,bit,READ); SET_PULL_UP(port,bit,ON); }while(0)

#define BUTTON_IS_DOWN(port,bit) READ_PIN(port,bit)

#endif // SWITCH_H
