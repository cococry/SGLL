#pragma once

#include "RenderablePrimitiv.h"

namespace SGLL
{
	class Triangle : public RenderablePrimitiv
	{
	public:
		Triangle(const glm::vec3& position, const glm::vec3& scale, const glm::vec3& color, const glm::vec3& rotation = glm::vec3(0.0f, 0.0f, 0.0f));

		virtual void render() override;

	private:

	};
} 