
#include "../Headers/FileSystemNode.h"

FileSystemNode::FileSystemNode(const FileSystemNode& node)
{
    //TODO: NodePath
    this -> data = node.data;
    this -> nodePath = node.nodePath;
    this -> parent = node.parent;
    this -> children = node.children;
}

FileSystemNode& FileSystemNode::operator=(const FileSystemNode& node)
{
    this -> data = node.data;
    this -> nodePath = node.nodePath;
    this -> parent = node.parent;
    this -> children = node.children;
    return *this;
}

FileSystemNode::~FileSystemNode()
{
    if(data) delete(data);
    if(parent) delete(parent);
    for(auto child : children)
    {
        if(child) delete(child);
    }
}

bool FileSystemNode::AddChild(const std::string& filePath)
{
    // TODO: FilePath
    std::string path = filePath;
    auto newFile = new TxtFile(filePath);
    auto newNode = new FileSystemNode();
    newNode -> data = newFile;
    newNode -> nodePath = this -> nodePath + '/' + path.erase(0, 3);
    newNode -> parent = this;
    this -> children.emplace_back(newNode);
    return newNode != nullptr;
}

bool FileSystemNode::RemoveChild(const std::string& filePath)
{
    for(auto child : this -> children)
    {
        if (child -> data -> GetFileName() == filePath)
        {
            delete(child);
            return true;
        }
    }
    std::cout << "Log: Child Not Found!" << std::endl;
    return false;
}
