#include<bits/stdc++.h>
using namespace std;

int main(){
    int i;  cout << i << endl;
    i++;
    cout << i << endl;

    int *p = 0;                 // Never make an empty pointer Don't make like {int *p}  => Initialise pointer initially with NUll if nothing is there :_
    cout << p << endl;
    cout <<*p << endl;      // What does this mean ???
    /*
        p has some garbage -> It's storing it and we are trying to use that Garbage address     
    */
    return 0;   
}