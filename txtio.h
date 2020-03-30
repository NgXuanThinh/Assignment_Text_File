#ifndef TXTIO_H_
#define TXTIO_H_
#include<vector>
#include<string>
#include<memory>
    class StreamIO
    {
        public:
        static std::shared_ptr<std::vector<std::string>> Readfile(std::string namefile);
        static void Writefile(std::string namefile,const std::vector<std::string> & text, bool is_append);
    };
#endif //TXTIO_H_