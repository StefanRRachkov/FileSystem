#include "../Headers/FileSystemStructure.h"


FileSystemStructure::FileSystemStructure(FileSystemNode* root)
{
    this -> root = root;
    this -> workingNode = root;
}

FileSystemStructure::FileSystemStructure(const FileSystemStructure& dataStructure)
{
    this -> root = dataStructure.root;
    this -> workingNode = dataStructure.workingNode;
}

FileSystemStructure& FileSystemStructure::operator=(const FileSystemStructure& dataStructure)
{
    this -> root = dataStructure.root;
    this -> workingNode = dataStructure.workingNode;
    return *this;
}

FileSystemStructure::~FileSystemStructure()
{
    if(this -> root)
    {
        delete(this -> root);
    }
    else
    {
        std::cout << "LogError: FileSystemStructure::~FileSystemStructure() -> root == nullprt" << std::endl;
    }
    if(this -> workingNode) delete(this -> workingNode);
}

bool FileSystemStructure::AddNode(const std::string& filePath)
{
    //TODO: return this -> workingNode -> AddChild(filePath);
}

bool FileSystemStructure::Remove(const std::string& filePath)
{
    return this -> workingNode -> RemoveChild(filePath);
}

FileSystemNode *FileSystemStructure::GetRoot()
{
    return this -> root;
}

FileSystemNode *FileSystemStructure::GetWorkingNode()
{
    return this -> workingNode;
}

void FileSystemStructure::SetWorkingNode(FileSystemNode* newWorkingNode)
{
    this -> workingNode = newWorkingNode;
}
