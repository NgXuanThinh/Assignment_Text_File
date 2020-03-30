#include"properties.h"

std::string getMonth(int month)
{
    const static std::string Months[] = {"January","February","March",
    "April","May","June","July","August","September",
    "October","November","December"};
    return Months[month - 1];
}

 Month::Month(int v):str_month(getMonth(v))
 {

 }

Month Month::January()
{
    //return getMonth(1);
    return Month(1);
}
Month Month::February()
{
    //return getMonth(2);
    return Month(2);
}
Month Month::March()
{
    //return getMonth(3);
    return Month(3);
}
Month Month::April()
{
    //return getMonth(4);
    return Month(4);
}
Month Month::May()
{
    //return getMonth(5);
    return Month(5);
}
Month Month::June()
{
    //return getMonth(7);
    return Month(6);
}
Month Month::July()
{
    //return getMonth(8);
    return Month(7);
}
Month Month::August()
{
    //return getMonth(8);
    return Month(8);
}
Month Month::September()
{
    //return getMonth(9);
    return Month(9);
}
Month Month::October()
{
    //return getMonth(10);
    return Month(10);
}
Month Month::November()
{
    //return getMonth(11);
    return Month(11);
}
Month Month::December()
{
    //return getMonth(12);
    return Month(12);
}
// Month::operator int() const
// {
//     return month;
// }
Month::Month(std::string month):
str_month(month)
{

}

Month::operator std::string() const
{
    // std::string Months[]={"January","February","March",
    // "April","May","June","July","August","September",
    // "October","November","December"};
    // return Months[month - 1];
    return str_month;
}

Day::Day(int d):day(d)
{       
}
Day::operator int() const
{
    return day;
}

Score::Score(unsigned int score):score(score)
{       
}

Score::operator int() const{
    return score;
}


Properties::Properties():day(Day(1)),
month(Month::January()),
score_1(Score(0)),
score_2(Score(0)),
score_3(Score(0))
{
}

Properties::Properties(Month m,Day d,Score sc_1, Score sc_2, Score sc_3):
day(d),
month(m),
score_1(sc_1),
score_2(sc_2),
score_3(sc_3)
{
}

Day Properties::getDay() const
{
    return day;
}

Month Properties::getMonth() const
{
    return month;
}

Score Properties::getScore1() const
{
    return score_1;
}

Score Properties::getScore2() const
{
    return score_2;
}

Score Properties::getScore3() const
{
    return score_3;
}

void Properties::setDay(Day d)
{
    day = d;
}

void Properties::setMonth(Month m)
{
    month = m;
}

void Properties::setScore1(Score score1)
{
    score_1 = score1;
}

void Properties::setScore2(Score score2)
{
    score_2 = score2;
}

void Properties::setScore3(Score score3)
{
    score_3 = score3;
}