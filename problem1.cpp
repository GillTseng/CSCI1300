// Author: Enchieh Tseng
// Recitation: 110 – Monika Tak
//
// Assignment 3
// Problem 1

# include <iostream>
using namespace std;

/**
* Algorithm description:
*
*
*/

void menu (char);
int main()
{
    char a ='1';
    menu(a);
}

void story1 (string plur_noun, string occupation, string animal, string place)
{
    cout << "In the book War of the " << plur_noun << ", the main character is an anonymous " << occupation <<
    " who records the arrival of the " << animal << "s in " << place << "." << endl;
}

void story2 (string name, string state_country)
{
    cout << name << ", I've got a feeling we're not in " << state_country << " anymore." << endl;
}

void story3 (string first_name, string relative, string verb)
{
    cout << "Hello. My name is " << first_name << ". You killed my " << relative << ". Prepare to " << verb <<"." << endl;
}


void menu (char a)
{
    cout << "Which story would you like to play? Enter the number of the story (1, 2, or 3) or type q to quit:";
    cin >> a;
    if (a == '1')
    {
        string plur_noun, occupation, animal, place;
        cout << "Enter a plural noun: "<< endl;
        cin >> plur_noun;
        cout << "Enter an occupation: "<< endl;
        cin >> occupation;
        cout << "Enter an animal name: "<< endl;
        cin >> animal;
        cout << "Enter a place: "<< endl;
        cin >> place;
        story1(plur_noun,occupation,animal,place);
        menu(a);

    }
    else if (a == '2')
    {
        string name, state_country;
        cout << "Enter a name: "<< endl;
        cin >> name;
        cout << "Enter a state/country: "<< endl;
        cin >> state_country;
        story2(name,state_country);
        menu(a);
    }
    else if (a == '3')
    {
        string first_name, relative, verb;
        cout << "Enter a first name: "<< endl;
        cin >> first_name;
        cout << "Enter a relative: "<< endl;
        cin >> relative;
        cout << "Enter a verb: "<< endl;
        cin >> verb;
        story3(first_name,relative,verb);
        menu(a);
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
