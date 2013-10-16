#include "tms.h"

#include <Wt/WCalendar>
#include <Wt/WDate>
#include <Wt/WDatePicker>
#include<Wt/WLabel>
#include<Wt/WDateValidator>
#include <Wt/WInPlaceEdit>

#include <Wt/WText>
#include <Wt/WBreak>
#include <Wt/WContainerWidget>
#include <Wt/WLineEdit>
#include <Wt/WPushButton>
#include <Wt/WString>
#include <Wt/WTextArea>
using namespace Wt;

#include <Wt/WText>
#include <Wt/WBreak>
#include <Wt/WContainerWidget>
#include <Wt/WLineEdit>
#include <Wt/WPushButton>
#include <Wt/WString>
#include <Wt/WTextArea>
using namespace Wt;

#include <Wt/Dbo/Dbo>
#include <Wt/Dbo/backend/Sqlite3>
#include <Wt/Dbo/SqlConnection>
namespace dbo = Wt::Dbo;

#include <string>
#include <sstream>
using namespace std;

class Issue: public Wt::WContainerWidget
{
public:

dbo::Session session;
dbo::backend::Sqlite3 sqlite3;

Issue(WContainerWidget * parent);

Wt::WLabel *label1;
Wt::WDatePicker *birthDp;

Wt::WLabel *label;
Wt::WDatePicker *birthDP;
Wt::WDateValidator *dv;
WLineEdit *Mid;
WLineEdit * Bc;
WLineEdit * Doi;
WLineEdit * Dor;
WLineEdit * dateEdit;
WLineEdit * retrievetxt;
WContainerWidget *issue;
void adddata();
void retrievedata();
void check();


};

