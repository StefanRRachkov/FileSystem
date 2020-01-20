//
// Created by User on 20.1.2020 г..
//

#ifndef FILESYSTEM_LSLISTDIRECTORY_H
#define FILESYSTEM_LSLISTDIRECTORY_H

#include "Command.h"
#include "../FileSystemStructure.h"

class lsListDirectory : public Command
{
private:
    FileSystemStructure* fileSystem;
public:
    lsListDirectory(FileSystemStructure*);

    bool Execute(std::string);

    inline ~lsListDirectory() = default;
};


#endif //FILESYSTEM_LSLISTDIRECTORY_H
