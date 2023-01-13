#ifndef NORTHENGINE_RESOURCE_H
#define NORTHENGINE_RESOURCE_H

#include "rend/sys/String.h"

/**
* Base class for all resources the game need
*/
namespace northengine 
{
	struct Resources;
	struct Resource 
	{
		/**
		* event is called when resource is loaded in to the resource manager
		*/
		virtual void onLoad() = 0;
		
		/**
		* returns path to resource
		* 
		* \return path string
		*/
		sys::String getPath();

	private:
		friend Resources;
		sys::String m_path;
		void load();
	};

}
#endif