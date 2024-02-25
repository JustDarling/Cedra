#pragma once

#ifdef CD_PLATFORM_WINDOWS
#if CD_DYNAMIC_LINK
#ifdef CD_BUILD_DLL
#define CEDRA_API __declspec(dllexport)
#else
#define CEDRA_API __declspec(dllimport)
#endif // CD_BUILD_DLL
#else
#define CEDRA_API
#endif // CD_DYNAMIC_LINK

#else
#error Cedra only support Windows x64 platform!
#endif // CD_PLATFORM_WINDOWS

#ifndef CD_DEBUG
#define CD_ENABLE_ASSERTS
#endif // CD_ENABLE_ASSERTS

#ifdef CD_ENABLE_ASSERTS
#define CD_ASSERT(x, ...) { if(!(x)) { CD_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#define CD_CORE_ASSERT(x, ...) { if(!(x)) { CD_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
#define CD_ASSERT(x, ...)
#define CD_CORE_ASSERT(x, ...)
#endif