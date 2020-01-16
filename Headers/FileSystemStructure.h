
#ifndef FILESYSTEM_FILESYSTEMSTRUCTURE_H
#define FILESYSTEM_FILESYSTEMSTRUCTURE_H

#include "FileSystemNode.h"

class FileSystemStructure
{
private:
    FileSystemNode* root;
    FileSystemNode* workingNode;
public:
    inline FileSystemStructure() = default;
    FileSystemStructure(FileSystemNode*);
    FileSystemStructure(const FileSystemStructure&);
    FileSystemStructure& operator=(const FileSystemStructure&);

    /// Methods:
    bool AddNode(const std::string&);
    bool Remove(const std::string&);

    /// Get & Set
    FileSystemNode* GetRoot();

    FileSystemNode* GetWorkingNode();
    void SetWorkingNode(FileSystemNode*);

    ~FileSystemStructure();
};

#endif //FILESYSTEM_FILESYSTEMSTRUCTURE_H
