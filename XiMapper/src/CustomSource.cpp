#include "CustomSource.h"

void CustomSource::setup(){
	// Give our source a decent name
	name = "Custom FBO Source";

	// Allocate our FBO source, decide how big it should be
	allocate(500, 500);

    specificSetup();
}

void CustomSource::specificSetup(){
    switch (animationNumber)
    {
        case 0:
        case 1:  void_setup();                                       break;
        case 2:  smoothHorizontalLines_setup();                      break;
        case 3:  smoothVerticalLines_setup();                        break;
        case 4:  randomGlitchHorizontalLines_LowProba_setup();       break;
        case 5:  randomGlitchHorizontalLines_MidProba_setup();       break;
        case 6:  randomGlitchHorizontalLines_HiProba_setup();        break;
        case 7:  randomGlitchVerticalLines_LowProba_setup();         break;
        case 8:  randomGlitchVerticalLines_MidProba_setup();         break;
        case 9:  randomGlitchVerticalLines_HiProba_setup();          break;
        case 10: randomGlitchLinesRandomAngle_LowProba_setup();      break;
        case 11: randomGlitchLinesRandomAngle_MidProba_setup();      break;
        case 12: randomGlitchLinesRandomAngle_HiProba_setup();       break;
            
        case 13:  smoothHorizontalLines_setup();                     break;
        case 14:  smoothVerticalLines_setup();                       break;
        case 15:  randomGlitchHorizontalLines_LowProba_setup();      break;
        case 16:  randomGlitchHorizontalLines_MidProba_setup();      break;
        case 17:  randomGlitchHorizontalLines_HiProba_setup();       break;
        case 18:  randomGlitchVerticalLines_LowProba_setup();        break;
        case 19:  randomGlitchVerticalLines_MidProba_setup();        break;
        case 20:  randomGlitchVerticalLines_HiProba_setup();         break;
        case 21:  randomGlitchLinesRandomAngle_LowProba_setup();     break;
        case 22:  randomGlitchLinesRandomAngle_MidProba_setup();     break;
        case 23:  randomGlitchLinesRandomAngle_HiProba_setup();      break;
            
        case 24:  smoothHorizontalLines_setup();                     break;
        case 25:  smoothVerticalLines_setup();                       break;
        case 26:  randomGlitchHorizontalLines_LowProba_setup();      break;
        case 27:  randomGlitchHorizontalLines_MidProba_setup();      break;
        case 28:  randomGlitchHorizontalLines_HiProba_setup();       break;
        case 29:  randomGlitchVerticalLines_LowProba_setup();        break;
        case 30:  randomGlitchVerticalLines_MidProba_setup();        break;
        case 31:  randomGlitchVerticalLines_HiProba_setup();         break;
        case 32:  randomGlitchLinesRandomAngle_LowProba_setup();     break;
        case 33:  randomGlitchLinesRandomAngle_MidProba_setup();     break;
        case 34:  randomGlitchLinesRandomAngle_HiProba_setup();      break;
            
        case 35:  generalDimmer_80percent_setup();                   break;
        case 36:  generalDimmer_50percent_setup();                   break;
        case 37:  generalDimmer_30percent_setup();                   break;
        case 38:  generalDimmer_fadeIn_fast_setup();                 break;
        case 39:  generalDimmer_fadeIn_medium_setup();               break;
        case 40:  generalDimmer_fadeIn_slow_setup();                 break;
        case 41:  generalDimmer_fadeOut_fast_setup();                break;
        case 42:  generalDimmer_fadeOut_medium_setup();              break;
        case 43:  generalDimmer_fadeOut_slow_setup();                break;
            
        default: animationNumber = 1;                                break;
    }
}

