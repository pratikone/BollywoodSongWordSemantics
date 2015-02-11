#include "ofApp.h"

bool rectOverlap( int lx1, int rx1, int ly1, int ry1, int lx2, int rx2, int ly2, int ry2 ){


    if( lx1 > rx2  || lx2 > rx1 )  //left side || right side
        return false;

    if( ly1 > ry2 || ly2 > ry1 ) // below || above   y-cordinate system is opposite of cartesian hence, the comparison operators are flipped
        return false;


    return true;
}


int getRandX( ){

return MIN_X_SIZE + abs(rand() % X_SIZE-100);
}

int getRandY( ){
    return MIN_Y_SIZE + abs(rand() % Y_SIZE-100);
}

LinkedList*  getMahNode( LinkedList *head, ofRectangle bounds, char *name ){
    LinkedList *node = new LinkedList( bounds );
    int X = getRandX( );
    int Y = getRandY( );

    node->name = name;

    LinkedList *temp;

    temp = head;
    if( temp != NULL ){   //non-head condition, empty list

        while( temp != NULL ){



            cout<<"temp "<< temp->name <<" dimensions lx1 "<<temp->offsetX<<"  rx1 "<< temp->offsetX + temp->bounds.width << " ly1 "<< temp->offsetY <<" ry1 " << temp->offsetY + temp->bounds.height<<endl;

            cout<<"node dimensions lx2 "<< X<<"  rx2 "<< X + bounds.width << " ly2 "<<  + Y <<" ry2 " << Y + bounds.height<<endl;

            if( rectOverlap( temp->offsetX,
                             temp->offsetX + temp->bounds.width,
                             temp->offsetY,
                             temp->offsetY + temp->bounds.height,
                             X,
                             X + bounds.width,
                             Y,
                             Y + bounds.height ) ||
                (X + bounds.width > X_SIZE || Y + bounds.height > Y_SIZE) ){

                    Y = getRandX(); // randomized again as there is collision
                    X = getRandY();
                    temp = head;
                    cout<<"\n YO ENTERED\n";
            }else{
                temp = temp->next;
            }

        }
    }




    node->offsetX = X;
    node->offsetY = Y; //non-colliding offsets

    return node;
}



//--------------------------------------------------------------
void ofApp::setup(){

	copperBlack.loadFont("cooperBlack.ttf", 30);
	ofBackground(50,50,50);  //best background ever



    strcpy(words[0], "Ram");
    strcpy(words[1], "Lakhan");l
    strcpy(words[2], "Bulla");
    strcpy(words[3], "Teja");
    strcpy(words[4], "Mogambo");
    strcpy(words[5], "Raka");
    strcpy(words[6], "Gogo");
    strcpy(words[7], "Shakaal");
    strcpy(words[8], "Gabbar");
    strcpy(words[9], "Dang");

    head = NULL;  // empty linkedlist


    for( int i=0; i<SIZE; i++){
        ofRectangle bounds = copperBlack.getStringBoundingBox(words[i], 0,  0);

        cout<<words[i]<<"~~~~~~~~~~~~~~~~~~~"<<endl;


        LinkedList *node = NULL;

        if ( head == NULL ){ //base case

            node = getMahNode( head, bounds, words[i] );
            head = node;

        }
        else{ //TODO : to be replaced with head and tail pointer system
            LinkedList *temp = head;
            while( temp->next != NULL )
                temp = temp->next;

            node = getMahNode( head, bounds, words[i] );
            temp->next = node;

        }


    }

}



//--------------------------------------------------------------
void ofApp::update(){





//verdana14A.getStringBoundingBox(scaleA, 0, 0);

}

//--------------------------------------------------------------
void ofApp::draw(){

    int SCALE = 40;


    //printing mah words here...
    for(LinkedList *temp=head; temp !=NULL;   temp = temp->next ){
        ofSetColor(255,122 + SCALE,220);
        copperBlack.drawString(temp->name, temp->offsetX,  temp->offsetY );
    }

}



//--------------------------------------------------------------
void ofApp::keyPressed  (int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    cout<<" mouse X: "<<mouseX<<" mouse Y: "<<mouseY;

}


//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    cout<<" mouse X: "<<mouseX<<" mouse Y: "<<mouseY;

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){

}
