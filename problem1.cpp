// Author: Enchieh Tseng
// Recitation: 110 – Monika Tak
//
// Assignment 3
// Problem 1

/**
* Algorithm description:
* The function is a story generator, the user will be asked to select a story (1, 2 or 3)
* after the user select one of the options, the user will be asked to enter several strings
* the strings that user inputted will be used in the story that they selected.
*/


# include <iostream>
using namespace std;

void menu ();

int main()
{
    menu();
}

void story1 (void)
{
    string plur_noun,occupation,animal,place;
    cout << "Enter a plural noun: "<< endl;
    cin >> plur_noun;
    cout << "Enter an occupation: "<< endl;
    cin >> occupation;
    cout << "Enter an animal name: "<< endl;
    cin >> animal;
    cout << "Enter a place: "<< endl;
    cin >> place;
    cout << "In the book War of the " << plur_noun << ", the main character is an anonymous " << occupation <<
    " who records the arrival of the " << animal << "s in " << place << "." << endl;
}

void story2 (void)
{
    string name, state_country;
    cout << "Enter a name: "<< endl;
    cin >> name;
    cout << "Enter a state/country: "<< endl;
    cin >> state_country;
    cout << name << ", I've got a feeling we're not in " << state_country << " anymore." << endl;
}

void story3 (void)
{
    string first_name, relative, verb;
    cout << "Enter a first name: "<< endl;
    cin >> first_name;
    cout << "Enter a relative: "<< endl;
    cin >> relative;
    cout << "Enter a verb: "<< endl;
    cin >> verb;
    cout << "Hello. My name is " << first_name << ". You killed my " << relative << ". Prepare to " << verb <<"." << endl;
}


void menu (void)
{
    char a;
    cout << "Which story would you like to play? Enter the number of the story (1, 2, or 3) or type q to quit:";
    cin >> a;
    if (a == '1')
    {
        story1();
        menu();

    }
    else if (a == '2')
    {
        story2();
        menu();
    }
    else if (a == '3')
    {
        story3();
        menu();
    }
    else if (a == 'q')
    {
        cout << "good bye";
    }
    else
    {
        cout << "Valid choice not selected.";
    }
}
