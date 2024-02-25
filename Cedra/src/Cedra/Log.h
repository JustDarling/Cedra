#pragma once

#include <memory>

#include <spdlog/spdlog.h>
#include "spdlog/sinks/stdout_color_sinks.h"

namespace Cedra
{
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


//Core log macros
#define CD_CORE_TRACE(...)    ::Cedra::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define CD_CORE_INFO(...)     ::Cedra::Log::GetCoreLogger()->info(__VA_ARGS__)
#define CD_CORE_WARN(...)     ::Cedra::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define CD_CORE_ERROR(...)    ::Cedra::Log::GetCoreLogger()->error(__VA_ARGS__)
#define CD_CORE_FATAL(...)    ::Cedra::Log::GetCoreLogger()->fatal(__VA_ARGS__)

//Client log macros
#define CD_TRACE(...)    ::Cedra::Log::GetClientLogger()->trace(__VA_ARGS__)
#define CD_INFO(...)     ::Cedra::Log::GetClientLogger()->info(__VA_ARGS__)
#define CD_WARN(...)     ::Cedra::Log::GetClientLogger()->warn(__VA_ARGS__)
#define CD_ERROR(...)    ::Cedra::Log::GetClientLogger()->error(__VA_ARGS__)
#define CD_FATAL(...)    ::Cedra::Log::GetClientLogger()->fatal(__VA_ARGS__)
