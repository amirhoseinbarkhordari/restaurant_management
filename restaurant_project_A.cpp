#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <cstring>
#include <conio.h>

//-----------------------------------------------------
using namespace std;
//-----------------------------------------------------
struct date{
	int day,
	month,
	year;
};

class factor{
	public:
	int Total_price;
	int ID;
	date d;
	bool mode,mode1;
	int counter_food;
	int price[10];
	int number[10];
	string food[10];
	factor *next;
};

struct menu_food{
	string name_food;
	int price_food;
	int counter;
	bool mode;
	string name_matter[100];
	int amount_matter [100];
	menu_food *next;
};
struct inventory_kitchen{
	string name_material;
	long amount_material;
	inventory_kitchen*next;
};
//-----------------------------------------------------
int id = 0 ,x=0,m = 0,b=1,t=0;
string pass;
factor *f=NULL;
inventory_kitchen* material=NULL;
menu_food *menu=NULL;
//-----------------------------------------------------
void Admin_manage();
void Question();
void Change();
void Choose();
void View_all(factor *);
void View_undelivere(factor *,int );
void View_based_price(factor * );
void View_based_id(factor * );
void View_based_date(factor *);
void Reset_factors(factor *&);
void Add_food();
void manage_material(inventory_kitchen *& ,menu_food*&);
void Delete_food();
void Barmaid();
void Manage_kitchen_part(inventory_kitchen *&,menu_food *,factor *&);
void Kitchen_part();
void Deliver_order(factor *&);
void View_menu();
void Register_order(factor *&,menu_food *);
void Sort_price(factor *&);
void Record_amount_material();
int  Exit();
//------------------------------------------------------
int main()
{
	menu_food *temp;
	temp=new menu_food;
	temp->name_food="pizza";
	temp->price_food=10000;
	temp->name_matter[0]="meat";
	temp->name_matter[1]="mushroom ";
	temp->name_matter[2]="Sweet_pepper";
	temp->name_matter[3]="Cheese";
	temp->name_matter[4]="dough";
	temp->amount_matter[0]=200;
	temp->amount_matter[1]=200;
	temp->amount_matter[2]=150;
	temp->amount_matter[3]=200;
	temp->amount_matter[4]=1;
	temp->mode=false;
	temp->counter=4;
	temp->next=menu;
	menu=temp;
	temp=new menu_food;
	temp->name_food="snack";
	temp->price_food=5000;
	temp->name_matter[0]="mushroom ";
	temp->name_matter[1]="Cheese";
	temp->name_matter[2]="meat";
	temp->name_matter[3]="Toast";
	temp->amount_matter[0]=200;
	temp->amount_matter[1]=200;
	temp->amount_matter[2]=150;
	temp->amount_matter[3]=1;
	temp->mode=false;
	temp->counter=3;
	temp->next=menu;
	menu=temp;
	temp=new menu_food;
	temp->name_food="steak";
	temp->price_food=7000;
	temp->name_matter[0]="steak";
	temp->name_matter[1]="Oil";
	temp->name_matter[2]="Garlic";
	temp->amount_matter[0]=500;
	temp->amount_matter[1]=200;
	temp->amount_matter[2]=150;
	temp->counter=2;
	temp->mode=false;
	temp->next=menu;
	menu=temp;
	Choose();
}
//-------------------------------------------------------
//--------------Choose--------------
void Choose()
{
	int a;
	if(x==0){
		system("Color 0E");
		cout<<" \t\t\t     ***In the name of GOD***\n\n\n"<<endl;
		cout<<"  **Welcome to A.H.B RESTAURANT**    \t         **Welcome to A.H.B RESTAURANT**"<<endl<<endl;
		cout<<" \t\t\t  **Welcome to A.H.B RESTAURANT**"<<endl<<endl<<endl;
		x++;
	}
	cout<<" Admin(1) "<<endl;
	cout<<" Barmaid(2) "<<endl;
	cout<<" Kitchen part(3) "<<endl;
	cout<<" Manage kitchen part(4) "<<endl;
	cout<<" Exit(0) "<<endl<<endl;
	cout<<" \n Please enter your choice: ";
	cin>>a;
	switch(a)
	{
		case 1: Admin_manage() ; break;
		case 2: Barmaid() ; break;
		case 3: Kitchen_part() ; break;
		case 4: Manage_kitchen_part(material,menu,f);break;
		case 0: Exit() ; break;
		default :
		{
			cout<<" \n An error occured!\n **Please try again and enter a number between 1 to 4(0 for quit).** "<<endl<<endl;
			Choose();
		}
	}
}
//--------------Admin_manage--------------
void Admin_manage()
{
	string u , p , found[2];
	do
	{
	cout<<" \n Enter user name: ";
	cin>>u;
	cout<<" \n Enter password: ";
	cin>>p; 
	ifstream admin;
	admin.open("D:\\user&pass.txt");
	for(int i=0 ; i<2 ; i++)
		getline(admin,found[i]);
	}
	while((u != found[0]) || (p != found[1]));
	Question();
}
//--------------Question--------------
void Question()
{
	if(x==1){
		system("Cls");
		x++;
	}
	int a;
	cout<<" \n Change your user name and password(1) "<<endl;
	cout<<" View all factors(2) "<<endl;
	cout<<" View undelivere factors(3) "<<endl;
	cout<<" View factors based on the total price(4) "<<endl;
	cout<<" View factor based on the ID number(5) "<<endl;
	cout<<" View factor based on the date(6) "<<endl;
	cout<<" Reset all factors and ID's factors(7) "<<endl;
	cout<<" Add a new food(8) "<<endl;
	cout<<" Delete a food(9) "<<endl;
	cout<<" Back(0) "<<endl;
	cout<<" \n Please enter a number between 1 to 8 (0 for quit) for going to that part: ";
	cin>>a;
	switch (a)
	{
		case 0: Choose() ; break;
		case 1: Change() ; break;
		case 2: View_all( f ) ; break;
		case 3: View_undelivere( f,1 ) ; break;
		case 4: View_based_price( f) ; break;
		case 5: View_based_id( f ) ; break;
		case 6: View_based_date(f) ; break;
		case 7: Reset_factors(f) ; break;
		case 8: Add_food() ; break;
		case 9: Delete_food() ; break;
		default :
		{
			cout<<" **\n An error occured! \n **Please enter a number between 0 to 8.** "<<endl;
			Question();
		}
	}
}
//--------------Change--------------
void Change()
{
	system("Cls");
	char a;
	string p_admin[2] , p_user , pass2;
	cout<<" \n Do you want to change your user name and password?(Y or N) ";
	cin>>a;
	if((a == 'Y')  ||  (a == 'y'))
	{
		ifstream ad;
		ad.open("D:\\user&pass.txt");
		if (!ad)
		{
			cerr <<" \n Some thing wrong during opening file! \n\n **Please try again.** \n "<< endl;
		}
		else{
			for(int i=0 ; i<2 ; i++)
				getline(ad , p_admin[i]);
			ad.close();
		}
		do
		{
			cout<<" \n Please enter previous user name: ";
			cin>>p_user;
			cout<<" \n Please enter previous password: ";
			cin>>pass2 ;
		}
		while((p_user != p_admin[0]) || (pass2 != p_admin[1]));

		ofstream adm;
		string user , password;
		adm.open("D:\\user&pass.txt");
		cout<<" \n Please enter your new user name: ";
		cin>>user;
		cout<<" \n Please enter your new password: ";
		cin>>pass2;
		adm<<user<<endl<<pass2;
		adm.close();
		cout<<" \n **Your user name and password changed successfully.** "<<endl<<endl<<"--------------------------------------------"<<endl;
	}
	Question();
}
//--------------View_all--------------
void View_all(factor* f)
{
	system("Cls");
	factor *temp=f;
	while(temp!=NULL)
	{
		cout<<" \n\nFactor("<<temp->ID<<")"<<endl<<"-----------------------------"<<endl;
		cout<<" Factor ID:"<< temp->ID <<" \t\tdate:  "<< temp->d.day << " / " << temp->d.month << " / " << temp->d.year <<endl<<endl<<"-------------------------------\n";
	    cout<<" Food names  \t  Prices  \t  Numbers  \t  Total price of foods"<<endl<<"-----------  \t-----------  \t-----------  \t-------------\n";
		for(int j=0 ; j<=temp->counter_food; j++)
			cout<< j+1 << ") " << temp->food[j] << "  \t  " << temp->price[j]/temp->number[j] << "     \t     " <<temp->number[j] << "      \t       " << temp->price[j]<<endl;
        cout<<"------------------------------"<<endl;
        cout<<" Total Price of the foods that you ordered: "<< temp->Total_price<<endl;
        cout<<" \n Delivery status: ";
        if(temp->mode)
        	cout<<" Delivere. "<<endl<<endl<<"*********************************************\n"<<endl;
        else
        	cout<<" Undelivere. "<<endl<<endl<<"*********************************************\n"<<endl;
		temp=temp->next;
	}
	Question();
}
//--------------view_based_date-----------------
void View_based_date(factor *f){
	system("Cls");
	Sort_price(f);
	factor* temp=f;
	date dt;
	bool c=true;
	cout<<" \n Enter the present date:(dd/mm/yyyy)  "<<endl;
	cin>>dt.day>>dt.month>>dt.year;
	while(temp!=NULL){
		if((temp->d.day==dt.day)&&(temp->d.month==dt.month)&&(temp->d.year==dt.year)){
			cout<<" \n\nFactor("<<temp->ID<<")"<<endl<<"-----------------------------"<<endl;
			cout<<" Factor ID:"<< temp->ID <<" \t\tdate:  "<< temp->d.day << " / " << temp->d.month << " / " << temp->d.year <<endl<<endl<<"-------------------------------\n";
			cout<<" Food names  \t  Prices  \t  Numbers  \t  Total price of foods"<<endl<<"-----------  \t-----------  \t-----------  \t-------------\n";
			for(int j=0 ; j<=temp->counter_food; j++)
				cout<< j+1 << ") " << temp->food[j] << "  \t  " << temp->price[j]/temp->number[j] << "     \t     " <<temp->number[j] << "      \t       " << temp->price[j]<<endl;
			cout<<"------------------------------"<<endl;
			cout<<" Total Price of the foods that you ordered: "<< temp->Total_price<<endl;
			cout<<" \n Delivery status: ";
			if(temp->mode)
				cout<<" Delivere. "<<endl<<endl<<"*******************************************\n"<<endl;
			else
				cout<<" Undelivere. "<<endl<<endl<<"*********************************************\n"<<endl;
			c=false;
		}
		temp=temp->next;
	}
	if(c)
		cout<<"\n**  There isnt any factor in this date  **\n\n\n"<<endl;
	Question();
}
//--------------View_undelivere--------------
void View_undelivere(factor *f,int n)
{
	system("Cls");
	factor * temp=f;
	bool h;
	while(temp!=NULL){
		h = temp->mode;
		if(!h)
		{
			cout<<" Factor(" << temp->ID << ")" <<endl<<"-------------------------"<<endl;
			cout<<" Factor ID: "<< temp->ID << " \t\tDate:  "<< temp->d.day << " / " << temp->d.month << " / " << temp->d.year <<endl<<endl<<"-------------------------------\n";
			cout<<" Food names  \t  Prices  \t  Numbers  \t  Total price of food  "<<endl<<"-----------\t  -----------  \t------------  \t------------"<<endl;
			for(int j=0 ; j<=temp->counter_food ; j++)
				cout<< j+1 << ") " << temp->food[j] << " \t   " << temp->price[j]/temp->number[j] << "   \t   " << temp->number[j] << "  \t\t " << temp->price[j]<<endl;
			cout<<"-----------------------------"<<endl;
			cout<<" Total Price of foods that you ordered: "<< temp->Total_price<<"\n\n*********************************************" <<endl<<endl;
		}
		temp=temp->next;
	}
	if(n==0)
		Kitchen_part();
	else
		Question();
}
//--------------View_based_price--------------
void View_based_price(factor * f)
{
	system("Cls");
	Sort_price(f);
	factor *temp=f;
	while(temp!=NULL)
	{
		cout<<" Factor( "<< temp->ID <<" )"<<endl<<"----------------------------"<<endl;
		cout<<" Factor ID:  "<< temp->ID <<"\t\t Date:  "<< temp->d.day << " / " << temp->d.month << " / " << temp->d.year<<endl;
		cout<<" Food names\t   Prices\t   numbers\t   Total price of food   "<<"\n------------  \t------------  \t-------------  \t -------------------------"<<endl;
		for(int j=0 ; j<=temp->counter_food ; j++)
			cout<< j+1 <<") "<< temp->food[j] <<" \t   "<<temp->price[j]/temp->number[j]<<"    \t    "<< temp->number[j] <<"   \t         "<< temp->price[j] <<endl;
		cout<<"-----------------------------"<<endl;
		cout<<" Total Price of foods that you ordered: "<< temp->Total_price <<endl;
		cout<<" Delivery Status: ";
		if(temp->mode)
			cout<<" Delivere. "<<endl<<endl<<"*********************************************\n"<<endl;
		else
			cout<<" Undelivere. "<<endl<<endl<<"*********************************************\n"<<endl;
		temp=temp->next;
	}
	Question();
}
//--------------Sort_price--------------
void Sort_price(factor*& f)
{
    factor *temp1=new factor;
	factor *temp2=new factor;
	int temp;
	bool tmp;
	string name;
	date dt;
	for(temp1=f;temp1!=NULL;temp1=temp1->next)
		for(temp2=temp1->next;temp2!=NULL;temp2=temp2->next)
			if(temp1->Total_price > temp2->Total_price){
				temp=temp1->Total_price;
				temp1->Total_price=temp2->Total_price;
				temp2->Total_price=temp;
				temp=temp1->ID;
				temp1->ID=temp2->ID;
				temp2->ID=temp;
				dt=temp1->d;
				temp1->d=temp2->d;
				temp2->d=dt;
				tmp=temp1->mode;
				temp1->mode=temp2->mode;
				temp2->mode=tmp;
				temp=temp1->counter_food;
				temp1->counter_food=temp2->counter_food;
				temp2->counter_food=temp;
				for(int i=0;i<10;i++){
					temp=temp1->price[i];
					name=temp1->food[i];
					temp1->price[i]=temp2->price[i];
					temp1->food[i]=temp2->food[i];
					temp2->price[i]=temp;
					temp2->food[i]=name;
				}
				for(int i=0;i<10;i++){
					temp=temp1->number[i];
					temp1->number[i]=temp2->number[i];
					temp2->number[i]=temp;
				}
			}
}
//--------------View_based_id--------------
void  View_based_id(factor* f)
{
	system("Cls");
	int v;
	factor *temp=f;
	bool c=true;
	cout<<" Please enter ID factor: ";
	cin>>v;
	while((temp!=NULL)&&(c)){
		if(temp->ID == v)
		{
			cout<<" Factor( " << temp->ID << ")" <<endl<<"\n---------------------------\n"<<endl;
			cout<<" ID factor: "<< temp->ID << "\t\tDate:  "<< temp->d.day << " / " << temp->d.month << " / " << temp->d.year <<endl<<"\n"<<"------------------------------"<<endl;
			cout<<" Food names  \t  Prices  \t  Numbers  \t  Total price of food  "<<endl<<"-----------\t-----------\t--------------"<<endl;
			for(int j=0 ;j<=temp->counter_food ; j++)
				cout<< j+1 << " ) " << temp->food[j] << "\t" << temp->price[j]/temp->number[j] << "\t" << temp->number[j] << "\t" << temp->price[j] <<endl;
			cout<<" Total Price of foods that you ordered: "<< temp->Total_price <<endl<<endl;
			cout<<" Delivery Status: ";
			if(temp->mode)
				cout<<" Delivere. "<<endl<<endl<<endl;
			else
				cout<<" Undelivere. "<<endl<<endl<<endl;
			c=false;
			cout<<"\n****************************************************\n\n"<<endl;
		}
		else
			temp=temp->next;
	}
	if(c)
	cout<<"\n**  There isnt factor with this ID  **\n\n"<<endl;
	Question();
}
//--------------Reset_factors--------------
void  Reset_factors(factor*& f)
{
	system("Cls");
	factor *temp;
	while(f!=NULL){
		temp=new factor;
		temp=f;
		f=f->next;
		delete temp;
	}
	id = 0;
	cout<<"\n **Factor reseted successfully.** "<<endl<<"*******************************************\n\n"<<endl;
	Question();
}
//--------------Add_food--------------
void Add_food()
{
	menu_food *temp1;
	temp1=new menu_food;
	char c,d='y';
	cout<<"\n Do you want to add a new food?(Y or N): ";
	cin>>c;
	if((c == 'y')  ||  (c == 'Y'))
	{
		cout<<" \n Enter your food name: ";
		cin>>temp1->name_food;
		cout<<" \n Enter the price of this food: ";
		cin>>temp1->price_food;
		for(int i=0;(i<10)&&((d=='y')||(d=='Y'));i++){
			cout<<"\nEnter names used matters in this food: ";
			cin>>temp1->name_matter[i];
			cout<<"\nEnter amount used "<<temp1->name_matter[i]<<": ";
			cin>>temp1->amount_matter[i];
			temp1->mode=true;
			temp1->counter=i;
			cout<<"\nDo you want add another matter?(Y or N) ";
			cin>>d;
		}
		temp1->next=menu;
		menu=temp1;
		t=1;
		Manage_kitchen_part(material,menu,f);
		cout<<"\n **Your new food added successfully.** "<<endl<<endl;
		Add_food();
	}
	else
		Question();
}
//--------------Delete_food--------------
void Delete_food()
{
	menu_food *temp1=menu,*temp2=menu;
	char c;
	bool d=false;
	string name;
	cout<<" \n Do you want to delete a food?(Y or N) ";
	cin>>c;
	if((c == 'Y')  ||  (c == 'y'))
	{
		if(temp1==NULL){
		cout<<"\n***  There is no element in the list of menu  ***\n";
		Choose();
		}
		else{
			cout<<" \n Enter the name of food that you want to delete it from menu: ";
			cin>>name;
			while(temp1!=NULL){
				if(temp1->name_food==name){
					if((temp1==menu)&&(temp1->next==NULL))
						menu=NULL;
					else if(temp1==menu)
						menu=menu->next;	
					else {
						while(temp2->next!=temp1)
							temp2=temp2->next;
						temp2->next=temp1->next;
					}
					delete temp1;
					d=true;
					cout<<"\n **Food deleted successfully.** "<<endl<<endl;
					break;
				}
				else
					temp1=temp1->next;
			}
			if(!d)
				cout<<"\n***  There was no food with this name in the menu_food list   ***\n\n";
			Delete_food();
		}
	}
	else
		Question();
}
//--------------Barmaid--------------
void Barmaid()
{
	int a;
	cout<<" \n View menu(1) \n Register order(2) \n Back(0) \n" <<endl;
	cout<<" Please enter your choice: ";
	cin>>a;
	switch(a)
	{
		case 1: View_menu() ; break;
		case 2: Register_order(f,menu) ; break;
		case 0: Choose();break;
		default :
		{
			cout<<" \n **Please try again and enter a number between 1 and 2:** \n\n";
			Barmaid();
			break;
		}
	}
}
//--------------Kitchen_part--------------
void Kitchen_part()
{
	int a;
	cout<<" \n View undelivere factors(1) \n Register order in deliver orders(2) \n Back(0) \n"<<endl;
	cout<<" Enter your choice: ";
	cin>>a;
	switch(a)
	{
		case 1: View_undelivere(f,0) ; break;
		case 2: Deliver_order(f) ; break;
		case 0: Choose();break;
		default :
		{
			cout<<" \n **Please try again** \n ";
			Kitchen_part();
			break;
		}
	}
}
//--------------View_menu--------------
void View_menu()
{
	system("Cls");
	int i=1;
	char h;
	menu_food *temp1=menu;
	cout<<" \n Food names\t"<<"\tFood prices"<<endl<<"------------           -------------"<<endl;
	while(temp1!=NULL)
	{
		cout<< i<<") "<<temp1->name_food<<setw(20)<<temp1->price_food<<endl;
		i++;
		temp1=temp1->next;
	}
	cout<<endl;
	cout<<" \n Do you want to register order?(Y or N) ";
	cin>>h;
	if((h == 'y')  ||  (h == 'Y'))
		Register_order(f,menu);
	else
		Choose();
}
//--------------Register_order--------------
void Register_order(factor*& f,menu_food *menu)
{
	bool c,h=true;
	int j;
	char d;
	string name;
	factor *temp=new factor;
	menu_food *temp1=menu;
	temp->mode=false;
    temp->mode1=true;
	cout<<" \n Enter ID factor: ";
	temp->ID = ++id;
	cout<<temp->ID<<endl;
	temp->Total_price=0;
	cout<<" \n Enter the present date:(dd/mm/yyyy)  "<<endl;
	cin>>temp->d.day;
	cin>>temp->d.month;
	cin>>temp->d.year;
	cout<<" \n Enter food name: ";
	for(int i=0;(i<10)&&(h);i++){
		j=1;
		c=true;
		while(c){
			if(j>=2) 
				cout<<"\n**  Error!!! There are not this name in menu_food list  **\n\n\n Please enter food name again: ";

			cin>>temp->food[i];

			for(;(temp1!=NULL)&&(c);temp1=temp1->next){
				if(temp->food[i]==temp1->name_food){
					cout<<" \n\nEnter number of the "<<temp->food[i]<<": ";
					cin>>temp->number[i];
					temp->price[i]=(temp->number[i])*(temp1->price_food);
					temp->Total_price+=temp->price[i];
					c=false;
				}
			}
			temp1=menu;
			j++;
		}
		cout<<" \n Do you want to add another food?(Y or N) ";
		cin>>d;
		if((d=='n')||(d=='N'))
			h=false;
		else
			cout<<" \n Enter food name: ";
		temp->counter_food=i;
	}
	temp->next=NULL;
	if(f==NULL)
		f=temp;
	else if(f->next==NULL)
		f->next=temp;
	else {
		factor *tmp=f;
		while(tmp->next != NULL)
			tmp=tmp->next;
		tmp->next=temp;
	}
	cout<<" **  Your order registered successfully.  ** "<<endl<<"------------------------------------\n"<<endl;
	Barmaid();
}
//--------------Deliver_order--------------
void Deliver_order(factor*& f)
{
	system("Cls");
	factor * temp=f;
	int s;
	bool c=true;
	cout<<" Enter ID factor: ";
	cin>>s;
	for(;(temp!=NULL)&&(c);temp=temp->next)
	{
		if(s == temp->ID)
		{
			temp->mode=true;
			c=false;
		}
	}
	if(c) cout<<"\n***  There isnt this ID factor  ***\n\n"<<endl;
	else  cout<<"\n***  Delivery factor done successfully  ***\n\n";
	Kitchen_part();
}
//-------------------------Manage_kitchen_part------------------------------------
void Manage_kitchen_part(inventory_kitchen *& material,menu_food *menu,factor *& f){
	int j=1;
	bool z=true;
	if(b==1){
		system("Cls");
		menu_food *temp=menu;
		inventory_kitchen*temp1,*temp2;
		cout<<"\n---------------------------------------\n\nEnter all inventory kitchen:\n\n";
		for(int i=0;temp!=NULL;i++){
			temp2=material;
			z=true;
			if(i<=temp->counter){
				while((temp2!=NULL)&&(z)){
					if(temp2->name_material==temp->name_matter[i])
						z=false;
					else
						temp2=temp2->next;
				}
				if(z){
					temp1= new inventory_kitchen;
					temp1->name_material=temp->name_matter[i];
					temp1->next=material;
					material=temp1;
				}
			}
			else{
				temp=temp->next;
				i=0;
			}
		}
		cout<<"\n----------------------------------\n\n"<<"Name material \t\tThe total amount material(gr or number)\n";
		cout<<"--------------\t\t ------------------------------\n";
		for(temp2=material;temp2!=NULL;temp2=temp2->next){
			cout<<j++<<")"<<temp2->name_material<<":\t\t";
			cin>>temp2->amount_material;
		}
		b++;
		t=2;
		cout<<"\n------------------------------\n\n";
		Choose();
	}
	else if(t==1){
		menu_food* temp=menu;
		bool z=true;
		int j=1;
		inventory_kitchen * in,*temp1= material;

		while(!temp->mode)
			temp=temp->next;

		for(int i=0;i<=temp->counter;i++){
			temp1= material;
			z=true;
			while((z)&&(temp1!=NULL)){
				if(temp1->name_material==temp->name_matter[i])
				z=false;
				temp1=temp1->next;
			}
			if(z){

				if(t==1){
					cout<<"\n----------------------------------\n\n"<<"Name material \t\tThe total amount material(gr or number)\n";
					cout<<"--------------\t\t ------------------------------\n";
				}

				t=2;
				in=new inventory_kitchen;
				in->name_material=temp->name_matter[i];
				cout<<j++<<")"<<in->name_material<<"\t\t\t";
				cin>>in->amount_material;
				in->next= material;
				material=in;
			}
		}

		temp->mode=false;
	}
	else {
		system("Cls");	
		bool n=true;
		menu_food * mu=menu;
		inventory_kitchen *matt=material;
		factor *fact=f;
		while(fact!=NULL){
			if(fact->mode1){
				for(int i=0;i<=fact->counter_food;i++){
					mu=menu;

					while(mu->name_food!=fact->food[i])
						mu=mu->next;

					for(int k=0;k<=mu->counter;k++){
						matt=material;
						n=true;
						while((n)&&(matt!=NULL)){
							if(mu->name_matter[k]== matt->name_material){
								matt->amount_material= (matt->amount_material) - (fact->number[i]*mu->amount_matter[k]);
								fact->mode1=false;
								n=false;
							}
							else matt=matt->next;
						}
					}
				}
			}

			else fact=fact->next;
		}
		matt=material;
		cout<<"inventory kitchen:\n\n---------------------------\n";
		cout<<"name materials\t\tamount materials\n------------\t\t-------------------------\n";
		j=1;
		while(matt!=NULL){
			cout<<j++<<")"<<matt->name_material<<"\t\t\t"<<matt->amount_material<<endl;
			matt=matt->next;
		}
		cout<<"\n-----------------------------------\n\n";
		Choose();
	}
}
//---------------------------------exit--------------------
int Exit(){
	return 0;
}
