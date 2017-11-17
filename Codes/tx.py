import serial
import bugabox as bb
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


hc05=serial.Serial("/dev/ttyUSB0",baud)
os.system("gnome-terminal -e 'bash -c \"python /home/buga/programs/rx.py %d\"'" % baud)


print "\nTHIS IS THE SUBTERMINAL DISPLAYING TRANSMISSION"

while(1):
	
	print "What should I transmit? : "
	#a=bb.getch()
	a=raw_input()
	#print a




	#if ord(a)==27 or ord(a)==3:
	#	break
	hc05.write(a)

