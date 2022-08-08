#include "Graphics/Primitves/TexturedQuad.h"
#include "Graphics/StaticShader.h"

#include <glm/gtc/matrix_transform.hpp>

#include "DeltaTime.h"
#include "Graphics/ModelLoader.h"

namespace SGLL
{
	TexturedQuad::TexturedQuad(const glm::vec3& position, const glm::vec3& scale, const std::string& texturePath, const glm::vec3& color, const glm::vec3& rotation)
		: RenderablePrimitiv(position, scale, color, rotation, {
			-0.5f, -0.5f, 0.0f,
			-0.5f,  0.5f, 0.0f,
			 0.5f,  0.5f, 0.0f,
			 0.5f, -0.5f, 0.0f
			}, 
			{
				0, 1, 2,
				2, 3, 0
			}, false)
	{

		std::vector<float> uvs = {
			0.0f, 0.0f,
			0.0f, 1.0f,
			1.0f, 1.0f,
			1.0f, 0.0f
		};
	
		mModel = SGLL::ModelLoader::loadModel(mVertexPositions, uvs, mIndices);


		mTexture = std::make_shared<SGLL::Texture>(texturePath);

		SGLL::StaticShader::getTextureShader().use();
		SGLL::StaticShader::getTextureShader().setUniformInt("uTexture", 0);
		SGLL::StaticShader::getTextureShader().setUniformVector3f("uColor", color);

	}

	void TexturedQuad::render()
	{
		mTexture->bind();
		mTexture->activateSlot();

		glm::mat4 modelMatrix = glm::mat4(1.0f);
		modelMatrix = glm::scale(glm::mat4(1.0f), glm::vec3(1.0f)) *
			glm::rotate(glm::mat4(1.0f), glm::radians(Rotation.x), glm::vec3(1.0f, 0.0f, 0.0f)) * 
			glm::rotate(glm::mat4(1.0f), glm::radians(Rotation.y), glm::vec3(0.0f, 1.0f, 0.0f)) * 
			glm::rotate(glm::mat4(1.0f), glm::radians(Rotation.z), glm::vec3(0.0f, 0.0f, 1.0f)) * 
			glm::translate(glm::mat4(1.0f), Position);

		SGLL::StaticShader::getTextureShader().setUniformMatrix4f("uModel", modelMatrix);

		glDrawElements(GL_TRIANGLES, mModel.getVertexCount(), GL_UNSIGNED_INT, nullptr);
	}

	
}