// Don't do any drawing here
void CustomSource::update(){
    switch (animationNumber)
    {
        case 0:
        case 1:  void_update();                                       break;
        case 2:  smoothHorizontalLines_update();                      break;
        case 3:  smoothVerticalLines_update();                        break;
        case 4:  randomGlitchHorizontalLines_LowProba_update();       break;
        case 5:  randomGlitchHorizontalLines_MidProba_update();       break;
        case 6:  randomGlitchHorizontalLines_HiProba_update();        break;
        case 7:  randomGlitchVerticalLines_LowProba_update();         break;
        case 8:  randomGlitchVerticalLines_MidProba_update();         break;
        case 9:  randomGlitchVerticalLines_HiProba_update();          break;
        case 10: randomGlitchLinesRandomAngle_LowProba_update();      break;
        case 11: randomGlitchLinesRandomAngle_MidProba_update();      break;
        case 12: randomGlitchLinesRandomAngle_HiProba_update();       break;
            
        case 13:  smoothHorizontalLines_update();                     break;
        case 14:  smoothVerticalLines_update();                       break;
        case 15:  randomGlitchHorizontalLines_LowProba_update();      break;
        case 16:  randomGlitchHorizontalLines_MidProba_update();      break;
        case 17:  randomGlitchHorizontalLines_HiProba_update();       break;
        case 18:  randomGlitchVerticalLines_LowProba_update();        break;
        case 19:  randomGlitchVerticalLines_MidProba_update();        break;
        case 20:  randomGlitchVerticalLines_HiProba_update();         break;
        case 21:  randomGlitchLinesRandomAngle_LowProba_update();     break;
        case 22:  randomGlitchLinesRandomAngle_MidProba_update();     break;
        case 23:  randomGlitchLinesRandomAngle_HiProba_update();      break;
            
        case 24:  smoothHorizontalLines_update();                     break;
        case 25:  smoothVerticalLines_update();                       break;
        case 26:  randomGlitchHorizontalLines_LowProba_update();      break;
        case 27:  randomGlitchHorizontalLines_MidProba_update();      break;
        case 28:  randomGlitchHorizontalLines_HiProba_update();       break;
        case 29:  randomGlitchVerticalLines_LowProba_update();        break;
        case 30:  randomGlitchVerticalLines_MidProba_update();        break;
        case 31:  randomGlitchVerticalLines_HiProba_update();         break;
        case 32:  randomGlitchLinesRandomAngle_LowProba_update();     break;
        case 33:  randomGlitchLinesRandomAngle_MidProba_update();     break;
        case 34:  randomGlitchLinesRandomAngle_HiProba_update();      break;

        case 35:  generalDimmer_80percent_update();                   break;
        case 36:  generalDimmer_50percent_update();                   break;
        case 37:  generalDimmer_30percent_update();                   break;
        case 38:  generalDimmer_fadeIn_fast_update();                 break;
        case 39:  generalDimmer_fadeIn_medium_update();               break;
        case 40:  generalDimmer_fadeIn_slow_update();                 break;
        case 41:  generalDimmer_fadeOut_fast_update();                break;
        case 42:  generalDimmer_fadeOut_medium_update();              break;
        case 43:  generalDimmer_fadeOut_slow_update();                break;
        default:                                                      break;
    }
}

