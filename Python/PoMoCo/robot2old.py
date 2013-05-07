import time
import math
import os
import ConfigParser


from servotorComm import runMovement
from robot import *


class hexmove(hexapod):
    def __init__(self,con, floor = 60):
        self.con = con
        self.floor = floor
        
        self.RF  = leg2(con,'rightFront',24,25,26, (0, 3, 0), floor)
        self.RM  = leg2(con,'rightMid',20,21,22, (0, 3, 0), floor)
        self.RB  = leg2(con,'rightBack',16,17,18, (0, 3, 0), floor)

        self.LF  = leg2(con,'leftFront',7,6,5, (0, 3, 0), floor)
        self.LM  = leg2(con,'leftMid',11,10,9, (0, 3, 0), floor)
        self.LB  = leg2(con,'leftBack',15,14,13, (0, 3, 0), floor)

        self.legs = [self.RF,
                     self.RM,
                     self.RB,
                     self.LF,
                     self.LM,
                     self.LB]

        self.neck = neck(con,31)

        self.tripod1 = [self.RF,self.RB,self.LM]
        self.tripod2 = [self.LF,self.LB,self.RM]
        
    def loadOffsets(self):
        # If there is one offset file in the folder, automatically load it
        off_files = []
        for filename in os.listdir(os.getcwd()):
            start, ext = os.path.splitext(filename)
            if ext == '.cfg':
                off_files.append(filename)

        if len(off_files) == 1:
            print "opening",off_files[0]
            config = ConfigParser.ConfigParser()
            config.read(off_files[0])

            try:
                offsets = config.items('offsets')
                for offset in offsets:
                    servoNum = int(offset[0])
                    offset = int(offset[1])
                    for servo in self.con.servos:
                        if self.con.servos[servo].servoNum == servoNum:
                            #print "set servo",servoNum,"offset as",offset
                            self.con.servos[servo].setOffset(timing=offset)
                            break
                print "automatically loaded offsets from",off_files[0]
            except:
                print "automatic offset load failed, is there an offset file" 

    def setzero(self):
        print 'Move Set Zero'
        for servo in self.con.servos:
            self.con.servos[servo].setPos(deg=0)
    def getup(self):
        deg = -30
        
        #put all the feet centered and on the floor.
        
        self.LF.hip(-deg)
        self.RM.hip(1)
        self.LB.hip(deg)
        
        self.RF.hip(deg)
        self.LM.hip(1)
        self.RB.hip(-deg)
        
        time.sleep(0.5)
        
        for leg in self.legs:
            leg.knee(-30)
            leg.hip("sleep")
        
        time.sleep(0.5)
        
        for leg in self.legs:
            leg.ankle(-90)
        
        time.sleep(0.5)
        
        for angle in range(0,45,3):
            for leg in self.legs:
                leg.knee(angle)
                leg.ankle(-90+angle)
            time.sleep(0.1)
            
        self.reset()
        
    def moveforward(self, q=25):
        
        # Move: Move Forward
        
        deg = q
        midFloor = 30
        hipSwing = q
        pause = 0.5
        
        #tripod1 = RF,LM,RB
        #tripod2 = LF,RM,LB
        
        for timeStop in range(2):
            #time.sleep(0.1)
            # replant tripod2 forward while tripod1 move behind
            #   relpant tripod 2 forward
            self.LF.replantFoot(deg-hipSwing,stepTime=0.5)
            self.RM.replantFoot(hipSwing,stepTime=0.5)
            self.LB.replantFoot(-deg-hipSwing,stepTime=0.5)
        
            #   tripod1 moves behind
            self.RF.setHipDeg(-deg-hipSwing,stepTime=0.5)
            self.LM.setHipDeg(hipSwing,stepTime=0.5)
            self.RB.setHipDeg(deg-hipSwing,stepTime=0.5)
            time.sleep(0.6)
        
            # replant tripod1 forward while tripod2 move behind
            #   replant tripod1 forward
            self.RF.replantFoot(-deg+hipSwing,stepTime=0.5)
            self.LM.replantFoot(-hipSwing,stepTime=0.5)
            self.RB.replantFoot(deg+hipSwing,stepTime=0.5)
        
            #   tripod2 moves behind
            self.LF.setHipDeg(deg+hipSwing,stepTime=0.5)
            self.RM.setHipDeg(-hipSwing,stepTime=0.5)
            self.LB.setHipDeg(-deg+hipSwing,stepTime=0.5)
            time.sleep(0.6)

    def  movebackward(self, q=25):
        # Move: Move Backward
        self.moveforward(-q)
            
    
    def reset(self):     
        deg = -30
        
        # pickup and put all the feet centered and on the floor.
        
        self.LF.replantFoot(-deg,stepTime=0.3)
        self.RM.replantFoot(1,stepTime=0.3)
        self.LB.replantFoot(deg,stepTime=0.3)
        
        time.sleep(0.5)
        
        self.RF.replantFoot(deg,stepTime=0.3)
        self.LM.replantFoot(1,stepTime=0.3)
        self.RB.replantFoot(-deg,stepTime=0.3)
        
        time.sleep(0.5)
        
        # set all the hip angle to what they should be while standing
        self.LF.hip(-deg)
        self.RM.hip(1)
        self.LB.hip(deg)
        self.RF.hip(deg)
        self.LM.hip(1)
        self.RB.hip(-deg)
        
  
            
    def rotateleft(self, q=45):
        deg = q
        
        #set neck to where body is turning
        self.neck.set(deg)
        
        #re-plant tripod2 deg degrees forward
        for leg in self.tripod2:
            leg.replantFoot(deg,stepTime=0.2)
        time.sleep(0.3)
        
        #raise tripod1 feet
        for leg in self.tripod1:
            leg.setFootY(int(self.floor/2.0))
        time.sleep(0.3)
        
        #swing tripod2 feet back 2*deg degrees (to -deg)
        for leg in self.tripod2:
            leg.setHipDeg(-deg,stepTime=0.3)
        
        #reset neck as body turns
        self.neck.set(0)
        time.sleep(0.4)
        
        #lower tripod1 feet
        for leg in self.tripod1:
            leg.setFootY(self.floor)
        time.sleep(0.3)
        
        #re-plant legs to starting position
        self.LF.replantFoot(deg,stepTime=0.3)
        self.RM.replantFoot(1,stepTime=0.3)
        self.LB.replantFoot(-deg,stepTime=0.3)
        
        time.sleep(0.5)
        
    def rotateright(self, q=45):
        self.rotateleft(-q)
        
    def wave(self):
        # Move: Wave
        self.neck.set(0)
        
        self.LF.hip(-20)
        self.LF.knee(0)
        self.LF.ankle(0)
        
        time.sleep(0.2)
        
        for i in range(3):
            self.LF.hip(-20)
            self.LF.knee(-50)
            self.LF.ankle(-20)
        
            time.sleep(0.2)
        
            self.LF.knee(-10)
            self.LF.ankle(0)
            time.sleep(0.2)
        
        self.LF.knee(-40)
        
    def bellyflop(self):
        self.setzero()
        time.sleep(2)
        self.getup()
        time.sleep(0.5)
        
    def leanback(self):
        # Pick up back feet
        self.RB.setHipDeg(-45,stepTime=0.3)
        self.LB.setHipDeg(45,stepTime=0.3)
        self.RB.setFootY(self.floor-40)
        self.LB.setFootY(self.floor-40)
        
        time.sleep(0.5)
        
        # Push side feet down
        self.RM.setFootY(self.floor+10)
        self.RM.hip(70)
        self.LM.setFootY(self.floor+10)
        self.LM.hip(-70)
        time.sleep(0.2)
        
        # Put hands into air
        self.LF.hip(-45)
        self.LF.knee(0)
        self.LF.ankle(0)
        self.RF.hip(45)
        self.RF.knee(0)
        self.RF.ankle(0)
        time.sleep(0.4)
        
    def killall(self):
        for servo in self.con.servos:
                self.con.servos[servo].kill()

class leg2(leg):

    def __init__(self,con,name,hipServoNum,kneeServoNum,ankleServoNum,simOrigin=(0,3,0), floor = 60):
        self.floor = floor
        self.con = con
        self.name = name
        self.hipServoNum = hipServoNum
        self.kneeServoNum = kneeServoNum
        self.ankleServoNum = ankleServoNum

    
        
