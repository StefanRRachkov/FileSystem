//
// Created by User on 20.1.2020 г..
//

#ifndef FILESYSTEM_RMDIRDELETEEMPTYDIR_H
#define FILESYSTEM_RMDIRDELETEEMPTYDIR_H

#include "Command.h"
#include "../FileSystemStructure.h"

class rmdirDeleteEmptyDir : public Command
{
private:
    FileSystemStructure* fileSystem;
public:
    rmdirDeleteEmptyDir(FileSystemStructure*);

    bool Execute(std::string);

    inline ~rmdirDeleteEmptyDir() = default;
};


#endif //FILESYSTEM_RMDIRDELETEEMPTYDIR_H
