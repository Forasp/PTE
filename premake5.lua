-- premake5.lua
workspace "PTE"
    configurations { "Debug", "Release" }

    project "PTE"
        kind "ConsoleApp"
        language "C++"
        architecture "x86_64"
        targetdir "bin/%{cfg.buildcfg}"
        objdir "obj/%{cfg.buildcfg}"

        files { "**.h", "**.cpp" }

        filter "configurations:Debug"
            defines { "DEBUG" }
            flags { "Symbols" }

        filter "configurations:Release"
            defines { "NDEBUG" }
            optimize "On"

-- Clean Function --
newaction {
    trigger     = "clean",
    description = "clean the software",
    execute     = function ()
    print("clean the build...")
    os.rmdir("./bin")
    os.rmdir("./obj")
    os.remove("./PTE.make")
    os.remove("./Makefile")
    print("done.")
    end
}
