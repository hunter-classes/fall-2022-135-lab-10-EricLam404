#include <iostream>
#include "funcs.h"

int main() {
    std::cout << "Task A \n";
    Time t1 = {10, 0};
    Time t2 = {10, 30};
    Time t3 = {13, 40};
    std::cout << "minutesSinceMidnight( {10, 0} ) \n";
    std::cout << minutesSinceMidnight(t1) << '\n';
    std::cout << "minutesUntil( {10, 30}, {13, 40} ) \n";
    std::cout << minutesUntil(t2, t3 ) << '\n';

    std::cout << "\nTask B \n";
    Time t4 = {8, 10};
    Time addTime = addMinutes(t4, 75);

    std::cout << "addMinutes({8, 10}, 75) \n";
    std::cout << formatTime(addTime) << '\n';

    std::cout << "\nTask C \n";
    Movie movie1 = {"Back to the Future", COMEDY, 116};
    Movie movie2 = {"Black Panther", ACTION, 134};

    TimeSlot morning = {movie1, {9, 15}};  
    TimeSlot daytime = {movie2, {12, 15}}; 
    TimeSlot evening = {movie2, {16, 45}};
    
    std::cout << "printTimeSlot(morning) \n";
    std::cout << printTimeSlot(morning) << '\n';

    std::cout << "printTimeSlot(daytime) \n";
    std::cout << printTimeSlot(daytime) << '\n';

    std::cout << "printTimeSlot(evening) \n";
    std::cout << printTimeSlot(evening) << '\n';

    std::cout << "\nTask D \n";

    Movie movie = {"Back to the Future", COMEDY, 116};
    
    TimeSlot first = {movie, {9, 15}};  
    Time firstEnd = addMinutes(first.startTime, first.movie.duration);
    TimeSlot after = scheduleAfter(first, movie);
    Time afterEnd = addMinutes(after.startTime, after.movie.duration);

    std::cout << "scheduleAfter(first, movie) \n";
    std::cout << "First movie timeslot: " << formatTime(first.startTime) << "-" << formatTime(firstEnd) << "\n";
    std::cout << "Second movie timeslot: " << formatTime(after.startTime) << "-" << formatTime(afterEnd) << "\n";    
    
    std::cout << "\nTask E \n";
    TimeSlot timeslot1 = {movie1, {9, 15}};  
    TimeSlot timeslot2 = {movie2, {11, 15}}; 
    TimeSlot timeslot3 = {movie2, {12, 15}};
    TimeSlot timeslot4 = {movie2, {14, 55}};
    
    std::cout << "timeOverlap(timeslot1, timeslot2) \n";
    std::cout << std::boolalpha << timeOverlap(timeslot1, timeslot2) << '\n';

    std::cout << "timeOverlap(timeslot2, timeslot3) \n";
    std::cout << std::boolalpha << timeOverlap(timeslot2, timeslot3) << '\n';

    std::cout << "timeOverlap(timeslot3, timeslot4) \n";
    std::cout << std::boolalpha << timeOverlap(timeslot3, timeslot4) << '\n';
    return 0;
}
