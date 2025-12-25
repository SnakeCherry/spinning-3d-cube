#include "Cube.hpp"
#include <chrono>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <thread>

int main() {
  std::cout << "\x1b[2J"; // Escape character to clear screen
  Screen screen(160, 44);
  char buffer[static_cast<unsigned long>(screen.getScreenWidth() *
                                         screen.getScreenHeight())];
  float zBuffer[static_cast<unsigned long>(screen.getScreenWidth() *
                                           screen.getScreenHeight())];
  int backgroundASCIICode = '.';
  int distanceFromCam = 100;
  float thetaX = 0.0f;
  float thetaY = 0.0f;
  float thetaZ = 0.0f;
  int screenWidth = screen.getScreenWidth();
  int screenHeight = screen.getScreenHeight();
  Cube cube = {20, 0.6, thetaX, thetaY, thetaZ, screen};

  while (true) {
    std::memset(buffer, backgroundASCIICode, screenWidth * screenHeight);
    std::fill(zBuffer, zBuffer + screenWidth * screenHeight, 0.0f);
    cube.setAngles(thetaX, thetaY, thetaZ);
    cube.displayCube(buffer, zBuffer);
    printf("\x1b[H");
    for (int k = 0; k < screenWidth * screenHeight; k++) {
      if (k % screenWidth == 0) {
        std::putchar('\n');
      } else {
        std::putchar(buffer[k]);
      }
    }
    std::fflush(stdout);
    thetaX += 0.05;
    thetaY += 0.05;
    thetaZ += 0.01;
    std::this_thread::sleep_for(std::chrono::milliseconds(16));
  }
  return 0;
}
