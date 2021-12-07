// Copyright 2021 Landon Kushimi lsk1801@bu.edu

#include <iostream>
#include <string>

// Modify digits from user input

int getDigit(char c) {
  return (int)c - '0';
}

// Modify digits from base 10 converted user input

char getDigit10(int num) {
  return (char)(num + '0');
}

// Convert from starting base to base 10

int decimalConv(std::string str, int base) {
  int len = str.length();
  int power = 1;
  int num = 0;
  int i;
  for (i = len - 1; i >= 0; i--) {
    num += getDigit(str.at(i)) * power;
    power = power * base;
  }

  return num;
}

// Convert from base 10 to user desired base

std::string finalConv(int base, int inputNum) {
  std::string result = "";
  int index = 0;
  while (inputNum > 0) {
    result = getDigit10(inputNum % base) + result;
    inputNum /= base;
  }

  return result;
}

// Main function

int main(int argc, char **argv) {
  std::string input = argv[1];
  std::string startingBase = argv[2];
  std::string endingBase = argv[3];
  int intEndingBase = stoi(endingBase, nullptr, 10);
  int intStartingBase = stoi(startingBase, nullptr, 10);
  std::cout << finalConv(intEndingBase, decimalConv(input, intStartingBase)) << std::endl;
  return 0;
}