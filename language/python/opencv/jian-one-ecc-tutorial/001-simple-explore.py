import cv2

img = cv2.imread(r"language/python/opencv/footage/COCO_val2014_000000000192.jpg")
print(img)

img_grey = cv2.imread(r"language/python/opencv/footage/COCO_val2014_000000000192.jpg", 0)
print(img_grey)
cv2.imshow('scene', img)
cv2.imshow('img1', img_grey)
cv2.waitKey()