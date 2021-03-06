//
// Created by alejandrofrech on 08-23-16.
//

#ifndef SISO2_DIRECTORY_H
#define SISO2_DIRECTORY_H

#include <iostream>
#include <vector>
#include <sstream>
#include <fstream>
#include "FileAttributes.h"
#include "Block.h"
#include <algorithm>

using namespace std;


class Directory {
public:
    Directory();
    FileAttributes DirectoryEntries[127];
    void Add(FileAttributes entry);
    void RenameFile(char * name,char * newName);
    FileAttributes GetFileEntry(char* name);
    void DeleteEntry(char * name);
    bool EntryExists(char * name);
    void ListFiles();
private:
    int occupied;
    void del(int index);
};


#endif //SISO2_DIRECTORY_H
