#include "Headers/FileSystemRepresentator.h"

int main()
{
    auto rootDir = new Directory("../Testing/");
    FileSystemNode* root = new FileSystemNode(rootDir, DIR, "../Testing/", nullptr);
    root -> AddChild(root -> nodePath + "test.txt", TXT);
    root -> AddChild(root -> nodePath + "output.txt", TXT);

    FileSystemRepresentator fs(root);
    fs.Start();

    delete(root);
    return 0;
}