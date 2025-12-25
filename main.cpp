/** PROGRAM TO RENDER A 3D CUBE IN THE TERMINAL
 * ROTATES ACROSS ALL THREE AXES (X, Y AND Z)
 * INSPIRED BY: https://github.com/tarantino07/cube.c
 */ 

#include "Cube.hpp"
#include <chrono>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <thread>

int main() {
  std::cout << "\x1b[2J"; // Escape character to clear screen

  Screen screen(800, 200);
  int screenWidth = screen.getScreenWidth();
  int screenHeight = screen.getScreenHeight();

  char buffer[static_cast<unsigned long>(screenWidth * screenHeight)];
  float zBuffer[static_cast<unsigned long>(screenWidth * screenHeight)];

  int backgroundASCIICode = ' ';
  int distanceFromCam = 100;

  float thetaX = 0.0f;
  float thetaY = 0.0f;
  float thetaZ = 0.0f;

  Cube cube = {40, 0.6, thetaX, thetaY, thetaZ, screen, distanceFromCam};

  while (true) {
    std::memset(buffer, backgroundASCIICode, screenWidth * screenHeight);
    // Clear the Z Buffer
    std::fill(zBuffer, zBuffer + screenWidth * screenHeight, 0.0f);

    cube.setAngles(thetaX, thetaY, thetaZ);
    cube.displayCube(buffer, zBuffer);

    printf("\x1b[H"); // Moves cursor to top left
                      
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

    // 120 FPS
    std::this_thread::sleep_for(std::chrono::milliseconds(8));
  }
  return 0;
}
