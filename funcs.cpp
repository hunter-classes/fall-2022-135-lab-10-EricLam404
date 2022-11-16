#include <iostream>
#include "funcs.h"

int minutesSinceMidnight(Time time){
    return (time.h * 60) + time.m;
}

int minutesUntil(Time earlier, Time later){
    int earlierMin = (earlier.h * 60) + earlier.m;
    int laterrMin = (later.h * 60) + later.m;
    return laterrMin - earlierMin;
}

Time addMinutes(Time time0, int min){
    time0.m += min;
    int hr = time0.m / 60;
    time0.h += hr;
    time0.m = time0.m % 60;
    return time0;
}

std::string printMovie(Movie mv){
    std::string g;
    switch (mv.genre) {
        case ACTION   : g = "ACTION"; break;
        case COMEDY   : g = "COMEDY"; break;
        case DRAMA    : g = "DRAMA";  break;
        case ROMANCE  : g = "ROMANCE"; break;
        case THRILLER : g = "THRILLER"; break;
    }
    return mv.title + " " + g + " (" + std::to_string(mv.duration) + " min)";
}

std::string formatTime(Time t){
    return std::to_string(t.h) + ":" + std::to_string(t.m);
}

std::string printTimeSlot(TimeSlot ts){
    std::string str = printMovie(ts.movie);
    Time end = addMinutes(ts.startTime, ts.movie.duration);
    
    str += " [starts at " + formatTime(ts.startTime) + ", ends by " + formatTime(end) + "]";
    return str;
}

TimeSlot scheduleAfter(TimeSlot ts, Movie nextMovie){
    Time end = addMinutes(ts.startTime, ts.movie.duration);
    TimeSlot after = {nextMovie, end};
    return after;
}