#include <iomanip>
#include <cassert>
#include <sstream>
#include "byte.h"
#include <iostream>

Byte::Byte(){
    _byte = 0x0; //initialised to hex 0
}

Byte::Byte(const Byte &obj){
    _byte = obj._byte;
}

Byte::Byte(unsigned  i){ 
    _byte = i;
}

Byte::Byte(string str){
    assert(str.length() == 2) ; 
    stringstream ss;
    ss<<hex<<str;
    unsigned tmp;
    ss>> tmp;
    _byte = tmp;
}

Byte::~Byte(){}



Byte Byte::mSNibble() const{
    return Byte(_byte>>4);
}

Byte Byte::lSNibble()const {
    return Byte(_byte & 0x0f );
}

unsigned Byte::asUint() const{
    return _byte;
}
 
Byte Byte::operator*(const Byte other){
    return Byte (_byte * other._byte ); 
}

 
Byte Byte::operator+(const Byte other){
    return Byte (_byte + other._byte ); 
}
 
Byte Byte::operator+=(const Byte other){
    return Byte (_byte += other._byte ); 
}
 
Byte Byte::operator&(const Byte other){
    return Byte (_byte & other._byte ); 
}

Byte Byte::operator|(const Byte other){
    return Byte (_byte | other._byte ); 
}

Byte Byte::operator^(const Byte other){
    return Byte (_byte ^ other._byte ); 
}

bool Byte::operator==(const Byte other) const{
    return(_byte == other._byte);
    //
}



ostream &operator<<(ostream &out, Byte b) {
     out<<hex<<std::setfill('0') << std::setw(2)<<b._byte;
    return out;
}


vector<Byte> str2bytevec(string str){
    
    assert(str.length() % 2 == 0 ) ; //only even length accepted

    vector<Byte> res;
    
    for(string::iterator it = str.begin(); it != str.end(); it += 2){
      
        char temp[3];
        temp[2] = '\0';

        copy(it,it+2, temp);
        res.push_back(Byte(string(temp)));
    }
    return res;
    
}
