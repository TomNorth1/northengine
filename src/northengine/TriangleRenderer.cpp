#include "TriangleRenderer.h"
#include "Entity.h"
#include "Transform.h"

namespace northengine 
{
	TriangleRenderer::TriangleRenderer() : m_shader("data/shaders/basic.vert", "data/shaders/basic.frag")
	{
		m_mesh.loadTriangle();
	}

	void TriangleRenderer::onDisplay() 
	{
		rend::Renderer r(640, 480);

		r.shader(&m_shader);
		r.mesh(&m_mesh);

		r.projection(rend::perspective(rend::radians(45.0f), 1.0f, 0.1f, 100.f));
		r.model(getEntity()->getTransform()->getModel());

		r.render();
	}
}