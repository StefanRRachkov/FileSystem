//
// Created by User on 19.1.2020 г..
//

#ifndef FILESYSTEM_DIRECTORY_H
#define FILESYSTEM_DIRECTORY_H

#include "File.h"
#include <iostream>
#include <algorithm>
#include <vector>
#include <sstream>
#include <stdio.h>
#include <io.h>

class Directory : public File
{
private:
    std::string dirName;
public:
    inline Directory() = default;
    Directory(std::string);
    Directory(const Directory&);
    Directory& operator=(const Directory&);

    std::string GetFileName();
    std::string GetContent();
    inline void SetContent(std::string) {};
    bool Create(const std::string&);
    bool Delete(const std::string&);

    inline ~Directory() = default;
};


#endif //FILESYSTEM_DIRECTORY_H
