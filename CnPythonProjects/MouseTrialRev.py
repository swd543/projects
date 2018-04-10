import serial
print "hello this code works!"
mouse=file('/dev/input/mouse1')
arduinopro=serial.Serial("/dev/ttyUSB0",9600)

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
		if mid:
			arduinopro.write("x")
		else:
			print "Both clicked!"
			arduinopro.write("b")
	elif left :
		print "Left click!"
		arduinopro.write("%d"	%	1)
	elif right :
		print "Right click!"
		arduinopro.write("%d"	%	2)
	elif mid :
		print "Mid click!"
		arduinopro.write("%d"	%	3)
	else :
		arduinopro.write("%d"	%	0)
	print "%d\t%d"	%	(to_signed(y),to_signed(z))

	
