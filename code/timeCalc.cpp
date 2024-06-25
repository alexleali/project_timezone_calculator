#include <chrono>
#include <ctime>
#include <iostream>
#include <string>

struct timeZone {
    std::string zoneName;
    int hoursOffset;

};

int main(){

    //time zones
    timeZone timeZones[15]= {
        {"PDT", -7},
        {"MDT", -6},
        {"CDT", -5},
        {"EDT", -4},
        {"BRT", -3},
        {"UTC", 0},
        {"BST", 1},
        {"CEST", 2},
        {"MSK", 3},
        {"AST", 4},
        {"WAST", 5},
        {"MPST",8},
        {"JST",9},
        {"AEST",10},
        {"NZST",12},
    };

    std::string userFirstTimeZone = "";
    std::string userSecondTimeZone = "";
    //time_zone firstTimeZone;
    std::chrono::time_point firstTimeZone = std::chrono::system_clock::now();
    std::chrono::time_point secondTimeZone= std::chrono::system_clock::now();

    //std::time_t end_time = std::chrono::system_clock::to_time_t(secondTimeZone);

    //getting input from user
    std::cout << "Enter the first time zone:";
    std::getline(std::cin, userFirstTimeZone);
    std::cout << "\n";
    std::cout << "Enter the second time zone: ";
    std::getline(std::cin, userSecondTimeZone);
    std::cout << "\n";

    if(userFirstTimeZone == ""){
        firstTimeZone = std::chrono::system_clock::now();
    }

    //std::cout << date::

    //std::cout << "current time is " << std::ctime(&end_time) << "\n";

    return 0;
}
