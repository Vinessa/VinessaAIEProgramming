from example_grid import make_graph
from astar_grid import *

screenProperties	= { 'width':1280, 'height':720, 'fullscreen':False, 'title':"Python Game Example"  }
MouseButtons 		= { 'button_one':0, 'button_two':1, 'button_three':2 }
_level 				= None #none is the equivalent of nullptr in C++0x11 (or NULL in regular C++)
_entity 			= None

graph, nodes = make_graph({"width": 20, "height": 11})
paths = AStarGrid(graph)
start, end = nodes[1][1], nodes[5][7]
path = paths.search(start, end)
