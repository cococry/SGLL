#include "Shader.h"

#include "FileUtil.h"

#include <glm/gtc/type_ptr.hpp>

#include "Logging.h"

namespace SGLL
{
	Shader::Shader(const std::string& vertexShaderFile, const std::string& fragmentShaderFile, const std::string& geometryShaderFile)
	{
		init(vertexShaderFile, fragmentShaderFile, geometryShaderFile);
	}
	Shader::~Shader()
	{

	}
	void Shader::init(const std::string& vertexShaderFile, const std::string& fragmentShaderFile, const std::string& geometryShaderFile)
	{
		unsigned int vertexShader = compileShader(GL_VERTEX_SHADER, vertexShaderFile);
		unsigned int fragmentShader = compileShader(GL_FRAGMENT_SHADER, fragmentShaderFile);

		if (geometryShaderFile != "")
		{
			unsigned int geometryShader = compileShader(GL_GEOMETRY_SHADER, geometryShaderFile);
			linkShaderProgram(vertexShader, fragmentShader, geometryShader);
		}

		linkShaderProgram(vertexShader, fragmentShader);
	}
	void Shader::use()
	{
		glUseProgram(mID);
	}
	void Shader::unuse()
	{
		glUseProgram(0);
	}
	void Shader::deleteID()
	{
		glDeleteShader(mID);
	}
	void Shader::setUniformMatrix4f(const std::string& shaderVariableName, const glm::mat4& uniformValue)
	{
		glUniformMatrix4fv(getUniformLocation(shaderVariableName), 1, false, glm::value_ptr(uniformValue));
	}
	void Shader::setUniformMatrix3f(const std::string& shaderVariableName, const glm::mat3& uniformValue)
	{
		glUniformMatrix3fv(getUniformLocation(shaderVariableName), 1, false, glm::value_ptr(uniformValue));
	}
	void Shader::setUniformMatrix2f(const std::string& shaderVariableName, const glm::mat2& uniformValue)
	{
		glUniformMatrix2fv(getUniformLocation(shaderVariableName), 1, false, glm::value_ptr(uniformValue));
	}
	void Shader::setUniformVector4f(const std::string& shaderVariableName, const glm::vec4& uniformValue)
	{
		glUniform4fv(getUniformLocation(shaderVariableName), 1, glm::value_ptr(uniformValue));
	}
	void Shader::setUniformVector3f(const std::string& shaderVariableName, const glm::vec3& uniformValue)
	{
		glUniform3fv(getUniformLocation(shaderVariableName), 1, glm::value_ptr(uniformValue));
	}
	void Shader::setUniformVector2f(const std::string& shaderVariableName, const glm::vec2& uniformValue)
	{
		glUniform2fv(getUniformLocation(shaderVariableName), 1, glm::value_ptr(uniformValue));
	}
	void Shader::setUniformFloat(const std::string& shaderVariableName, float uniformValue)
	{
		glUniform1f(getUniformLocation(shaderVariableName), uniformValue);
	}
	void Shader::setUniformInt(const std::string& shaderVariableName, int uniformValue)
	{
		glUniform1i(getUniformLocation(shaderVariableName), uniformValue);
	}
	int Shader::getUniformLocation(const std::string& shaderVariableName)
	{
		return glGetUniformLocation(mID, shaderVariableName.c_str());
	}
	unsigned int Shader::compileShader(GLenum type, const std::string& shaderFilepath)
	{
		unsigned int shader;

		int success;
		char infoLog[512];

		shader = glCreateShader(type);

		std::string shaderSource = FileUtil::getFileContents(shaderFilepath);
		const char* shaderSourceCSTR = shaderSource.c_str();

		glShaderSource(shader, 1, &shaderSourceCSTR, nullptr);
		glCompileShader(shader);

		glGetShaderiv(shader, GL_COMPILE_STATUS, &success);

		if (!success)
		{
			glGetShaderInfoLog(shader, 512, nullptr, infoLog);
			std::string shaderType = "";

			switch (type)
			{
			case GL_VERTEX_SHADER:
				shaderType = "vertex";
				break;
			case GL_FRAGMENT_SHADER:
				shaderType = "fragment";
				break;
			case GL_GEOMETRY_SHADER:
				shaderType = "geometry";
				break;
			default:
				shaderType = "unknown type";
				break;
			}

			SGLL_INTERNAL_ERROR("Failed to compile {0} shader.", shaderType);

			SGLL_INTERNAL_TRACE("{0}", infoLog);
		}

		return shader;
	}
	void Shader::linkShaderProgram(unsigned int vertexShader, unsigned int fragmentShader, int geometryShader)
	{
		int success;
		char infoLog[512];

		mID = glCreateProgram();

		glAttachShader(mID, vertexShader);
		glAttachShader(mID, fragmentShader);

		if (geometryShader != -1)
		{
			glAttachShader(mID, geometryShader);
		}

		glLinkProgram(mID);

		glGetProgramiv(mID, GL_LINK_STATUS, &success);

		if (!success)
		{
			glGetProgramInfoLog(mID, 512, nullptr, infoLog);
			SGLL_INTERNAL_ERROR("Failed to linke shader program.");
			SGLL_INTERNAL_TRACE("{0}", infoLog);
		}

		glDeleteShader(vertexShader);
		glDeleteShader(fragmentShader);

		if (geometryShader != -1)
		{
			glDeleteShader(geometryShader);
		}
	}
}

