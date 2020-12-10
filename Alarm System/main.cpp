#include "alarm_system.h"
#include <iostream>
using namespace std;

int main(){

    AlarmSystem test;

    bool test1 = test.activate(123);
    bool test2 = test.activate(123);
    bool test3 = test.activate(123);
    bool test4 = test.activate(123);
    

    cout << test1 << endl;
    cout << test2 << endl;
    cout << test3 << endl;
    cout << test4 << endl; 
    
    return 0;
}




