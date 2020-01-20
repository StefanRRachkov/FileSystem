//
// Created by User on 20.1.2020 г..
//

#ifndef FILESYSTEM_MKDIRCREATEDIR_H
#define FILESYSTEM_MKDIRCREATEDIR_H

#include "Command.h"
#include "../FileSystemStructure.h"

class mkdirCreateDir : public Command
{
private:
    FileSystemStructure* fileSystem;
public:
    mkdirCreateDir(FileSystemStructure*);

    bool Execute(std::string);

    inline ~mkdirCreateDir() = default;
};


#endif //FILESYSTEM_MKDIRCREATEDIR_H
