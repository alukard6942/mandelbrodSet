#!bin/py


import numpy as np
import cv2 as cv2
# this is a python 


height, width = 500, 500
img = np.zeros((height+1, width+1, 3), np.uint8)
img[:,:] = [0,0,0]

zoom = 2.0
rNum = -1
iNum = .0

def main():
	# redner margin
	
	render()

	cv2.imshow("image", img)
	cv2.namedWindow('image')
	cv2.setMouseCallback('image', on_click)

	cv2.waitKey(0)

def render():
	pixelY = 0
	for i in np.arange(iNum - zoom, iNum + zoom, 2*zoom / height):
		pixelX = 0
		for j in np.arange(rNum - zoom, rNum + zoom, 2*zoom / width):
			real, imagin = .0,.0
			for iritation in range(100, 0, -1):
				tmp = real * real - imagin * imagin + j
				imagin = 2 * imagin * real + i
				real = tmp
				if (real*real + imagin * imagin >= 4):
					img[pixelY,pixelX] = [iritation%250,iritation/2 % 250,iritation /3 % 250]
					break
				if iritation == 1:
					img[pixelY,pixelX] = [0,0,0]
			
			pixelX += 1
		pixelY += 1
	cv2.imshow("image", img)


def on_click(event, x, y, p1, p2):
	if event == cv2.EVENT_LBUTTONDOWN:
		rNum = (zoom * y / height) + rNum - zoom 
		iNum = (zoom * x / height) + iNum - zoom

		print (x1,y1)

		render()
		
		
		

main()

