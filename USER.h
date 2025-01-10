//#pragma once

#include<iostream>
#include<iomanip>
#include<fstream>
#include<string>
using namespace std;


bool matchstr(const char* p, const  char* t)
{

	int i = 0, k = 0;
	for (;p[i] != '\0';i++);
	i++;
	for (;t[k] != '\0';k++);
	k++;
	if (i == k)
	{
		for (int j = 0;j < i;j++)
			if (p[j] != t[j])
				return 0;
		return 1;
	}
	else
		return 0;
}

class Payment
{
	
};

class Epay :public Payment
{

};

class Bank :public Payment
{

};

class Jazzcash :public Epay
{

};

class Easypaisa :public Epay
{

};


class Paypak :public Bank
{

};

class UnionPay :public Bank
{

};


class Date
{
protected:
	int year;
	int month;
	int day;
public:
	Date() 
	{
		year = month = day = 0;
	}
	int getYear()
	{
		return year;
	}
	int getMonth()
	{
		return month;
	}
	int getDay()
	{
		return day;
	}
	void setYear(int y)
	{
		if(y>=2022)
		year = y;
	}
	void setMonth(int m)
	{
		if (m>0&&m <= 12)
			month = m;
	}
	void setDay(int d)
	{
		if (d > 0 && d<=30)
			day = d;
	}

};


class Feedback
{
protected:
	int rating;
	char review[100];  //Patient Review
	char comment[100]; //Doctor / Admin comment
public:
	Feedback()
	{
		rating = 0;
		review[0] = '\0';
	}
	int getRating()
	{
		return rating;
	}
	char* getReview()
	{
		return review;
	}
	char* getcommet()
	{
		return comment;
	}
	void setRating(int r)
	{
		rating = r;
	}
	void setReview(string r)
	{
		strcpy_s(review, r.c_str());
	}
	void setcomment(string c)
	{
		strcpy_s(comment, c.c_str());
	}
};

class Appointment
{
protected:
	Date bd;		//Book hour of Appointment
	int bh,h;		//Book hour of Appointment
	Feedback f;		//Feedback of Appointment
	Date cd;		//complete hour of Appointment
	int ch;			//complete hour of Appointment
	char dCNIC[14];
	char pCNIC[14];
	char dName[30];
	char pName[30];
	double charges;
	char Method[20];
	char status;
	bool comment = 0;
	Payment* p;
public:

	void setMethod(string m)
	{
		strcpy_s(Method, m.c_str());
	}
	Appointment() 
	{
		dCNIC[0]='\0';
		pCNIC[0] = '\0';
		dName[0] = '\0';
		pName[0] = '\0';
		h = 0;
		charges = 0;
		status = 'P';
	}
	char* getDName()
	{
		return dName;
	}
	char* getPName()
	{
		return pName;
	}
	char* getDCNIC()
	{
		return dCNIC;
	}
	char* getPCNIC()
	{
		return pCNIC;
	}
	void setDName(string n)
	{
		strcpy_s(dName, n.c_str());
	}
	void setPName(string n)
	{
		strcpy_s(pName, n.c_str());
	}
	void setDCNIC(string n)
	{
		strcpy_s(dCNIC, n.c_str());
	}
	void setPCNIC(string n)
	{
		strcpy_s( pCNIC,n.c_str());
	}
	void setStatus(char c)
	{
		status = c;
	}
	int getBookDay()
	{
		return bd.getDay();
	}
	Feedback getfeedback()
	{
		return f;
	}
	void setBookdate(int d, int m, int y)
	{
		//Appointment::id++;
		bd.setDay(d);
		bd.setMonth(m);
		bd.setYear(y);
	}
	void setCompdate(int d, int m, int y)
	{
		cd.setDay(d);
		cd.setMonth(m);
		cd.setYear(y);
	}
	void setBookHour(int h)
	{
		bh = h;
	}
	void setCompHour(int h)
	{
		ch = h;
	}
	int getBookHour()
	{
		return bh;
	}
	int getCompHour()
	{
		return ch;
	}
	char getStatus()
	{
		return status;
	}
	int comapareDate()
	{

		if (bd.getDay() == cd.getDay() && bd.getMonth() == cd.getMonth() && bd.getYear() == cd.getYear())
			return 0;
		else if ((bd.getDay()+1) == cd.getDay() && bd.getMonth() == cd.getMonth() && bd.getYear() == cd.getYear())
		{
			return 1;
		}
		else if ((bd.getDay()+2) == cd.getDay() && bd.getMonth() == cd.getMonth() && bd.getYear() == cd.getYear())
		{
			return 2;
		}
		else if ((bd.getDay() + 3) == cd.getDay() && bd.getMonth() == cd.getMonth() && bd.getYear() == cd.getYear())
		{
			return 3;
		}
		else
			return 3;
	}
	void setCharges(int rate)
	{
		charges = rate;
	}
	void Display()
	{
		cout << "\n\n\t\t\t    Appointment Details       : " ;

		cout << "\n\n\t\t\t  Doctor Name  : " << dName;
		cout << "\n\t\t\t  Doctor CNIC  : " << dCNIC;
		cout << "\n\t\t\t  Patient Name : " << pName;
		cout << "\n\t\t\t  Patient Name : " << dCNIC;
		cout << "\n\t\t\t  Book Date    : " << bd.getDay()<<"/"<<bd.getMonth()<<"/"<<bd.getYear();
		cout << "\n\t\t\t  Book Time    : " << bh<<"-"<<bh+1;
		cout << "\n\t\t\t  Method       : " << Method;
		cout << "\n\t\t\t  Charges      : " << charges;
		cout << "\n\t\t\t  Status       : " << status<<endl;

	}
	double extracharge(int n)
	{
		double r;
		if (n == 1)
		{
			r = charges * (0.3);
			return r;
		}
			
		else if (n == 2)
		{
			r = charges * (0.6);
			return r;
		}
			
		else
			return charges;

	}
	double refundcharge(int n)
	{
		double r=0;
		if (n == 1)
		{
			return charges;
		}

		else if (n == 2)
		{
			r = charges * (0.6);
			return r;
		}

		else if (n == 3)
		{
			r = charges * (0.3);
			return charges;
		}
		else
			return 0;

	}
	
};





