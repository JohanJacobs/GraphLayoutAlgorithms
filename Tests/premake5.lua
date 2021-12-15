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
        "src/**.cpp",
		"%{IncludeDir.GraphLayoutAlgorithms}/**.cpp",
		"%{IncludeDir.GraphLayoutAlgorithms}/**.hpp"
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