// No need to take care of fbo.begin() and fbo.end() here.
// All within draw() is being rendered into fbo;
void CustomSource::draw(){
    switch (animationNumber)
    {
        case 0:
        case 1:  void_draw();                                            break;
        case 2:  smoothHorizontalLines_white_draw();                     break;
        case 3:  smoothVerticalLines_white_draw();                       break;
        case 4:  randomGlitchHorizontalLines_LowProba_white_draw();      break;
        case 5:  randomGlitchHorizontalLines_MidProba_white_draw();      break;
        case 6:  randomGlitchHorizontalLines_HiProba_white_draw();       break;
        case 7:  randomGlitchVerticalLines_LowProba_white_draw();        break;
        case 8:  randomGlitchVerticalLines_MidProba_white_draw();        break;
        case 9:  randomGlitchVerticalLines_HiProba_white_draw();         break;
        case 10: randomGlitchLinesRandomAngle_LowProba_white_draw();     break;
        case 11: randomGlitchLinesRandomAngle_MidProba_white_draw();     break;
        case 12: randomGlitchLinesRandomAngle_HiProba_white_draw();      break;
            
        case 13:  smoothHorizontalLines_black_draw();                    break;
        case 14:  smoothVerticalLines_black_draw();                      break;
        case 15:  randomGlitchHorizontalLines_LowProba_black_draw();     break;
        case 16:  randomGlitchHorizontalLines_MidProba_black_draw();     break;
        case 17:  randomGlitchHorizontalLines_HiProba_black_draw();      break;
        case 18:  randomGlitchVerticalLines_LowProba_black_draw();       break;
        case 19:  randomGlitchVerticalLines_MidProba_black_draw();       break;
        case 20:  randomGlitchVerticalLines_HiProba_black_draw();        break;
        case 21:  randomGlitchLinesRandomAngle_LowProba_black_draw();    break;
        case 22:  randomGlitchLinesRandomAngle_MidProba_black_draw();    break;
        case 23:  randomGlitchLinesRandomAngle_HiProba_black_draw();     break;
            
        case 24:  smoothHorizontalLines_red_draw();                      break;
        case 25:  smoothVerticalLines_red_draw();                        break;
        case 26:  randomGlitchHorizontalLines_LowProba_red_draw();       break;
        case 27:  randomGlitchHorizontalLines_MidProba_red_draw();       break;
        case 28:  randomGlitchHorizontalLines_HiProba_red_draw();        break;
        case 29:  randomGlitchVerticalLines_LowProba_red_draw();         break;
        case 30:  randomGlitchVerticalLines_MidProba_red_draw();         break;
        case 31:  randomGlitchVerticalLines_HiProba_red_draw();          break;
        case 32:  randomGlitchLinesRandomAngle_LowProba_red_draw();      break;
        case 33:  randomGlitchLinesRandomAngle_MidProba_red_draw();      break;
        case 34:  randomGlitchLinesRandomAngle_HiProba_red_draw();       break;
            
        case 35:  generalDimmer_80percent_draw();                        break;
        case 36:  generalDimmer_50percent_draw();                        break;
        case 37:  generalDimmer_30percent_draw();                        break;
        case 38:  generalDimmer_fadeIn_fast_draw();                      break;
        case 39:  generalDimmer_fadeIn_medium_draw();                    break;
        case 40:  generalDimmer_fadeIn_slow_draw();                      break;
        case 41:  generalDimmer_fadeOut_fast_draw();                     break;
        case 42:  generalDimmer_fadeOut_medium_draw();                   break;
        case 43:  generalDimmer_fadeOut_slow_draw();                     break;
            
        default: break;
    }
	
}

void CustomSource::clearAnimation(int animNb){
    switch (animationNumber)
    {
        case 0:
        case 1:  void_clear();                                       break;
        case 2:  smoothHorizontalLines_clear();                      break;
        case 3:  smoothVerticalLines_clear();                        break;
        case 4:  randomGlitchHorizontalLines_LowProba_clear();       break;
        case 5:  randomGlitchHorizontalLines_MidProba_clear();       break;
        case 6:  randomGlitchHorizontalLines_HiProba_clear();        break;
        case 7:  randomGlitchVerticalLines_LowProba_clear();         break;
        case 8:  randomGlitchVerticalLines_MidProba_clear();         break;
        case 9:  randomGlitchVerticalLines_HiProba_clear();          break;
        case 10: randomGlitchLinesRandomAngle_LowProba_clear();      break;
        case 11: randomGlitchLinesRandomAngle_MidProba_clear();      break;
        case 12: randomGlitchLinesRandomAngle_HiProba_clear();       break;
            
        case 13:  smoothHorizontalLines_clear();                     break;
        case 14:  smoothVerticalLines_clear();                       break;
        case 15:  randomGlitchHorizontalLines_LowProba_clear();      break;
        case 16:  randomGlitchHorizontalLines_MidProba_clear();      break;
        case 17:  randomGlitchHorizontalLines_HiProba_clear();       break;
        case 18:  randomGlitchVerticalLines_LowProba_clear();        break;
        case 19:  randomGlitchVerticalLines_MidProba_clear();        break;
        case 20:  randomGlitchVerticalLines_HiProba_clear();         break;
        case 21:  randomGlitchLinesRandomAngle_LowProba_clear();     break;
        case 22:  randomGlitchLinesRandomAngle_MidProba_clear();     break;
        case 23:  randomGlitchLinesRandomAngle_HiProba_clear();      break;
            
        case 24:  smoothHorizontalLines_clear();                     break;
        case 25:  smoothVerticalLines_clear();                       break;
        case 26:  randomGlitchHorizontalLines_LowProba_clear();      break;
        case 27:  randomGlitchHorizontalLines_MidProba_clear();      break;
        case 28:  randomGlitchHorizontalLines_HiProba_clear();       break;
        case 29:  randomGlitchVerticalLines_LowProba_clear();        break;
        case 30:  randomGlitchVerticalLines_MidProba_clear();        break;
        case 31:  randomGlitchVerticalLines_HiProba_clear();         break;
        case 32:  randomGlitchLinesRandomAngle_LowProba_clear();     break;
        case 33:  randomGlitchLinesRandomAngle_MidProba_clear();     break;
        case 34:  randomGlitchLinesRandomAngle_HiProba_clear();      break;
            
        case 35:  generalDimmer_80percent_clear();                   break;
        case 36:  generalDimmer_50percent_clear();                   break;
        case 37:  generalDimmer_30percent_clear();                   break;
        case 38:  generalDimmer_fadeIn_fast_clear();                 break;
        case 39:  generalDimmer_fadeIn_medium_clear();               break;
        case 40:  generalDimmer_fadeIn_slow_clear();                 break;
        case 41:  generalDimmer_fadeOut_fast_clear();                break;
        case 42:  generalDimmer_fadeOut_medium_clear();              break;
        case 43:  generalDimmer_fadeOut_slow_clear();                break;
            
        default: break;
    }
}

