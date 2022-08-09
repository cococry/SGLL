#include "sgll/Graphics/StaticShader.h"


SGLL::Shader SGLL::StaticShader::sColorShader;
SGLL::Shader SGLL::StaticShader::sTextureShader;

namespace SGLL
{
	void StaticShader::init(const std::string& colorVertexPath, const std::string& colorFragmentPath,
		const std::string& textureVertexPath, const std::string& textureFragmentPath)
	{
		sColorShader = Shader(colorVertexPath, colorFragmentPath);
		sTextureShader = Shader(textureVertexPath, textureFragmentPath);
	}
}