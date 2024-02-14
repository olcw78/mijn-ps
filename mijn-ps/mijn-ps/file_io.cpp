// fstream
// file 을 stream 으로

#include <fstream>
#include <iostream>
#include <string>

void _file_io() {

  //   std::ifstream in("test.txt"); // C++ 은 C 와 다르게 fclose 직접 해줄
  //   필요가 없당. std::string s;

  //   if (in.is_open()) {
  //     in >> s;
  //     std::cout << "파일에 읽은 문자열: " << s << std::endl;
  //   } else {
  //     std::cout << "파일 읽기 실패" << std::endl;
  //   }
  //

  std::ifstream in("test.txt", std::ios::binary);
  std::string s;

  int x;
  if (in.is_open()) {
    in.read(reinterpret_cast<char*>(&x), 4);
    std::cout << std::hex << x << std::endl;
  } else {
    std::cout << "파일을 찾을 수 없습니다." << std::endl;
  }
}
