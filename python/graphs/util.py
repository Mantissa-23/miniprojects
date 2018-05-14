from nodegraph import NodeGraph

'''
Read format:
First line is read as the graph size. This many vertices will be added to the
new Nodegraph. The 2nd line is ignored. The remaining lines contain
an adjacencylist in the format:

vertex<tab>edge1<space>edge2<space>edge3<space>...<space>edgen

Example for 3 interconnected nodes:
3

0   1 2
1   2 0
2   0 1
'''


def importGraph(iterator):
    ng = NodeGraph()

    for i, line in enumerate(iterator):
        if i == 0:
            ng.addVertices(int(line))
        elif i > 1:
            split = line.split('\t')
            vindex = int(split[0])
            edges = split[1].split(' ')
            for edge in edges:
                ng.addEdge(vindex, int(edge))

    return ng
