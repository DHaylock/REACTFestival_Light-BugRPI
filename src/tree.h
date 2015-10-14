//
//  tree.h
//  REACTFestival_Light_Bug
//
//  Created by David Haylock on 09/10/2015.
//
//

#include "ofMain.h"

//--------------------------------------------------------------
class Tree {
    
    public:
        //--------------------------------------------------------------
        void setup(int id,int addressStart, int numChannels = 3)
        {
            _id = id;
            _address = addressStart;
            cout << "--------------------" << endl;
            cout << "Tree" << endl;
            cout << "ID: " << id << endl;
            cout << "Start Channel: " <<  addressStart << endl;
        }
        //--------------------------------------------------------------
        void update()
        {
            
        }
        //--------------------------------------------------------------
        void draw(int x, int y)
        {
            ofSetColor(_C);
            ofCircle(x, y, 20);
        }
        //--------------------------------------------------------------
        void setColor(ofColor c)
        {
            _C = c;
        }
        //--------------------------------------------------------------
        ofColor getColor()
        {
            return _C;
        }
        //--------------------------------------------------------------
        int getAddresses(){
            return _address;
        }
    
    private:
        
    protected:
        ofColor _C;
    
        int _id;
        int _address;
};