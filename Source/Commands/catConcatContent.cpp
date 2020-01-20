//
// Created by User on 20.1.2020 г..
//

#include "../../Headers/Commands/catConcatContent.h"

catConcatContent::catConcatContent(FileSystemStructure* fileSystem)
{
    this -> fileSystem = fileSystem;
}

bool catConcatContent::Execute(std::string input)
{
    std::string steps = input;
    std::replace(steps.begin(), steps.end(), '>', ' ');
    std::vector<std::string> stepsOneByOne;
    std::stringstream ss(steps);
    std::string step;
    while(ss >> step)
    {
        stepsOneByOne.push_back(step);
    }
    std::string buffer;
    if(stepsOneByOne.size() > 1)
    {
        for(unsigned int index = 0; index < stepsOneByOne.size() - 1; index++)
        {
            for(auto child : this -> fileSystem -> GetWorkingNode() -> children)
            {
                if (child -> data -> GetFileName() == stepsOneByOne.at(index))
                {
                    buffer += child -> data -> GetContent();
                }
            }
        }
        for(auto child : this -> fileSystem -> GetWorkingNode() -> children)
        {
            if (child -> data -> GetFileName() == stepsOneByOne.at(stepsOneByOne.size() - 1))
            {
                child -> data -> SetContent(child -> data -> GetContent() + buffer);
                this -> message = "Saved into " + stepsOneByOne.at(stepsOneByOne.size() - 1) + '\n' + child -> data -> GetContent();
                return true;
            }
        }
    }
    else
    {
        for(auto child : this -> fileSystem -> GetWorkingNode() -> children)
        {
            if (child -> data -> GetFileName() == stepsOneByOne.at(stepsOneByOne.size() - 1))
            {
                std::cin >> buffer;
                child -> data -> SetContent(child -> data -> GetContent() + buffer);
                this -> message = "Saved into " + stepsOneByOne.at(stepsOneByOne.size() - 1) + child -> data -> GetContent();
                return true;
            }
        }
    }
    std::cout << "LogError: catConcatContent::Execute(std::string input) -> Returns False!" << std::endl;
    return false;
}
