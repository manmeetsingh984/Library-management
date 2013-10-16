#include "stock.h"

using namespace Wt;

class lib1
{
public:
std::string bname;
std::string bid;
std::string author;
std::string darrival;
std::string price;
std::string rackno;
std::string nbooks;
std::string scode;

template <class Check>
void persist(Check& a)
{
dbo::field(a, bname, "Bookname");
dbo::field(a, bid, "BookId");
dbo::field(a, author, "Author");
dbo::field(a, darrival, "Date of arrival");  
dbo::field(a, price, "Price");
dbo::field(a, rackno, "Rack No.");
dbo::field(a, nbooks, "No of Books");
dbo::field(a, scode, "Subject Code");
}
};
Stock::Stock(WContainerWidget *parent):
                     WContainerWidget(parent),  sqlite3("data5")
{
session.setConnection (sqlite3);
session.mapClass<lib1>("library1");
//session.createTables();

stock=new WContainerWidget(this);

WText * head=new WText("Book Registration", stock);
head->setStyleClass("text2");
stock->addWidget(new WBreak);
stock->addWidget(new WBreak);
stock->addWidget(new WBreak);


WText * bid=new WText("Book Id", stock);
BId=new WLineEdit("",stock);
bid->setStyleClass("ln");


WText * bname=new WText("Book Name &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;", stock);

BName=new WLineEdit("",stock);

bname->setStyleClass("kl");
stock->addWidget(new WBreak);
stock->addWidget(new WBreak);

WText * author=new WText("Author &nbsp;", stock);
Author=new WLineEdit("",stock);
author->setStyleClass("ln");

/*Wt::WLabel *dp1Label = new Wt::WLabel("From", stock);
Wt::WDatePicker *dp1 = new Wt::WDatePicker(stock);
dp1->setDate(Wt::WDate::currentServerDate().addDays(1));
dp1Label->setBuddy(dp1->lineEdit());
*/
WText * data=new WText("Date of Arrival &nbsp;", stock);
Data=new WLineEdit("",stock);
stock->addWidget(new WBreak);
stock->addWidget(new WBreak);
data->setStyleClass("kl");

WText * price=new WText("Price &nbsp;&nbsp;&nbsp;&nbsp;", stock);
Price=new WLineEdit("",stock);
price->setStyleClass("ln");

WText * scode=new WText("Subject Code &nbsp;&nbsp;&nbsp;", stock);
SCode=new WLineEdit("",stock);
stock->addWidget(new WBreak);
stock->addWidget(new WBreak);
scode->setStyleClass("kl");


WText * rno=new WText("Rack No", stock);
Rno=new WLineEdit("",stock);
rno->setStyleClass("ln");

WText * nbooks=new WText("No of books &nbsp; &nbsp;&nbsp;", stock);
Nbooks=new WLineEdit("",stock);
stock->addWidget(new WBreak);
stock->addWidget(new WBreak);
nbooks->setStyleClass("kl");


WText *Add=new WText("Click to register the book ",stock);
WPushButton *add =new WPushButton("Add", stock);
add->clicked().connect(this, &Stock::adddata);
stock->addWidget(new WBreak);
Add->setStyleClass("ln");
//add->setStyleClass("pad");

/*
Wt::WText *out1 = new Wt::WText("<p></p>", stock);

BName->changed().connect(std::bind([=] () {
    out1->setText("<p>Book Name Added is :  " +
                 BName->text() + ".</p>");
}));

Wt::WText *out2 = new Wt::WText("<p></p>", stock);

BId->changed().connect(std::bind([=] () {
    out2->setText("<p>Book Id Added is :    " +
                 BId->text() + ".</p>");
}));

Wt::WText *out = new Wt::WText("<p></p>", stock);

Data->changed().connect(std::bind([=] () {
    out->setText("<p>Entry Added at  :        " +
                 Wt::WDateTime::currentDateTime().toString() + ".</p>");
}));
*/
/*
WText *text_r=new WText("Enter name to retrieve data",root());
retrievetxt=new WLineEdit(root());
WPushButton *push_r=new WPushButton("submit", root());
push_r->clicked().connect(this,&MyApplication::retrievedata);
*/
}

void Stock::adddata()
{
{
dbo::Transaction transaction(session);
lib1 *library1=new lib1();
library1->bname=BName->text().toUTF8();
library1->bid=BId->text().toUTF8();
library1->author=Author->text().toUTF8();
library1->darrival=Data->text().toUTF8();
library1->price=Price->text().toUTF8();
library1->rackno=Rno->text().toUTF8();
library1->nbooks=Nbooks->text().toUTF8();
library1->scode=SCode->text().toUTF8();
dbo::ptr<lib1> library1Ptr = session.add(library1);

   transaction.commit();
}
}

/*void MyApplication::retrievedata()
{
 
 Wt::WString a=retrievetxt->text(); 
 std::string b=a.toUTF8();

{
dbo::Transaction transaction(session);
typedef dbo::collection< dbo::ptr<lib> > balls;
balls library = session.find<lib>().where("id=?").bind(b);

int i;
for (balls::const_iterator i = library.begin(); i != library.end(); ++i)

{
stock->addWidget(new WText("name: "));
WText *nameout=new WText ((*i)->name,stock);
}
}
}
*/

