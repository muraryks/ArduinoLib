/*
    Menu.h - Library for graphical menus.
    Created by Daniel Esteban, December 23, 2012.
    Released into the public domain.
*/

#ifndef Menu_h
#define Menu_h

#if defined(ARDUINO) && ARDUINO >= 100
#include <Arduino.h>
#else
#include <stdlib.h>
#include <WProgram.h>
#endif
#include "UI.h"

class Menu : public UI {
    public:
        Menu(String title, byte numItems, String items[], TouchEvent onClick = NULL, TouchEvent onDown = NULL);
        void render(UTFT tft);
        void setLabel(byte id, String label, bool render = true);
    private:
        static const byte itemsPerPage = 6,
            titleHeight = 13,
            menuPadding = 20,
            itemMargin = 10;

        byte _numItems,
            _page,
            _itemPadding,
            _lastPress;

        UTFT _tft;

        String _title;
        String * _items;

        TouchEvent _onClick;
        TouchEvent _onDown;

        void renderItem(byte id, bool pressed = false);
        void onClick(byte id);
        void onDown(byte id);
};
 
#endif
