#include <iostream>
using namespace std;

extern int add(int x, int y);

int main(int argc, char **argv)
{
    int result = add(3, 4);
    cout << result << endl;
    return 0;
}
