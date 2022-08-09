#include "sgll/Graphics/Renderer.h"
#include "sgll/Graphics/StaticShader.h"
#include "sgll/Graphics/Projection.h"

namespace SGLL
{
	void Renderer::init(const std::string& colorVertexShaderPath, const std::string& colorFragmentShaderPath,
		const std::string& textureVertexShaderPath, const std::string& textureFragmentPath)
	{
		StaticShader::init(colorVertexShaderPath, colorFragmentShaderPath, textureVertexShaderPath, textureFragmentPath);

		StaticShader::getColorShader().use();
		SGLL::Projection::init(0.1f, 1000.0f);
		SGLL::Projection::setMatrix();
		StaticShader::getColorShader().setUniformMatrix4f("uProjection", SGLL::Projection::getMatrix());
		StaticShader::getColorShader().unuse();

		StaticShader::getTextureShader().use();
		SGLL::Projection::init(0.1f, 1000.0f);
		SGLL::Projection::setMatrix();
		StaticShader::getTextureShader().setUniformMatrix4f("uProjection", SGLL::Projection::getMatrix());
		StaticShader::getTextureShader().unuse();
	}
}

