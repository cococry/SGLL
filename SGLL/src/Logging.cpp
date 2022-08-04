#include "logging.h"

std::shared_ptr<spdlog::logger> SGLL::Log::sClientLogger;
std::shared_ptr<spdlog::logger> SGLL::Log::sInternalLogger;

namespace SGLL
{
	void Log::Init(const std::string& clientLoggerName)
	{
		spdlog::set_pattern("%^[%T] %n: %v%$");

		sInternalLogger = spdlog::stdout_color_mt("SGLL");
		sInternalLogger->set_level(spdlog::level::trace);

		sClientLogger = spdlog::stdout_color_mt(clientLoggerName);
		sClientLogger->set_level(spdlog::level::trace);
	}
}
