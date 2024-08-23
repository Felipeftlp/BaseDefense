#ifndef CONFIG_H
#define CONFIG_H

#include <SFML/Graphics.hpp>

namespace Config {

    // Configurações da Janela
    const unsigned int WINDOW_WIDTH = 800;
    const unsigned int WINDOW_HEIGHT = 600;
    const sf::String WINDOW_TITLE = "Base Defense";
    const sf::Uint32 WINDOW_STYLE = sf::Style::Titlebar | sf::Style::Close;

    // Configurações do Jogo
    const float SPAWN_INTERVAL = 3.0f;
    const float TOTAL_TIME = 60.0f;
    const bool AUDIO_ENABLED = true;

    // Configurações do Player
    const float PLAYER_SPEED = 300.0f;
    const int PLAYER_HEALTH = 100;
    const int PLAYER_MAX_HEALTH = 100;
    const int PLAYER_MAX_AMMO = 50;
    const int PLAYER_PROJETEIS_DISPONIVEIS = 50;

    // Configurações do Inimigo
    const float ENEMY_SPEED = 30.0f;
    const int ENEMY_HEALTH = 2;

    // Configurações do Projetil do Inimigo
    const float PROJETIL_INIMIGO_SPEED = 50.0f;

    // Configurações do Projetil do Jogador
    const float PROJETIL_SPEED = 500.0f;

    // Configurações do Drop

    // Configurações da Base
    const int BASE_HEALTH = 100;

    const int ENEMY_TANQUE_HEALTH = 10; // Mais vida para o tanque
    const float ENEMY_TANQUE_SPEED = 20.0f; // Menos velocidade para o tanque

    // Configurações do Inimigo Veloz
    const float ENEMY_VELOZ_SPEED = 60.0f;

    const Vector2f BASE_POSITION = {400, 300};



}

#endif // CONFIG_H