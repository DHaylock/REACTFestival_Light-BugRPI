//
//  MyTimer.hpp
//  myTimer
//
//  Created by David Haylock on 20/10/2015.
//
//

#include "ofMain.h"

class MyTimer {
public:
    void setup(float timerLength,string timerName,bool loop);
    void update();
    void draw(int x, int y);
    
    void start();
    void stop();
    void reset();
    
    
private:
    float startTime;
    float endTime;
    float timeLeft;
    bool  bTimerReached;
    bool _loop;
    float _timerLength;
    string _timerName;
    
};