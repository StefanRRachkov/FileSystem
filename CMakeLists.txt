cmake_minimum_required(VERSION 3.14)
project(FileSystem)

set(CMAKE_CXX_STANDARD 17)

add_executable(FileSystem main.cpp Headers/FileSystemStructure.h Source/FileSystemStructure.cpp Source/Files/TxtFile.cpp Headers/Files/TxtFile.h Source/FileSystemRepresentator.cpp Headers/FileSystemRepresentator.h Source/Commands/Command.cpp Headers/Commands/Command.h Source/Commands/pwdFullPath.cpp Headers/Commands/pwdFullPath.h Source/InputController.cpp Headers/InputController.h Source/MetaData.cpp Headers/MetaData.h Source/FileSystemNode.cpp Headers/FileSystemNode.h Headers/Commands/CommandTypes.h Source/Commands/cdChangeDirectory.cpp Headers/Commands/cdChangeDirectory.h Source/Files/File.cpp Headers/Files/File.h Source/Files/Directory.cpp Headers/Files/Directory.h)