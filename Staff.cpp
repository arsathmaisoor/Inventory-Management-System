#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <fstream>
using namespace std;

void userLogin();

class Staff {
protected:
	string* username;
	string* password;
	string* fullname;
	string* position;
	string* join_date;

public:

	virtual void details() {}	
	virtual void displayDetails() {}
	virtual void addStaffs() {}
	virtual void removeStaffs() {}
	virtual void addStocks() {}
	virtual void removeStocks() {}
};

class FloorWorkers :public Staff {
public:
	//4
	FloorWorkers()
	{
		username = new string[4];
		password = new string[4];
		fullname = new string[4];
		position = new string[4];
		join_date = new string[4];

		string frst, last;

		ifstream obj("Floorworkers.txt");
		for (int i = 0; i < 4; i++)
		{
			obj >> frst >> last >> username[i] >> password[i] >> join_date[i];
			fullname[i] = frst + " " + last;
		}
		for (int i = 0; i < 4; i++)
			position[i] = "Floor_Worker";

	}
	void details()
	{
		cout << "1. View Stocks\n2. Add stock items\n3. Back\n";
		int n;
		cin >> n;

		switch (n)
		{
		case 1:
			displayDetails();
			break;
		case 2:
			break;
		case 3:
			break;
		case 4:
			break;
		case 5:
			break;
		}
	}
	void addStocks()
	{

	}
};

class Cashier :public Staff {
public:
	Cashier()
	{
		username = new string[4];
		password = new string[4];
		fullname = new string[4];
		position = new string[4];
		join_date = new string[4];

		string frst, last;

		ifstream obj("Floorworkers.txt");
		for (int i = 0; i < 4; i++)
		{
			obj >> frst >> last >> username[i] >> password[i] >> join_date[i];
			fullname[i] = frst + " " + last;
		}
		for (int i = 0; i < 4; i++)
			position[i] = "Floor_Worker";
	}
};

class Manager :public Staff {
public:

	void displayDetails()
	{
		system("CLS");
		cout << "No\tFull Name\tPostion\tJoin date\n";
		for (int i = 0; i < 4; i++)
			cout << i + 1 << "\t" << fullname[i] << "\t" << position[i] << "\t" << join_date << "\n";

		cout << endl;
		cout << "Do you need to continue : ";
		char let;
		cin >> let;

		if (let == 'y')
			details();
	}
};

class Owner :public Staff {

};

int main()
{
	userLogin();
}

void userlogin()
{
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
		cout << "User Name\t:\t";
		string un, pwd;
		cin >> un;
		cout << "Password\t:\t";
		cin >> pwd;
		int no = 0;
		while (username[no] != "\0")
		{
			if (un == username[no])
			{
				if (pwd == password[no])
				{

					switch (username[no][0])
					{
					case 'F': {

						break;
					}

					case 'C': {

						break;
					}

					case 'M': {

						break;
					}

					case 'O': {

						break;
					}

					}
				}

			}
			else
			{
				cout << "Your username or password is not correct. Try again" << endl;
				count++;
				break;
			}
			no++;
		}
	}

}