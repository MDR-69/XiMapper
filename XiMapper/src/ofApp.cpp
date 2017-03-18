#include "ofApp.h"

void ofApp::setup(){
	ofBackground(0);
    
    serial.listDevices();
    vector <ofSerialDeviceInfo> deviceList = serial.getDeviceList();
    
    int baud = 115200;
    //serial.setup(0, baud); //open the first device
    serial.setup("/dev/tty.usbmodem1868531", baud); // mac osx example

	// Enable or disable audio for video sources globally
	// Set this to false to save resources on the Raspberry Pi
	ofx::piMapper::VideoSource::enableAudio = false;

	customSource = new CustomSource();
	piMapper.registerFboSource(customSource);
    
	piMapper.setup();

	// The info layer is hidden by default, press <i> to toggle
	// piMapper.showInfo();
	
	ofSetFullscreen(Settings::instance()->getFullscreen());
}

void ofApp::update(){
	piMapper.update();
    readSerialData();           // Check incoming serial data
}

void ofApp::draw(){
	piMapper.draw();
}


///////////////////////////////////////////////////////

void ofApp::readSerialData() {
    unsigned char msgHeader[6];
    unsigned char incomingCmdMsg[4];
    memset(msgHeader, 0, 6);
    if (serial.available() > 0) {
        serial.readBytes(msgHeader, 1);
        
        if (msgHeader[0] == TPM2NET_HEADER_IDENT) {
            serial.readBytes(msgHeader + 1, 5);
            /*  // These fields are unused for now, but this code will stay commented in order not to lose the info
             unsigned char frameType       = msgHeader[1]; unsigned char frameSize_msb   = msgHeader[2];
             unsigned char frameSize_lsb   = msgHeader[3]; unsigned char rx_packetNb     = msgHeader[4]; unsigned char rx_totalPackets = msgHeader[5];
             */
            serial.readBytes(incomingCmdMsg, USEFUL_PAYLOAD_SIZE);
            
            unsigned int msgFooter = serial.readByte();
            if (msgFooter == TPM2NET_FOOTER_IDENT) {
                // Accept message
                processRxMsg(incomingCmdMsg);
            }
        }
    }
}

void ofApp::processRxMsg(unsigned char* incomingMsg) {
    unsigned int commandNb = (int) incomingMsg[0];
    unsigned int data1     = (int) incomingMsg[1];
    unsigned int data2     = (int) incomingMsg[2];
    unsigned int data3     = (int) incomingMsg[3];
    
    switch (commandNb)
    {
        case CMD_HEARTBEAT:       break;
        case CMD_SYSEX:           break;
        case CMD_TIMEINFO:        break;
        case CMD_DISPLAYIMG:      setImageByNb((data2 << 8) + data1);break;                     // Display the requested main image
        case CMD_PLAYVIDEOLOOP:   setVideoByNb((data2 << 8) + data1, OF_LOOP_NORMAL);break;     // Play the requested video. If the video is not yet loaded inside the memory, load it
        case CMD_PLAYVIDEOONCE:   setVideoByNb((data2 << 8) + data1, OF_LOOP_NONE);break;       // Play the requested video, but do not loop it
        case CMD_LOADVIDEO:       loadVideoInMediaServer((data2 << 8) + data1); break;          // Load the video inside the memory - but do not play it yet
        case CMD_SETIMGEFFECT:    setImageFxByNb((data2 << 8) + data1); break;                  // (data2 << 8 + data1) -> (msb << 8) + lsb
        case CMD_SETCUSTOMEFFECT: setCustomFxByNb((data2 << 8) + data1); break;
        case CMD_CALIBRATION_X1:
        case CMD_CALIBRATION_Y1:
        case CMD_CALIBRATION_X2:
        case CMD_CALIBRATION_Y2:
        case CMD_CALIBRATION_X3:
        case CMD_CALIBRATION_Y3:
        case CMD_CALIBRATION_X4:
        case CMD_CALIBRATION_Y4:  calibrateSurface(data1,data2,data3); break;                   // Change the mapping geometry
        case CMD_SAVE_SETTINGS:   saveCurrentSettings(); break;
        default:                  break;
    }
}

////////////////////////////////////////////

