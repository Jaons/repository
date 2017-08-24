#include <iostream>
using namespace std;

struct test {
    char    a;
    int   b;
    short   bb;
    int     c;
    char    d;
    short   e;
    short   ee;
};

void test_func()
{
    char    *str1 = "123";
    char    *str2 = "123";
    const char    *str3 = "123";
    const char    *str4 = "123";
    char    str5[] = "123";
    char    str6[] = "123";
    const char str7[] = "123";
    const char str8[] = "123";


    cout << (str1 == str2) << endl;
    cout << (str3 == str4) << endl;
    cout << (str5 == str6) << endl;
    cout << (str5 == str7) << endl;
    
    
    return ;
}

int main(int argc, char** argv)
{
    char    *str1 = "123";
    char    *str2 = "123";
    const char    *str3 = "123";
    const char    *str4 = "123";
    char    str5[] = "123";
    char    str6[] = "123";
    const char str7[] = "123";
    const char str8[] = "123";

    test    test1;

    test_func();

    cout << (str1 == str2) << endl;
    cout << (str3 == str4) << endl;
    cout << (str5 == str6) << endl;
    cout << (str5 == str7) << endl;
    
    cout << sizeof(test1) << endl;

    return 0;
}
