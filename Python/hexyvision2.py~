import os
import time
import re
import sys 

abspath = os.path.abspath(__file__)
dname = os.path.dirname(abspath)
os.chdir(dname)

sys.path.append('Moves') # include the moves folder
sys.path.append('PoMoCo')

import servotorComm
from robot import hexapod



# Open Output File For Writing
fwstr = 'pyout.txt'
fw = open('pyout.txt','w')
fw.write('Connecting To Robot')
fw.close()

controller = servotorComm.Controller() # Servo controller

while controller.serialHandler.serOpen == 'false':
    time.sleep(1)
 
hexy = hexapod(controller)

time.sleep(1)

hexy.loadOffsets()
hexy.setzero()
hexy.killall()
openpipe = True


intcommand = int(0)

while openpipe:
    
    try:
        if os.path.exists("cpp2py.txt"):
            intcommand += 1
            fr = open('cpp2py.txt', 'rt')
            command = fr.read()
            fr.close()
            fw = open(fwstr, 'a')
            print "executing command Number {0} \r\n {1}".format(intcommand, command)
            fw.write("executing command Number {0} \r\n {1}".format(intcommand, command))
            os.remove("cpp2py.txt")
            if command == 'q':
                fw.write("quitting!")
                print 'quitting'
                hexy.killall()
                del hexy
                del controller    
                fw.write("good by")
                print 'good by'
                fw.close()
                os._exit(0)
            elif command == 'd':
                fw.write('Terminating Connection \r\n Python Window Will Remain Open \r\n If This Program is running in In Interactive Mode')
                fw.close()
                print 'Terminating Connection \r\n Python Window Will Remain Open \r\n If This Program is running in In Interactive Mode'
                openpipe = False
            else:
                eval(command)
    except :
        pass

    
    time.sleep(0.001)



