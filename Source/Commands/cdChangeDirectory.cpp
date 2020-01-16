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
    std::cout << "LogWarning: cdChangeDirectory::Execute(std::string filePath) -> unfinished" << std::endl;
    return false;
}