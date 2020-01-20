//
// Created by User on 20.1.2020 г..
//

#ifndef FILESYSTEM_CATCONCATCONTENT_H
#define FILESYSTEM_CATCONCATCONTENT_H

#include "Command.h"
#include "../FileSystemStructure.h"

class catConcatContent : public Command
{
private:
    FileSystemStructure* fileSystem;
public:
    catConcatContent(FileSystemStructure*);

    bool Execute(std::string);

    inline ~catConcatContent() = default;
};


#endif //FILESYSTEM_CATCONCATCONTENT_H
