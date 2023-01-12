#include "AudioClip.h"

#include "stb_vorbis.c"
#include <stdexcept>

namespace northengine
{
	void AudioClip::onLoad()
	{
		load_ogg(getPath(), bufferData, format, freq);
	}
	void AudioClip::load_ogg(const sys::String& _path, std::vector<unsigned char>& _buffer, ALenum& _format, ALsizei& _freq)
	{
		int channels = 0;
		int sampleRate = 0;
		short* output = NULL;

		size_t samples = stb_vorbis_decode_filename(_path.unsafe_raw(),
			&channels, &sampleRate, &output);

		if (samples == -1)
		{
			throw std::runtime_error("Failed to open file audio file for decoding");
		}

		// Record the format required by OpenAL
		if (channels < 2)
		{
			_format = AL_FORMAT_MONO16;
		}
		else
		{
			_format = AL_FORMAT_STEREO16;
		}

		// Copy (# samples) * (1 or 2 channels) * (16 bits == 2 bytes == short)
		_buffer.resize(samples * channels * sizeof(short));
		memcpy(&_buffer.at(0), output, _buffer.size());

		// Record the sample rate required by OpenAL
		_freq = sampleRate;

		// Clean up the read data
		free(output);
	}
	ALenum AudioClip::getFormat()
	{
		return format;
	}
	ALsizei AudioClip::getFreq()
	{
		return freq;
	}
	std::vector<unsigned char> AudioClip::getBufferData()
	{
		return bufferData;
	}
}
