#include "FileUtil.h"

#include <sstream>
#include <fstream>

#include "Logging.h"

namespace SGLL
{
	std::string FileUtil::getFileContents(const std::string& filepath)
	{
		std::ifstream file;
		std::stringstream buffer;
		std::string returnValue = "";

		file.open(filepath);

		if (file.is_open())
		{
			buffer << file.rdbuf();
			returnValue = buffer.str();
		}
		else
		{
			SGLL_INTERNAL_ERROR("Failed to open file at location '{0}'.", filepath);
		}

		return returnValue;
	}

}
