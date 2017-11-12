# ifndef SYSTEM_H_INCLUDED
# define SYSTEM_H_INCLUDED

# include <iostream>
# include <string>
using namespace std;

class System{
	public:
		System(string);
		~System();

		// methods
		void readList(string);  						// read current YA alumni list
		int findAlum(int);								// find the specific user by input ID number, and return the index
		int searchID(string, string, int, string);		// user input their first name, last name, graduation year and major to find their ID number, then return ID number
		int addAlumni(string, string, int, string);		// if can't find user ID in the system, create new ID for the user, the function return ID number
		int getRanking();								// return ranking of the user
		int getEnd();
		void requestPoint(int);
		void redeemPoint(int);
		void inputAddress(string, string, int);
		void writeList(string);							// after modify the list output the up-to-date version.
		Alumni getAlumni(int);

		// help function
		void split(string, char, string[], int);
		void sortID(Alumni[]);						    // sort the list with ascending ID
		void sortPoint();                               // sort the list with descending Points

		// data member
		int user_index;
		int end_index;

	private:
		// data member
		Alumni YoungAlumni[100000];						// array of young alumni list, each object is one alum
		int max_cap = 100000;


};

# endif // SYSTEM_H_INCLUDED
