// Merging arrays
// O(n + m) time
// O(n + m) space
// and should be pure function.
function merge(arr1, arr2) {
  const merged = [];
  let i = 0;
  let j = 0;

  while (i < arr1.length && j < arr2.length) {
    const c1 = arr1[i];
    const c2 = arr2[j];

    if (c1 < c2) {
      merged.push(c1);
      ++i;
    } else {
      merged.push(c2);
      ++j;
    }
  }

  while (i < arr1.length) {
    merged.push(arr1[i]);
    ++i;
  }

  while (j < arr2.length) {
    merged.push(arr2[j]);
    ++j;
  }

  return merged;
}

// const res = merge([1, 10, 50], [2, 14, 99, 100]);
// console.log(res);

// const res2 = merge([100], [1, 2, 3, 4, 5, 6]);
// console.log(res2);

// merge sort pseudo code
// 1. break up the array into halves until you have arrays that
//    are empty or have one element.
//
// 2. Once you have smaller sorted arrays, merge those arrays
//    with other sorted arrays until you are back at the full
//    length of the array.
//
// 3. Once the array has been merged back together, return
//    the merged (and sorted) array.

/**
 * Big O
 * Time - Best Avg Worst: O(nlogn)
 *        <decomposition> O(log n) decompositions + 
 *        <merge> O(n) comparisons per decomposition
 * Space - O(n)
 * @param {int[]} arr
 */
function mergeSort(arr) {
  if (arr.length <= 1) return arr;

  const mid = Math.floor(arr.length / 2);

  const l = mergeSort(arr.slice(0, mid));
  const r = mergeSort(arr.slice(mid));

  return merge(l, r);
}

const res = mergeSort([10, 24, 76, 73, 72, 1, 9]);
console.log(res);

// [10, 24, 76]     [73, 72, 1, 9]
// [10] [24, 76]    [73, 72] [1, 9]
// [10] [24] [76]   [73] [72] [1] [9]
// [10, 24, 76]     [72, 73] [1, 9]
//                  [1, 9, 72, 73]
// [1, 9, 10, 24, 72, 73, 76]