/////////////////////////////////////

void CustomSource::loadAnimation(int newAnimNb) {
    int oldAnimNb = animationNumber;
    animationNumber = newAnimNb;
    specificSetup();
    clearAnimation(oldAnimNb);
}


/////////////////////////////////////

void CustomSource::void_draw() {
	ofClear(0);
}

void CustomSource::void_setup() {
    
}

void CustomSource::void_update() {
    
}

void CustomSource::void_clear() {
    
}

/////////////////////////////////////

void CustomSource:: drawRectangleArray(){
#if (OF_VERSION_MAJOR == 0 && OF_VERSION_MINOR >= 9) || OF_VERSION_MAJOR > 0
    for(int i = 0; i < rects.size(); i++){
        ofDrawRectangle(rects[i]);
    }
#else
    for(int i = 0; i < rects.size(); i++){
        ofRect(rects[i]);
    }
#endif
}

void CustomSource::smoothHorizontalLines_white_draw() {
	ofClear(0);
	ofSetColor(255);
    drawRectangleArray();
}

void CustomSource::smoothHorizontalLines_black_draw() {
	ofClear(0);
	ofSetColor(0);
    drawRectangleArray();
}

void CustomSource::smoothHorizontalLines_red_draw() {
	ofClear(0);
	ofSetColor(255,0,0);
    drawRectangleArray();
}

void CustomSource::smoothHorizontalLines_setup() {
    rects = std::vector<ofRectangle>();
    rectSpeeds = std::vector<float>();

    int numRects = 20;  // change this to add more or less rects
	for(int i = 0; i < numRects; i++){
		rects.push_back(ofRectangle(0,
									ofRandom(fbo->getHeight()),
									fbo->getWidth(),
									ofRandom(20)));
		rectSpeeds.push_back((1.0f + ofRandom(5)));
	}
}

void CustomSource::smoothHorizontalLines_update() {
	// Move rects
	for(int i = 0; i < rects.size(); i++){
		rects[i].y += rectSpeeds[i];
		if(rects[i].y > fbo->getHeight()){
			rects[i].y = -rects[i].getHeight();
		}
	}
}

void CustomSource::smoothHorizontalLines_clear() {
//    rects = std::vector<ofRectangle>();
//    rectSpeeds = std::vector<float>();
}

/////////////////////////////////////

void CustomSource::smoothVerticalLines_white_draw() {
    smoothHorizontalLines_white_draw();
}

void CustomSource::smoothVerticalLines_black_draw() {
    smoothHorizontalLines_black_draw();
}

void CustomSource::smoothVerticalLines_red_draw() {
    smoothHorizontalLines_red_draw();
}

