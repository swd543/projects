import serial
from datetime import datetime as tt
import math
print "This is a rough sketch to obtain absolute coordinates from an optical mouse."
mouse=file('/dev/input/mouse0')
abs_x=abs_y=0
f=2	#Tune this value!

def uncomplicated(t):
	if t&0b10000000==0b10000000:
		return -(256-t)
	else:
		return (t)


t1=t2=tt.now()
while(1):

	status,vx,vy=tuple(ord(e) for e in mouse.read(3))	
	#vx=uncomplicated(ord(mouse.read(1)))
	#vy=uncomplicated(ord(mouse.read(1)))
	
	if dt>=1/f:

		t1=t2
		t2=tt.now()
		dt=(t2-t1)
		vx=uncomplicated(vx)
		vy=uncomplicated(vy)
		print dt.total_seconds()

		#del_x=vx*dt.total_seconds()
		#del_y=vy*dt.total_seconds()
		abs_x+=vx*dt.total_seconds()*f
		abs_y+=vy*dt.total_seconds()*f
	
	print "(%d , %d)"	%	(abs_x*10,abs_y*10)
	#print "%d\t%d\t%s\t%f"	%	(uncomplicated(del_x),uncomplicated(del_y),bin(status),dt.total_seconds())
