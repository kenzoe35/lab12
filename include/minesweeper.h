#ifndef ARCADE_MINESWEEPER_H
#define ARCADE_MINESWEEPER_H

/// @file minesweeper.h
/// @brief The Minesweeper game loop.

/// The score for a game.
/// @param revealed_count squares the player uncovered
/// @param won true if the player cleared the board
/// @return revealed_count, plus 100 for a win
int minesweeper_score(int revealed_count, bool won);

/// Play one game on an 8-by-8 board with 10 mines.
/// @return minesweeper_score() when the game ends or the player quits
int play_minesweeper();


class Minesweeper : public Game {
public:
    explicit Minesweeper(std::string title = "Minesweeper");

    // Non-virtual play method wrapping play_minesweeper()
    void play();

    // Times played getter
    int times_played() const;

private:
    int m_times_played;
};

#endif // ARCADE_MINESWEEPER_H
