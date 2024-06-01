#include<bits/stdc++.h>
using namespace std;

int main(){
    int i = 10;
    int *p= &i;
    int *q = p;             // It is storing the p => address of "i" => Therefore q also stores the address of 'i' :)
    /*
        *p,*q,i     => Three ways to reach at the same place :)
    */
    cout << sizeof(p) << endl;
    cout << i << endl;
    cout << *p<< endl;

    i++;

    cout << "Since we are changing both the variables but we are using 2 different Paths :) => " << endl;
    cout << i << endl;
    cout <<*p << endl;

    int a = i;
    a++;            // This will not affect the value of i :) // Since location where a is stored is changed
    cout << *p << endl;
    cout << a << endl;

    i = 25;
    *p = 87;

    cout << i << endl;
    cout << *p<< endl;

    (*p)++;

    cout << *p <<endl;
    return 0;
}