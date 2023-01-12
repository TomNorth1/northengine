#include "Resource.h"
#include "rend/rend.h"
#include "rend/sys/Ptr.h"

namespace northengine 
{
	struct Model : Resource
	{
		void onLoad();
		sys::Ptr<rend::Model> getModel();
	private:
		sys::Ptr<rend::Model> m_model;
	};
}