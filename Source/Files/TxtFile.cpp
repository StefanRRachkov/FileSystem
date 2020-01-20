#include "../../Headers/Files/TxtFile.h"

// TODO: Branch Predictor Optimise

TxtFile::TxtFile(const std::string& filePath)
{
    std::string steps = filePath;
    std::replace(steps.begin(), steps.end(), '/', ' ');
    std::vector<std::string> stepsOneByOne;
    std::stringstream ss(steps);
    std::string step;
    while(ss >> step)
    {
        stepsOneByOne.push_back(step);
    }
    std::string buffer;
    if(!this -> file.is_open())
    {
        this -> file.open(filePath);
        while(!this -> file.eof() && this -> file.is_open())
        {
            std::getline(this -> file, buffer);
            this -> fileContent += buffer + '\n';
        }
        this -> fileName = stepsOneByOne.back();
    }
    else
    {
        std::cout << "LogError: TxtFile::TxtFile(const std::string& filePath) -> !this -> file.is_open() -> this -> file.is_open() == true" << std::endl;
    }

}

TxtFile::TxtFile(const TxtFile& other)
{
    this -> fileName = other.fileName;
    if(file.is_open()) file.close();
    if(!this -> file.is_open())
    {
        this -> file.open(this -> fileName);
        this -> fileContent = other.fileContent;
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
        this -> fileContent = other.fileContent;
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

void TxtFile::SetContent(std::string content)
{
    this -> fileContent = content;
    this -> file << this -> fileContent;
}

bool TxtFile::Create(const std::string& filePath)
{
    this -> fileName = filePath;
    std::string buffer;
    if(file.is_open()) file.close();
    if(!this -> file.is_open())
    {
        this -> file.open(this -> fileName);
        while(!this -> file.eof())
        {
            std::getline(this -> file, buffer);
            this -> fileContent += buffer + '\n';
        }
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
        return !this -> file.is_open();
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