class Admin;
class Doctor;
class Patient;



class User {
protected:
	bool loggedIn = 0;
	bool repeatCNIC = 0;
	char type;
	char Name[30];
	char CNIC[14];
	char username[20];
	char password[30];
	char SecurityQ[30]; //Security Question for Changing password
public:
	User()
	{
		Name[0] = '\0';
		CNIC[0] = '\0';
		username[0] = '\0';
		password[0] = '\0';
		SecurityQ[0] = '\0';
	}
	char* getName()
	{
		return Name;
	}
	char* getCNIC()
	{
		return CNIC;
	}
	char* getUsername()
	{
		return username;
	}
	char getType()
	{
		return type;
	}
	void setName(string n)
	{
		strcpy_s(this->Name, n.c_str());
	}
	void setUsername(string u)
	{
		strcpy_s(this->username, u.c_str());
	}
	void setPassword(string p)
	{
		strcpy_s(this->password, p.c_str());
	}
	bool checkPassword(string p)

	{
		bool digit = 0, upcase = 0, locase = 0, special = 0;
		int n = p.length();
		if (n >= 8)
		{
			for (int i = 0;i < n;i++)
			{
				if (p[i] >= 65 && p[i] <= 90)
					upcase = 1;
				else if (p[i] >= 97 && p[i] <= 122)
					locase = 1;
				else if ((p[i] > 32 && p[i] <= 47) || (p[i] >= 58 && p[i] <= 64) || (p[i] >= 91 && p[i] <= 96) || (p[i] >= 123 && p[i] <= 126))
					special = 1;
				else if (p[i] > 47 && p[i] < 58)
					digit = 1;
			}
			if (digit && upcase && locase && special)
				return 1;
			else if (!digit)
				cout << "\n\t  Again Enter Password that includes Digits, uppercase, lowercase and special character.\n";
			else if (!upcase)
				cout << "\n\t  Again Enter Password that includes Digits, uppercase, lowercase and special character.\n";
			else if (!locase)
				cout << "\n\t  Again Enter Password that includes Digits, uppercase, lowercase and special character.\n";
			else if (!special)
				cout << "\n\t  Again Enter Password that includes Digits, uppercase, lowercase and special character.\n";
			return 0;
		}

		else
		{
			cout << "\n\t  Minimum 8 Characters required for Password\n";
			return 0;
		}
	}
	bool checkCNIC(string c)
	{
		if (c.length() == 13)
		{
			for (int i = 0;i < 13;i++)
			{
				if (!(c[i] > 47 && c[i] < 58))
				{
					cout << "\n\t  Invalid Input. Again enter CNIC without dashes.";
					return 0;
				}
			}
			return 1;
		}
		else
		{
			cout << "\n\t  Invalid Input. Again enter CNIC without dashes.";
			return 0;
		}
	}

	void setSQ(string q) 
	{
		strcpy_s(this->SecurityQ, q.c_str());
	}

	virtual void UserMainMenu() = 0;
	virtual void Display()
	{
		cout << "\n\t\t\t  Name           : " << Name;
		cout << "\n\t\t\t  Username       : " << username;
		cout << "\n\t\t\t  CNIC           : " << CNIC;
		cout << "\n\t\t\t  Password       : **********"<<endl;

	}
	virtual void Menu()
	{
		int n = 0;
		cout << "\t  1.Login\n";
		cout << "\t  2.Register\n";
		cout << "\n\t  >";
		cin >> n;
		if (n == 1)
		{
			this->login();
		}
		else if (n == 2)
		{
			this->Register();
		}
		else
		{
			cout << "\nInvalid Input. Please Try again.";
		}

	}
	virtual void login()
	{
		cout << "\n\t   Enter your CNIC : ";
		cin >> CNIC;
		
		cout << "\t   Enter the Password : ";
		cin >> password;
		
		while (!checkCNIC(CNIC))
		{
			login();
		}

	}
	virtual void Register()
	{
		string tempname, temppas, temppas2;

		getline(cin, tempname);
		
		cout << "\t  To Register in OLADOC, Please Provide Following Information.\n";
		cout << "\n\t  Enter Your Name          : ";
		getline(cin,tempname);
		setName(tempname);
		 
		cout<< "\t  Enter Your UserName       : ";
		cin >> username;
		cout<< "\t  Enter Your CNIC           : ";
		cin >> CNIC;

		while (!checkCNIC(CNIC))
		{
			cout << "\n\t  Again Enter Your CNIC     : ";
			cin >> CNIC;
		}

		

		cout<< "\t  Enter Your Password       : ";
		cin >> temppas;

		while (!checkPassword(temppas))
		{
			cout << "\n\t  Again Enter Your Password     : ";
			cin >> temppas;
		}
		
		cout << "\t  Re-Enter Your Password    : ";
		cin >> temppas2;


		while (!(matchstr(temppas.c_str(), temppas2.c_str())))
		{
			cout << "\t  Enter Your Password       : ";
			cin >> temppas;

			while (!checkPassword(temppas))
			{
				cout << "\n\t  Again Enter Your Password     : ";
				cin >> temppas;
			}

			cout << "\t  Re-Enter Your Password    : ";
			cin >> temppas2;
		}

		setPassword(temppas);

		cout << "\n\t  Remember the following Answer for Reseting Your Password.\n";
		cout << "\n\t  What is Name of Your Birthplace : ";
		cin >> SecurityQ;
	}
	virtual void Display_Sed() {}
};



//----------------------------------------------------------------------------------------------

