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