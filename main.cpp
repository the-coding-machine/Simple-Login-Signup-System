#include <iostream>
#include "functions.h"
using namespace std;
int main() {
    string result;
    result = welcome();
    result = signUp_func(result);
    login_func (result);
return 0;
}


