#pragma once

#include <string>

#include <glm/glm.hpp>

#include <glad/glad.h>

namespace SGLL
{
	class Shader
	{
	public:
		Shader() = default;

		Shader(const std::string& vertexShaderFile, const std::string& fragmentShaderFile, const std::string& geometryShaderFile = "");

		~Shader();

		void init(const std::string& vertexShaderFile, const std::string& fragmentShaderFile, const std::string& geometryShaderFile = "");

		void use();

		void unuse();

		void deleteID();

		void setUniformMatrix4f(const std::string& shaderVariableName, const glm::mat4& uniformValue);

		void setUniformMatrix3f(const std::string& shaderVariableName, const glm::mat3& uniformValue);

		void setUniformMatrix2f(const std::string& shaderVariableName, const glm::mat2& uniformValue);

		void setUniformVector4f(const std::string& shaderVariableName, const glm::vec4& uniformValue);

		void setUniformVector3f(const std::string& shaderVariableName, const glm::vec3& uniformValue);

		void setUniformVector2f(const std::string& shaderVariableName, const glm::vec2& uniformValue);

		void setUniformFloat(const std::string& shaderVariableName, float uniformValue);

		void setUniformInt(const std::string& shaderVariableName, int uniformValue);

		int getUniformLocation(const std::string& shaderVariableName);

		unsigned int getID() const
		{
			return mID;
		}

	private:
		unsigned int compileShader(GLenum type, const std::string& shaderFilepath);

		void linkShaderProgram(unsigned int vertexShader, unsigned int fragmentShader, int geometryShader = -1);

		unsigned int mID;
	};
}