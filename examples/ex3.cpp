/*!
     _ _                
__ _(_) |_ _ _ ___ _ _  
\ \ / |  _| '_/ -_) ' \ 
/_\_\_|\__|_| \___|_||_|
* @date 19.02.2024
*/

#include <iostream>

using namespace std;

struct base
{
    base() { cout << "base\n"; }
    ~base() { cout << "~base\n"; }
};

struct derive : base
{
    derive() = default;
    derive(int) : derive{}
    {
        cout << "derive\n";
        throw - 1;
    }
    ~derive() { cout << "~derive\n"; }
};

int main()
{
    try{
        derive{0};
    }
    catch (...){}
    return 0;
}