workspace "Swift"
    architecture "x64"
    startproject "Sandbox"

    configurations
	{
		"Debug",
		"Release"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

IncludeDirs = {}
IncludeDirs["spdlog"] = "Swift/vendor/spdlog/include"

include "Swift"
include "Sandbox"