//
//  std_algo.h
//  mijn-ps
//
//  Created by Yoonsang Lee on 2/13/24.
//

#ifndef std_algo_h
#define std_algo_h

template <typename T>
void print(T begin, T end) {
    while (begin != end) {
        std::cout << *begin << " ";
        ++begin;
    }
    std::cout << std::endl;
}


void _sort();
void _rm();

#endif /* std_algo_h */
