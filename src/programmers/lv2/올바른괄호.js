// https://school.programmers.co.kr/learn/courses/30/lessons/12909?language=javascript

// "()()" 또는 "(())()" 는 올바른 괄호입니다.
// ")()(" 또는 "(()(" 는 올바르지 않은 괄호입니다.

// '(' 또는 ')' 로만 이루어진 문자열 s
// 문자열 s가 올바른 괄호이면 true

// 결국 올바른 괄호는 여는 괄호가 먼저 나오고 닫는 괄호가 나오는지 체크하면 되는 문제
// 여는 괄호를 만나면 count에 1을 더함
// 닫는 괄호를 만나면 count에 1을 뺌 ( 단, count가 이미 0이라면 올바르지 않은 괄호 )
// 최종적으로 모든 괄호를 체크했다면, count가 0인지 체크해서 여부판단
/**
 *
 * @param {string} s
 * @returns
 */
function solution(s) {
  let cnt = 0;
  for (let i = 0; i < s.length; ++i) {
    const c = s[i];

    if (c === "(") ++cnt;
    else if (cnt === 0) return false;
    else --cnt;
  }

  return cnt === 0;
}
