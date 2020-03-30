#include "menu.h"
#include <iostream>
#include "corefunctions.h"
#include <iomanip>
namespace Menu
{
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

    void ClearScreen()
    {
        for(int i = 0; i < 50; ++i)
        {
            std::cout<<std::endl;
        }
    }

    bool check_question(const char * pmt)
    {
        ClearScreen();
        std::string choice = "";
        while(true)
        {
            std::cout<<pmt<<" "<<"[y]es/[n]o:";
            std::getline(std::cin,choice);
            if(choice == "y")
                return true;
            else if(choice == "n")
                return false;
        }
    }

    void Reminder()
    {
        std::cout<<"Press Enter<Return> times to continue."<<std::endl;
        std::cin.get();
        std::cin.ignore(std::cin.rdbuf()->in_avail());
    }

    void ShowPropertyForm(const std::string & month, const int & day, const int & score1, const int & score2, const int & score3)
    {
        std::cout<<"On "<<month<<" "<<day<<
        ", you scored "<<score1<<", "<<score2
        <<", and "<<score3<<std::endl;
    }

    // 2. View all Scores.  If the user selects this option, call a function named viewScores. This function 
    // should print the scores in a nicely formatted manner. For example:
    // "On January 15, you scored 200, 300, and 126"
    void viewScores()
    {
        std::cout<<"Start list:"<<std::endl;
        CoreFunctions::viewScore(ShowPropertyForm);
        std::cout<<"End list:"<<std::endl;
    }

//  3. Add a Score. If the user selects this option, call a function named addScore. This function should 
// ask the user for a month, day, and 3 scores. The day should be between 1 and 31, and each of the 3 scores 
// should be between 0 and 300. Do not worry about validating the 'month' string. When the user submits data 
// to be entered, a separate function named scoreExistsForDate should be called. This function returns true 
// if there is already an entry in scores.txt for the given date. In that case, tell the user that a set of 
// scores already exists and do not enter the new score. If all input validation passes (i.e. the day is 
// between 1 and 31, the scores are all between 0 and 300, there is no entry for the given date) then append 
    void addScore()
    {
       
        bool is_continue = true;
        while (is_continue)
        {
            std::cout<<"Add scores and information in score.txt file"<<std::endl;
            int month = 0;
            while(true)
            {
                std::cout<<"Input month (number): ";
                month = OnlyInputNumber("Not valid: please enter again:");   
                if(month < 13 && month > 0)  // range of day 1 and 12
                    break;   
                std::cout<<"Value of month is not valid!"<<std::endl;
            }
            int day = 0;
            
            while (true)
            {
                std::cout<<"Input day: ";
                day = OnlyInputNumber("Not valid: please enter again:"); 
                if(day < 32 && day > 0) // range of day 1 and 31
                    break;   
                std::cout<<"Value of month is not valid!"<<std::endl;      
            }

            if(CoreFunctions::scoreExistsForDate(month,day))
            {
                std::cout<<"Set of score is existed in the given date! Can not append!"<<std::endl;
                return;
            }
            else
            {
                std::cout<<"The time is valid !"<<std::endl;
            }
            
            int score_1 = -1;
            
            while (true)
            {
                std::cout<<"Input Score 1: ";
                score_1 = OnlyInputNumber("Not valid: please enter again:");  
                if(score_1 < 301 && score_1 >= 0) //range of score 0 -> 300
                    break;
                std::cout<<"Value of month is not valid!"<<std::endl;
            }
            int score_2 = -1;
            while (true)
            {
                std::cout<<"Input Score 2: ";
                score_2 = OnlyInputNumber("Not valid: please enter again:");  
                if(score_2 < 301 && score_2 >= 0) //range of score 0 -> 300
                    break;
                std::cout<<"Value of month is not valid!"<<std::endl;
            }
            int score_3 = -1;
            while (true)
            {
                std::cout<<"Input Score 3: ";
                score_3 = OnlyInputNumber("Not valid: please enter again:");  
                if(score_3 < 301 && score_3 >= 0) //range of score 0 -> 300
                    break;
                std::cout<<"Value of month is not valid!"<<std::endl;
            }
            bool chk = check_question("Do you want to save infomation!");
            if(chk)
            {
                CoreFunctions::addScore(month,day,score_1,score_2,score_3);     
            }  
            is_continue = check_question("Would you like to continue to add score!");
        }        
    }

