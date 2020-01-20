#include "../Headers/InputController.h"

InputController::InputController()
{
    currentExecutableCommand = nullptr;
    fileSystem = nullptr;
}

InputController::InputController(FileSystemStructure* fileSystem)
{
    currentExecutableCommand = nullptr;
    this -> fileSystem = fileSystem;
}

InputController::InputController(const InputController& otherController)
{
    this -> currentExecutableCommand = otherController.currentExecutableCommand;
    this -> fileSystem = otherController.fileSystem;
}

InputController& InputController::operator=(const InputController& otherController)
{
    this -> currentExecutableCommand = otherController.currentExecutableCommand;
    this -> fileSystem = otherController.fileSystem;
    return *this;
}

bool InputController::SetFileSystem(FileSystemStructure* newFileSystem)
{
    this -> fileSystem = newFileSystem;
    return true;
}

std::string InputController::LogicOverInput(const std::string& userInput)
{
    // Interesting bug
    std::string allWithoutCommand = userInput;
    if (userInput.find("pwd") != std::string::npos)
    {
        allWithoutCommand = allWithoutCommand.replace(userInput.find("pwd"), 4, "");
        this -> currentExecutableCommand = new pwdFullPath(fileSystem);

    }
    else if (userInput.find("cd") != std::string::npos)
    {
        allWithoutCommand = allWithoutCommand.replace(userInput.find("cd"), 3, "");
        this -> currentExecutableCommand = new cdChangeDirectory(fileSystem);
    }
    else if (userInput.find("ls") != std::string::npos)
    {
        allWithoutCommand = allWithoutCommand.replace(userInput.find("ls"), 3, "");
        this -> currentExecutableCommand = new lsListDirectory(fileSystem);
    }
    else if (userInput.find("cat") != std::string::npos)
    {
        allWithoutCommand = allWithoutCommand.replace(userInput.find("cat"), 4, "");
        this -> currentExecutableCommand = new catConcatContent(fileSystem);
    }
    else if (userInput.find("cp") != std::string::npos)
    {
        allWithoutCommand = allWithoutCommand.replace(userInput.find("cp"), 3, "");
        this -> currentExecutableCommand = new cpCopy(fileSystem);
    }
    else if (userInput.find("rm") != std::string::npos && userInput.find("rmdir") == std::string::npos)
    {
        allWithoutCommand = allWithoutCommand.replace(userInput.find("rm"), 3, "");
        this -> currentExecutableCommand = new rmRemoveFile(fileSystem);
    }
    else if (userInput.find("rmdir") != std::string::npos)
    {
        allWithoutCommand = allWithoutCommand.replace(userInput.find("rmdir"), 6, "");
        this -> currentExecutableCommand = new rmdirDeleteEmptyDir(fileSystem);
    }
    else if (userInput.find("mkdir") != std::string::npos)
    {
        allWithoutCommand = allWithoutCommand.replace(userInput.find("mkdir"), 6, "");
        this -> currentExecutableCommand = new mkdirCreateDir(fileSystem);
    }
    else
    {
        currentExecutableCommand = nullptr;
    }
    if(currentExecutableCommand)
    {
        currentExecutableCommand -> Execute(allWithoutCommand);
        return currentExecutableCommand -> GetMessage();
    }
    else
    {
        return "-";
    }
}


InputController::~InputController()
{
    delete(currentExecutableCommand);
}
