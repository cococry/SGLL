#include "Graphics/Projection.h"

#include <glm/gtc/matrix_transform.hpp>

#include "Display.h"

#include "Logging.h"

float SGLL::Projection::sFarPlane;
float SGLL::Projection::sNearPlane;
glm::mat4 SGLL::Projection::sMatrix;

namespace SGLL
{
	void Projection::init(float nearPlane, float farPlane)
	{
		sNearPlane = nearPlane;
		sFarPlane = farPlane;
	}
	void Projection::setMatrix()
	{
		sMatrix = glm::perspective(45.0f, (float)((float)Display::getWidth() / (float)Display::getHeight()), sNearPlane, sFarPlane);
	}
}
