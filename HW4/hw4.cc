#include <time.h>

#include <iostream>

using namespace std;

// complete the JulianDate class
// write your code in the JulianDae class
// complete the code in main
class JulianDate {
  // Make all your class access is public

  // first define your variable type and variable (year, month, day, hour, mins,
  // sec)
 public:
  int year, month, day, hour, mins, sec;
  // write your non-default constructor that set variables today's date
  // write your code here
  // Name it JulianDate
  JulianDate(int year, int month, int day, int hour, int mins, int sec) {
    this->year = year;
    this->month = month;
    this->day = day;
    this->hour = hour;
    this->mins = mins;
    this->sec = sec;
  }

  // Write your default constructor that takes nothing
  JulianDate() : year(0), month(0), day(0), hour(0), mins(0), sec(0) {}

  // write function that calculate julian number from given date
  // your function should return the value
  // use calc_juliandate as the function name
  // write your code here
  double calc_juliandate() {
    int a = (14 - month) / 12;
    int y = year + 4800 - a;
    int m = month + 12 * a - 3;

    double nDate =
        day + (153 * m + 2) / 5 + 365 * y + y / 4 - y / 100 + y / 400 - 32045;
    double nTime = (hour - 12) / 24.0 + mins / 1440.0 + sec / 86400.0;
    return nDate + nTime;
  }

  // write function that calculate difference between two Julian date
  // use diff_calc_juliandate as the function name
  // write your code here

  double diff_calc_juliandate(JulianDate other) {
    double x1 = calc_juliandate();
    double y1 = other.calc_juliandate();
    return x1 - y1;
  }
};

/*

Use the formula in the below web page in the calculate julian function

http://www.c-jump.com/bcc/c155c/Homework/a4_Serial_Julian_Date/a4_Serial_Julian_Date.html
https://www.aavso.org/jd-calculator

hh:mm:ss

00:00:00  0.0
12:00:00  0.5

18*365+18/4 - 18/100 + 18/400
18*364+4 = 6574

6574.041666666 --> Jan 1, 2018, 01:00:00
 */
// int JulianDate::EPOCH = 2000; // Jan.1 2000, 00:00:00 = 0

int main() {
  cout << "########" << endl;
  cout << "Main Problem" << endl;
  cout << "########" << endl;

  // Run your class on this code and calculate the difference of Julian number
  // below

  cout.precision(20);
  JulianDate x(2007, 2, 8, 0, 0,
               0);  // how many days since day 0? dy = (2018 - 2000) * 365
  double x1 = x.calc_juliandate();
  cout << x1 << endl;

  JulianDate y(2000, 12, 31, 0, 0, 1);
  double y1 = y.calc_juliandate();
  cout << y1 << endl;

  // manual calculation of the difference between two dates, e.g., x1 - y1 =
  // results print out the result
  //  write your code here
  double difference1 = x1 - y1;
  cout << "Manual Calculation: " << difference1 << endl;

  // Now use your class function to find the difference between two dates
  // print out the result
  // write your code here
  double difference2 = x.diff_calc_juliandate(y);
  cout << "Class Function Calculation: " << difference2 << endl;

  // example of date to Julian date format without hour/min/sec
  // 7/4/1776   2369916
  // 12/31/2000 2451910
  // 2/8/2007   2454140
  // 2/9/2007   2454141

  cout << "====[ end ]====" << endl;

  return 0;
}
