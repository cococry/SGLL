#include "Display.h"

#include "Asserts.h"
#include "Keyboard.h"
#include "Mouse.h"
#include "DeltaTime.h"

#include <glad/glad.h>

unsigned int SGLL::Display::sWidth;
unsigned int SGLL::Display::sHeight;

namespace SGLL
{
	Display::Display(unsigned int width, unsigned int height, const std::string& title, bool rezisable, bool startFullScreen, bool vsync)
	{
		init(width, height, title, rezisable, startFullScreen);
	}

	Display::~Display()
	{
		shutdownGLFW();
		destory();
	}

	void Display::swapBuffers()
	{
		glfwSwapBuffers(mGLFWWindow);
	}

	void Display::init(unsigned int width, unsigned int height, const std::string& title, bool rezisable, bool startFullScreen, bool vsync)
	{
		mTitle = title;
		sWidth = width;
		sHeight = height;

		Log::Init(title == "" ? "SGLL CLIENT" : title);

		SGLL_ASSERT_MSG(glfwInit(), "Failed to intialize GLFW.");

		glfwWindowHint(GLFW_RESIZABLE, rezisable);

		mGLFWWindow = glfwCreateWindow(width, height, title.c_str(), startFullScreen ? glfwGetPrimaryMonitor() : nullptr, nullptr);

		SGLL_ASSERT_MSG(mGLFWWindow, "Failed to create GLFW Window.");

		glfwMakeContextCurrent(mGLFWWindow);

		glfwSetFramebufferSizeCallback(mGLFWWindow, resizeCallback);
		glfwSetKeyCallback(mGLFWWindow, Keyboard::glfwKeyCallback);
		glfwSetMouseButtonCallback(mGLFWWindow, Mouse::glfwButtonCallback);
		glfwSetCursorPosCallback(mGLFWWindow, Mouse::glfwCursorPosCallback);
		glfwSetScrollCallback(mGLFWWindow, Mouse::glfwScrollCallback);

		glfwSwapInterval(vsync);

		SGLL_ASSERT_MSG(gladLoadGLLoader((GLADloadproc)glfwGetProcAddress), "Failed to intialize Glad.");
	}

	void Display::destory()
	{
		glfwDestroyWindow(mGLFWWindow);
	}

	void Display::shutdownGLFW()
	{
		glfwTerminate();
	}

	void Display::pollEvents(bool updateDelta)
	{
		glfwPollEvents();
		if (updateDelta)
		{
			DeltaTime::update();
		}
	}

	void Display::resizeCallback(GLFWwindow* window, int width, int height)
	{
		glViewport(0, 0, width, height);

		sWidth = width;
		sHeight = height;
	}

}
