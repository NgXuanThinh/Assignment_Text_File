#include "string_converter.h"
#include "properties.h"
#include "sstream"
#include <vector>
const char * Blank()
{
    return " ";
} 

int convert_string_to_int(std::string str)
{
    std::stringstream geek(str);
    int number = 0;
    geek >> number;
    return number;
}

std::string convert_int_to_string(int number)
{
    std::stringstream ss;
    ss << number;
    return ss.str();
}



std::vector<std::string> ParseText(std::string str, std::string delimiter)
{
    std::vector<std::string> texts;
    size_t pos = 0;
    std::string token;
    while ((pos = str.find(delimiter)) != std::string::npos)
    {
        token = str.substr(0,pos);
        if(token.length() > 0)
            texts.push_back(token);
        str.erase(0,pos + delimiter.length());
    }
    if(token.length() > 0)
        texts.push_back(str);
    return texts;
}

std::string StringCoverter::PropertiesToString(const Properties & properties)
{
    std::string rtrn;
    rtrn.append(properties.getMonth());
    rtrn.append(Blank());
    rtrn.append(convert_int_to_string(properties.getDay()));
    rtrn.append(Blank());
    rtrn.append(convert_int_to_string(properties.getScore1()));
    rtrn.append(Blank());
    rtrn.append(convert_int_to_string(properties.getScore2()));
    rtrn.append(Blank());
    rtrn.append(convert_int_to_string(properties.getScore3()));
    return rtrn;
} 

bool StringCoverter::StringToProperties(std::string string,Properties & properties)
{
    std::vector<std::string> texts = ParseText(string,Blank());
    if(texts.size() < Properties::NumberofVariable())
        return false;
    try
    {
        properties.setMonth(Month(texts[0]));
        properties.setDay(Day(convert_string_to_int(texts[1])));
        properties.setScore1(Score(convert_string_to_int(texts[2])));
        properties.setScore2(Score(convert_string_to_int(texts[3])));
        properties.setScore3(Score(convert_string_to_int(texts[4])));
    }
    catch(const std::exception& e)
    {
        return false;
    }
    return true;
}
