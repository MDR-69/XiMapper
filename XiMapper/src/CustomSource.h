#pragma once

#include "ofMain.h"
#include "FboSource.h"

class CustomSource : public ofx::piMapper::FboSource {
	public:
        void setup();
        void specificSetup();
		void update();
		void draw();
        void clearAnimation(int animNb);
        void loadAnimation(int newAnimNb);

        int animationNumber = 0;

        void void_draw();
        void void_setup();
        void void_update();
        void void_clear();
    
        vector <ofRectangle> rects;
        vector <float> rectSpeeds;
        void smoothHorizontalLines_white_draw();
        void smoothHorizontalLines_black_draw();
        void smoothHorizontalLines_red_draw();
        void smoothHorizontalLines_setup();
        void smoothHorizontalLines_update();
        void smoothHorizontalLines_clear();
    
        void drawRectangleArray();
    
        void smoothVerticalLines_white_draw();
        void smoothVerticalLines_black_draw();
        void smoothVerticalLines_red_draw();
        void smoothVerticalLines_setup();
        void smoothVerticalLines_update();
        void smoothVerticalLines_clear();

        void randomGlitchHorizontalLines_LowProba_white_draw();
        void randomGlitchHorizontalLines_LowProba_black_draw();
        void randomGlitchHorizontalLines_LowProba_red_draw();
        void randomGlitchHorizontalLines_LowProba_setup();
        void randomGlitchHorizontalLines_LowProba_update();
        void randomGlitchHorizontalLines_LowProba_clear();

        void randomGlitchVerticalLines_LowProba_white_draw();
        void randomGlitchVerticalLines_LowProba_black_draw();
        void randomGlitchVerticalLines_LowProba_red_draw();
        void randomGlitchVerticalLines_LowProba_setup();
        void randomGlitchVerticalLines_LowProba_update();
        void randomGlitchVerticalLines_LowProba_clear();

        void randomGlitchHorizontalLines_MidProba_white_draw();
        void randomGlitchHorizontalLines_MidProba_black_draw();
        void randomGlitchHorizontalLines_MidProba_red_draw();
        void randomGlitchHorizontalLines_MidProba_setup();
        void randomGlitchHorizontalLines_MidProba_update();
        void randomGlitchHorizontalLines_MidProba_clear();
    
        void randomGlitchVerticalLines_MidProba_white_draw();
        void randomGlitchVerticalLines_MidProba_black_draw();
        void randomGlitchVerticalLines_MidProba_red_draw();
        void randomGlitchVerticalLines_MidProba_setup();
        void randomGlitchVerticalLines_MidProba_update();
        void randomGlitchVerticalLines_MidProba_clear();
    
        void randomGlitchHorizontalLines_HiProba_white_draw();
        void randomGlitchHorizontalLines_HiProba_black_draw();
        void randomGlitchHorizontalLines_HiProba_red_draw();
        void randomGlitchHorizontalLines_HiProba_setup();
        void randomGlitchHorizontalLines_HiProba_update();
        void randomGlitchHorizontalLines_HiProba_clear();
    
        void randomGlitchVerticalLines_HiProba_white_draw();
        void randomGlitchVerticalLines_HiProba_black_draw();
        void randomGlitchVerticalLines_HiProba_red_draw();
        void randomGlitchVerticalLines_HiProba_setup();
        void randomGlitchVerticalLines_HiProba_update();
        void randomGlitchVerticalLines_HiProba_clear();
    
        void randomGlitchLines_draw(float probability);
        void randomGlitchLines_white_draw(float probability);
        void randomGlitchLines_black_draw(float probability);
        void randomGlitchLines_red_draw(float probability);
        void drawGlitchRectangleArray(float probability);
    
        float randomAngle;
        void randomGlitchLines_randomAngle_draw(float probability);
        void randomGlitchLinesRandomAngle_LowProba_white_draw();
        void randomGlitchLinesRandomAngle_LowProba_black_draw();
        void randomGlitchLinesRandomAngle_LowProba_red_draw();
        void randomGlitchLinesRandomAngle_MidProba_white_draw();
        void randomGlitchLinesRandomAngle_MidProba_black_draw();
        void randomGlitchLinesRandomAngle_MidProba_red_draw();
        void randomGlitchLinesRandomAngle_HiProba_white_draw();
        void randomGlitchLinesRandomAngle_HiProba_black_draw();
        void randomGlitchLinesRandomAngle_HiProba_red_draw();
        void randomGlitchLinesRandomAngle_LowProba_setup();
        void randomGlitchLinesRandomAngle_LowProba_update();
        void randomGlitchLinesRandomAngle_LowProba_clear();
        void randomGlitchLinesRandomAngle_MidProba_setup();
        void randomGlitchLinesRandomAngle_MidProba_update();
        void randomGlitchLinesRandomAngle_MidProba_clear();
        void randomGlitchLinesRandomAngle_HiProba_setup();
        void randomGlitchLinesRandomAngle_HiProba_update();
        void randomGlitchLinesRandomAngle_HiProba_clear();

    
        float generalDimmer_progress;
        void generalDimmer_80percent_update();
        void generalDimmer_50percent_update();
        void generalDimmer_30percent_update();
        void generalDimmer_fadeIn_fast_update();
        void generalDimmer_fadeIn_medium_update();
        void generalDimmer_fadeIn_slow_update();
        void generalDimmer_fadeOut_fast_update();
        void generalDimmer_fadeOut_medium_update();
        void generalDimmer_fadeOut_slow_update();
    
        void generalDimmer_80percent_setup();
        void generalDimmer_50percent_setup();
        void generalDimmer_30percent_setup();
        void generalDimmer_fadeIn_fast_setup();
        void generalDimmer_fadeIn_medium_setup();
        void generalDimmer_fadeIn_slow_setup();
        void generalDimmer_fadeOut_fast_setup();
        void generalDimmer_fadeOut_medium_setup();
        void generalDimmer_fadeOut_slow_setup();
    
        void generalDimmer_80percent_draw();
        void generalDimmer_50percent_draw();
        void generalDimmer_30percent_draw();
        void generalDimmer_fadeIn_fast_draw();
        void generalDimmer_fadeIn_medium_draw();
        void generalDimmer_fadeIn_slow_draw();
        void generalDimmer_fadeOut_fast_draw();
        void generalDimmer_fadeOut_medium_draw();
        void generalDimmer_fadeOut_slow_draw();
    
        void generalDimmer_80percent_clear();
        void generalDimmer_50percent_clear();
        void generalDimmer_30percent_clear();
        void generalDimmer_fadeIn_fast_clear();
        void generalDimmer_fadeIn_medium_clear();
        void generalDimmer_fadeIn_slow_clear();
        void generalDimmer_fadeOut_fast_clear();
        void generalDimmer_fadeOut_medium_clear();
        void generalDimmer_fadeOut_slow_clear();
    
    
};