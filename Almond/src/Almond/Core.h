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

#define BIT(x) (1 << x) 
