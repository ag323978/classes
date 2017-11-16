#include "digitalMedia.h"
#include "digitalMedia.cpp"
#include "movie.h"
#include "movie.cpp"
#include "music.h"
#include "music.cpp"
#include "videoGame.h"
#include "videoGame.cpp"
#include <cstring>
#include <iterator>
#include <vector>

using namespace std;

int main() {

  vector<DigitalMedia*> mediaList;
  cout << endl << endl << endl;
  cout << "-------------------------------------------------------------------------------------" << endl;
  cout << "|To create a database of digital media...                                           |" << endl;
  cout << "|Type 'ADD' to add either music, movies, or video games.                            |" << endl;
  cout << "|Type 'SEARCH' to find and print different medias that are currently in the database|" << endl;
  cout << "|Type 'DELETE' to delete an item                                                    |" << endl;
  cout << "|You can also type 'QUIT' to exit the program                                       |" << endl;
  cout << "-------------------------------------------------------------------------------------" << endl;
  cout << endl << endl << endl;
  
  while(true) {

    // array for command inputs
    char input[6];
    // basic elements shared by all types of media
    char typeOfMedia[9];
    char title[100];
    int year;

    // command inputs
    cout << "Type one of the commands listed above: ";
    cin >> input;

    // if user types add
    if(strcmp(input, "ADD") == 0) {
      // enter information of the media they want to add
      cout << "Enter the type of the media. Digital media includes 'VIDEOGAME', 'MOVIE', 'MUSIC': ";
      cin.ignore();
      cin.getline(typeOfMedia, 9);
      cout << "Enter the title please: ";
      cin.ignore();
      cin.getline(title, 100);
      cout << "Enter the year it was released: ";
      cin >> year;
      /* depending on the type of media the user chose,
	 enter the specific information of that type of media that it doesn't have in
	 common with the other types of media
       */
      // if user chose music
      if(strcmp(typeOfMedia, "MUSIC") == 0) {
	// enter artist, duration, and publisher of music
	char artist[75];
	int duration;
	char publisher[75];
	cout << "Enter the artist's name: ";
	cin.ignore();
	cin.getline(artist, 75);
	cout << "Enter the music's duration in seconds please: ";
	cin >> duration;
	cout << "Enter the publisher: ";
	cin.ignore();
	cin.getline(publisher, 75);
	// add the media to the vector 
	Music* temp = new Music(title, year, artist, publisher, duration);
	mediaList.push_back(temp);
      } // if user chose movie
      else if(strcmp(typeOfMedia, "MOVIE") == 0) {
	// enter director, duration, and rating of movie
	char director[75];
	int duration;
	float rating;
	cout << "Enter the movie's director: ";
	cin.ignore();
	cin.getline(director, 75);
	cout << "Enter the movie's duration in minutes please: ";
	cin >> duration;
	cout << "Enter the movie's rating, 1 out of 5 stars: ";
	cin >> rating;
	// add the media to the vector
	Movie* temp = new Movie(title, year, director, duration, rating);
	mediaList.push_back(temp);
      } // if user chose video game
      else if(strcmp(typeOfMedia, "VIDEOGAME") == 0) {
	// enter publisher and rating of video game
	char publisher[75];
	float rating;
	cout << "Enter the game's publisher: ";
	cin.ignore();
	cin.getline(publisher, 75);
	cout << "Enter the game's rating, 1 out of 10 stars: ";
	cin >> rating;
	// add the media to the vector
	VideoGame* temp = new VideoGame(title, year, publisher, rating);
	mediaList.push_back(temp);
      } else {
	// otherwise the user did not choose a valid digital media type
	cout << "Not a valid media type." << endl;
      }
    } else if(strcmp(input, "SEARCH") == 0) {
      cout << "You are going to search for an item" << endl;
    } else if(strcmp(input, "DELETE") == 0) {
      cout << "You are going to delete an item" << endl;
    } else if (strcmp(input, "QUIT") == 0) {
      cout << "Exiting program" << endl;
      break;
    } else {
      cout << "Invalid command" << endl;
    }
  }
}