    void RemoveByLineIndex()
    {
        int choice = 0;
        int is_continue = true;
        while (is_continue)
        {
            std::cout<<"Erase a line in txt file."<<std::endl;
            std::cout<<"Enter the line index: ";
            choice = OnlyInputNumber("Not Valid! Please enter value again: ");
            bool is_accept = check_question("Are you sure to remove this item?");
            if(!is_accept)
            {
                std::cout<<"Process is canceled!"<<std::endl;
                return;
            }
            CoreFunctions::removeScore(choice);
            std::cout<<"Finish!"<<std::endl;
            Reminder();
            is_continue = check_question("Would you like to continue ?");
        }
    }

    void RemoveByMonthAndDay()
    {     
         int is_continue = true;
        while (is_continue)
        {
            int month = 0;
            while(true)
            {
                std::cout<<"Input month (number): ";
                month = OnlyInputNumber("Not valid: please enter again:");   
                if(month < 13 && month > 0) 
                    break;   
                std::cout<<"Value of month is not valid!"<<std::endl;
            }
            int day = 0;    
            while (true)
            {
                std::cout<<"Input day: ";
                day = OnlyInputNumber("Not valid: please enter again:"); 
                if(day < 32 && day > 0) 
                    break;   
                std::cout<<"Value of month is not valid!"<<std::endl;      
            }
            bool is_accept = check_question("Are you sure to remove this item?");
            if(!is_accept)
            {
            std::cout<<"Process is canceled!"<<std::endl;
            return;
            }
            CoreFunctions::removeScore(month,day);
            std::cout<<"Finish!"<<std::endl;
            Reminder();
            is_continue = check_question("Would you like to continue ?");
        }
        
    }

    void removeScore()
    {
        int choice = 0;
        while(true)
        {
            ClearScreen();
            std::cout<<"   Remove Score !"<<std::endl;
            std::cout<<"1. Remove by line index in text file. "<<std::endl;
            std::cout<<"2. Remove by month and day. "<<std::endl;
            std::cout<<"3. Back. "<<std::endl;
            choice = OnlyInputNumber("value not valid. please enter again: ");
            switch (choice)
            {
            case 1:
                ClearScreen();
                RemoveByLineIndex();
                break;
            case 2:
                ClearScreen();
                RemoveByMonthAndDay();
                break;
            case 3:
                return;
            default:
                break;
            }
        }
    }

    //Average Scores.(terminal)
    void averageScore()
    {
        std::shared_ptr<std::vector<std::string>> months = std::make_shared<std::vector<std::string>>();
        std::shared_ptr<std::vector<int>> days = std::make_shared<std::vector<int>>();
        std::shared_ptr<std::vector<int>> avg_score_of_each_day = std::make_shared<std::vector<int>>();
        int averageScores = 0;
        CoreFunctions::averageScores(months,days,avg_score_of_each_day, averageScores);
        if((months->size() != days->size()) || (months->size() != avg_score_of_each_day->size()))
        {
            std::cout<<"Error in averageScores"<<std::endl;
            return;
        }
        std::cout<<std::setw(10)<<"Average score on all days: "<<std::setw(10)<<averageScores<<std::endl;
        std::cout<<std::setw(10)<<"Month"<<std::setw(15)<<"Day"<<std::setw(25)<<"Avg-Score"<<std::endl;
        for(int i = 0; i < months->size(); ++i)
        {
             std::cout<<std::setw(10)<<(std::string)(*months)[i]
                      <<std::setw(15)<<(*days)[i]
                      <<std::setw(20)<<(*avg_score_of_each_day)[i]<<std::endl;
        }

    }



    void MainMenu()
    {

        int choice = 0;
        while(true)
        {
            ClearScreen();
            std::cout<<"1. Quit Program. "<<std::endl;
            std::cout<<"2. View all Scores. "<<std::endl;
            std::cout<<"3. Add a Score. "<<std::endl;
            std::cout<<"4. Averge Scores. "<<std::endl;
            std::cout<<"5. Remove Scores. "<<std::endl;
            std::cout<<"Enter selection index <1-5>: ";
            choice = OnlyInputNumber("value not valid. please enter again: ");
            switch (choice)
            {
            //1. Quit the program.
            case 1:
                return;
            //2. viewScores
            case 2:
                ClearScreen();
                viewScores();
                Reminder();                
                break;
            //3. addScore
            case 3:
                ClearScreen();
                addScore();
                break;
            //4. AverageScore.
            case 4:
                ClearScreen();
                averageScore();
                Reminder();     
                break;
            //5. RemoveScore.
            case 5:
                ClearScreen();
                removeScore();   
                break;
            default:
                break;
            }
        }
    }
}