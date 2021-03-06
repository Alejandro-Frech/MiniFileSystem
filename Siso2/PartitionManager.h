//
// Created by alejandrofrech on 08-24-16.
//

#ifndef SISO2_PARTICIONMANAGER_H
#define SISO2_PARTICIONMANAGER_H


#include "BitMap.h"
#include "Directory.h"
#include "FileManager.h"
#include <string>

class PartitionManager {
private:
    BitMap *bitMap;
    Directory * directory;
    FileManager * fileManager;
public:
    PartitionManager();
    string PartitionName;
    int PartitionSize;
    void Export(char * fileName,char * path);
    void CreatePartition(char *name, char *size);
    void RenameFile(char*newName,char *name);
    void DeleteFile(char * name);
    void Delete(char * name);
    PartitionManager* LoadPartition(char *name);
    void CreateEmptyFile(char* name);
    void ListFiles();
    void Import(char*path,char* file);

private:
    Block  ReadBlock(string name, int position);
    BitMap ReadBitMap(string name);
    Directory  ReadDirectory(string name);
    int ReadSize(string name);
    void WriteDirectory(string partitionName,Directory * directory);
    void WriteBlock(string partitionName,Block * block,int position);
    void WriteSize(string partitionName,int size);
    void WriteBitMap(string partitionName, BitMap *bitmap);
    void ImportFile(string filePath);
    void ExportFile(char * name,char * path);


    void FreeBitMapEntryBlocks(FileAttributes name);
};


#endif //SISO2_PARTICIONMANAGER_H
