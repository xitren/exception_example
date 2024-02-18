/*!
     _ _                
__ _(_) |_ _ _ ___ _ _  
\ \ / |  _| '_/ -_) ' \ 
/_\_\_|\__|_| \___|_||_|
* @date 18.02.2024
*/
#include "throw.h"

extern "C" {
void some_exception_func() {
    throw Exception();
}
}
