/*!
     _ _                
__ _(_) |_ _ _ ___ _ _  
\ \ / |  _| '_/ -_) ' \ 
/_\_\_|\__|_| \___|_||_|
* @date 19.02.2024
*/

#include <iostream>

struct demo
{
    demo() = default;
    demo(demo &&) = delete;
    demo(const demo &) = delete;
};

int main()
{
    try {
        throw demo{};
    } catch (demo& ex) {
        std::cout << "Exception caught " << std::endl;
    }
    return 0;
}
