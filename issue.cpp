#include "issue.h"

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
dbo::field(a, bcode, "bookIdentity"); 
dbo::field(a, dateissue, "Date of issue");
dbo::field(a, datereturn, "Date of return");
}
};

class lib
{
public:
std::string id;
std::string dissue;
std::string dreturn;
std::string name;
std::string address;
std::string status;

template <class Check>
void persist(Check& a)
{
dbo::field(a, id, "identity");
dbo::field(a, name, "name");
dbo::field(a, address, "address");
dbo::field(a, dissue, "dissue");  
dbo::field(a, dreturn, "dreturn");
dbo::field(a, status, "status");
}
};




Issue::Issue(WContainerWidget* parent):
                    WContainerWidget(parent), sqlite3("data8")
{

session.setConnection (sqlite3);
session.mapClass<lib2>("issueman");
session.mapClass<lib>("libraryn");

//session.createTables();

//useStyleSheet("library.css");
issue=new WContainerWidget(this); 

WText *head=new WText("Issue of Books", issue);
issue->addWidget(new WBreak);
issue->addWidget(new WBreak);
issue->addWidget(new WBreak);
issue->addWidget(new WBreak);
head->setStyleClass("text2");
WText *mid=new WText("Member Id No", issue);
Mid=new WLineEdit("", issue);
mid->setStyleClass("kl");


WText *bc=new WText("Book Code &nbsp; &nbsp;", issue);
Bc=new WLineEdit("", issue);
issue->addWidget(new WBreak);
issue->addWidget(new WBreak);
bc->setStyleClass("pl");

//WText *doi=new WText("Date of Issue", issue);
//Wt::WContainerWidget *cc = new Wt::WContainerWidget(issue);
label = new Wt::WLabel("Date of Issue &nbsp;",issue);
Doi = new Wt::WLineEdit(issue);
label->setStyleClass("kl");

/*birthDP = new Wt::WDatePicker( issue);
birthDP->setDate(Wt::WDate::currentServerDate().addDays(0));
label->setBuddy(birthDP->lineEdit());
 */
label1 = new Wt::WLabel("Date of Return",issue);

Dor = new Wt::WLineEdit(issue);
/*birthDp = new Wt::WDatePicker( issue);
birthDp->setDate(Wt::WDate::currentServerDate().addDays(15));
label1->setBuddy(birthDp->lineEdit());
*/
label1->setStyleClass("pl");


issue->addWidget(new WBreak);
issue->addWidget(new WBreak);
issue->addWidget(new WBreak);

WText* submit=new WText("Click to issue the book",issue);
WPushButton *button=new WPushButton("Issue", issue);

button->clicked().connect(this, &Issue::check);
issue->addWidget(new WBreak);
issue->addWidget(new WBreak);
issue->addWidget(new WBreak);
submit->setStyleClass("kl");

WText *text_r=new WText("Enter book id to retrieve data",issue);
retrievetxt=new WLineEdit(issue);
WPushButton *push_r=new WPushButton("submit", issue);
push_r->clicked().connect(this,&Issue::retrievedata);
text_r->setStyleClass("pl");
}


void Issue::check()
{
{
WString mid=Mid->text();
string mid_str=mid.toUTF8();

dbo::Transaction transaction(session);


typedef dbo::collection<dbo::ptr<lib> > tran;
tran librarym = session.find<lib>().where(" identity= ?").bind(mid_str);

transaction.commit();

if(librarym.size()==0)
{
WText *dis=new WText("Member not Registered",issue);
}
else
{
// MyApplication obj; 
 //obj.adddata();
Issue::adddata();
}

}
}
void Issue::adddata()
{
{
dbo::Transaction transaction(session);


lib2 *issuei=new lib2();
issuei->midno=Mid->text().toUTF8();
issuei->bcode=Bc->text().toUTF8();
issuei->dateissue=Doi->text().toUTF8();
issuei->datereturn=Dor->text().toUTF8();

dbo::ptr<lib2> issueiPtr = session.add(issuei);

   transaction.commit();
}
}


void Issue::retrievedata()
{
 
 Wt::WString a=retrievetxt->text(); 
 std::string b=a.toUTF8();

{
dbo::Transaction transaction(session);
typedef dbo::collection< dbo::ptr<lib2> > bals;
bals library = session.find<lib2>().where("bookIdentity=?").bind(b);

int i;
for (bals::const_iterator i = library.begin(); i != library.end(); ++i)

{
issue->addWidget(new WBreak);
issue->addWidget(new WText("id: "));
WText *nameout=new WText ((*i)->bcode,issue);
issue->addWidget(new WBreak);

issue->addWidget(new WText("Member to which book is issued: "));
WText *nameout1=new WText ((*i)->midno,issue);
issue->addWidget(new WBreak);

issue->addWidget(new WText("Date of issue: "));
WText *nameout2=new WText ((*i)->dateissue,issue);
issue->addWidget(new WBreak);

issue->addWidget(new WText("Date of return: "));
WText *nameout3=new WText ((*i)->datereturn,issue);

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
