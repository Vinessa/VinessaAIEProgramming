from astar_grid import AStarGrid, AStarGridNode
from itertools import product

#Some global variables that are going to be used in this classless basefile, please note there are OO ways to pass this
#information around, which would be overall more desirable
mapinfo    = { 'width':1280, 'height':720, 'fullscreen':False, 'title':"PYTHON GAMEY GAME"  }
MouseButtons        = { 'button_one':0, 'button_two':1, 'button_three':2 }
_level              = None #none is the equivalent of nullptr in C++0x11 (or NULL in regular C++)
_entity             = None
_astar              = None
 
def PyInitialise():
    # Another option for the intialisation is to return a dictionary object however this would require 
    # a different method of parsing than PyArg_ParseTuple as the return type is a Dictionary object
    #return { 'width':1024, 'height':720, 'fullscreen':False, 'title':"Python Game Example" }
    return ( mapinfo['width'], mapinfo['height'], mapinfo['fullscreen'], mapinfo['title'] )

def make_graph(mapinfo):
    nodes = [[AStarGridNode(x, y) for y in range(mapinfo['height'])] for x in range(mapinfo['width'])]
    graph = {}
    for x, y in product(range(mapinfo['width']), range(mapinfo['height'])):
        node = nodes[x][y]
        graph[node] = []
        for i, j in product([-1, 0, 1], [-1, 0, 1]):
            if not (0 <= x + i < mapinfo['width']): continue
            if not (0 <= y + j < mapinfo['height']): continue
            graph[nodes[x][y]].append(nodes[x+i][y+j])
    return graph, nodes
 
graph, nodes = make_graph({"width": 8, "height": 8})
paths = AStarGrid(graph)
start, end = nodes[1][1], nodes[5][7]
path = paths.search(start, end)
if path is None:
    print "No path found"
else:
    print "Path found:", path