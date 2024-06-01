#include<bits/stdc++.h>
using namespace std;


int main(){
    int i = 10;          // Allocation of memory
    cout << &i << endl;         // Returns the address where our variable is stored :)
    int*p = &i;                 // Memory has been used for p also => therefore entry of p in symbol table
    cout << "Size of Memory Allocated for p: " << sizeof(p) << endl;    // It varies from system to system :_
    cout << p << endl;          // In p we had introduced address of "i"
    cout << *p<< endl;          // Dereferencing the pointer

    /*
        We can access the adrress from :
            i) Pointer or from variable itself
    */

    float f = 10.2;
    float *pf = &f;             // Float pointer
    cout << pf << endl;
    
    double d = 122.32;
    double *pd = &d;            // Double Pointer
    cout << pd << endl;

    return 0;
}
