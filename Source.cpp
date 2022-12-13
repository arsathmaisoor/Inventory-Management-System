#include <iostream>
#include <string.h>
#include <conio.h>
#include <stdlib.h>
#include <fstream>
using namespace std;

void userLogin();
int stock();
int stock_FW();
int stock_CS();
void record_transaction();
void display_staff();
void add_remove_staff();
//////////////////////////////////////////////////////////////////////////

class Staff {
protected:
	
	

public:


};
//////////////////////////////////////////////////////////////////////////
class FloorWorkers :public Staff {
protected:

public:
	//4
	FloorWorkers(){}
	void Main();
	
};

void FloorWorkers::Main()
{

	cout << "\t1 : Stock Access" << endl;
	cout << "\t2 : Exit" << endl;
	int select;
	cin >> select;
	switch (select)
	{
	case 1: {
		stock_FW;
		break;
	}

	case 2: {
		exit(0);
		break;
	}
	}
}
//////////////////////////////////////////////////////////////////////////
class Cashier: public Staff {
protected:

public:
	Cashier(){}
	void Main();
};

void Cashier::Main()
{

		cout << "\t1 : Record a transaction" << endl;
		cout << "\t2 : Stock Access" << endl;
		cout << "\t3 : Exit" << endl;
		int select;
		cin >> select;
		switch (select)
		{
		case 1: {
			record_transaction();
			break;
		}

		case 2: {
			stock_CS();
			break;
		}
		case 3: {
			exit(0);
			break;
		}
		}
	
}

void record_transaction()
{
	cout << "Name of the Customer\t:\t";
	string Cus_name;
	cin >> Cus_name;
	cout << "Name of the Cashier\t:\t";
	string Cashier_name;
	cin >> Cashier_name;
	cout << "Items Bought\t:\t";
	string Item;
	cin >> Item;

	ofstream T("Transactions.txt",ios::app);
	T <<"(Cashier) "<< Cashier_name << "\t\t" <<"(Customer) "<< Cus_name << "\t\t(Item) " << Item << endl;

}

///////////////////////////////////////////////////////////////////////////
class Manager :public Staff {
protected:

public:
	Manager(){}
	void Main();
};

void Manager::Main() {
	cout << "\t1 : Display Staff Details" << endl;
	cout << "\t2 : Record a transaction" << endl;
	cout << "\t3 : Stock Access" << endl;
	cout << "\t4 : Exit" << endl;
	int select;
	cin >> select;
	switch (select)
	{
	case 1: {
		display_staff();
		break;
	}

	case 2: {
		record_transaction();
		break;
	}

	case 3: {
		stock();
		break;
	}
	case 4: {
		exit(0);
		break;
	}
	}
}

void display_staff() {
	string* name;
	name = new string[100];
	string* joindate;
	joindate = new string[100];
	string* post;
	post = new string[100];

	ifstream s("staffdetails.txt");
	int no = 0;
	system("CLS");
	cout << "Name\t\tJoin.Date\t\tPost" << endl;
	while (s>>name[no]>>post[no]>>joindate[no])
	{
		
		no++;
	}
	
	for (int i = 0;i<100;i++)
	{
		cout << name[i] << "\t\t" << joindate[i] << "\t\t" << post[i] << endl;
		if (name[i] == "\0")
		{
			cout << "\n\tEND OF THE DETAILS";
			int k;
			cin >> k;
			break;
		}

	}
	
}

///////////////////////////////////////////////////////////////////////////
class Owner :public Staff {
protected:

public:
	Owner() {}
	void Main();
};

void Owner::Main() {
	cout << "\t1 : Display Staff Details" << endl;
	cout << "\t2 : Add or Remove Staff" << endl;
	cout << "\t3 : Record a transaction" << endl;
	cout << "\t4 : Stock Access" << endl;
	cout << "\t5 : Exit" << endl;
	int select;
	cin >> select;
	switch (select)
	{
	case 1: {
		display_staff();
		break;
	}
	
	case 2: {
		add_remove_staff();
		break;
	}

	case 3: {
		record_transaction();
		break;
	}

	case 4: {
		stock();
		break;
	}
	case 5: {
		exit(0);
		break;
	}
	}
}

void add_remove_staff() {
	system("CLS");
	cout << "\t1 : Add staff\n";
	cout << "\t2 : Remove staff\n";
	int sel;
	cin >> sel;
	switch (sel)
	{
	case 1: {
		cout << "Name of the new staff : ";
		string name;
		cin >> name;
		cout << "Post of the new staff : ";
		string post;
		cin >> post;
		cout << "Date he/she joined : ";
		string date;
		cin >> date;
		
		ofstream o("staffdetails.txt",ios::app);
		o << endl << name << "\t" << post << "\t" << date;

		cout << "Username of new employee\t:\t";
		string username;
		cin >> username;
		switch (post[0])
		{
		case 'F': {
			username = "F" + username;
			break;
		}

		case 'M': {
			username = "M" + username;
			break;
		}

		case 'C': {
			username = "C" + username;
			break;
		}
		}
		cout << "Password for new employee : ";
		string password;
		cin >> password;
		
		ofstream p("Username_Password.txt",ios::app);
		p << endl << username << "\t" << password;
		break;
	}

	case 2: {ifstream out("staffdetails.txt");
		ifstream pwd("Username_Password.txt");
		string* username;
		username = new string[100];
		string* password;
		password = new string[100];
		string* name;
		name = new string[100];
		string* post;
		post = new string[100];
		string* date;
		date = new string[100];
		int no = 0;
		
			cout << "Name\t\tJoin.Date\t\tPost" << endl;
			while (out >> name[no] >> post[no] >> date[no])
			{

				no++;
			}
			while (pwd>>username[no]>>password[no])
			{
				no++;
			}
			for (int i = 0;i < 100;i++)
			{
				cout <<i+1<< name[i] << "\t\t" << date[i] << "\t\t" << post[i] << endl;
				if (name[i] == "\0")
				{
					cout << "\n\tEND OF THE DETAILS";
					int k;
					cin >> k;
					break;
				}

			}
			cout << "\n\n\tEnter the number of the staff to remove : ";
			int num;
			cin >> num;
			int count = 0;
			while (name[count] != "\0")
			{
				if (num - 1 <= count)
				{
					name[count] = name[count + 1];
					post[count] = post[count + 1];
					date[count] = date[count + 1];
					username[count] = username[count + 1];
					password[count] = password[count + 1];
				}
				count++;
			}

			ofstream o("staffdetails.txt");
			ofstream s("Username_Password.txt",ios::app);
			int k = 0;
			while (name[k] != "\0")
			{
				o << name[k] << "\t" << post[k] << "\t" << date[k] << endl;
				s << username[k] << "\t" << password[k] << endl;
				k++;
			}

		break;
	}

	}
}

///////////////////////////////////////////////////////////////////////////
class Stock {
protected:

	int number[4];
	int numbers[8];
	string name[4];
	string names[8];
	string brand[4];
	string brandItem[8];
	float gram[4];
	float gramItem[8];
	float discount[4];
	float discounts[8];
	float retailPrice[4];
	float retailprice[8];
	float totalPrice[4];
	float totalprice[8];
	char local_imported[4];
	char localImported[8];

public:
	virtual void Main() {}
	virtual void displayItems() {}
	virtual void addItems() {}
	virtual void removeItems() {}
	virtual void finalPrice() {}
	virtual void updatefile() {}

};
class Stock_FW {
protected:

	int number[4];
	int numbers[8];
	string name[4];
	string names[8];
	string brand[4];
	string brandItem[8];
	float gram[4];
	float gramItem[8];
	float discount[4];
	float discounts[8];
	float retailPrice[4];
	float retailprice[8];
	float totalPrice[4];
	float totalprice[8];
	char local_imported[4];
	char localImported[8];

public:
	virtual void Main() {}
	virtual void displayItems() {}
	virtual void addItems() {}
	virtual void finalPrice() {}
	virtual void updatefile() {}

};
class Stock_CS {
protected:

	int number[4];
	int numbers[8];
	string name[4];
	string names[8];
	string brand[4];
	string brandItem[8];
	float gram[4];
	float gramItem[8];
	float discount[4];
	float discounts[8];
	float retailPrice[4];
	float retailprice[8];
	float totalPrice[4];
	float totalprice[8];
	char local_imported[4];
	char localImported[8];

public:
	virtual void Main() {}
	virtual void displayItems() {}
	virtual void removeItems() {}
	virtual void finalPrice() {}
	virtual void updatefile() {}

};

class Fruits_Vegetables :public Stock {
	//apple	orange	carrot	beans

public:
	Fruits_Vegetables()
	{

		ifstream FruVeg("FV.txt");
		for (int i = 0; i < 4; i++)
		{
			FruVeg >> name[i] >> gram[i] >> retailPrice[i] >> discount[i] >> totalPrice[i] >> local_imported[i];

		}
		
	}
	void Main()
	{
		system("CLS");
		int n;
		cout << "1. Display items\n2. Add items\n3. Remove items\n4. Back\n";
		cin >> n;
		switch (n)
		{
		case 1:
			displayItems();
			break;
		case 2:
			addItems();
			break;
		case 3:
			removeItems();
			break;
		case 4:
			stock();
			break;
		}
	}

	void updatefile()
	{
		ofstream FV("FV.txt");
		for (int i = 0; i < 4; i++)
		{
			FV << name[i] << " " << gram[i] << " " << retailPrice[i] << " " << discount[i] << " " << totalPrice[i] << " " << local_imported[i] << endl;

		}
	}



	void displayItems()
	{
		system("CLS");

		for (int i = 0; i < 4; i++)
		{
			cout <<i+1<<"\t"<< name[i] << "\t" << gram[i] << "\t" << retailPrice[i] << "\t" << discount[i] << " \t" << totalPrice[i] << "\t" << local_imported[i] << endl;

		}
		cout << endl;
		char let;
		cout << "Do you need to continue : ";
		cin >> let;
		if (let == 'y')
			Main();
	}
	void addItems()
	{
		system("CLS");
		cout << "No\tName\tWeight\tRet.Price\tDiscount\tFinal Price" << endl;
		for (int i = 0; i < 4; i++)
		{
			cout << i + 1 << "\t" << name[i] << "\t" << gram[i] << "g\tRs." << retailPrice[i] << "\t\t"<<discount[i] <<"%\tRs."<< totalPrice[i] << "\t";
			if (local_imported[i] == 'l')
				cout << "Local\n";
			else
				cout << "Imported\n";
		}
		cout << endl << endl;
		int no, grams;
		char li;
		cout << "What do you need to add  " << endl;
		cout << "Select number of item from above list : ";
	
		cin >> no;
		cout << "How many grams of " << name[no - 1] << "s you need to add : ";
		cin >> grams;

		gram[no - 1] += grams;
		updatefile();
		Main();

	}
	void removeItems()
	{
		system("CLS");
		for (int i = 0; i < 4; i++)
		{
			cout << i + 1 << "\t" << name[i] << "\t" << gram[i] << "g\tRs." << retailPrice[i] << "\tRs." << totalPrice[i] << "\t";
			if (local_imported[i] == 'l')
				cout << "Local\n";
			else
				cout << "Imported\n";
		}
		cout << endl << endl;


		int no, grams;
		cout << "What do you need to remove  " << endl;
		cout << "Select number of item : ";
		cin >> no;
		cout << "How many grams of " << name[no - 1] << "s you need to remove : ";
		cin >> grams;

		if (gram[no - 1] < grams)
		{
			cout << "Sorry there is no enough " << name[no - 1] << "s to remove";
			Main();
		}
		else
		{
			gram[no - 1] -= grams;
			updatefile();
			Main();
		}

	}
};
class Fruits_Vegetables_FW :public Stock_FW {
	//apple	orange	carrot	beans

public:
	Fruits_Vegetables_FW()
	{

		ifstream FruVeg("FV.txt");
		for (int i = 0; i < 4; i++)
		{
			FruVeg >> name[i] >> gram[i] >> retailPrice[i] >> discount[i] >> totalPrice[i] >> local_imported[i];

		}

	}
	void Main()
	{
		system("CLS");
		int n;
		cout << "1. Display items\n2. Add items\n3. Back\n";
		cin >> n;
		switch (n)
		{
		case 1:
			displayItems();
			break;
		case 2:
			addItems();
			break;
		case 3:
			stock_FW();
			break;
		}
	}

