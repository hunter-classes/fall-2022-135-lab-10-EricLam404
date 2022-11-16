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