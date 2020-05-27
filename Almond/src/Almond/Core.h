#pragma once

#ifdef AM_PLATFORM_WINDOWS
	#ifdef AM_BUILD_DLL
		#define ALMOND_API __declspec(dllexport)
	#else
		#define ALMOND_API __declspec(dllimport)
	#endif
#else
	#error Almond only supports Windows!
#endif

#ifdef AM_ENABLE_ASSERTS
#define AM_ASSERT(x, ...) { if(!(x)) { AM_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#define AM_CORE_ASSERT(x, ...) { if(!(x)) { AM_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
#define AM_ASSERT(x, ...)
#define AM_CORE_ASSERT(x, ...)
#endif

#define BIT(x) (1 << x) 
