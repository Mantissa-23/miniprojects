# Some boilerplate code to grab test from the parent directory
import os, sys
sys.path.insert(1, os.path.join(sys.path[0], '..'))

from test import test

def _swap(x, i, j):
    """ Swaps the position of elements i and j in list x """

    temp = x[j] # Store element j for later use
    x[j] = x[i]
    x[i] = temp


def selectionsort(x):
    """ Python implementation of a selection sort

    Sorts lists by the following algorithm:
    1. Index a divider that separates the list into:
        - A sorted left side
        - An unsorted right side
        - Note: In this implementation, the divider indicates the first item in
        the unsorted portion of the list.
    2. Iterate through the entire right side
    3. Find the smallest value on the right side compared to all the others
    4. Swap that value with the first value in the unsorted list (the divider)
    5. Return the list once the unsorted section no longer has values

    """

    _x = x.copy()
    
    divider = 0
    last = len(_x)

    while divider != last:
        lowindex = divider

        for index in range(divider, last):
            if _x[index] < _x[lowindex]:
                lowindex = index

        _swap(_x, divider, lowindex)

        divider += 1

    return _x

if __name__ == "__main__":
    test(selectionsort)
