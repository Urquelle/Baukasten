#ifndef CAMERA_H_T6GLZWCT
#define CAMERA_H_T6GLZWCT

#include "base.h"
#include "core/Identity"

class Settings;

/*!
 * \brief Camera class declaration.
 */
class Camera : public Identity {
public:
	static shared_ptr<Camera> create();
	static shared_ptr<Camera> create(const float, const float, const float,
			const float, const float, const float, const vec3);

	// TODO implement settings class
	void init(Settings*);

	float fieldOfView() const;
	void setFieldOfView(const float);

	float aspectRatio() const;
	void setAspectRatio(const float);

	mat4 matrix() const;

	void pan(const float, const float);
	mat4 orientation() const;

	void setPosition(const vec3);
	vec3 position() const;
	void move(const vec3);

	vec3 left() const;
	vec3 right() const;

	vec3 forward() const;
	vec3 back() const;

	vec3 up() const;
	vec3 down() const;

	virtual ~Camera();

private:
	Camera();
	Camera(const float, const float, const float,
			const float, const float, const float, const vec3);

	BK_PIMPL(Camera);
};

#endif /* end of include guard: CAMERA_H_T6GLZWCT */
