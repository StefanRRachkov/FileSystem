
#ifndef FILESYSTEM_TXTFILE_H
#define FILESYSTEM_TXTFILE_H

#include "../MetaData.h"
#include "File.h"
#include <fstream>
#include <iostream>

class TxtFile : public File
{
private:
    std::string fileName;
    std::fstream file;
    std::string fileContent;
public:
    inline TxtFile() = default;
    TxtFile(const std::string&);
    TxtFile(const TxtFile&);
    TxtFile& operator=(const TxtFile&);

    std::string GetContent();
    std::string GetFileName();
    bool Create(const std::string&);
    bool Delete(const std::string&);

    ~TxtFile();
};


#endif //FILESYSTEM_TXTFILE_H
