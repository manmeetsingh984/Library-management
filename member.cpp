#include "member.h"

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


MyApplication::MyApplication (WContainerWidget *parent)
:WContainerWidget(parent), sqlite3("data8")
{
session.setConnection (sqlite3);
session.mapClass<lib>("libraryn");
//session.createTables();

//useStyleSheet("library.css");

member=new WContainerWidget(this);

WText *head=new WText("Member Registration", member);
head->setStyleClass("text2");
member->addWidget(new WBreak);
member->addWidget(new WBreak);
member->addWidget(new WBreak);
member->addWidget(new WBreak);

WText * id=new WText("Id no.", member);
Id=new WLineEdit("",member);
//Id->setTextSize(10);
id->setStyleClass("ln");
//member->addWidget(new WBreak);

WText * name=new WText("Name", member);
Name=new WLineEdit("",member);
//Name->setTextSize(30);
name->setStyleClass("nm");
member->addWidget(new WBreak);
member->addWidget(new WBreak);


WText * course=new WText("Course", member);
Course=new WComboBox(member);
Course->addItem("");
Course->addItem("B.Tech");
Course->addItem("M.Tech");
Course->addItem("MCA");
course->setStyleClass("ln");


WText * address=new WText("Branch", member);
Branch=new WComboBox(member);
address->setStyleClass("cb");
Branch->addItem("");
Branch->addItem("Information Technology");
Branch->addItem("Computer Science");
Branch->addItem("Mechanical");
Branch->addItem("Civil");
Branch->addItem("Electrical");
Branch->addItem("Electronics");
//Branch->addItem("");
//Branch->addItem("");
member->addWidget(new WBreak);
member->addWidget(new WBreak);

WText * datr=new WText("Batch", member);

Batch=new WLineEdit("",member);
//Batch->setTextSize(10);
//member->addWidget(new WBreak);
datr->setStyleClass("ln");

WText * dati=new WText("Date of membership", member);
dati->setStyleClass("mn");
//WDatePicker (WLineEdit *Dati,member);
//WDatePicker *Dp1=new Wt::WDatePicker(WLineEdit * forEdit, member);
//Dp1->setDate(Wt::WDate::currentServerDate().addDays(0));
Dati=new WLineEdit("",member);

member->addWidget(new WBreak);
member->addWidget(new WBreak);

WText * status=new WText("Designation", member);
status->setStyleClass("ln");
Status=new WLineEdit("",member);
//Status->setTextSize(30);
member->addWidget(new WBreak);
member->addWidget(new WBreak); 
member->addWidget(new WBreak);

WText *Add=new WText("Click to add the member",member);
WPushButton *add =new WPushButton("Add", member);
Add->setStyleClass("ln");
add->clicked().connect(this, &MyApplication::adddata);
member->addWidget(new WBreak);

/*WText *text_r=new WText("Enter id to retrieve data",member);
retrievetxt=new WLineEdit(member);
WPushButton *push_r=new WPushButton("submit", member);
push_r->clicked().connect(this,&MyApplication::retrievedata);
*/}

void MyApplication::adddata()
{
{
dbo::Transaction transaction(session);
lib *library=new lib();
library->id=Id->text().toUTF8();
library->name=Name->text().toUTF8();
library->course=Course->currentText().toUTF8();
library->branch=Branch->currentText().toUTF8();
library->batch=Batch->text().toUTF8();
library->dissue=Dati->text().toUTF8();
library->status=Status->text().toUTF8();
dbo::ptr<lib> libraryPtr = session.add(library);

   transaction.commit();
}
}
/*
void MyApplication::retrievedata()
{
 
 Wt::WString a=retrievetxt->text(); 
 std::string b=a.toUTF8();

{
dbo::Transaction transaction(session);
typedef dbo::collection< dbo::ptr<lib> > balls;
balls library = session.find<lib>().where("identity=?").bind(b);

int i;
for (balls::const_iterator i = library.begin(); i != library.end(); ++i)

{
member->addWidget(new WText("id: "));
WText *nameout=new WText ((*i)->id,member);

member->addWidget(new WText("name: "));
WText *nameout1=new WText ((*i)->name,member);

member->addWidget(new WText("address: "));
WText *nameout2=new WText ((*i)->branch,member);

member->addWidget(new WText("Batch: "));
WText *nameout4=new WText ((*i)->batch,member);

member->addWidget(new WText("date of issue: "));
WText *nameout3=new WText ((*i)->dissue,member);


member->addWidget(new WText("id: "));
WText *nameout5=new WText ((*i)->status,member);

 transaction.commit();
}
}
}
*/
/*WApplication * createApplication (WEnvironment const & env)
{
 
return new MyApplication (env);

}

int main(int argc, char **argv)
{
  return WRun (argc, argv, & createApplication);
}*/
