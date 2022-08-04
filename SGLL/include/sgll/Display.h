#pragma once

#include <string>

#include <GLFW/glfw3.h>

struct GLBitmask;

namespace SGLL
{
	class Display
	{
	public:
		Display() = default;

		Display(unsigned int width, unsigned int height, const std::string& title,
			bool rezisable = true, bool startFullScreen = false, bool vsync = true);

		~Display();

		void swapBuffers();

		void init(unsigned int width, unsigned int height, const std::string& title,
			bool rezisable = true, bool startFullScreen = false, bool vsync = true);

		void destory();

		unsigned int getWidth() const
		{
			return mWidth;
		}

		unsigned int getHeight() const
		{
			return mHeight;
		}

		const std::string& getTitle() const
		{
			return mTitle;
		}

		GLFWwindow* getGLFWWindow() const
		{
			return mGLFWWindow;
		}

		bool closeRequested() const
		{
			return glfwWindowShouldClose(mGLFWWindow);
		}

		void setOpen(bool open) const
		{
			glfwSetWindowShouldClose(mGLFWWindow, open);
		}

		void setTitle(const std::string& title)
		{
			glfwSetWindowTitle(mGLFWWindow, title.c_str());
		}

		void setVsync(bool vsync)
		{
			glfwSwapInterval(vsync);
		}

		void pollEvents(bool updateDelta = true);
		
	private:

		static unsigned int mWidth, mHeight;

		std::string mTitle;

		GLFWwindow* mGLFWWindow;

		static void resizeCallback(GLFWwindow* window, int width, int height);

		void shutdownGLFW();

	};
}
