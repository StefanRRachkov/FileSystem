#include "Headers/FileSystemRepresentator.h"

int main()
{
    auto file = new TxtFile("../test.txt");
    auto root = new FileSystemNode;
    root -> data = file;
    root -> parent = nullptr;
    root->AddChild("../test2.txt");

    auto treeStructure = new FileSystemStructure(root);
    FileSystemRepresentator test;
    test.PrintTree(treeStructure -> GetRoot());

    return 0;
}