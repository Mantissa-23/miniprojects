# Some boilerplate code to grab test from the parent directory
import os, sys
sys.path.insert(1, os.path.join(sys.path[0], '..'))

from test import test

def _swap(x, i, j):
    """ Swap elements of index i and j in list x """

    temp = x[i]
    x[i] = x[j]
    x[j] = temp

def bubblesort(x):
    """ Implementation of bubble sort algorithm, in-place

    Returns list x sorted via the following steps:
    1. Begin iterating through list x
    2. If element n+1 > element n, swap them
    3. Keep iterating through the list until all elements are sorted

    """

    while True:
        swap = False

        for i in range(len(x) - 1):
            if x[i] > x[i + 1]:
                _swap(x, i, i+1)

                if not swap:
                    swap = True

        if not swap:
            break

    return x

if __name__ == "__main__":
    test(bubblesort)
