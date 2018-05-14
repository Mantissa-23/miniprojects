from utils import test, swap


def bubblesort(x):
    """ Implementation of bubble sort algorithm, in-place

    Returns list x sorted via the following steps:
    1. Begin iterating through list x
    2. If element n+1 > element n, swap them
    3. Keep iterating through the list until all elements are sorted

    """

    while True:
        isswapped = False

        for i in range(len(x) - 1):
            if x[i] > x[i + 1]:
                swap(x, i, i+1)

                if not isswapped:
                    isswapped = True

        if not isswapped:
            break

    return x


if __name__ == "__main__":
    test(bubblesort)
