#include <Wt/WText>
#include <Wt/WBreak>
#include <Wt/WContainerWidget>
#include <Wt/WLineEdit>
#include <Wt/WPushButton>
#include <Wt/WString>
#include <Wt/WTextArea>
#include<Wt/WDate>
#include<Wt/WCalendar>
#include <Wt/WDatePicker>
#include<Wt/WComboBox>

using namespace Wt;

#include <Wt/Dbo/Dbo>
#include <Wt/Dbo/backend/Sqlite3>
#include <Wt/Dbo/SqlConnection>
namespace dbo = Wt::Dbo;

#include <string>
#include <sstream>
using namespace std;


namespace dbo=Wt::Dbo;
 
class MyApplication:public Wt::WContainerWidget
{
public:
WBreak *break1;
WLineEdit *Id;
WLineEdit * Name;
WComboBox *Course;
WComboBox *Branch;
WLineEdit *Dati;
WDatePicker *Dp1;
WLineEdit *Batch;
WLineEdit *Status;
WLineEdit *retrievetxt;
WContainerWidget *member;

MyApplication(WContainerWidget *parent);

void adddata();
void retrievedata();

dbo::Session session;
dbo::backend::Sqlite3 sqlite3;

};
