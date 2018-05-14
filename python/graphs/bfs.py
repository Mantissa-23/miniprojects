import fileinput

from util import importGraph


def bfsTree(ng, startingNode, debug=False):
    # bfsTree = NodeGraph(directed=True, size=ng.edgeCount())
    visited = []

    stack = []
    stack.append(startingNode)

    while len(stack) > 0:
        v = stack.pop()

        if v not in visited:
            if debug:
                print(v)
            visited.append(v)
            stack += ng.neighbors(v)


if __name__ == "__main__":
    data = fileinput.input()
    ng = importGraph(data)
    bfsTree(ng, 0, debug=True)
