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
	hsv=cv2.cvtColor(raw, cv2.COLOR_BGR2HSV)
	
	lower_green=[80,23,5]	#Fine tuned values trained specifically to recognise my tshirt! 145,23,12 also works!
	upper_green=[205,80,64]
	lower_blue=[209,30,10]
	upper_blue=[265,90,97]
	lower_red=[322,45,5]
	upper_red=[360,80,90]

	gmask=cv2.inRange(hsv,converted(lower_green),converted(upper_green))
	bmask=cv2.inRange(hsv,converted(lower_blue),converted(upper_blue))
	rmask=cv2.inRange(hsv,converted(lower_red),converted(upper_red))
	greened_mask=cv2.bitwise_and(raw,raw,mask=gmask)
	blued_mask=cv2.bitwise_and(raw,raw,mask=bmask)
	reddened_mask=cv2.bitwise_and(raw,raw,mask=rmask)

	cv2.imshow('Its such a good vibration!',raw)
	cv2.imshow('Greened Mask',greened_mask)
	cv2.imshow('Reddened Mask',reddened_mask)
	cv2.imshow('Blued Mask',blued_mask)
	k=cv2.waitKey(2) & 0xff
	if k==27:
		break
cv2.destroyAllWindows()
