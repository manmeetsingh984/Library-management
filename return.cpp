#include"return.h"
using namespace Wt;

class return1
{
public:
std::string  name;
std::string id;
std::string dateissue;
std::string datereturn;
std::string bcode;

template <class Check>
void persist(Check &a)
{
dbo::field(a, id,"issue id no");
dbo::field(a, name,"Name");
dbo::field(a, bcode, "book code"); 
dbo::field(a, dateissue, "Date of issue");
dbo::field(a, datereturn, "Date of return");
}
};

class lib2
{
public:
std::string midno;
 std::string bcode;
std::string dateissue;
 std::string datereturn;

template <class Check>
void persist(Check &a)
{
dbo::field(a, midno,"identity");
dbo::field(a, bcode, "bookIdentity "); 
dbo::field(a, dateissue, "Date of issue");
dbo::field(a, datereturn, "Date of return");
}
};

Return::Return(WContainerWidget *parent):
                 WContainerWidget(parent), sqlite3("data8")

{
session.setConnection (sqlite3);
session.mapClass<return1>("returntab");
session.mapClass<lib2>("issueman");
//session.createTables();

returncont=new WContainerWidget(this);

WText *head=new WText("Return of Books",returncont);
returncont->addWidget(new WBreak);
returncont->addWidget(new WBreak);
returncont->addWidget(new WBreak);
returncont->addWidget(new WBreak);
head->setStyleClass("text2");

WText *mid=new WText("Member Id No", returncont);
mid->setStyleClass("dor");
Mid=new WLineEdit("", returncont);

WText *bc=new WText("Book Code", returncont);
Bc=new WLineEdit("", returncont);
bc->setStyleClass("pl");
returncont->addWidget(new WBreak);
returncont->addWidget(new WBreak);

WText *submit=new WText("Click to check",returncont);
WPushButton *button=new WPushButton("Submit",returncont);
submit->setStyleClass("dor");
button->clicked().connect(this, &Return::returndata );

}

void Return::returndata()
{
 
// Wt::WString a=Mid->text(); 
 //std::string b=a.toUTF8();
  Wt::WString c=Bc->text(); 
 std::string d=c.toUTF8();
{
dbo::Transaction transaction(session);
typedef dbo::collection< dbo::ptr<lib2> > balls;
balls library = session.find<lib2>().where(" bookIdentity=?").bind(d);
{
int i;
for (balls::const_iterator i = library.begin(); i != library.end(); ++i)

{
returncont->addWidget(new WBreak);
returncont->addWidget(new WBreak);
returncont->addWidget(new WBreak);
returncont->addWidget(new WText("&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Date of Issue: "));
WText *nameout=new WText ((*i)->dateissue,returncont);
returncont->addWidget(new WBreak);
returncont->addWidget(new WBreak);

returncont->addWidget(new WText("&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Date of Return: "));
WText *nameout1=new WText ((*i)->datereturn,returncont);
returncont->addWidget(new WBreak);
returncont->addWidget(new WBreak);

 transaction.commit();
}
}
}
WText *button=new WText(" Click to return book",returncont);
WPushButton *button5=new WPushButton("Return", returncont);
button5->clicked().connect(this,&Return::deletedata);
button->setStyleClass("dor");
}
void Return::deletedata()
{

  Wt::WString c=Bc->text(); 
  std::string d=c.toUTF8();
{
dbo::Transaction transaction(session);
typedef dbo::ptr<lib2>  bals;
bals librar = session.find<lib2>().where(" bookIdentity=?").bind(d);

librar.remove();
transaction.commit();
}

}

/*WApplication * createApplication (WEnvironment const & env)
{
 
return new MyApplication (env);

}

int main(int argc, char **argv)
{
  return WRun (argc, argv, & createApplication);
}*/
