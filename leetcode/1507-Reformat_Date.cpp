// Given a date string in the form Day Month Year, where:

// Day is in the set {"1st", "2nd", "3rd", "4th", ..., "30th", "31st"}.
// Month is in the set {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"}.
// Year is in the range [1900, 2100].
// Convert the date string to the format YYYY-MM-DD, where:

// YYYY denotes the 4 digit year.
// MM denotes the 2 digit month.
// DD denotes the 2 digit day.

// Example 1:

// Input: date = "20th Oct 2052"
// Output: "2052-10-20"
// Example 2:

// Input: date = "6th Jun 1933"
// Output: "1933-06-06"
// Example 3:

// Input: date = "26th May 1960"
// Output: "1960-05-26"

// Constraints:

// The given dates are guaranteed to be valid, so no error handling is necessary.

class Solution
{
public:
    string reformatDate(string date)
    {

        string m, day, year;
        if (date.size() == 13)
        {
            m = date.substr(5, 3);
            day = date.substr(0, 2);
            year = date.substr(9);
        }
        else
        {
            m = date.substr(4, 3);
            day = "0" + date.substr(0, 1);
            year = date.substr(8);
        }

        string month;

        if (m == "Jan")
            month = "01";
        else if (m == "Feb")
            month = "02";
        else if (m == "Mar")
            month = "03";
        else if (m == "Apr")
            month = "04";
        else if (m == "May")
            month = "05";
        else if (m == "Jun")
            month = "06";
        else if (m == "Jul")
            month = "07";
        else if (m == "Aug")
            month = "08";
        else if (m == "Sep")
            month = "09";
        else if (m == "Oct")
            month = "10";
        else if (m == "Nov")
            month = "11";
        else
            month = "12";

        string res = year + "-" + month + "-" + day;

        return res;
    }
};
