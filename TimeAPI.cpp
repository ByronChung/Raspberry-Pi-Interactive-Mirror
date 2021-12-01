//Class to return formatted time
//Implements API Interface for use with model class

#include "TimeAPI.h"

std::string& TimeAPI::call()
{
    stringstream buffer; //a

    int seconds, minutes, hours;
    string str;

    //Storing total seconds
    time_t total_seconds=time(0);

    //Getting values of seconds, minutes and hours
    struct tm* ct=localtime(&total_seconds);

    seconds=ct->tm_sec;
    minutes=ct->tm_min;
    hours=ct->tm_hour;

    //Converting it into 12 hour format
    if(hours>=12)
      str="PM";
    else
      str="AM";
    hours=hours>12?hours-12:hours;

    buffer << (hours<10?"0":"") << hours <<":" << (minutes<10?"0":"") << minutes << ":" << (seconds<10?"0":"") << seconds << " " << str <<endl;

    output = buffer.str();

    return output;
}

