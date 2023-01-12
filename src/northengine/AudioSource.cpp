#include "AudioSource.h"
#include "AudioClip.h"
#include "rend/rend.h"
#include "Entity.h"
#include "Transform.h"

namespace northengine
{
	AudioSource::AudioSource() 
	{
		format = 0;
		freq = 0;
		sourceId = 0;
	}
	void AudioSource::setAudioClip(std::shared_ptr<AudioClip> _audioClip)
	{
		format = _audioClip->getFormat();
		freq = _audioClip->getFreq();
		bufferData = _audioClip->getBufferData();

		ALuint bufferId = 0;
		alGenBuffers(1, &bufferId);

		alBufferData(bufferId, format, &bufferData.at(0),
			static_cast<ALsizei>(bufferData.size()), freq);

		/*************************************************************************
		 * Preparing sound source
		 *************************************************************************/
		alGenSources(1, &sourceId);

		rend::vec3 sourcePos = getEntity()->getTransform()->getPosition();

		alSourcei(sourceId, AL_BUFFER, bufferId);
		alSource3f(sourceId, AL_POSITION, sourcePos.x, sourcePos.y, sourcePos.z);
		//alSourcef(sourceId, AL_PITCH, 10);
		alSourcef(sourceId, AL_GAIN, 0.1);

	}
	void AudioSource::play()
	{
		alSourcePlay(sourceId);
	}
}