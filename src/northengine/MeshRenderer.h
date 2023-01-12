#include "Component.h"

#include <string>

#include <rend/rend.h>
#include <rend/sys/String.h>
#include <memory>

#include "Texture.h"
#include "Model.h"

namespace northengine
{
	struct MeshRenderer : Component
	{
		MeshRenderer();
		void init(const sys::String _texPath, const sys::String _modPath);
	private:
		rend::Mesh m_mesh;
		std::shared_ptr<Model> m_model;
		rend::Shader m_shader;
		std::shared_ptr<Texture> m_texture;

		sys::String texPath;
		sys::String modPath;


		void onDisplay();
	};
}