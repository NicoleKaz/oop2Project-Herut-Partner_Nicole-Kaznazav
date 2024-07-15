#include "Resources.h"


Resources::Resources()
{
	loadTextures();
	//loadMusic();	
}

//void Resources::loadMusic()
//{
//	m_soundBuffers[Red_Song].loadFromFile("Red_Song.wav");
//	m_soundBuffers[Pink_Song].loadFromFile("Pink_Song.wav");
//	m_soundBuffers[Blue_Song].loadFromFile("Blue_Song.wav");
//	m_soundBuffers[Menu_Song].loadFromFile("Menu_Song.wav");
//}
//
//
////getGameSounds
//sf::SoundBuffer& Resources::getGameSounds(GameSounds sound)
//{
//	return m_soundBuffers[sound];
//}

//loading all the textures
void Resources::loadTextures()
{
	m_menuTextures[menuBackground].loadFromFile("menuBackground.png");
	m_menuTextures[menuBackground].setSmooth(true);
	m_menuTextures[Title].loadFromFile("Title.png");
	m_menuTextures[Title].setSmooth(true);
	m_menuTextures[Score_Background].loadFromFile("Menu_Background_Score.png");
	m_menuTextures[Score_Background].setSmooth(true);

	//menu buttons
	m_menuButton[PLAY].loadFromFile("Play.png");
	m_menuButton[HELP].loadFromFile("Help.png");
	m_menuButton[SWITCH_PLAYER].loadFromFile("Switch_Player.png");
	m_menuButton[SCORE_TABLE].loadFromFile("ScoreTable.png");
	m_menuButton[EXIT].loadFromFile("Exit.png");

	m_menuPlayers[PLAYER1].loadFromFile("Player1.png");
	m_menuPlayers[PLAYER2].loadFromFile("Player2.png");
	m_menuPlayers[PLAYER3].loadFromFile("Player3.png");
	m_menuPlayers[PLAYER4].loadFromFile("Player4.png");


	//game image
	m_maps[MapRed].loadFromFile("MapRed.png");
	m_maps[MapPink].loadFromFile("MapPink.png");
	m_maps[MapBlue].loadFromFile("MapBlue.png");

	m_menuLevel[level1].loadFromFile("Level1.png");
	m_menuLevel[level2].loadFromFile("Level2.png");
	m_menuLevel[level3].loadFromFile("Level3.png");

	m_instructionsTextures[GAME_RULES].loadFromFile("instructions.png");
	m_instructionsTextures[STICKER].loadFromFile("Sticker.png");	


	//background textures
	m_background_textures[LevelRed].loadFromFile("background1.png");
	m_background_textures[LevelPink].loadFromFile("background2.png");
	m_background_textures[LevelBlue].loadFromFile("background3.png");

	//game textures

	m_game_textures[Floor_Inair_red].loadFromFile("FloorRed.png");
	m_game_textures[Cube1Red].loadFromFile("Cube1Red.png");
	m_game_textures[Cube2Red].loadFromFile("Cube2Red.png");
	m_game_textures[ThornRed].loadFromFile("ThornRed.png");

	m_game_textures[Floor_Inair_pink].loadFromFile("FloorPink.png");
	m_game_textures[Cube1Pink].loadFromFile("Cube1Pink.png");
	m_game_textures[Cube2Pink].loadFromFile("Cube2Pink.png");
	m_game_textures[ThornPink].loadFromFile("ThornPink.png");

	m_game_textures[Floor_Inair_blue].loadFromFile("FloorBlue.png");
	m_game_textures[Cube1Blue].loadFromFile("Cube1Blue.png");
	m_game_textures[Cube2Blue].loadFromFile("Cube2Blue.png");
	m_game_textures[ThornBlue].loadFromFile("ThornBlue.png");

	m_game_textures[Thorns].loadFromFile("Thorns.png");

	m_game_textures[First_Player].loadFromFile("Player1.png");
	m_game_textures[First_Shield].loadFromFile("Player1_Shield.png");
	m_game_textures[First_Speed].loadFromFile("Player1_Speed.png");
	m_game_textures[First_Fly].loadFromFile("Player1_Fly.png");
	m_game_textures[Second_Player].loadFromFile("Player2.png");
	m_game_textures[Second_Shield].loadFromFile("Player2_Shield.png");
	m_game_textures[Second_Speed].loadFromFile("Player2_Speed.png");
	m_game_textures[Second_Fly].loadFromFile("Player2_Fly.png");
	m_game_textures[Third_Player].loadFromFile("Player3.png");
	m_game_textures[Third_Shield].loadFromFile("Player3_Shield.png");
	m_game_textures[Third_Speed].loadFromFile("Player3_Speed.png");
	m_game_textures[Third_Fly].loadFromFile("Player3_Fly.png");
	m_game_textures[Fourth_Player].loadFromFile("Player4.png");
	m_game_textures[Fourth_Shield].loadFromFile("Player4_Shield.png");
	m_game_textures[Fourth_Speed].loadFromFile("Player4_Speed.png");
	m_game_textures[Fourth_Fly].loadFromFile("Player4_Fly.png");

	m_game_textures[Enemy1].loadFromFile("Enemy1.png");
	m_game_textures[Enemy2].loadFromFile("Enemy2.png");
	m_game_textures[Bullet1].loadFromFile("Bullet.png");

	m_game_textures[CoinSpeed].loadFromFile("CoinSpeed.png");
	m_game_textures[CoinScore].loadFromFile("CoinScore.png");
	m_game_textures[CoinShield].loadFromFile("CoinShield.png");
	m_game_textures[CoinFly].loadFromFile("CoinFly.png");

	m_game_textures[Jumper1].loadFromFile("Jumper1.png");
	m_game_textures[Jumper2].loadFromFile("Jumper2.png");
	m_game_textures[Wheel].loadFromFile("SpikedWheel.png");
	m_game_textures[GateGravityChange].loadFromFile("GateGravityChange.png");
	m_game_textures[GateNoFly].loadFromFile("GateNoFly.png");
	m_game_textures[GateLevelEnd].loadFromFile("GateLevelEnd.png");

	m_font.loadFromFile("C:/Windows/Fonts/Arial.ttf");
}

//
Resources& Resources::instance()
{
	static Resources Resource;
	return Resource;
}