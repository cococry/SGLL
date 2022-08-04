#pragma once

#include <spdlog/spdlog.h>
#include <spdlog/sinks/stdout_color_sinks.h>
#include <memory>

namespace SGLL
{
	class Log
	{
	public:
		static void Init(const std::string& clientLoggerName = "SGLL CLIENT");

		inline static std::shared_ptr<spdlog::logger> GetInternalLogger() { return sInternalLogger; }

		inline static std::shared_ptr<spdlog::logger> GetClientLogger() { return sClientLogger; }
	private:
		static std::shared_ptr<spdlog::logger> sInternalLogger;
		static std::shared_ptr<spdlog::logger> sClientLogger;
	};
}

#define SGLL_INTERNAL_INFO(...) SGLL::Log::GetInternalLogger()->info(__VA_ARGS__)
#define SGLL_INTERNAL_DEBUG(...) SGLL::Log::GetInternalLogger()->debug(__VA_ARGS__)
#define SGLL_INTERNAL_TRACE(...) SGLL::Log::GetInternalLogger()->trace(__VA_ARGS__)
#define SGLL_INTERNAL_WARN(...) SGLL::Log::GetInternalLogger()->warn(__VA_ARGS__)
#define SGLL_INTERNAL_ERROR(...) SGLL::Log::GetInternalLogger()->error(__VA_ARGS__)
#define SGLL_INTERNAL_CRITICAL(...) SGLL::Log::GetInternalLogger()->critical(__VA_ARGS__)

#define SGLL_INFO(...) SGLL::Log::GetClientLogger()->info(__VA_ARGS__)
#define SGLL_DEBUG(...) SGLL::Log::GetClientLogger()->debug(__VA_ARGS__)
#define SGLL_TRACE(...) SGLL::Log::GetClientLogger()->trace(__VA_ARGS__)
#define SGLL_WARN(...) SGLL::Log::GetClientLogger()->warn(__VA_ARGS__)
#define SGLL_ERROR(...) SGLL::Log::GetClientLogger()->error(__VA_ARGS__)
#define SGLL_CRITICAL(...) SGLL::Log::GetClientLogger()->critical(__VA_ARGS__)