void storeobj(string fileName, User* obj);
void updatePatient(Patient t);
Doctor getdoc(string tcnic);
void updateDoc(Doctor t);
void storeapp(Appointment* app);
void displayDapp(string dcnic);
void displayPapp(string pcnic);
Appointment searchApp(string Dcnic, int time,int day);
void updateApp(Appointment t, int time, int day);
void deleteApp(Appointment t, int time, int day);
Patient getPat(string tcnic);
void feed(string tcnic);
void displaydoc();
void displaySdoc();

//----------------------------------------------------------------------------------------------



class Admin :public User
{

public:
	Admin() 
	{
		type = 'A';
	}

	void Menu()
	{
		cout << "\tMenu for Admin : \n";
		User::Menu();
	}

	void login()
	{
		User::login();
		getObj(CNIC,password);

		if (loggedIn)
		{
			
			UserMainMenu();
		}
		else
		{
			cout << "\n\t\t   CNIC and Password donot match " << endl;
		}
	}
	void Register()
	{
		User::Register();

		getObj(CNIC, password);
		if (!(this->repeatCNIC))
		{
			storeobj("Admin", this);
			cout << "\n\t\t  Account Registered Successfully";
		}
		else if ((this->repeatCNIC))
			cout << "\n\t\t  Already Account Exist on this CNIC.\n";
	}
	
	void getObj(string cnic,string pass) {
		Admin temp;
		ifstream myFile("Admin", ios::binary);
		while (myFile.read((char*)&temp, sizeof(temp))) {
			if (matchstr(temp.CNIC, cnic.c_str()) && matchstr(temp.password, pass.c_str()))
			{
				myFile.close();
				*this = temp;
				loggedIn = 1;
			}
			else if (matchstr(temp.CNIC, cnic.c_str()))
			{
				myFile.close();
				this->repeatCNIC = 1;
			}
		}
	}

	void UserMainMenu()
	{
		cout << "\n\t\t   Welcome Admin " << Name << endl;
		int n = 0;
		cout << "\n\t\t    1.View Appointment ";
		cout << "\n\t\t    2.View All Doctors";
		cout << "\n\t\t    3.View Doctor Schedule";
		cout << "\n\t\t    0.Logout ";
		cout << "\n\n\t\t     >";
		cin >> n;
		if (n == 1)
		{
			Appointment temp;

			ifstream myFile("Appointment", ios::binary);

			while (myFile.read((char*)&temp, sizeof(temp)))
			{
				temp.Display();
			}
			myFile.close();
			UserMainMenu();
		}
		else if (n == 2)
		{
			displaydoc();
			UserMainMenu();
		}

		else if (n == 3)
		{
			displaySdoc();
			UserMainMenu();
		}
		else if (n == 0)
		{
			cout << endl << endl;
		}
		else
		{
			cout << "\n\t\t  Invalid Input. Try Again \n\n";
			UserMainMenu();
		}
	}

	~Admin(){}

};


//----------------------------------------------------------------------------------------------


class Doctor:public User
{
	char SpecArea[15];
	bool appslot[5][8];
	int rate;
	char City[15];
	int balance;
	double Rating;
public:
	static int RatingCount;
	Doctor(){
		type = 'D';
		SpecArea[0] = '\0';
		rate = 0;
		City[0] = '\0';
		for (int i = 0;i < 5;i++)
			for (int j = 0;j < 8;j++)
				appslot[i][j] = 0;
		balance = 0;
		Rating = 0;
	}

