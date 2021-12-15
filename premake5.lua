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
    IncludeDir["GraphLayoutAlgorithms"] = "%{wks.location}/include/"
    IncludeDir["Gtest"] = "%{wks.location}/Tests/Vendor/googletest/googletest"
    IncludeDir["GtestInclude"] = "%{wks.location}/Tests/Vendor/googletest/googletest/include"

    include "Sandbox"
    include "Tests"   
