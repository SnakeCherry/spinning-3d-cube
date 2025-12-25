#ifndef SCREEN_HPP
#define SCREEN_HPP

class Screen {
public:
  Screen(const float screenWidth, const float screenHeight);
  ~Screen();
  float getScreenWidth() const;
  float getScreenHeight() const;

private:
  const float screenWidth_;
  const float screenHeight_;
};

#endif
