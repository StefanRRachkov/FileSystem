//
// Created by User on 16.1.2020 г..
//

#include "../../Headers/Commands/cdChangeDirectory.h"



cdChangeDirectory::cdChangeDirectory(FileSystemStructure* fileSystem)
{
    this -> fileSystem = fileSystem;
}

bool cdChangeDirectory::Execute(std::string filePath)
{
    std::string steps = filePath;
    std::replace(steps.begin(), steps.end(), '/', ' ');
    std::vector<std::string> stepsOneByOne;
    std::stringstream ss(steps);
    std::string step;
    while(ss >> step)
    {
        stepsOneByOne.push_back(step);
    }
    FileSystemNode* tempNode = this -> fileSystem -> GetWorkingNode();
    for(auto s : stepsOneByOne)
    {
        if (s == "..")
        {
            tempNode = tempNode -> parent;
        }
        else
        {
            tempNode = tempNode -> parent;
            for(auto child : tempNode -> children)
            {
                if (child -> data -> GetFileName() == s)
                {
                    this -> fileSystem -> SetWorkingNode(child);
                    this -> message = "Changed Directory to: " + filePath;
                    return true;
                }
            }
        }
    }
    return false;
}