#include "game.h"
#include <iostream>

Game::Game(std::string title)
	: m_title(std::move(title)), m_last_score(0) {
}

const std::string& Game::title() const {
    return m_title;
}

int Game::last_score() const {
    return m_last_score;
}

void Game::play() {
    std::cout << "\nGame::play called.\n";
}

void Game::set_score(int score) {
    m_last_score = score;
}

bool Game::ask_play_again() const {
    std::cout << "Play again? (y/n): ";
    char response = 'n';
    if (std::cin >> response) {
        return (response == 'y' || response == 'Y');
    }
    return false;
}