string ofApp::getVideoPath(int number) {
    string videoPath = "";
    switch (number)
    {
        case 0:
        case 1:      videoPath = MAIN_VIDEO_DATA_PATH "00_Blackout.mp4";  break;
        case 2:      videoPath = MAIN_VIDEO_DATA_PATH "01_Front_Static_Upright_Front_Static_ArmsClosed2.mp4";  break;
        case 3:      videoPath = MAIN_VIDEO_DATA_PATH "01_Front_Static_Upright_Front_Static_ArmsUpright1.mp4";  break;
        case 4:      videoPath = MAIN_VIDEO_DATA_PATH "02_Front_Static_ArmsOpen_Front_Static_ArmsOpen1.mp4";  break;
        case 5:      videoPath = MAIN_VIDEO_DATA_PATH "02_Front_Static_ArmsOpen_Front_Static_ArmsOpen2.mp4";  break;
        case 6:      videoPath = MAIN_VIDEO_DATA_PATH "02_Front_Static_ArmsOpen_Front_Static_ArmsOpen3.mp4";  break;
        case 7:      videoPath = MAIN_VIDEO_DATA_PATH "02_Front_Static_ArmsOpen_Front_Static_ArmsOpen4.mp4";  break;
        case 8:      videoPath = MAIN_VIDEO_DATA_PATH "02_Front_Static_ArmsOpen_Front_Static_ArmsOpen5.mp4";  break;
        case 9:      videoPath = MAIN_VIDEO_DATA_PATH "03_45Side_Static_ArmsOpen_45Side_ArmsOpen1.mp4";  break;
        case 10:     videoPath = MAIN_VIDEO_DATA_PATH "04_45Back_Static_ArmsOpen_45Back_Static_ArmsOpen1.mp4";  break;
        case 11:     videoPath = MAIN_VIDEO_DATA_PATH "06_Front_Slow_RaiseYourArms_Front_RaiseYourArms_DropOnly.mp4";  break;
        case 12:     videoPath = MAIN_VIDEO_DATA_PATH "06_Front_Slow_RaiseYourArms_Front_RaiseYourArms_DropOnly2.mp4";  break;
        case 13:     videoPath = MAIN_VIDEO_DATA_PATH "06_Front_Slow_RaiseYourArms_Front_RaiseYourArms_EndOnly.mp4";  break;
        case 14:     videoPath = MAIN_VIDEO_DATA_PATH "06_Front_Slow_RaiseYourArms_Front_RaiseYourArms_RaiseOnly.mp4";  break;
        case 15:     videoPath = MAIN_VIDEO_DATA_PATH "06_Front_Slow_RaiseYourArms_Front_RaiseYourArms1.mp4";  break;
        case 16:     videoPath = MAIN_VIDEO_DATA_PATH "08_45Side_DynamicStandBy_DynamicStandby1.mp4";  break;
        case 17:     videoPath = MAIN_VIDEO_DATA_PATH "08_45Side_DynamicStandBy_DynamicStandby2.mp4";  break;
        case 18:     videoPath = MAIN_VIDEO_DATA_PATH "08_45Side_DynamicStandBy_DynamicStandby3.mp4";  break;
        case 19:     videoPath = MAIN_VIDEO_DATA_PATH "08_45Side_DynamicStandBy_DynamicStandby4.mp4";  break;
        case 20:     videoPath = MAIN_VIDEO_DATA_PATH "08_45Side_DynamicStandBy_DynamicStandby5.mp4";  break;
        case 21:     videoPath = MAIN_VIDEO_DATA_PATH "08_45Side_DynamicStandBy_DynamicStandby6.mp4";  break;
        case 22:     videoPath = MAIN_VIDEO_DATA_PATH "09_45Side_StickToTheBeat_StickToTheBeat2.mp4";  break;
        case 23:     videoPath = MAIN_VIDEO_DATA_PATH "09_45Side_StickToTheBeat_WaistPose.mp4";  break;
        case 24:     videoPath = MAIN_VIDEO_DATA_PATH "10_45Side_ButtonTurning2_FingerDrumming1.mp4";  break;
        case 25:     videoPath = MAIN_VIDEO_DATA_PATH "10_45Side_ButtonTurning2_FingerDrumming2.mp4";  break;
        case 26:     videoPath = MAIN_VIDEO_DATA_PATH "10_45Side_ButtonTurning2_FingerDrumming3.mp4";  break;
        case 27:     videoPath = MAIN_VIDEO_DATA_PATH "10_45Side_ButtonTurning2_FingerDrumming4.mp4";  break;
        case 28:     videoPath = MAIN_VIDEO_DATA_PATH "10_45Side_ButtonTurning2_FireTheKnob1.mp4";  break;
        case 29:     videoPath = MAIN_VIDEO_DATA_PATH "10_45Side_ButtonTurning2_FireTheKnob2.mp4";  break;
        case 30:     videoPath = MAIN_VIDEO_DATA_PATH "10_45Side_ButtonTurning2_FireTheKnob3.mp4";  break;
        case 31:     videoPath = MAIN_VIDEO_DATA_PATH "10_45Side_ButtonTurning2_FireTheKnob4.mp4";  break;
        case 32:     videoPath = MAIN_VIDEO_DATA_PATH "10_45Side_ButtonTurning2_FireTheKnob5.mp4";  break;
        case 33:     videoPath = MAIN_VIDEO_DATA_PATH "10_45Side_ButtonTurning2_FireTheKnob6.mp4";  break;
        case 34:     videoPath = MAIN_VIDEO_DATA_PATH "10_45Side_ButtonTurning2_TwistAndHitHard1.mp4";  break;
        case 35:     videoPath = MAIN_VIDEO_DATA_PATH "10_45Side_ButtonTurning2_TwistAndHitHard2.mp4";  break;
        case 36:     videoPath = MAIN_VIDEO_DATA_PATH "10_45Side_ButtonTurning2_TwistAndHitHard3.mp4";  break;
        case 37:     videoPath = MAIN_VIDEO_DATA_PATH "10_45Side_ButtonTurning2_TwistAndHitHard4.mp4";  break;
        case 38:     videoPath = MAIN_VIDEO_DATA_PATH "10_45Side_ButtonTurning2_TwistTheKnob1.mp4";  break;
        case 39:     videoPath = MAIN_VIDEO_DATA_PATH "10_45Side_ButtonTurning2_TwistTheKnob2.mp4";  break;
        case 40:     videoPath = MAIN_VIDEO_DATA_PATH "10_45Side_ButtonTurning2_TwistTheKnob3.mp4";  break;
        case 41:     videoPath = MAIN_VIDEO_DATA_PATH "11_Front_ButtonTurning_HellYeah1.mp4";  break;
        case 42:     videoPath = MAIN_VIDEO_DATA_PATH "11_Front_ButtonTurning_HellYeah2.mp4";  break;
        case 43:     videoPath = MAIN_VIDEO_DATA_PATH "11_Front_ButtonTurning_HellYeah3.mp4";  break;
        case 44:     videoPath = MAIN_VIDEO_DATA_PATH "11_Front_ButtonTurning_HitOnce1.mp4";  break;
        case 45:     videoPath = MAIN_VIDEO_DATA_PATH "11_Front_ButtonTurning_HitOnce2.mp4";  break;
        case 46:     videoPath = MAIN_VIDEO_DATA_PATH "11_Front_ButtonTurning_HitOnce3.mp4";  break;
        case 47:     videoPath = MAIN_VIDEO_DATA_PATH "11_Front_ButtonTurning_HitOnce4.mp4";  break;
        case 48:     videoPath = MAIN_VIDEO_DATA_PATH "11_Front_ButtonTurning_Jumper1.mp4";  break;
        case 49:     videoPath = MAIN_VIDEO_DATA_PATH "11_Front_ButtonTurning_Jumper2.mp4";  break;
        case 50:     videoPath = MAIN_VIDEO_DATA_PATH "11_Front_ButtonTurning_Jumper3.mp4";  break;
        case 51:     videoPath = MAIN_VIDEO_DATA_PATH "11_Front_ButtonTurning_TurnDatKnobHard1.mp4";  break;
        case 52:     videoPath = MAIN_VIDEO_DATA_PATH "11_Front_ButtonTurning_TurnDatKnobHard2.mp4";  break;
        case 53:     videoPath = MAIN_VIDEO_DATA_PATH "11_Front_ButtonTurning_TurnDatKnobHard3.mp4";  break;
        case 54:     videoPath = MAIN_VIDEO_DATA_PATH "13_Clap_Clap1.mp4";  break;
        case 55:     videoPath = MAIN_VIDEO_DATA_PATH "13_Clap_Clap2.mp4";  break;
        case 56:     videoPath = MAIN_VIDEO_DATA_PATH "13_Clap_Clap3.mp4";  break;
        case 57:     videoPath = MAIN_VIDEO_DATA_PATH "13_Clap_Clap4.mp4";  break;
        case 58:     videoPath = MAIN_VIDEO_DATA_PATH "13_Clap_Clap5.mp4";  break;
        case 59:     videoPath = MAIN_VIDEO_DATA_PATH "13_Clap_Clap6.mp4";  break;
        case 60:     videoPath = MAIN_VIDEO_DATA_PATH "13_Clap_Clap7.mp4";  break;
        case 61:     videoPath = MAIN_VIDEO_DATA_PATH "14_HairEffect_HairEffect1.mp4";  break;
        case 62:     videoPath = MAIN_VIDEO_DATA_PATH "14_HairEffect_HairEffect2.mp4";  break;
        case 63:     videoPath = MAIN_VIDEO_DATA_PATH "15_HeadBanging_HeadBanger1.mp4";  break;
        case 64:     videoPath = MAIN_VIDEO_DATA_PATH "15_HeadBanging_HeadBanger2.mp4";  break;
        case 65:     videoPath = MAIN_VIDEO_DATA_PATH "15_HeadBanging_HeadBanger3.mp4";  break;
        case 66:     videoPath = MAIN_VIDEO_DATA_PATH "15_HeadBanging_HeadBanger4.mp4";  break;
        case 67:     videoPath = MAIN_VIDEO_DATA_PATH "15_HeadBanging_HeadBanger5.mp4";  break;
        case 68:     videoPath = MAIN_VIDEO_DATA_PATH "15_HeadBanging_HeadBanger6.mp4";  break;
        case 69:     videoPath = MAIN_VIDEO_DATA_PATH "15_HeadBanging_HeadBanger7.mp4";  break;
        case 70:     videoPath = MAIN_VIDEO_DATA_PATH "15_HeadBanging_HeadBanger8.mp4";  break;
        case 71:     videoPath = MAIN_VIDEO_DATA_PATH "16_Sadako_RaiseYourHead_RaiseYourHead1.mp4";  break;
        case 72:     videoPath = MAIN_VIDEO_DATA_PATH "16_Sadako_RaiseYourHead_RaiseYourHead2.mp4";  break;
        case 73:     videoPath = MAIN_VIDEO_DATA_PATH "16_Sadako_RaiseYourHead_RaiseYourHead3.mp4";  break;
        case 74:     videoPath = MAIN_VIDEO_DATA_PATH "16_Sadako_RaiseYourHead_RaiseYourHead4.mp4";  break;
        case 75:     videoPath = MAIN_VIDEO_DATA_PATH "17_AllDirections_Sadako_Sadako1.mp4";  break;
        case 76:     videoPath = MAIN_VIDEO_DATA_PATH "17_AllDirections_Sadako_Sadako2.mp4";  break;
        case 77:     videoPath = MAIN_VIDEO_DATA_PATH "17_AllDirections_Sadako_Sadako3.mp4";  break;
            
        default:     videoPath = MAIN_VIDEO_DATA_PATH "00_Blackout.mp4";  break;
    }
    return videoPath;
}

