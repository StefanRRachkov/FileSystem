
#include "../../Headers/Commands/pwdFullPath.h"

pwdFullPath::pwdFullPath(FileSystemStructure* currentFileSystem)
{
    this -> fileSystem = currentFileSystem;
}


bool pwdFullPath::Execute(std::string input)
{
    std::string msg =  this -> fileSystem -> GetWorkingNode() -> nodePath;
    if (msg.size() > 11)
    {
        msg.erase(msg.begin(), msg.begin() + 11);
    }
    else
    {
        msg.erase(msg.begin(), msg.begin() + 10);
    }
    this -> message = msg;
    return true;
}

