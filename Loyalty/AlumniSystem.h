# ifndef ALUMNISYSTEM_H_INCLUDED
# define ALUMNISYSTEM_H_INCLUDED

# include <iostream>
# include <string>
using namespace std;

class AlumniSystem{
	public:
		AlumniSystem();
		AlumniSystem(string,string,string);             // when create AlumniSystem object, it will read current alumni record file
		~AlumniSystem();

		// methods
		bool readList(string);  						// read current alumni list
		bool readEventList(string);                     // read event list that user can request points
		bool readGiftList(string);                      // read gift list that user can redeem points
		bool findAlum(int);								// find the specific user by input ID number, and return the index
		bool searchAlum(string, string, int, string);		// user input their first name, last name, graduation year and major to find their ID number, then return ID number
		bool addAlumni(string, string, int, string);		// if can't find user ID in the system, create new ID for the user, the function return ID number
		int getRanking(int);								// return ranking of the user
		void inputAddress(string, string, int);         // input address information when user redeem points
		string get_Events(int);
		int get_EventPoints(int);
		string get_Gifts(int);
		int get_GiftPoints(int);
		bool writeList(string);							// after modify the list output the up-to-date version.
		Alumni getAlumni(int);                          // retrieve specific alumni record within Alumni array

		void welcomeLines();
		bool idLogin();
		bool nameLogin();
		void loginLines();
		void wrongmsgLines();
		void menuLines();
		bool requestPoint();
		bool redeemPoint();
		void updateLines();
		void enterAddress();

		// help function
		void split(string, char, string[], int);        // parsing string information after read line from input file
		void sortID(Alumni[]);						    // sort the list with ascending ID
		void sortPoint(Alumni[]);                       // sort the list with descending Points

		// data member
		int user_index;                                 // after find the user's record store the index for further usage e.g. update points
		int end_index;
		int user_ranking;                                  // indicate where is the last record of the YoungAlumni array

	private:
		// data member
		Alumni YoungAlumni[1500];						// array of young alumni list, each object is one alum
		int max_cap = 1500;
		string events[10];                              // the array is for storing event list
		int events_points[10];                          // the array is for storing how many points the event worth
		string gifts[5];                                // the array is for storing gift list
		int gifts_points[5];                            // the array is for storing how many points the gift worth

};

# endif // ALUMNISYSTEM_H_INCLUDED
