
#ifndef FILESYSTEM_FILE_H
#define FILESYSTEM_FILE_H

#include "MetaData.h"
#include <fstream>
#include <iostream>

class File
{
private:
    // TODO: -> MetaData meta(std::string, std::string, std::string, std::string, std::string, std::string);
    std::string fileName;
    std::fstream file;
    // TODO: Idea -> std::string fileContent;
    // MetaData meta;
public:
    inline File() = default;
    File(const std::string&);
    File(const File&);
    File& operator=(const File&);

    bool Open(const std::string&);
    bool Close();

    std::string GetFileName();

    ~File();
};


#endif //FILESYSTEM_FILE_H
