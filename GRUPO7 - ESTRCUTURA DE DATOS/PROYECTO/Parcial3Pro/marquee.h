#pragma once
#include <string>
#include <thread>
#include <atomic>
#include "console.h"

/**
* @file marquee.h
* @author Leonardo de la Cadena
* @version 1.0
*/

struct MarqueeCharacter {
    char character;
    short x;
    short y;
};

class Marquee {
public:
    Marquee() = default;
    Marquee(std::string text, short limit);

    /**
    * @brief declare the marquee text
    * @param string
    * @return void
    */
    void text(std::string text);

    std::string text();

    /**
    * @display marquee
    * @param
    * @return void
    */
    void display();

private:
    std::string text_;
    short limit_;
    std::thread thread_;
    bool running_ = false;
    std::atomic_int step_ = 0;


    void process();
};