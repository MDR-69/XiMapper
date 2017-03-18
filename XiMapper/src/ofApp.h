#pragma once

#include "ofMain.h"
#include "Settings.h"
#include "ofxPiMapper.h"
#include "CustomSource.h"
#include "VideoSource.h"

#define VIDEO_SURFACE_IDX       0
#define EFFECTS_SURFACE_IDX     1

// TPM2 protocol definitions
#define TPM2NET_HEADER_SIZE     4
#define TPM2NET_HEADER_IDENT    0x9c
#define TPM2NET_CMD_DATAFRAME   0xda
#define TPM2NET_CMD_COMMAND     0xc0
#define TPM2NET_CMD_ANSWER      0xaa
#define TPM2NET_FOOTER_IDENT    0x36
#define SERIAL_FOOTER_SIZE      1

#define USEFUL_PAYLOAD_SIZE     4

#define CMD_HEARTBEAT           0
#define CMD_SYSEX               1
#define CMD_TIMEINFO            2
#define CMD_DISPLAYIMG          3
#define CMD_PLAYVIDEOLOOP       4
#define CMD_PLAYVIDEOONCE       5
#define CMD_LOADVIDEO           6
#define CMD_SETIMGEFFECT        7
#define CMD_SETCUSTOMEFFECT     8
#define CMD_CALIBRATION_X1      9
#define CMD_CALIBRATION_Y1      10
#define CMD_CALIBRATION_X2      11
#define CMD_CALIBRATION_Y2      12
#define CMD_CALIBRATION_X3      13
#define CMD_CALIBRATION_Y3      14
#define CMD_CALIBRATION_X4      15
#define CMD_CALIBRATION_Y4      16
#define CMD_SAVE_SETTINGS       17

#define MAIN_VIDEO_DATA_PATH    "/Users/Martin/Documents/OpenFrameworks/addons/ofxPiMapper/XiMapper/bin/data/sources/videos/"
#define MAIN_IMAGE_DATA_PATH    "/Users/Martin/Documents/OpenFrameworks/addons/ofxPiMapper/XiMapper/bin/data/sources/images/"
#define FX_IMAGE_DATA_PATH      "/Users/Martin/Documents/OpenFrameworks/addons/ofxPiMapper/XiMapper/bin/data/sources/images/fx/"

class ofApp : public ofBaseApp {
	public:
		void setup();
		void update();
		void draw();
        void processRxMsg(unsigned char*);
        void readSerialData();
    
        string getVideoPath(int number);
        string getMainImagePath(int number);
        string getFxImagePath(int number);
    
        void loadVideoInMediaServer(int number);
    
        void setVideoByNb(int number, ofLoopType loopType);
        void setImageByNb(int number);
        void setImageFxByNb(int number);
        void setCustomFxByNb(int number);
        void setVideoByPath(string & path, ofLoopType loopType);
        void setImageByPath(string & path);
        void setImageFxByPath(string & path);
    
        void calibrateSurface(unsigned int vertexElem, unsigned int valLsb, unsigned int valMsb);
        void saveCurrentSettings();
    
		ofxPiMapper piMapper;

		// By using a custom source that is derived from FboSource
		// you will be able to see the source listed in sources editor
		CustomSource * customSource;
    
        ofSerial	serial;
    
        char		incomingCmdMsg[4];          // data transmitted by the RF microcontroller
        int			nBytesRead;					// how much did we read?
        int			nTimesRead;					// how many times did we read?

};
