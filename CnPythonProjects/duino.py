import serial
print "hello this code works!"
mouse=file('/dev/input/mouse0')
arduino=serial.Serial("/dev/ttyUSB1",9600)




def to_signed(n):
	return n-((0x80 &n)<<1)



while(1):
	status, dx, dy = tuple(ord(c) for c in mouse.read(3))

	dx=to_signed(dx)
	dy=to_signed(dy)
	print "%d	%d	%d" % (status,dx,dy)
	arduino.write(b'%d' % (dx))





#while True:
#	status, dx, dy = tuple(ord(c) for c in mouse.read(3))
#	dx=to_signed(dx)
#	dy=to_signed(dy)
#	print "%#b	%d	%d" % (status,dx,dy)