	void updatefile()
	{
		ofstream FV("FV.txt");
		for (int i = 0; i < 4; i++)
		{
			FV << name[i] << " " << gram[i] << " " << retailPrice[i] << " " << discount[i] << " " << totalPrice[i] << " " << local_imported[i] << endl;

		}
	}



	void displayItems()
	{
		system("CLS");

		for (int i = 0; i < 4; i++)
		{
			cout << i + 1 << "\t" << name[i] << "\t" << gram[i] << "\t" << retailPrice[i] << "\t" << discount[i] << " \t" << totalPrice[i] << "\t" << local_imported[i] << endl;

		}
		cout << endl;
		char let;
		cout << "Do you need to continue : ";
		cin >> let;
		if (let == 'y')
			Main();
	}
	void addItems()
	{
		system("CLS");
		cout << "No\tName\tWeight\tRet.Price\tDiscount\tFinal Price" << endl;
		for (int i = 0; i < 4; i++)
		{
			cout << i + 1 << "\t" << name[i] << "\t" << gram[i] << "g\tRs." << retailPrice[i] << "\t\t" << discount[i] << "%\tRs." << totalPrice[i] << "\t";
			if (local_imported[i] == 'l')
				cout << "Local\n";
			else
				cout << "Imported\n";
		}
		cout << endl << endl;
		int no, grams;
		char li;
		cout << "What do you need to add  " << endl;
		cout << "Select number of item from above list : ";

		cin >> no;
		cout << "How many grams of " << name[no - 1] << "s you need to add : ";
		cin >> grams;

		gram[no - 1] += grams;
		updatefile();
		Main();

	}
	
};
class Fruits_Vegetables_CS :public Stock_CS {
	//apple	orange	carrot	beans

public:
	Fruits_Vegetables_CS()
	{

		ifstream FruVeg("FV.txt");
		for (int i = 0; i < 4; i++)
		{
			FruVeg >> name[i] >> gram[i] >> retailPrice[i] >> discount[i] >> totalPrice[i] >> local_imported[i];

		}

	}
	void Main()
	{
		system("CLS");
		int n;
		cout << "1. Display items\n2. Add items\n3. Back\n";
		cin >> n;
		switch (n)
		{
		case 1:
			displayItems();
			break;
		case 2:
			removeItems();
			break;
		case 3:
			stock();
			break;
		}
	}

	void updatefile()
	{
		ofstream FV("FV.txt");
		for (int i = 0; i < 4; i++)
		{
			FV << name[i] << " " << gram[i] << " " << retailPrice[i] << " " << discount[i] << " " << totalPrice[i] << " " << local_imported[i] << endl;

		}
	}



	void displayItems()
	{
		system("CLS");

		for (int i = 0; i < 4; i++)
		{
			cout << i + 1 << "\t" << name[i] << "\t" << gram[i] << "\t" << retailPrice[i] << "\t" << discount[i] << " \t" << totalPrice[i] << "\t" << local_imported[i] << endl;

		}
		cout << endl;
		char let;
		cout << "Do you need to continue : ";
		cin >> let;
		if (let == 'y')
			Main();
	}
	
	void removeItems()
	{
		system("CLS");
		for (int i = 0; i < 4; i++)
		{
			cout << i + 1 << "\t" << name[i] << "\t" << gram[i] << "g\tRs." << retailPrice[i] << "\tRs." << totalPrice[i] << "\t";
			if (local_imported[i] == 'l')
				cout << "Local\n";
			else
				cout << "Imported\n";
		}
		cout << endl << endl;


		int no, grams;
		cout << "What do you need to remove  " << endl;
		cout << "Select number of item : ";
		cin >> no;
		cout << "How many grams of " << name[no - 1] << "s you need to remove : ";
		cin >> grams;

		if (gram[no - 1] < grams)
		{
			cout << "Sorry there is no enough " << name[no - 1] << "s to remove";
			Main();
		}
		else
		{
			gram[no - 1] -= grams;
			updatefile();
			Main();
		}

	}
};

class Meat_SeaFoods :public Stock {
	//chicken	fish	prawns	sausages
public:
	Meat_SeaFoods()
	{
		ifstream MeSe("MS.txt");
		for (int i = 0; i < 4; i++)
		{
			MeSe >> name[i] >> gram[i] >> retailPrice[i] >> discount[i] >> totalPrice[i] >> local_imported[i];

		}
	}
	void Main()
	{
		system("CLS");
		int n;
		cout << "1. Display items\n2. Add items\n3. Remove items\n4. Back\n";
		cin >> n;
		switch (n)
		{
		case 1:
			displayItems();
			break;
		case 2:
			addItems();
			break;
		case 3:
			removeItems();
			break;
		case 4:
			stock();
			break;
		}
	}
	void updatefile()
	{
		ofstream MS("MS.txt");
		for (int i = 0; i < 4; i++)
		{
			MS << name[i] << " " << gram[i] << " " << retailPrice[i] << " " << discount[i] << " " << totalPrice[i] << " " << local_imported[i] << endl;

		}
	}
	void displayItems()
	{
		system("CLS");

		for (int i = 0; i < 4; i++)
		{
			cout << i + 1 << "\t" << name[i] << "\t" << gram[i] << "\t" << retailPrice[i] << "\t" << discount[i] << " \t" << totalPrice[i] << "\t" << local_imported[i] << endl;

		}
		cout << endl;
		char let;
		cout << "Do you need to continue : ";
		cin >> let;
		if (let == 'y')
			Main();
	}
	void addItems()
	{
		system("CLS");
		cout << "No\tName\tWeight\tRet.Price\tDiscount\tFinal Price" << endl;
		for (int i = 0; i < 4; i++)
		{
			cout << i + 1 << "\t" << name[i] << "\t" << gram[i] << "g\tRs." << retailPrice[i] << "\t\t" << discount[i] << "%\tRs." << totalPrice[i] << "\t";
			if (local_imported[i] == 'l')
				cout << "Local\n";
			else
				cout << "Imported\n";
		}
		cout << endl << endl;
		int no, grams;
		char li;
		cout << "What do you need to add  " << endl;
		cout << "Select number of item from above list : ";

		cin >> no;
		cout << "How many grams of " << name[no - 1] << "s you need to add : ";
		cin >> grams;

		gram[no - 1] += grams;
		updatefile();
		Main();

	}
	void removeItems()
	{
		system("CLS");
		for (int i = 0; i < 4; i++)
		{
			cout << i + 1 << "\t" << name[i] << "\t" << gram[i] << "g\tRs." << retailPrice[i] << "\tRs." << totalPrice[i] << "\t";
			if (local_imported[i] == 'l')
				cout << "Local\n";
			else
				cout << "Imported\n";
		}
		cout << endl << endl;


		int no, grams;
		cout << "What do you need to remove  " << endl;
		cout << "Select number of item : ";
		cin >> no;
		cout << "How many grams of " << name[no - 1] << "s you need to remove : ";
		cin >> grams;

		if (gram[no - 1] < grams)
		{
			cout << "Sorry there is no enough " << name[no - 1] << "s to remove";
			Main();
		}
		else
		{
			gram[no - 1] -= grams;
			updatefile();
			Main();
		}

	}
};
class Meat_SeaFoods_FW :public Stock_FW {
	//chicken	fish	prawns	sausages
public:
	Meat_SeaFoods_FW()
	{
		ifstream MeSe("MS.txt");
		for (int i = 0; i < 4; i++)
		{
			MeSe >> name[i] >> gram[i] >> retailPrice[i] >> discount[i] >> totalPrice[i] >> local_imported[i];

		}
	}
	void Main()
	{
		system("CLS");
		int n;
		cout << "1. Display items\n2. Add items\n3. Back\n";
		cin >> n;
		switch (n)
		{
		case 1:
			displayItems();
			break;
		case 2:
			addItems();
			break;
		case 3:
			stock_FW();
			break;
		}
	}
	void updatefile()
	{
		ofstream MS("MS.txt");
		for (int i = 0; i < 4; i++)
		{
			MS << name[i] << " " << gram[i] << " " << retailPrice[i] << " " << discount[i] << " " << totalPrice[i] << " " << local_imported[i] << endl;

		}
	}
	void displayItems()
	{
		system("CLS");

		for (int i = 0; i < 4; i++)
		{
			cout << i + 1 << "\t" << name[i] << "\t" << gram[i] << "\t" << retailPrice[i] << "\t" << discount[i] << " \t" << totalPrice[i] << "\t" << local_imported[i] << endl;

		}
		cout << endl;
		char let;
		cout << "Do you need to continue : ";
		cin >> let;
		if (let == 'y')
			Main();
	}
	void addItems()
	{
		system("CLS");
		cout << "No\tName\tWeight\tRet.Price\tDiscount\tFinal Price" << endl;
		for (int i = 0; i < 4; i++)
		{
			cout << i + 1 << "\t" << name[i] << "\t" << gram[i] << "g\tRs." << retailPrice[i] << "\t\t" << discount[i] << "%\tRs." << totalPrice[i] << "\t";
			if (local_imported[i] == 'l')
				cout << "Local\n";
			else
				cout << "Imported\n";
		}
		cout << endl << endl;
		int no, grams;
		char li;
		cout << "What do you need to add  " << endl;
		cout << "Select number of item from above list : ";

		cin >> no;
		cout << "How many grams of " << name[no - 1] << "s you need to add : ";
		cin >> grams;

		gram[no - 1] += grams;
		updatefile();
		Main();

	}
	
};
class Meat_SeaFoods_CS :public Stock_CS {
	//chicken	fish	prawns	sausages
public:
	Meat_SeaFoods_CS()
	{
		ifstream MeSe("MS.txt");
		for (int i = 0; i < 4; i++)
		{
			MeSe >> name[i] >> gram[i] >> retailPrice[i] >> discount[i] >> totalPrice[i] >> local_imported[i];

		}
	}
	void Main()
	{
		system("CLS");
		int n;
		cout << "1. Display items\n2. Remove items\n3. Back\n";
		cin >> n;
		switch (n)
		{
		case 1:
			displayItems();
			break;
		case 2:
			removeItems();
			break;
		case 3:
			stock();
			break;
		}
	}
	void updatefile()
	{
		ofstream MS("MS.txt");
		for (int i = 0; i < 4; i++)
		{
			MS << name[i] << " " << gram[i] << " " << retailPrice[i] << " " << discount[i] << " " << totalPrice[i] << " " << local_imported[i] << endl;

		}
	}
	void displayItems()
	{
		system("CLS");

		for (int i = 0; i < 4; i++)
		{
			cout << i + 1 << "\t" << name[i] << "\t" << gram[i] << "\t" << retailPrice[i] << "\t" << discount[i] << " \t" << totalPrice[i] << "\t" << local_imported[i] << endl;

		}
		cout << endl;
		char let;
		cout << "Do you need to continue : ";
		cin >> let;
		if (let == 'y')
			Main();
	}
	void removeItems()
	{
		system("CLS");
		for (int i = 0; i < 4; i++)
		{
			cout << i + 1 << "\t" << name[i] << "\t" << gram[i] << "g\tRs." << retailPrice[i] << "\tRs." << totalPrice[i] << "\t";
			if (local_imported[i] == 'l')
				cout << "Local\n";
			else
				cout << "Imported\n";
		}
		cout << endl << endl;


		int no, grams;
		cout << "What do you need to remove  " << endl;
		cout << "Select number of item : ";
		cin >> no;
		cout << "How many grams of " << name[no - 1] << "s you need to remove : ";
		cin >> grams;

		if (gram[no - 1] < grams)
		{
			cout << "Sorry there is no enough " << name[no - 1] << "s to remove";
			Main();
		}
		else
		{
			gram[no - 1] -= grams;
			updatefile();
			Main();
		}

	}
};

