#include <Wt/WText>
#include <Wt/WBreak>
#include <Wt/WContainerWidget>
#include <Wt/WLineEdit>
#include <Wt/WPushButton>
#include <Wt/WString>
#include <Wt/WTextArea>

#include<Wt/WDateTime>
#include<Wt/WDate>
#include<Wt/WDatePicker>
#include<Wt/WLabel>
#include<Wt/WCalendar>
using namespace Wt;

#include <Wt/Dbo/Dbo>
#include <Wt/Dbo/backend/Sqlite3>
#include <Wt/Dbo/SqlConnection>
namespace dbo = Wt::Dbo;

#include <string>
#include <sstream>
using namespace std;

class Stock:public Wt::WContainerWidget
{
public:
WLineEdit *BName;
WLineEdit * BId;
WLineEdit *Author;
WLineEdit *Data;
WLineEdit *Price;
WLineEdit *Rno;
WLineEdit *Nbooks;
WLineEdit *SCode;
Wt::WDatePicker *dp1;
WLabel *dp1Label;

dbo::Session session;
dbo::backend::Sqlite3 sqlite3;

Stock(WContainerWidget *parent);


WContainerWidget * stock;

void adddata();
void retrievedata();
};
