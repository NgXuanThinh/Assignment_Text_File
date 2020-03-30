#ifndef _STRING_CONVERTER_
#define _STRING_CONVERTER_
#include <string>
class Properties;
namespace StringCoverter
{
    std::string PropertiesToString(const Properties & properties); 
    bool StringToProperties(std::string string,Properties & properties);
}

#endif //STRING_CONVERTER_