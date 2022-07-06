#include <iostream>

using namespace std;

///////////////////////////////////////////////////////////////////////////////
struct Sterling {
    int pounds;
    int shilling;
    int pence;
};
///////////////////////////////////////////////////////////////////////////////

int main()
{
    Sterling sterling = {};
    double sum;
    
    cout << "Enter sum in new system:" << endl;
    cin >> sum;
    
    int i_sum = static_cast<int>(sum);
    double penny = sum - i_sum;
    
    sterling.pounds = i_sum;
    sterling.shilling = static_cast<int>(penny * 20);
    sterling.pence = static_cast<int>((penny * 20 - sterling.shilling) * 12);

    cout << "In old system: J" << sterling.pounds << '.' << sterling.shilling << '.' << sterling.pence << endl;
    
    return 0;
}
