#ifndef WORD32_H
#define WORD32_H
#include <ostream>
#include "byte.h"

using namespace std;

class Word32 {
 public:
    Word32();
    Word32(const Word32 &obj);
    Word32(unsigned w0, unsigned w1, unsigned w2, unsigned w3);
    Word32(Byte b0, Byte b1, Byte b2, Byte b3);
    ~Word32();


    Byte getByte(const unsigned i) const;

    Word32 operator&(const Word32 other);
    Word32 operator|(const Word32 other);
    Word32 operator^(const Word32 other);
    bool operator==(const Word32 other) const;
    bool operator!=(const Word32 other) const;

    friend ostream &operator<<(ostream &out, Word32  w); 

 private:
    Byte _word32[4];
};

#endif
