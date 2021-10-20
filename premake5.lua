workspace "GraphLayoutAlgorithms"
    architecture "x86_64"
    startproject "Sandbox"

    TargetDirectory = "%{wks.location}/bin/%{cfg.buildcfg}/%{prj.name}"
    ObjectDirectory = "%{wks.location}/bin-int/%{cfg.buildcfg}/%{prj.name}"

    configurations
    {
        "Debug",
        "Release"
    }

    flags
    {
        "MultiprocessorCompile"
    }

    IncludeDir = {}
    IncludeDir["GraphLayoutAlgorithms"] = "%{wks.location}/GraphLayoutAlgorithms/src"

    include "Sandbox"
    include "GraphLayoutAlgorithms"
