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
    3. Return the smallest value on the right side compared to all the others
    4. Swap that value with the first value in the unsorted list (the divider)

    """
    
    divider = 0
    last = len(x)

    while divider != last:
        lowindex = divider

        for index in range(divider, last):
            if x[index] < x[lowindex]:
                lowindex = index

        _swap(x, divider, lowindex)

        divider += 1

if __name__ == "__main__":
    tests = [
        [5, 7, 1, 9, 89, 15, 14, 2],
        [False, True, False, True],
        ['z', 'x', 'u', 'i', 'o', 'z', 'r', 'a', 'b'],
        ['grape', 'orange', 'apple', 'zebra']
    ]

    for testlist in tests:
        testsort = testlist.copy()
        print("Unsorted: ", testsort)
        selectionsort(testsort)
        print("Sorted: ", testsort, "\n")

        stdsort = testlist.copy()
        stdsort.sort()

        assert stdsort == testsort, "Test list " + testlist + " was not sorted correctly by selectionsort"
        
    print("All tests passed")
