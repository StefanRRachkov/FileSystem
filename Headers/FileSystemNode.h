
#ifndef FILESYSTEM_FILESYSTEMNODE_H
#define FILESYSTEM_FILESYSTEMNODE_H

#include <vector>
#include <iostream>
#include "Files/TxtFile.h"

struct FileSystemNode
{
    inline FileSystemNode() = default;
    FileSystemNode(const FileSystemNode&);
    FileSystemNode& operator=(const FileSystemNode&);
    /// Fields:
        TxtFile* data;
        std::string nodePath;
        FileSystemNode* parent;
        std::vector<FileSystemNode*> children;
    ///  Utility Methods to Work With DS:
    bool AddChild(const std::string&);
    bool RemoveChild(const std::string&);

    ~FileSystemNode();
};


#endif //FILESYSTEM_FILESYSTEMNODE_H
