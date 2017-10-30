This project is no longer active. An AAR is provided below, all original content follows the AAR.

# AAR (After Action Review)

Well, this was a fun project to throw a little time at and I learned a few good things along the way. My initial goal was to create a highly threaded and class diverse text game engine with a very simple method of creating new "games" or text interactions. I realized pretty quickly that threading was completely unecessary given the low amount of work, and lack of any need for independant operation. I also learned that without a game in mind, I'm developing something with requirements but nothing to bench them on. Without a solid and enjoyable project in mind to use as a benchmark, I quickly lost interest in the project, and completed it to a fairly low standard. It's capable of reading in formatted text files declaring objects and their interactions, and it has a usable entry point. For text only adventures, with no RNG, this works fine and supports some flags, but it really doesn't allow much customization for the user (writer) and requires changes in code to add support for things like character stats.

# PTE (Powell Text Engine)

## Description
A basic text game engine with simple text configuration.

## Build Instructions
Run the included premake, from this folder, with parameters for whatever compiler/IDE you plan to use. See guide here: https://github.com/premake/premake-core/wiki/Using-Premake

After that's finished, build via typical steps for your IDE/Compiler.

## Use Instructions
The FileList.pte in the Objects folder determines what Object files will be, and where they are relative to application's output file or executable. Each one of those Object files can support as many objects as you want, and there can be as many Object files as you want. You can nest the files in additional folders, or keep them all in one folder, as long as the files are referenced properly in the FileList.pte file.
Currently, only extremely basic functionality is supported. Each game object can contain a Name, Description, Trigger, Required State, Response, Action, and sub-action. The only actions currently supported in the Main.cpp file are QUIT and ENTER_STATE, adding additional actions is planned.

A Sample FileList.pte, and two sample object files are provided in the Objects folder, here's a breakdown of how the files are formatted, and how they're read.

### FileList.pte
FILE_NAME Indicates that the proceeding line will contain a relative or direct path to an object file.
A newline must follow FILE_NAME, and on that new line, you can put a relative or direct path to an object file.
At the end of the file, include FILE_END

### [Object file name].pte
We open each object with "Object" and a new line.
We open each Object Property (Such as ObjectName) with "Object[Property]" and a new line.
Each Object Property's content immediately follows, and is terminated with a new line.
If an Object Property has sub-properties (Such as ObjectAction), the sub-properties will immediately proceed the Property.
      At present, if the Action is a type that requires a sub action, it requires a sub-action to follow. This must be enforced.
An Object is closed when we read "Object" again, as this opens a new object.
When we reach the end of the file, add "FILE_END".

## Notes to users

This is all subject to change; however, I will attempt to keep as much backwards compatibility as possible with .pte formatted files. If the time comes that I switch to an XML format, or some other style, I will change the file extension to prevent any confusion.

Since this is a console/terminal application, if the QUIT Action is not included in the GameObjects.pte, you can terminate the program with Ctrl+C or Ctrl+Shift+Break, or by closing the console/terminal.

All lines must be limited to 1024 characters until a change is made to support longer strings. If there is a need for that then you may fork the project, make and test your change, pull, merge, and push. 

I intend to eliminate the need for the FileList.pte file; however, I will leave the functionality as an override, so that you may either let all .pte files be found automatically, or specify only specific files to load. 

I'm trying to keep things as cross-platform compatible as possible between Ubuntu 16.04+ and Windows 10+, if you find any issues with any other OSes please alert me, or feel free to fix them yourself (and pull/merge/push with trunk)
