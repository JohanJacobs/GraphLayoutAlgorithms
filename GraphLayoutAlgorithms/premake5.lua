project "GraphLayoutAlgorithms"
    kind "StaticLib"
    language "C++"
    cppdialect "C++17"

    targetdir (TargetDirectory)
    objdir(ObjectDirectory)

    files
    {
        "src/**.h",
        "src/**.cpp"
    }

    includedirs
    {
        "src",
    }

    filter "configurations:Debug"
        defines "DEBUG"
        runtime "Debug"
        symbols "on"
    
    filter "configurations:Release"
        defines "RELEASE"
        runtime "Release"
        optimize "on"	