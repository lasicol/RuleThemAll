-- premake5.lua
workspace "RuleThemAll"
	configurations { "Debug", "Release" }
	architecture "x86_64"

project "RuleThemAll"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++17"

	targetdir "bin/%{cfg.buildcfg}"

	files { 
		"src/**.h", 
		"src/**.cpp" 
	}

	includedirs
	{
		"src",
		"vendor/spdlog/include",
	}

	filter "configurations:Debug"
		defines { "DEBUG" }
		symbols "On"

	filter "configurations:Release"
		defines { "NDEBUG" }
		optimize "On"