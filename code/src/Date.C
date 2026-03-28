#include "Date.H"

int daysInMonth(int month, int year)
{
    int days[] = {31,28,31,30,31,30,31,31,30,31,30,31};

    if(month == 2)
    {
        if((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
            return 29;
    }

    return days[month - 1];
}


Date addMonths(const Date& d, int monthsParm)
{
    Date result = d;   // create a new Date object

    int totalMonths = result.mMonth + monthsParm;

    result.mYear += (totalMonths - 1) / 12;
    result.mMonth = ((totalMonths - 1) % 12) + 1;

    int maxDay = daysInMonth(result.mMonth, result.mYear);

    if(result.mDay > maxDay)
        result.mDay = maxDay;

    return result;
}

