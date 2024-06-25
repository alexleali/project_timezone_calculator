#include <chrono>
#include <ctime>
#include <iostream>
#include <string>

stuct {
    int hoursOffset;
    string zoneName;
} timezone;

int main(){

    //time zones
    std::string timeZones[15][2] = {
        {"PDT", "-07"},
        {"MDT", "-06"},
        {"CDT", "-05"},
        {"EDT", "-04"},
        {"BRT", "-03"},
        {"UTC", "00"},
        {"BST", "+01"},
        {"CEST", "+02"},
        {"MSK", "+03"},
        {"AST", "+04"},
        {"WAST", "+05"},
        {"MPST","+08"},
        {"JST","+09"},
        {"AEST","+10"},
        {"NZST","+12"},
    };

    std::string userFirstTimeZone = "";
    std::string userSecondTimeZone = "";
    //time_zone firstTimeZone;
    std::chrono::time_point firstTimeZone = std::chrono::system_clock::now();
    std::chrono::time_point secondTimeZone= std::chrono::system_clock::now();

    //std::time_t end_time = std::chrono::system_clock::to_time_t(secondTimeZone);

    //getting input from user
    std::cout << "Enter the first time zone";
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
