#ifndef AES_H
#define AES_H
#include "byte.h"
#include "word32.h"

#include <vector>

class AES {
 public:
    AES();
    ~AES();

    vector<Byte> getKey() const;
    void setKey(std::vector<Byte> inkey);
    void setKey(std::string inkey);
    vector<Word32>  expandKey() const; 
    vector<Word32>  expandKey(const vector<Byte> key) const; 
  
  
 private:
    Byte subByte(const Byte in) const;
    Word32 subWord32(const Word32 in) const;
    Word32 rotWord32(const Word32 in) const;
    
    void  shiftRows(const Byte  in[4][4], Byte** res) const;
    void  mixColumns(const Byte in[4], Byte* res) const;

  
    static Byte SBox[16][16] ;
    static Byte C[4][4];
    Byte state[4][4];
  
    std::vector<Byte> key;

    static Byte RCon[256];
    

};


#endif