void CustomSource::smoothVerticalLines_setup() {
    int numRects = 20;  // change this to add more or less rects
    rects = std::vector<ofRectangle>();
    rectSpeeds = std::vector<float>();
    
	for(int i = 0; i < numRects; i++){
		rects.push_back(ofRectangle(ofRandom(fbo->getWidth()),
                                    0,
									ofRandom(20),
                                    fbo->getWidth()));
		rectSpeeds.push_back((1.0f + ofRandom(5)));
	}
}

void CustomSource::smoothVerticalLines_update() {
	// Move rects
	for(int i = 0; i < rects.size(); i++){
		rects[i].x += rectSpeeds[i];
		if(rects[i].x > fbo->getWidth()){
			rects[i].x = -rects[i].getWidth();
		}
	}
}

void CustomSource::smoothVerticalLines_clear() {
}

/////////////////////////////////////

void CustomSource:: drawGlitchRectangleArray(float probability){
#if (OF_VERSION_MAJOR == 0 && OF_VERSION_MINOR >= 9) || OF_VERSION_MAJOR > 0
    for(int i = 0; i < rects.size(); i++){
        if (ofRandom(0,100) < probability) {
            ofDrawRectangle(rects[i]);
        }
    }
#else
    for(int i = 0; i < rects.size(); i++){
        if (ofRandom(0,100) < probability) {
            ofRect(rects[i]);
        }
    }
#endif
}


void CustomSource::randomGlitchLines_draw(float probability) {
    if (ofRandom(0,100) < probability) {
        ofClear(0);
    }
    else {
        ofClear(0);
        drawGlitchRectangleArray(probability);
    }
}

void CustomSource::randomGlitchLines_white_draw(float probability) {
    ofSetColor(255);
    randomGlitchLines_draw(probability);
}

void CustomSource::randomGlitchLines_black_draw(float probability) {
    ofSetColor(0);
    randomGlitchLines_draw(probability);
}

void CustomSource::randomGlitchLines_red_draw(float probability) {
    ofSetColor(255,0,0);
    randomGlitchLines_draw(probability);
}

void CustomSource::randomGlitchHorizontalLines_LowProba_white_draw() {
    randomGlitchLines_white_draw(10.0);
}

void CustomSource::randomGlitchHorizontalLines_LowProba_black_draw() {
    randomGlitchLines_black_draw(10.0);
}

void CustomSource::randomGlitchHorizontalLines_LowProba_red_draw() {
    randomGlitchLines_red_draw(10.0);
}

void CustomSource::randomGlitchHorizontalLines_LowProba_setup() {
    int numRects = 6;  // change this to add more or less rects
    rects = std::vector<ofRectangle>();
    
	for(int i = 0; i < numRects; i++){
		rects.push_back(ofRectangle(0,
									ofRandom(fbo->getHeight()),
									fbo->getWidth(),
									ofRandom(50)));
	}
}

void CustomSource::randomGlitchHorizontalLines_LowProba_update() {
	// Move rects
	for(int i = 0; i < rects.size(); i++){
		rects[i].y = (int)ofRandom(0,fbo->getWidth());
	}
}

void CustomSource::randomGlitchHorizontalLines_LowProba_clear() {

}

//////////////////////////////////

void CustomSource::randomGlitchVerticalLines_LowProba_setup() {
    int numRects = 6;  // change this to add more or less rects
    rects = std::vector<ofRectangle>();
    
	for(int i = 0; i < numRects; i++){
		rects.push_back(ofRectangle(ofRandom(fbo->getWidth()),
                                    0,
									ofRandom(50),
                                    fbo->getWidth()));
	}
}

void CustomSource::randomGlitchVerticalLines_LowProba_update() {
	// Move rects
	for(int i = 0; i < rects.size(); i++){
		rects[i].x = (int)ofRandom(0,fbo->getWidth());
	}
}

void CustomSource::randomGlitchVerticalLines_LowProba_white_draw() {
    ofSetColor(255);
    randomGlitchLines_draw(20.0);
}

void CustomSource::randomGlitchVerticalLines_LowProba_black_draw() {
    ofSetColor(0);
    randomGlitchLines_draw(20.0);
}

