#include <string.h>
#include <iostream>
#include <string>
#include <map>
#include <fstream>
using namespace std;
using std::cout;
using std::endl;
using std::ifstream;
using std::ofstream;
using std::string;
using std::map;


map<string,int> _dict;
class Dict{
public:
    Dict(const char *readfile,const char * dictfile)
        :_readFile(new char[strlen(readfile)+1]())
         ,_dictFile(new char[strlen(dictfile)+1]())
    {
        strcpy(_readFile,readfile);
        strcpy(_dictFile,dictfile);
        cout<<"Dict(const char * ,const char *)"<<endl;
    }
    void dict_read()
    {
        ifstream ifs(_readFile);
        string word;
        while(ifs>>word)
        {
            if(isalpha(word[0]))
            {
                auto search=_dict.find(word);
                if(search!=_dict.end())
                {
                   ++ search->second;
                }else{
                    
                    ++_dict[word];
                }
            }
        }
        ifs.close();
    }
    void dict_wrtie()
    {
        ofstream ofs(_dictFile);
        for(auto &word:_dict)
        {
            ofs<<word.first<<"  "<<word.second<<endl;
        }
        ofs.close();
    }
private:
    char * _readFile;
    char * _dictFile;
};

int main()
{
    Dict S("The_Holy_Bible.txt","DICT");
    double start=clock();
    S.dict_read();
    S.dict_wrtie();
    double end=clock();
    cout<<"统计时间共花费："<<(end-start)/CLOCKS_PER_SEC<<"S"<<endl;
    std::cout << "Hello world" << std::endl;
    return 0;
}

