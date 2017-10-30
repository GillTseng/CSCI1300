#include <iostream>
#include <string>
using namespace std;

class Robot{
    public:
        Robot(int x_pos, int y_pos, char heading_dir){
            x = x_pos;
            y = y_pos;
            heading = heading_dir;
        }

        ~Robot(){}

        int getX(){
            return x;
        }
        int getY(){
            return y;
        }
        char getHeading(){
            return heading;
        }
        void setX(int x_new){
            x = x_new;
        }
        void setY(int y_new){
            y = y_new;
        }
        void setHeading(char heading_new){
            heading = heading_new;
        }
        void turnLeft(){
            if (heading == 'N'){
                heading = 'W';
            } else if (heading == 'W'){
                heading = 'S';
            } else if (heading == 'S'){
                heading = 'E';
            } else {
                heading ='N';
            }
        }
        void turnRight(){
            if (heading == 'N'){
                heading ='E';
            } else if (heading == 'E'){
                heading ='S';
            } else if (heading == 'S'){
                heading ='W';
            } else {
                heading ='N';
            }
        }
        void moveForward(){
            if (heading == 'N') {
                y = y + 1;
            } else if (heading == 'S') {
                y = y - 1;
            } else if (heading == 'E') {
                x = x + 1;
            } else {
                x = x - 1;
            }
        }

    private:
        int x;
        int y;
        char heading;
};

int main(){
    Robot robot1(1,1,'N');
    robot1.moveForward();
    robot1.setX(5);
    robot1.turnLeft();
    cout << robot1.getX() <<' ' << robot1.getY() <<' ' << robot1.getHeading();
}
