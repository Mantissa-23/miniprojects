def mergesort(l):
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
    workarray = []

    lindex = 0
    rindex = 0

    while lindex < len(left) and rindex < len(right):
        if left[lindex] > right[rindex]:
            workarray.append(right[rindex])
            rindex += 1
        else:
            workarray.append(left[lindex])
            lindex += 1

    workarray += left[lindex:]
    workarray += right[rindex:]

    return workarray

if __name__ == "__main__":
    testlist = [37, 24, 66, 77, 10, 1, 5, 7, 2, 89, 106, 55]

    print(mergesort(testlist))