void CustomSource::randomGlitchVerticalLines_LowProba_red_draw() {
    ofSetColor(255,0,0);
    randomGlitchLines_draw(20.0);
}

void CustomSource::randomGlitchVerticalLines_LowProba_clear() {

}

//////////////////////////////////

void CustomSource::randomGlitchHorizontalLines_HiProba_white_draw() {
    ofSetColor(255);
    randomGlitchLines_draw(50.0);
}

void CustomSource::randomGlitchHorizontalLines_HiProba_black_draw() {
    ofSetColor(0);
    randomGlitchLines_draw(50.0);
}

void CustomSource::randomGlitchHorizontalLines_HiProba_red_draw() {
    ofSetColor(255,0,0);
    randomGlitchLines_draw(50.0);
}

void CustomSource::randomGlitchHorizontalLines_HiProba_setup() {
    randomGlitchHorizontalLines_LowProba_setup();
}

void CustomSource::randomGlitchHorizontalLines_HiProba_update() {
    randomGlitchHorizontalLines_LowProba_update();
}

void CustomSource::randomGlitchHorizontalLines_HiProba_clear() {
    randomGlitchHorizontalLines_LowProba_clear();
}


void CustomSource::randomGlitchHorizontalLines_MidProba_white_draw() {
    ofSetColor(255);
    randomGlitchLines_draw(30.0);
}

void CustomSource::randomGlitchHorizontalLines_MidProba_black_draw() {
    ofSetColor(0);
    randomGlitchLines_draw(30.0);
}

void CustomSource::randomGlitchHorizontalLines_MidProba_red_draw() {
    ofSetColor(255,0,0);
    randomGlitchLines_draw(30.0);
}

void CustomSource::randomGlitchHorizontalLines_MidProba_setup() {
    randomGlitchHorizontalLines_LowProba_setup();
}

void CustomSource::randomGlitchHorizontalLines_MidProba_update() {
    randomGlitchHorizontalLines_LowProba_update();
}

void CustomSource::randomGlitchHorizontalLines_MidProba_clear() {
    randomGlitchHorizontalLines_LowProba_clear();
}



void CustomSource::randomGlitchVerticalLines_HiProba_white_draw() {
    randomGlitchHorizontalLines_HiProba_white_draw();
}

void CustomSource::randomGlitchVerticalLines_HiProba_black_draw() {
    randomGlitchHorizontalLines_HiProba_black_draw();
}

void CustomSource::randomGlitchVerticalLines_HiProba_red_draw() {
    randomGlitchHorizontalLines_HiProba_red_draw();
}

void CustomSource::randomGlitchVerticalLines_HiProba_setup() {
    randomGlitchVerticalLines_LowProba_setup();
}

void CustomSource::randomGlitchVerticalLines_HiProba_update() {
    randomGlitchVerticalLines_LowProba_update();
}

void CustomSource::randomGlitchVerticalLines_HiProba_clear() {
    randomGlitchVerticalLines_LowProba_clear();
}


void CustomSource::randomGlitchVerticalLines_MidProba_white_draw() {
    randomGlitchHorizontalLines_MidProba_white_draw();
}

void CustomSource::randomGlitchVerticalLines_MidProba_black_draw() {
    randomGlitchHorizontalLines_MidProba_black_draw();
}

void CustomSource::randomGlitchVerticalLines_MidProba_red_draw() {
    randomGlitchHorizontalLines_MidProba_red_draw();
}

void CustomSource::randomGlitchVerticalLines_MidProba_setup() {
    randomGlitchVerticalLines_LowProba_setup();
}

void CustomSource::randomGlitchVerticalLines_MidProba_update() {
    randomGlitchVerticalLines_LowProba_update();
}

void CustomSource::randomGlitchVerticalLines_MidProba_clear() {
    randomGlitchVerticalLines_LowProba_clear();
}


////////////////////////////////////////////////



void CustomSource::randomGlitchLines_randomAngle_draw(float probability) {
	ofClear(0);

	ofPushMatrix();
    ofTranslate(fbo->getWidth()/2, fbo->getHeight()/2, 0);
    ofRotate(randomAngle,0.0,0.0,1.0);

	ofPushMatrix();
    ofTranslate(-fbo->getWidth()/2, -fbo->getHeight()/2, 0);
    drawGlitchRectangleArray(probability);
    ofPopMatrix();
    
    ofPopMatrix();
}

