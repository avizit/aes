#ifndef AES_H
#define AES_H
#include "byte.h"
#include "word32.h"

#include <vector>

struct InterType{
    bool interCal; // is it an intermediate data calculation
    unsigned round;
    enum{ AFT_SUBBYTES, AFT_SHIFTROWS, AFT_MIXCOLS, AFT_ADDKEY} stage;
};



class AES {
 public:
    AES();
    ~AES();

    vector<Byte> getKey() const;
    void setKey(std::vector<Byte> inkey);
    void setKey(std::string inkey);

    vector<Byte> getInput() const;
    void setInput(vector<Byte> in) ;
    void setInput(string inStr);
 
    
    vector<Word32>  expandKey() const; 
    vector<Word32>  expandKey(const vector<Byte> key) const; 
  
    void encryptTo(InterType t, Byte* output); //encrpyt only upto a point if intermediate data is required
  
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
    std::vector<Byte> input;

    static Byte RCon[256];
    
    

};


#endif

