#pragma once

#include <SFML/Graphics.hpp>
//#include <SFML/Audio.hpp>
#include <string.h>
#include <vector>

//enum
enum Instructions { GAME_RULES, STICKER };
enum Button { PLAY, HELP, SWITCH_PLAYER, SCORE_TABLE, EXIT };
enum ButtonHelp { BACK, VIDEO_PLAY };
enum Direction { Right, Left, Up, Stay };
enum ToolBarWord { LIFE, SCORE, LEVEL, TIME, KEYCOUNTER };
enum Sound { CLICK, MINUS_LIFE, EAT, CLOCK_SOUND, DOOR_SOUND, FREEZE_SOUND, KEY_SOUND, GAME_OVER, WIN, EXTRA_LIFE };
enum Music { SONG, SECOND_END };
enum MenuTextures { menuBackground, Title, Score_Background };
enum MenuPlayer { PLAYER1, PLAYER2, PLAYER3, PLAYER4 };
enum MenuLevels { level1, level2, level3 };
enum GameMaps { MapRed, MapPink, MapBlue };
enum GameBackground { LevelRed, LevelPink, LevelBlue };
enum GameAnimations { Enemy1Animation, Enemy2Animation };


enum GameTextures {
	Floor_Inair_red, Floor_Inair_pink, Floor_Inair_blue,
	First_Player, First_Shield, First_Speed, First_Fly,
	Second_Player, Second_Shield, Second_Speed, Second_Fly,
	Third_Player, Third_Shield, Third_Speed, Third_Fly,
	Fourth_Player, Fourth_Shield, Fourth_Speed, Fourth_Fly,
	ThornRed, ThornPink, ThornBlue, Thorns,
	CoinSpeed, CoinScore, CoinShield, CoinFly,
	Cube1Red, Cube2Red, Cube1Pink, Cube2Pink, Cube1Blue, Cube2Blue,
	GateNoFly, GateGravityChange, GateLevelEnd,
	Jumper1, Jumper2,
	Enemy1SpriteSheet, Enemy2SpriteSheet, Enemy1, Enemy2, Bullet1,
	ScoreBoard, Wheel
};


//consts
const int LEVEL_MENU = 3;
const int MENU_BUTTONS = 5;
const int MENU_PLAYER = 4;
const int INSTRUCTIONS = 2;
const int TOOL_BAR = 5;
//const int SOUNDS = 10;
const int MUSIC = 2;
const float SPRITE_SIZE = 400.f;
const int MENU_TEXTURES = 3;
const int GAME_MAPS = 3;
const int GAME_BACKGROUND = 3;

const int GAME_TEXTURES = 45;


//game object by color
const sf::Color FLOOR_Inair_RED = sf::Color(0, 0, 0);
const sf::Color CUBE1_RED = sf::Color(63, 72, 204);
const sf::Color CUBE2_RED = sf::Color(0, 162, 232);
const sf::Color THORN_RED = sf::Color(237, 28, 36);

const sf::Color FLOOR_Inair_PINK = sf::Color(10, 9, 9);
const sf::Color CUBE1_PINK = sf::Color(0, 162, 12);
const sf::Color CUBE2_PINK = sf::Color(32, 184, 228);
const sf::Color THORN_PINK = sf::Color(85, 100, 200);

const sf::Color FLOOR_Inair_BLUE = sf::Color(20, 5, 6);
const sf::Color CUBE1_BLUE = sf::Color(125, 80, 60);
const sf::Color CUBE2_BLUE = sf::Color(38, 190, 223);
const sf::Color THORN_BLUE = sf::Color(255, 30, 20);

const sf::Color THORNS_COLOR = sf::Color(255, 174, 201);
const sf::Color COIN_COLOR_SCORE = sf::Color(255, 242, 0);
const sf::Color COIN_COLOR_SPEED = sf::Color(60, 120, 180);
const sf::Color COIN_COLOR_SHIELD = sf::Color(60, 228, 34);
const sf::Color COIN_COLOR_FLY = sf::Color(255, 127, 39);

