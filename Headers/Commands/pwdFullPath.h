
#ifndef FILESYSTEM_PWDFULLPATH_H
#define FILESYSTEM_PWDFULLPATH_H

#include "Command.h"
#include "../FileSystemStructure.h"

class pwdFullPath : public Command
{
private:
    FileSystemStructure* fileSystem;
public:
    pwdFullPath(FileSystemStructure*);

    bool Execute(std::string) override;

    inline ~pwdFullPath() = default;
};


#endif //FILESYSTEM_PWDFULLPATH_H
