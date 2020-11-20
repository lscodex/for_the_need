//============================================================================
// Name        : main.cpp
// Author      : lscodex
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <opencv2/core.hpp>
#include <opencv2/videoio.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>
#include <stdio.h>

using namespace cv;
using namespace std;

int main(int, char**) {
	Mat frame;
	VideoCapture cap;
	// open the default camera using default API
	// cap.open(0);
	// OR advance usage: select any API backend
	int deviceID = 0;             // 0 = open default camera
	int apiID = cv::CAP_V4L2;      // 0 = autodetect default API
	// open selected camera using selected API
	cap.open(deviceID, apiID);
	// check if it succeeded
	if (!cap.isOpened()) {
		cerr << "ERROR! Unable to open camera\n";
		return -1;
	}

	//--- GRAB AND WRITE LOOP
	cout << "Start grabbing" << endl << "Press any key to terminate" << endl;
	while (cap.isOpened()) {
		// wait for a new frame from camera and store it into 'frame'
		cap.read(frame);
		flip(frame,frame,1);
		resize(frame, frame, Size(200,200));
		// check if we succeeded
		if (frame.empty()) {
			cerr << "ERROR! blank frame grabbed\n";
			break;
		}
		// show live and wait for a key with timeout long enough to show images
		imshow("Live", frame);

		// quit key
		char k = waitKey(1);
		if (k == 'q' || k == 'Q') {
			break;
		}
	}
	// the camera will be deinitialized automatically in VideoCapture destructor
	return 0;
}
