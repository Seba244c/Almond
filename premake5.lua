workspace "Almond"
	architecture "x86_64"
	startproject "Sandbox"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

	flags
	{
		"MultiProcessorCompile"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- Include directories relative to root folder (solution directory)

group ""

project "Almond"
	location "Almond"
	kind "SharedLib"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"%{prj.name}/vendor/spdlog/include"
	}

	postbuildcommands {
		("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
	}

	filter "system:windows"
		systemversion "latest"
		defines {
		"AM_PLATFORM_WINDOWS",
		"AM_BUILD_DLL"
		}

	filter "configurations:Debug"
		defines "AM_DEBUG"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		defines "AM_RELEASE"
		runtime "Release"
		optimize "on"

	filter "configurations:Dist"
		defines "AM_DIST"
		runtime "Release"
		optimize "on"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"Almond/vendor/spdlog/include",
		"Almond/src"
	}

	links
	{
		"Almond"
	}

	filter "system:windows"
		systemversion "latest"
		defines {
		"AM_PLATFORM_WINDOWS"
		}
		
	filter "configurations:Debug"
		defines "AM_DEBUG"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		defines "AM_RELEASE"
		runtime "Release"
		optimize "on"

	filter "configurations:Dist"
		defines "AM_DIST"
		runtime "Release"
		optimize "on"