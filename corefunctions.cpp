#include "corefunctions.h"
#include "txtio.h"
#include "properties.h"
#include "string_converter.h"
#include <string>
#include <iostream>



namespace CoreFunctions
{

    const std::string NameFile()
    {
        static std::string namefile = "score.txt";
        return namefile;
    }

    int OnlyInputNumber(const char * pmt)
    {
	    char *p, s[100];
	    int n;
	    while (fgets(s, sizeof(s), stdin)) {
	    	n = strtol(s, &p, 10);
	    	if (p == s || *p != '\n') {
	    		std::cout<<pmt;
	    	}
	    	else break;
	    }
	return n;
    }

    //View all Scores (core)
    void viewScore(void (*func)(const std::string &, const int &,const int &,const int &,const int &))
    {
        std::shared_ptr<std::vector<std::string>> source_ptr = StreamIO::Readfile(NameFile());
        for(int i = 0; i < source_ptr->size(); i++)
        {
            Properties p;
            if(StringCoverter::StringToProperties((*source_ptr)[i],p))
            {
               func(p.getMonth(),p.getDay(),p.getScore1(),p.getScore2(),p.getScore3());
            }
        } 
    }

    bool scoreExistsForDate(const int & month,const int & day)
    {
        std::shared_ptr<std::vector<std::string>> string_list_ptr = StreamIO::Readfile(NameFile());
        Month m(month);
        for(auto && tmp : *string_list_ptr)
        {
            Properties property;
            if(StringCoverter::StringToProperties(tmp,property))
            {
                if((std::string)m == (std::string)property.getMonth()
                    && day == property.getDay())
                {
                    return true;
                }

            }
        }
        return false;
    }

    //Average Scores(core)
    void averageScores(std::shared_ptr<std::vector<std::string>> months,
    std::shared_ptr<std::vector<int>> days,
    std::shared_ptr<std::vector<int>> avg_score_of_each_day,
    int & avgScoreOfAllday)
    {
        std::shared_ptr<std::vector<std::string>> source_ptr = StreamIO::Readfile(NameFile());
        int sum_of_avg_score = 0;
        for(int i = 0; i < source_ptr->size(); i++)
        {
            Properties p;
            if(StringCoverter::StringToProperties((*source_ptr)[i],p))
            {
                months->push_back(std::move(p.getMonth()));
                days->push_back(std::move(p.getDay()));
                int avg_score = (p.getScore1() + p.getScore3() + p.getScore3())/3;
                sum_of_avg_score += avg_score;
                avg_score_of_each_day->push_back(avg_score);
            }
        }
        int size = avg_score_of_each_day->size();
        avgScoreOfAllday = size == 0 ? 0 : sum_of_avg_score / size;
    }

    //Add a Score(core)
    void addScore(const int & month, const int & day, const int & score_1,const int & score_2,const int & score_3)
    {
        Properties tmp = Properties(Month(month),Day(day),Score(score_1),Score(score_2),Score(score_3));
        StreamIO::Writefile(NameFile(),std::vector<std::string>({StringCoverter::PropertiesToString(tmp)}),true);
    }

    //Remove score(core)
    void removeScore(const int & line_index)
    {
        auto strings_ptr = StreamIO::Readfile(NameFile());
        int size = strings_ptr->size();
        if(line_index < 1 || line_index > size)
            return; 
        strings_ptr->erase(strings_ptr->begin() + line_index - 1);
        StreamIO::Writefile(NameFile(),*strings_ptr,false);
    }

    void removeScore(const int & month,const int & day)
    {
        std::shared_ptr<std::vector<std::string>> string_list_ptr = StreamIO::Readfile(NameFile());
        Month m(month);
        {
            auto iter = string_list_ptr->begin();
            while(iter != string_list_ptr->end())
            {
                Properties property;
                if(StringCoverter::StringToProperties(*iter,property))
                {
                    if((std::string)m == (std::string)property.getMonth()
                    && day == property.getDay())
                    {
                        auto tmp_iter = iter;
                        iter = string_list_ptr->erase(tmp_iter);
                    }
                    else
                        ++iter;
                }
            }
        }
       StreamIO::Writefile(NameFile(),*string_list_ptr,false);
    }
}