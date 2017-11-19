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
      char *searchType = new char[6];
      cout << "Do you want to search by 'TITLE' or 'YEAR': ";
      cin.getline(searchType, 6);
      //iterator
      vector<DigitalMedia*>::iterator it;
      // if they want to search by title
      if(strcmp(searchType, "TITLE") == 0) {
	char *searchTitle = new char[100];
	// ask for the title they are searching for
	cout << "Please enter the title you are looking for: ";
	cin.getline(searchTitle, 100);
	cout << endl;
	/* iterate through the vector of all media to see if the title the user is searching for
	   matches with one or more from the vector */
	for(it = mediaList.begin(); it != mediaList.end(); it++) {
	  if(strcmp((*it)->getTitle(), searchTitle) == 0) {
	    // if the result is a movie
	    if((*it)->getType() == 2) {
	      // print all of the information
	      cout << "---Movie---" << endl;
	      ((Movie*)(*it))->printElements();
	    } // if the result is music
	    else if ((*it)->getType() == 3) {
	      // print all of the information
	      cout << "---Music---" << endl;
	      ((Music*)(*it))->printElements();
	    } // if the result is a video game
	    else if((*it)->getType() == 4) {
	      // print all of the information
	      cout << "---Videogame---" << endl;
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
	cout << endl;
	/* iterate through the vector of all media to see if the title the user is searching for 
	   matches with one or more from the vector */
	for(it = mediaList.begin(); it != mediaList.end(); it++) {
	  if((*it)->getYear() == searchYear) {
	    // if the result is a movie
	    if((*it)->getType() == 2) {
	      // print all information
	      cout << "---Movie---" << endl;
	      ((Movie*)(*it))->printElements();
	    } // if the result is music
	    else if((*it)->getType() == 3) {
	      // print all the information
	      cout << "---Music---" << endl;
	      ((Music*)(*it))->printElements();
	    } // if the result is a video game
	    else if((*it)->getType() == 4) {
	      // print all the information
	      cout << "---Videogame---" << endl;
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
      // type
      char *deleteType = new char[6];
      // confirms if they want to delete the item
      char verify[4];
      // ask them if they want to delete by title or year
      cout << "Would you like to delete by 'TITLE' or 'YEAR': ";
      cin.getline(deleteType, 6);
      // iterator
      vector<DigitalMedia*>::iterator it;
      if (strcmp(deleteType, "TITLE") == 0) {
	// ask for title that user wants to delete
	char *deleteTitle = new char[100];
	cout << "Enter the title you want to remove: ";
	cin.getline(deleteTitle, 100);
	cout << endl;
	// iterate through the vector of all medias to see if it matches the one the user wnats
	for(it = mediaList.begin(); it != mediaList.end();) {
	  if(strcmp((*it)->getTitle(), deleteTitle) == 0) {
	    // if the media is a movie
	    if((*it)->getType() == 2) {
	      // display the information
	      cout << "---Movie---" << endl;
	      ((Movie*)(*it))->printElements();
	    } // if the media is music
	    else if((*it)->getType() == 3) {
	      // display the information
	      cout << "---Music---" << endl;
	      ((Music*)(*it))->printElements();
	    } // if the media is a videogame
	    else if((*it)->getType() == 4) {
	      cout << "---Videogame---" << endl;
	      ((VideoGame*)(*it))->printElements();
	    }
	    // verify with user if they want to delete the media
	    cout << "Are you sure you want to delete this? Type 'YES' or 'NO': ";
	    cin.getline(verify, 4);
	    // if user says yes then delete it
	    if(strcmp(verify, "YES") == 0) {
	      delete *it;
	      it = mediaList.erase(it);
	    } // if user answers no contine iterating through vector to find the right media
	    else if(strcmp(verify, "NO") == 0) {
	      ++it;
	    } // if user doesn't answer correctly then contine through iterator
	    else {
	      cout << "Invalid answer" << endl;
	      ++it;
	      //break;
	    }
	  } // if the deleteTitle doesn't match the media in the vector continue iterating
	  else {
	    ++it;
	  }
	}
      } else if(strcmp(deleteType, "YEAR") == 0) {
	// the yeah in which the media the user wants to delete is in
	int deleteYear;
	cout << "Enter the year in which the media you want to delete is in: ";
	cin >> deleteYear;
	cin.get();
	cout << endl;
	// iterate through vector to see if the year matches any of the medias
	for(it = mediaList.begin(); it != mediaList.end();) {
	  if ((*it)->getYear() == deleteYear) {
	    // if the media is a movie
	    if((*it)->getType() == 2) {
	      // display it's information
	      cout << "---Movie---" << endl;
	      ((Movie*)(*it))->printElements();
	    } // if the media is music
	    else if((*it)->getType() == 3) {
	      // display it's information
	      cout << "---Music---" << endl;
	      ((Music*)(*it))->printElements();
	    } // if the media is a video game
	    else if((*it)->getType() == 4) {
	      // display it's information
	      ((VideoGame*)(*it))->printElements();
	    }
	    cout << "Are you sure you want to delete this? Type 'YES' or 'NO': ";
	    cin.getline(verify, 4);
	    // if the user answers yes then delete the media
	    if(strcmp(verify, "YES") == 0) {
	      delete *it;
	      it = mediaList.erase(it);
	    } // if the user answers no contune iterating through the vector
	    else if (strcmp(verify, "NO") == 0) {
	      ++it;
	    } // otherwise the user didn't answer correctly
	    else {
	      cout << "Invalid entry" << endl;
	      ++it;
	      //break;
	    }
	  } // if the deleteYear doesn't match the media then continue through the vector
	  else {
	    ++it;
	  }
	}
      } // the user didn't choose a valid delete type
      else {
	cout << "Not a valid delete type" << endl;
      }
    } // program ends when user quits
    else if (strcmp(input, "QUIT") == 0) {
      cout << "Exiting program." << endl;
      break;
    } else {
      cout << "Invalid command" << endl;
    }
  }
}
