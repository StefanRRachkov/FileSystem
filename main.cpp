#include "Headers/FileSystemRepresentator.h"
#include "Headers/Files/TxtFile.h"

int main()
{
    TxtFile a;
    a.Create("../Testing/test.txt");
    std::cout << a.GetFileName() << " -> " << a.GetContent() << std::endl;
    return 0;
}