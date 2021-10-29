project "Tests"
    kind "ConsoleApp"
    language "C++"
    cppdialect "C++17"
    staticruntime "off"

    targetdir(TargetDir)
    objdir(ObjectDirectory)

    files
    {
        "src/**.h",
        "src/**.cpp"
    }

    includedirs
    {
        "src",
        "%{IncludeDir.GraphLayoutAlgorithms}",
        "%{IncludeDir.Gtest}",
        "%{IncludeDir.GtestInclude}",
    }

    links 
    {
        "GraphLayoutALgorithms",
        "gtest_main"
    }

    filter "configurations:Debug"
        defines "DEBUG"
        runtime "Debug"
        symbols "on"

    filter "configurations:Release"
        defines "NDEBUG"
        runtime "Release"
        optimize "on"

    include "/vendor/googletest"