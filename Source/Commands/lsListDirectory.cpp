//
// Created by User on 20.1.2020 г..
//

#include "../../Headers/Commands/lsListDirectory.h"

lsListDirectory::lsListDirectory(FileSystemStructure* fileSystem)
{
    this -> fileSystem = fileSystem;
}

bool lsListDirectory::Execute(std::string input)
{
    for(auto child : this -> fileSystem -> GetWorkingNode() -> children)
    {
        this -> message += child -> data -> GetFileName() + '\n';
    }
    return true;
}
