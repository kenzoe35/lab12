#pragma once

class Game {
public:
	//Stores the title and sets the last score to 0.
	explicit Game(std::string title);

	// The name of the game.
	const std::string& title() const;

	// The score from the most recent game.
	int last_score() const;

	// 	Not virtual this week. In Game it prints Game::play called.
	void play();

protected:

	// Derived classes call it to record a score.
	void set_score(int score);

	// Asks the player whether to play again.
	bool ask_play_again() const;

private: // Only Game touches them directly.
	std::string m_title;
	int m_last_score;
};