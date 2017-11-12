# include "Alumni.h"
# include "System.h"
# include <iostream>
# include <string>
using namespace std;

Alumni::Alumni(){

}

Alumni::Alumni(int id, string fname, string lname, int gyr, string mj){
	ID = id;
	first_name = fname;
	last_name = lname;
	grad_year = gyr;
	major = mj;
	address = "";
	state = "";
	zip = 0;
	gift = "";
	point = 0;
}

Alumni::~Alumni(){

}

void Alumni::set_ID(int id){
	ID = id;
	return;
}

int Alumni::get_ID(){
    return ID;
}

void Alumni::set_firstname(string fname){
    first_name = fname;
    return;
}

string Alumni::get_firstname(){
    return first_name;
}

void Alumni::set_lastname(string lname){
    last_name = lname;
    return;
}

string Alumni::get_lastname(){
    return last_name;
}

void Alumni::set_gradyr(int gyr){
    grad_year = gyr;
    return;
}

int Alumni::get_gradyr(){
    return grad_year;
}

void Alumni::set_major(string mj){
    major = mj;
    return;
}

string Alumni::get_major(){
    return major;
}

void Alumni::set_address(string addr){
    address = addr;
    return;
}

string Alumni::get_address(){
    return address;
}

void Alumni::set_state(string st){
    state = st;
    return;
}

string Alumni:: get_state(){
    return state;
}

void Alumni::set_zip(int zip_code){
    zip = zip_code;
    return;
}

int Alumni::get_zip(){
    return zip;
}

void Alumni::set_gift(string gft){
    gift = gft;
    return;
}

string Alumni::get_gift(){
    return gift;
}

void Alumni::set_point(int pt){
    point = pt;
    return;
}

int Alumni::get_point(){
    return point;
}
