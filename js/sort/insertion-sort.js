// differenct and good things about insertion sort
// 1. build up the sort by gradually creating a larger left half which is always sorted.

/**
 * Perform insertion sort on the given array.
 *
 * @param {number[]} arr - the array to be sorted
 * @returns {number[]}
 */
function insertionSort(arr) {
  for (let i = 1; i < arr.length; ++i) {
    const cur = arr[i];
    let j = i - 1;
    for (; j >= 0 && arr[j] > cur; --j) {
      arr[j + 1] = arr[j];
      console.log(arr);
    }

    arr[j + 1] = cur;
    console.log(arr);
  }

  return arr;
}

const res = insertionSort([2, 1, 9, 76, 4]);
console.log(res);

// [1, 2, 9, 76, 4]
// [1, 2, 9, 4, 76]

// [1, 2, 4, 9, 76]
