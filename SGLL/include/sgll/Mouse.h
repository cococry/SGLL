#pragma once

#include <GLFW/glfw3.h>

namespace SGLL
{
	class Mouse
	{
	public:
		static void glfwButtonCallback(GLFWwindow* window, int button, int action, int mods);

		static void glfwScrollCallback(GLFWwindow* window, double xoffset, double yoffest);

		static void glfwCursorPosCallback(GLFWwindow* window, double xpos, double ypos);

		static bool isButtonPressed(int button);

		static bool isButtonReleased(int button);

		static bool buttonChanged(int button);

		static bool buttonWentDown(int button);

		inline static double getXPos() { return sXPos; }

		inline static double getYPos() { return sYPos; }

		inline static double getXScrollDelta() { return sXScrollDelta; }

		inline static double getYScrollDelta() { return sYScrollDelta; }

		inline static double getXDeltaPos() { double ret = s_XDeltaPos; s_XDeltaPos = 0.0f; return ret; }

		inline static double getYDeltaPos() { double ret = s_YDeltaPos; s_YDeltaPos = 0.0f; return ret; }
	private:
		static bool sButtons[];
		static bool sButtonsChanged[];

		static bool sFirstMouse;

		static double sXPos;
		static double sYPos;

		static double sXScrollDelta, sYScrollDelta;
		static double sLastXPos, sLastYPos;
		static double s_XDeltaPos, s_YDeltaPos;
	};
}