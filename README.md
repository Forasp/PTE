# PTE (Powell Text Engine)

## Description
A basic text game engine with simple text configuration.

## Instructions
The GameObjects.pte in the same folder as the output determines what Objects will be read in and how they work.
Currently, only extremely basic functionality is supported. Each game object can contain a Name, Description, Trigger, Response, and an Action. The only action currently supported in the Main.cpp file is QUIT, adding additional actions, and shifting Response to be conditional on a RESPONSE action are planned.

A Sample GameObjects.pte is included in the root folder of the project, here's a breakdown of how the file is formatted, and how it's read.

We open each object with "Object" and a new line.
We open each Object Property (Such as ObjectName) with "Object[Property]" and a new line.
Each Object Property's content immediately follows, and is terminated with a new line.
An Object is closed when we read "Object" again, as this opens a new object.
When we reach the end of the file, add "FILE_END".

## Notes to users

This is all subject to change; however, I will attempt to keep as much backwards compatibility as possible with .pte formatted files. If the time comes that I switch to an XML format, or some other style, I will change the file extension to prevent any confusion.

Since this is a console/terminal application, if the QUIT Action is not included in the GameObjects.pte, you can terminate the program with Ctrl+C or Ctrl+Shift+Break, or by closing the console/terminal.