string ofApp::getMainImagePath(int number) {
    string imagePath = "";
    switch (number)
    {
        case 0:
        case 1: imagePath = MAIN_IMAGE_DATA_PATH "void.jpg";             break;
        case 2: imagePath = MAIN_IMAGE_DATA_PATH "calibration.jpg";      break;
        case 3: imagePath = MAIN_IMAGE_DATA_PATH "image2.jpg";           break;
        case 4: imagePath = MAIN_IMAGE_DATA_PATH "image3.jpg";           break;
        case 5: imagePath = MAIN_IMAGE_DATA_PATH "image4.jpg";           break;
        case 6: imagePath = MAIN_IMAGE_DATA_PATH "image5.jpg";           break;
            
        default: imagePath = MAIN_IMAGE_DATA_PATH "void.jpg";            break;
            
    }
    return imagePath;
}

string ofApp::getFxImagePath(int number) {
    string imagePath = "";
    switch (number)
    {
        case 0:
        case 1:  imagePath = FX_IMAGE_DATA_PATH "00.transparent.png";                          break;
        case 2:  imagePath = FX_IMAGE_DATA_PATH "01.blendingUp.png";                           break;
        case 3:  imagePath = FX_IMAGE_DATA_PATH "02.blendingDown.png";                         break;
        case 4:  imagePath = FX_IMAGE_DATA_PATH "03.blendingLeft.png";                         break;
        case 5:  imagePath = FX_IMAGE_DATA_PATH "04.blendingRight.png";                        break;
        case 6:  imagePath = FX_IMAGE_DATA_PATH "05.verticalLine_25_Left.png";                 break;
        case 7:  imagePath = FX_IMAGE_DATA_PATH "06.verticalLine_25_MidLeft.png";              break;
        case 8:  imagePath = FX_IMAGE_DATA_PATH "07.verticalLine_25_MidRight.png";             break;
        case 9:  imagePath = FX_IMAGE_DATA_PATH "08.verticalLine_25_Right.png";                break;
        case 10: imagePath = FX_IMAGE_DATA_PATH "09.verticalLine_75_Left.png";                 break;
        case 11: imagePath = FX_IMAGE_DATA_PATH "10.verticalLine_75_MidLeft.png";              break;
        case 12: imagePath = FX_IMAGE_DATA_PATH "11.verticalLine_75_MidRight.png";             break;
        case 13: imagePath = FX_IMAGE_DATA_PATH "12.verticalLine_75_Right.png";                break;
        case 14: imagePath = FX_IMAGE_DATA_PATH "13.verticalLine_90_Center.png";               break;
        case 15: imagePath = FX_IMAGE_DATA_PATH "14.verticalLine_90_CenterTriple.png";         break;
        case 16: imagePath = FX_IMAGE_DATA_PATH "15.horizontalLine_25_Up.png";                 break;
        case 17: imagePath = FX_IMAGE_DATA_PATH "16.horizontalLine_25_MidUp.png";              break;
        case 18: imagePath = FX_IMAGE_DATA_PATH "17.horizontalLine_25_MidDown.png";            break;
        case 19: imagePath = FX_IMAGE_DATA_PATH "18.horizontalLine_25_Down.png";               break;
        case 20: imagePath = FX_IMAGE_DATA_PATH "19.horizontalLine_75_Up.png";                 break;
        case 21: imagePath = FX_IMAGE_DATA_PATH "20.horizontalLine_75_MidUp.png";              break;
        case 22: imagePath = FX_IMAGE_DATA_PATH "21.horizontalLine_75_MidDown.png";            break;
        case 23: imagePath = FX_IMAGE_DATA_PATH "22.horizontalLine_75_Down.png";               break;
        case 24: imagePath = FX_IMAGE_DATA_PATH "23.horizontalLine_90_Center.png";             break;
        case 25: imagePath = FX_IMAGE_DATA_PATH "24.horizontalLine_90_CenterTriple.png";       break;
            
        default: imagePath = FX_IMAGE_DATA_PATH "00.transparent.png";                          break;
            
    }
    return imagePath;
}