class Grains :public Stock {
	//rice	dhal	oats	greengram
	//Nipun	jasmine	ramba	ppp	diamond	kellogg's	ramba	john's
public:
	Grains()
	{
		ifstream Grain("GR.txt");
		for (int i = 0; i < 8; i++)
		{
			Grain >> names[i] >> gramItem[i] >> retailprice[i] >> discounts[i] >> totalprice[i] >> localImported[i];

		}

	}
	void Main()
	{
		system("CLS");
		int n;
		cout << "1. Display items\n2. Add items\n3. Remove items\n4. Back\n";
		cin >> n;
		switch (n)
		{
		case 1:
			displayItems();
			break;
		case 2:
			addItems();
			break;
		case 3:
			removeItems();
			break;
		case 4:
			stock();
			break;
		}
	}
	void updatefile()
	{
		ofstream GR("GR.txt");
		for (int i = 0; i < 8; i++)
		{
			GR << names[i] << " " << gramItem[i] << " " << retailprice[i] << " " << discounts[i] << " " << totalprice[i] << " " << localImported[i] << endl;

		}
	}
	void displayItems()
	{
		system("CLS");
		cout << "No\tName\tBrand\tWeight\tRet.Price\tDiscount\tFinal Price" << endl;
		for (int i = 0; i < 8; i++)
		{
			cout << i + 1 << "\t" << names[i] <<"\t"<< brandItem[i]<<"\t" << gramItem[i] << "\t" << retailprice[i] << "\t\t" << discounts[i] << " \t" << totalprice[i] << "\t" << localImported[i] << endl;

		}
		cout << endl;
		char let;
		cout << "Do you need to continue : ";
		cin >> let;
		if (let == 'y')
			Main();
	}
	void addItems()
	{
		system("CLS");
		cout << "No\tName\tBrand\tWeight\tRet.Price\tDiscount\tFinal Price" << endl;
		for (int i = 0; i < 8; i++)
		{
			cout << i + 1 << "\t" << names[i]<<"\t" << brandItem[i] << "\t" << gramItem[i] << "\t" << retailprice[i] << "\t\t" << discounts[i] << " \t" << totalprice[i] << "\t" << localImported[i] << endl;

		}
		cout << endl;
		cout << endl << endl;
		int no, grams;
		char li;
		cout << "What do you need to add  " << endl;
		cout << "Select number of item from above list : ";

		cin >> no;
		cout << "How many grams of " << name[no - 1] << "s you need to add : ";
		cin >> grams;

		gram[no - 1] += grams;
		updatefile();
		Main();

	}
	void removeItems()
	{
		system("CLS");
		cout << "No\tName\tBrand\tWeight\tRet.Price\tDiscount\tFinal Price" << endl;
		for (int i = 0; i < 8; i++)
		{
			cout << i + 1 << "\t" << names[i] << brandItem[i] << "\t" << gramItem[i] << "\t" << retailprice[i] << "\t\t" << discounts[i] << " \t" << totalprice[i] << "\t" << localImported[i] << endl;

		}
		cout << endl;
		cout << endl;


		int no, grams;
		cout << "What do you need to remove  " << endl;
		cout << "Select number of item : ";
		cin >> no;
		cout << "How many grams of " << name[no - 1] << "s you need to remove : ";
		cin >> grams;

		if (gram[no - 1] < grams)
		{
			cout << "Sorry there is no enough " << name[no - 1] << "s to remove";
			Main();
		}
		else
		{
			gram[no - 1] -= grams;
			updatefile();
			Main();
		}

	}
};
class Grains_FW :public Stock_FW {
	//rice	dhal	oats	greengram
	//Nipun	jasmine	ramba	ppp	diamond	kellogg's	ramba	john's
public:
	Grains_FW()
	{
		ifstream Grain("GR.txt");
		for (int i = 0; i < 8; i++)
		{
			Grain >> names[i] >> gramItem[i] >> retailprice[i] >> discounts[i] >> totalprice[i] >> localImported[i];

		}

	}
	void Main()
	{
		system("CLS");
		int n;
		cout << "1. Display items\n2. Add items\n3. Back\n";
		cin >> n;
		switch (n)
		{
		case 1:
			displayItems();
			break;
		case 2:
			addItems();
			break;
		case 3:
			stock();
			break;
		}
	}
	void updatefile()
	{
		ofstream GR("GR.txt");
		for (int i = 0; i < 8; i++)
		{
			GR << names[i] << " " << gramItem[i] << " " << retailprice[i] << " " << discounts[i] << " " << totalprice[i] << " " << localImported[i] << endl;

		}
	}
	void displayItems()
	{
		system("CLS");
		cout << "No\tName\tBrand\tWeight\tRet.Price\tDiscount\tFinal Price" << endl;
		for (int i = 0; i < 8; i++)
		{
			cout << i + 1 << "\t" << names[i] << "\t" << brandItem[i] << "\t" << gramItem[i] << "\t" << retailprice[i] << "\t\t" << discounts[i] << " \t" << totalprice[i] << "\t" << localImported[i] << endl;

		}
		cout << endl;
		char let;
		cout << "Do you need to continue : ";
		cin >> let;
		if (let == 'y')
			Main();
	}
	void addItems()
	{
		system("CLS");
		cout << "No\tName\tBrand\tWeight\tRet.Price\tDiscount\tFinal Price" << endl;
		for (int i = 0; i < 8; i++)
		{
			cout << i + 1 << "\t" << names[i] << "\t" << brandItem[i] << "\t" << gramItem[i] << "\t" << retailprice[i] << "\t\t" << discounts[i] << " \t" << totalprice[i] << "\t" << localImported[i] << endl;

		}
		cout << endl;
		cout << endl << endl;
		int no, grams;
		char li;
		cout << "What do you need to add  " << endl;
		cout << "Select number of item from above list : ";

		cin >> no;
		cout << "How many grams of " << name[no - 1] << "s you need to add : ";
		cin >> grams;

		gram[no - 1] += grams;
		updatefile();
		Main();

	}
	
};
class Grains_CS :public Stock_CS {
	//rice	dhal	oats	greengram
	//Nipun	jasmine	ramba	ppp	diamond	kellogg's	ramba	john's
public:
	Grains_CS()
	{
		ifstream Grain("GR.txt");
		for (int i = 0; i < 8; i++)
		{
			Grain >> names[i] >> gramItem[i] >> retailprice[i] >> discounts[i] >> totalprice[i] >> localImported[i];

		}

	}
	void Main()
	{
		system("CLS");
		int n;
		cout << "1. Display items\n2. Remove items\n3. Back\n";
		cin >> n;
		switch (n)
		{
		case 1:
			displayItems();
			break;
		case 2:
			removeItems();
			break;
		case 3:
			stock();
			break;
		}
	}
	void updatefile()
	{
		ofstream GR("GR.txt");
		for (int i = 0; i < 8; i++)
		{
			GR << names[i] << " " << gramItem[i] << " " << retailprice[i] << " " << discounts[i] << " " << totalprice[i] << " " << localImported[i] << endl;

		}
	}
	void displayItems()
	{
		system("CLS");
		cout << "No\tName\tBrand\tWeight\tRet.Price\tDiscount\tFinal Price" << endl;
		for (int i = 0; i < 8; i++)
		{
			cout << i + 1 << "\t" << names[i] << "\t" << brandItem[i] << "\t" << gramItem[i] << "\t" << retailprice[i] << "\t\t" << discounts[i] << " \t" << totalprice[i] << "\t" << localImported[i] << endl;

		}
		cout << endl;
		char let;
		cout << "Do you need to continue : ";
		cin >> let;
		if (let == 'y')
			Main();
	}
	void removeItems()
	{
		system("CLS");
		cout << "No\tName\tBrand\tWeight\tRet.Price\tDiscount\tFinal Price" << endl;
		for (int i = 0; i < 8; i++)
		{
			cout << i + 1 << "\t" << names[i] << brandItem[i] << "\t" << gramItem[i] << "\t" << retailprice[i] << "\t\t" << discounts[i] << " \t" << totalprice[i] << "\t" << localImported[i] << endl;

		}
		cout << endl;
		cout << endl;


		int no, grams;
		cout << "What do you need to remove  " << endl;
		cout << "Select number of item : ";
		cin >> no;
		cout << "How many grams of " << name[no - 1] << "s you need to remove : ";
		cin >> grams;

		if (gram[no - 1] < grams)
		{
			cout << "Sorry there is no enough " << name[no - 1] << "s to remove";
			Main();
		}
		else
		{
			gram[no - 1] -= grams;
			updatefile();
			Main();
		}

	}
};

