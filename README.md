# canny-edge-detection
Detect edges in an image using canny edge function from OpenCV

##### To run the project
Place the test image in the `data` folder.
```
cd source/build
cmake ..
make
./cannyEdge somefile.extension
```

##### Sample output

Sample input

![alt text](https://github.com/mrinal-r/canny-edge-detection/blob/master/data/lena.jpg "Input Image")



Detected edges 

![alt text](https://github.com/mrinal-r/canny-edge-detection/blob/master/sample/edges.jpg "Edges Image")



Edges superimposed on the original image

![alt text](https://github.com/mrinal-r/canny-edge-detection/blob/master/sample/combined.jpg "Combined Image")



##### References
[OpenCV documentation](https://docs.opencv.org/3.4/da/d5c/tutorial_canny_detector.html)
