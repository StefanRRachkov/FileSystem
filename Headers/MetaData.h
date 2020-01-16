
#ifndef FILESYSTEM_METADATA_H
#define FILESYSTEM_METADATA_H

#include <string>

class MetaData
{
    private:
        std::string index;
        std::string size;
        std::string type;
        std::string lastApproach;
        std::string lastChange;
        std::string lastMetaChange;
    public:
        MetaData(std::string,
                 std::string,
                 std::string,
                 std::string,
                 std::string,
                 std::string);

        bool MetaUpdate();
        void GetMetaData();

        ~MetaData() = default;
};

#endif //FILESYSTEM_METADATA_H
