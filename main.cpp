#include "Headers/FileSystemRepresentator.h"
#include "Headers/Files/TxtFile.h"
#include "Headers/Commands/Command.h"

int main()
{
    std::string steps = " > folder3";
    std::replace(steps.begin(), steps.end(), '>', ' ');
    std::vector<std::string> stepsOneByOne;
    std::stringstream ss(steps);
    std::string step;
    while(ss >> step)
    {
        stepsOneByOne.push_back(step);
    }
    for(auto a : stepsOneByOne)
    {
        std::cout << a << std::endl;
    }
    return 0;
}