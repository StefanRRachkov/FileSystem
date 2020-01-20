
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
//    if(data) delete(data);
//    if(parent) delete(parent);
//    for(auto child : children)
//    {
//        if(child) delete(child);
//    }
}

bool FileSystemNode::AddChild(const std::string& filePath, const FileType& fType)
{
    File* childData;
    switch (fType)
    {
        case TXT:
        {
            childData = new TxtFile(filePath);
            break;
        }
        case DIR:
        {
            childData = new Directory;
            childData -> Create(filePath);
            break;
        }
    }
    auto child = new FileSystemNode(
            childData,
            fType,
            this -> nodePath + '/' + childData -> GetFileName(),
            this
    );
    this -> children.push_back(child);
    return true;
}

bool FileSystemNode::RemoveChild(const std::string& filePath)
{
    std::string steps = filePath;
    std::replace(steps.begin(), steps.end(), '/', ' ');
    std::vector<std::string> stepsOneByOne;
    std::stringstream ss(steps);
    std::string step;
    while(ss >> step)
    {
        stepsOneByOne.push_back(step);
    }
    for(unsigned int index = 0; index < this -> children.size(); index++)
    {
        if (this -> children.at(index) -> data -> GetFileName() == stepsOneByOne.back())
        {
            if(this -> children.at(index) -> fileType == DIR) this -> data -> Delete(filePath);
            this -> children.erase(this -> children.begin() + index);
            return true;
        }
    }
    std::cout << "Log: Child Not Found!" << std::endl;
    return false;
}
