
#include "../Headers/MetaData.h"

MetaData::MetaData( std::string index,
                    std::string size,
                    std::string type,
                    std::string lastApproach,
                    std::string lastChange,
                    std::string lastMetaChange) : index(index), size(size), type(type), lastApproach(lastApproach), lastChange(lastChange), lastMetaChange(lastMetaChange)
{

}

bool MetaData::MetaUpdate()
{
    return true;
}

void MetaData::GetMetaData()
{

}