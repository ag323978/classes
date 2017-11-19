#ifndef DIGITALMEDIA_H
#define DIGITALMEDIA_H
#include <cstring>

class DigitalMedia{
 public:
  DigitalMedia(char* newTitle, int newYear);
  char* getTitle();
  int getYear();
  void printElements();
  virtual int getType();
  ~DigitalMedia();
 private:
  char* title;
  int year;
};

#endif
