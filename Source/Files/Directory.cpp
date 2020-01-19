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
    fs::create_directories("./" + directoryName);
    this -> dirName = directoryName;
    return true;
}

bool Directory::Delete(const std::string& directoryName)
{
    fs::remove_all(directoryName);
    this -> dirName = "";
    std::cout << "LogWarning: Directory::Delete(const std::string& directoryName) -> Needs Testing" << std::endl;
    return false;
}






