//
// Created by User on 20.1.2020
//

#include "../../Headers/Commands/mkdirCreateDir.h"

mkdirCreateDir::mkdirCreateDir(FileSystemStructure* fileSystem)
{
    this -> fileSystem = fileSystem;
}

bool mkdirCreateDir::Execute(std::string fileName)
{
    bool proceed = this -> fileSystem -> GetWorkingNode() -> AddChild(this -> fileSystem -> GetWorkingNode() -> nodePath + '/' + fileName , DIR);
    if(proceed) this -> message = "Created a Directory";
    else this -> message = "Didn't create a Directory";
    return proceed;
}
