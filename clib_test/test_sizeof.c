#include <iostream>
using namespace std;

int main(int argc, char **argv)
{
    size_t      n;
    char        *p = "1234";
    const char  *p1 = "1234";
    char        p2[] = "1234";
    const char  p3[] = "1234";

    n = sizeof(p);
    cout << n << endl;
    n = sizeof(p1);
    cout << n << endl;
    
    cout << p << endl;
    cout << p1 << endl;
    cout << (p == p1) << endl;
    n = sizeof(p2);
    cout << n << endl;
    n = sizeof(p3);
    cout << n << endl;
    cout << p2 << endl;
    cout << p3 << endl;
    cout << (p2 == p3) << endl;
}