////////////////////////////////////////////

void ofApp::loadVideoInMediaServer(int number) {
    string path = getVideoPath(number);
    piMapper._application.getMediaServer()->loadVideo(path, OF_LOOP_NORMAL);
}

void ofApp::setVideoByNb(int number, ofLoopType loopType) {
    string videoPath = getVideoPath(number);
    setVideoByPath(videoPath, loopType);
}

void ofApp::setImageByNb(int number) {
    string imagePath = getMainImagePath(number);
    setImageByPath(imagePath);
}

void ofApp::setCustomFxByNb(int number) {
    ofx::piMapper::BaseSurface * surface = piMapper._application.getSurfaceManager()->selectSurface(EFFECTS_SURFACE_IDX);
    surface->setSource(piMapper._application.getMediaServer()->loadFboSource(customSource->getName()));
    customSource->loadAnimation(number);
}

void ofApp::setImageFxByNb(int number) {
    string imagePath = getFxImagePath(number);
    setImageFxByPath(imagePath);
}

////////////////////////////////////////////

void ofApp::setVideoByPath(string & path, ofLoopType loopType) {
    
    ofx::piMapper::BaseSurface * surface = piMapper._application.getSurfaceManager()->selectSurface(VIDEO_SURFACE_IDX);
	if(surface == 0){
		ofLogWarning("SourcesEditorWidget") << "No surface selected";
		return;
	}
    
    
    string previousSource;
	// Unload old media
	ofx::piMapper::BaseSource * source = surface->getSource();
	if(source->isLoadable()){
        previousSource = source->getPath();

	}else{
        previousSource = source->getName();
	}
    
    // Load new video
	surface->setSource(piMapper._application.getMediaServer()->loadVideo(path, loopType));
    
    piMapper._application.getMediaServer()->unloadMedia(previousSource);
    
    
}