	void Menu()
	{
		cout << "\tMenu for Doctor : \n";
		User::Menu();
	}
	void login()
	{
		User::login();
		getObj(CNIC,password);

		if (this->loggedIn)
		{
			UserMainMenu();
		}
		else
		{
			cout << "\n\t\t   CNIC and Password donot match " << endl;
		}
	}
	void Register()
	{
		User::Register();
		getObj(CNIC, password);
		if (!(this->repeatCNIC))
		{
			cout << "\n\t  Enter Specialization Area : ";
			cin >> SpecArea;
			cout << "\t  Enter Your Rate per hour  : ";
			cin >> rate;
			cout << "\t  Enter Your City           : ";
			cin >> City;


			storeobj("Doctor", this);
			cout << "\n\t\t  Account Registered Successfully";
		}
		else if ((this->repeatCNIC))
			cout << "\n\t\t  Already Account Exist on this CNIC.\n";
	}
	char* getCity()
	{
		return City;
	}
	char* getSpec()
	{
		return SpecArea;
	}
	int getrate()
	{
		return rate;
	}
	void setrate(int n)
	{
		rate = n;
	}
	void setspec(string s)
	{
		strcpy_s(SpecArea, s.c_str());
	}
	void setRating(int r)
	{
		Rating = Rating * (RatingCount);
		RatingCount++;
		Rating += r;
		Rating /= RatingCount;
		
	}
	void setCity(string c)
	{
		strcpy_s(City, c.c_str());
	}
	void getObj(string cnic, string pass) 
	{
		Doctor temp;
		ifstream myFile("Doctor", ios::binary);

		while (myFile.read((char*)&temp, sizeof(temp)))
		{
			if (matchstr(temp.CNIC, cnic.c_str()) && matchstr(temp.password, pass.c_str()))
			{
				myFile.close();
				*this = temp;
				loggedIn = 1;
			}
			else if (matchstr(temp.CNIC, cnic.c_str()))
			{
				myFile.close();
				this->repeatCNIC = 1;
			}
		}
	}
	void setbalance(int b)
	{
		balance = b;
	}
	int getbalance()
	{
		return balance;
	}
	void UserMainMenu()
	{
		int n = 0;
		cout << "\n\t\t   Welcome Dr. " << Name << endl;
		cout << "\n\t\t    1.Account Details ";
		cout << "\n\t\t    2.Edit Profile Details ";
		cout << "\n\t\t    3.View Appointment ";
		cout << "\n\t\t    4.Edit Appointment Status";
		cout << "\n\t\t    5.Reply to Feedback";
		cout << "\n\t\t    0.Logout ";
		cout << "\n\n\t\t     >";
		cin >> n;
		if (n == 1)
		{
			this->Display();
			cout<< "\t\t\t  Balance         : " << balance << endl;
			cout<< "\t\t\t  Rating          : " << Rating << endl;
			cout<< "\t\t\t  Rate Per Hour   : " << rate << endl;
			cout<< "\t\t\t  Specialization  : " << SpecArea << endl;
			cout<< "\t\t\t  City            : " << City << endl<<endl;
			UserMainMenu();
		}
		else if (n == 2)
		{
			cout << "\n\t\t    Edit Profile Details ";
			cout << "\n\t\t\t    1.Edit Name";
			cout << "\n\t\t\t    2.Edit Username";
			cout << "\n\t\t\t    3.Edit Password";
			cout << "\n\t\t\t    4.Edit Location";
			cout << "\n\t\t\t    5.Edit Specialization";
			cout << "\n\t\t\t    6.Edit Rates";
			cout << "\n\t\t\t    0.Go Back";
			cout << "\n\n\t\t\t     >";
			cin >> n;
			if (n == 1)
			{
				string n;
				getline(cin, n);
				cout << "\n\t\t\t\t    Enter New Name : ";
				getline(cin, n);
				setName(n);
				cout << "\n\t\t\t\t    Name Changed Successfully";

			}
			else if (n == 2)
			{
				string n;
				cout << "\n\t\t\t\t    Enter New Username : ";
				cin >> n;
				setUsername(n);
				cout << "\n\t\t\t\t    Username Changed Successfully";

			}
			else if (n == 3)
			{
				string n, bp, temppas2;
				cout << "\t\t\t     Enter the Name of Your Birthplace : ";
				cin >> bp;
				if (matchstr(SecurityQ, bp.c_str()))
				{
					cout << "\n\t\t\t\t    Enter New Password : ";
					cin >> n;
					while (!(checkPassword(n)))
					{
						cout << "\n\t\t\t\t    Again Enter New Password : ";
						cin >> n;
					}

					cout << "\t\t\t\t    Re-Enter Your Password    : ";
					cin >> temppas2;


					while (!(matchstr(n.c_str(), temppas2.c_str())))
					{
						cout << "\n\t\t\t\t    Passwords Donot match with Eachother.";

						cout << "\n\t\t\t\t    Enter Your Password       : ";
						cin >> n;
						while (!checkPassword(n))
						{
							cout << "\n\t\t\t\t    Again Enter Your Password     : ";
							cin >> n;
						}
						cout << "\t\t\t\t    Re-Enter Your Password    : ";
						cin >> temppas2;
					}

					setPassword(n);

					cout << "\n\t\t\t\t    Password Changed Successfully";
				}
				else
					cout << "\n\t\t\t\t    Wrong Answer. Try Again.";

			}
			else if (n == 4)
			{
				string n;
				cout << "\n\t\t\t\t    Enter New City/Loction : ";
				cin >> n;
				setCity(n);
				cout << "\n\t\t\t\t    Location Changed Successfully";
			}
			else if (n == 5)
			{
				string n;
				cout << "\n\t\t\t\t    Enter New Specialization : ";
				cin >> n;
				setspec(n);
				cout << "\n\t\t\t\t    Specialization Changed Successfully";
			}
			else if (n == 6)
			{
				int n;
				cout << "\n\t\t\t\t    Enter New Rate Per Hour : ";
				cin >> n;
				setrate(n);
				cout << "\n\t\t\t\t    Rate Per Hour Changed Successfully";
			}
			else if (n == 0)
			{
				cout << endl << endl;
			}
			else
			{
				cout << "\n\t\t\t\t    Invalid Input. Try Again";
			}
			updateDoc(*this);
			UserMainMenu();
		}
		else if (n == 3)
		{
			displayDapp(this->CNIC);
			UserMainMenu();
		}
		else if (n == 4)
		{
			Appointment a;
			int time = 0, day = 0;
			displayDapp(this->CNIC);
			string str;
			cout << "\n\n\t\t\t   Enter the Patient CNIC : ";
			cin >> str;
			cout << "\n\t\t\t   Enter Starting time of Appointment : ";
			cin >> time;
			cout << "\n\t\t\t   Enter the Day of Appointment : ";
			cin >> day;
			a = searchApp(this->CNIC, time, day);
			cout << endl << endl;
			a.Display();
			cout << endl << endl;
			char ch='P';
			cout << "You Want to Approve(A)/Reject(R) : ";
			cin >> ch;
			a.setStatus(ch);

			updateApp(a, time, day);
			updateDoc(*this);

			UserMainMenu();
		}
		
		else if (n == 5)
		{
			feed(this->CNIC);
			UserMainMenu();
		}
		else if (n == 0)
		{
			cout << endl << endl;
		}
		else
		{
			cout << "\n\t\t  Invalid Input. Try Again \n\n";
			UserMainMenu();
		}
	}

	void miniInfo()
	{
		cout << "\n\t\t   "<< setw(22) << left << Name << setw(17) << City << setw(19) << SpecArea << setw(20) << CNIC<< setw(15) << rate<<Rating;
	}
	void Display_Sed()
	{
		cout << "\n\n\t\t\t     Doctor Name : " << Name;
		cout << "\n\t\t\t     Specialization :" << SpecArea;
		cout << "\n\n\t  Day/Time\t  9-10AM"<<setw(15)<<right << " 10-11AM"<<setw(12)<<" 11-12PM" << setw(13) << " 12-1PM " << setw(12) << " 1-2PM " << setw(13) << "2-3PM " << setw(14) << " 3-4PM " << setw(12) << " 4-5PM";
		
		for (int i = 0;i < 5;i++)
		{
			if (i == 0)
			{
				cout << "\n\n\t  09/06/2022\t";
			}
			else if(i==1)
				cout << "\n\t  10/06/2022\t";
			else if (i == 2)
				cout << "\n\t  11/06/2022\t";
			else if (i == 3)
				cout << "\n\t  12/06/2022\t";
			else if (i == 4)
				cout << "\n\t  13/06/2022\t";
			

			for (int j = 0;j < 8;j++)
			{
				if (!appslot[i][j])
					cout << " Available   ";
				else //if(appslot[i][j])
					cout << "  Booked     ";
			}

		}
		cout << endl;
	}
	void setAppBook(int i, int j)
	{
		appslot[i][j] = 1;
	}
	void setAppAvail(int i, int j)
	{
		appslot[i][j] = 0;
	}
	bool getapp(int i, int j)
	{
		return appslot[i][j];
	}

