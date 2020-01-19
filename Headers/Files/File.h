//
// Created by User on 19.1.2020 г..
//

#ifndef FILESYSTEM_FILE_H
#define FILESYSTEM_FILE_H

#include <string>

// Abstract Class
//std::filesystem::create_directories("./a/b/c") -> Directory Creation
//std::filesystem::remove(DIRNAME) -> Empty Directory

class File
{
public:
    virtual std::string GetFileName() = 0;
    virtual std::string GetContent() = 0;
    virtual bool Create(const std::string&) = 0;
    virtual bool Delete(const std::string&) = 0;
};


#endif //FILESYSTEM_FILE_H
