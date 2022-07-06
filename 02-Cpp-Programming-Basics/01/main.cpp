#include <iostream>

using namespace std;

int main()
{
    const double GALLON_IN_FOOT = 7.481;
    double gallon, foot;
    
    cout << "Enter value in gallon:";
    cin >> gallon;
    
    foot = gallon / GALLON_IN_FOOT;
    cout << gallon << " gallon is " << foot << " foot";
    
    return 0;
}
