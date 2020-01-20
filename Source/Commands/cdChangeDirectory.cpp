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
    // Clearing the ../Testing/ and putting only /
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
        if (s == ".." && tempNode -> parent)
        {
            tempNode = tempNode -> parent;
        }
        else
        {
            for(auto child : tempNode -> children)
            {
                if (child -> data -> GetFileName() == s && child -> data -> GetFileName() == stepsOneByOne.at(stepsOneByOne.size() - 1))
                {
                    this -> fileSystem -> SetWorkingNode(child);
                    this -> message = "Changed Directory to: " + filePath;
                    return true;
                }
            }
        }
    }
    if(stepsOneByOne.at(stepsOneByOne.size() - 1) == "..")
    {
        this -> fileSystem -> SetWorkingNode(tempNode);
        this -> message = "Changed Directory to: " + filePath;
        return true;
    }
    this -> message = "Cannot change the directory. Possible Solution: Check input";
    return false;
 }