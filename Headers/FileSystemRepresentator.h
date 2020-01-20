/// DemoClass -> Purpose: Testing

#ifndef FILESYSTEM_FILESYSTEMREPRESENTATOR_H
#define FILESYSTEM_FILESYSTEMREPRESENTATOR_H

#include "FileSystemStructure.h"
#include "InputController.h"

class FileSystemRepresentator
{
private:
    FileSystemStructure* fileSystem;
    InputController inputController;
public:
    inline FileSystemRepresentator() = default;
    FileSystemRepresentator(FileSystemNode*);

    bool Start();

    ~FileSystemRepresentator();
};


#endif //FILESYSTEM_FILESYSTEMREPRESENTATOR_H
