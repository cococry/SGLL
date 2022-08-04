#pragma once

#include <string>

namespace SGLL
{
	class Texture
	{
	public:
		Texture() = default;

		Texture(const std::string& filepath, bool flipped = true);

		~Texture();

		void init(const std::string& filepath, bool flipped = true);

		void bind();

		void unbind();

		void activateSlot(unsigned int slot = 0);
		
		void deleteID();

		unsigned int getID() const
		{
			return mID;
		}

		int getWidth() const
		{
			return mWidth;
		}

		int getHeight() const
		{
			return mHeight;
		}

		int getNumberOfChannels() const
		{
			return mNumberChannels;
		}
	private:

		unsigned int mID;

		int mWidth, mHeight, mNumberChannels;
	};
}