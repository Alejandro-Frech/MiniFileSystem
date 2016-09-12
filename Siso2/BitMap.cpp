//
// Created by alejandrofrech on 08-22-16.
//

#include <cmath>
#include "BitMap.h"


int BitMap::GetNextFreeSpace() {
    for(int i=0;i<Size;i++){
        if(Buffer[i]!=0) {
            unsigned int auxBit=128;
            for(int n=0;n<8;n++){
                int tmp=Buffer[i] & auxBit;
                if(tmp>0) {
                    SetFreeToOcuppied(i, n);
                    return ((8 * i) + n)+1;
                }else
                    auxBit /= 2;
            }
        }
    }
    return -1;
}

void BitMap::InitMap(int size) {
    Size=(size/1024/4)/8;
    if(Size>4092)
        Size=4092;

    for(int i=0;i<Size;i++) {
        if (i == 0)
            Buffer[i] = 31;
        else
            Buffer[i] = 255;
    }
}

unsigned char BitMap::SetOccupiedToFree(unsigned char value, int bitPos) {
    int pos=GetCharPosition(value);
    Buffer[pos]=(Buffer[pos] | (unsigned int)(128/pow(2,bitPos)));
    return Buffer[pos];
}

unsigned char BitMap::SetFreeToOcuppied(int pos, int bitPos){
    Buffer[pos]=(Buffer[pos] &~((unsigned int)(128/pow(2,bitPos))));
    return Buffer[pos];
}

int BitMap::GetCharPosition(unsigned char value) {
    for(int i=0;i<Size;i++){
        if(Buffer[i]==value){
            return i;
        }
    }
    return -1;
}

BitMap::BitMap() {
    Size=0;
}

unsigned char BitMap::Get(int pos) {
    return Buffer[pos];
}

void BitMap::FreeBlock(int positionBlock) {
    auto tmpchar = Get(positionBlock/8);
    auto bitpos = positionBlock%8;
    SetOccupiedToFree(tmpchar,bitpos-1);
}

