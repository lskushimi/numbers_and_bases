// Copyright 2021 Landon Kushimi lsk1801@bu.edu

#include <iostream>
#include <cstdint>
using namespace std;

// Divisor sum function
// Takes user input, halves it, and loops through finding any divisors which leave no remainder
// Adds each divisor to running sum, and prints each divisor as they are found

void divisorSum() {
  while(true) {
    int flag = 0;
    int num;
    cin >> num;
    cout << num << ": ";
    if (num == 0) {
      return;
    }
    int newNum = num / 2;
    unsigned int runSum = 0;

    for(int i = 1; i <= newNum; i++) {
      if (num % i == 0) {
        if (flag == 1) {
          cout << "+";
        }
        runSum = runSum + i;
        cout << i;
        flag = 1;
      }
    }
    cout << " = " << runSum << endl;
  }
}

//Main function
int main() {
  divisorSum();
}