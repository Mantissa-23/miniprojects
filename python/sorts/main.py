import bubblesort
import insertionsort
import mergesort
import quicksort
import selectionsort

from utils import test


if __name__ == "__main__":
    testfuncs = [
        bubblesort.bubblesort,
        insertionsort.insertionsort,
        mergesort.mergesort,
        quicksort.quicksort,
        selectionsort.selectionsort
    ]

    for function in testfuncs:
        test(function, verbose=False)
