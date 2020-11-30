#include "controllers/listeners/inputsListener.hpp"
#include "views/display.hpp"

void InputsListener::onMenuKeyPressed(int code)
{
    switch (code)
    {
    case KEY_UP:
        menuUp();
        break;

    case KEY_DOWN:
        menuDown();
        break;

    case '\n':
        menuEnter();
        break;
    };
}

void InputsListener::openMenu()
{
    _gameData.state = GameData::menu;
    _display.showMenu();
}

void InputsListener::menuUp()
{
    (*_display.menu).previous();
}

void InputsListener::menuDown()
{
    (*_display.menu).next();
}

void InputsListener::menuEnter()
{
    unsigned int selected = (*_display.menu).select();
    if (selected == 3)
    {
        _display.close();
        exit(0);
        return;
    }
    GameData::GameMode newGameMode = GameData::GameMode(selected);
    auto contentSnapshot = _grid.content;
    _gameData.state = GameData::running;
    _display.showGame();
    if (_gameData.mode != newGameMode)
    {
        _gameData.mode = newGameMode;
        _grid.reset();

        _gameData.activePiece.map([&](Puyo &puyo) {
            (*_display.game).setCell(puyo.x, puyo.y, Grid::none);
        });
        _gameData.activePiece.setEmpty();
        (*_display.game).refreshDiff(contentSnapshot, _grid);
    }
}