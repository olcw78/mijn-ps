// Time Complexity - O(N^2)
// 

function swap(arr, a, b) {
  const tmp = arr[a];
  arr[a] = arr[b];
  arr[b] = tmp;
}

function selectionSort(arr) {
  for (let i = 0; i < arr.length; ++i) {
    let minPos = i;

    for (let j = i + 1; j < arr.length; ++j) {
      //   console.log(arr, arr[minPos], arr[j]);

      if (arr[minPos] > arr[j]) {
        minPos = j;
      }
    }

    if (minPos !== i) swap(arr, i, minPos);
  }

  return arr;
}

const res = selectionSort([3, 52, 12, -45, 22, -121]);
console.log(res);
