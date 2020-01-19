
#ifndef FILESYSTEM_FILESYSTEMNODE_H
#define FILESYSTEM_FILESYSTEMNODE_H

#include <vector>
#include <iostream>
#include "Files/FileTypes.h"

enum FileType {TXT, DIR};

struct FileSystemNode
{
    inline FileSystemNode() = default;
    FileSystemNode(File*, const FileType&, const std::string&, FileSystemNode*);
    FileSystemNode(const FileSystemNode&);
    FileSystemNode& operator=(const FileSystemNode&);

    /// Fields:
        File* data;
        FileType fileType;
        std::string nodePath;
        FileSystemNode* parent;
        std::vector<FileSystemNode*> children;

    ///  Utility Methods to Work With DS:
    bool AddChild(const std::string&, const FileType&);
    bool RemoveChild(const std::string&);

    ~FileSystemNode();
};


#endif //FILESYSTEM_FILESYSTEMNODE_H
