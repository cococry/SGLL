#pragma once

#include <GLFW/glfw3.h>

namespace SGLL
{
	class Keyboard
	{
	public:
		static void glfwKeyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);

		static bool isKeyDown(int key);

		static bool wentKeyDown(int key);

		static bool isKeyReleased(int key);

		static bool keyChanged(int key);
	private:

		static bool sKeys[];
		static bool sKeysChanged[];

	};
}