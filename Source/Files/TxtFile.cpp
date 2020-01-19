#include "../../Headers/Files/TxtFile.h"

TxtFile::TxtFile(const std::string& filePath)
{
    this -> fileName = filePath;
    file.open(filePath);
    std::cout << "LogFILE: TxtFile::TxtFile(const std::string& filePath) this -> file.is_open() == " << this -> file.is_open() << std::endl;
}

TxtFile::TxtFile(const TxtFile& other)
{
    this -> fileName = other.fileName;
    if(file.is_open()) file.close();
    if(!this -> file.is_open())
    {
        this -> file.open(this -> fileName);
    }
    else
    {
        std::cout << "LogError: TxtFile::TxtFile(const TxtFile& other) -> file.close() -> this -> file.is_open() == true" << std::endl;
    }
}

TxtFile& TxtFile::operator=(const TxtFile& other)
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
        std::cout << "LogError: TxtFile::operator=(const TxtFile& other) -> file.close() -> this -> file.is_open() == true" << std::endl;
        return *this;
    }
}

// File methods
std::string TxtFile::GetContent()
{
    return this -> fileContent;
}

std::string TxtFile::GetFileName()
{
    return this -> fileName;
}

bool TxtFile::Create(const std::string& filePath)
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
        std::cout << "LogError: TxtFile::Open(const std::string& filePath) -> file.close() -> this -> file.is_open() == true" << std::endl;
        return false;
    }
}

bool TxtFile::Delete(const std::string& filePath)
{
    if(this -> fileName == filePath)
    {
        this -> file.close();
        return ~this -> file.is_open();
    }
    else
    {
        return false;
    }
}

TxtFile::~TxtFile()
{
    file.close();
}

