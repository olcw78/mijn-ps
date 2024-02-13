// STL
// iostream
// chrono
// regex
//
// container: 임의 타입의 객체를 보관할 수 있는 컨테이너.
// iterator: 컨테이너에 보관된 원소에 접근할 수 있는 반복자.
// algorithm: 반복자들을 가지고 일련의 작업을 수행하는 알고리즘.

// Sequence Container
// vector
// list
// deque

// 1. vector
#include <iostream>
#include <vector>

template <class T> void print_vec(std::vector<T> &vref) {
  for (typename std::vector<T>::iterator i = vref.begin(); i != vref.end();
       ++i) {
    std::cout << *i << std::endl;
  }
}

template <class T> void print_vec2(std::vector<T> &vref) {
  for (auto const &i : vref) {
    std::cout << i << std::endl;
  }
}

void _vec() {
  std::vector<int> v;
  v.push_back(10);
  v.push_back(20);
  v.push_back(30);
  v.push_back(40);

  for (auto i = 0; i < v.size(); ++i) {
    std::cout << i + 1 << " 번째 원소: " << v[i] << std::endl;
  }

  // 임의의 위치 원소 접근 ([], at): O(1)
  // 맨 뒤에 원소 추가 or 제거 (push_back, pop_back): amortized O(1): AVG O(1),
  // WORST O(n) 임의의 위치 원소 추가 및 제거 (insert, erase): O(n)
}

void _vec_iter() {
  // 컨테이너에 원소에 접근할 수 있는 포인터와 같은 객체라고 요오오
  // 반복자는 컨테이너에 iterator 멤버 타입으로 정의되어있음.
  // vector 는 begin(), end(), cbegin(), cend()..
  // begin() == end() -> 원소가 없다.
  //
  std::vector<int> v;
  v.push_back(10);
  v.push_back(20);
  v.push_back(30);
  v.push_back(40);

  for (std::vector<int>::iterator i = v.begin(); i != v.end(); ++i) {
    std::cout << *i << std::endl;
  }

  std::vector<int>::iterator it = v.begin() + 2;
  std::cout << "3 번째 원소: " << *it << std::endl;

  std::cout << "insert\n";
  v.insert(v.begin() + 2, 15); // v[2] 옆에 15 추가
  print_vec(v);

  std::cout << "erase\n";
  v.erase(v.begin() + 3);
  print_vec(v);
}

// double-linked list
#include <list>
void _list() {
  std::list<int> l;
  l.push_back(10);
  l.push_back(20);
  l.push_back(30);
  l.push_back(40);

  // list 는 BidirectionalIterator 로
  // vector 의 RandomAccessIterator
}

#include <deque>
void _deque() {
  // 1. 일반적인 상황에서는 그냥 벡터
  // 2. 만약에 맨 끝이 아닌 중간에 원소들을 추가하거나 제거하는 일을 많이 하고,
  //    원소들을 순차접근만 하면 리스트
  // 3. 맨 처음과 끝 모두에 원소들을 추가하는 작업을 많이 하면 덱

  // vector 와 다르게 insert, erase 에서 O(1) 의 속도.
  // -> 복사를 수행하는 vector,
  // -> 단순히 추가 원소를 넣고 나머지는 변경없는 deque.
}

int main() {
  //   _vec();
  // _vec_iter();
  _list();

  return 0;
}