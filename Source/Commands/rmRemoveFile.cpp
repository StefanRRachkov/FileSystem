//
// Created by User on 20.1.2020 г..
//

#include "../../Headers/Commands/rmRemoveFile.h"

rmRemoveFile::rmRemoveFile(FileSystemStructure* fileSystem)
{
    this -> fileSystem = fileSystem;
}

bool rmRemoveFile::Execute(std::string fileName)
{
    bool executed = this -> fileSystem -> GetWorkingNode() -> RemoveChild(fileName);
    if(executed) this -> message = "Removed File";
    else this -> message = "Cannot remove file";
    return executed;
}
