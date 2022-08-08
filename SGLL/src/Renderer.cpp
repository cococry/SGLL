#include "Graphics/Renderer.h"

#include "Graphics/StaticShader.h"
#include "Graphics/Projection.h"

namespace SGLL
{
	void Renderer::init()
	{
		StaticShader::init();
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

