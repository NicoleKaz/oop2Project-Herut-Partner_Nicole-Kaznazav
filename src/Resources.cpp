#include "Resources.h"


Resources::Resources()
{
	loadTextures();
}



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
	m_maps[Map1].loadFromFile("Map1.png");
	//m_maps[Map2].loadFromFile("Map2.png");
	//m_maps[Map3].loadFromFile("Map3.png");


	m_menuLevel[level1].loadFromFile("Level1.png");
	m_menuLevel[level2].loadFromFile("Level2.png");
	m_menuLevel[level3].loadFromFile("Level3.png");

	m_instructionsTextures[GAME_RULES].loadFromFile("instructions.png");
	m_instructionsTextures[STICKER].loadFromFile("Sticker.png");	


	//game textures
	m_game_textures[Level_Background].loadFromFile("background1.png");
	m_game_textures[Floor_Inair].loadFromFile("Floor.png");
	m_game_textures[Cube1].loadFromFile("Cube1.png");
	m_game_textures[Cube2].loadFromFile("Cube2.png");
	m_game_textures[Helfcube].loadFromFile("Helfcube.png");
	m_game_textures[Thorn1].loadFromFile("Thorn1.png");
	m_game_textures[Thorn2].loadFromFile("Thorn2.png");
	m_game_textures[Thorns].loadFromFile("Thorns.png");

	m_game_textures[First_Player].loadFromFile("Player1.png");
	m_game_textures[First_Shield].loadFromFile("Player1_Shield.png");
	m_game_textures[First_Speed].loadFromFile("Player1_Speed.png");
	m_game_textures[First_Fly].loadFromFile("Player1_Fly.png");

	
	m_game_textures[Second_Player].loadFromFile("Player2.png");
	m_game_textures[Second_Shield].loadFromFile("Player2_Shield.png");
	m_game_textures[Second_Speed].loadFromFile("Player2_Speed.png");
	//m_game_textures[Second_Fly].loadFromFile("Player2_Fly.png");
 
	m_game_textures[Third_Player].loadFromFile("Player3.png");
	m_game_textures[Third_Shield].loadFromFile("Player3_Shield.png");
	m_game_textures[Third_Speed].loadFromFile("Player3_Speed.png");
	//m_game_textures[Third_Fly].loadFromFile("Player3_Fly.png");

	m_game_textures[Fourth_Player].loadFromFile("Player4.png");
	m_game_textures[Fourth_Shield].loadFromFile("Player4_Shield.png");
	m_game_textures[Fourth_Speed].loadFromFile("Player4_Speed.png");
	//m_game_textures[Fourth_Fly].loadFromFile("Player4_Fly.png");


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
	m_game_textures[Gate3].loadFromFile("Gate3.png");
	m_game_textures[Gate2].loadFromFile("Gate2.png");

	m_font.loadFromFile("C:/Windows/Fonts/Arial.ttf");
}

//
Resources& Resources::instance()
{
	static Resources Resource;
	return Resource;
}


//return the sound
void Resources::playSound(Sound sound)
{
	//m_sound.setBuffer(m_soundVector[sound]);
	//m_sound.play();
}