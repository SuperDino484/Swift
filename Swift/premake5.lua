project "Swift"
    kind "StaticLib"
    language "C++"
    staticruntime "on"
    cppdialect "C++17"

    targetdir ("../bin/" .. outputdir .. "/%{prj.name}")
	objdir ("../bin-int/" .. outputdir .. "/%{prj.name}")

    pchheader "sfpch.h"
	pchsource "src/sfpch.cpp"

    files
	{
		"src/**.h",
		"src/**.cpp"
	}

    includedirs
	{
		"src",
		"vendor/spdlog/include"
	}

    defines
	{
		"_CRT_SECURE_NO_WARNINGS"
	}

    filter "system:windows"
		systemversion "latest"

		defines
		{
			"SF_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "SF_DEBUG"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		defines "SF_RELEASE"
		runtime "Release"
		optimize "on"