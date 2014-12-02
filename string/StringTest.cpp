#include "String.h"
#include <gtest/gtest.h>

using namespace jia;

TEST(StringTest, SmallTest) {
    String s1;
    String s2;

    EXPECT_EQ(s1, s2);
}

TEST(StringTest, StringCon) {
    //String()
    String s1;
    EXPECT_EQ(s1, "");
    EXPECT_EQ(true, s1.empty());

    //String(char *)
    char *ch = NULL;
    String s2(ch);
    EXPECT_EQ(s2, "");
    String s3("");
    EXPECT_EQ(s3, "");
    String s4("123");
    EXPECT_EQ(s4, "123");

    //String(String&)
    String s5(s1);
    EXPECT_EQ(0, s5.length());
    String s6(s4);
    EXPECT_EQ(3, s6.length());
}

TEST(StringTest, OperatorAsign) {
    //=(char *)
    String s1;
    char *ch = NULL;
    s1 = ch;
    EXPECT_EQ(0, s1.length());
    s1 = "";
    EXPECT_EQ(0, s1.length());
    s1 = "123";
    EXPECT_EQ(3, s1.length());
    s1 = "123";
    EXPECT_EQ(3, s1.length());
    s1 = ch;
    EXPECT_EQ(0, s1.length());
    s1 = "123";
    s1 = "";
    EXPECT_EQ(0, s1.length());

    //=(String&)
    String s2;
    String s3("123");
    s2 = s2;
    EXPECT_EQ(0, s2.length());
    s2 = s3;
    EXPECT_EQ(3, s2.length());
    s2 = s2;
    EXPECT_EQ(3, s2.length());
    s2 = s1;
    EXPECT_EQ(0, s2.length());
}

TEST(StringTest, SubString) {
    String s1("1234567");

    String s2 = s1.substr(0, 7);
    EXPECT_EQ(s2, "1234567");

    String s3 = s2.substr(7, 0);
    EXPECT_EQ(s3, "");

    String s4 = s2.substr(2, 3);
    EXPECT_EQ(s4, "345");

    s3 = s1.substr(4,1);
    EXPECT_EQ(s3, "5");

    s4 = s1.substr(4,0);
    EXPECT_EQ(s4, "");
}

TEST(StringTest, AddOperator) {
    String s1;
    String s2;

    s1 += s2;
    EXPECT_EQ(s1, "");
    s1 = s1+s2;
    EXPECT_EQ(s1, "");

    String s3("123");
    String s4("456");
    
    s3 += s4;
    EXPECT_EQ(s3, "123456");
    s3 = s3+s4;
    EXPECT_EQ(s3, "123456456");
    s3 = s1+s4;
    EXPECT_EQ(s3, "456");
    s1 += s4;
    EXPECT_EQ(s1, "456");

    //clear
    s1.clear();
    EXPECT_EQ(s1, "");
}
