import bugabox as b
import sys

#sys.path.append("/home/buga/programs/libs")
#print(sys.path)

while(1):
	x=ord(b.getch())
	print "%d" % x
	if x==27 or x==3:
		break
