project "Sandbox"
    kind "ConsoleApp"
    language "C++"
    staticruntime "on"
    cppdialect "C++17"
    
    targetdir ("../bin/" .. outputdir .. "/%{prj.name}")
    objdir ("../bin-int/" .. outputdir .. "/%{prj.name}")
    
    files
    {
        "src/**.h",
        "src/**.cpp"
    }
    
    includedirs
    {
        "../Swift/src",
        "../Swift/vendor/spdlog/include"
    }

    links
    {
        "Swift"
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