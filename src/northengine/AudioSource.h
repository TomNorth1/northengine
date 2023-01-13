#include "Component.h"
#include <vector>
#include <string>
#include <AL/al.h>
#include <AL/alc.h>
#include <memory>

namespace northengine
{
	struct AudioClip;
	/**
	* Component responsible for playing audio
	*/
	struct AudioSource : Component 
	{
		/**
		* default constructor
		*/
		AudioSource();

		/**
		* load audio clip resource 
		* 
		* \param Audio clip resource
		*/
		void setAudioClip(std::shared_ptr<AudioClip> _audioClip);

		/**
		* plays audio clip
		* 
		*/
		void play();

		/**
		* updates position of audio source
		*/
		void onTick();

		//std::shared_ptr<AudioClip> m_audioClip;
	private:
		ALuint sourceId;///< source id
		ALenum format;///< format of audio clip
		ALsizei freq;///< frequency of audio buffer
		std::vector<unsigned char> bufferData;///< data from audio clip
	};
}