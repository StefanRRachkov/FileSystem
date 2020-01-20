//
// Created by User on 20.1.2020 г..
//

#ifndef FILESYSTEM_CPCOPY_H
#define FILESYSTEM_CPCOPY_H

#include "Command.h"
#include "../FileSystemStructure.h"

class cpCopy : public Command
{
private:
    FileSystemStructure* fileSystem;
public:
    cpCopy(FileSystemStructure*);

    bool Execute(std::string);

    inline ~cpCopy() = default;
};


#endif //FILESYSTEM_CPCOPY_H
