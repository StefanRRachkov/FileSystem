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
    std::string allWithoutCommand = userInput;
    if (userInput.find("pwd") != std::string::npos)
    {
        allWithoutCommand = allWithoutCommand.replace(userInput.find("pwd"), 3, "");
        this -> currentExecutableCommand = new pwdFullPath(fileSystem);

    }
    if (userInput.find("cd") != std::string::npos)
    {
        allWithoutCommand = allWithoutCommand.replace(userInput.find("cd"), 2, "");
        this -> currentExecutableCommand = new cdChangeDirectory(fileSystem);
    }
    if (userInput.find("ls") != std::string::npos)
    {

    }
    if (userInput.find("cat") != std::string::npos)
    {

    }
    if (userInput.find("cp") != std::string::npos)
    {

    }
    if (userInput.find("rm") != std::string::npos)
    {

    }
    if (userInput.find("mkdir") != std::string::npos)
    {

    }
    if (userInput.find("rmdir") != std::string::npos)
    {

    }
    if (userInput.find("ln") != std::string::npos)
    {

    }
    if (userInput.find("stat") != std::string::npos)
    {

    }
    currentExecutableCommand -> Execute(allWithoutCommand);
    return currentExecutableCommand -> GetMessage();
}


InputController::~InputController()
{
    delete(currentExecutableCommand);
}
