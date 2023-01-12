#include "Resource.h"

namespace northengine
{
	sys::String Resource::getPath()
	{
		return m_path;
	}

	void Resource::load()
	{
		onLoad();
	}
}