	~Doctor() {}
};

int Doctor::RatingCount = 0;

//----------------------------------------------------------------------------------------------

class Patient :public User
{
	Appointment* app;
	int balance;
	int i;
public:
	Patient() 
	{
		type = 'P';
		balance = 3500;
		i = 0;
	}

	void Menu()
	{
		cout << "\tMenu for Patient : \n";
		User::Menu();
	}
	void login()
	{
		User::login();
		
		getObj(CNIC,password);

		if (loggedIn)
		{
			UserMainMenu();
		}
		else
		{
			cout << "\n\t\t   CNIC and Password donot match " << endl;
		}
	}
	void Register()
	{
		User::Register();
		getObj(CNIC, password);

		if (!(this->repeatCNIC))
		{
			storeobj("Patient", this);
			cout << "\n\t\t  Account Registered Successfully";
			
		}
		else if ((this->repeatCNIC))
			cout << "\n\t\t  Already Account Exist on this CNIC.\n";
	}
	void getObj(string cnic,string pass) 
	{
		Patient temp;
		ifstream myFile("Patient", ios::binary);
		while (myFile.read((char*)&temp, sizeof(temp))) 
		{
			if (matchstr(temp.CNIC, cnic.c_str()) && matchstr(temp.password, pass.c_str()) )
			{
				//temp.getData();
				myFile.close();
				*this = temp;
				loggedIn = 1;
			}
			else if (matchstr(temp.CNIC, cnic.c_str()))
			{
				myFile.close();
				this->repeatCNIC = 1;
			}
		}
	}
	void setBalance(int b)
	{
		balance = b;
	}
	void UserMainMenu()
	{
		int n = 0;
		cout << "\n\n\t\t   Welcome " << Name << endl;
		cout << "\n\t\t    1.Account Details ";
		cout << "\n\t\t    2.Edit Profile Details ";
		cout << "\n\t\t    3.Book Appointment ";
		cout << "\n\t\t    4.Cancal Appointment ";
		cout << "\n\t\t    5.Update Appointment";
		cout << "\n\t\t    6.My Appointments ";
		cout << "\n\t\t    7.Recharge Account ";
		cout << "\n\t\t    8.Search Doctor ";
		cout << "\n\t\t    9.Complete Appointment ";
		cout << "\n\t\t    0.Logout ";
		cout << "\n\n\t\t     >";
		cin >> n;

		if (n == 1)
		{
			this->Display();
			cout << "\t\t\t  Balance       : "<<balance<<endl;
			UserMainMenu();
		}
		else if (n == 2)
		{
			cout << "\n\t\t    Edit Profile Details ";
			cout << "\n\t\t\t    1.Edit Name";
			cout << "\n\t\t\t    2.Edit Username";
			cout << "\n\t\t\t    3.Edit Password";
			cout << "\n\t\t\t    0.Go Back";
			cout << "\n\n\t\t\t     >";
			cin >> n;
			if (n == 1)
			{
				string n;
				getline(cin, n);
				cout << "\n\t\t\t\t    Enter New Name : ";
				getline(cin, n);
				setName(n);
				cout << "\n\t\t\t\t    Name Changed Successfully";
			
			}
			else if (n == 2)
			{
				char n[20];
				cout << "\n\t\t\t\t    Enter New Username : ";
				cin >> n;
				setUsername(n);
				cout << "\n\t\t\t\t    Username Changed Successfully";
				
			}
			else if (n == 3)
			{
				string n,bp,temppas2;
				cout << "\t\t\t     Enter the Name of Your Birthplace : ";
				cin >> bp;
				if (matchstr(SecurityQ, bp.c_str()))
				{
					cout << "\n\t\t\t\t    Enter New Password : ";
					cin >> n;
					while (!(checkPassword(n)))
					{
						cout << "\n\t\t\t\t    Again Enter New Password : ";
						cin >> n;
					}

					cout << "\t\t\t\t    Re-Enter Your Password    : ";
					cin >> temppas2;


					while (!(matchstr(n.c_str(), temppas2.c_str())))
					{
						cout << "\n\t\t\t\t    Passwords Donot match with Eachother.";

						cout << "\n\t\t\t\t    Enter Your Password       : ";
						cin >> n;
						while (!checkPassword(n))
						{
							cout << "\n\t\t\t\t    Again Enter Your Password     : ";
							cin >> n;
						}
						cout << "\t\t\t\t    Re-Enter Your Password    : ";
						cin >> temppas2;
					}
					
					setPassword(n);

					cout << "\n\t\t\t\t    Password Changed Successfully";
				}
				else
					cout << "\n\t\t\t\t    Wrong Answer. Try Again.";
				
			}
			else if (n == 0)
			{
				cout << endl << endl;
			}
			else
			{
				cout << "\n\t\t\t\t    Invalid Input. Try Again";
			}


			updatePatient(*this);
			UserMainMenu();
		}

		else if (n == 3)
		{
			int t = 0;
			app = new Appointment;
			cout << "\n\t\t    Book Appointment ";
			cout << "\n\t\t\t    1.In-Person Appointment ";
			cout << "\n\t\t\t    2.Video Appointment";
			cout << "\n\t\t\t    0.Go Back";
			cout << "\n\n\t\t\t     >";
			cin >> n;
			t = n;
			if (n == 1)
			{
				app->setMethod("In - person");
			}
			else if (n == 2)
			{
				app->setMethod("Video");
			}
			else if (n == 0)
			{
				cout << endl << endl;
			}
			else
			{
				cout << "\n\t\t\t\t    Invalid Input. Try Again";
				UserMainMenu();
			}
			
			bool a;
			cout << "\n\t\t\t\t     Search Doctor  by  ";
			cout << "\n\t\t\t\t     1.By City  ";
			cout << "\n\t\t\t\t     2.By Specialization  ";
			cout << "\n\t\t\t\t      > ";
			cin >> n;
			if (n == 1)
			{
				string city;
				cout << "\n\t\t\t\t      Enter the Name of City : ";
				cin >> city;
				cout << "\n\t\t\t   Name" << setw(23) << right << "City" << setw(21) << "SpecArea" << setw(24) << "CNIC" << setw(15) << "Rate";
				cout << endl;
				
				a = searchCity(city);
				if (a)
					cout << "\n\t\t\t\t   No Doctor Registered Yet";
			}
			else if (n == 2)
			{
				string spec;
				cout << "\n\t\t\t\t      Enter the Area Speaclization : ";
				cin >> spec;
				cout << "\n\t\t\t   Name" << setw(23) << right << "	City" << setw(21) << "Specialization" << setw(19) << "CNIC" << setw(18) << "Rate";
				cout << endl;
				a=searchSpec(spec);
				if (a)
					cout << "\n\t\t\t\t   No Doctor Registered Yet";
			}
			else
				UserMainMenu();
			if (!a)
			{
				string tcnic;
				cout << "\n\n\t\t\t   Enter the CNIC of Doctor For booking an Appointment : ";
				cin >> tcnic;

				Doctor doc;
				doc = getdoc(tcnic);

				doc.Display_Sed();
				int i, k;
				cout << "\n\n\t\t\t   Enter the Day you Want for Appointment : ";
				cout << "\n\t\t\t    1.09/06/2022";
				cout << "\n\t\t\t    2.10/06/2022";
				cout << "\n\t\t\t    3.11/06/2022";
				cout << "\n\t\t\t    4.12/06/2022";
				cout << "\n\t\t\t    5.13/06/2022";
				cout << "\n\n\t\t\t     >";
				cin >> i;



				cout << "\n\n\t\t\t    Enter the Time Limit : ";
				cout << "\n\t\t\t    1.9-10AM";
				cout << "\n\t\t\t    2.10-11AM";
				cout << "\n\t\t\t    3.11-12PM";
				cout << "\n\t\t\t    4.12-13PM";
				cout << "\n\t\t\t    5.13-14PM";
				cout << "\n\t\t\t    6.14-15PM";
				cout << "\n\t\t\t    7.15-16PM";
				cout << "\n\t\t\t    8.16-17PM";
				cout << "\n\n\t\t\t     >";
				cin >> k;

				if (doc.getapp(i - 1, k - 1))
					cout << "\n\t\t\t     This slot is not Available.\n\n";
				else
				{
					app->setBookdate(i + 8, 06, 2022);
					app->setBookHour(k + 8);
					doc.setAppBook(i - 1, k - 1);
					app->setDCNIC(tcnic);
					app->setDName(doc.getName());
					app->setPCNIC(this->CNIC);
					app->setPName(this->Name);
					if (t == 1)
					{
						app->setCharges(doc.getrate());
						setBalance(balance - doc.getrate());
					}
					else if (t == 2)
					{
						app->setCharges((doc.getrate()*(0.7)));
						setBalance(balance - (doc.getrate() * (0.7)));
					}
					cout << "\n\t\t\t\t    Fee Paid of Appointment";
					cout << "\n\t\t\t\t    Current Balance : "<<balance<<endl;

					storeapp(app);
					updateDoc(doc);
					updatePatient(*this);
					cout << "\t\t\t        Appoinment Added Successfully\n";
				}
			}
			UserMainMenu();
		}
		else if (n == 4)
		{

			Appointment a;
			string Dcnic;
			int time = 0, day = 0;
			displayPapp(this->CNIC);
			cout << "\n\t\t\t   Enter the CNIC of Doctor           : ";
			cin >> Dcnic;
			cout << "\n\t\t\t   Enter Starting time of Appointment : ";
			cin >> time;
			cout << "\n\t\t\t   Enter the Day of Appointment : ";
			cin >> day;
			a = searchApp(Dcnic, time, day);
			cout << endl << endl;
			a.Display();
			cout << endl << endl;
			Doctor doc;
			doc = getdoc(Dcnic);
			doc.setAppAvail(day - 9, time - 9);
			int d, m, y;
			cout << "\n\n\t\t\t   Enter the Date of cancalation : ";

			cout << "\n\n\t\t\t   Enter the Day   : ";
			cin >> d;
			cout << "\n\t\t\t   Enter the Month : ";
			cin >> m;
			cout << "\n\t\t\t   Enter the Year  : ";
			cin >> y;
			a.setCompdate(d, m, y);
			
			int charge = a.refundcharge(a.comapareDate());

			cout << "\n\n\t\t\t    Refund Amount : " << charge << endl;
			setBalance(balance + charge);
			cout << "\n\n\t\t\t    Your Current Balance : " << charge << endl;
			a.setStatus('R');

			deleteApp(a, time, day);
			updateDoc(doc);
			updatePatient(*this);

			cout << "\t\t\t        Appoinment Cancaled Successfully\n";


			UserMainMenu();
		}
		else if (n == 5)
		{

			Appointment a;
			string Dcnic;
			int time = 0, day = 0;
			displayPapp(this->CNIC);
			cout << "\n\t\t\t   Enter the CNIC of Doctor           : ";
			cin >> Dcnic;
			cout << "\n\t\t\t   Enter Starting time of Appointment : ";
			cin >> time;
			cout << "\n\t\t\t   Enter the Day of Appointment : ";
			cin >> day;
			a = searchApp(Dcnic, time, day);
			cout << endl << endl;
			a.Display();
			cout << endl << endl;

			Doctor doc;
			doc = getdoc(Dcnic);

			doc.Display_Sed();

			cout << "\n\t\t\t   Select New time for Appointment ";
			int i = 0, k = 0;
			cout << "\n\n\t\t\t   Enter the Day you Want for Appointment : ";
			cout << "\n\t\t\t    1.09/06/2022";
			cout << "\n\t\t\t    2.10/06/2022";
			cout << "\n\t\t\t    3.11/06/2022";
			cout << "\n\t\t\t    4.12/06/2022";
			cout << "\n\t\t\t    5.13/06/2022";
			cout << "\n\n\t\t\t     >";
			cin >> i;



			cout << "\n\n\t\t\t    Enter the Time Limit : ";
			cout << "\n\t\t\t    1.9-10AM";
			cout << "\n\t\t\t    2.10-11AM";
			cout << "\n\t\t\t    3.11-12PM";
			cout << "\n\t\t\t    4.12-13PM";
			cout << "\n\t\t\t    5.13-14PM";
			cout << "\n\t\t\t    6.14-15PM";
			cout << "\n\t\t\t    7.15-16PM";
			cout << "\n\t\t\t    8.16-17PM";
			cout << "\n\n\t\t\t     >";
			cin >> k;


			if (doc.getapp(i - 1, k - 1))
				cout << "\n\t\t\t     This slot is not Available.\n\n";
			else
			{

				doc.setAppAvail(day - 9, time - 9);
				a.setBookdate(i + 8, 06, 2022);
				a.setBookHour(k + 8);
				doc.setAppBook(i - 1, k - 1);
				updateApp(a, time, day);
				updateDoc(doc);
				updatePatient(*this);

				cout << "\t\t\t        Appoinment Edited Successfully\n";

			}


			UserMainMenu();
		}
		else if (n == 6)
		{
			if (1)
				displayPapp(this->CNIC);
			else
				cout << "No Appointment Created Yet";
			UserMainMenu();
		}
		else if (n == 7)
		{
			int bal;
			cout << "\n\t\t\t    Enter the Amount You want to insert : ";
			cin >> bal;
			setBalance(balance + bal);
			cout << "\n\t\t\t    Your Current Balance : "<<balance<<endl<<endl;
			UserMainMenu();
		}
		else if (n == 8)
		{
		cout << "\n\t\t\t\t     Search Doctor  by  ";
		cout << "\n\t\t\t\t     1.By City  ";
		cout << "\n\t\t\t\t     2.By Specialization  ";
		cout << "\n\t\t\t\t      > ";
		cin >> n;
		if (n == 1)
		{
			string city;
			cout << "\n\t\t\t\t      Enter the Name of City : ";
			cin >> city;
			cout << "\n\t\t\t   Name" << setw(23) << right << "City" << setw(21) << "SpecArea" << setw(24) << "CNIC" << setw(15) << "Rate";
			cout << endl;
			searchCity(city);
		}
		else if (n == 2)
		{
			string spec;
			cout << "\n\t\t\t\t      Enter the Area Speaclization : ";
			cin >> spec;
			cout << "\n\t\t\t   Name" << setw(23) << right << "City" << setw(21) << "SpecArea" << setw(24) << "CNIC" << setw(15) << "Rate";
			cout << endl;
			searchSpec(spec);
		}
			else
			{
				cout << "\n\t\t\t\t    Invalid Input. Try Again";
			}
			UserMainMenu();
		}
		else if (n == 9)
		{

		Appointment a;
		string Dcnic;
		int time = 0, day = 0;
		displayPapp(this->CNIC);
		cout << "\n\t\t\t   Enter the CNIC of Doctor           : ";
		cin >> Dcnic;
		cout << "\n\t\t\t   Enter Starting time of Appointment : ";
		cin >> time;
		cout << "\n\t\t\t   Enter the Day of Appointment : ";
		cin >> day;
		a = searchApp(Dcnic, time, day);
		cout << endl << endl;
		a.Display();
		cout << endl << endl;
		Doctor doc;
		doc = getdoc(Dcnic);
		doc.setAppAvail(day - 9, time - 9);

		cout << "\n\t\t\t   To Complete Appointment, Enter the complete Date : ";
		int d, m, y;

		cout << "\n\n\t\t\t   Enter the Day   : ";
		cin >> d;
		cout << "\t\t\t   Enter the Month : ";
		cin >> m;
		cout << "\t\t\t   Enter the Year  : ";
		cin >> y;
		a.setCompdate(d, m, y);
		int charge = a.extracharge(a.comapareDate());

		cout << "\n\n\t\t\t    Additional Fee for being Late : " << charge<<endl;
		if ((balance - charge) >= 0)
			setBalance(balance - charge);
		else
			cout << "\n\n\t\t\t    Not Enough Balance.";
		cout << "\n\n\t\t\t    Your Current Balance : " << balance << endl;
		a.setStatus('C');
		
		int r;
		cout << "\n\t\t\t\t  Doctor FeedBack ";
		while (1)
		{
		cout << "\n\t\t\t   Rating : ";
		cin >> r;
		if (r >= 0 && r <= 5)
			break;
		}

		a.getfeedback().setRating(r);
		string str;
		getline(cin, str);
		cout << "\n\t\t\t   Review : ";
		getline(cin,str);
		a.getfeedback().setReview(str);
		
		cout << "\n\n\t\t\t    Appointment Completed Successfully " << endl;

		UserMainMenu();
		}
		else if (n == 0)
		{
			cout << endl << endl;
		}
		else
		{
			cout << "Invalid Input. Try Again.\n";
			UserMainMenu();
		}

	}
	bool searchCity(string c)
	{
		Doctor temp;
		bool flag = 1;
		ifstream myFile("Doctor", ios::binary);

		while (myFile.read((char*)&temp, sizeof(temp)))
		{
			if (matchstr(temp.getCity(), c.c_str()))
			{
				flag = 0;
				temp.miniInfo();
			}

		}
		myFile.close();
		return flag;
	}
	bool searchSpec(string s)
	{
		Doctor temp;
		bool flag = 1;
		ifstream myFile("Doctor", ios::binary);

		while (myFile.read((char*)&temp, sizeof(temp)))
		{
			if (matchstr(temp.getSpec(), s.c_str()))
			{
				flag = 0;
				temp.miniInfo();
			}

		}
		myFile.close();
		return flag;
	}

