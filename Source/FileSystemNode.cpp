
#include "../Headers/FileSystemNode.h"

FileSystemNode::FileSystemNode( File* data,
                                const FileType& fType,
                                const std::string& filePath,
                                FileSystemNode* parent)
{
    this -> data = data;
    this -> fileType = fType;
    this -> nodePath = filePath;
    this -> parent = parent;
}


FileSystemNode::FileSystemNode(const FileSystemNode& node)
{
    this -> data = node.data;
    this -> fileType = node.fileType;
    this -> nodePath = node.nodePath;
    this -> parent = node.parent;
    this -> children = node.children;
}

FileSystemNode& FileSystemNode::operator=(const FileSystemNode& node)
{
    this -> data = node.data;
    this -> fileType = node.fileType;
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

bool FileSystemNode::AddChild(const std::string& filePath, const FileType& fType)
{
    auto childData = new TxtFile;
    childData -> Create(filePath);
    auto child = new FileSystemNode(
            childData,
            fType,
            this -> nodePath + filePath,
            this
    );
    this -> children.emplace_back(child);
    return true;
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