const sf::Color GATE_NO_FLY_COLOR = sf::Color(136, 0, 21);
const sf::Color GATE_GRAVITY_CHANGE_COLOR = sf::Color(200, 191, 231);
const sf::Color GATE_END_LEVEL_COLOR = sf::Color(64, 128, 128);

const sf::Color RECTANGLE_COLOR = sf::Color(153, 217, 234);
const sf::Color JUMPER2_COLOR = sf::Color(34, 177, 76);
const sf::Color JUMPER1_COLOR = sf::Color(181, 230, 29);
const sf::Color PLAYER_COLOR = sf::Color(255, 201, 14);
const sf::Color ENEMY1_COLOR = sf::Color(195, 195, 195);
const sf::Color ENEMY2_COLOR = sf::Color(234, 54, 128);
const sf::Color BULLET_COLOR = sf::Color(255, 0, 0);
const sf::Color WHEEL_COLOR = sf::Color(50, 60, 70);

//physics
const float SCALE = 30.f;
const float SPEED_JUMP_FORCE = 80.f;
const float REGULER_JUMP_FORCE = 30.f;
const float SHIELD_JUMP_FORCE = 60.f;
const float FLY_FORCE = 5.f;
const float PLAYER_MOVEMENT_SPEED = 7;
const float PLAYER_MOVEMENT_EXTRA_SPEED = 11;
const float ENEMY_MOVEMENT_SPEED = 3;



//window
const int WINDOW_HEIGHT = 800;
const int WINDOW_WIDTH = 1400;


class Resources
{
public:

	Resources(); //private so there will be no duplicates
	Resources(const Resources&) = default;
	static Resources& instance(); //static so the resources will called once

	const sf::Texture& getMenuPlayer(const MenuPlayer player) const { return m_menuPlayers[player]; }
	const sf::Texture& getInstruction(const Instructions instruction) const { return m_instructionsTextures[instruction]; }
	const sf::Texture& getGameTexture(const GameTextures texture) const { return m_game_textures[texture]; }
	const sf::Texture& getGameBackground(const GameBackground texture) const { return m_background_textures[texture]; }
	const sf::Texture& getLevelsMenu(const MenuLevels button) const { return m_menuLevel[button]; }
	const sf::Image& getMap(const GameMaps map) const { return m_maps[map]; }
	const sf::Font& getFont() const { return m_font; }
	const sf::Texture& getMenuTexture(const MenuTextures texture)const { return m_menuTextures[texture]; }
	const sf::Texture& getButton(const Button button)const { return m_menuButton[button]; }


	//void playSound(Sound);

private:
	void loadTextures();
	sf::Texture m_menuTextures[MENU_TEXTURES];
	sf::Texture m_menuButton[MENU_BUTTONS];
	sf::Texture m_instructionsTextures[INSTRUCTIONS];
	sf::Texture m_game_textures[GAME_TEXTURES];
	sf::Texture m_background_textures[GAME_BACKGROUND];
	sf::Texture m_menuPlayers[MENU_PLAYER];
	sf::Texture m_menuLevel[LEVEL_MENU];


	sf::Font m_font;
	sf::Image m_maps[GAME_MAPS];

	sf::CircleShape player;
	//sf::Sound m_sound;
//	sf::Music m_music;

	//std::vector<sf::Texture> m_textureVec;
	//std::vector<sf::SoundBuffer> m_soundVector;
//	std::vector<sf::Music> m_musicVector;
	/*std::string m_ButtonFiles[BUTTONS] = { "Play.png", "Help.png", "Exit.png" , "VideoPlay.png" , "Back.png" };
	std::string m_MusicFiles[MUSIC] = { "Song.wav","5_second_end.wav" };
	std::string m_InstructionFiles[INSTRUCTIONS] = { "GameRules.png" };
	std::string m_SoundFiles[SOUNDS] = { "Click.ogg", "MinusLife.ogg", "Eat.ogg", "ClockSound.ogg",
									"DoorSound.ogg" , "FreezeSound.ogg" ,
									 "KeySound.ogg" , "GameOver.ogg","win.ogg", "ExtraLifeSound.ogg" };*/
};