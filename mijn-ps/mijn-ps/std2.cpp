// 연관 컨테이너 (Associative Container)

// 원소 자체를 보관하는거에 중점을 둔 연속 컨테이너와는 다르게,
// 다른 종류의 컨테이너인 연관 컨테이너.

// key, value 구조.
// key 가 존재하나요? -> set, multiset
// key 가 존재하나요? 그리고 그 값은 무엇인가요? -> map, multimap

#include <iostream>
#include <set>
template <typename T> void print_set(std::set<T> &sref) {
  std::cout << "[ ";
  for (const auto &i : sref) {
    std::cout << i << " ";
  }
  std::cout << "]" << std::endl;
}

#include <map>
template <typename K, typename V> void print_map(std::map<K, V> &mref) {
  for (const auto &kvp : mref) {
    std::cout << kvp.first() << " " << kvp.second() << std::endl;
  }
}

void _set() {
  std::set<int> s;
  s.insert(10);
  s.insert(50);
  s.insert(20);
  s.insert(30);
  s.insert(40);

  std::cout << "순서대로 정렬되서 나온다" << std::endl;
  print_set(s);

  std::cout << "20 이 s 의 원소인가요?";
  auto find_i = s.find(20);
  if (find_i != s.end()) {
    std::cout << "yes" << std::endl;
  } else {
    std::cout << "no" << std::endl;
  }

  std::cout << "25 가 s 의 원소인가요?";
  find_i = s.find(25);
  if (find_i != s.end()) {
    std::cout << "yes" << std::endl;
  } else {
    std::cout << "no" << std::endl;
  }

  // 추가, 삭제 - O(logN)
}

void _map() {
    // 데이터의 존재 유무만 궁금 -> set
    // 중복 데이터를 허락할 경우 -> multiset (insert, erase, find 모두 O(logN))
    // 데이터에 대응되는 데이터를 저장하고 싶은 경우 -> map
    // 중복 키를 허락할 경우 -> multimap (insert, erase, find 모두 O(logN))
    // 속도가 매우 중요해서 최적화를 해야할 경우 -> unordered_set, unordered_map
    //    (insert, erase, find 모두 O(1), WORST O(N))
}

//int main() {
//  _set();
//
//  return 0;
//}
