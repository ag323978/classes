#include "digitalMedia.h"
#include <iostream>
#include <cstring>

using namespace std;

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
  return 1;
}

void DigitalMedia::printElements() {
  cout << endl;
  cout << "Title: " << getTitle() << endl;
  cout << "Year: " << getYear() << endl;
  cout << endl;
}

DigitalMedia::~DigitalMedia() {
  delete[] title;
}
