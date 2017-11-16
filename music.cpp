#include "music.h"
#include <cstring>

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
  return 1;
}

Music::~Music() {
  delete[]publisher;
  delete[]artist;
}
