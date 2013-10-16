#include "stockret.h"

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

Stockretrieve::Stockretrieve(WContainerWidget *parent):
                     WContainerWidget(parent), sqlite3("data5")
{
session.setConnection (sqlite3);
session.mapClass<lib1>("library1");

stock_ret=new WContainerWidget(this);

WText *text_r=new WText("Enter Book id to retrieve data",stock_ret);
retrievetxt=new WLineEdit(stock_ret);
WPushButton *push_r=new WPushButton("submit", stock_ret);
push_r->clicked().connect(this,&Stockretrieve::retrievedata);

}

void Stockretrieve::retrievedata()
{
 
 Wt::WString a=retrievetxt->text(); 
 std::string b=a.toUTF8();

{
dbo::Transaction transaction(session);
typedef dbo::collection< dbo::ptr<lib1> > balls;
balls library = session.find<lib1>().where("BookId=?").bind(b);

if(library.size()==0)
{
stock_ret->addWidget(new WBreak);
WText *err=new WText("Not a Valid Id   Please Register",stock_ret);
}
else
{
int i;
for (balls::const_iterator i = library.begin(); i != library.end(); ++i)

{
stock_ret->addWidget(new WBreak);
stock_ret->addWidget(new WBreak);
stock_ret->addWidget(new WBreak);
stock_ret->addWidget(new WText("Book Name: "));
WText *nameout=new WText ((*i)->bname,stock_ret);
stock_ret->addWidget(new WBreak);
stock_ret->addWidget(new WBreak);

stock_ret->addWidget(new WText("Book Id: "));
WText *nameout1=new WText ((*i)->bid,stock_ret);
stock_ret->addWidget(new WBreak);
stock_ret->addWidget(new WBreak);

stock_ret->addWidget(new WText("Author: "));
WText *nameout6=new WText ((*i)->author,stock_ret);
stock_ret->addWidget(new WBreak);
stock_ret->addWidget(new WBreak);

stock_ret->addWidget(new WText("Date of Arrival: "));
WText *nameout2=new WText ((*i)->darrival,stock_ret);
stock_ret->addWidget(new WBreak);
stock_ret->addWidget(new WBreak);

stock_ret->addWidget(new WText("Price: "));
WText *nameout4=new WText ((*i)->price,stock_ret);
stock_ret->addWidget(new WBreak);
stock_ret->addWidget(new WBreak);

stock_ret->addWidget(new WText("Rack No: "));
WText *nameout3=new WText ((*i)->rackno,stock_ret);
stock_ret->addWidget(new WBreak);
stock_ret->addWidget(new WBreak);

stock_ret->addWidget(new WText("No of Books: "));
WText *nameout5=new WText ((*i)->nbooks,stock_ret);
stock_ret->addWidget(new WBreak);
stock_ret->addWidget(new WBreak);


stock_ret->addWidget(new WText("Subject Code: "));
WText *nameout9=new WText ((*i)->scode,stock_ret);
stock_ret->addWidget(new WBreak);
stock_ret->addWidget(new WBreak);

 transaction.commit();
}
}
}
}

