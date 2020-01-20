#include "Headers/FileSystemRepresentator.h"

int main()
{
    auto rootDir = new Directory("../Testing/");
    FileSystemNode* root = new FileSystemNode(rootDir, DIR, "../Testing/", nullptr);
//    root->AddChild("folder1", DIR);
//    root->AddChild("test.txt", TXT);

    FileSystemRepresentator fs(root);
    fs.Start();
    return 0;
}