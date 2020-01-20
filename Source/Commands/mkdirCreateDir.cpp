//
// Created by User on 20.1.2020 г..
//

#include "../../Headers/Commands/mkdirCreateDir.h"

mkdirCreateDir::mkdirCreateDir(FileSystemStructure* fileSystem)
{
    this -> fileSystem = fileSystem;
}

bool mkdirCreateDir::Execute(std::string fileName)
{
    this -> message = "Created Directory";
    return this -> fileSystem -> GetWorkingNode() -> AddChild(fileName, DIR);
}
