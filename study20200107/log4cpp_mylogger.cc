#include <iostream>

#include <log4cpp/Category.hh>
#include <log4cpp/BasicLayout.hh>
#include <log4cpp/OstreamAppender.hh>
#include <log4cpp/Priority.hh>
#include <log4cpp/PatternLayout.hh>
#include <log4cpp/FileAppender.hh>

using namespace std;
using namespace log4cpp;

class Mylogger{
public:
    static Mylogger *getInstance(void)
    {
        if(_plogger==nullptr)
            _plogger=new Mylogger();
        return _plogger;
    }
    void destory()

    {
        if(_plogger)
        { 
            delete _plogger;
            Category::shutdown();
        }
        cout<<"destory()"<<endl;
    }
public:
    void warn(const char * msg)
    {
    _root.setPriority(Priority::WARN);
    string msg_pro=msg;
    msg_pro+="  FILE:"+(string) __FILE__+"  FUNCTION:"+(string)__FUNCTION__+"  LINE:";
    _root.warn(msg_pro+to_string(__LINE__));
    
    }
    void error(const char * msg)
    {
    _root.setPriority(Priority::ERROR);
    string msg_pro=msg;
    msg_pro+="  FILE:"+(string) __FILE__+"  FUNCTION:"+(string)__FUNCTION__+"  LINE:";
    _root.error(msg_pro+to_string(__LINE__));
    }
    void debug(const char * msg)
    {
    _root.setPriority(Priority::ERROR);
    string msg_pro=msg;
    msg_pro+="  FILE:"+(string) __FILE__+"  FUNCTION:"+(string)__FUNCTION__+"  LINE:";
    _root.error(msg_pro+to_string(__LINE__));
    }
    void info(const char *msg)
    {
    _root.setPriority(Priority::INFO);
    string msg_pro=msg;
    msg_pro+="  FILE:"+(string) __FILE__+"  FUNCTION:"+(string)__FUNCTION__+"  LINE:";
    _root.info(msg_pro+to_string(__LINE__));
    }
private:
    Mylogger()//单例模式
    :_root ( Category::getRoot().getInstance("mydog"))
    {
    PatternLayout *ptLayout1 =new PatternLayout();
    ptLayout1->setConversionPattern("%d %c [%p] %m%n");
    PatternLayout *ptLayout2 =new PatternLayout();
    ptLayout2->setConversionPattern("%d %c [%p] %m%n");

    FileAppender * fileAppender=new FileAppender("fileAppender","AA.log");
    fileAppender->setLayout(ptLayout1);

    OstreamAppender *ostreamAppender=new OstreamAppender("ostreamAppender",&cout);
    ostreamAppender->setLayout(ptLayout2);

    _root.addAppender(fileAppender);
    _root.addAppender(ostreamAppender);
    }
    ~Mylogger()
    {

    }
private:
    static Mylogger * _plogger;
    Category &_root;

};

Mylogger * Mylogger::_plogger=nullptr;
int main()
{

    Mylogger *log=Mylogger::getInstance();
    log->warn("hi");
    log->error("error");
    log->info("hello");
    log->debug("debug");
    log->destory();

    return 0;
}

