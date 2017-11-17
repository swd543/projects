import cv2
import numpy as np

def converted(p):
	p[0]=p[0]/2
	p[1]=p[1]*255/100
	p[2]=p[2]*255/100
	return np.array(p)

cap=cv2.VideoCapture(0)
while(1):
	_,raw=cap.read()
#	raw=cv2.GaussianBlur(raw,(5,5),0)
	hsv=cv2.cvtColor(raw, cv2.COLOR_BGR2HSV)
	
	lower_green=[80,23,12]	#Fine tuned values trained specifically to recognise my tshirt! 145,23,12 also works!
	upper_green=[205,80,64]

	mask=cv2.inRange(hsv,converted(lower_green),converted(upper_green))
#	mask=cv2.inRange(hsv,np.array([0,50,50]),np.array([180,255,255]))
	greened_mask=cv2.bitwise_and(raw,raw,mask=mask)

	cv2.imshow('Its such a good vibration!',raw)
	cv2.imshow('Masked',mask)
	cv2.imshow('Greened Mask',greened_mask)
#	cv2.imshow('bgr',span)
	k=cv2.waitKey(5) & 0xff
	if k==27:
		break
cv2.destroyAllWindows()
