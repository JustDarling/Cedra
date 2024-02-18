#pragma once

#ifdef CD_PLATFORM_WINDOWS
	#ifdef CD_BUILD_DLL
		#define CEDRA_API __declspec(dllexport)
	#else
		#define CEDRA_API __declspec(dllimport)
	#endif
#else
	#error Cedra only supports Windows!
#endif