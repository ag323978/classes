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
  cout << endl << endl;
  
  while(true) {

    // array for command inputs
    char input[7];

    // command inputs
    cout << endl;
    cout << "Type one of the commands listed above: ";
    cin.getline(input, 7);
    
    // if user types add
    if(strcmp(input, "ADD") == 0) {
      // basic information shared by all types of digital media
      char typeOfMedia[10];
      char *title = new char[100];
      int year;
      // enter information of the media they want to add
      cout << "Enter the type of the media. Digital media includes 'VIDEOGAME', 'MOVIE', 'MUSIC': ";
      cin.getline(typeOfMedia, 10);
      /*cout << "Enter the title please: ";
      cin.getline(title, 100);
      cout << "Enter the year it was released: ";
      cin >> year;
      cin.get();*/
      /* depending on the type of media the user chose,
	 enter the specific information of that type of media that it doesn't have in
	 common with the other types of media */
      // if user chose music
      if(strcmp(typeOfMedia, "MUSIC") == 0) {
	// enter artist, duration, and publisher of music
	char *artist = new char[75];
	char *publisher = new char[75];
	int duration;
	cout << "Enter the title please: ";
	cin.getline(title, 100);
	cout << "Enter the year it was released: ";
	cin >> year;
	cin.get();
	cout << "Enter the artist's name: ";     	
	cin.getline(artist, 75);
	cout << "Enter the music's duration in seconds please: ";
	cin >> duration;
	cin.get();
	cout << "Enter the publisher: ";
	cin.getline(publisher, 75);
	// add the media to the vector 
	Music* temp = new Music(title, year, artist, publisher, duration);
	mediaList.push_back(temp);
      } // if user chose movie
      else if(strcmp(typeOfMedia, "MOVIE") == 0) {
	// enter director, duration, and rating of movie
	char *director = new char[75];
	int duration;
	float rating;
	cout << "Enter the title please: ";
	cin.getline(title, 100);
	cout << "Enter the year it was released: ";
	cin >> year;
	cin.get();
	cout << "Enter the movie's director: ";
	cin.getline(director, 75);
	cout << "Enter the movie's duration in minutes please: ";
	cin >> duration;
	cin.get();
	cout << "Enter the movie's rating, 1 out of 10 stars: ";
	cin >> rating;
	cin.get();
	// add the media to the vector
	Movie* temp = new Movie(title, year, director, duration, rating);
	mediaList.push_back(temp);
      } // if user chose video game
      else if(strcmp(typeOfMedia, "VIDEOGAME") == 0) {
	// enter publisher and rating of video game
	char *publisher = new char[75];
	float rating;
	cout << "Enter the title please: ";
	cin.getline(title, 100);
	cout << "Enter the year it was released: ";
	cin >> year;
	cin.get();
	cout << "Enter the game's publisher: ";
	cin.getline(publisher, 75);
	cout << "Enter the game's rating, 1 out of 10 stars: ";
	cin >> rating;
	cin.get();
	// add the media to the vector
	VideoGame* temp = new VideoGame(title, year, publisher, rating);
	mediaList.push_back(temp);
      } else {
	// otherwise the user did not choose a valid digital media type
	cout << "Not a valid media type." << endl;
      }
    } else if(strcmp(input, "SEARCH") == 0) {
      // ask if user wants to search by title or year
      char *searchType = new char[5];
      cout << "Do you want to search by 'TITLE' or 'YEAR': ";
      cin.getline(searchType, 6);
      vector<DigitalMedia*>::iterator it;
      //int count = 0;
      // if they want to search by title
      if(strcmp(searchType, "TITLE") == 0) {
	char *searchTitle = new char[100];
	// ask for the title they are searching for
	cout << "Please enter the title you are looking for: ";
	cin.getline(searchTitle, 100);
	for(it = mediaList.begin(); it != mediaList.end(); it++) {
	  if(strcmp((*it)->getTitle(), searchTitle) == 0) {
	    // if the result is a movie
	    if((*it)->getType() == 2) {
	      // print all of the information
	      ((Movie*)(*it))->printElements();
	    } // if the result is music
	    else if ((*it)->getType() == 3) {
	      // print all of the information
	      ((Music*)(*it))->printElements();
	    } // if the result is a video game
	    else if((*it)->getType() == 4) {
	      // print all of the information
	      ((VideoGame*)(*it))->printElements();
	    }
	  }
	}
      } else if(strcmp(searchType, "YEAR") == 0) {
	int searchYear;
	// ask user for the year they want to search in
	cout << "Enter the year you want to search in: ";
        cin >> searchYear;
	cin.get();
	for(it = mediaList.begin(); it != mediaList.end(); it++) {
	  if((*it)->getYear() == searchYear) {
	    // if the result is a movie
	    if((*it)->getType() == 2) {
	      // print all information
	      ((Movie*)(*it))->printElements();
	    } // if the result is music
	    else if((*it)->getType() == 3) {
	      // print all the information
	      ((Music*)(*it))->printElements();
	    } // if the result is a video game
	    else if((*it)->getType() == 4) {
	      // print all the information
	      ((VideoGame*)(*it))->printElements();
	    }
	  }
	}
      } // if the user chose a search type other than 'TITLE' or 'YEAR' its invalid
      else {
	cout << "Invalid search type." << endl;
	continue;
      }
    } // if user wants to delete a media from the list
    else if(strcmp(input, "DELETE") == 0) {
      cout << "You are going to delete an item" << endl;
    } // program ends when user quits
    else if (strcmp(input, "QUIT") == 0) {
      cout << "Exiting program." << endl;
      break;
    } else {
      cout << "Invalid command" << endl;
    }
  }
}
