import serial
print "hello this code works!"
mouse=file('/dev/input/mouse0')
arduino=serial.Serial("/dev/ttyACM1",9600)


while(1):
	t=input('')
	arduino.write(b'%d' % (t));



#def to_signed(n):
#	return n-((0x80 &n)<<1)

#while True:
#	status, dx, dy = tuple(ord(c) for c in mouse.read(3))
#	dx=to_signed(dx)
#	dy=to_signed(dy)
#	print "%#b	%d	%d" % (status,dx,dy)
