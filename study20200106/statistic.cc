#include <func.h>
#include <string.h>
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
using namespace std;

#define MAXKEY 10000
int _hash(const char *key)   //哈希函数 
{
    int h = 0, g;
    while (*key) 
    {
        h = (h << 4) + *key++;
        g = h & 0xf0000000;
        if (g)
            h ^= g >> 24;
        h &= ~g;
    }
    return h % MAXKEY;
}

typedef struct sta{
    int count;
    string word;
}sta;  // struct sta  存放单词信息

class Dictionary{
public:
    void read(const string &readname);
    void  store(const string &dictname);
private:
    char *_readname;
    char *_dictname;
};

sta *data=new sta[MAXKEY]();
void Dictionary::read(const string & readname)
{
    ifstream ifs(readname);
    if(!ifs) {
        cerr << "ifstream open " << readname << " error\n";
        return;
    }
    int index,i;
    string alp;
    string line;
    while(ifs>>alp)
    {
        if(alp[0]>='0'&&alp[0]<='9')
            continue;
        index=_hash(alp.c_str());
        if(data[index].count==0)
        {
            data[index].word=alp;
            ++data[index].count;
        }else{
            i=0;
            while(data[(index+i)%MAXKEY].word.compare(alp)==true)
            {
                ++i;
            }
            if(!data[(index+i)%MAXKEY].count)
                data[(index+i)%MAXKEY].word=alp;
            ++data[(index+i)%MAXKEY].count;
        }
    }
}

void Dictionary::store(const string & dictname )
{
    string name =dictname;
    ofstream ofs(name);
    if(!ofs.good())
    {
        cerr<<"ofstream create file error\n"<<endl;
        return ;
    }
    for(int i=0;i<MAXKEY;++i)
    {
        if(data[i].count>0)
            ofs<<data[i].word<<"    "<<data[i].count<<"\n";
    }
    cout<<"统计单词结束"<<endl;
}
int main()
{
    Dictionary S;
    double start=clock();

    S.read("The_Holy_Bible.txt");
    S.store("DICT");
    double end=clock();
    cout<<"统计时间共花费："<<(end-start)/CLOCKS_PER_SEC<<" S"<<endl;
}
