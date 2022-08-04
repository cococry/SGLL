#include "DeltaTime.h"

float SGLL::DeltaTime::sDeltaTime;
float SGLL::DeltaTime::sLastFrameTime;

namespace SGLL
{
	void DeltaTime::update()
	{
		float thisFrameTime = glfwGetTime();
		sDeltaTime = thisFrameTime - sLastFrameTime;
		sLastFrameTime = thisFrameTime;
	}

}
