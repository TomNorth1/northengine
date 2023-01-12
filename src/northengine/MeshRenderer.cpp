#include "MeshRenderer.h"
#include "Entity.h"
#include "Transform.h"
#include "Core.h"
#include "Resources.h"
#include <iostream>

namespace northengine
{
	MeshRenderer::MeshRenderer() : m_shader("data/shaders/basic.vert", "data/shaders/basic.frag")
	{
		sys::String texPath = "data/textures/Whiskers_diffuse.png";
		sys::String modPath = "data/models/curuthers.obj";
	}
	void MeshRenderer::init(const sys::String _texPath,  const sys::String _modPath)
	{

		if (!getEntity()->getCore()->getResources()->load<Texture>(_texPath))
		{
			std::cout << "Invalid texture path!";
			getEntity()->getCore()->getResources()->load<Texture>(texPath);

		}
		m_texture = getEntity()->getCore()->getResources()->load<Texture>(_texPath);

		if (!getEntity()->getCore()->getResources()->load<Model>(_modPath))
		{
			getEntity()->getCore()->getResources()->load<Model>(modPath);
			std::cout << "Invalid model path!";
		}
		m_model = getEntity()->getCore()->getResources()->load<Model>(_modPath);

	}

	void northengine::MeshRenderer::onDisplay()
	{
		rend::ModelRenderer r(1280, 720);
		r.mesh(m_model->getModel());
		r.model(getEntity()->getTransform()->getModel());
		r.shader(&m_shader);

		r.texture(m_texture->getTexture());
		r.depthTest(true);

		r.projection(rend::perspective(rend::radians(45.0f), (float)1280/720, 0.1f, 100.f));

		r.render();
	}
}