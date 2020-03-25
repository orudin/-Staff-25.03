#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct sutrydnicu {
	string famili;
	string name;
	int age;
	string zarplata;

};

fstream infile;

void addSutrydnik(sutrydnicu *arr, int b) {
	cout << "Enter employee famili" << endl;
	cin >> arr[b].famili;
	cout << "Enter employee name" << endl;
	cin >> arr[b].name;
	cout << "Enter employee age" << endl;
	cin >> arr[b].age;
	cout << "Enter employee salary" << endl;
	cin >> arr[b].zarplata;
}
void menu() {
	cout << "  Enter new employee press\t1" << endl;
	cout << "  Employee Removal Press\t2" << endl;
	cout << "  Search for employee press\t3" << endl;
	cout << "  Output all employees press\t4" << endl;
	cout << "  Save changes to file, press\t5" << endl;
	cout << "  Editing employee data Press\t6" << endl;
	cout << "  To exit, press\t\t9" << endl;
	cout << endl << endl;

}
void save(sutrydnicu* arr, int b) {
	infile.open("if.txt", fstream::in | fstream::out | fstream::app);
	for (int i = 0; i < b; i++)
		infile << arr[i].famili << " " << arr[i].name << " " << arr[i].age << " " << arr[i].zarplata << endl;
	cout << "Workers are saved" << endl<<endl;
}

sutrydnicu* Add(sutrydnicu* arr, int b)
{
	if (b == 0)
	{
		arr = new sutrydnicu[b + 1]; 
	}
	else
	{
		sutrydnicu* temp = new sutrydnicu[b + 1];

		for (int i = 0; i < b; i++)
		{
			temp[i] = arr[i];
		}
		delete[] arr;
		arr = temp;
	}
	return arr;
}

void vuvid(sutrydnicu* arre, int b) {
	cout << endl;
	cout << "Staff:" << endl << endl;
	for (int i = 0; i < b; i++)
	{
		cout << arre[i].famili << " " << arre[i].name << " " << arre[i].age << " " << arre[i].zarplata << endl;
	}
	cout << endl;
	menu();

}
void redaguvaty(sutrydnicu* arre) {
	
	int p;
	int pos2;
	cout << "\n\tWhich account do you want to edit?" << endl;
	cin >> pos2;
	pos2 -= 1;
	cout << "\nWhich parameter do you want to change?\n";
	cout << "1  Surname\n"
		<< "2  Name\n"
		<< "3  Age\n"
		<< "4  Salary\n";
	cin >> p;
	switch (p)
	{


	case 1: {
		cout << "Enter new  famili" << endl;
		cin >> arre[pos2].famili;
		break;
	}
	case 2: {
		cout << "Enter new name" << endl;
		cin >> arre[pos2].name;
		break;
	}
	case 3: {
		cout << "Enter new age" << endl;
		cin >> arre[pos2].age;
		break;
	}
	case 4: {
		cout << "Enter new Salary" << endl;
		cin >> arre[pos2].zarplata;
		break;
	}
	default: cout << "Wrong number" << endl;
		break;
	}


	menu();
}

int  main()
{
	int b = 0;
	int a = 0;
	sutrydnicu* arre = 0;
	int YesOrNot = 0;
	string fg= " ";
	bool ft = true;
	bool ft1 = true;
	bool ft2 = true;
	int age2;
	int k = 0;
	int pos;

	infile.open("if.txt", fstream::in | fstream::out | fstream::app);

	while (!infile.eof()) {
		
		if (ft) {
			arre = Add(arre, b);
			infile >> fg;
			arre[b].famili = fg;
			ft = false;
		}
		else if(ft1){
			infile >> fg;
			arre[b].name = fg;
			ft1 = false;
			
		}
		else if(ft2){
			infile >> age2;
			arre[b].age = age2;
			ft2 = false;

		}
		else   {
			infile >> fg;
			arre[b].zarplata = fg;
			ft = true;
			ft1 = true;
			ft2 = true;
			b++;

		}
	
	}
	
	sutrydnicu* Add(sutrydnicu * arr, int b);

	
	int vb = 0;

	if (!infile.is_open())
	{
		cout << "ERRoR File" << endl;
	}
	else
	{
		for (int i = 0; i < b; i++)
		{
			infile >> arre[i].famili >> arre[i].name >> arre[i].age >> arre[i].zarplata;
		}
		infile.close();
	}
	menu();
	while (a != 9)
	{
		cin >> a;
		switch (a)
		{
		case 9: { break; }
		case 1:
		{
			do
			{
				arre = Add(arre, b);
				addSutrydnik(arre, b);
				b++;
				cout << "Continue data entry (1 - yes, 0 - no): ";
				cin >> YesOrNot;
				cin.get();
			} while (YesOrNot != 0);

			cout << "Employee recorded, can save changes to file (5)" << endl << endl;
			menu();
			break;
		}

		case 2: {
			cout << "Enter posiziu ";
			cin >> pos;
			pos -= 1;
			for (int i = pos; i < b - 1; i++) 
			{
				arre[i] = arre[i + 1]; 
			}

			b--;
			vuvid(arre, b);
			break;
		}

		case 3: {
			cout << "Search by last name press 1" << endl;
			cout << "Search by age press 2 " << endl;
			cin >> vb;
			switch (vb)
			{
				
			case 1:{
				string fy;
				cout << "Vvedite Famaly:";
				cin >> fy;
				cout << endl << endl;
				for (int i = 0; i < b; i++)
					if (arre[i].famili == fy)
					{
						cout << "Famaly: " << arre[i].famili << endl;
						cout << "Name: " << arre[i].name << endl;
						cout << "Zarplata: " << arre[i].zarplata << endl;
					}
				cout << endl << endl;

				break;
			}
			case 2: {
				
				int age1;
				cout << "Vvedite vozrast: ";
				cin >> age1;
				cout << endl << endl;
				for (int i = 0; i < b; i++)
					if (arre[i].age == age1)
					{
						cout << "Name: " << arre[i].name << endl;
					}
				cout << endl << endl;
				break;
			}	
			}
			menu();
			break;
		}
		case 4:
		{
			cout << endl;
			vuvid(arre, b);
			break;
		}
		case 5:
		{
			save(arre, b);
			menu();
			break;
		}
		case 6: {
			redaguvaty(arre);
			break;
		}

		default: cout << "Wrong number" << endl << endl;
			break;
		}
	}
	infile.close();
	return 0;
}
