#ifndef COLOR__H
#define COLOR__H

#include <stdint.h>
#include <WString.h>

struct Color {
  uint8_t r = 255;
  uint8_t g = 255;
  uint8_t b = 255;

  Color() {};
  
  Color(uint8_t r, uint8_t g, uint8_t b) {
    this->r = r;
    this->g = g;
    this->b = b;
  }

  static Color parse(const String& a_str) {
    int number = (int)strtol(&a_str.c_str()[1], NULL, 16);

    Color c;
    c.r = number >> 16;
    c.g = number >> 8 & 0xFF;
    c.b = number & 0xFF;
    return c;
  }

  String toString() {
    int number;
    number += r << 16;
    number += g << 8;
    number += b;
    return '#' + String(number, 16);
  }

  Color& dimm(uint8_t a_perc) {
    if (a_perc > 100) 
      a_perc = 100;

    r = ((uint16_t)r * a_perc) / 100;
    g = ((uint16_t)g * a_perc) / 100;
    b = ((uint16_t)b * a_perc) / 100;
    return *this;
  }
};

#endif