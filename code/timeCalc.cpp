#include <chrono>
#include <ctime>
#include <iostream>
#include <string>

int main(){

    std::string userFirstTimeZone = "";
    std::string userSecondTimeZone = "";
    //time_zone firstTimeZone;
    std::chrono::time_point startAgga = std::chrono::system_clock::now();
    std::chrono::time_point endAgga = std::chrono::system_clock::now();

    std::time_t end_time = std::chrono::system_clock::to_time_t(endAgga);

    //getting input from user
    std::cout << "Enter the first time zone, leave blank for your system's time zone: ";
    std::getline(std::cin, userFirstTimeZone);
    std::cout << "\n";
    std::cout << "Enter the second time zone: ";
    std::getline(std::cin, userSecondTimeZone);
    std::cout << "\n";
    //std::cout << date::

    std::cout << "current time is " << std::ctime(&end_time) << "\n";

    return 0;
}
