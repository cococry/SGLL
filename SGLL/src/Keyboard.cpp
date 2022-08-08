#include "Input/Keyboard.h"

bool SGLL::Keyboard::sKeys[GLFW_KEY_LAST];
bool SGLL::Keyboard::sKeysChanged[GLFW_KEY_LAST];

namespace SGLL
{
	void Keyboard::glfwKeyCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
	{
		if (action != GLFW_RELEASE)
		{
			if (!sKeys[key])
			{
				sKeys[key] = true;
			}
		}
		else
		{
			sKeys[key] = false;
		}

		sKeysChanged[key] = (action != GLFW_REPEAT);
	}
	bool Keyboard::isKeyDown(int key)
	{
		return sKeys[key];
	}
	bool Keyboard::wentKeyDown(int key)
	{
		return keyChanged(key) && sKeys[key];
	}
	bool Keyboard::isKeyReleased(int key)
	{
		return keyChanged(key) && !sKeys[key];
	}
	bool Keyboard::keyChanged(int key)
	{
		bool tmp = sKeysChanged[key];
		sKeysChanged[key] = false;
		return tmp;
	}
}