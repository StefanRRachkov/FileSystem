
#ifndef FILESYSTEM_COMMAND_H
#define FILESYSTEM_COMMAND_H

#include <string>
#include <sstream>
#include <algorithm>
#include <vector>

class Command {
    protected:
        std::string message;
    public:
        inline Command() = default;

        virtual bool Execute(std::string) = 0;
        std::string GetMessage();

        inline ~Command() = default;
};


#endif //FILESYSTEM_COMMAND_H
