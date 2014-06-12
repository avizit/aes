#include <iostream>
#include <cassert>
#include <vector>


#include "gtest/gtest.h"

#include "byte.h"
#include "word32.h"
#include "aes.h"

namespace {
    class ByteTest : public ::testing::Test{
    protected:
        ByteTest(){
        }

        virtual ~ByteTest(){}

        virtual void SetUp(){
        
       
           
        }
        virtual void TearDown() {
            // Code here will be called immediately after each test (right
            // before the destructor).
        }

        // Objects declared here can be used by all tests in the test case for Foo.
    };

    TEST_F(ByteTest, ConstTest){
        EXPECT_EQ(2,2);
    }
    
    TEST_F(ByteTest, Str2bytevecTest){
        string str("abcd12");
        vector<Byte> v;
        v.push_back(Byte(0xab));v.push_back(Byte(0xcd));v.push_back(0x12);
        
        EXPECT_EQ(v , str2bytevec(str));
    }


    class AESTest : public ::testing::Test{
    protected:
        AESTest(){
        }

        virtual ~AESTest(){}

        virtual void SetUp(){
	    myaes.setKey("2b 7e 15 16 28 ae d2 a6 ab f7 15 88 09 cf 4f 3c");
       
           
        }
        virtual void TearDown() {
            // Code here will be called immediately after each test (right
            // before the destructor).
        }
	AES myaes;

        // Objects declared here can be used by all tests in the test case for Foo.
    };

    
    TEST_F(AESTest, SetKeyTest){

	const unsigned  uikey[16] = {0x2b, 0x7e, 0x15, 0x16, 0x28,  0xae,  0xd2,  0xa6, 0xab, 0xf7, 0x15, 0x88, 0x09, 0xcf, 0x4f, 0x3c};
	vector<Byte> bkey;
	for(unsigned i = 0; i < 16 ; i++){
	    bkey.push_back(Byte(uikey[i]));
	}
        
	EXPECT_EQ(myaes.getKey() , bkey);
    }

    TEST_F(AESTest, KeyExpandTest){
	vector<Word32> tes = myaes.expandKey();
	EXPECT_EQ(tes[0] , Word32(0x2b, 0x7e, 0x15, 0x16));
	EXPECT_EQ(tes[20], Word32(0xd4, 0xd1, 0xc6, 0xf8));


    }
    
    

    
}


int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
