import serial
from datetime import datetime as tt
#import math
import time#, pythoncom,pyhook



print "This is a rough sketch to obtain absolute coordinates from an optical mouse."
mouse=file('/dev/input/mouse0')
hc05=serial.Serial("/dev/ttyUSB0",9600)

f=2	#Tune this value!

def uncomplicated(t):
	if t&0b10000000==0b10000000:
		return -(256-t)
	else:
		return (t)

abs_x=abs_y=0
t1=t2=tt.now()
while(1):
	status,vx,vy=tuple(ord(e) for e in mouse.read(3))
	#mouse.write(status,vx,vy)	
	#vx=uncomplicated(ord(mouse.read(1)))
	#vy=uncomplicated(ord(mouse.read(1)))
	t1=t2
	t2=tt.now()
	dt=(t2-t1)
	vx=uncomplicated(vx)
	vy=uncomplicated(vy)
	#print dt.total_seconds()

	#del_x=vx*dt.total_seconds()
	#del_y=vy*dt.total_seconds()
	abs_x+=vx*dt.total_seconds()*f
	abs_y+=vy*dt.total_seconds()*f
	


	#if abs_y>150:
	#	hc05.write('d')
	#	if abs_x>230 and abs_y>150:
	#		hc05.write('w')
	#		abs_x=0
	#		abs_y=0
#
#	elif abs_y<-50:
#		hc05.write('w')




#	if abs_y <= 0 and abs_x <= 0:		##I RUINED MY CODE!!	:)
#		hc05.write(' ')
#	elif abs_y >= 200:
#			hc05.write('w')
#			time.sleep(2)
#			hc05.write(' ')
#	elif abs_x >= 200:
#			time.sleep(2)
#			hc05.write(' ')
#	elif abs_y >= 200:
#			hc05.write('w')
#			time.sleep(2)
#			hc05.write(' ')
#	elif  abs_y <= -500 and abs_x <= -500:
#			hc05.write(' ')



	
	print "(%d , %d)"	%	(abs_x*10,abs_y*10)
	#print "%d\t%d\t%s\t%f"	%	(uncomplicated(del_x),uncomplicated(del_y),bin(status),dt.total_seconds())
