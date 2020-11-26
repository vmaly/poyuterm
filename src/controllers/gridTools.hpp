#pragma once

#include <vector>
#include "domains/grid.hpp"
#include "domains/gameData.hpp"

struct Coordinates
{
    std::size_t x;
    std::size_t y;
    Coordinates(std::size_t x, std::size_t y);
    void add(std::size_t x, std::size_t y);

    Coordinates operator+=(const Coordinates &coordinate);
    Coordinates operator+(Coordinates coordinate);
};

std::vector<std::vector<Puyo>> runDetection(Grid &grid, std::vector<Coordinates> &starts);

void extractGroup(std::vector<Puyo> &group,
                  std::vector<std::vector<Grid::PuyoType>> &clonedContent,
                  Coordinates Coordinates);

bool shift(std::vector<Puyo> &activePiece, Grid constraint, int x, int y);