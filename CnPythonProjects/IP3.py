import cv2
import numpy as np
from matplotlib import pyplot as plot

def converted(p):
	p[0]=p[0]/2
	p[1]=p[1]*255/100
	p[2]=p[2]*255/100
	return np.array(p)

def imgNeg(image):
	return 255-image
	

cap=cv2.VideoCapture(0)
while(1):
	#_,raw=cap.read()
	#daw=cv2.Canny(raw,100,250)	#Intensity gradient-Min to max
	#hsv=cv2.cvtColor(raw, cv2.COLOR_BGR2HSV)

	im = cv2.imread('Pictures/Webcam/2015-05-18-035043.jpg')
	imgray = cv2.cvtColor(im,cv2.COLOR_BGR2GRAY)
	thresh = cv2.threshold(imgray,127,255,0)
	contours= cv2.findContours(thresh,cv2.RETR_TREE,cv2.CHAIN_APPROX_SIMPLE)
	im = cv2.drawContours(im, contours, -1, (0,255,0), 3)

	#canny=cv2.Canny(hsv,100,250)
	#canny=imgNeg(canny)
	
	#lower_white=[0,0,65]	#Fine tuned values trained specifically to recognise my tshirt! 145,23,12 also works!
	#upper_white=[360,22,100]
	#lower_blue=[209,30,10]
	#upper_blue=[265,90,97]
	#lower_red=[322,45,5]
	#upper_red=[360,80,90]

	#wmask=cv2.inRange(hsv,converted(lower_white),converted(upper_white))
	#wmask=cv2.medianBlur(wmask,5)
	#wmask=cv2.GaussianBlur(wmask,(5,5),0)
	
	#bmask=cv2.inRange(hsv,converted(lower_blue),converted(upper_blue))
	#rmask=cv2.inRange(hsv,converted(lower_red),converted(upper_red))
	#rmask=cv2.medianBlur(rmask,5)
	#daw=cv2.Canny(rmask,100,250)
	#whitened_mask=cv2.bitwise_and(raw,raw,mask=wmask)
	#blued_mask=cv2.bitwise_and(raw,raw,mask=bmask)
	#reddened_mask=cv2.bitwise_and(raw,raw,mask=rmask)
	#rmask=cv2.medianBlur(rmask,5)

	#gray=cv2.cvtColor(raw,cv2.COLOR_BGR2GRAY)
	#thresh=cv2.threshold(gray,127,255,0)
	#contours=cv2.findContours(thresh,cv2.RETR_TREE,cv2.CHAIN_APPROX_SIMPLE)
	#raw=cv2.drawContours(raw,contours,-1,(0,255,0),3)

	cv2.imshow('Its such a good vibration!',raw)
	#cv2.imshow('whitened Mask',whitened_mask)
	#cv2.imshow('Canny',daw)
	#cv2.imshow('Reddened Mask',rmask)
	#cv2.imshow('Trackin \'n Crackin\'!',daw)
	#cv2.imshow('Blued Mask',blued_mask)
	#cv2.imshow('My Sketch!',canny)
	k=cv2.waitKey(5) & 0xff
	if k==27:
		break
cv2.destroyAllWindows()