void ofApp::setImageByPath(string & path) {
    
    ofx::piMapper::BaseSurface * surface = piMapper._application.getSurfaceManager()->selectSurface(VIDEO_SURFACE_IDX);
	if(surface == 0){
		ofLogWarning("SourcesEditorWidget") << "No surface selected";
		return;
	}
    
	// Unload old media
	ofx::piMapper::BaseSource * source = surface->getSource();
	if(source->isLoadable()){
		piMapper._application.getMediaServer()->unloadMedia(source->getPath());
	}else{
		piMapper._application.getMediaServer()->unloadMedia(source->getName());
	}
    
	// Load new image
	surface->setSource(piMapper._application.getMediaServer()->loadImage(path));
}

void ofApp::setImageFxByPath(string & path) {
    
    ofx::piMapper::BaseSurface * surface = piMapper._application.getSurfaceManager()->selectSurface(EFFECTS_SURFACE_IDX);
	if(surface == 0){
		ofLogWarning("SourcesEditorWidget") << "No surface selected";
		return;
	}
    
	// Unload old media
	ofx::piMapper::BaseSource * source = surface->getSource();
	if(source->isLoadable()){
		piMapper._application.getMediaServer()->unloadMedia(source->getPath());
	}else{
		piMapper._application.getMediaServer()->unloadMedia(source->getName());
	}
    
	// Load new image
	surface->setSource(piMapper._application.getMediaServer()->loadImage(path));
}

