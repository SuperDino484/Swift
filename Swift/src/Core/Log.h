#pragma once

#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"

namespace Swift {

	class Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }

	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;

	};

}

// Core logging macros

#define SF_CORE_TRACE(...)		::Swift::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define SF_CORE_INFO(...)		::Swift::Log::GetCoreLogger()->info(__VA_ARGS__)
#define SF_CORE_WARN(...)		::Swift::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define SF_CORE_ERROR(...)		::Swift::Log::GetCoreLogger()->error(__VA_ARGS__)
#define SF_CORE_CRITICAL(...)	::Swift::Log::GetCoreLogger()->critical(__VA_ARGS__)


// Client logging macros

#define SF_TRACE(...)			::Swift::Log::GetClientLogger()->trace(__VA_ARGS__)
#define SF_INFO(...)			::Swift::Log::GetClientLogger()->info(__VA_ARGS__)
#define SF_WARN(...)			::Swift::Log::GetClientLogger()->warn(__VA_ARGS__)
#define SF_ERROR(...)			::Swift::Log::GetClientLogger()->error(__VA_ARGS__)
#define SF_CRITICAL(...)		::Swift::Log::GetClientLogger()->critical(__VA_ARGS__)