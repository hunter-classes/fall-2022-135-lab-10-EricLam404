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

bool timeOverlap(TimeSlot ts1, TimeSlot ts2){
    int start1 = minutesSinceMidnight(ts1.startTime);
    int start2 = minutesSinceMidnight(ts2.startTime);
    if(start1 < start2){
        Time end = addMinutes(ts1.startTime, ts1.movie.duration);
        if(minutesUntil(end, ts2.startTime) < 0){
            return true;
        }
    }
    else{
        Time end = addMinutes(ts2.startTime, ts2.movie.duration);
        if(minutesUntil(end, ts1.startTime) < 0){
            return true;
        }
    }
    return false;
}