#include <iostream>
#include <cassert>

#include "byte.h"
#include "word32.h"
#include "aes.h"

int main(){

    Byte a("0a");
    vector<Byte> test = str2bytevec("0a0b");
    cout<<a<<endl;
    AES myaes;
    return 0;
    
}
