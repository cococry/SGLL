#include "Mouse.h"


bool SGLL::Mouse::sButtons[GLFW_MOUSE_BUTTON_LAST] = { 0 };
bool SGLL::Mouse::sButtonsChanged[GLFW_MOUSE_BUTTON_LAST] = { 0 };
double SGLL::Mouse::sXPos = 0;
double SGLL::Mouse::sYPos = 0;
double SGLL::Mouse::sXScrollDelta = 0;
double SGLL::Mouse::sYScrollDelta = 0;
double SGLL::Mouse::s_XDeltaPos = 0;
double SGLL::Mouse::s_YDeltaPos = 0;
double SGLL::Mouse::sLastXPos = 0;
double SGLL::Mouse::sLastYPos = 0;
bool SGLL::Mouse::sFirstMouse = true;

namespace SGLL
{
	void Mouse::glfwButtonCallback(GLFWwindow* window, int button, int action, int mods)
	{
		if (action != GLFW_RELEASE)
		{
			if (!sButtons[button])
			{
				sButtons[button] = true;
			}
		}
		else
		{
			sButtons[button] = false;
		}

		sButtonsChanged[button] = (action != GLFW_REPEAT);
	}
	void Mouse::glfwScrollCallback(GLFWwindow* window, double xoffset, double yoffest)
	{

		sXScrollDelta = xoffset;
		sYScrollDelta = yoffest;
	}
	void Mouse::glfwCursorPosCallback(GLFWwindow* window, double xpos, double ypos)
	{
		sXPos = xpos;
		sYPos = ypos;

		if (sFirstMouse)
		{
			sLastXPos = sXPos;
			sLastYPos = sYPos;
			sFirstMouse = false;
		}

		s_XDeltaPos = sXPos - sLastXPos;
		s_YDeltaPos = sYPos - sLastYPos;
		sLastXPos = sXPos;
		sLastYPos = sYPos;
	}
	bool Mouse::isButtonPressed(int button)
	{
		return sButtons[button];
	}
	bool Mouse::isButtonReleased(int button)
	{
		return buttonChanged(button) && !sButtons[button];
	}
	bool Mouse::buttonChanged(int button)
	{
		bool tmp = sButtonsChanged[button];
		sButtonsChanged[button] = false;
		return tmp;
	}
	bool Mouse::buttonWentDown(int button)
	{
		return buttonChanged(button) && !sButtons[button];
	}
}