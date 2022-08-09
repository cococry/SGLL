#include "sgll/Graphics/Primitves/Triangle.h"
#include "sgll/Graphics/StaticShader.h"

#include <glm/gtc/matrix_transform.hpp>

#include "sgll/DeltaTime.h"
#include "sgll/Graphics/ModelLoader.h"


namespace SGLL
{
	Triangle::Triangle(const glm::vec3& position, const glm::vec3& scale, const glm::vec3& color, const glm::vec3& rotation)
		: RenderablePrimitiv(position, scale, color, rotation, {
		   -0.5f, -0.5f, 0.0f,
		   -0.5f,  0.5f, 0.0f,
			0.5f,  0.5f, 0.0f,
			}, { 0, 1, 2 })
	{
		StaticShader::getColorShader().use();
		StaticShader::getColorShader().setUniformVector3f("uColor", color);
	}

	void Triangle::render()
	{
		StaticShader::getColorShader().use();

		glm::mat4 modelMatrix = glm::mat4(1.0f);
		modelMatrix = glm::scale(glm::mat4(1.0f), Scale) *
			glm::rotate(glm::mat4(1.0f), glm::radians(Rotation.x), glm::vec3(1.0f, 0.0f, 0.0f)) *
			glm::rotate(glm::mat4(1.0f), glm::radians(Rotation.y), glm::vec3(0.0f, 1.0f, 0.0f)) *
			glm::rotate(glm::mat4(1.0f), glm::radians(Rotation.z), glm::vec3(0.0f, 0.0f, 1.0f)) * 
			glm::translate(glm::mat4(1.0f), Position);

		StaticShader::getColorShader().setUniformMatrix4f("uModel", modelMatrix);

		glDrawElements(GL_TRIANGLES, mModel.getVertexCount(), GL_UNSIGNED_INT, nullptr);

		StaticShader::getColorShader().unuse();

	}

}
