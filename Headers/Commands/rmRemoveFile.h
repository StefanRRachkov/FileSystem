//
// Created by User on 20.1.2020 г..
//

#ifndef FILESYSTEM_RMREMOVEFILE_H
#define FILESYSTEM_RMREMOVEFILE_H

#include "Command.h"
#include "../FileSystemStructure.h"

class rmRemoveFile
{
private:
    FileSystemStructure* fileSystem;
public:
    rmRemoveFile(FileSystemStructure*);

    bool Execute(std::string);

    inline ~rmRemoveFile() = default;
};


#endif //FILESYSTEM_RMREMOVEFILE_H
