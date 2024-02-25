workspace "Cedra"
    architecture "x64"

    configurations
    {
        "Debug",
        "Release"
    }

    startproject "Sandbox"

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Cedra"
        location "Cedra"
    kind "StaticLib"
    language "C++"
    cppdialect "C++17"
    staticruntime "on"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }

    defines
    {
        "_CRT_SECURE_NO_WARNINGS"
    }

    includedirs
    {
        "%{prj.name}/src",
        "%{prj.name}/vendor/spdlog/include"
    }

    filter "system:windows"
        systemversion "latest"

        defines
        {
            "CD_PLATFORM_WINDOWS"
        }

    filter "configurations:Debug"
        defines "CD_DEBUG"
        runtime "Debug"
        symbols "on"
    
    filter "configurations:Release"
        defines "CD_RELEASE"
        runtime "Release"
        optimize "on"

project "Sandbox"
    location "Sandbox"
    kind "ConsoleApp"
    language "C++"
    cppdialect "C++17"
    staticruntime "on"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }

    includedirs
    {
        "Cedra/vendor/spdlog/include",
        "Cedra/src",
        "Cedra/vendor"
    }

    links 
    {
        "Cedra"
    }

    filter "system:windows"
        systemversion "latest"

        defines
        {
            "CD_PLATFORM_WINDOWS"
        }

    filter "configurations:Debug"
        defines "CD_DEBUG"
        runtime "Debug"
        symbols "on"
    
    filter "configurations:Release"
        defines "CD_RELEASE"
        runtime "Release"
        optimize "on"