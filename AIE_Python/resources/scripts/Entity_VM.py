import AIE
import game

#Tank Entity
#   A simple entity that can be placed on the screen with a right click, you should modify this so that the tank can be told to 
#   navigate to a point instead of instantly move.

class TankEntity:

	def __init__(self):
		self.Position = ( 1200, 600 )
		self.Goal = 0
		self.GoalIndex = 0
		self.Start = 0
		closedset = set{}
		openset = {set.copy(_level.leveltiles)}
		self.Rotation = 0
		self.spriteName = "./images/PlayerTanks.png"
		self.size = (57, 72 )
		self.origin = (0.5, 0.5)
		self.spriteID = AIE.CreateSprite(self.spriteName, self.size[0], self.size[1], self.origin[0], self.origin[1], 71.0/459.0, 1.0 - 72.0/158.0, 128/459.0, 1.0 , 0xff, 0xff, 0xff, 0xff )
		print "spriteID", self.spriteID
		#Move Tile to appropriate location
		
		self.turret = Turret(self)
		
	def update(self, fDeltaTime ):
		self.Goal = update4Astar(self)
		self.Start = getcurrentnodeindex(self)
		#mouseX, mouseY = AIE.GetMouseLocation()
		#if( AIE.GetMouseButton(1)  ):
			#self.Position = (mouseX, mouseY)
		AIE.MoveSprite( self.spriteID, self.Position[0], self.Position[1] )
		self.turret.update(fDeltaTime)
	
	def draw(self):
		
		AIE.DrawSprite( self.spriteID )
		self.turret.draw()
		
	def getImageName(self):
		return self.imageName
		
	def getState(self):
		return self.state
	
	def getSpriteID(self):
		return self.spriteID
		
	def setSpriteID(self, a_spriteID):
		self.spriteID = a_spriteID
	
	def getPosition(self):
		return self.Position

	def cleanUp(self):
		self.turret.cleanUp()
		AIE.DestroySprite( self.spriteID )

	
#update4Astar - checks for right click, gets mouse location and uses a formula to determine which
# tile / node was clicked on. Returns the tile's index.
	def GetTargetNodeIndex (self):
		mouseX, mouseY = AIE.GetMouseLocation()
		if(AIE.GetMouseButton(1) and (self.buttonPressed is False)):
			self.buttonPressed = True
			GoalIndex = int (_level.resolveGridSquare(mouseX, mouseY))
			self.buttonPressed = not AIE.GetMouseButtonRelease(1)
			return GoalIndex
#getcurrentnode - gets the current position of the tank and uses a formula to determine 
#what tile it is currently sitting on and returns it.
	def getcurrentnodeindex(self):
		positionX, positionY = self.getPosition()
		CurrentNode = int (_level.resolveGridSquare(positionX,positionY))
		return CurrentNode


	def Astar(self):
		#mouseX, mouseY = AIE.GetMouseLocation()
		self.Start = self.getcurrentnodeindex(self)
		self.Goal = (GetTargetNodeIndex(self))
		#closedset = set{}
		#openset = {_level.leveltiles}
		#_level.leveltiles[i]

	def getStart(self):
		return self.Start

	def setStart(a_Start):
		self.Start = a_Start

	def setGoal(a_Goal):
		self.Goal = a_Goal

	def getGoal(self):
		return self.Goal

# findcostG - meant to be used while running through a list of tiles(i). Gets the current node index assigns it to
# Origin . Gets the Destination (i) tile to compare it to. Subtracts
	def findCostG(self, i):
		Origin = self.getcurrentnodeindex(self)
		DestinationTile = i
		Gcost = (DestinationTile - _level[Origin]) / _level.tilesize

#Turret
#    This is an Entity Object that has an owner, it is up to you to implement inheritance (BaseEntity->Turret) 
#    The Turret's position is based on the location of it's owner, if it's owner (in this scenario a Tank) is moveable
#    The turret will move with it's base/owner

class Turret:
	
	def __init__(self, owner):
		self.owner = owner
		self.Position = ( 0, 0 )
		self.Rotation = 0
		self.spriteName = "./images/PlayerTanks.png"
		self.size = (29, 60 )
		self.origin = (0.55, 0.75)
		self.spriteID = AIE.CreateSprite( self.spriteName, self.size[0], self.size[1], self.origin[0], self.origin[1], 129.0/459.0, 1.0 - 61.0/158.0, 157.0/459.0, 1.0 , 0xff, 0xff, 0xff, 0xff )
		print "spriteID", self.spriteID
	
	def update(self, fDeltaTime):
		turretLocation = self.owner.getPosition()
		AIE.MoveSprite( self.spriteID, turretLocation[0], turretLocation[1] )
		
	def draw(self):
		AIE.DrawSprite( self.spriteID )
	
	def	cleanUp(self):
		AIE.DestroySprite( self.spriteID )
		