class Bakery :public Stock {
	//bun	biscuits	cake	bread
public:
	Bakery()
	{
		ifstream Bak("BI.txt");
		for (int i = 0; i < 8; i++)
		{
			Bak >> names[i] >> gramItem[i] >> retailprice[i] >> discounts[i] >> totalprice[i] >> localImported[i];

		}

	}
	void Main()
	{
		system("CLS");
		int n;
		cout << "1. Display items\n2. Add items\n3. Remove items\n4. Back\n";
		cin >> n;
		switch (n)
		{
		case 1:
			displayItems();
			break;
		case 2:
			addItems();
			break;
		case 3:
			removeItems();
			break;
		case 4:
			stock();
			break;
		}
	}
	void updatefile()
	{
		ofstream BI("BI.txt");
		for (int i = 0; i < 8; i++)
		{
			BI << names[i] << " " << gramItem[i] << " " << retailprice[i] << " " << discounts[i] << " " << totalprice[i] << " " << localImported[i] << endl;

		}
	}
	void displayItems()
	{
		system("CLS");
		cout << "No\tName\tBrand\tWeight\tRet.Price\tDiscount\tFinal Price" << endl;
		for (int i = 0; i < 8; i++)
		{
			cout << i + 1 << "\t" << names[i] << "\t" << brandItem[i] << "\t" << gramItem[i] << "\t" << retailprice[i] << "\t\t" << discounts[i] << " \t" << totalprice[i] << "\t" << localImported[i] << endl;

		}
		cout << endl;
		char let;
		cout << "Do you need to continue : ";
		cin >> let;
		if (let == 'y')
			Main();
	}
	void addItems()
	{
		system("CLS");
		cout << "No\tName\tBrand\tWeight\tRet.Price\tDiscount\tFinal Price" << endl;
		for (int i = 0; i < 8; i++)
		{
			cout << i + 1 << "\t" << names[i] << "\t" << brandItem[i] << "\t" << gramItem[i] << "\t" << retailprice[i] << "\t\t" << discounts[i] << " \t" << totalprice[i] << "\t" << localImported[i] << endl;

		}
		cout << endl;
		cout << endl << endl;
		int no, grams;
		char li;
		cout << "What do you need to add  " << endl;
		cout << "Select number of item from above list : ";

		cin >> no;
		cout << "How many grams of " << name[no - 1] << "s you need to add : ";
		cin >> grams;

		gram[no - 1] += grams;
		updatefile();
		Main();

	}
	void removeItems()
	{
		system("CLS");
		cout << "No\tName\tBrand\tWeight\tRet.Price\tDiscount\tFinal Price" << endl;
		for (int i = 0; i < 8; i++)
		{
			cout << i + 1 << "\t" << names[i] << brandItem[i] << "\t" << gramItem[i] << "\t" << retailprice[i] << "\t\t" << discounts[i] << " \t" << totalprice[i] << "\t" << localImported[i] << endl;

		}
		cout << endl;
		cout << endl;


		int no, grams;
		cout << "What do you need to remove  " << endl;
		cout << "Select number of item : ";
		cin >> no;
		cout << "How many grams of " << name[no - 1] << "s you need to remove : ";
		cin >> grams;

		if (gram[no - 1] < grams)
		{
			cout << "Sorry there is no enough " << name[no - 1] << "s to remove";
			Main();
		}
		else
		{
			gram[no - 1] -= grams;
			updatefile();
			Main();
		}

	}
};
class Bakery_FW :public Stock_FW {
	//bun	biscuits	cake	bread
public:
	Bakery_FW()
	{
		ifstream Bak("BI.txt");
		for (int i = 0; i < 8; i++)
		{
			Bak >> names[i] >> gramItem[i] >> retailprice[i] >> discounts[i] >> totalprice[i] >> localImported[i];

		}

	}
	void Main()
	{
		system("CLS");
		int n;
		cout << "1. Display items\n2. Add items\n3. Back\n";
		cin >> n;
		switch (n)
		{
		case 1:
			displayItems();
			break;
		case 2:
			addItems();
			break;
		case 3:
			stock();
			break;
		}
	}
	void updatefile()
	{
		ofstream BI("BI.txt");
		for (int i = 0; i < 8; i++)
		{
			BI << names[i] << " " << gramItem[i] << " " << retailprice[i] << " " << discounts[i] << " " << totalprice[i] << " " << localImported[i] << endl;

		}
	}
	void displayItems()
	{
		system("CLS");
		cout << "No\tName\tBrand\tWeight\tRet.Price\tDiscount\tFinal Price" << endl;
		for (int i = 0; i < 8; i++)
		{
			cout << i + 1 << "\t" << names[i] << "\t" << brandItem[i] << "\t" << gramItem[i] << "\t" << retailprice[i] << "\t\t" << discounts[i] << " \t" << totalprice[i] << "\t" << localImported[i] << endl;

		}
		cout << endl;
		char let;
		cout << "Do you need to continue : ";
		cin >> let;
		if (let == 'y')
			Main();
	}
	void addItems()
	{
		system("CLS");
		cout << "No\tName\tBrand\tWeight\tRet.Price\tDiscount\tFinal Price" << endl;
		for (int i = 0; i < 8; i++)
		{
			cout << i + 1 << "\t" << names[i] << "\t" << brandItem[i] << "\t" << gramItem[i] << "\t" << retailprice[i] << "\t\t" << discounts[i] << " \t" << totalprice[i] << "\t" << localImported[i] << endl;

		}
		cout << endl;
		cout << endl << endl;
		int no, grams;
		char li;
		cout << "What do you need to add  " << endl;
		cout << "Select number of item from above list : ";

		cin >> no;
		cout << "How many grams of " << name[no - 1] << "s you need to add : ";
		cin >> grams;

		gram[no - 1] += grams;
		updatefile();
		Main();

	}
	
};
class Bakery_CS :public Stock_CS {
	//bun	biscuits	cake	bread
public:
	Bakery_CS()
	{
		ifstream Bak("BI.txt");
		for (int i = 0; i < 8; i++)
		{
			Bak >> names[i] >> gramItem[i] >> retailprice[i] >> discounts[i] >> totalprice[i] >> localImported[i];

		}

	}
	void Main()
	{
		system("CLS");
		int n;
		cout << "1. Display items\n2. Remove items\n3. Back\n";
		cin >> n;
		switch (n)
		{
		case 1:
			displayItems();
			break;
		case 2:
			removeItems();
			break;
		case 4:
			stock();
			break;
		}
	}
	void updatefile()
	{
		ofstream BI("BI.txt");
		for (int i = 0; i < 8; i++)
		{
			BI << names[i] << " " << gramItem[i] << " " << retailprice[i] << " " << discounts[i] << " " << totalprice[i] << " " << localImported[i] << endl;

		}
	}
	void displayItems()
	{
		system("CLS");
		cout << "No\tName\tBrand\tWeight\tRet.Price\tDiscount\tFinal Price" << endl;
		for (int i = 0; i < 8; i++)
		{
			cout << i + 1 << "\t" << names[i] << "\t" << brandItem[i] << "\t" << gramItem[i] << "\t" << retailprice[i] << "\t\t" << discounts[i] << " \t" << totalprice[i] << "\t" << localImported[i] << endl;

		}
		cout << endl;
		char let;
		cout << "Do you need to continue : ";
		cin >> let;
		if (let == 'y')
			Main();
	}
void removeItems()
	{
		system("CLS");
		cout << "No\tName\tBrand\tWeight\tRet.Price\tDiscount\tFinal Price" << endl;
		for (int i = 0; i < 8; i++)
		{
			cout << i + 1 << "\t" << names[i] << brandItem[i] << "\t" << gramItem[i] << "\t" << retailprice[i] << "\t\t" << discounts[i] << " \t" << totalprice[i] << "\t" << localImported[i] << endl;

		}
		cout << endl;
		cout << endl;


		int no, grams;
		cout << "What do you need to remove  " << endl;
		cout << "Select number of item : ";
		cin >> no;
		cout << "How many grams of " << name[no - 1] << "s you need to remove : ";
		cin >> grams;

		if (gram[no - 1] < grams)
		{
			cout << "Sorry there is no enough " << name[no - 1] << "s to remove";
			Main();
		}
		else
		{
			gram[no - 1] -= grams;
			updatefile();
			Main();
		}

	}
};

class FrozenFoods :public Stock {
		//frozenpizza	frozenstringhoppers	frozensweetcorn	frozenchicken
	public:
		FrozenFoods()
		{
			ifstream Fro("FF.txt");
			for (int i = 0; i < 8; i++)
			{
				Fro >> names[i] >> gramItem[i] >> retailprice[i] >> discounts[i] >> totalprice[i] >> localImported[i];

			}
		}
		void Main()
		{
			system("CLS");
			int n;
			cout << "1. Display items\n2. Add items\n3. Remove items\n4. Back\n";
			cin >> n;
			switch (n)
			{
			case 1:
				displayItems();
				break;
			case 2:
				addItems();
				break;
			case 3:
				removeItems();
				break;
			case 4:
				stock();
				break;
			}
		}
		void updatefile()
		{
			ofstream FF("FF.txt");
			for (int i = 0; i < 8; i++)
			{
				FF << names[i] << " " << gramItem[i] << " " << retailprice[i] << " " << discounts[i] << " " << totalprice[i] << " " << localImported[i] << endl;

			}
		}
		void displayItems()
		{
			system("CLS");
			cout << "No\tName\tBrand\tWeight\tRet.Price\tDiscount\tFinal Price" << endl;
			for (int i = 0; i < 8; i++)
			{
				cout << i + 1 << "\t" << names[i] << "\t" << brandItem[i] << "\t" << gramItem[i] << "\t" << retailprice[i] << "\t\t" << discounts[i] << " \t" << totalprice[i] << "\t" << localImported[i] << endl;

			}
			cout << endl;
			char let;
			cout << "Do you need to continue : ";
			cin >> let;
			if (let == 'y')
				Main();
		}
		void addItems()
		{
			system("CLS");
			cout << "No\tName\tBrand\tWeight\tRet.Price\tDiscount\tFinal Price" << endl;
			for (int i = 0; i < 8; i++)
			{
				cout << i + 1 << "\t" << names[i] << "\t" << brandItem[i] << "\t" << gramItem[i] << "\t" << retailprice[i] << "\t\t" << discounts[i] << " \t" << totalprice[i] << "\t" << localImported[i] << endl;

			}
			cout << endl;
			cout << endl << endl;
			int no, grams;
			char li;
			cout << "What do you need to add  " << endl;
			cout << "Select number of item from above list : ";

			cin >> no;
			cout << "How many grams of " << name[no - 1] << "s you need to add : ";
			cin >> grams;

			gram[no - 1] += grams;
			updatefile();
			Main();

		}
		void removeItems()
		{
			system("CLS");
			cout << "No\tName\tBrand\tWeight\tRet.Price\tDiscount\tFinal Price" << endl;
			for (int i = 0; i < 8; i++)
			{
				cout << i + 1 << "\t" << names[i] << brandItem[i] << "\t" << gramItem[i] << "\t" << retailprice[i] << "\t\t" << discounts[i] << " \t" << totalprice[i] << "\t" << localImported[i] << endl;

			}
			cout << endl;
			cout << endl;


			int no, grams;
			cout << "What do you need to remove  " << endl;
			cout << "Select number of item : ";
			cin >> no;
			cout << "How many grams of " << name[no - 1] << "s you need to remove : ";
			cin >> grams;

			if (gram[no - 1] < grams)
			{
				cout << "Sorry there is no enough " << name[no - 1] << "s to remove";
				Main();
			}
			else
			{
				gram[no - 1] -= grams;
				updatefile();
				Main();
			}

		}
	};
class FrozenFoods_FW :public Stock_FW {
		//frozenpizza	frozenstringhoppers	frozensweetcorn	frozenchicken
	public:
		FrozenFoods_FW()
		{
			ifstream Fro("FF.txt");
			for (int i = 0; i < 8; i++)
			{
				Fro >> names[i] >> gramItem[i] >> retailprice[i] >> discounts[i] >> totalprice[i] >> localImported[i];

			}
		}
		void Main()
		{
			system("CLS");
			int n;
			cout << "1. Display items\n2. Add items\n3. Back\n";
			cin >> n;
			switch (n)
			{
			case 1:
				displayItems();
				break;
			case 2:
				addItems();
				break;
			case 3:
				stock();
				break;
			}
		}
		void updatefile()
		{
			ofstream FF("FF.txt");
			for (int i = 0; i < 8; i++)
			{
				FF << names[i] << " " << gramItem[i] << " " << retailprice[i] << " " << discounts[i] << " " << totalprice[i] << " " << localImported[i] << endl;

			}
		}
		void displayItems()
		{
			system("CLS");
			cout << "No\tName\tBrand\tWeight\tRet.Price\tDiscount\tFinal Price" << endl;
			for (int i = 0; i < 8; i++)
			{
				cout << i + 1 << "\t" << names[i] << "\t" << brandItem[i] << "\t" << gramItem[i] << "\t" << retailprice[i] << "\t\t" << discounts[i] << " \t" << totalprice[i] << "\t" << localImported[i] << endl;

			}
			cout << endl;
			char let;
			cout << "Do you need to continue : ";
			cin >> let;
			if (let == 'y')
				Main();
		}
		void addItems()
		{
			system("CLS");
			cout << "No\tName\tBrand\tWeight\tRet.Price\tDiscount\tFinal Price" << endl;
			for (int i = 0; i < 8; i++)
			{
				cout << i + 1 << "\t" << names[i] << "\t" << brandItem[i] << "\t" << gramItem[i] << "\t" << retailprice[i] << "\t\t" << discounts[i] << " \t" << totalprice[i] << "\t" << localImported[i] << endl;

			}
			cout << endl;
			cout << endl << endl;
			int no, grams;
			char li;
			cout << "What do you need to add  " << endl;
			cout << "Select number of item from above list : ";

			cin >> no;
			cout << "How many grams of " << name[no - 1] << "s you need to add : ";
			cin >> grams;

			gram[no - 1] += grams;
			updatefile();
			Main();

		}
		
	};
class FrozenFoods_CS :public Stock_CS {
	//frozenpizza	frozenstringhoppers	frozensweetcorn	frozenchicken
public:
	FrozenFoods_CS()
	{
		ifstream Fro("FF.txt");
		for (int i = 0; i < 8; i++)
		{
			Fro >> names[i] >> gramItem[i] >> retailprice[i] >> discounts[i] >> totalprice[i] >> localImported[i];

		}
	}
	void Main()
	{
		system("CLS");
		int n;
		cout << "1. Display items\n2. Remove items\n3. Back\n";
		cin >> n;
		switch (n)
		{
		case 1:
			displayItems();
			break;
		case 2:
			removeItems();
			break;
		case 3:
			stock();
			break;
		}
	}
	void updatefile()
	{
		ofstream FF("FF.txt");
		for (int i = 0; i < 8; i++)
		{
			FF << names[i] << " " << gramItem[i] << " " << retailprice[i] << " " << discounts[i] << " " << totalprice[i] << " " << localImported[i] << endl;

		}
	}
	void displayItems()
	{
		system("CLS");
		cout << "No\tName\tBrand\tWeight\tRet.Price\tDiscount\tFinal Price" << endl;
		for (int i = 0; i < 8; i++)
		{
			cout << i + 1 << "\t" << names[i] << "\t" << brandItem[i] << "\t" << gramItem[i] << "\t" << retailprice[i] << "\t\t" << discounts[i] << " \t" << totalprice[i] << "\t" << localImported[i] << endl;

		}
		cout << endl;
		char let;
		cout << "Do you need to continue : ";
		cin >> let;
		if (let == 'y')
			Main();
	}
	void removeItems()
	{
		system("CLS");
		cout << "No\tName\tBrand\tWeight\tRet.Price\tDiscount\tFinal Price" << endl;
		for (int i = 0; i < 8; i++)
		{
			cout << i + 1 << "\t" << names[i] << brandItem[i] << "\t" << gramItem[i] << "\t" << retailprice[i] << "\t\t" << discounts[i] << " \t" << totalprice[i] << "\t" << localImported[i] << endl;

		}
		cout << endl;
		cout << endl;


		int no, grams;
		cout << "What do you need to remove  " << endl;
		cout << "Select number of item : ";
		cin >> no;
		cout << "How many grams of " << name[no - 1] << "s you need to remove : ";
		cin >> grams;

		if (gram[no - 1] < grams)
		{
			cout << "Sorry there is no enough " << name[no - 1] << "s to remove";
			Main();
		}
		else
		{
			gram[no - 1] -= grams;
			updatefile();
			Main();
		}

	}
};

