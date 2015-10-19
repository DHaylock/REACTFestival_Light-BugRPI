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
        _on = false;
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
    void setIsTreeOn(bool on) {
        _on = on;
    }
    //--------------------------------------------------------------
    bool getIsTreeOn() {
        return _on;
    }
    //--------------------------------------------------------------
    void setColor(ofColor c)
    {
        cout << "ID: " << _id << " Original Color " << getColor() << endl;
        cout << "ID: " << _id << " New Color " << c << endl;
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
    bool _on;
};