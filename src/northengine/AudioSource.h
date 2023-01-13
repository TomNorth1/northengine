#include "Component.h"
#include <vector>
#include <string>
#include <AL/al.h>
#include <AL/alc.h>
#include <memory>

namespace northengine
{
	struct AudioClip;
	struct AudioSource : Component 
	{
		AudioSource();

		void setAudioClip(std::shared_ptr<AudioClip> _audioClip);

		void play();
		void onTick();

		//std::shared_ptr<AudioClip> m_audioClip;
	private:
		ALuint sourceId;
		ALenum format;
		ALsizei freq;
		std::vector<unsigned char> bufferData;
	};
}