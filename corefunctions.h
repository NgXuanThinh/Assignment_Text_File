#ifndef _CORE_FUNCTION_H_
#define _CORE_FUNCTION_H_
#include <memory>
#include <vector>
#include <string>
class Month;
struct Day;
struct Score;
namespace CoreFunctions
{
    void viewScore(void (*func)(const std::string &, const int &,const int &,const int &,const int &));
    void addScore(const int & month, const int & day, const int & score_1,const int & score_2,const int & score_3);
    bool scoreExistsForDate(const int & month,const int & day);
    void removeScore(const int & line_index);
    void removeScore(const int & month,const int & day);
    void averageScores(std::shared_ptr<std::vector<std::string>> months,
    std::shared_ptr<std::vector<int>> days,
    std::shared_ptr<std::vector<int>> avg_score_of_each_day,
    int & avgScoreOfAllday);
}

#endif //_CORE_FUNCTION_H_
