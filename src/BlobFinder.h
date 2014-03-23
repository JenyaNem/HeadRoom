//
//  BlobTracker.h
//  kinectTCPServer
//
//  Created by maybites on 14.02.14.
//
//
#pragma once

#include "ofMain.h"
#include "ofxOpenCv.h"
#include "ofVec3f.h"
#include "ofxGui.h"
#include "ofConstants.h"
#include "Linef.h"

#include "BlobTracker.h"

#include <cmath>

#define N_MAX_BLOBS 20
#define EYE_DIFF_TO_HEADTOP 160 //the eyes are 130 mm below the top of the head


class BlobFinder {
    
public:
    void setup();
    void allocate();
    
    void update(ofFbo & captureFBO);

    void updateSensorBox(int & value);
    
    void drawSensorBox();
    void drawBodyBlobs(ofRectangle _rect);

    void drawBodyBlobsBox();
    void drawBodyBlobsHeadTop();

    
    int nBlobs;
    vector <BlobTracker> trackedBlobs;
    
    ofVec2f captureScreenSize;
    
    /////////////////
    //COLOR CONTOUR//
    /////////////////
        
    ofPixels fbopixels;
    
    ofxCvColorImage colorImg;
    
    ofxCvGrayscaleImage grayImage; // grayscale depth image
    ofxCvGrayscaleImage grayEyeLevel; // the eyelevel thresholded image
    ofxCvGrayscaleImage grayThreshFar; // the far thresholded image
    
    ofxCvContourFinder contourFinder;
    ofxCvContourFinder contourEyeFinder;
    
    bool bThreshWithOpenCV;
    
    int nearThreshold;
    int farThreshold;
    
    //////////////
    //PROPERTIES//
    //////////////

    ofxPanel gui;
    
    ofParameterGroup sensorBoxGuiGroup;
    
    ofParameter<int> sensorBoxLeft;
    ofParameter<int> sensorBoxRight;
    ofParameter<int> sensorBoxTop;
    ofParameter<int> sensorBoxBottom;
    ofParameter<int> sensorBoxFront;
    ofParameter<int> sensorBoxBack;
    ofParameter<int> nearFrustum;
    ofParameter<int> farFrustum;
    
    ofParameterGroup blobGuiGroup;
    
    ofParameter<int> blobAreaMin;
    ofParameter<int> blobAreaMax;
    ofParameter<int> countBlob;

    ofVboMesh sensorBox;
   
    ofVec3f normal;
    float p;

};

