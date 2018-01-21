def msort3(x):
    result = []
    if len(x) < 2:
        return x
    mid = int(len(x) / 2)
    y = msort3(x[:mid])
    z = msort3(x[mid:])
    i = 0
    j = 0
    while i < len(y) and j < len(z):
        if y[i] > z[j]:
            result.append(z[j])
            j += 1
        else:
            result.append(y[i])
            i += 1
    result += y[i:]
    result += z[j:]
    return result
if __name__ == "__main__":
    testlist = [37, 24, 66, 77, 10, 1, 5, 7, 2, 89, 106, 55]

    print(msort3(testlist))