	~Patient () {}
};

//----------------------------------------------------------------------------------------------

void storeapp(Appointment* app)
{
	
	ofstream myFile("Appointment", ios::binary | ios::app); 
	myFile.write((char*)app, sizeof(Appointment));

	myFile.close();
}

void displayDapp(string dcnic)
{
	Appointment temp;

	ifstream myFile("Appointment", ios::binary);

	while (myFile.read((char*)&temp, sizeof(temp)))
	{
		if (matchstr(temp.getDCNIC(), dcnic.c_str()))
		{
			temp.Display();
		}

	}
	myFile.close();
}

void displayPapp(string pcnic)
{
	Appointment temp;

	ifstream myFile("Appointment", ios::binary);

	while (myFile.read((char*)&temp, sizeof(temp)))
	{
		if (matchstr(temp.getPCNIC(), pcnic.c_str()))
		{
			temp.Display();
		}

	}
	myFile.close();
}

void storeobj(string fileName, User* obj)
{
	char ch =obj->getType();
	int size=0;
	if (ch == 'P')
		size = sizeof(Patient);
	else if( ch == 'D')
		size = sizeof(Doctor);
	else if (ch == 'A')
		size = sizeof(Admin);
	ofstream myFile(fileName, ios::binary | ios::app); // 
	myFile.write((char*)obj, size);
	
	myFile.close();
	
}

