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
    
}


int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
