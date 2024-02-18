/*!
     _ _                
__ _(_) |_ _ _ ___ _ _  
\ \ / |  _| '_/ -_) ' \ 
/_\_\_|\__|_| \___|_||_|
* @date 19.02.2024
*/

#include <exception>

struct demo
{
    ~demo() { throw std::exception{}; }
};

int main() {
    try {
        demo d;
    }
    catch (const std::exception &) {}
    return 0;
}