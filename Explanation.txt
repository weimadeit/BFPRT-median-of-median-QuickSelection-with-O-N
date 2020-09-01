# BFPRT-median-of-median-QuickSelection-with-O-N-

Originated from QuickSort algorithm: the QuickSort Algorithm has recursive formula T(N) = 2T(N/2) + O(N), for dividing the original array into two ideally equal-sized subarray, and recursively applying QuickSort to each of them. And it could be solved that T(N) = O(NlogN);

The raw QuickSelect could achieve O(N) in average since it only processes a single subarray. The recursive formula is T(N) = T(N/2)(ideally) + O(N), and it could be solved that T(N) = O(N);
However, in case the partition is not that efficient, like the pivot is too large or small, and only several elements are segmented, the complexity will degenerate back to O(N2), so O(N) time complexity depends on the algorithm to select the pivot so that each segmentation guarantees a certain ratio (could be 80%, 70%, 60%, or whatever, but there must be a ratio) of elements is segmented.

The partition strategy is called median-of-median of five and the algorithm in total is termed as BFPRT, after the last name of the author.
The graphic demos of median strategy is provided. The principle is that while comparing all the elements to the median of median, we can always find a certain portion of elements le than that, and the same portion of elements ge than that, so the ratio could be promised.

The array will be divided into 5-element subarrays. We could have the N/5 medians by InsertionSort in O(N) since for 5 elements, the median could be obtained by constant number of comparison operations. And that also serves as the base case for recursive median_m5 function; After that, we choose the median of those N/5 medians as the pivot. For this median, we could recursively call median_m5 function and the total complexity will be O(N + N/5 + N/25 +...), still O(N);

Another caution is to pinpoint the index of the pivot, since it will be used in the QuickSelect function. The strategy is that for each 5-element group, it is easy to return the position(index) of median. Then we swap all medians to the front of the array, and imagine there are less than or equal to 5 groups, then the median-of-median is easily located by a median_m5 function call (will enter the base case, so actually by an InsertionSort);

Another thing worth notice is that in the QuickSelect function, we have to adjust the left/right cursor i/j while traversing in opposite directions and looking for the elements ge/le than the pivot, but cannot do that after swapping the elements at two sides. Because otherwise, we might be in the situation that although i have been >= j, but arr[i] is not an element le than pivot (still smaller than the pivot), then the partition will be in error.
