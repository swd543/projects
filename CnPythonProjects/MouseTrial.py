import serial
print "hello this code works!"
mouse=file('/dev/input/mouse0')
hc05=serial.Serial("/dev/ttyUSB0",9600)

def to_signed(a):
	if a & 0b10000000 == 0b10000000:
		return -(a ^ 0b11111111)
	else:
		return a


ax=ay=0

while(1):
	x=ord(mouse.read(1))
	y=ord(mouse.read(1))
	z=ord(mouse.read(1))

	ax+=to_signed(y)
	ay+=to_signed(z)

	left=right=mid=False
	if (x & 0b00000001) == 0b00000001 :
		left=True
	if (x & 0b00000010) == 0b00000010 :
		right=True
	if (x & 0b00000100) == 0b00000100 :
		mid=True
	if (left&right) :
		print "Both clicked!"
	elif left :
		print "Left click!"
	elif right :
		print "Right click!"
	elif mid :
		print "Mid click!"
	
	print "%d\t%d\t%s"	%	(to_signed(ax),to_signed(ay),bin(x))
	hc05.write("a")
	
