#pragma once

#include "ofMain.h"

#define SIZE 10

#define X_SIZE  400
#define Y_SIZE  300

#define MIN_X_SIZE 40
#define MIN_Y_SIZE 40

class LinkedList{
    public:
        ofRectangle bounds;
        LinkedList *next;
        int offsetX, offsetY;
        char *name;

        LinkedList( ofRectangle bounds ):offsetX(0), offsetY(0),next(NULL){
            this->bounds = bounds;

    }

};




class ofApp : public ofBaseApp{

	public:

		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);



		ofTrueTypeFont 	copperBlack;
		LinkedList *head;


		char words[255][255];
};

