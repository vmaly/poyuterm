#define DOCTEST_CONFIG_IMPLEMENT
#include <doctest/doctest.h>
#include "domains/grid.hpp"
#include <iostream>

TEST_CASE("testing the constructor")
{
    vector<vector<Grid::PuyoType>> content =
        {
            {Grid::red, Grid::none, Grid::none},
            {Grid::none, Grid::red, Grid::red},
            {Grid::none, Grid::none, Grid::red}};

    Grid grid = Grid(content);
    CHECK(grid.content == content);

    content =
        {
            {Grid::none, Grid::blue},
            {Grid::red, Grid::yellow},
            {Grid::green, Grid::none}};

    grid = Grid(content);
    CHECK(grid.content == content);
}