class Dairy :public Stock {
		//milk	icecream	cheese	butter
	public:
		Dairy()
		{
			ifstream Da("DA.txt");
			for (int i = 0; i < 8; i++)
			{
				Da >> names[i] >> gramItem[i] >> retailprice[i] >> discounts[i] >> totalprice[i] >> localImported[i];

			}

		}
		void Main()
		{
			system("CLS");
			int n;
			cout << "1. Display items\n2. Add items\n3. Remove items\n4. Back\n";
			cin >> n;
			switch (n)
			{
			case 1:
				displayItems();
				break;
			case 2:
				addItems();
				break;
			case 3:
				removeItems();
				break;
			case 4:
				stock();
				break;
			}
		}
		void updatefile()
		{
			ofstream DA("DA.txt");
			for (int i = 0; i < 8; i++)
			{
				DA << names[i] << " " << gramItem[i] << " " << retailprice[i] << " " << discounts[i] << " " << totalprice[i] << " " << localImported[i] << endl;

			}
		}
		void displayItems()
		{
			system("CLS");
			cout << "No\tName\tBrand\tWeight\tRet.Price\tDiscount\tFinal Price" << endl;
			for (int i = 0; i < 8; i++)
			{
				cout << i + 1 << "\t" << names[i] << "\t" << brandItem[i] << "\t" << gramItem[i] << "\t" << retailprice[i] << "\t\t" << discounts[i] << " \t" << totalprice[i] << "\t" << localImported[i] << endl;

			}
			cout << endl;
			char let;
			cout << "Do you need to continue : ";
			cin >> let;
			if (let == 'y')
				Main();
		}
		void addItems()
		{
			system("CLS");
			cout << "No\tName\tBrand\tWeight\tRet.Price\tDiscount\tFinal Price" << endl;
			for (int i = 0; i < 8; i++)
			{
				cout << i + 1 << "\t" << names[i] << "\t" << brandItem[i] << "\t" << gramItem[i] << "\t" << retailprice[i] << "\t\t" << discounts[i] << " \t" << totalprice[i] << "\t" << localImported[i] << endl;

			}
			cout << endl;
			cout << endl << endl;
			int no, grams;
			char li;
			cout << "What do you need to add  " << endl;
			cout << "Select number of item from above list : ";

			cin >> no;
			cout << "How many grams of " << name[no - 1] << "s you need to add : ";
			cin >> grams;

			gram[no - 1] += grams;
			updatefile();
			Main();

		}
		void removeItems()
		{
			system("CLS");
			cout << "No\tName\tBrand\tWeight\tRet.Price\tDiscount\tFinal Price" << endl;
			for (int i = 0; i < 8; i++)
			{
				cout << i + 1 << "\t" << names[i] << brandItem[i] << "\t" << gramItem[i] << "\t" << retailprice[i] << "\t\t" << discounts[i] << " \t" << totalprice[i] << "\t" << localImported[i] << endl;

			}
			cout << endl;
			cout << endl;


			int no, grams;
			cout << "What do you need to remove  " << endl;
			cout << "Select number of item : ";
			cin >> no;
			cout << "How many grams of " << name[no - 1] << "s you need to remove : ";
			cin >> grams;

			if (gram[no - 1] < grams)
			{
				cout << "Sorry there is no enough " << name[no - 1] << "s to remove";
				Main();
			}
			else
			{
				gram[no - 1] -= grams;
				updatefile();
				Main();
			}

		}
	};
class Dairy_FW :public Stock_FW {
		//milk	icecream	cheese	butter
	public:
		Dairy_FW()
		{
			ifstream Da("DA.txt");
			for (int i = 0; i < 8; i++)
			{
				Da >> names[i] >> gramItem[i] >> retailprice[i] >> discounts[i] >> totalprice[i] >> localImported[i];

			}

		}
		void Main()
		{
			system("CLS");
			int n;
			cout << "1. Display items\n2. Add items\n3. Back\n";
			cin >> n;
			switch (n)
			{
			case 1:
				displayItems();
				break;
			case 2:
				addItems();
				break;
			case 3:
				stock();
				break;
			}
		}
		void updatefile()
		{
			ofstream DA("DA.txt");
			for (int i = 0; i < 8; i++)
			{
				DA << names[i] << " " << gramItem[i] << " " << retailprice[i] << " " << discounts[i] << " " << totalprice[i] << " " << localImported[i] << endl;

			}
		}
		void displayItems()
		{
			system("CLS");
			cout << "No\tName\tBrand\tWeight\tRet.Price\tDiscount\tFinal Price" << endl;
			for (int i = 0; i < 8; i++)
			{
				cout << i + 1 << "\t" << names[i] << "\t" << brandItem[i] << "\t" << gramItem[i] << "\t" << retailprice[i] << "\t\t" << discounts[i] << " \t" << totalprice[i] << "\t" << localImported[i] << endl;

			}
			cout << endl;
			char let;
			cout << "Do you need to continue : ";
			cin >> let;
			if (let == 'y')
				Main();
		}
		void addItems()
		{
			system("CLS");
			cout << "No\tName\tBrand\tWeight\tRet.Price\tDiscount\tFinal Price" << endl;
			for (int i = 0; i < 8; i++)
			{
				cout << i + 1 << "\t" << names[i] << "\t" << brandItem[i] << "\t" << gramItem[i] << "\t" << retailprice[i] << "\t\t" << discounts[i] << " \t" << totalprice[i] << "\t" << localImported[i] << endl;

			}
			cout << endl;
			cout << endl << endl;
			int no, grams;
			char li;
			cout << "What do you need to add  " << endl;
			cout << "Select number of item from above list : ";

			cin >> no;
			cout << "How many grams of " << name[no - 1] << "s you need to add : ";
			cin >> grams;

			gram[no - 1] += grams;
			updatefile();
			Main();

		}
	};
class Dairy_CS :public Stock_CS {
	//milk	icecream	cheese	butter
public:
	Dairy_CS()
	{
		ifstream Da("DA.txt");
		for (int i = 0; i < 8; i++)
		{
			Da >> names[i] >> gramItem[i] >> retailprice[i] >> discounts[i] >> totalprice[i] >> localImported[i];

		}

	}
	void Main()
	{
		system("CLS");
		int n;
		cout << "1. Display items\n2. Remove items\n3. Back\n";
		cin >> n;
		switch (n)
		{
		case 1:
			displayItems();
			break;
		case 2:
			removeItems();
			break;
		case 3:
			stock();
			break;
		}
	}
	void updatefile()
	{
		ofstream DA("DA.txt");
		for (int i = 0; i < 8; i++)
		{
			DA << names[i] << " " << gramItem[i] << " " << retailprice[i] << " " << discounts[i] << " " << totalprice[i] << " " << localImported[i] << endl;

		}
	}
	void displayItems()
	{
		system("CLS");
		cout << "No\tName\tBrand\tWeight\tRet.Price\tDiscount\tFinal Price" << endl;
		for (int i = 0; i < 8; i++)
		{
			cout << i + 1 << "\t" << names[i] << "\t" << brandItem[i] << "\t" << gramItem[i] << "\t" << retailprice[i] << "\t\t" << discounts[i] << " \t" << totalprice[i] << "\t" << localImported[i] << endl;

		}
		cout << endl;
		char let;
		cout << "Do you need to continue : ";
		cin >> let;
		if (let == 'y')
			Main();
	}
	void removeItems()
	{
		system("CLS");
		cout << "No\tName\tBrand\tWeight\tRet.Price\tDiscount\tFinal Price" << endl;
		for (int i = 0; i < 8; i++)
		{
			cout << i + 1 << "\t" << names[i] << brandItem[i] << "\t" << gramItem[i] << "\t" << retailprice[i] << "\t\t" << discounts[i] << " \t" << totalprice[i] << "\t" << localImported[i] << endl;

		}
		cout << endl;
		cout << endl;


		int no, grams;
		cout << "What do you need to remove  " << endl;
		cout << "Select number of item : ";
		cin >> no;
		cout << "How many grams of " << name[no - 1] << "s you need to remove : ";
		cin >> grams;

		if (gram[no - 1] < grams)
		{
			cout << "Sorry there is no enough " << name[no - 1] << "s to remove";
			Main();
		}
		else
		{
			gram[no - 1] -= grams;
			updatefile();
			Main();
		}

	}
};


class Snacks_sweets :public Stock {
		//savourybiscuits	chips	chocolates	jelly
	public:
		Snacks_sweets()
		{
			ifstream Sna("SS.txt");
			for (int i = 0; i < 8; i++)
			{
				Sna >> names[i] >> gramItem[i] >> retailprice[i] >> discounts[i] >> totalprice[i] >> localImported[i];

			}

		}
		void Main()
		{
			system("CLS");
			int n;
			cout << "1. Display items\n2. Add items\n3. Remove items\n4. Back\n";
			cin >> n;
			switch (n)
			{
			case 1:
				displayItems();
				break;
			case 2:
				addItems();
				break;
			case 3:
				removeItems();
				break;
			case 4:
				stock();
				break;
			}
		}
		void updatefile()
		{
			ofstream SS("SS.txt");
			for (int i = 0; i < 8; i++)
			{
				SS << names[i] << " " << gramItem[i] << " " << retailprice[i] << " " << discounts[i] << " " << totalprice[i] << " " << localImported[i] << endl;

			}
		}
		void displayItems()
		{
			system("CLS");
			cout << "No\tName\tBrand\tWeight\tRet.Price\tDiscount\tFinal Price" << endl;
			for (int i = 0; i < 8; i++)
			{
				cout << i + 1 << "\t" << names[i] << "\t" << brandItem[i] << "\t" << gramItem[i] << "\t" << retailprice[i] << "\t\t" << discounts[i] << " \t" << totalprice[i] << "\t" << localImported[i] << endl;

			}
			cout << endl;
			char let;
			cout << "Do you need to continue : ";
			cin >> let;
			if (let == 'y')
				Main();
		}
		void addItems()
		{
			system("CLS");
			cout << "No\tName\tBrand\tWeight\tRet.Price\tDiscount\tFinal Price" << endl;
			for (int i = 0; i < 8; i++)
			{
				cout << i + 1 << "\t" << names[i] << "\t" << brandItem[i] << "\t" << gramItem[i] << "\t" << retailprice[i] << "\t\t" << discounts[i] << " \t" << totalprice[i] << "\t" << localImported[i] << endl;

			}
			cout << endl;
			cout << endl << endl;
			int no, grams;
			char li;
			cout << "What do you need to add  " << endl;
			cout << "Select number of item from above list : ";

			cin >> no;
			cout << "How many grams of " << name[no - 1] << "s you need to add : ";
			cin >> grams;

			gram[no - 1] += grams;
			updatefile();
			Main();

		}
		void removeItems()
		{
			system("CLS");
			cout << "No\tName\tBrand\tWeight\tRet.Price\tDiscount\tFinal Price" << endl;
			for (int i = 0; i < 8; i++)
			{
				cout << i + 1 << "\t" << names[i] << brandItem[i] << "\t" << gramItem[i] << "\t" << retailprice[i] << "\t\t" << discounts[i] << " \t" << totalprice[i] << "\t" << localImported[i] << endl;

			}
			cout << endl;
			cout << endl;


			int no, grams;
			cout << "What do you need to remove  " << endl;
			cout << "Select number of item : ";
			cin >> no;
			cout << "How many grams of " << name[no - 1] << "s you need to remove : ";
			cin >> grams;

			if (gram[no - 1] < grams)
			{
				cout << "Sorry there is no enough " << name[no - 1] << "s to remove";
				Main();
			}
			else
			{
				gram[no - 1] -= grams;
				updatefile();
				Main();
			}

		}
	};
