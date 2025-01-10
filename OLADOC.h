
#include"USER.h"

class OLADOC
{
	User* user;
	Admin admin;
public:
	OLADOC();
	void MainMenu();

};

OLADOC::OLADOC()
{
	cout << "\n\n   ----------| Welcome TO OLADOC |----------\n";
	cout << endl;
	MainMenu();
}
void OLADOC::MainMenu()
{

	int n = 0;
	cout << "\n MAIN MENU : \n";
	cout << "  1.Doctor\n  2.Patient\n  3.Admin\n\n";
	cout << " Select Your Type : ";
	cin >> n;
	if (n == 1)
	{
		cout << endl;
		user = new Doctor;
		user->Menu();
		cout << "\n\n-------------------------------------------------------------------------\n";
		MainMenu();
	}
	else if (n == 2)
	{
		cout << endl;
		user = new Patient;
		user->Menu();
		cout << "\n\n-------------------------------------------------------------------------\n";
		MainMenu();
	}
	else if (n == 3)
	{
		cout << endl;
		user = new Admin;
		//user = &admin;
		user->Menu();
		//cout << "  Oladoc is Digital Healthcare Platform in Pakistan. You can easily find doctors around you. ";
		cout << "\n\n-------------------------------------------------------------------------\n";
		MainMenu();
	}
	else
	{
		cout << "\nInvalid Input. Please Try again.";
		cout << "\n\n-------------------------------------------------------------------------\n";
		MainMenu();
	}
}



