#include <chrono>
#include <ctime>
#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>

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
    timeZone firstTimeZone;
    timeZone secondTimeZone;
    int calculatedOffset;
    auto end = std::chrono::system_clock::now();

    std::time_t end_time = std::chrono::system_clock::to_time_t(end);

    //getting input from user
    std::cout << "Enter the first time zone, e.x. EDT:";
    std::getline(std::cin, userFirstTimeZone);
    std::cout << "\n";
    std::cout << "Enter the second time zone: ";
    std::getline(std::cin, userSecondTimeZone);
    std::cout << "\n";

    std::transform(userFirstTimeZone.begin(), userFirstTimeZone.end(), userFirstTimeZone.begin(), ::toupper);
    std::transform(userSecondTimeZone.begin(), userSecondTimeZone.end(), userSecondTimeZone.begin(), ::toupper);
    //std::cout << std::ctime(&end_time) << "\n";
    std::tm timeToBeCalculated = *std::localtime(std::addressof(end_time));
    std::cout << timeToBeCalculated.tm_hour << "\n";

    for(int x = 0; x < 14; x++){
        if(userFirstTimeZone == timeZones[x].zoneName){
            firstTimeZone = timeZones[x];
        }
        if(userSecondTimeZone == timeZones[x].zoneName){
            secondTimeZone = timeZones[x];
        }
    }

    bool firstZoneIsNegative = firstTimeZone.hoursOffset < 0;
    bool secondZoneIsNegative = secondTimeZone.hoursOffset < 0;

    if(firstZoneIsNegative){
        calculatedOffset = secondTimeZone.hoursOffset + (-firstTimeZone.hoursOffset);


    }
    else if (secondZoneIsNegative){
        calculatedOffset = firstTimeZone.hoursOffset + (-secondTimeZone.hoursOffset);
    }

    int oldHours = timeToBeCalculated.tm_hour;
    int newHours = calculatedOffset + timeToBeCalculated.tm_hour;

    if(newHours => 24){
        newHours = newHours % 23
    }


    //std::cout << newHours << "\n";

    //std::cout << "current time is " << std::ctime(&end_time) << "\n";

    return 0;
}
