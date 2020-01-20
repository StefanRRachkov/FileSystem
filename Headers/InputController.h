
#ifndef FILESYSTEM_INPUTCONTROLLER_H
#define FILESYSTEM_INPUTCONTROLLER_H

#include "Commands/CommandTypes.h"

//../Testing/

class InputController
{
private:
    Command* currentExecutableCommand;
    FileSystemStructure* fileSystem;

public:
    // TODO: Destructor for Commands
    InputController();
    InputController(FileSystemStructure*);
    InputController(const InputController&);
    InputController& operator=(const InputController&);

    bool SetFileSystem(FileSystemStructure*);

    std::string LogicOverInput(const std::string&);

    ~InputController();
};


#endif //FILESYSTEM_INPUTCONTROLLER_H
