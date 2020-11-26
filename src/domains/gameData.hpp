#pragma once
#include <vector>
#include "domains/grid.hpp"
#include "views/display.hpp"

struct Puyo
{
    Grid::PuyoType type;
    std::size_t x;
    std::size_t y;
    Puyo();
    Puyo(Grid::PuyoType type, std::size_t x, std::size_t y);
    void move(int x, int y);
    bool operator==(const Puyo &other) const;
};

struct GameData
{

    enum GameState
    {
        running = 0,
        won = 1,
        lost = 2
    };

    enum GameMode
    {
        menu = 0,
        simulation = 1,
        solo = 2,
        tetris = 3
    };

    GameMode mode = menu;
    GameState state = running;

    GameData();
    std::vector<Puyo> activePiece;
    long delaySinceGravity;
};