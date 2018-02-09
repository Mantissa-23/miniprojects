'''
Generic edge class. Inherit and add to NodeGraph to add data or functionality.
'''

class WeightedEdge:
    def __init__(self, weight=0):
        self.weight = weight
