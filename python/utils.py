def test(func):
    """ Tests a sort function by comparing it to Python's builtin "Timsort." """
    
    tests = [
        [5, 7, 1, 9, 89, 15, 14, 2],
        [False, True, False, True, False, True, True, True, False, False],
        ['z', 'x', 'u', 'i', 'o', 'z', 'r', 'a', 'b'],
        ['grape', 'orange', 'apple', 'zebra'],
        [1.0, 1.1, 0.8, 0.01, -0.0001, 0.05, 0.9, 9.8, -10.2, 1.3, 4.5, -2.2]
    ]

    for testlist in tests:
        print("Unsorted: ", testlist)
        testsort = func(testlist)
        print("Sorted: ", testsort, "\n")

        stdsort = testlist.copy()
        stdsort.sort()

        assert stdsort == testsort, "Sorted list " + str(testsort) + " was not sorted correctly by " + func.__name__
        
    print("All tests passed")

def swap(x, i, j):
    """ Swaps the position of elements i and j in list x """

    temp = x[j] # Store element j for later use
    x[j] = x[i]
    x[i] = temp
