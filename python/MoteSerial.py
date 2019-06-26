# -*- coding: utf-8 -*-

# Import Python libraries
import logging
import serial
import sys
import time
import glob
import re

import threading
from abc import ABC, abstractmethod

# Import OpenMote libraries
import Serial

class MoteSerial(ABC, threading.Thread):
    def __init__(self, port = None, baudrate = None, timeout = 0.1):
        self.port     = port
        self.baudrate = baudrate
        self.timeout  = timeout
        self.serial   = Serial.Serial(name=self.port, baudrate=self.baudrate, timeout=self.timeout)

        ABC.__init__(self)
        threading.Thread.__init__(self)

    def start(self):
        # Start the serial port
        self.serial.start()
        threading.Thread.start(self)
    
    @abstractmethod
    def run(self):
        pass

    def stop(self):
        # Stop the serial port
        self.serial.stop()


def serial_ports():
        if sys.platform.startswith('win'):
            ports = ['COM%s' % (i + 1) for i in range(256)]
        elif sys.platform.startswith('linux') or sys.platform.startswith('cygwin'):
            ports = glob.glob('/dev/ttyUSB*')
        elif sys.platform.startswith('darwin'):
            ports = glob.glob('/dev/tty.*')
        else:
            raise EnvironmentError('Unsupported platform!')

        result = []
        for port in ports:
            try:
                r = re.compile("[0-9]+")
                m = int(r.findall(port)[0])
                if (m % 2 != 0):
                    result.append(port)
            except (OSError, serial.SerialException):
                pass
        return result
