project "Tests"
    kind "ConsoleApp"
    language "C++"
    cppdialect "C++17"
    staticruntime "on"

    targetdir(TargetDirectory)
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
        "google_test"
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