void CustomSource::randomGlitchLinesRandomAngle_LowProba_white_draw() {
	ofSetColor(255);
    randomGlitchLines_randomAngle_draw(10.0);
}

void CustomSource::randomGlitchLinesRandomAngle_LowProba_black_draw() {
	ofSetColor(0);
    randomGlitchLines_randomAngle_draw(10.0);
}

void CustomSource::randomGlitchLinesRandomAngle_LowProba_red_draw() {
	ofSetColor(255,0,0);
    randomGlitchLines_randomAngle_draw(10.0);
}

void CustomSource::randomGlitchLinesRandomAngle_LowProba_setup() {
    randomAngle = ofRandom(0,180);
    int numRects = 6;  // change this to add more or less rects
    rects = std::vector<ofRectangle>();
    
	for(int i = 0; i < numRects; i++){
		rects.push_back(ofRectangle(-ofRandom(1*fbo->getHeight()),
									ofRandom(2*fbo->getHeight()),
									2.5*(fbo->getWidth()),
									ofRandom(50)));
	}
}

void CustomSource::randomGlitchLinesRandomAngle_LowProba_update() {
	for(int i = 0; i < rects.size(); i++){
		rects[i].y = (int)ofRandom(0,fbo->getWidth());
	}
}

void CustomSource::randomGlitchLinesRandomAngle_LowProba_clear() {
    
}



void CustomSource::randomGlitchLinesRandomAngle_MidProba_white_draw() {
    ofSetColor(255);
    randomGlitchLines_randomAngle_draw(25.0);
}

void CustomSource::randomGlitchLinesRandomAngle_MidProba_black_draw() {
    ofSetColor(0);
    randomGlitchLines_randomAngle_draw(25.0);
}

void CustomSource::randomGlitchLinesRandomAngle_MidProba_red_draw() {
    ofSetColor(255,0,0);
    randomGlitchLines_randomAngle_draw(25.0);
}

void CustomSource::randomGlitchLinesRandomAngle_MidProba_setup() {
    randomGlitchLinesRandomAngle_LowProba_setup();
}

void CustomSource::randomGlitchLinesRandomAngle_MidProba_update() {
    randomGlitchLinesRandomAngle_LowProba_update();
}

void CustomSource::randomGlitchLinesRandomAngle_MidProba_clear() {
    randomGlitchLinesRandomAngle_LowProba_clear();
}

void CustomSource::randomGlitchLinesRandomAngle_HiProba_white_draw() {
    ofSetColor(255);
    randomGlitchLines_randomAngle_draw(60.0);
}

void CustomSource::randomGlitchLinesRandomAngle_HiProba_black_draw() {
    ofSetColor(0);
    randomGlitchLines_randomAngle_draw(60.0);
}

void CustomSource::randomGlitchLinesRandomAngle_HiProba_red_draw() {
    ofSetColor(255,0,0);
    randomGlitchLines_randomAngle_draw(60.0);
}

void CustomSource::randomGlitchLinesRandomAngle_HiProba_setup() {
    randomGlitchLinesRandomAngle_LowProba_setup();
}

void CustomSource::randomGlitchLinesRandomAngle_HiProba_update() {
    randomGlitchLinesRandomAngle_LowProba_update();
}

void CustomSource::randomGlitchLinesRandomAngle_HiProba_clear() {
    randomGlitchLinesRandomAngle_LowProba_clear();
}


/////////////////////////////////////////

void CustomSource::generalDimmer_80percent_update(){
    
}

void CustomSource::generalDimmer_50percent_update(){
    
}

void CustomSource::generalDimmer_30percent_update(){
    
}

void CustomSource::generalDimmer_fadeIn_fast_update(){
    generalDimmer_progress += 6;
}

void CustomSource::generalDimmer_fadeIn_medium_update(){
    generalDimmer_progress += 4;
}

void CustomSource::generalDimmer_fadeIn_slow_update(){
    generalDimmer_progress += 1;
}

void CustomSource::generalDimmer_fadeOut_fast_update(){
    generalDimmer_progress += 6;
}

