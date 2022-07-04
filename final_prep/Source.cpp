#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int total_accounts = 0;
const int no_of_details = 5;

void add_acc()
{
	int temp = 0;

	ifstream total_acc;
	total_acc.open("total_acc.txt");

	if (!total_acc.is_open())
	{
		cout << "fail";
	}
	
	total_acc >> temp;
	temp++;
	total_acc.close();
	remove("total_acc.txt");

	ofstream temp_file;

	temp_file.open("temp.txt");

	if (!temp_file.is_open())
	{
		cout << "FAILED.";
	}

	temp_file << temp;
	temp_file.close();

	rename("temp.txt", "total_acc.txt");

	total_accounts = temp;
}

void register_acc(fstream& accounts)
{
	string temp;
	int length_temp = 0;
	bool check = true;

	system("CLS");
	cout << "\t REGISTRATION WINDOW\n\n\n";

	//account number
	cout << "ACCOUNT NUMBER : ";
	accounts << "\n";

	if (total_accounts < 9)
	{
		accounts << "00";
		cout << "00";
	}
	else if (total_accounts < 99)
	{
		accounts << "0";
		cout << "0";
	}

	accounts << total_accounts + 1;

	cout << total_accounts + 1 << "\n";	
	

	//name
	cout << "ENTER NAME : ";
	getline(cin, temp);

	length_temp = temp.length();

	while (!(length_temp <= 0 || length_temp >= 16))
	{
		cout << "\n\n\tNOPE\ntry again : ";
		getline(cin, temp);
		length_temp = temp.length();
	}

	accounts.clear();
	accounts << temp;

	if (length_temp < 4)
	{
		accounts << "\t\t\t\t";
	}
	else if (length_temp >= 4 && length_temp < 8)
	{
		accounts << "\t\t\t";
	}
	else if (length_temp >= 8 && length_temp < 12)
	{
		accounts << "\t\t";
	}
	else if (length_temp >= 12 && length_temp < 16)
	{
		accounts << "\t";
	}
	

	//card number
	cout << "enter card number : ";
	getline(cin, temp);

	while (temp.length() != 16)
	{
		cout << "\n\n\tNOPE\ntry again : ";
		getline(cin, temp);
	}

	accounts << temp << "t";


	//phone number
	cout << "enter phone number : ";
	getline(cin, temp);
	while (temp.length() != 11)
	{
		cout << "\n\n\tNOPE\ntry again : ";
		getline(cin, temp);
	}
	accounts << temp << "\t\t";


	//deposit ammount
	cout << "enter deposit ammount : ";
	getline(cin, temp);
	accounts << temp;

	add_acc();
}

void show_info(fstream& accounts)
{
	/*string name = "";
	getline(cin, name);*/

	string input;
	string* data;
	int count = 0;
	data = new string[no_of_details];
	

	for (int i = 0; !accounts.eof(); i++)
	{
		getline(accounts, input);
		count = 0;

		for (int x = 0; x < no_of_details; x++)
		{
			data[x] = "";
		}

		if (i > 2)
		{
			for (int j = 0; input[j] != '\0'; j++)
			{
				if (input[j] == '\t' && input[j + 1] != '\t')
				{
					data[count].push_back('\0');
					count++;
				}
				else if (input[j] != '\t')
				{
					data[count].push_back(input[j]);
				}
			}
		}

		for (int i = 0; i < 5; i++)
		{
			cout << data[i] << "  ";
		}
		cout << "\n";

	}

	

}

int main()
{
	ifstream total_acc;
	total_acc.open("total_acc.txt");
	if (!total_acc.is_open())
	{
		cout << "failed";
	}

	total_acc >> total_accounts;
	total_acc.close();

	fstream accounts;
	accounts.open("accounts.txt", ios::in | ios::out | ios::app);

	show_info(accounts);

	/*register_acc(accounts);*/

	accounts.close();
}



//	ofstream writeMode; //Created object of ofstream
//	writeMode.open("name.dat"); //Opened the file in write mode
//	writeMode << name << endl; //Putted data inside the file
//	writeMode << name << endl; //Again putted data inside the file
//	writeMode.close(); //Closed the write mode
// 
// 
//	ifstream readMode; //Created object of ifstream
//	readMode.open("name.dat"); //Opened the file in read mode.
//	readMode >> name;
//	readMode.close(); //Closed the read mode
//	system("pause");
//	return 0;
//}
