import serial
from time import sleep
#import bugabox as bb






print "Hello this code works!"
#mouse=file('/dev/input/mouse0')
hc05=serial.Serial("/dev/ttyUSB0",38400)

while(1):

	a=raw_input()
	hc05.write("%s\r\n" % a)
	sleep(0.1)

	if hc05.inWaiting()!=0:
		a=hc05.readline()
		#print "ACKNOWLEDGEMENT RECEIVED: "
		print "%s" % a
		if hc05.inWaiting()!=0:
			a=hc05.readline()
			#print "ACKNOWLEDGEMENT RECEIVED: "
			print "%s" % a
			if hc05.inWaiting()!=0:
				sleep(0.1)
				a=hc05.readline()
				#print "ACKNOWLEDGEMENT RECEIVED: "
				print "%s" % a
				if hc05.inWaiting()!=0:
					a=hc05.readline()
					#print "ACKNOWLEDGEMENT RECEIVED: "
					print "%s" % a



	#if ord(a)==27 or ord(a)==3:
	#	break

