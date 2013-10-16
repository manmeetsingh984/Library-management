#include "memberret.h"


using namespace Wt;

class lib
{
public:
std::string id;
std::string dissue;
std::string course;
std::string branch;
std::string name;
std::string batch;
std::string status;

template <class Check>
void persist(Check& a)
{
dbo::field(a, id, "identity");
dbo::field(a, name, "name");
dbo::field(a, course, "Course");
dbo::field(a, branch, "Branch");
dbo::field(a, batch, "Batch");
dbo::field(a, dissue, "dissue");  
dbo::field(a, status, "Designation");
}
};


Memberretrieve::Memberretrieve(WContainerWidget *parent):
                     WContainerWidget(parent), sqlite3("data8")
{
session.setConnection (sqlite3);
session.mapClass<lib>("libraryn");

member_ret=new WContainerWidget(this);

WText *text_r=new WText("Enter id to retrieve data",member_ret);
retrievetxt=new WLineEdit(member_ret);
WPushButton *push_r=new WPushButton("submit", member_ret);
push_r->clicked().connect(this,&Memberretrieve::retrievedata);
}

void Memberretrieve::retrievedata()
{
 
 Wt::WString a=retrievetxt->text(); 
 std::string b=a.toUTF8();

{
dbo::Transaction transaction(session);
typedef dbo::collection< dbo::ptr<lib> > balls;
balls library = session.find<lib>().where("identity=?").bind(b);

if(library.size()==0)
{
member_ret->addWidget(new WBreak);
WText *err=new WText("Not a Valid Id   Please Register",member_ret);
}
else
{
int i;
for (balls::const_iterator i = library.begin(); i != library.end(); ++i)

{
member_ret->addWidget(new WBreak);
member_ret->addWidget(new WBreak);
member_ret->addWidget(new WBreak);
member_ret->addWidget(new WText("Id: "));
WText *nameout=new WText ((*i)->id,member_ret);
member_ret->addWidget(new WBreak);
member_ret->addWidget(new WBreak);

member_ret->addWidget(new WText("Name: "));
WText *nameout1=new WText ((*i)->name,member_ret);
member_ret->addWidget(new WBreak);
member_ret->addWidget(new WBreak);

member_ret->addWidget(new WText("Course: "));
WText *nameout6=new WText ((*i)->course,member_ret);
member_ret->addWidget(new WBreak);
member_ret->addWidget(new WBreak);

member_ret->addWidget(new WText("Branch: "));
WText *nameout2=new WText ((*i)->branch,member_ret);
member_ret->addWidget(new WBreak);
member_ret->addWidget(new WBreak);

member_ret->addWidget(new WText("Batch: "));
WText *nameout4=new WText ((*i)->batch,member_ret);
member_ret->addWidget(new WBreak);
member_ret->addWidget(new WBreak);

member_ret->addWidget(new WText("Date of issue: "));
WText *nameout3=new WText ((*i)->dissue,member_ret);
member_ret->addWidget(new WBreak);
member_ret->addWidget(new WBreak);

member_ret->addWidget(new WText("Designation: "));
WText *nameout5=new WText ((*i)->status,member_ret);
member_ret->addWidget(new WBreak);
member_ret->addWidget(new WBreak);

 transaction.commit();
}
}
}
}
/*
WApplication * createApplication (WEnvironment const & env)
{
 
return new MyApplication (env);

}

int main(int argc, char **argv)
{
  return WRun (argc, argv, & createApplication);
}
*/
