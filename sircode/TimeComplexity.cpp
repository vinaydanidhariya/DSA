// write how many operation can perform in one second
#include <iostream>
#include <ctime>
using namespace std;

int main()
{
    clock_t start, end;
    start = clock();
    int count = 0;
    for (int i = 0; i < 1e8; i++)
    {
        count++;
    }
    end = clock();
    cout<<"micro second: "<<(double)(end - start)<<endl;
    cout<<"nano second: "<<(double)(end - start)*1000<<endl;
    cout<<"milli second: "<<(double)(end - start)/CLOCKS_PER_SEC<<endl;
    cout<<"second: "<<(double)(end - start)/CLOCKS_PER_SEC<<endl;
    return 0;
}


// what is difff between nano second and micro second milli second and second
// 1 second = 1000 milli second
// 1 milli second = 1000 micro second
// 1 micro second = 1000 nano second
// 1 second = 1000000 micro second

// if in 1 sec 10^8 operation can be performed then
// 1. if the number of operation in your code is less than 10^8 then your code is in time constraint

// if in 1 sec 10^9 operation can be performed then

// what is max int value in c++
// 2^31 - 1 = 2147483647

// what is max long long value in c++
// 2^63 - 1 = 9223372036854775807

// what is max unsigned long long value in c++
// 2^64 - 1 = 18446744073709551615

// what is max unsigned int value in c++
// 2^32 - 1 = 4294967295

// if my program function take log(n) time then how many operation can be performed in 1 sec what is the value of n
// if the function take log(n) time then the number of operation can be performed in 1 sec is 10^8
// n = 10^8

// if my program function take n time then how many operation can be performed in 1 sec what is the value of n
// if the function take n time then the number of operation can be performed in 1 sec is 10^6

// if my program function take n^2 time then how many operation can be performed in 1 sec what is the value of n
// if the function take n^2 time then the number of operation can be performed in 1 sec is 10^4
// n = 10^4

// if my program function take n^3 time then how many operation can be performed in 1 sec what is the value of n
// if the function take n^3 time then the number of operation can be performed in 1 sec is 10^2

// if my program function take 2^n time then how many operation can be performed in 1 sec what is the value of n
// if the function take 2^n time then the number of operation can be performed in 1 sec is 20


// what is log(n) time
// example
// n = 1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024
// log(1) = 0
// log(2) = 1
// log(4) = 2
// log(8) = 3
// log(16) = 4
// log(32) = 5
// log(64) = 6
// log(128) = 7
// log(10) = 3.3219

// 2^15=

