/*
 * Date: 23/01/2024
 * Name: Abdimannabov Sohibjon
 */

#include <iostream>
using namespace std;

int Euler(int a, int b){
    return (a-1)*(b-1);
}

int main(){

    int a,b;
    cin>>a>>b;
    cout<<Euler(a,b);
    return 0;
}

