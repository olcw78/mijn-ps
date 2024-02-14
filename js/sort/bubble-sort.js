// this sort where the largest value bubble up to the top.
// Best - O(N)
// AVG, WORST - O(N^2)

function bubbleSortAsc(arr) {
  for (let i = 0; i < arr.length; ++i) {
    for (let j = 0; j < arr.length; ++j) {
      console.log(arr, arr[j], arr[j + 1]);
      if (arr[j] > arr[j + 1]) {
        const t = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = t;
      }
    }
  }
  return arr;
}

function bubbleSortAscImprv(arr) {
  for (let i = arr.length; i > 0; --i) {
    // 맨 뒤의 원소들은 이미 오름차순으로 정렬이 완료되어 검사할 필요 없음.
    for (let j = 0; j < i - 1; ++j) {
      console.log(arr, arr[j], arr[j + 1]);
      if (arr[j] > arr[j + 1]) {
        // const t = arr[j];
        // arr[j] = arr[j + 1];
        // arr[j + 1] = t;
        [arr[j], arr[j + 1]] = [arr[j + 1], arr[j]]; // es2015 swap
      }
    }
  }
  return arr;
}

function bubbleSortAscImprv2(arr) {
  let noSwaps = false;
  for (let i = arr.length; i > 0; --i) {
    noSwaps = true;
    for (let j = 0; j < i - 1; ++j) {
      console.log(arr, arr[j], arr[j + 1]);
      if (arr[j] > arr[j + 1]) {
        const t = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = t;

        noSwaps = false;
      }

      if (noSwaps) break;
    }
  }
  return arr;
}

console.log("sorted!", bubbleSortAscImprv2([8, 1, 2, 3, 4, 5, 6, 7]));
// 37, 45, 29, 8
// 37, 29, 8, 45
// 29, 8, 37, 45
// 8, 29, 37, 45
