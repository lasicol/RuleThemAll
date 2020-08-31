#pragma once

#include <memory>

#include <spdlog/spdlog.h>
#include <spdlog/fmt/ostr.h>

namespace RTA {

	class Log
	{
	public:
		static void Init();

		static std::shared_ptr<spdlog::logger>& GetLogger() { return s_Logger; }
	private:
		static std::shared_ptr<spdlog::logger> s_Logger;
	};

}

// Log macros
#define RTA_TRACE(...)    ::RTA::Log::GetLogger()->trace(__VA_ARGS__)
#define RTA_INFO(...)     ::RTA::Log::GetLogger()->info(__VA_ARGS__)
#define RTA_WARN(...)     ::RTA::Log::GetLogger()->warn(__VA_ARGS__)
#define RTA_ERROR(...)    ::RTA::Log::GetLogger()->error(__VA_ARGS__)
#define RTA_CRITICAL(...) ::RTA::Log::GetLogger()->critical(__VA_ARGS__)

