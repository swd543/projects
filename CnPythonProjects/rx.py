import serial
import os,sys
baud=4800

os.system("clear")
argv=tuple(sys.argv)


if len(argv)>=2:
	argv=int(argv[1])
	if argv%4800==0:
		print "\n\nSpecified baud rate = %d. Attempting communication."	% argv
		baud=argv
	else:
		print "\n\nUse a supported baud rate you moron. Supported baud rates are in multiples of 4800.\n"
else:
	print "\n\nNo baud rate specified! Using default baud i.e. %d!\n" % baud




print "THIS IS THE SUBTERMINAL DISPLAYING RECEIVED DATA %d"
#mouse=file('/dev/input/mouse0')
hc05=serial.Serial("/dev/ttyUSB0",baud)
while(1):
	if hc05.inWaiting()!=0:
		a=hc05.readline()
		#print "ACKNOWLEDGEMENT RECEIVED: "
		print "%s" % a
