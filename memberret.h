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

class Memberretrieve:public  Wt::WContainerWidget

{
public:
dbo::Session session;
dbo::backend::Sqlite3 sqlite3;

WLineEdit *retrievetxt;
Memberretrieve(WContainerWidget *parent);

WContainerWidget * member_ret;


void retrievedata();
};
