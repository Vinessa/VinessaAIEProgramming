import AIE
import game
import Pathfinding
import Level_Grid
import math
import itertools

# A Simple Script that handles AI pathfinding
# Created by Vinessa Mayer April 2014

	class AStar(object)
		def __init__(self, tiles):
			self.steps = tiles

		def H(self,node,start,goal):
			#raise NotImplementedError

	def findPath(self,start, goal):
		PossibleStepSet = set()
		FootprintsSet = set()
		GroundBeingSearched = start
		PossibleStepSet.append(GroundBeingSearched)

		while PossibleStepSet: #While we are looking in adjasent tiles
			GroundBeingSearched = min(PossibleStepSet, key = lambda 0:0.g + 0.h) #looks through all nodes, arranges them by smallest cost, makes the smallest GroundBeingSearched
			if GroundStoodApon == goal:# if Ground Being Searched is the Goal
				path = #[] Create a list to contain the entire path
				while GroundBeingSearched.parent:
					path.append(GroundBeingSearched) #Adds each node to the path list
					GroundStoodApon = GroundBeingSearched.parent
				path.append(GroundBeingSearched)
				return path[::-1]

			PossibleStepSet.remove(GroundBeingSearched)# removes the nodes from the open list
			FootprintsSet.add(GroundBeingSearched)# Adds the ground we've already dearched to the closed list

			for step in self.steps[GroundBeingSearched]:
				if step in FootprintsSet:
					continue

				if step in PossibleStepSet:
					new_g = GroundBeingSearched.g + GroundBeingSearched.move_cost(step)
					if step.g > new_g:
						step.g = new_g
						step.parent = GroundBeingSearched

					else:
					 step.g = GroundBeingSearched.g + GroundBeingSearched.move_cost(step)
					 step.h = self.H(step,start,goal)
					 step.patent = GroundBeingSearched
					 PossibleStepSet.add(step)
			return None

	class AStarStep(object):
			def __init__(self):
				self.g = 0
				self.h = 0
				self.parent = None

			def move_cost(self,other):
				raise NotImplementedError

	class AStarTerrain(AStar)
		def heuristic(self, step, start, goal):
			return sqrt((goal.x - step.x))**2 + (goal.y - step.y)**2)

	class AStarTerrainStep(AStarStep):
		def __init__(self, x, y):
			self.x = x
			self.y = y
			super(AStarTerrainStep, self).__init__()

		def move_cost(self, other):
			diagonal = abs(self.x - other.x) == 1 and abs(self.y - other.y)== 1
			if diagonal:
				return 14
			else:
				return 10





