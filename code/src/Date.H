#include <iostream>
#include <sstream>
class Date
{
public:
    int mDay;
    int mMonth;
    int mYear;
    bool mValid;

    Date()
    {
        mDay = 0;
        mMonth = 0;
        mYear = 0;
        mValid = true;
    }

    Date(int d, int m, int y)
    {
        mDay = d;
        mMonth = m;
        mYear = y;
        mValid = true;
    }

    bool isValid() const
    {
        return mValid;
    }

    void setNA()
    {
        mValid = false;
    }

    friend std::istream& operator>>(std::istream& in, Date& d)
    {
        std::cout << "Enter Day: ";
        in >> d.mDay;

        std::cout << "Enter Month: ";
        in >> d.mMonth;

        std::cout << "Enter Year: ";
        in >> d.mYear;

        d.mValid = true;

        return in;
    }

    friend std::ostream& operator<<(std::ostream& out, const Date& d)
    {
        if(!d.mValid){
            out << "N/A";
        }
        else{
            // out << d.mDay << "/" << d.mMonth << "/" << d.mYear;
            std::ostringstream oss;
            oss << d.mDay << "/" << d.mMonth << "/" << d.mYear;
            out << oss.str();  
        } 

        return out;
    }
};

int daysInMonth(int month, int year);
Date addMonths(const Date& d, int monthsParm);