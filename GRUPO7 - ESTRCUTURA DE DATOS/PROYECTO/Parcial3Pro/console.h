#pragma once
#include <string>
#include <Windows.h>

/**
* @file console.h
* @author Leonardo de la Cadena
* @verison 1.0
*/

class Console
{
public:
    Console(Console const&) = delete;
    Console& operator=(Console const&) = delete;
    static Console& get();

    /**
    * @brief print text in console with given coordinates
    * @param string, COORD
    * @return void
    */
    void print(std::string text, COORD coord);

    /**
    * @brief clear line
    * @param short
    * @return void
    */
    void clear_line(short y);

    /**
    * @brief clear console screen
    * @param
    * @return void
    */
    void clear_screen();

    /**
    * @brief clear given area
    * @param SMALL_RECT
    * @return void
    */
    void clear_area(SMALL_RECT area);

    /**
    * @brief set position of the concole cursor with given coordinates
    * @param COORD
    * @return void
    */
    void set_cursor_position(COORD coord);

    /**
    * @brief get size of console screen in coordinates
    * @param
    * @return COORD
    */
    COORD get_console_size();

private:
    Console();
};