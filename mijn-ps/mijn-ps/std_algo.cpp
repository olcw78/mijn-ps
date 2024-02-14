//
//  std_algo.cpp
//  mijn-ps
//
//  Created by Yoonsang Lee on 2/13/24.
//

#include <iostream>
#include <algorithm>
#include <vector>

#include "std_algo.h"

void _sort() {
    std::vector<int> v;
    v.push_back(5);
    v.push_back(3);
    v.push_back(1);
    v.push_back(6);
    v.push_back(4);
    v.push_back(7);
    v.push_back(2);
    
    std::cout << "voor sorting ---" << std::endl;
    print(v.begin(), v.end());
    std::sort(
              v.begin(),
              v.end(),
              [](const int& a, const int& b) -> bool { return a < b; });
    
    std::cout << "achter sorting ---" << std::endl;
    print(v.begin(), v.end());
}

void _rm() {
    std::vector<int> v;
}