Doctor getdoc(string tcnic)
{
	Doctor temp;

	ifstream myFile("Doctor", ios::binary);

	while (myFile.read((char*)&temp, sizeof(temp)))
	{
		if (matchstr(temp.getCNIC(), tcnic.c_str()))
		{
			myFile.close();
			return temp;
		}
		
	}
}

Patient getPat(string tcnic)
{
	Patient temp;

	ifstream myFile("Patient", ios::binary);

	while (myFile.read((char*)&temp, sizeof(temp)))
	{
		if (matchstr(temp.getCNIC(), tcnic.c_str()))
		{
			myFile.close();
			return temp;
		}

	}
}

void updatePatient(Patient t)
{
	Patient temp;

	fstream myfile("Patient", ios::in | ios::out | ios::binary);

	while (myfile.read((char*)&temp, sizeof(temp)))
	{
		if (matchstr(temp.getCNIC(), t.getCNIC()))
		{
			int current = myfile.tellg();
			int oneblock = sizeof(temp);
			myfile.seekg(current - oneblock);
			temp = t;
			myfile.write((char*)&temp, sizeof(temp));

			myfile.close();

		}
	}
}

void updateDoc(Doctor t)
{
	Doctor temp;

	fstream myfile("Doctor", ios::in | ios::out | ios::binary);

	while (myfile.read((char*)&temp, sizeof(temp)))
	{
		if (matchstr(temp.getCNIC(), t.getCNIC()))
		{
			int current = myfile.tellg();
			int oneblock = sizeof(temp);
			myfile.seekg(current - oneblock);
			temp = t;
			myfile.write((char*)&temp, sizeof(temp));

			myfile.close();

		}
	}
}

