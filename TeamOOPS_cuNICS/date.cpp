#include "date.h"
#include "constants.h"
Date::Date()
{

}

Date::Date(int day, int month, int year)
{
    this->day = day;
    this->year = year;
    this->month = month;
}

Date::~Date()
{

}

//----- Getters -----
int Date::getDay()
{
    return day;
}

int Date::getMonth()
{
    return month;
}

int Date::getYear()
{
    return year;
}

//----- Operators -----
bool Date::operator<(Date& d) const
{
    if (this->year < d.getYear()) {
        return true;
    }
    else if (this->year == d.getYear() &&
             this->month < d.getMonth()) {
        return true;
    }
    else if (this->year == d.getYear() &&
             this->month == d.getMonth() &&
             this->day < d.getDay()) {
        return true;
    }
    else {
        return false;
    }
}

bool Date::operator>(Date& d) const
{
    return !(*this <= d);
}

bool Date::operator<=(Date& d) const
{
    return (*this < d || *this == d);
}

bool Date::operator>=(Date& d) const
{
    return (*this > d || *this == d);
}


bool Date::operator==(Date& d) const
{
    if (this->year == d.getYear() &&
        this->month == d.getMonth() &&
        this->day == d.getDay()) {
        return true;
    }
    return false;
}

