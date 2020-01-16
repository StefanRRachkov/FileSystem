#include "../Headers/File.h"

File::File(const std::string& filePath)
{
    this -> fileName = filePath;
    file.open(filePath);
    std::cout << "LogFILE: File::File(const std::string& filePath) this -> file.is_open() == " << this -> file.is_open() << std::endl;
}

bool File::Open(const std::string& filePath)
{
    this -> fileName = filePath;
    if(file.is_open()) file.close();
    if(!this -> file.is_open())
    {
        this -> file.open(this -> fileName);
        return file.is_open();
    }
    else
    {
        std::cout << "LogError: File::Open(const std::string& filePath) -> file.close() -> this -> file.is_open() == true" << std::endl;
        return false;
    }
}

bool File::Close()
{
    file.close();
    return  !file.is_open();
}

File::File(const File& other)
{
    this -> fileName = other.fileName;
    if(file.is_open()) file.close();
    if(!this -> file.is_open())
    {
        this -> file.open(this -> fileName);
    }
    else
    {
        std::cout << "LogError: File::File(const File& other) -> file.close() -> this -> file.is_open() == true" << std::endl;
    }
}

File& File::operator=(const File& other)
{
    this -> fileName = other.fileName;
    if(file.is_open()) file.close();
    if(!this -> file.is_open())
    {
        this -> file.open(this -> fileName);
        return *this;
    }
    else
    {
        std::cout << "LogError: File::operator=(const File& other) -> file.close() -> this -> file.is_open() == true" << std::endl;
        return *this;
    }
}

File::~File()
{
    file.close();
}

std::string File::GetFileName()
{
    return this -> fileName;
}

