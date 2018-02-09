import warnings

'''
Generic node class. Inherit and add to NodeGraph to add data or functionality.
'''
class Node:
    def __init__(self):
        self.edges = {}

    def addEdge(self, vindex, edge=None):
        if edge is None:
            self.edges[vindex] = Edge()
        else:
            self.edges[vindex] = edge

    def removeEdge(self, vindex):
        del self.edges[vindex]

'''
Generic edge class. Inherit and add to NodeGraph to add data or functionality.
'''
class Edge:
    pass

'''
Implements AdjacencyList vertex and edge storage with a dictionary. Vertices 
and edges can contain arbitrary data.

Note: addNeighbor and removeNeighbor functions should only ever be called by
the NodeGraph, as they do not implement bidirectionality and do not error check.
'''
class NodeGraph:
    def __init__(self):
        self.nodes = {}
        
    '''
    Adds vertex to graph, returns index of added vertex.

    If no node is passed, a generic one containing no extra data will be created.

    If the node has neighbors, the NodeGraph will attempt to add them as edges
    via the addEdge function.
    '''
    def addVertex(self, vindex=None, node=None, directed=False):
        if node is None:
            return self._addVertex(vindex, Node())
        else:
            nindex = self._addVertex(vindex, node)
            for neighbor in node.edges.keys():
                self.addEdge(nindex, neighbor, node.edges[neighbor], directed)

    def _addVertex(self, vindex, node):
        if vindex is None:
            nindex = max(self.nodes.keys(), default=-1) + 1
            self.nodes[nindex] = node
            return nindex
        else:
            if vindex in self.nodes.keys():
                warnings.warn("Vertex " + vindex 
                              + " already exists. Vertex not added.")
            else:
                self.nodes[vindex] = node
                return vindex

    def removeVertex(self, vindex):
        for neighbor in self.nodes[vindex].edges.keys():
            del self.nodes[neighbor].edges[vindex]
        del self.nodes[vindex]

    '''
    Adds an edge to the nodegraph between vertex 1 and vertex 2.

    If directed=True, then vertex1 will point to vertex2, but not vice-versa.
    '''
    def addEdge(self, vindex1, vindex2, edge=None, directed=False):
        # Handle potential errors
        if vindex1 in self.nodes[vindex2].edges.keys():
            warnings.warn("Vertex " + vindex1 + " and " + vindex2 
                          + " already share an edge; Edge not added.")
        # If no errors, continue adding edge
        else:
            self.nodes[vindex1].addEdge(vindex2)
            if not directed:
                self.nodes[vindex2].addEdge(vindex1)
    '''
    Removes edge from nodegraph between vertex 1 and vertex 2.

    If directed=true, only vertex1 will be affected. Otherwise both vertices 
    will be affected.
    '''
    def removeEdge(self, vindex1, vindex2, directed=False):
        self.nodes[vindex1].removeEdge(vindex2)
        if not directed:
            self.nodes[vindex2].removeEdge(vindex1)


    '''
    Checks if vertex 2 is a neighbor of vertex 1.

    Note: Will return false even if vertex 1 is a neighbor of vertex 2.
    '''
    def adjacent(self, vindex1, vindex2):
        return vindex2 in self.nodes[vindex1].edges.keys()

    def neighbors(self, vindex):
        return self.nodes[vindex].edges.keys()

if __name__ == "__main__":
    testgraph = NodeGraph()

    for i in range(0, 5):
        testgraph.addVertex()

    testgraph.addEdge(0, 1)
    testgraph.addEdge(0, 2)
    testgraph.addEdge(0, 3)
    testgraph.addEdge(0, 4)

    assert testgraph.adjacent(0, 1)
    assert testgraph.adjacent(0, 4)
    assert not testgraph.adjacent(4, 3)

    testgraph.removeEdge(0, 1)

    assert not testgraph.adjacent(0, 1)

    testgraph.removeVertex(0)

    assert len(testgraph.neighbors(2)) == 0

    print("All tests passed.")
