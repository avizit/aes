#include <cassert>
#include <iomanip>

#include "word32.h"


Word32::Word32(){
    for(unsigned i = 0; i < 4; i++){
        _word32[i] = 0x0;
    }
}

Word32::Word32(const Word32 &obj){
    for(unsigned i = 0 ; i < 4; i++){
        _word32[i] = obj._word32[i];
    }
}

Word32::Word32(unsigned w0, unsigned w1, unsigned w2, unsigned w3){
    _word32[0] = Byte(w0);
    _word32[1] = Byte(w1);
    _word32[2] = Byte(w2);
    _word32[3] = Byte(w3);
 
    
}
Word32::Word32(Byte b0, Byte b1, Byte b2, Byte b3){
    _word32[0] = b0;
    _word32[1] = b1;
    _word32[2] = b2;
    _word32[3] = b3;

}


Word32::~Word32(){}





Byte Word32::getByte(const unsigned i) const {
    assert( i < 4);
    return _word32[i];
}

Word32 Word32::operator&(const Word32 other){
    Byte res[4];
    for(unsigned i  = 0; i < 4; i++){
        res[i] = _word32[i] & other._word32[i];
    }
    return( Word32(res[0], res[1] , res[2], res[3]));
}   


Word32 Word32::operator|(const Word32 other){
    Byte res[4];
    for(unsigned i  = 0; i < 4; i++){
        res[i] = _word32[i] | other._word32[i];
    }
    return( Word32 ( res[0], res[1] , res[2], res[3]));
}   


Word32 Word32::operator^(const Word32 other){
    Byte res[4];
    for(unsigned i  = 0; i < 4; i++){
        res[i] = _word32[i] ^ other._word32[i];
    }
    return( Word32 ( res[0], res[1] , res[2], res[3]));
}   


bool Word32::operator==(const Word32 other)const{
   
    for(unsigned i = 0; i < 4; i++){
	if(_word32[i] != other._word32[i])
	    return false;
    }
    return true;
}   

bool Word32::operator!=(const Word32 other)const{
    return(!( *this  == other ));
}   



ostream &operator<<(ostream &out, Word32  w){
    out<<hex<<std::setfill('0') << std::setw(2)<<w._word32[0]<<w._word32[1]<<w._word32[2]<<w._word32[3];
    return out;
}
