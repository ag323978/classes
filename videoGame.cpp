#include "videoGame.h"
#include <iostream>
#include <cstring>

using namespace std;

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
  return 4;
}

void VideoGame::printElements() {
  cout << endl;
  cout << "Title: " << getTitle() << endl;
  cout << "Year: " << getYear() << endl;
  cout << "Publisher: " << getPublisher() << endl;
  cout << "Rating: " << getRating() << endl;
  cout << endl;
}

VideoGame::~VideoGame() {
  delete[]publisher;
}