void feed(string tcnic)
{
	Appointment temp;

	fstream myFile("Appointment",ios::in| ios::out| ios::binary);
	string str;
	while (myFile.read((char*)&temp, sizeof(temp)))
	{
		if (temp.getStatus() == 'C')
		{
			cout << "\n\t\t\t Rating : " << temp.getfeedback().getRating();
			cout << "\n\t\t\t Review :" << temp.getfeedback().getReview();
			cout << "\n\n\t\t\t Enter Your Comment on this Feedback : ";
			cin >> str;
			temp.getfeedback().setcomment(str);
			cout << "\n\t\t\t    Replied Successfully \n\n";
		}

	}
	myFile.close();
}

Appointment searchApp(string Dcnic,int time,int day)
{
	Appointment temp;

	ifstream myFile("Appointment", ios::binary);

	while (myFile.read((char*)&temp, sizeof(temp)))
	{
		if (matchstr(temp.getDCNIC(), Dcnic.c_str()) && temp.getBookHour()==time && temp.getBookDay()==day)
		{
			myFile.close();
			return temp;
		}

	}
	
}

void updateApp(Appointment t,int time, int day)
{
	Appointment temp;

	fstream myfile("Appointment", ios::in | ios::out | ios::binary);

	while (myfile.read((char*)&temp, sizeof(temp)))
	{
		if (matchstr(temp.getDCNIC(), t.getDCNIC()) && temp.getBookHour() == time && temp.getBookDay() == day)
		{
			int current = myfile.tellg();
			int oneblock = sizeof(temp);
			myfile.seekg(current - oneblock);
			temp = t;
			myfile.write((char*)&temp, sizeof(temp));

			myfile.close();

		}
	}
}

void deleteApp(Appointment t, int time, int day)
{
	Appointment temp;

	fstream myfile("Appointment", ios::in | ios::out | ios::binary);
	ofstream myFile_temp("temp", ios::app | ios::binary);

	while (myfile.read((char*)&temp, sizeof(temp)))
	{
		if (!(matchstr(temp.getDCNIC(), t.getDCNIC()) && temp.getBookHour() == time && temp.getBookDay() == day))
		{
			myFile_temp.write((char*)&temp, sizeof(temp));
		}
	}
	myfile.close();
	myFile_temp.close();
	remove("Appointment");
	rename("temp", "Appointment");
}

void displaydoc()
{
	User* temp=NULL;

	ifstream myFile("Doctor", ios::binary);

	while (myFile.read((char*)temp, sizeof(Doctor)))
	{
		temp->Display();
	}
	myFile.close();

	
}

void displaySdoc()
{
	User* temp=NULL;

	ifstream myFile("Doctor", ios::binary);

	while (myFile.read((char*)temp, sizeof(Doctor)))
	{
		temp->Display_Sed();
	}
	myFile.close();

	
}