import AIE
import game

# A Simple Script that handles AI pathfinding
# Created by Vinessa Mayer April 2014

class AStar:
	
	def __init__(self, _level):

		unsorted_list = _level.tile_list #clones the list of tiles for use as an unsorted list so we don't break stuff.
		open_list = [] # a list of nodes that are adjasent to the current node.
		black_list = [] # a list of nodes that have already been searched.
		calc_list = [] # this list holds the results of calculating the stepping stone node.

		current_node = 0 # variable to store where we currently are.
		goal_node = 0 # variable to store our destination.
		stepping_stone = 0 # variable to store next best node to walk in.


	def resolveGridSquare(xPos, yPos): #figures out the position of the node on the grid
		xGridPos = math.floor(xPos/self.tileSize['width'])
		yGridPos = math.floor(yPos/self.tileSize['height'])
		return (yGridPos * _level.levelWidth) + xGridPos

	def identifyClickedNode(): #Does the math to identify which node we clicked
		global _level
		global _entity
		mouseX, mouseY = AIE.GetMouseLocation()
		tileIndex = int(_level.resolveGridSquare(mouseX, mouseY))
		return tileIndex

	def identifyOccupiedNode(): #does the math to identify with node we are currently on
		global _level
		global _entity
		tankX, tankY = _entity.getposition()
		tileIndex = int(_level.resolveGridSquare(tankX, tankY))
		return tileIndex

	def setStartNode(): # assigns the start node to the global variable and adds it to the open list
		global _level
		global _entity
		start_node = IdentifyOccupiedNode()
		open_list.append(start_node)
		unsorted_list.remove(start_node) #removes the node from the unsorted list so it won't be checked again

	def setGoalNode():
		global _level
		global _entity
		goal_node = identifyClickedNode()
		#open_list.append(goal_node) I don't believe the goal should be on the open list, or else it will be sent to the blacklist too early.


	def identifySurroundingNodes(): #identifies which nodes are surrounding the current node by Offest and places them on the open_list
		global _level
		global _entity

		for node in _level.tile_list:
			node.xGridPos = math.floor(xPos/self.tileSize['width'])
			node.yGridPos = math.floor(yPos/self.tileSize['height'])
			if node.fabs(node.xGridPos - current_node.xGridPos) <= _level.tileSize['width'] or node.fabs(yGridPos - current_node.yGridPos) <= _level.tileSize['height']:
				open_list.append(node)
				print "adding node " + _level.tile_list[node] + " to the OPEN LIST"

			else:
				print "node " + _level.tile_list[node] + " is not eligible for the open_list yet. "



	def calculateCost(): #calculates the cost of each node and places them on the calc list.
		global _level
		global _entity

		for node in self.open_list:
			node.xGridPos = math.floor(xPos/self.tileSize['width'])
			node.yGridPos = math.floor(yPos/self.tileSize['height'])

			goal_node.xGridPos = math.floor(xPos/self.tileSize['width'])
			goal_node.yGridPos = math.floor(yPos/self.tileSize['height'])

			calc_list.append(node.fabs(node.xGridPos - goal_node.xGridPos))
			calc_list.append(node.fabs(node.yGridPos - goal_node.yGridPos))

		
	def determineBestNode(): #calculates which node on the open list is closest to the end node and places all other nodes on the closed_list
		global _level
		global _entity

		self.calculateCost()
		calc_list.sort() #puts the lowest number (cheapest cost) node in index 0

		for node in self.open_list:
			node.xGridPos = math.floor(xPos/self.tileSize['width'])
			node.yGridPos = math.floor(yPos/self.tileSize['height'])

			if node.fabs(node.xGridPos - goal_node.xGridPos) == calc_list[0]: # checks to see which node belongs to the winning number.
				self.stepping_stone = self.open_list[node] # adds the cheapest node to the stepping stone variable
			else:
				self.black_list.append(self.open_list[node]) #adds the item to the blacklist
				self.open_list.remove(self.open_list[node]) # removes the item from the open list

	def AStar():
		global _level
		global _entity

		self.setStartNode()
		self.setGoalNode()
		self.identifySurroundingNodes()
		self.determineBestNode()







