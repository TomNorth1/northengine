#ifndef NORTHENGINE_RESOURCE_H
#define NORTHENGINE_RESOURCE_H

#include "rend/sys/String.h"

namespace northengine 
{
	struct Resources;
	struct Resource 
	{
		virtual void onLoad() = 0;

		sys::String getPath();

	private:
		friend Resources;
		sys::String m_path;
		void load();
	};

}
#endif