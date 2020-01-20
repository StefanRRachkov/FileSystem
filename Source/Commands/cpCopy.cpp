//
// Created by User on 20.1.2020 г..
//

#include "../../Headers/Commands/cpCopy.h"

cpCopy::cpCopy(FileSystemStructure* fileSystem)
{
    this -> fileSystem = fileSystem;
}

bool cpCopy::Execute(std::string filePath)
{
    std::string steps = filePath;
    std::vector<std::string> stepsOneByOne;
    std::stringstream ss(steps);
    std::string step;
    while(ss >> step)
    {
        stepsOneByOne.push_back(step);
    }
    std::vector<std::string> files;
    for(unsigned int index = 0; index < stepsOneByOne.size() - 1; index++)
    {
        files.push_back(stepsOneByOne.at(index));
    }
    std::string dir = stepsOneByOne.at(stepsOneByOne.size() - 1);
    std::replace(dir.begin(), dir.end(), '/', ' ');
    std::vector<std::string> pathToDir;
    std::stringstream ssDir(dir);
    FileSystemNode* tempNode = this -> fileSystem -> GetWorkingNode();
    while(ssDir >> step)
    {
        pathToDir.push_back(step);
    }
    for(const auto& s : pathToDir)
    {
        if (s == "..")
        {
            for(auto file : files)
            {
                file += tempNode -> data -> GetFileName() + '/';
            }
            tempNode = tempNode -> parent;
        }
        else
        {
            tempNode = tempNode -> parent;
            for(const auto& file : files)
            {
                tempNode -> AddChild(file, TXT);
            }
        }
    }
    return true;
}