void CustomSource::generalDimmer_fadeOut_medium_update(){
    generalDimmer_progress += 4;
}

void CustomSource::generalDimmer_fadeOut_slow_update(){
    generalDimmer_progress += 1;
}


void CustomSource::generalDimmer_80percent_setup(){
    
}

void CustomSource::generalDimmer_50percent_setup(){
    
}

void CustomSource::generalDimmer_30percent_setup(){
    
}

void CustomSource::generalDimmer_fadeIn_fast_setup(){
    
}

void CustomSource::generalDimmer_fadeIn_medium_setup(){
    generalDimmer_progress = 0;
}

void CustomSource::generalDimmer_fadeIn_slow_setup(){
    generalDimmer_progress = 0;
}

void CustomSource::generalDimmer_fadeOut_fast_setup(){
    generalDimmer_progress = 0;
}

void CustomSource::generalDimmer_fadeOut_medium_setup(){
    generalDimmer_progress = 0;
}

void CustomSource::generalDimmer_fadeOut_slow_setup(){
    generalDimmer_progress = 0;
}


void CustomSource::generalDimmer_80percent_draw(){
    ofSetColor(0,0,0, int(255.0*0.2));
    ofDrawRectangle( ofRectangle(0, 0, fbo->getWidth(), fbo->getHeight()) );
}

void CustomSource::generalDimmer_50percent_draw(){
    ofSetColor(0,0,0, int(255.0*0.5));
    ofDrawRectangle( ofRectangle(0, 0, fbo->getWidth(), fbo->getHeight()) );
}

void CustomSource::generalDimmer_30percent_draw(){
    ofSetColor(0,0,0, int(255.0*0.7));
    ofDrawRectangle( ofRectangle(0, 0, fbo->getWidth(), fbo->getHeight()) );
}

void CustomSource::generalDimmer_fadeIn_fast_draw(){
    ofSetColor(0,0,0, int(MAX(0, 255-generalDimmer_progress)));
    ofDrawRectangle( ofRectangle(0, 0, fbo->getWidth(), fbo->getHeight()) );
}

void CustomSource::generalDimmer_fadeIn_medium_draw(){
    ofSetColor(0,0,0, int(MAX(0, 255-generalDimmer_progress)));
    ofDrawRectangle( ofRectangle(0, 0, fbo->getWidth(), fbo->getHeight()) );

}

void CustomSource::generalDimmer_fadeIn_slow_draw(){
    ofSetColor(0,0,0, int(MAX(0, 255-generalDimmer_progress)));
    ofDrawRectangle( ofRectangle(0, 0, fbo->getWidth(), fbo->getHeight()) );

}

void CustomSource::generalDimmer_fadeOut_fast_draw(){
    ofSetColor(0,0,0, int(MIN(255, generalDimmer_progress)));
    ofDrawRectangle( ofRectangle(0, 0, fbo->getWidth(), fbo->getHeight()) );
}

void CustomSource::generalDimmer_fadeOut_medium_draw(){
    ofSetColor(0,0,0, int(MIN(255, generalDimmer_progress)));
    ofDrawRectangle( ofRectangle(0, 0, fbo->getWidth(), fbo->getHeight()) );
}

void CustomSource::generalDimmer_fadeOut_slow_draw(){
    ofSetColor(0,0,0, int(MIN(255, generalDimmer_progress)));
    ofDrawRectangle( ofRectangle(0, 0, fbo->getWidth(), fbo->getHeight()) );
}


void CustomSource::generalDimmer_80percent_clear(){
    
}

void CustomSource::generalDimmer_50percent_clear(){
    
}

void CustomSource::generalDimmer_30percent_clear(){
    
}

void CustomSource::generalDimmer_fadeIn_fast_clear(){
    
}

void CustomSource::generalDimmer_fadeIn_medium_clear(){
    
}

void CustomSource::generalDimmer_fadeIn_slow_clear(){
    
}

void CustomSource::generalDimmer_fadeOut_fast_clear(){
    
}

void CustomSource::generalDimmer_fadeOut_medium_clear(){
    
}

void CustomSource::generalDimmer_fadeOut_slow_clear(){
    
}

