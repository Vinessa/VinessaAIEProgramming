import AIE
import game
import Pathfinding
import Level_Grid
import math

# A Simple Script that handles AI pathfinding
# Created by Vinessa Mayer April 2014
class PossibleStepNodes(object):
	def __init__(self,offset,cost):
		self.offset = offset
		self.cost = cost

class AStar(object):
	
	#def __init__(self, tileset):
	def __init__(self, levelGrid):
	global _level	
		self.unsortedNodes = levelGrid.levelTiles
		#self.unsorted_list = game._level.tile_list #clones the list of tiles for use as an unsorted list so we don't break stuff.
		self.open_list = [] # a list of nodes that are adjasent to the current node.
		self.black_list = [] # a list of nodes that have already been searched.
		self.calc_list = [] # this list holds the results of calculating the stepping stone node.

		self.current_node = 0 # variable to store where we currently are.
		self.goal_node = 0 # variable to store our destination.
		self.stepping_stone = 0 # variable to store next best node to walk in.

		#Based on tile index
		self.PossibleStepNodes = [PossibleStepNode(-(levelGrid.levelWidth + 1), 14), #diagonal_back?
							  	  PossibleStepNode(- levelGrid.levelWidth	  , 10), #flat_back?
							      PossibleStepNode(-(levelGrid.levelWidth - 1), 14), #diagonal_back?
							      PossibleStepNode(- 1 						  , 10), #flat_bottom?
							      PossibleStepNode(  1 						  , 10), #flat_top?
							      PossibleStepNode(  levelGrid.levelWidth - 1 , 14), #diagonal_front?
							      PossibleStepNode(  levelGrid.levelWidth     , 10), #flat_front?
							      PossibleStepNode(  levelGrid.levelWidth + 1 , 14)] #diagonal_front?

	def FindHCost(self, node):
		

	def resolveGridSquare(self, xPos, yPos): #figures out the position of the node on the grid
		xGridPos = math.floor(xPos/self.tileSize['width'])
		yGridPos = math.floor(yPos/self.tileSize['height'])
		return (yGridPos * _level.levelWidth) + xGridPos

	def identifyClickedNode(self): #Does the math to identify which node we clicked
		global _level
		global _entity
		mouseX, mouseY = AIE.GetMouseLocation()
		tileIndex = int(game._level.resolveGridSquare(mouseX, mouseY))
		return tileIndex

	def identifyOccupiedNode(self): #does the math to identify with node we are currently on
		global _level
		global _entity
		tankX, tankY = game._entity.getPosition()
		tileIndex = int(game._level.resolveGridSquare(tankX, tankY))
		return tileIndex

	def setStartNode(self): # assigns the start node to the global variable and adds it to the open list
		global _level
		global _entity
		start_node = self.identifyOccupiedNode()
		self.open_list.append(self.current_node)
		##self.unsorted_list.remove(self.current_node) #removes the node from the unsorted list so it won't be checked again

	#def setGoalNode(self):
		#global _level
		#global _entity
		#self.goal_node = self.identifyClickedNode()
		#open_list.append(goal_node) I don't believe the goal should be on the open list, or else it will be sent to the blacklist too early.


	#def identifySurroundingNodes(self, xPos, yPos): #identifies which nodes are surrounding the current node by Offest and places them on the open_list
		#global _level
		#global _entity
		#nonlocal node
		#for node in self.unsorted_list[node]:
			#NGridPosX = math.floor(xPos/game._level.tileSize['width'])
			#NGridPosY = math.floor(yPos/game._level.tileSize['height'])
			#if math.fabs(self.unsorted_list[node].leveltiles[node].x - self.current_node.leveltiles[current_node].x) <= game._level.tileSize['width'] or math.fabs(self.unsorted_list[node].leveltiles[node].y - self.current_node.leveltiles[current_node].y) <= game._level.tileSize['height']:
				#self.open_list.append(node)
				#print "adding node " + _level.tile_list[node] + " to the OPEN LIST"

			#else:
				#print "node " + _level.tile_list[node] + " is not eligible for the open_list yet. "



	#def calculateCost(self): #calculates the cost of each node and places them on the calc list.
		#global _level
		#global _entity

		#for node in self.open_list:
			##self.open_list = math.floor(xPos/self.tileSize['width'])
			##node.yGridPos = math.floor(yPos/self.tileSize['height'])

			##self.goal_node.xGridPos = math.floor(xPos/self.tileSize['width'])
			##self.goal_node.yGridPos = math.floor(yPos/self.tileSize['height'])

			#self.calc_list.append(self.openlist[node].fabs(self.goal_node.levelTiles[goal_node].x - self.open_list[node].Level_Grid.levelTiles[node].x))
			#self.calc_list.append(self.openlist[node].fabs(self.goal_node.levelTiles[goal_node].y - self.open_list[node].Level_Grid.leveltiles[node].x))
		
	#def determineBestNode(self): #calculates which node on the open list is closest to the end node and places all other nodes on the closed_list
		#global _level
		#global _entity

		#self.calculateCost()
		#self.calc_list.sort() #puts the lowest number (cheapest cost) node in index 0

		#for node in self.open_list:
			#node.xGridPos = math.floor(xPos/self.tileSize['width'])
			#node.yGridPos = math.floor(yPos/self.tileSize['height'])

			#if node.fabs(node.xGridPos - goal_node.xGridPos) == calc_list[0]: # checks to see which node belongs to the winning number.
				#self.stepping_stone = self.open_list[node] # adds the cheapest node to the stepping stone variable
			#else:
				#self.black_list.append(self.open_list[node]) #adds the item to the blacklist
				#self.open_list.remove(self.open_list[node]) # removes the item from the open list

	#def aStar(self):
		#global _level
		#global _entity

		#self.setStartNode()
		#self.setGoalNode()
		#self.identifySurroundingNodes(game._level.levelTiles[self.current_node].x, game._level.levelTiles[self.current_node].y)
		#self.determineBestNode()







