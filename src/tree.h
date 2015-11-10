//
//  tree.h
//  REACTFestival_Light_Bug
//
//  Created by David Haylock on 09/10/2015.
//
//

#include "ofMain.h"
#include "ofParameterGroup.h"
#include "ofParameter.h"

//--------------------------------------------------------------
class Tree {
    
public:
    //--------------------------------------------------------------
    void setup(int id,int addressStart, int numChannels = 3,bool debugWithGui = false)
    {
        
        _id = id;
        _on = false;
        _address = addressStart;
        cout << "--------------------" << endl;
        cout << "Tree" << endl;
        cout << "ID: " << id << endl;
        cout << "Start Channel: " <<  addressStart << endl;
        _debugWithGui = debugWithGui;
        
        if (debugWithGui) {
            parameters.setName("Tree "+ofToString(id));
            color.set("Color",ofColor(127),ofColor(0,0),ofColor(255));
            parameters.add(color);
        }
    }
    //--------------------------------------------------------------
    void update()
    {
        setColor(color);
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
    
    ofParameterGroup parameters;
    ofParameter<ofColor> color;
private:
    
    
protected:
    ofColor _C;
    
    int _id;
    int _address;
    bool _on;
    bool _debugWithGui;
};