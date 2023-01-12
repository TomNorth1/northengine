#include "Resource.h"
#include "rend/rend.h"
#include "rend/sys/Ptr.h"
namespace northengine 
{
	struct Texture : Resource
	{
		void onLoad();
		sys::Ptr<rend::Texture> getTexture();
	private:
		sys::Ptr<rend::Texture> m_texture;
	};
}