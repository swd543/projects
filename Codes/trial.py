import serial
print "hello this code works!"
mouse=file('/dev/input/mouse0')
#arduino=serial.Serial("/dev/ttyACM0",9600)
hc05=serial.Serial("/dev/ttyUSB0",9600)

def to_signed(a):
	if a & 0b10000000 == 0b10000000:
		return -(a ^ 0b11111111)
	else:
		return a

while(1):
	x=ord(mouse.read(1))
	y=ord(mouse.read(1))
	z=ord(mouse.read(1))	

	left=right=mid=False
	if (x & 0b00000001) == 0b00000001 :
		left=True
	if (x & 0b00000010) == 0b00000010 :
		right=True
	if (x & 0b00000100) == 0b00000100 :
		mid=True
	if (left&right) :
		print "Both clicked!"
		#hc05.write("LEFT & RIGHT")
	elif left :
		print "Left click!"
		#hc05.write("LEFT")
	elif right :
		print "Right click!"
		#hc05.write("RIGHT")
	elif mid :
		print "Mid click!"
		#hc05.write("MID")
	
	print "%d\t%d"	%	(to_signed(y),to_signed(z))
	hc05.write("%d"%(x))
