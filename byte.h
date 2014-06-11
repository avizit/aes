#ifndef BYTE_H
#define BYTE_H

#include <ostream>
#include <string>
#include <vector>

using namespace std;



class Byte {
 public:
    Byte();
    Byte(const Byte &obj);
    Byte(unsigned  i);
    Byte(string str);
    
    ~Byte();

    Byte mSNibble()  const;
    Byte lSNibble() const;

    unsigned asUint() const;

    Byte operator*(const Byte other);
    Byte operator+(const Byte other);
    Byte operator+=(const Byte other);
    Byte operator&(const Byte other);
    Byte operator|(const Byte other);
    Byte operator^(const Byte other);

    friend ostream &operator<<(ostream &out, Byte  b);     //output
    friend vector<Byte> str2bytevec(string str); //convert string to byte vector
 private:
    unsigned  _byte;
};

vector<Byte> str2bytevec(string str); //needed else get a not declared in scope error

#endif
