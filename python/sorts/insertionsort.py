from utils import test, swap


def insertionsort(x, hook=None):
    for i in range(1, len(x)):
        j = i
        while j > 0 and x[j - 1] > x[j]:
            swap(x, j, j-1)
            j -= 1
    return x


if __name__ == "__main__":
    test(insertionsort)
