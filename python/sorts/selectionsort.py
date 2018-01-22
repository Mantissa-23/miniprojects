from utils import test, swap

def selectionsort(x):
    """ Python implementation of a selection sort, in-place

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

    #_x = x.copy()
    
    divider = 0
    last = len(x)

    while divider != last:
        lowindex = divider

        for index in range(divider, last):
            if x[index] < x[lowindex]:
                lowindex = index

        swap(x, divider, lowindex)

        divider += 1

    return x

if __name__ == "__main__":
    test(selectionsort)
