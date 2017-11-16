#ifndef DIGITALMEDIA_H
#define DIGITALMEDIA_H
#include <cstring>

class DigitalMedia{
 public:
  DigitalMedia(char* newTitle, int newYear);
  char* getTitle();
  int getYear();
  virtual int getType();
  virtual ~DigitalMedia();
 private:
  char* title;
  int year;
};

#endif
