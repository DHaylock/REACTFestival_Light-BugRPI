//
//  MyTimer.cpp
//  myTimer
//
//  Created by David Haylock on 20/10/2015.
//
//

#include "MyTimer.h"


void MyTimer::setup(float timerLength,string timerName,bool loop)
{
    bTimerReached = true;
    _loop = loop;
    _timerLength = timerLength;
    _timerName = timerName;
}

void MyTimer::update()
{
    
    float timer = ofGetElapsedTimeMillis() - startTime;
    
    if (!bTimerReached) {
        timeLeft = _timerLength - timer;        
    }

    
    if (timer >= _timerLength && !bTimerReached) {
        bTimerReached = true;
        ofMessage msg(_timerName + " Finished");
        ofSendMessage(msg);
        if (_loop) {
            start();
        }
    }
    
}

void MyTimer::draw(int x, int y)
{
    ofDrawBitmapString(ofToString(timeLeft), x,y);
}

void MyTimer::start()
{
    if (bTimerReached) {
        ofMessage msg(_timerName + " Started");
        ofSendMessage(msg);
        bTimerReached = false;
        startTime = ofGetElapsedTimeMillis();
    }
}

void MyTimer::stop( )
{
    bTimerReached = true;
}