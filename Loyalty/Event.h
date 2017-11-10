#ifndef EVENT_H_INCLUDED
#define EVENT_H_INCLUDED

class Event{
	public:
	Event();
	~Event();
	void readEvent(string);
	void set_name(string);
	string get_name();
	void set_point(int);
	int get_point();
	
	private:
	string name[10];
	int point[10];
};