class Snacks_sweets_FW :public Stock_FW {
		//savourybiscuits	chips	chocolates	jelly
	public:
		Snacks_sweets_FW()
		{
			ifstream Sna("SS.txt");
			for (int i = 0; i < 8; i++)
			{
				Sna >> names[i] >> gramItem[i] >> retailprice[i] >> discounts[i] >> totalprice[i] >> localImported[i];

			}

		}
		void Main()
		{
			system("CLS");
			int n;
			cout << "1. Display items\n2. Add items\n3. Back\n";
			cin >> n;
			switch (n)
			{
			case 1:
				displayItems();
				break;
			case 2:
				addItems();
				break;
			case 3:
				stock();
				break;
			}
		}
		void updatefile()
		{
			ofstream SS("SS.txt");
			for (int i = 0; i < 8; i++)
			{
				SS << names[i] << " " << gramItem[i] << " " << retailprice[i] << " " << discounts[i] << " " << totalprice[i] << " " << localImported[i] << endl;

			}
		}
		void displayItems()
		{
			system("CLS");
			cout << "No\tName\tBrand\tWeight\tRet.Price\tDiscount\tFinal Price" << endl;
			for (int i = 0; i < 8; i++)
			{
				cout << i + 1 << "\t" << names[i] << "\t" << brandItem[i] << "\t" << gramItem[i] << "\t" << retailprice[i] << "\t\t" << discounts[i] << " \t" << totalprice[i] << "\t" << localImported[i] << endl;

			}
			cout << endl;
			char let;
			cout << "Do you need to continue : ";
			cin >> let;
			if (let == 'y')
				Main();
		}
		void addItems()
		{
			system("CLS");
			cout << "No\tName\tBrand\tWeight\tRet.Price\tDiscount\tFinal Price" << endl;
			for (int i = 0; i < 8; i++)
			{
				cout << i + 1 << "\t" << names[i] << "\t" << brandItem[i] << "\t" << gramItem[i] << "\t" << retailprice[i] << "\t\t" << discounts[i] << " \t" << totalprice[i] << "\t" << localImported[i] << endl;

			}
			cout << endl;
			cout << endl << endl;
			int no, grams;
			char li;
			cout << "What do you need to add  " << endl;
			cout << "Select number of item from above list : ";

			cin >> no;
			cout << "How many grams of " << name[no - 1] << "s you need to add : ";
			cin >> grams;

			gram[no - 1] += grams;
			updatefile();
			Main();

		}
		
	};
class Snacks_sweets_CS :public Stock_CS {
	//savourybiscuits	chips	chocolates	jelly
public:
	Snacks_sweets_CS()
	{
		ifstream Sna("SS.txt");
		for (int i = 0; i < 8; i++)
		{
			Sna >> names[i] >> gramItem[i] >> retailprice[i] >> discounts[i] >> totalprice[i] >> localImported[i];

		}

	}
	void Main()
	{
		system("CLS");
		int n;
		cout << "1. Display items\n2. Remove items\n3. Back\n";
		cin >> n;
		switch (n)
		{
		case 1:
			displayItems();
			break;
		case 2:
			removeItems();
			break;
		case 3:
			stock();
			break;
		}
	}
	void updatefile()
	{
		ofstream SS("SS.txt");
		for (int i = 0; i < 8; i++)
		{
			SS << names[i] << " " << gramItem[i] << " " << retailprice[i] << " " << discounts[i] << " " << totalprice[i] << " " << localImported[i] << endl;

		}
	}
	void displayItems()
	{
		system("CLS");
		cout << "No\tName\tBrand\tWeight\tRet.Price\tDiscount\tFinal Price" << endl;
		for (int i = 0; i < 8; i++)
		{
			cout << i + 1 << "\t" << names[i] << "\t" << brandItem[i] << "\t" << gramItem[i] << "\t" << retailprice[i] << "\t\t" << discounts[i] << " \t" << totalprice[i] << "\t" << localImported[i] << endl;

		}
		cout << endl;
		char let;
		cout << "Do you need to continue : ";
		cin >> let;
		if (let == 'y')
			Main();
	}
	void removeItems()
	{
		system("CLS");
		cout << "No\tName\tBrand\tWeight\tRet.Price\tDiscount\tFinal Price" << endl;
		for (int i = 0; i < 8; i++)
		{
			cout << i + 1 << "\t" << names[i] << brandItem[i] << "\t" << gramItem[i] << "\t" << retailprice[i] << "\t\t" << discounts[i] << " \t" << totalprice[i] << "\t" << localImported[i] << endl;

		}
		cout << endl;
		cout << endl;


		int no, grams;
		cout << "What do you need to remove  " << endl;
		cout << "Select number of item : ";
		cin >> no;
		cout << "How many grams of " << name[no - 1] << "s you need to remove : ";
		cin >> grams;

		if (gram[no - 1] < grams)
		{
			cout << "Sorry there is no enough " << name[no - 1] << "s to remove";
			Main();
		}
		else
		{
			gram[no - 1] -= grams;
			updatefile();
			Main();
		}

	}
};


class Beverages :public Stock {
		//softdrinks	fruitjuice	candrinks	bottleDrinks
	public:
		Beverages()
		{

			ifstream Bev("BVR.txt");
			for (int i = 0; i < 8; i++)
			{
				Bev >> names[i] >> gramItem[i] >> retailprice[i] >> discounts[i] >> totalprice[i] >> localImported[i];

			}
		}
		void Main()
		{
			system("CLS");
			int n;
			cout << "1. Display items\n2. Add items\n3. Remove items\n4. Back\n";
			cin >> n;
			switch (n)
			{
			case 1:
				displayItems();
				break;
			case 2:
				addItems();
				break;
			case 3:
				removeItems();
				break;
			case 4:stock();
				break;
			}
		}
		void updatefile()
		{
			ofstream BVR("BVR.txt");
			for (int i = 0; i < 8; i++)
			{
				BVR << names[i] << " " << gramItem[i] << " " << retailprice[i] << " " << discounts[i] << " " << totalprice[i] << " " << localImported[i] << endl;

			}
		}
		void displayItems()
		{
			system("CLS");
			cout << "No\tName\tBrand\tWeight\tRet.Price\tDiscount\tFinal Price" << endl;
			for (int i = 0; i < 8; i++)
			{
				cout << i + 1 << "\t" << names[i] << "\t" << brandItem[i] << "\t" << gramItem[i] << "\t" << retailprice[i] << "\t\t" << discounts[i] << " \t" << totalprice[i] << "\t" << localImported[i] << endl;

			}
			cout << endl;
			char let;
			cout << "Do you need to continue : ";
			cin >> let;
			if (let == 'y')
				Main();
		}
		void addItems()
		{
			system("CLS");
			cout << "No\tName\tBrand\tWeight\tRet.Price\tDiscount\tFinal Price" << endl;
			for (int i = 0; i < 8; i++)
			{
				cout << i + 1 << "\t" << names[i] << "\t" << brandItem[i] << "\t" << gramItem[i] << "\t" << retailprice[i] << "\t\t" << discounts[i] << " \t" << totalprice[i] << "\t" << localImported[i] << endl;

			}
			cout << endl;
			cout << endl << endl;
			int no, grams;
			char li;
			cout << "What do you need to add  " << endl;
			cout << "Select number of item from above list : ";

			cin >> no;
			cout << "How many grams of " << name[no - 1] << "s you need to add : ";
			cin >> grams;

			gram[no - 1] += grams;
			updatefile();
			Main();

		}
		void removeItems()
		{
			system("CLS");
			cout << "No\tName\tBrand\tWeight\tRet.Price\tDiscount\tFinal Price" << endl;
			for (int i = 0; i < 8; i++)
			{
				cout << i + 1 << "\t" << names[i] << brandItem[i] << "\t" << gramItem[i] << "\t" << retailprice[i] << "\t\t" << discounts[i] << " \t" << totalprice[i] << "\t" << localImported[i] << endl;

			}
			cout << endl;
			cout << endl;


			int no, grams;
			cout << "What do you need to remove  " << endl;
			cout << "Select number of item : ";
			cin >> no;
			cout << "How many grams of " << name[no - 1] << "s you need to remove : ";
			cin >> grams;

			if (gram[no - 1] < grams)
			{
				cout << "Sorry there is no enough " << name[no - 1] << "s to remove";
				Main();
			}
			else
			{
				gram[no - 1] -= grams;
				updatefile();
				Main();
			}

		}
	};
class Beverages_FW :public Stock_FW {
		//softdrinks	fruitjuice	candrinks	bottleDrinks
	public:
		Beverages_FW()
		{

			ifstream Bev("BVR.txt");
			for (int i = 0; i < 8; i++)
			{
				Bev >> names[i] >> gramItem[i] >> retailprice[i] >> discounts[i] >> totalprice[i] >> localImported[i];

			}
		}
		void Main()
		{
			system("CLS");
			int n;
			cout << "1. Display items\n2. Add items\n3. Back\n";
			cin >> n;
			switch (n)
			{
			case 1:
				displayItems();
				break;
			case 2:
				addItems();
				break;
			case 3:
				stock();
				break;
			}
		}
		void updatefile()
		{
			ofstream BVR("BVR.txt");
			for (int i = 0; i < 8; i++)
			{
				BVR << names[i] << " " << gramItem[i] << " " << retailprice[i] << " " << discounts[i] << " " << totalprice[i] << " " << localImported[i] << endl;

			}
		}
		void displayItems()
		{
			system("CLS");
			cout << "No\tName\tBrand\tWeight\tRet.Price\tDiscount\tFinal Price" << endl;
			for (int i = 0; i < 8; i++)
			{
				cout << i + 1 << "\t" << names[i] << "\t" << brandItem[i] << "\t" << gramItem[i] << "\t" << retailprice[i] << "\t\t" << discounts[i] << " \t" << totalprice[i] << "\t" << localImported[i] << endl;

			}
			cout << endl;
			char let;
			cout << "Do you need to continue : ";
			cin >> let;
			if (let == 'y')
				Main();
		}
		void addItems()
		{
			system("CLS");
			cout << "No\tName\tBrand\tWeight\tRet.Price\tDiscount\tFinal Price" << endl;
			for (int i = 0; i < 8; i++)
			{
				cout << i + 1 << "\t" << names[i] << "\t" << brandItem[i] << "\t" << gramItem[i] << "\t" << retailprice[i] << "\t\t" << discounts[i] << " \t" << totalprice[i] << "\t" << localImported[i] << endl;

			}
			cout << endl;
			cout << endl << endl;
			int no, grams;
			char li;
			cout << "What do you need to add  " << endl;
			cout << "Select number of item from above list : ";

			cin >> no;
			cout << "How many grams of " << name[no - 1] << "s you need to add : ";
			cin >> grams;

			gram[no - 1] += grams;
			updatefile();
			Main();

		}
		
	};
