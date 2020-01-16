
#include "../../Headers/Commands/pwdFullPath.h"

pwdFullPath::pwdFullPath(FileSystemStructure* currentFileSystem)
{
    this -> fileSystem = currentFileSystem;
}


bool pwdFullPath::Execute(std::string input)
{
    this -> message = this -> fileSystem -> GetWorkingNode() -> nodePath;
    return true;
}

