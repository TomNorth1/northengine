#include <memory>
#include "rend/sys/String.h"
#include <vector>


namespace northengine
{
	struct Resource;
	struct Resources 
	{
		template <typename T>
		std::shared_ptr<T> load(const sys::String& _path) 
		{
			for (size_t i = 0; i < m_resources.size(); ++i)
			{
				// Return it if found
				if (m_resources.at(i)->getPath() == _path)
				{
					std::shared_ptr<Resource> r = m_resources.at(i);

					std::shared_ptr<T> t = std::dynamic_pointer_cast<T>(r);
					if (t) 
					{
						return t;
					}
					
				}
			}

			// Create new instance, construct it and add to cache
			std::shared_ptr<T> rtn = std::make_shared<T>();
			rtn->m_path = _path;

			m_resources.push_back(rtn);
			rtn->load();
			
			return rtn;

		}
	private:
		friend Resource;
		std::vector < std::shared_ptr<Resource>> m_resources;
	};
}