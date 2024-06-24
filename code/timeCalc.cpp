#include <chrono>
#include <ctime>
#include <iostream>

int main(){

    //string userInput = "";
    //time_zone firstTimeZone;
    std::chrono::time_point startAgga = std::chrono::system_clock::now();
    std::chrono::time_point endAgga = std::chrono::system_clock::now();

    std::time_t end_time = std::chrono::system_clock::to_time_t(endAgga);

    std::cout << "Enter the first time zone:, leave blank for your system's time zone \n";
    //std::cin >> userInput;
    std::cout << "current time is " << std::ctime(&end_time) << "\n";

    return 0;
}
