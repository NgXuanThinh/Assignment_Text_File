#include "txtio.h"
#include <fstream>
#include <vector>
bool exists_test0 (const std::string& name) {
    std::ifstream f(name.c_str());
    return f.good();
}

std::shared_ptr<std::vector<std::string>> StreamIO::Readfile(std::string namefile)
{
    
    std::shared_ptr<std::vector<std::string>> contexts = std::make_shared<std::vector<std::string>>();
    std::ifstream fs(namefile);
    if(!fs.good())
        return contexts;
    {
        std::string chars;
        while (std::getline(fs,chars))
        {
            contexts->push_back(chars);
        }
    }   
    return std::move(contexts);
}

void StreamIO::Writefile(std::string namefile,const std::vector<std::string> & text, bool is_append)
{
    std::ofstream ofs;
    if(is_append)
         ofs.open(namefile,std::ios::out | std::ios::ate | std::ios::app);
    else
        ofs.open(namefile);
    for(std::vector<std::string>::const_iterator iter = text.begin(); iter != text.end(); ++iter)
    {
        ofs << *iter << std::endl;
    }
    ofs.close();
}