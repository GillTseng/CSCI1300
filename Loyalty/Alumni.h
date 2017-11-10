# ifndef ALUMNI_H_INCLUDED
# define ALUMNI_H_INCLUDED

# include <iostream>
# include <string>
using namespace std;

class Alumni{
	public:
		Alumni();
		Alumni(int, string, string, int, string);
		~Alumni();

		// methods
		void set_ID(int);
		int get_ID();
		void set_firstname(string);
		string get_firstname();
		void set_lastname(string);
		string get_lastname();
		void set_gradyr(int);
		int get_gradyr();
		void set_major(string);
		string get_major();
		void set_address(string);
		string get_address();
		void set_state(string);
		string get_state();
		void set_zip(int);
		int get_zip();
		void set_gift(string);
		int get_gift();
		void set_point(int);
		int get_point();


	private:
		// data member
		int ID;
		string first_name;
		string last_name;
		int grad_year;
		string major;
		string address;
		string state;
		int zip;
		string gift;
		int point;
};

# endif // ALUMNI_H_INCLUDED
