#include "Model.h"
namespace northengine 
{
	void Model::onLoad()
	{
		m_model = new rend::Model(getPath());
	}
	sys::Ptr<rend::Model> Model::getModel()
	{
		return m_model;
	}
}