////////////////////////////////////////////


void ofApp::calibrateSurface(unsigned int vertexElem, unsigned int valLsb, unsigned int valMsb) {
    // The surfaces are made of 4 points -> 8 1-dim coordinates: x1, y1, x2, y2, x3, y3, x4, y4
    //     1:2/3      0:0/1
    //     2:4/5      3:6/7
    int value = ((valMsb << 8) + valLsb);
    float percentagePos = value / (255.0*255.0);
    
    std::vector <int> surfaceIndexes;
    surfaceIndexes.push_back(EFFECTS_SURFACE_IDX);
    surfaceIndexes.push_back(VIDEO_SURFACE_IDX);
    
    for (int surfaceIdx : surfaceIndexes) {
        ofx::piMapper::BaseSurface * surface = piMapper._application.getSurfaceManager()->selectSurface(surfaceIdx);
        vector<ofVec3f> vertices = surface->getVertices();
        
        ofVec3f editedVertex = vertices[vertexElem/2];
        
        int currentValX = editedVertex.x;
        int currentValY = editedVertex.y;
        int currentValZ = editedVertex.z;
        
        // vertexElem % 2 is 0 for X, 1 for Y
        ofVec3f position;
        if (vertexElem % 2 == 0) {      // Edit X
            // Limit the position so that the rectangle's normal stays the right way
            int newValX = int(percentagePos * ofGetWidth());
            switch (vertexElem) {
                case 0: newValX = MAX(vertices[1].x + 5,newValX); break;
                case 2: newValX = MIN(vertices[0].x - 5,newValX); break;
                case 4: newValX = MIN(vertices[3].x - 5,newValX); break;
                case 6: newValX = MAX(vertices[2].x + 5,newValX); break;
                default: break;
            }
            position = ofVec3f(newValX, currentValY, 0);
        }
        else {                          // Edit Y
            int newValY = int(percentagePos * ofGetHeight());
            switch (vertexElem) {
                case 1: newValY = MIN(vertices[3].y - 5,newValY); break;
                case 3: newValY = MIN(vertices[2].y - 5,newValY); break;
                case 5: newValY = MAX(vertices[1].y + 5,newValY); break;
                case 7: newValY = MAX(vertices[0].y + 5,newValY); break;
                default: break;
            }
            position = ofVec3f(currentValX, newValY, 0);
        }
        
        surface->setVertex(vertexElem/2 , position);
    }
}

void ofApp::saveCurrentSettings() {
    piMapper._application.saveProject();
    piMapper._application.setPresentationMode();
}

