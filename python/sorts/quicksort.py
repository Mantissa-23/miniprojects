from utils import test, swap


def lomutopartition(x, low, high):
    return high


def hoarepartition(x, low, high):
    return low


def sedgewickpartition(x, low, high):
    choices = [x[low], x[high], x[int((high - low)/2)]]
    sortedchoices = choices.copy()
    sortedchoices.sort()
    median = sortedchoices[1]
    return choices.index(median)  # This code needs to be refactored. It works, 
    # just poorly.


def quicksort(x, partition=lomutopartition):
    """ Python implementation of Hoare's Quicksort, in-place

    Sorts lists by the following algorithm:
    1. Pick a pivot (see pivot selection below)
    2. Move all items in the list below that pivot, in no particular order
    3. Reexcute this algorithm on the items below the pivot
    4. Reexecute this algorithm on the items above the pivot
    5. Return list

    Pivot selection:
    - Lomuto Partition Scheme: Pick the last item in the set as a pivot. 
    Simple, but nonideal, as it degrades to O(n^2) with an ordered/nearly 
    ordered list. Often used to teach the quicksort, not used in practice.
    - Original Hoare Method: Pick the first item in a set as the pivot. Had
    similar problems, and was more complicated to implement, but was more
    efficient.
    - Sedgewick Scheme: Take the median of the first, middle and last elements
    in a partition as the pivot. Provides the most efficient sorting without
    knowledge of the order of a set. More complicated to implement, requires
    more calculations.

    There are more partition methods, these are the ones I read about. This
    function supports using any partitioning scheme passed to it, and defaults
    to Sedgewick.

    """

    return _quicksort(x, 0, len(x)-1, partition)


def _quicksort(x, low, high, partition):
    pivot = partition(x, low, high)
    value = x[pivot]
    
    divider = low
    i = divider

    while i <= high:
        if x[i] == value:
            swap(x, i, divider)
        if x[i] < value:
            swap(x, i, divider)
            divider += 1

        i += 1

    # print(low, ", ", divider, ", ", high)
    # print(x[low:high + 1])

    if high - low < 1:
        return x
    else:
        _quicksort(x, low, _positive(divider-1), partition)
        _quicksort(x, divider+1, high, partition)

    return x


def _positive(i):
    """ Ensures that a number is bound to >= 0 """
    if i < 0:
        return 0
    else:
        return i


if __name__ == "__main__":
    test(quicksort)
