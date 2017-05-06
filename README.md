# PTE (Powell Text Engine)

## Description
A basic text game engine with simple text configuration.

## Build Instructions
Run the included premake, from this folder, with parameters for whatever compiler/IDE you plan to use. See guide here: https://github.com/premake/premake-core/wiki/Using-Premake

After that's finished, build via typical steps for your IDE/Compiler.

## Use Instructions
The GameObjects.pte in the same folder as the output determines what Objects will be read in and how they work.
Currently, only extremely basic functionality is supported. Each game object can contain a Name, Description, Trigger, Required State, Response, Action, and sub-action. The only actions currently supported in the Main.cpp file are QUIT and ENTER_STATE, adding additional actions, and shifting Response to be conditional on a RESPONSE action are planned.

A Sample GameObjects.pte is included in the root folder of the project, here's a breakdown of how the file is formatted, and how it's read.

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
