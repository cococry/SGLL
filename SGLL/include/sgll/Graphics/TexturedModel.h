#pragma once

#include "Texture.h"
#include "RawModel.h"

namespace SGLL
{
	class TexturedModel
	{
	public:
		TexturedModel(RawModel model, Texture texture);

		RawModel getModel() const
		{
			return mModel;
		}

		Texture getTexture() const
		{
			return mTexture;
		}
	private:
		RawModel mModel;
		Texture mTexture;
	};
}