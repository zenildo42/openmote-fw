/*
 * Copyright 2013 OpenMote Technologies, S.L.
 */

/**
 *
 * @file       InterruptHandler.h
 * @author     Pere Tuset-Peiro (peretuset@openmote.com)
 * @version    v0.1
 * @date       May, 2014
 * @brief
 * @ingroup
 *
 */

#ifndef INTERRUPT_HANDLER_H_
#define INTERRUPT_HANDLER_H_

class GpioIn;
class GpioInPow;
class Timer;
class Uart;
class I2c;
class Spi;
class Radio;
class SysTick;

class InterruptHandler {

public:
    static InterruptHandler& getInstance(void);
    static void setInterruptHandler(GpioIn* gpio_);
    static void clearInterruptHandler(GpioIn* gpio_);
    static void setInterruptHandler(Timer* timer_);
    static void clearInterruptHandler(Timer* timer_);
    static void setInterruptHandler(Uart* uart_);
    static void clearInterruptHandler(Uart* uart_);
    static void setInterruptHandler(I2c* i2c_);
    static void clearInterruptHandler(I2c* i2c_);
    static void setInterruptHandler(Spi* spi_);
    static void clearInterruptHandler(Spi* spi_);
    static void setInterruptHandler(SysTick* systick_);
    static void clearInterruptHandler(SysTick* systick_);
    static void setInterruptHandler(Radio* radio_);
    static void clearInterruptHandler(Radio* radio_);
private:
    InterruptHandler();
    static inline void GPIOA_InterruptHandler(void);
    static inline void GPIOB_InterruptHandler(void);
    static inline void GPIOC_InterruptHandler(void);
    static inline void GPIOD_InterruptHandler(void);
    static inline void TIMER0_InterruptHandler(void);
    static inline void TIMER1_InterruptHandler(void);
    static inline void TIMER2_InterruptHandler(void);
    static inline void TIMER3_InterruptHandler(void);
    static inline void UART0_InterruptHandler(void);
    static inline void UART1_InterruptHandler(void);
    static inline void I2C_InterruptHandler(void);
    static inline void SPI0_InterruptHandler(void);
    static inline void SPI1_InterruptHandler(void);
    static inline void SysTick_InterruptHandler(void);
    static inline void RFCore_InterruptHandler(void);
    static inline void RFError_InterruptHandler(void);
private:
    static InterruptHandler instance;
    static GpioIn* GPIOA_interruptVector[8];
    static GpioIn* GPIOB_interruptVector[8];
    static GpioIn* GPIOC_interruptVector[8];
    static GpioIn* GPIOD_interruptVector[8];
    static Timer* TIMER0_interruptVector[2];
    static Timer* TIMER1_interruptVector[2];
    static Timer* TIMER2_interruptVector[2];
    static Timer* TIMER3_interruptVector[2];
    static Uart* UART0_interruptVector;
    static Uart* UART1_interruptVector;
    static I2c* I2C_interruptVector;
    static Spi* SPI0_interruptVector;
    static Spi* SPI1_interruptVector;
    static SysTick* SysTick_interruptVector;
    static Radio* Radio_interruptVector;
};

#endif /* INTERRUPT_HANDLER_H */