class Beverages_CS :public Stock_CS {
	//softdrinks	fruitjuice	candrinks	bottleDrinks
public:
	Beverages_CS()
	{

		ifstream Bev("BVR.txt");
		for (int i = 0; i < 8; i++)
		{
			Bev >> names[i] >> gramItem[i] >> retailprice[i] >> discounts[i] >> totalprice[i] >> localImported[i];

		}
	}
	void Main()
	{
		system("CLS");
		int n;
		cout << "1. Display items\n2. Remove items\n3. Back\n";
		cin >> n;
		switch (n)
		{
		case 1:
			displayItems();
			break;
		case 2:
			removeItems();
			break;
		case 3:
			stock();
			break;
		}
	}
	void updatefile()
	{
		ofstream BVR("BVR.txt");
		for (int i = 0; i < 8; i++)
		{
			BVR << names[i] << " " << gramItem[i] << " " << retailprice[i] << " " << discounts[i] << " " << totalprice[i] << " " << localImported[i] << endl;

		}
	}
	void displayItems()
	{
		system("CLS");
		cout << "No\tName\tBrand\tWeight\tRet.Price\tDiscount\tFinal Price" << endl;
		for (int i = 0; i < 8; i++)
		{
			cout << i + 1 << "\t" << names[i] << "\t" << brandItem[i] << "\t" << gramItem[i] << "\t" << retailprice[i] << "\t\t" << discounts[i] << " \t" << totalprice[i] << "\t" << localImported[i] << endl;

		}
		cout << endl;
		char let;
		cout << "Do you need to continue : ";
		cin >> let;
		if (let == 'y')
			Main();
	}
	void removeItems()
	{
		system("CLS");
		cout << "No\tName\tBrand\tWeight\tRet.Price\tDiscount\tFinal Price" << endl;
		for (int i = 0; i < 8; i++)
		{
			cout << i + 1 << "\t" << names[i] << brandItem[i] << "\t" << gramItem[i] << "\t" << retailprice[i] << "\t\t" << discounts[i] << " \t" << totalprice[i] << "\t" << localImported[i] << endl;

		}
		cout << endl;
		cout << endl;


		int no, grams;
		cout << "What do you need to remove  " << endl;
		cout << "Select number of item : ";
		cin >> no;
		cout << "How many grams of " << name[no - 1] << "s you need to remove : ";
		cin >> grams;

		if (gram[no - 1] < grams)
		{
			cout << "Sorry there is no enough " << name[no - 1] << "s to remove";
			Main();
		}
		else
		{
			gram[no - 1] -= grams;
			updatefile();
			Main();
		}

	}
};

class Health_Beauty :public Stock {
		//soap	toothpaste	shampoo	cream
	public:
		Health_Beauty()
		{
			ifstream HB("HB.txt");
			for (int i = 0; i < 8; i++)
			{
				HB >> names[i] >> gramItem[i] >> retailprice[i] >> discounts[i] >> totalprice[i] >> localImported[i];

			}

		}
		void Main()
		{
			system("CLS");
			int n;
			cout << "1. Display items\n2. Add items\n3. Remove items\n4. Back\n";
			cin >> n;
			switch (n)
			{
			case 1:
				displayItems();
				break;
			case 2:
				addItems();
				break;
			case 3:
				removeItems();
				break;
			case 4:
				stock();
				break;
			}
		}
		void updatefile()
		{
			ofstream HB("HB.txt");
			for (int i = 0; i < 8; i++)
			{
				HB << names[i] << " " << gramItem[i] << " " << retailprice[i] << " " << discounts[i] << " " << totalprice[i] << " " << localImported[i] << endl;

			}
		}
		void displayItems()
		{
			system("CLS");
			cout << "No\tName\tBrand\tWeight\tRet.Price\tDiscount\tFinal Price" << endl;
			for (int i = 0; i < 8; i++)
			{
				cout << i + 1 << "\t" << names[i] << "\t" << brandItem[i] << "\t" << gramItem[i] << "\t" << retailprice[i] << "\t\t" << discounts[i] << " \t" << totalprice[i] << "\t" << localImported[i] << endl;

			}
			cout << endl;
			char let;
			cout << "Do you need to continue : ";
			cin >> let;
			if (let == 'y')
				Main();
		}
		void addItems()
		{
			system("CLS");
			cout << "No\tName\tBrand\tWeight\tRet.Price\tDiscount\tFinal Price" << endl;
			for (int i = 0; i < 8; i++)
			{
				cout << i + 1 << "\t" << names[i] << "\t" << brandItem[i] << "\t" << gramItem[i] << "\t" << retailprice[i] << "\t\t" << discounts[i] << " \t" << totalprice[i] << "\t" << localImported[i] << endl;

			}
			cout << endl;
			cout << endl << endl;
			int no, grams;
			char li;
			cout << "What do you need to add  " << endl;
			cout << "Select number of item from above list : ";

			cin >> no;
			cout << "How many grams of " << name[no - 1] << "s you need to add : ";
			cin >> grams;

			gram[no - 1] += grams;
			updatefile();
			Main();

		}
		void removeItems()
		{
			system("CLS");
			cout << "No\tName\tBrand\tWeight\tRet.Price\tDiscount\tFinal Price" << endl;
			for (int i = 0; i < 8; i++)
			{
				cout << i + 1 << "\t" << names[i] << brandItem[i] << "\t" << gramItem[i] << "\t" << retailprice[i] << "\t\t" << discounts[i] << " \t" << totalprice[i] << "\t" << localImported[i] << endl;

			}
			cout << endl;
			cout << endl;


			int no, grams;
			cout << "What do you need to remove  " << endl;
			cout << "Select number of item : ";
			cin >> no;
			cout << "How many grams of " << name[no - 1] << "s you need to remove : ";
			cin >> grams;

			if (gram[no - 1] < grams)
			{
				cout << "Sorry there is no enough " << name[no - 1] << "s to remove";
				Main();
			}
			else
			{
				gram[no - 1] -= grams;
				updatefile();
				Main();
			}

		}
	};
class Health_Beauty_FW :public Stock_FW {
		//soap	toothpaste	shampoo	cream
	public:
		Health_Beauty_FW()
		{
			ifstream HB("HB.txt");
			for (int i = 0; i < 8; i++)
			{
				HB >> names[i] >> gramItem[i] >> retailprice[i] >> discounts[i] >> totalprice[i] >> localImported[i];

			}

		}
		void Main()
		{
			system("CLS");
			int n;
			cout << "1. Display items\n2. Add items\n3. Back\n";
			cin >> n;
			switch (n)
			{
			case 1:
				displayItems();
				break;
			case 2:
				addItems();
				break;
			case 3:
				stock();
				break;
			}
		}
		void updatefile()
		{
			ofstream HB("HB.txt");
			for (int i = 0; i < 8; i++)
			{
				HB << names[i] << " " << gramItem[i] << " " << retailprice[i] << " " << discounts[i] << " " << totalprice[i] << " " << localImported[i] << endl;

			}
		}
		void displayItems()
		{
			system("CLS");
			cout << "No\tName\tBrand\tWeight\tRet.Price\tDiscount\tFinal Price" << endl;
			for (int i = 0; i < 8; i++)
			{
				cout << i + 1 << "\t" << names[i] << "\t" << brandItem[i] << "\t" << gramItem[i] << "\t" << retailprice[i] << "\t\t" << discounts[i] << " \t" << totalprice[i] << "\t" << localImported[i] << endl;

			}
			cout << endl;
			char let;
			cout << "Do you need to continue : ";
			cin >> let;
			if (let == 'y')
				Main();
		}
		void addItems()
		{
			system("CLS");
			cout << "No\tName\tBrand\tWeight\tRet.Price\tDiscount\tFinal Price" << endl;
			for (int i = 0; i < 8; i++)
			{
				cout << i + 1 << "\t" << names[i] << "\t" << brandItem[i] << "\t" << gramItem[i] << "\t" << retailprice[i] << "\t\t" << discounts[i] << " \t" << totalprice[i] << "\t" << localImported[i] << endl;

			}
			cout << endl;
			cout << endl << endl;
			int no, grams;
			char li;
			cout << "What do you need to add  " << endl;
			cout << "Select number of item from above list : ";

			cin >> no;
			cout << "How many grams of " << name[no - 1] << "s you need to add : ";
			cin >> grams;

			gram[no - 1] += grams;
			updatefile();
			Main();

		}
	
	};
class Health_Beauty_CS :public Stock_CS {
	//soap	toothpaste	shampoo	cream
public:
	Health_Beauty_CS()
	{
		ifstream HB("HB.txt");
		for (int i = 0; i < 8; i++)
		{
			HB >> names[i] >> gramItem[i] >> retailprice[i] >> discounts[i] >> totalprice[i] >> localImported[i];

		}

	}
	void Main()
	{
		system("CLS");
		int n;
		cout << "1. Display items\n2. Remove items\n3. Back\n";
		cin >> n;
		switch (n)
		{
		case 1:
			displayItems();
			break;
		case 2:
			removeItems();
			break;
		case 3:
			stock();
			break;
		}
	}
	void updatefile()
	{
		ofstream HB("HB.txt");
		for (int i = 0; i < 8; i++)
		{
			HB << names[i] << " " << gramItem[i] << " " << retailprice[i] << " " << discounts[i] << " " << totalprice[i] << " " << localImported[i] << endl;

		}
	}
	void displayItems()
	{
		system("CLS");
		cout << "No\tName\tBrand\tWeight\tRet.Price\tDiscount\tFinal Price" << endl;
		for (int i = 0; i < 8; i++)
		{
			cout << i + 1 << "\t" << names[i] << "\t" << brandItem[i] << "\t" << gramItem[i] << "\t" << retailprice[i] << "\t\t" << discounts[i] << " \t" << totalprice[i] << "\t" << localImported[i] << endl;

		}
		cout << endl;
		char let;
		cout << "Do you need to continue : ";
		cin >> let;
		if (let == 'y')
			Main();
	}
	void removeItems()
	{
		system("CLS");
		cout << "No\tName\tBrand\tWeight\tRet.Price\tDiscount\tFinal Price" << endl;
		for (int i = 0; i < 8; i++)
		{
			cout << i + 1 << "\t" << names[i] << brandItem[i] << "\t" << gramItem[i] << "\t" << retailprice[i] << "\t\t" << discounts[i] << " \t" << totalprice[i] << "\t" << localImported[i] << endl;

		}
		cout << endl;
		cout << endl;


		int no, grams;
		cout << "What do you need to remove  " << endl;
		cout << "Select number of item : ";
		cin >> no;
		cout << "How many grams of " << name[no - 1] << "s you need to remove : ";
		cin >> grams;

		if (gram[no - 1] < grams)
		{
			cout << "Sorry there is no enough " << name[no - 1] << "s to remove";
			Main();
		}
		else
		{
			gram[no - 1] -= grams;
			updatefile();
			Main();
		}

	}
};

class Condiments_Spices :public Stock {
		//sauce	mayonnaise	chilliepowder	turmeric
	public:
		Condiments_Spices()
		{
			ifstream CS("CS.txt");
			for (int i = 0; i < 8; i++)
			{
				CS >> names[i] >> gramItem[i] >> retailprice[i] >> discounts[i] >> totalprice[i] >> localImported[i];

			}

		}
		void Main()
		{
			system("CLS");
			int n;
			cout << "1. Display items\n2. Add items\n3. Remove items\n4. Back\n";
			cin >> n;
			switch (n)
			{
			case 1:
				displayItems();
				break;
			case 2:
				addItems();
				break;
			case 3:
				removeItems();
				break;
			case 4:
				stock;
				break;
			}
		}
		void updatefile()
		{
			ofstream CS("CS.txt");
			for (int i = 0; i < 8; i++)
			{
				CS << names[i] << " " << gramItem[i] << " " << retailprice[i] << " " << discounts[i] << " " << totalprice[i] << " " << localImported[i] << endl;

			}
		}
		void displayItems()
		{
			system("CLS");
			cout << "No\tName\tBrand\tWeight\tRet.Price\tDiscount\tFinal Price" << endl;
			for (int i = 0; i < 8; i++)
			{
				cout << i + 1 << "\t" << names[i] << "\t" << brandItem[i] << "\t" << gramItem[i] << "\t" << retailprice[i] << "\t\t" << discounts[i] << " \t" << totalprice[i] << "\t" << localImported[i] << endl;

			}
			cout << endl;
			char let;
			cout << "Do you need to continue : ";
			cin >> let;
			if (let == 'y')
				Main();
		}
		void addItems()
		{
			system("CLS");
			cout << "No\tName\tBrand\tWeight\tRet.Price\tDiscount\tFinal Price" << endl;
			for (int i = 0; i < 8; i++)
			{
				cout << i + 1 << "\t" << names[i] << "\t" << brandItem[i] << "\t" << gramItem[i] << "\t" << retailprice[i] << "\t\t" << discounts[i] << " \t" << totalprice[i] << "\t" << localImported[i] << endl;

			}
			cout << endl;
			cout << endl << endl;
			int no, grams;
			char li;
			cout << "What do you need to add  " << endl;
			cout << "Select number of item from above list : ";

			cin >> no;
			cout << "How many grams of " << name[no - 1] << "s you need to add : ";
			cin >> grams;

			gram[no - 1] += grams;
			updatefile();
			Main();

		}
		void removeItems()
		{
			system("CLS");
			cout << "No\tName\tBrand\tWeight\tRet.Price\tDiscount\tFinal Price" << endl;
			for (int i = 0; i < 8; i++)
			{
				cout << i + 1 << "\t" << names[i] << brandItem[i] << "\t" << gramItem[i] << "\t" << retailprice[i] << "\t\t" << discounts[i] << " \t" << totalprice[i] << "\t" << localImported[i] << endl;

			}
			cout << endl;
			cout << endl;


			int no, grams;
			cout << "What do you need to remove  " << endl;
			cout << "Select number of item : ";
			cin >> no;
			cout << "How many grams of " << name[no - 1] << "s you need to remove : ";
			cin >> grams;

			if (gram[no - 1] < grams)
			{
				cout << "Sorry there is no enough " << name[no - 1] << "s to remove";
				Main();
			}
			else
			{
				gram[no - 1] -= grams;
				updatefile();
				Main();
			}

		}
	};
