#include <chrono>
#include <ctime>
#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <cmath>


//time zone structure
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

    //"global" variables
    std::string userFirstTimeZone = "";
    std::string userSecondTimeZone = "";
    //time_zone firstTimeZone;
    timeZone firstTimeZone;
    timeZone secondTimeZone;
    int calculatedOffset, utcOffset;
    bool use12Hour = false;
    auto end = std::chrono::system_clock::now();

    std::time_t end_time = std::chrono::system_clock::to_time_t(end);

    //getting input from user
    std::string userTimePref = "";
    std::cout << "12 hour or 24 hour?: ";
    std::getline(std::cin, userTimePref);
    std::cout << "\n";

    if(userTimePref == "12" || userTimePref == "12 hour"){
        use12Hour = true;
    }

    std::cout << "Enter the first time zone, e.x. EDT:";
    std::getline(std::cin, userFirstTimeZone);
    std::cout << "\n";
    std::cout << "Enter the second time zone: ";
    std::getline(std::cin, userSecondTimeZone);
    std::cout << "\n";

    //get local time from user
    std::transform(userFirstTimeZone.begin(), userFirstTimeZone.end(), userFirstTimeZone.begin(), ::toupper);
    std::transform(userSecondTimeZone.begin(), userSecondTimeZone.end(), userSecondTimeZone.begin(), ::toupper);
    std::tm timeToBeCalculated = *std::localtime(std::addressof(end_time));


    //finding time zones specified
    //probably should move this up to user input and ask user for input again if not found in array
    for(int x = 0; x < 14; x++){
        if(userFirstTimeZone == timeZones[x].zoneName){
            firstTimeZone = timeZones[x];
        }
        if(userSecondTimeZone == timeZones[x].zoneName){
            secondTimeZone = timeZones[x];
        }
    }

    //figure out which time zone is smaller (is that even the right way to word it?)
    bool firstZoneIsNegative = firstTimeZone.hoursOffset < 0;
    bool secondZoneIsNegative = secondTimeZone.hoursOffset < 0;

    //calcuating the hours offset
    //gonna need to do some more work because all it does is get from user's computer, not actually hours from the specified time zones
    //this doesn't do much, too bad!
    if(firstZoneIsNegative){
        calculatedOffset = secondTimeZone.hoursOffset + (-firstTimeZone.hoursOffset);



    }
    else if (secondZoneIsNegative){
        calculatedOffset = firstTimeZone.hoursOffset + (-secondTimeZone.hoursOffset);
    }


    //probably don't even need oldHours here?
    tm* gmtm = gmtime(&end_time);
    int firstTimeZoneHours = timeToBeCalculated.tm_hour;
    int newHours = calculatedOffset + timeToBeCalculated.tm_hour;

    //actual offset calculated here
    utcOffset = gmtm->tm_hour + secondTimeZone.hoursOffset;


    //printing is gonna happen here too
    if(use12Hour){
        if (newHours >= 13){
            newHours = newHours % 12;
            utcOffset = utcOffset % 12;
            //print pm hours

        }

    }
    else{
        if(newHours >= 24){
        newHours = newHours % 23;
        utcOffset = utcOffset % 23;
        //print 24 hours
        std::cout << "In the " << secondTimeZone.zoneName << "time zone, it's " << utcOffset << ":" << gmtm->tm_min << "\n";


        }
    }

    //std::cout << "current time is " << std::ctime(&end_time) << "\n";

    return 0;
}
