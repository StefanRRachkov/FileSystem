//
// Created by User on 19.1.2020 г..
//

#ifndef FILESYSTEM_FILE_H
#define FILESYSTEM_FILE_H

#include <string>

// Abstract Class

class File
{
public:
    virtual std::string GetFileName() = 0;
    virtual std::string GetContent() = 0;
    virtual void SetContent(std::string) = 0;
    virtual bool Create(const std::string&) = 0;
    virtual bool Delete(const std::string&) = 0;

    inline ~File() = default;
};


#endif //FILESYSTEM_FILE_H
