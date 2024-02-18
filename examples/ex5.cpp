/*!
     _ _                
__ _(_) |_ _ _ ___ _ _  
\ \ / |  _| '_/ -_) ' \ 
/_\_\_|\__|_| \___|_||_|
* @date 19.02.2024
*/

#include <exception>
#include <iostream>

void print_nested_exception(const std::exception_ptr &eptr=std::current_exception(), size_t level=0)
{
    static auto get_nested = [](auto &e) -> std::exception_ptr {
        try { return dynamic_cast<const std::nested_exception &>(e).nested_ptr(); }
        catch (const std::bad_cast&) { return nullptr; }
    };
    try{
        if (eptr) std::rethrow_exception(eptr);
    }
    catch (const std::exception &e){
        std::cerr << std::string(level, ' ') << "exception: " << e.what() << '\n';
        print_nested_exception(get_nested(e), level + 1);// rewind all nested exception
    }
}
// -----------------------------------------------------------------------------------------------
void func2(){
    try         { throw std::runtime_error("TESTING NESTED EXCEPTION SUCCESS"); }
    catch (...) { std::throw_with_nested(std::runtime_error("func2() failed")); }
}
void func1(){
    try         { func2(); }
    catch (...) { std::throw_with_nested(std::runtime_error("func1() failed")); }
}
int main()
{
    try                             { func1(); }
    catch (const std::exception&)   { print_nested_exception(); }
    return 0;
}
