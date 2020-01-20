//
// Created by User on 16.12.2019 г..
//

#include "../Headers/FileSystemRepresentator.h"

FileSystemRepresentator::FileSystemRepresentator(FileSystemNode* root)
{
    this -> fileSystem = new FileSystemStructure(root);
    this -> inputController.SetFileSystem(this -> fileSystem);
}

bool FileSystemRepresentator::Start()
{
    std::string input;
    do
    {
        input = "";
        std::getline(std::cin, input);
        std::cout << this -> inputController.LogicOverInput(input) << std::endl;
    }
    while(input != "exit");
    return true;
}

FileSystemRepresentator::~FileSystemRepresentator()
{
    delete(this -> fileSystem);
}