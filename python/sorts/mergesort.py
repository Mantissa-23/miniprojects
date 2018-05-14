from utils import test


def mergesort(l):
    """ Implementation of the mergesort algorithm, not in-place

    Sorts list l by the following steps:
    1. Look at list l. If the length is less than 2 (either 1 or 0), return the
    list, as it must be sorted.
    2. If the list is longer than two, split it in half, and sort each half
    independently starting at step 1.
    3. Merge the two halves via the included merge function
    4. The final, merged list will be sorted.

    """

    if len(l) < 2:
        return l
    else:
        midpoint = int(len(l)/2)

        left = l[:midpoint]
        right = l[midpoint:]

        left = mergesort(left)
        right = mergesort(right)

        return merge(left, right)


def merge(left, right):
    """ Merge two lists by the following method:

    1. Begin iterating through both halves simultaneously
    2. Compare the currently indexed value of each half
    3. Add the smaller value to the final, merged list, increment 

    """
    worklist = []

    lindex = 0
    rindex = 0

    while lindex < len(left) and rindex < len(right):
        if left[lindex] > right[rindex]:
            worklist.append(right[rindex])
            rindex += 1
        else:
            worklist.append(left[lindex])
            lindex += 1

    # It is necessary to append the remainder of the lists to the end of the
    # worklist because we used `and` instead of `or` for the loop's 
    # conditional. Using `or` would be more concise, but less efficient.
    worklist += left[lindex:]
    worklist += right[rindex:]

    return worklist


if __name__ == "__main__":
    test(mergesort)
