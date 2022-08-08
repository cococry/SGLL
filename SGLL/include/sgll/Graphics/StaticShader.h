#pragma once

#include "Shader.h"

namespace SGLL
{
	class StaticShader
	{
	public:
		static void init(const std::string& colorVertexPath = "../SGLL/assets/shaders/ColorVertex.glsl", const std::string& colorFragmentPath = "../SGLL/assets/shaders/ColorFragment.glsl",
			const std::string& textureVertexPath = "../SGLL/assets/shaders/TextureVertex.glsl", const std::string& textureFragmentPath = "../SGLL/assets/shaders/TextureFragment.glsl");

		static Shader getTextureShader()
		{
			return sTextureShader;
		}

		static Shader getColorShader()
		{
			return sColorShader;
		}

	private:
		static Shader sTextureShader;

		static Shader sColorShader;
	};
}