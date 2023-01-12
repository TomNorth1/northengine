#include "Component.h"

#include <rend/rend.h>

namespace northengine 
{
	struct TriangleRenderer : Component 
	{
		TriangleRenderer();
	private:
		rend::Mesh m_mesh;
		rend::Shader m_shader;

		void onDisplay();
	};
}