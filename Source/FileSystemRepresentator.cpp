//
// Created by User on 16.12.2019 г..
//

#include "../Headers/FileSystemRepresentator.h"

void FileSystemRepresentator::PrintTree(FileSystemNode* currentNode)
{
    /// Basic Traversal Algorithm
    if (!currentNode)
        return;
    for(auto child : currentNode -> children)
    {
        PrintTree(child);
    }
    std::cout << currentNode -> data -> GetFileName() << std::endl;
}
