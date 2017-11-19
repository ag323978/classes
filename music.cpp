#include "music.h"
#include <iostream>
#include <cstring>

using namespace std;

Music::Music(char* newTitle, int newYear, char* newArtist, char* newPublisher, int newDuration):DigitalMedia(newTitle, newYear) {
  artist = newArtist;
  publisher = newPublisher;
  duration = newDuration;
}

char* Music::getArtist() {
  return artist;
}

char* Music::getPublisher() {
  return publisher;
}

int Music::getDuration() {
  return duration;
}
int Music::getType() {
  return 3;
}

void Music::printElements() {
  cout << "Title: " << getTitle() << endl;
  cout << "Year: " << getYear() << endl;
  cout << "Artist: " << getArtist() << endl;
  cout << "Publisher: " << getPublisher() << endl;
  cout << "Duration: " << getDuration() << " seconds" << endl;
  cout << endl;
}

Music::~Music() {
  delete[]publisher;
  delete[]artist;
}
