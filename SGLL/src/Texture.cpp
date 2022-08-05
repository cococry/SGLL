#include "Texture.h"

#include <glad/glad.h>
#include <stb_image/stb_image.h>

#include "Logging.h"

namespace SGLL
{
	Texture::Texture(const std::string& filepath, bool flipped, GLenum minFilter, GLenum magFilter)
	{
		init(filepath, flipped);
	}
	Texture::~Texture()
	{
		glDeleteTextures(1, &mID);
	}
	void Texture::init(const std::string& filepath, bool flipped, GLenum minFilter, GLenum magFilter)
	{

		glGenTextures(GL_TEXTURE_2D, &mID);
		glBindTexture(GL_TEXTURE_2D, mID);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, magFilter);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, minFilter);

		stbi_set_flip_vertically_on_load(flipped);

		unsigned char* data = stbi_load(filepath.c_str(), &mWidth, &mHeight, &mNumberChannels, 0);

		GLenum internalFormat = GL_RGB;
		GLenum format = GL_RGB;

		if (mNumberChannels == 4) {
			internalFormat = GL_RGBA;
			format = GL_RGBA;
		}

		if (data) {
			glTexImage2D(GL_TEXTURE_2D, 0, internalFormat, mWidth, mHeight, 0, format, GL_UNSIGNED_BYTE, data);
			glGenerateMipmap(GL_TEXTURE_2D);

		}
		else {
			SGLL_INTERNAL_CRITICAL("Failed to load texture file at location '{0}'.", filepath);
		}

		stbi_image_free(data);

	}
	void Texture::bind()
	{
		glBindTexture(GL_TEXTURE_2D, mID);
	}
	void Texture::unbind()
	{
		glBindTexture(GL_TEXTURE_2D, 0);
	}
	void Texture::activateSlot(unsigned int slot)
	{
		glActiveTexture(GL_TEXTURE0 + slot);
	}
	void Texture::deleteID()
	{
		glDeleteTextures(1, &mID);
	}
}