class Condiments_Spices_FW :public Stock_FW {
		//sauce	mayonnaise	chilliepowder	turmeric
	public:
		Condiments_Spices_FW()
		{
			ifstream CS("CS.txt");
			for (int i = 0; i < 8; i++)
			{
				CS >> names[i] >> gramItem[i] >> retailprice[i] >> discounts[i] >> totalprice[i] >> localImported[i];

			}

		}
		void Main()
		{
			system("CLS");
			int n;
			cout << "1. Display items\n2. Add items\n3. Back\n";
			cin >> n;
			switch (n)
			{
			case 1:
				displayItems();
				break;
			case 2:
				addItems();
				break;
			case 3:
				stock;
				break;
			}
		}
		void updatefile()
		{
			ofstream CS("CS.txt");
			for (int i = 0; i < 8; i++)
			{
				CS << names[i] << " " << gramItem[i] << " " << retailprice[i] << " " << discounts[i] << " " << totalprice[i] << " " << localImported[i] << endl;

			}
		}
		void displayItems()
		{
			system("CLS");
			cout << "No\tName\tBrand\tWeight\tRet.Price\tDiscount\tFinal Price" << endl;
			for (int i = 0; i < 8; i++)
			{
				cout << i + 1 << "\t" << names[i] << "\t" << brandItem[i] << "\t" << gramItem[i] << "\t" << retailprice[i] << "\t\t" << discounts[i] << " \t" << totalprice[i] << "\t" << localImported[i] << endl;

			}
			cout << endl;
			char let;
			cout << "Do you need to continue : ";
			cin >> let;
			if (let == 'y')
				Main();
		}
		void addItems()
		{
			system("CLS");
			cout << "No\tName\tBrand\tWeight\tRet.Price\tDiscount\tFinal Price" << endl;
			for (int i = 0; i < 8; i++)
			{
				cout << i + 1 << "\t" << names[i] << "\t" << brandItem[i] << "\t" << gramItem[i] << "\t" << retailprice[i] << "\t\t" << discounts[i] << " \t" << totalprice[i] << "\t" << localImported[i] << endl;

			}
			cout << endl;
			cout << endl << endl;
			int no, grams;
			char li;
			cout << "What do you need to add  " << endl;
			cout << "Select number of item from above list : ";

			cin >> no;
			cout << "How many grams of " << name[no - 1] << "s you need to add : ";
			cin >> grams;

			gram[no - 1] += grams;
			updatefile();
			Main();

		}
		
	};
class Condiments_Spices_CS :public Stock_CS {
	//sauce	mayonnaise	chilliepowder	turmeric
public:
	Condiments_Spices_CS()
	{
		ifstream CS("CS.txt");
		for (int i = 0; i < 8; i++)
		{
			CS >> names[i] >> gramItem[i] >> retailprice[i] >> discounts[i] >> totalprice[i] >> localImported[i];

		}

	}
	void Main()
	{
		system("CLS");
		int n;
		cout << "1. Display items\n2. Remove items\n3. Back\n";
		cin >> n;
		switch (n)
		{
		case 1:
			displayItems();
			break;
		case 2:
			removeItems();
			break;
		case 3:
			stock;
			break;
		}
	}
	void updatefile()
	{
		ofstream CS("CS.txt");
		for (int i = 0; i < 8; i++)
		{
			CS << names[i] << " " << gramItem[i] << " " << retailprice[i] << " " << discounts[i] << " " << totalprice[i] << " " << localImported[i] << endl;

		}
	}
	void displayItems()
	{
		system("CLS");
		cout << "No\tName\tBrand\tWeight\tRet.Price\tDiscount\tFinal Price" << endl;
		for (int i = 0; i < 8; i++)
		{
			cout << i + 1 << "\t" << names[i] << "\t" << brandItem[i] << "\t" << gramItem[i] << "\t" << retailprice[i] << "\t\t" << discounts[i] << " \t" << totalprice[i] << "\t" << localImported[i] << endl;

		}
		cout << endl;
		char let;
		cout << "Do you need to continue : ";
		cin >> let;
		if (let == 'y')
			Main();
	}
	void removeItems()
	{
		system("CLS");
		cout << "No\tName\tBrand\tWeight\tRet.Price\tDiscount\tFinal Price" << endl;
		for (int i = 0; i < 8; i++)
		{
			cout << i + 1 << "\t" << names[i] << brandItem[i] << "\t" << gramItem[i] << "\t" << retailprice[i] << "\t\t" << discounts[i] << " \t" << totalprice[i] << "\t" << localImported[i] << endl;

		}
		cout << endl;
		cout << endl;


		int no, grams;
		cout << "What do you need to remove  " << endl;
		cout << "Select number of item : ";
		cin >> no;
		cout << "How many grams of " << name[no - 1] << "s you need to remove : ";
		cin >> grams;

		if (gram[no - 1] < grams)
		{
			cout << "Sorry there is no enough " << name[no - 1] << "s to remove";
			Main();
		}
		else
		{
			gram[no - 1] -= grams;
			updatefile();
			Main();
		}

	}
};

	int main()
	{
		userLogin();
		return 0;
	}


	int stock()
	{
		cout << "------------------Welcome to Stock------------------\n\n";
		int n;
		cout << "1. Fruits And vegetables\n2. Meat And Sea foods\n3. Grains\n4. Bakery Products\n5. Frozen Products\n6. Dairy products\n7. Snacks And Sweets"
			"\n8. Beverages\n9. Health And Beauty\n10. Condiments And Spices\n11. Exit" << endl;
		cin >> n;


		switch (n)
		{
		case 1: {
			Fruits_Vegetables f;
			f.Main();
		}
			  break;
		case 2: {
			Meat_SeaFoods f;
			f.Main();
		}
			  break;
		case 3: {
			Grains f;
			f.Main();
		}
			  break;
		case 4: {
			Bakery f;
			f.Main();
		}
			  break;
		case 5: {
			FrozenFoods f;
			f.Main();
		}
			  break;
		case 6: {
			Dairy f;
			f.Main();
		}
			  break;
		case 7: {
			Snacks_sweets f;
			f.Main();
		}
			  break;
		case 8: {
			Beverages f;
			f.Main();
		}
			  break;
		case 9: {
			Health_Beauty f;
			f.Main();
		}
			  break;
		case 10: {
			Condiments_Spices f;
			f.Main();
		}
			   break;
		case 11: {
			return 0;
		}
			   break;

		}

	}
	int stock_FW()
	{
		cout << "------------------Welcome to Stock------------------\n\n";
		int n;
		cout << "1. Fruits And vegetables\n2. Meat And Sea foods\n3. Grains\n4. Bakery Products\n5. Frozen Products\n6. Dairy products\n7. Snacks And Sweets"
			"\n8. Beverages\n9. Health And Beauty\n10. Condiments And Spices\n11. Exit" << endl;
		cin >> n;


		switch (n)
		{
		case 1: {
			Fruits_Vegetables_FW f;
			f.Main();
		}
			  break;
		case 2: {
			Meat_SeaFoods_FW f;
			f.Main();
		}
			  break;
		case 3: {
			Grains_FW f;
			f.Main();
		}
			  break;
		case 4: {
			Bakery_FW f;
			f.Main();
		}
			  break;
		case 5: {
			FrozenFoods_FW f;
			f.Main();
		}
			  break;
		case 6: {
			Dairy_FW f;
			f.Main();
		}
			  break;
		case 7: {
			Snacks_sweets_FW f;
			f.Main();
		}
			  break;
		case 8: {
			Beverages_FW f;
			f.Main();
		}
			  break;
		case 9: {
			Health_Beauty_FW f;
			f.Main();
		}
			  break;
		case 10: {
			Condiments_Spices_FW f;
			f.Main();
		}
			   break;
		case 11: {
			return 0;
		}
			   break;

		}

	}
	int stock_CS()
	{
		cout << "------------------Welcome to Stock------------------\n\n";
		int n;
		cout << "1. Fruits And vegetables\n2. Meat And Sea foods\n3. Grains\n4. Bakery Products\n5. Frozen Products\n6. Dairy products\n7. Snacks And Sweets"
			"\n8. Beverages\n9. Health And Beauty\n10. Condiments And Spices\n11. Exit" << endl;
		cin >> n;


		switch (n)
		{
		case 1: {
			Fruits_Vegetables_CS f;
			f.Main();
		}
			  break;
		case 2: {
			Meat_SeaFoods_CS f;
			f.Main();
		}
			  break;
		case 3: {
			Grains_CS f;
			f.Main();
		}
			  break;
		case 4: {
			Bakery_CS f;
			f.Main();
		}
			  break;
		case 5: {
			FrozenFoods_CS f;
			f.Main();
		}
			  break;
		case 6: {
			Dairy_CS f;
			f.Main();
		}
			  break;
		case 7: {
			Snacks_sweets_CS f;
			f.Main();
		}
			  break;
		case 8: {
			Beverages_CS f;
			f.Main();
		}
			  break;
		case 9: {
			Health_Beauty_CS f;
			f.Main();
		}
			  break;
		case 10: {
			Condiments_Spices_CS f;
			f.Main();
		}
			   break;
		case 11: {
			return 0;
		}
			   break;

		}

	}

	void userLogin()
	{

		cout << "\t\t\t*****************************************************\n";
		cout << "\t\t\t*                                                   *\n";
		cout << "\t\t\t*             WELCOME TO OUR LOGIN PAGE             *\n";
		cout << "\t\t\t*                                                   *\n";
		cout << "\t\t\t*****************************************************\n";

		string* username;
		username = new string[100];

		string* password;
		password = new string[100];

		ifstream UNPWD("Username_Password.txt");

		int i = 0;
		while (UNPWD >> username[i] >> password[i])
		{
			i++;
		}
		int count = 0;
		while (count < 3)
		{
			cout << "\n\t\t\t\tUser Name\t:\t";
			string un, pwd;
			cin >> un;
			cout << "\n\t\t\t\tPassword\t:\t";
			cin >> pwd;
			int no = 0;
			while (no<=100)
			{
				if (un == username[no])
				{
					if (pwd == password[no])
					{

						switch (username[no][0])
						{
						case 'F': {
							system("CLS");
							cout << "USER NAME\t:\t" << username[no] <<"\t\t ***FLOOR WORKER***"<< endl << endl;
							FloorWorkers f;
							f.Main();
							break;
						}

						case 'C': {
							system("CLS");
							cout << "USER NAME\t:\t" << username[no] << "\t\t ***CASHIER***" << endl << endl;
							Cashier c;
							c.Main();
							break;
						}

						case 'M': {
							system("CLS");
							cout << "USER NAME\t:\t" << username[no] << "\t\t ***MANAGER***" << endl << endl;
							Manager m;
							m.Main();
							break;
						}

						case 'O': {
							system("CLS");
							cout << "USER NAME\t:\t" << username[no] << "\t\t ***OWNER***" << endl << endl;
							Owner o;
							o.Main();
							break;
						}

						}
					}
					else
					{
						system("CLS");
						cout << "Your Password is not correct. Try again" << endl;
						count++;
					}

				}
				else
				no++;
			}
				
			system("CLS");
			cout << "Your username is not correct. Try again" << endl;
			count++;
					
				
			
		}

	}
