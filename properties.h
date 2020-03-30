#ifndef _PROPERTIES_H_
#define _PROPERTIES_H_
#include "string"
class Month
{
    private:
        std::string str_month;
    public:
        explicit Month(std::string month);
        explicit Month(int month);
        static Month January();
        static Month February();
        static Month March();
        static Month April();
        static Month May();
        static Month June();
        static Month July();
        static Month August();
        static Month September();
        static Month October();
        static Month November();
        static Month December();
        //operator int() const;
        operator std::string() const;
};

struct Day
{
private:
    int day;
public:
    explicit Day(int d);
    operator int() const;
};

struct Score
{
    unsigned int score;
    explicit Score(unsigned int score);
    operator int() const;
};


class Properties
{
    private:
    Day day;
    Month month;
    Score score_1;
    Score score_2;
    Score score_3;
    public:
    Properties();
    Properties(Month m,Day d,Score sc_1, Score sc_2, Score sc_3);
    Day getDay() const;
    Month getMonth() const;
    Score getScore1() const;
    Score getScore2() const;
    Score getScore3() const;
    void setDay(Day d);
    void setMonth(Month m);
    void setScore1(Score score1);
    void setScore2(Score score2);
    void setScore3(Score score3);
    public:
    static size_t NumberofVariable()
    {
        return 5;
    }
};

#endif //_PROPERTIES_H_