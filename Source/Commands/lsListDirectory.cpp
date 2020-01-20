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
    if(this -> fileSystem -> GetWorkingNode() -> children.size() > 0)
    {
        for(auto child : this -> fileSystem -> GetWorkingNode() -> children)
        {
            this -> message += child -> data -> GetFileName() + '\n';
        }
        if (!this -> message.empty() && this -> message.at(this -> message.size() - 1) == '\n')
        {
            this -> message.erase(this -> message.size() - 1);
        }
    }
    return true;
}
