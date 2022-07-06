#include <iostream>

using namespace std;

int main()
{
    signed int a, c;
    unsigned int b, d;
    char slash;
    
    cout << "Enter first fraction:";
    cin >> a >> slash >> b;
    cout << "Enter second fraction:";
    cin >> c >> slash >> d;
    
    cout << a << '/' << b << " + " << c << '/' << d << " = "
         << a*d+c*b << '/' << b*d << endl;
    
    return 0;
}
