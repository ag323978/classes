#include "videoGame.h"
#include <cstring>

VideoGame::VideoGame(char* newTitle, int newYear, char* newPublisher, float newRating):DigitalMedia(newTitle, newYear) {
  publisher = newPublisher;
  rating = newRating;
}

char* VideoGame::getPublisher() {
  return publisher;
}

float VideoGame::getRating() {
  return rating;
}

int VideoGame::getType() {
  return 0;
}

VideoGame::~VideoGame() {
  delete[]publisher;
}
