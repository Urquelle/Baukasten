#ifndef BASE_H_FIQRYC3F
#define BASE_H_FIQRYC3F

#define GLEW_STATIC
#include <GL/glew.h>
#include <GL/gl.h>
#include <GL/glfw.h>
#include <cassert>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <iostream>
#include <list>
#include <sstream>
#include <string>
#include <vector>

using namespace std;
using namespace glm;

class IShader;
typedef vector<IShader*> ShaderList;

class Vertex;
typedef vector<Vertex*> Vertices;

#include "debug.h"

#endif /* end of include guard: BASE_H_FIQRYC3F */

