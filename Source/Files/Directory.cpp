//
// Created by User on 19.1.2020 г..
//

#include "../../Headers/Files/Directory.h"

Directory::Directory(std::string dirName)
{
    this -> dirName = dirName;
}

Directory::Directory(const Directory& otherDir)
{
    this -> dirName = otherDir.dirName;
}

Directory& Directory::operator=(const Directory& otherDir)
{
    this -> dirName = otherDir.dirName;
    return *this;
}

std::string Directory::GetFileName()
{
    return this -> dirName;
}

std::string Directory::GetContent()
{
    return std::string("Directory: " + this -> dirName);
}

bool Directory::Create(const std::string& directoryName)
{
    std::string pureDirName = directoryName;
    std::replace(pureDirName.begin(), pureDirName.end(), '/', ' ');
    std::vector<std::string> stepsOneByOne;
    std::stringstream ss(pureDirName);
    std::string step;
    while(ss >> step)
    {
        stepsOneByOne.push_back(step);
    }

    this -> dirName = stepsOneByOne.at(stepsOneByOne . size() - 1);
    bool created = mkdir(directoryName.c_str());
    return created;
}

bool Directory::Delete(const std::string& directoryName)
{
    bool deleted = true;
    std::string steps = directoryName;
    std::replace(steps.begin(), steps.end(), '/', ' ');
    std::vector<std::string> stepsOneByOne;
    std::stringstream ss(steps);
    std::string step;
    while(ss >> step)
    {
        stepsOneByOne.push_back(step);
    }
    deleted = rmdir(directoryName.c_str());
    this -> dirName = "";
    return deleted;
}






