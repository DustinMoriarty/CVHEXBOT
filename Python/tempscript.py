# -*- coding: utf-8 -*-
"""
Created on Fri May 17 11:03:39 2013

@author: dustinm
"""

import time
import math
import serial
import serial.tools.list_ports
import threading

fw = open('com.txt','r')
fwstr = fw.read()
comList = []
comports = serial.tools.list_ports.comports()
for comport in comports:
        for thing in comport:
                #print thing
                comList.append(thing)
comList = list(set(comList))
print "Attempting to connect to Servotor"