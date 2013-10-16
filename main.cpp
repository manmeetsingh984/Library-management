#include <Wt/WContainerWidget>
#include <Wt/WBorderLayout>
#include <Wt/WText>
#include<Wt/WApplication>
#include<Wt/WImage>
#include<Wt/WStackedWidget>
#include<Wt/WImage>
#include<Wt/WMenu>
#include <Wt/WMenuItem>
#include <Wt/WTabWidget>
#include <Wt/WTextArea>


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

#include "member.h"
#include "memberret.h"
#include "stock.h"
#include "stockret.h"
#include "return.h"
#include "issue.h"

using namespace Wt;

class student : public WApplication
{
 public:
WContainerWidget *c;
WContainerWidget *member;
WContainerWidget *c2;
WContainerWidget *c3;
WContainerWidget *c4;
WContainerWidget *c5;
WMenu *menu;
WStackedWidget *menu_stack;
student(const WEnvironment & env):WApplication(env)
{
 useStyleSheet("library.css");
 //Creates a container on root.
 Wt::WContainerWidget *container = new Wt::WContainerWidget(root());
 
//new MyApplication(root());

//height of container
 container->setHeight(700);
container->setWidth(900);
 //set style class to container
 

//Makes a layout object of WBorderLayout. You used it to handle the layout of container
 Wt::WBorderLayout *layout = new Wt::WBorderLayout();
 container->setLayout(layout);

 const char *cell = "{1} ";
//Added text at the top
 Wt::WText *item = new Wt::WText(Wt::WString(cell).arg(" <h1>Library System</h1>"));
 item->setStyleClass("text3");
 layout->addWidget(item, Wt::WBorderLayout::North);

//Added Image in the West
/*menu_stack=new WStackedWidget();
menu = new WMenu(menu_stack, Vertical);
menu->setStyleClass("menu");
//hbox->addWidget( menu);
container->addWidget(menu_stack);

menu->setStyleClass("menu");
menu->addItem("Members",c);
menu->addItem("Add Members", member);
menu->addItem("Books",c2);
menu->addItem("AddBooks",c3);
menu->addItem("Lending",c4);
menu->addItem("Returning",c5);

 */
Wt::WTabWidget *tabW = new Wt::WTabWidget(container);

tabW->addTab(new Stock(container),
           "Add Books", Wt::WTabWidget::PreLoading);

tabW->addTab(new Stockretrieve(container),
           " Books", Wt::WTabWidget::PreLoading);

tabW->addTab( new MyApplication(container),
	     "Add Members", Wt::WTabWidget::PreLoading);

tabW->addTab(new Memberretrieve(container),
            "Members", Wt::WTabWidget::PreLoading);

tabW->addTab(new Issue(container),
           " Issue", Wt::WTabWidget::PreLoading);

tabW->addTab(new Return(container),
           " Return", Wt::WTabWidget::PreLoading);
/*Wt::WMenuItem *tab 
    = tabW->addTab(new Wt::WTextArea("You can close this tab"
				    " by clicking on the close icon."),
		   "Close");
tab->setCloseable(true);
*/
//tabW->setStyleClass("tabw");

layout->addWidget(tabW, Wt::WBorderLayout::West);


 item = new Wt::WText(Wt::WString(cell).arg(""));
 item->setStyleClass("no-box");
 layout->addWidget(item, Wt::WBorderLayout::East);

 item = new Wt::WText(Wt::WString(cell).arg(""));
 item->setStyleClass("no-box");
 layout->addWidget(item, Wt::WBorderLayout::South);

//Added text in center
 Wt::WImage *image = new Wt::WImage("img.png", root());
 item->setStyleClass("image");
 image->setHeight(0);
 image->setWidth(200);
 layout->addWidget(image, Wt::WBorderLayout::Center);


}
};
 WApplication *createapplication(const WEnvironment& env)
{
 return new student(env);
}
 int main(int argc, char ** argv)
{
 return WRun(argc, argv, &createapplication);
}
