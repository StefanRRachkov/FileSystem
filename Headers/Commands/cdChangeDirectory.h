//
// Created by User on 16.1.2020 г..
//

#ifndef FILESYSTEM_CDCHANGEDIRECTORY_H
#define FILESYSTEM_CDCHANGEDIRECTORY_H

#include "Command.h"
#include "../FileSystemStructure.h"

class  cdChangeDirectory : public Command
{
private:
    FileSystemStructure* fileSystem;
public:
    cdChangeDirectory(FileSystemStructure*);

    bool Execute(std::string) override;

    inline ~cdChangeDirectory() = default;
};


#endif //FILESYSTEM_CDCHANGEDIRECTORY_H
