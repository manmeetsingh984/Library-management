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

using namespace Wt;

class Return:public  Wt::WContainerWidget
{
public:


dbo::Session session;
dbo::backend::Sqlite3 sqlite3;

WLineEdit *Mid;
WLineEdit *Bc;
WContainerWidget *returncont;

Return(WContainerWidget *parent);

void returndata();
void deletedata();
};

