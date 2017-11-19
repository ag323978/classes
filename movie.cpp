#include "movie.h"
#include <iostream>
#include <cstring>

using namespace std;

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

void Movie::printElements() {
  cout << "Title: " << getTitle() << endl;
  cout << "Year: " << getYear() << endl;
  cout << "Director: " << getDirector() << endl;
  cout << "Duration: " << getDuration() << " minutes" << endl;
  cout << "Rating: " << getRating() << endl;
  cout << endl;
}

Movie::~Movie() {
  delete[] director;
}
