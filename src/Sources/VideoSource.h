#pragma once

#include "ofMain.h"
#include "BaseSource.h"

#ifdef TARGET_RASPBERRY_PI
 #include "ofxOMXPlayer.h"
 #include "OMXPlayerCache.h"
#endif

namespace ofx {
namespace piMapper {

class VideoSource : public BaseSource {

	public:

		// TODO: Create enableAudio() and disableAudio() methods
		//       for live audio enabling and disabling.
		static bool enableAudio;
		static bool useHDMIForAudio;

		VideoSource();
		~VideoSource();

		string & getPath();
		void loadVideo(string & path, ofLoopType loopType);
		void clear();
        void togglePause();
        void restartVideo(string & filePath);

		#ifndef TARGET_RASPBERRY_PI
			void update(ofEventArgs & args);
		#endif

	private:

		#ifdef TARGET_RASPBERRY_PI
			ofxOMXPlayer * omxPlayer;     // Naming different for less confusion
		#else
			// Go with ofVideoPlayer or
			// TODO: High Performance Video player on newer Macs
			ofVideoPlayer * videoPlayer;
			bool _initialVolumeSet;
		#endif

};

} // namespace piMapper
} // namespace ofx