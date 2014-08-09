/*
 * Copyright 2013 OpenMote Technologies, S.L.
 */

/**
 *
 * @file       GpioIn.h
 * @author     Pere Tuset-Peiro (peretuset@openmote.com)
 * @version    v0.1
 * @date       May, 2014
 * @brief
 * @ingroup
 *
 */

#ifndef GPIO_IN_H_
#define GPIO_IN_H_

#include <stdint.h>

#include "Gpio.h"
#include "InterruptHandler.h"

typedef void (*callback_t)(void);

class GpioIn : public Gpio
{

friend class InterruptHandler;

public:
    GpioIn(uint32_t port_, uint8_t pin_, uint32_t edge_);
    bool read(void);
    void setCallback(callback_t callback_);
    void clearCallback(void);
    void enableInterrupt(void);
    void disableInterrupt(void);
protected:
    void interruptHandler(void);
protected:
    uint32_t edge;
    callback_t callback = nullptr;
private:

};

#endif /* GPIO_IN_H_ */
