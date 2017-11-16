#include "movie.h"
#include <iostream>
#include <cstring>


Movie::Movie(char* newTitle, int newYear, char* newDirector, int newDuration, float newRating):DigitalMedia(newTitle, newYear) {
  director = newDirector;
  duration = newDuration;
  rating = newRating;
}

char* Movie::getDirector() {
  return director;
}

int Movie::getDuration() {
  return duration;
}

float Movie::getRating() {
  return rating;
}

int Movie::getType() {
  return 2;
}

Movie::~Movie() {
  delete[] director;
}
