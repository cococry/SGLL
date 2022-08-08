#pragma once

#include "RenderablePrimitiv.h"
#include "../Texture.h"
#include "../Shader.h"
#include "../RawModel.h"
#include <memory>

namespace SGLL
{
	class TexturedTriangle : public RenderablePrimitiv
	{
	public:
		TexturedTriangle(const glm::vec3& position, const glm::vec3& scale, const std::string& texturePath, const glm::vec3& color = glm::vec3(1.0f, 1.0f, 1.0f), const glm::vec3& rotation = glm::vec3(0.0f, 0.0f, 0.0f));

		virtual void render() override;
	private:
		std::shared_ptr<Texture> mTexture;

	};
}