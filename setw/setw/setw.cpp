#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
    int a(10), b(10);
    //set left Justified
    cout << left;
    cout << setw(6) << a 
		 << setw(7) << b
         << setw(7) << "water" << endl;
    cout << setfill('*');
    cout << setw(6) << a 
		 << setw(7) << b
         << setw(7) << "water" << endl;
    cout << setw(6) << a 
		 << setw(7) << setfill('&') << b
         << setw(7) << "water" << endl;
    cout << setw(6) << setfill('^') << a
         << setw(7) << setfill('%') << b
         << setw(7) << setfill('$') << "water" << endl;
    //set right Justified
    cout << right;
    cout << setfill(' ');
    cout << setw(6) << a 
		 << setw(7) << b
         << setw(7) << "water" << endl;
    
	system("pause");
    return 0;
}