import warnings

'''
Generic node class. Inherit and add to NodeGraph to add data or functionality.

addEdge and removeEdge functions should never be directly called; they do not
guarantee bidirectionality in an undirected graph and do not error check.
'''


class Node:
    def __init__(self):
        self.edges = {}

    def addEdge(self, vindex, edge):
        self.edges[vindex] = edge

    def removeEdge(self, vindex):
        del self.edges[vindex]


'''
Implements AdjacencyList vertex and edge storage with a dictionary. Vertices
and edges can contain arbitrary data.


directed sets the default behaviour of edge adding and can be overriden.
'''


class NodeGraph:
    def __init__(self, directed=False, size=0, 
                 defaultNode=Node, defaultEdge=None):
        self.nodes = {}
        self.directed = directed
        self.defaultNode = defaultNode
        self.defaultEdge = defaultEdge
        self.addVertices(size)
        
    '''
    Adds vertex to graph, returns index of added vertex.

    If no node is passed, a generic one
    containing no extra data will be created.

    If the node has neighbors, the NodeGraph will attempt to add them as edges
    via the addEdge function.
    '''
    def addVertex(self, vindex=None, node=None, directed=None):
        if directed is None:
            directed = self.directed

        if node is None:
            return self._addVertex(vindex, self.defaultNode())
        else:
            nindex = self._addVertex(vindex, node)
            for neighbor in node.edges.keys():
                self.addEdge(nindex, neighbor, node.edges[neighbor], directed)

    '''
    Performs actual add, split into separate function to reduce duplicate code
    in addVertex (I guess I could've used a lambda as well).

    If vindex is None, the function finds the number of the biggest node and
    increments it by 1 to get the next index. This results in list-like
    functionality when no vindexes are specified, and is a sane default.
    '''
    def _addVertex(self, vindex, node):
        if vindex is None:
            nindex = max(self.nodes.keys(), default=-1) + 1
            self.nodes[nindex] = node
            return nindex
        else:
            if vindex in self.nodes.keys():
                warnings.warn("Vertex " + str(vindex)
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

    Note that while a default Node contains data and therefore must be
    inherited from or mimcked for replacement, the default edge class is just
    None. Anything can be used as an edge class as in the AdjacencyList
    implementation, edges contain no data.
    '''
    def addEdge(self, vindex1, vindex2, edge=None, directed=None):
        if directed is None:
            directed = self.directed
        if edge is None:
            edge = self.defaultEdge

        # Handle potential errors
        if vindex1 in self.nodes[vindex2].edges.keys():
            warnings.warn("Vertex " + str(vindex1) + " and " + str(vindex2) 
                          + " already share an edge; Edge not added.")
        # If no errors, continue adding edge
        else:
            self.nodes[vindex1].addEdge(vindex2, edge)
            if not directed:
                self.nodes[vindex2].addEdge(vindex1, edge)
    '''
    Removes edge from nodegraph between vertex 1 and vertex 2.

    If directed=true, only vertex1 will be affected. Otherwise both vertices
    will be affected.
    '''
    def removeEdge(self, vindex1, vindex2, directed=None):
        if directed is None:
            directed = self.directed

        self.nodes[vindex1].removeEdge(vindex2)
        if not directed:
            self.nodes[vindex2].removeEdge(vindex1)

    '''
    Adds number of vertices specified by count. *args and **kwargs are passed
    to the addVertex function. See addVertex for arguments.
    '''
    def addVertices(self, count, *args, **kwargs):
        for i in range(0, count):
            self.addVertex(*args, **kwargs)

    '''
    Checks if vertex 2 is a neighbor of vertex 1.

    Note: Will return false even if vertex 1 is a neighbor of vertex 2.
    '''
    def adjacent(self, vindex1, vindex2):
        return vindex2 in self.nodes[vindex1].edges.keys()

    def neighbors(self, vindex):
        return self.nodes[vindex].edges.keys()

    def nodeCount(self):
        return len(self.nodes)

    '''
    This counter does not work correctly for all cases; it only works for
    homogenous graphs; it will not work for graphs that mix directedness.
    '''
    def edgeCount(self, directed=None):
        if directed is None:
            directed = self.directed

        nedge = 0
        for node in self.nodes:
            nedge += len(node.edges)

        if not directed:
            return nedge/2
        if directed:
            return nedge


if __name__ == "__main__":
    # Bidirectional graph tests
    testgraph = NodeGraph()

    testgraph.addVertices(5)

    testgraph.addEdge(0, 1)
    testgraph.addEdge(0, 2)
    testgraph.addEdge(0, 3)
    testgraph.addEdge(0, 4)

    assert testgraph.adjacent(0, 1)
    # Test that adjacency works both ways for a bidirectional graph
    assert testgraph.adjacent(1, 0)
    assert testgraph.adjacent(0, 4)
    assert not testgraph.adjacent(4, 3)

    testgraph.removeEdge(0, 1)

    # After being deleted, an edge is no longer adjacent
    assert not testgraph.adjacent(0, 1)

    testgraph.removeVertex(0)

    # After being deleted, a vertex should have no neighbors anywhere
    assert len(testgraph.neighbors(2)) == 0

    # Adding an edge between a nonexistant vertex and an existing one should
    # not work
    try:
        testgraph.addEdge(0, 4)
    except KeyError:
        pass

    # Directed graph tests
    directionalgraph = NodeGraph(directed=True)
    directionalgraph.addVertices(3)

    directionalgraph.addEdge(0, 1)
    directionalgraph.addEdge(1, 2)
    directionalgraph.addEdge(2, 0)

    assert directionalgraph.adjacent(0, 1)
    assert not directionalgraph.adjacent(1, 0)
    assert len(directionalgraph.neighbors(1)) == 1

    print("All tests passed.")
