#include "Component.h"

#include <string>

#include <rend/rend.h>
#include <rend/sys/String.h>
#include <memory>

#include "Texture.h"
#include "Model.h"

namespace northengine
{
	/**
	* Component responsible for renderering a mesh to screen
	*/
	struct MeshRenderer : Component
	{
		/**
		* default constructor
		*/
		MeshRenderer();
		/**
		* Loads texture and model resource from the resource manager
		* 
		* \param _texPath path to the desired texture file
		*
		* \param _modPath path to the desired model file
		*/
		void setResources(const sys::String _texPath, const sys::String _modPath);
	private:
		rend::Mesh m_mesh;
		std::shared_ptr<Model> m_model; ///< model resource
		rend::Shader m_shader;///< shader to use
		std::shared_ptr<Texture> m_texture;///< texture resource

		sys::String texPath;
		sys::String modPath;

		/**
		* displays the model to the screen
		*/
		void onDisplay();
	};
}