#include "digitalMedia.h"
#include <cstring>

DigitalMedia::DigitalMedia(char* newTitle, int newYear) {
  title = newTitle;
  year = newYear;
}

char* DigitalMedia::getTitle() {
  return title;
}

int DigitalMedia::getYear() {
  return year;
}

int DigitalMedia::getType() {
  return 4;
}

DigitalMedia::~DigitalMedia() {
  delete[] title;
}
