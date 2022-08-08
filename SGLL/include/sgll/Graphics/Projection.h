#pragma once

#include <glm/glm.hpp>

namespace SGLL
{
	class Projection
	{
	public:
		static void init(float nearPlane, float farPlane);

		static void setMatrix();

		static float getNearPlane() 
		{
			return sNearPlane;
		}

		static float getFarPlane() 
		{
			return sFarPlane;
		}

		static const glm::mat4& getMatrix()
		{
			return sMatrix;
		}
	private:
		static float sNearPlane, sFarPlane;

		static glm::mat4 sMatrix;
	};
}
