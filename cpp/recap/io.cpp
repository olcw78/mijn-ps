#include <ios>
#include <iostream>
#include <istream>
#include <string>

// c++ 의 모든 io 클래스는 ios_base 기반.
// 스트림의 입출력 형식 관련 데이터 처리.
//
// ios 클래스.
// 실제로 stream buffer 를 초기화.
// 그 외에도, 입출력 작업의 상태를 처리. 파일의 끝? eof().
// 입출력 작업을 잘 수행할 수 있는지? good()
//
// istream 클래스
// 입력을 수행.
// operator>> 가 정의됨.
// cin 은 istream 클래스의 객체 중 하나.
int main() {
  // 기본적인 cin cout 예시
  //   std::string s;
  //   while (true) {
  //     std::cin >> s;
  //     std::cout << "word: " << s << std::endl;
  //   }

  // 인풋으로 받은 타입이 달라 오류 발생..
  //   int t;
  //   while (1) {
  //     std::cin >> t;
  //     std::cout << "입력: " << t << std::endl;
  //     if (t == 0) {
  //       break;
  //     }
  //   }
  // goodbit: 스트림에 입출력 작업이 가능한 상태.
  // badbit: 스트림에 복구 불가능한 오류 발생..
  // failbit: 스트림에 복구 가능한 오류 발생..
  // eofbit: 입력 작업 중 EOF 도달한 상태

  // 인풋으로 받은 타입이 맞지않아 오류 발생 -> failbit 가 켜짐.
  // 그리고 입력값을 받지 않고 리턴.

  // bit flag 잘 핸들링 하는 예시.
  //   int t;
  //   while (true) {
  //     std::cin >> t;
  //     std::cout << "입력: " << t << std::endl;
  //     if (std::cin.fail()) { // failbit == true || badbit == true
  //       std::cout << "제대로 입력해주세요." << std::endl;
  //       std::cin.clear();           // 플래그를 초기화
  //       std::cin.ignore(100, '\n'); // 100 만큼, '\n' 이 나올 때까지 버퍼에서
  //       무시. (비움)
  //     }

  //     if (t == 1)
  //       break;
  //   }

  //   int t;
  //   while (true) {
  //     // ios_base 는 스트림의 입출력 형식을 바꿀 수 있다!
  //     // 16진수로 바꿔 출력해보기.~.
  //     // std::cin.setf(std::ios_base::hex, std::ios_base::basefield);
  //     // std::cin >> t;
  //     // setf 없이도 간단하게 조작자 (Manipulator) 를 이용해 입력형식 변경이
  //     가능해유.
  //     // 이외에도 조작자는 std::boolalpha (1 or 0)
  //     // std::left
  //     // std::right
  //     // std::endl (\n + flush)
  //     // flush 는 버퍼에 데이터가 얼마나 있든간에 바로 출력해줌.
  //     // 등등이 있따..
  //     std::cin >> std::hex >> t;
  //     std::cout << "입력: " << t << std::endl;
  //     if (std::cin.fail()) {
  //       std::cout << "제대로 입력해주세요." << std::endl;
  //       std::cin.clear();
  //       std::cin.ignore(100, '\n');
  //     }

  //     if (t == 1)
  //       break;
  //   }

  // Streambuffer
  // 모든 입출력 객체들은 이에 대응하는 스트림 객체를 가진다. C++ 입출력
  // 라이브러리에도 대응하는 스트림 버퍼 클래스도 있는데 -> streambuf
  //
  // 화면에 입력하는 문자도 스트림을 통하고
  // 하드디스크에서 파일을 익는 것도
  // Socket 도 모두 스트림을 통해서~
  // std::string -> std::stringstream.

  // 이렇게 std::streambuf 는 스트림에 대한 가장 기본적 제어를 담당.
  // 스트림의 상태를 나타내기 위해 3포인터를 사요ㅗㅇ.
  // 1. 시작 포인터
  // 2. 다음으로 읽을 문자를 가리키고 있는 포인터 (스트림 위치 지정자).
  // 3. 버퍼의 끝 부분을 가리키는 포인터.

  // 입력 버퍼와 출력 버퍼를 구분하여 각각
  // get area, put area
  // g---, p---
  
  std::string s;
  std::cin >> s;

  char peek = std::cin.rdbuf()->snextc();
  if (std::cin.fail()) {
    std::cout << "istream failed!";
  }
  
  std::cout << "두 번쨰 단어 맨 앞 글자: " << peek << std::endl;
  std::cin >> s;
  std::cout << "다시 읽으면: " << s << std::endl;

  return 0;
}