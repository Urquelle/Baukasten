#include "graphics/Scene"

#include "graphics/Camera"
#include "graphics/Model"

Scene::Scene(shared_ptr<Camera>& cam) :
	m_cams({cam}), m_activeCam(cam)
{
}

Scene::~Scene()
{
}

shared_ptr<Scene>
Scene::create(shared_ptr<Camera>& cam)
{
	return shared_ptr<Scene>(new Scene(cam));
}

void Scene::render(const int time)
{
	BK_GL_ASSERT(glClearColor(0, 0, 0, 1));
	BK_GL_ASSERT(glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT));
	for ( auto m: m_models ) {
		m->render(*m_activeCam, time);
	}
	BK_GL_ASSERT(glfwSwapBuffers());
}

shared_ptr<Camera>
Scene::activeCamera() const
{
	return m_activeCam;
}

void
Scene::setActiveCamera(const int id)
{
	for ( auto c: m_cams ) {
		if (c->id() == id) {
			BK_DEBUG("set active cam to: " << id);
			m_activeCam = c;
		}
	}
}

void
Scene::addModel(shared_ptr<Model>& model)
{
	m_models.push_back(model);
}

void
Scene::addCamera(shared_ptr<Camera>& cam, bool makeActive)
{
	m_cams.push_back(cam);
	if (makeActive) {
		m_activeCam = cam;
	}
}