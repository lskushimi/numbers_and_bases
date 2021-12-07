// Copyright 2021 Landon Kushimi lsk1801@bu.edu

#include <string>
#include <vector>

// Takes the input

std::vector<int> convertBase(int input, int inputBase) {
  std::vector<int> v;
  while (input > 0) {
    v.push_back(input % inputBase);
    input /= inputBase;
  }
  return v;
}

// Function returns 0 or 1 depending on convergence

unsigned int heavy(std::vector<int> v) {
  unsigned int sum = 0;
  for (int i = 0; i < v.size() ; i++) {
    sum += v.at(i) * v.at(i);
  }
  return sum;
}

// Main function

int main(int argc, char *argv[]) {
  // Predefine inputs
  int inputNum = std::stoi(argv[1], nullptr, 10);
  int inputBase = std::stoi(argv[2], nullptr, 10);
  int count = 0, flag = 0, output;
  std::vector<int> v {convertBase(inputNum, inputBase)};
  while (flag == 0) {
    unsigned int sum = heavy(v);
    if (sum == 1) {
      output = 1;
      flag = 1;
    }
    if (sum != 1) {
      v = convertBase(sum, inputBase);
      count++;
      if (count == 10000) {
        flag = 1;
        output = 0;
      }
    }
  }
  return output;
}