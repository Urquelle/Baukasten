#include "graphics/Context"

#include <map>

#include "graphics/Camera"

namespace bk {

class ContextPrivate {
public:
	ContextPrivate() :
		m_enable3d(true)
	{
	}

	~ContextPrivate()
	{
	}

	void setOption(ContextOption option, bool value)
	{
		switch( option ) {
		case ContextOption::ENABLE_3D:
			m_enable3d = value;
			break;
		}
	}

	void addCamera(Camera* cam, bool setActive)
	{
		m_cams[cam->id()] = cam;
		if (setActive)
			m_activeCam = cam;
	}

	void setActiveCamera(const int id)
	{
		m_activeCam = m_cams[id];
	}

	Camera* camera() const
	{
		return m_activeCam;
	}

private:
	bool m_enable3d;
	map<int, Camera*> m_cams;
	Camera* m_activeCam;
};

Context::Context() :
	m_impl(new ContextPrivate())
{
}

Context::~Context()
{
	delete m_impl;
}

Context*
Context::create()
{
	return new Context();
}

void
Context::setOption(const ContextOption option, bool value)
{
	m_impl->setOption(option, value);
}

void
Context::addCamera(Camera* cam, bool setActive)
{
	m_impl->addCamera(cam, setActive);
}

void
Context::setActiveCamera(const int id)
{
	m_impl->setActiveCamera(id);
}

Camera*
Context::camera() const
{
	return m_impl->camera();
}

} /* bk */
