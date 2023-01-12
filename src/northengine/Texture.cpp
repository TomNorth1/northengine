#include "Texture.h"

namespace northengine
{
	void Texture::onLoad()
	{
		m_texture = new rend::Texture(getPath());
	}
	sys::Ptr<rend::Texture> Texture::getTexture()
	{
		return m_texture;
	}
}

