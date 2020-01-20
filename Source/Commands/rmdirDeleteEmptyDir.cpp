//
// Created by User on 20.1.2020 г..
//

#include "../../Headers/Commands/rmdirDeleteEmptyDir.h"

rmdirDeleteEmptyDir::rmdirDeleteEmptyDir(FileSystemStructure* fileSystem)
{
    this -> fileSystem = fileSystem;
}

bool rmdirDeleteEmptyDir::Execute(std::string fileName)
{
    for(auto child : this -> fileSystem -> GetWorkingNode() -> children)
    {
        if (child -> data -> GetFileName() == fileName)
        {
            if(child -> children.empty())
            {
                this -> message = "Directory Removed";
                return this -> fileSystem -> GetWorkingNode() -> RemoveChild(child -> nodePath);
            }
            else
            {
                this -> message = "Directory was not Removed -> Subject: Not Empty";
                return false;
            }
        }
    }
    std::cout << "LogWarning: rmdirDeleteEmptyDir::Execute(std::string fileName) -> Doesn't Proceed" << std::endl;
    return false;
}
