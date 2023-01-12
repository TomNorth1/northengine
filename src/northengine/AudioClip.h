#include "Resource.h"
#include <AL/al.h>
#include <AL/alc.h>
#include <vector>
#include "rend/sys/String.h"

namespace northengine 
{
	struct AudioClip : Resource
	{
		void onLoad();
		void load_ogg(const sys::String& _path, std::vector<unsigned char>& _buffer,
			ALenum& _format, ALsizei& _freq);

		ALenum getFormat();
		ALsizei getFreq();
		std::vector<unsigned char> getBufferData();
	private:
		ALenum format;
		ALsizei freq;
		std::vector<unsigned char> bufferData;
	};

}