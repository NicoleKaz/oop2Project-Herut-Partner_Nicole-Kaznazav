#pragma once

#include <SFML/Graphics.hpp>
//#include <SFML/Audio.hpp>
#include <string.h>
#include <vector>

//enum
enum Instructions { GAME_RULES, STICKER };
enum Button { PLAY, HELP, SWITCH_PLAYER, SCORE_TABLE, EXIT };
enum ButtonHelp {BACK, VIDEO_PLAY};
enum Direction { Right, Left,Up, Stay };
enum ToolBarWord { LIFE, SCORE, LEVEL, TIME, KEYCOUNTER };
enum Sound { CLICK, MINUS_LIFE, EAT, CLOCK_SOUND, DOOR_SOUND, FREEZE_SOUND, KEY_SOUND, GAME_OVER, WIN, EXTRA_LIFE };
enum Music { SONG, SECOND_END };
enum MenuTextures { menuBackground, Title};
enum MenuPlayer { PLAYER1, PLAYER2, PLAYER3, PLAYER4};
enum MenuLevels { level1, level2, level3};
enum GameMaps { Map1, Map2, Map3};
enum GameAnimations { Enemy1Animation, Enemy2Animation };


enum GameTextures {
	Floor_Inair, Level_Background,
	First_Player, First_Shield, First_Speed, First_Fly,
	Second_Player, Second_Shield, Second_Speed, Second_Fly,
	Third_Player, Third_Shield, Third_Speed, Third_Fly,
	Fourth_Player, Fourth_Shield, Fourth_Speed, Fourth_Fly,
	Thorn1,Thorn2, Thorns,
	CoinSpeed, CoinScore, CoinShield,CoinFly,
	Helfcube,Cube1,Cube2, 
	Gate1, Gate2, Gate3, Gate4, Gate5, 
	Jumper1, Jumper2,
	Enemy1SpriteSheet, Enemy2SpriteSheet, Enemy1, Enemy2,Bullet1, 
	ScoreBoard, Wheel
};


//consts
const int LEVEL_MENU = 3;
const int MENU_BUTTONS = 5;
const int MENU_PLAYER = 4;
const int INSTRUCTIONS = 2;
const int TOOL_BAR = 5;
const int SOUNDS = 10;
const int MUSIC = 2;
const float SPRITE_SIZE = 400.f;
const int MENU_TEXTURES = 2;
const int GAME_MAPS = 3;

const int GAME_TEXTURES = 42;


//game object by color
const sf::Color FLOOR_Inair_COLOR = sf::Color(0, 0, 0);;
//const sf::Color SPIKE1_COLOR = sf::Color(237, 28, 36);
const sf::Color THORN1_COLOR = sf::Color(237, 28, 36);
const sf::Color THORN2_COLOR = sf::Color(185, 122, 87);;
const sf::Color THORNS_COLOR = sf::Color(255, 174, 201);
const sf::Color CUBE1_COLOR = sf::Color(63, 72, 204);
const sf::Color CUBE2_COLOR = sf::Color(0, 162, 232);
const sf::Color HELF_CUBE_COLOR = sf::Color(153, 217, 234);


const sf::Color COIN_COLOR_SCORE = sf::Color(255, 242, 0);
const sf::Color COIN_COLOR_SPEED = sf::Color(60,120,180);
const sf::Color COIN_COLOR_Shield = sf::Color(60, 228, 34);
const sf::Color COIN_COLOR_Fly = sf::Color(255, 127, 39);

const sf::Color GATE1_COLOR = sf::Color(255, 127, 39);
const sf::Color GATE2_COLOR = sf::Color(136, 0, 21);
const sf::Color GATE3_COLOR = sf::Color(200, 191, 231);
const sf::Color GATE4_COLOR = sf::Color(136, 0, 21);
const sf::Color GATE5_COLOR = sf::Color(64, 128, 128);


const sf::Color RECTANGLE_COLOR = sf::Color(153, 217, 234);
//const sf::Color SPIKES_COLOR = sf::Color(255, 174, 201);
const sf::Color JUMPER2_COLOR = sf::Color(34, 177, 76);
const sf::Color JUMPER1_COLOR = sf::Color(181, 230, 29);
const sf::Color JUMPER1_UP_COLOR = sf::Color(127, 127, 127);
const sf::Color PLAYER_COLOR = sf::Color(255, 201, 14);
const sf::Color ENEMY1_COLOR = sf::Color(195, 195, 195);
const sf::Color ENEMY1_UP_COLOR = sf::Color(117, 22, 63);
const sf::Color ENEMY2_COLOR = sf::Color(234, 54, 128);
const sf::Color ENEMY2_UP_COLOR = sf::Color(120, 67, 21);
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
	const sf::Texture& getMenuPlayer(const MenuPlayer player) const;
	const sf::Texture& getInstruction(const Instructions instruction) const;
	Resources(const Resources&) = default;
	Resources& operator=(const Resources&) = default;
	static Resources& instance(); //static so the resources will called once
	const sf::Texture& getGameTexture(const GameTextures texture) const;
	const sf::Font& getFont() const;

	const sf::Texture& getMenuTexture(const MenuTextures)const;
	const sf::Texture& getLevelsMenu(const MenuLevels button) const;
	const sf::Texture& getButton(const Button)const;
	const sf::Image& getMap(const GameMaps map) const;

	void playSound(Sound);

private:
	void loadTextures();
	sf::Texture m_menuTextures[MENU_TEXTURES];
	sf::Texture m_menuButton[MENU_BUTTONS];
	sf::Texture m_instructionsTextures[INSTRUCTIONS];
	sf::Texture m_game_textures[GAME_TEXTURES];
	sf::Texture m_menuPlayers[MENU_PLAYER];
	sf::Texture m_menuLevel[LEVEL_MENU];
	sf::Texture m_playerSpeed;
	sf::Texture m_playerShield;


	std::vector<sf::Texture> m_MenuTexture;

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