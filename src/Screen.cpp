#include "Screen.hpp"

Screen::Screen(const float windowWidth, const float windowHeight): screenWidth_(windowWidth), screenHeight_(windowHeight){}

Screen::~Screen() {}

float Screen::getScreenWidth() const {
    return screenWidth_;
}

float Screen::getScreenHeight() const {
    return screenHeight_;
}

