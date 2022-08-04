#pragma once

#include <GLFW/glfw3.h>

namespace SGLL
{
	class DeltaTime
	{
	public:
		operator float() { return sDeltaTime; }

		static float getLastFrameTime() { return sLastFrameTime; }

		static void update();

		static float get() { return sDeltaTime; }
	private:
		static float sDeltaTime;
		static float sLastFrameTime;
	};

}