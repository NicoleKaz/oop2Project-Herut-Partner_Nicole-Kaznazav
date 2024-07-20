Project: 
Geometry Dash
Names:
Herut Partner  205741333
Nicole Kazantsev  208258095

Game instructions:
The goal of the game: 
to reach the end of the lavel as quickly as possible with as many coins as possible.

The player moves by pressing space to jump or left and right arrows to move forward or backward. 

If the player crashes into an obstacle such as a thorn, spiked wheel, running enemy, shooting enemy or his bullet the stage restarts.

The player can collect coins during the game that will give him special powers:
1. Flight - cancels after crossing gate
2. Extra speed - for a certain time.
3. Shield - for a certain time.

During the game there are gates that the player can enter through and they change the player states:
1. Gravity Gate - Changes the gravity in the game so that the player is pulled up or down.
2. Gate to cancel the flight - when the player passes, he returns to normal state

In addition, there are bouncers in the game-
The bouncers give him a strong jump boost and help the player go over obstacles.

Departments:
Controller - the class that controls the game menu everything has the menu amd game manager as main members.
GameManager - The class that responsible for managing the game and everything that happens in it.
Reasources- a singleton that holds all the textures, spritessheets, sounds.
Factory- a template factory of game object.
Command- an abstract class of command in the menu.
 	These are the classes that inhert from this class:
		- ScoreTableButton
		- ExitGame
		- HelpButton
		- MuteMusic
		- PlayButton
		- Level_Button (1-3)
		- SwitchPlayerButton
		- Player1Button (1-4)
Menu-a class the perform a menu operation.
LevelsMenu - choose a level to play.
ScoreTable - shows the player's game results.
PlayersMenu - choose a character to play.
Board- the board of the game holds the objects, has the box2d world that hols the bodies of each object.
GdContactListener - the class that handles collision between 2 object.
GameObject- a base class of object in the game:

	StaticObject-the base of the static object:
		-Thorn
		-Floor
		-Entrance
		-Jumper
		-Coin

	MovingObject-the base class of the moving object:
		-Player: the class of the player - it has state, score, few boolean.
		- WheelSpike: an spiked wheel that rotates around itself.
		- Bullet: the shotting enemy bullet.
		-Enemy: the class of the eneny.
			-ChaserEnemy
			-ShooterEnemy

Data structure- 
std::map - for the factory saves std::pair(sf:Color, func) each color represent an object and has a lambda function which calls its c-tor.
std::map - for the multimethod design pattern.
std::vector - saves the object in the game (the moving, the static)

Noteworthy algorithms -

Known bugs - The wheel is not attached to its place and with a change of gravity or a collision with the player it may move from its place.

The score table cant be filled with hebrew names, please write your name in english at the end of the level.

Other notes - Using Box2d, SFML STD libaries.