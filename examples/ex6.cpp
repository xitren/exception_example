/*!
     _ _                
__ _(_) |_ _ _ ___ _ _  
\ \ / |  _| '_/ -_) ' \ 
/_\_\_|\__|_| \___|_||_|
* @date 19.02.2024
*/

#include <exception>
#include <iostream>
#include <vector>

using namespace std;

struct demo
{
    demo() = default;
    demo(const demo &) { cout << "Copying\n"; }
    // Exception safe move constructor
    demo(demo &&) noexcept { cout << "Moving\n"; }
private:
    std::vector<int>    m_v;
};
int main()
{
    demo obj1;
    if (noexcept(demo(std::declval<demo>()))){  // if moving safe
        demo obj2(std::move(obj1));             // then move it
    }
    else{
        demo obj2(obj1);                        // otherwise copy it
    }
    demo obj3(std::move_if_noexcept(obj1));     // Alternatively you can do this----------------
    return 0;
}