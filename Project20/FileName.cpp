#include <iostream>
#include<fstream>
#include<string>
#include<stdlib.h>
using namespace std;
////////////////////////function///////////////
void signup();
void login();
void forget();
void edit_data();
////////////////////////
void patient();
void show_specialties();
void search();
void searchofdoctor();
void searchofspeciality();
void viewdoctor();
void edit_appointment();
/////////////////
void doctordata();
////////////////////
void changeprice(int);
void doctor();
void addtime(int);
void edit_time(int);
void removetime(int);
void show_your_data();
void viewpatients(int);
void edit_appointment();
void clear_history();
//////////////////////////////////////////////



////////////////////////////file of patient//////////////////
struct patients
{
	string username;
	string password;
	int age;

}
patientdata[100];

int readfile(patients patientdata[])
{

	ifstream f;
	f.open("txst.txt");
	int sz;
	f >> sz;
	for (int i = 0; i < sz; i++)
	{
		f >> patientdata[i].username;
		f >> patientdata[i].password;
		f >> patientdata[i].age;


	}
	return sz;
}
void writefile(patients patientdata[], int sz) {

	ofstream f;
	f.open("txst.txt");
	f << sz << endl;
	for (int i = 0; i < sz; i++)
	{
		f << patientdata[i].username << endl;
		f << patientdata[i].password << endl;
		f << patientdata[i].age << endl;

	}

}
//////////////////////////////////////file of doctor/////////////////////////
struct doctors
{
	int len_t1, len_t2;
	string username;
	string password;
	int age;
	int do_num;
	string do_name;
	string doc_speciality;
	string doc_time1[10];
	string doc_time2[10];
	int doc_price;

}doc[100];
int readfile_doc(doctors doc[])
{

	ifstream r;
	r.open("txst1.txt");
	int sz1;
	r >> sz1;
	for (int i = 0; i < sz1; i++)
	{
		r >> doc[i].len_t1;
		r >> doc[i].len_t2;
		r >> doc[i].username;
		r >> doc[i].password;
		r >> doc[i].age;
		r >> doc[i].do_num;
		r >> doc[i].do_name;
		r >> doc[i].doc_speciality;
		for (int j = 0; j < doc[i].len_t1; j++)
		{
			r >> doc[i].doc_time1[j];
		}
		for (int j = 0; j < doc[i].len_t2; j++)
		{
			r >> doc[i].doc_time2[j];
		}
		r >> doc[i].doc_price;


	}
	return sz1;
}
void writefile_doc(doctors doctor[], int sz1) {

	ofstream r;
	r.open("txst1.txt");
	r << sz1 << endl;




	for (int i = 0; i < sz1; i++)
	{
		r << doc[i].len_t1 << "\t";
		r << doc[i].len_t2 << endl;
		r << doc[i].username << endl;
		r << doc[i].password << endl;
		r << doc[i].age << endl;
		r << doc[i].do_num << endl;
		r << doc[i].do_name << endl;
		r << doc[i].doc_speciality << endl;

		for (int j = 0; j < doc[i].len_t1; j++)
		{
			r << doc[i].doc_time1[j] << endl;

		}
		for (int j = 0; j < doc[i].len_t2; j++)
		{
			r << doc[i].doc_time2[j] << endl;

		}
		r << doc[i].doc_price << endl;


	}
}
///////////////////////////////file of booking///////////////////////////
struct patient_ap
{
	string _name_doctor;
	string _username_patient;
	string day;
	string time;

}_patient_data[100];

int readfile_ap(patient_ap _patient_data[])
{

	ifstream m;
	m.open("txst2.txt");
	int sz2;
	m >> sz2;
	for (int i = 0; i < sz2; i++)
	{
		m >> _patient_data[i]._name_doctor;
		m >> _patient_data[i]._username_patient;
		m >> _patient_data[i].day;
		m >> _patient_data[i].time;


	}
	return sz2;
}
void writefile_ap(patient_ap _patient_data[], int sz2) {

	ofstream m;
	m.open("txst2.txt");
	m << sz2 << endl;
	for (int i = 0; i < sz2; i++)
	{
		m << _patient_data[i]._name_doctor << endl;
		m << _patient_data[i]._username_patient << endl;
		m << _patient_data[i].day << endl;
		m << _patient_data[i].time << endl;


	}

}
//////////////////////////////////

string specialty[30] = {
	"Dentistry","Dermatology","Psychiatry","PediatritricsandNewBorn","Neurology",
	"Gynaecologyandinfertility","Orthopedics","Ear,NoseandThroat","CardiologyandVascularDisease",
	 "Ophthalmology","InternalMedicine"
};
/////////////////////////////////
int show_sp = 11;
bool tm;
int choose_doc;
int choose_day, choose_time;
int choisedoing2;
string update;
patients arr[200];
patient_ap arr2[200];
int len, len1, len2;
string username_pat;

int main()
{
	len = readfile(arr);
	len1 = readfile_doc(doc);
	len2 = readfile_ap(arr2);
	doctordata();
	int choice1;

	arr2[5].day = "today"; arr2[5].time = "3:4 pm"; arr2[5]._name_doctor = "doctoremantantawy";
		
	cout << "__" << endl;
	cout << "welcome to our vezeeta website" << endl;
	cout << "we offer you the best treatments with amazing offers" << endl;
	cout << "__" << endl;
	cout << " sign up???...... press 1" << endl;
	cout << "__ " << endl;
	cout << "login??....... press 2" << endl;
	cout << "__" << endl;
	cout << "forgot your pass??.....press 3" << endl;
	cout << "__" << endl;
	cout << "edit your username , password or age.......press 4" << endl;

	cin >> choice1;
	switch (choice1)
	{
	case 1:
		signup();
		break;
	case 2:
		login();
		break;
	case 3:
		forget();
		break;
	case 4:
		edit_data();
		break;
	default:
		cout << "sorry, wrong answer" << endl;

	}


	writefile(arr, len);
	writefile_doc(doc, len1);
	writefile_ap(arr2, len2);

	return 0;
}

void signup()
{
	int c;

	cout << "choose 1 for doctor and 2 for patient\n";
	cin >> c;
	switch (c)
	{
	case 1:
	{
		doc[len1].len_t1 = 5;
		doc[len1].len_t2 = 5;

		cout << "enter the username" << endl;
		cin >> doc[len1].username;
		cout << "create your pass" << endl;
		cin >> doc[len1].password;
		cout << "enter your age " << endl;
		cin >> doc[len1].age;
		doc[len1].do_num = doc[len1 - 1].do_num + 1;
		cout << "enter your name" << endl;
		cin >> doc[len1].do_name;
		cout << "enter your specialty" << endl;
		cin >> doc[len1].doc_speciality;
		cout << "enter the appropriate time" << endl;
		cout << "(1)Today\n";
		doc[len1].doc_time1[0] = "(1)Today";
		for (int i = 1; i < 5; i++)
		{
			cin >> doc[len1].doc_time1[i];
		}
		cout << "(2)Tomorrow\n";
		doc[len1].doc_time2[0] = "(2)Tomorrow";
		for (int i = 1; i < 5; i++)
		{
			cin >> doc[len1].doc_time2[i];
		}

		cout << "enter the price" << endl;
		cin >> doc[len1].doc_price;
		len1++;
		cout << "succesful registration as doctor\n";

		doctor();
		break;
	}
	case 2:
	{


		cout << "enter the username" << endl;
		cin >> arr[len].username;
		cout << "create your pass" << endl;
		cin >> arr[len].password;
		cout << "enter your age\n ";
		cin >> arr[len].age;

		len++;
		cout << "succesful registration\n";
		cout << "enter to continue ....";

		username_pat = arr[len].username;
		cin.get();
		system("cls");

		patient();


	}


	}
}

void login()
{
	string username, password;
	int age;
	cout << "enter your username" << endl;
	cin >> username;
	cout << "enter your password" << endl;
	cin >> password;
	cout << "Enter your age" << endl;
	cin >> age;
	bool flag = false;

	int i;
	for (i = 0; i < len; i++)
	{
		if (arr[i].username == username && arr[i].password == password && arr[i].age == age)

			break;
	}
	if (i == len)
	{

		for (i = 0; i < len1; i++)
		{
			if (doc[i].username == username && doc[i].password == password && doc[i].age == age)
			{
				flag = true;
				int n_of_index = i;
				break;

			}

		}

		if (flag == true)
		{
			cout << "successful registration as doctor" << endl;
			cin.get();
			cin.get();
			doctor();
		}
		else
		{
			cout << "not found  !" << endl;
			main();
		}

	}
	else

	{
		username_pat = username;
		cout << "successful registration as patient" << endl;
		cin.get();
		cin.get();
		patient();
	}


}

void forget()
{
	int no;


	cout << "__" << endl;
	cout << "for searching by username press 1";

	cout << "__" << endl;
	cout << "for searching by password press 2";

	cout << "__" << endl;
	cout << "for going back to menu press 3";
	cin >> no;
	switch (no)
	{
	case 1:
	{


		string search;
		cout << "enter the last remembered username" << endl;;
		cin >> search;
		int i;
		for (i = 0; i < len; i++)
		{
			if (arr[i].username == search)
			{

				break;
			}
		}
		if (i == len)
		{

			for (i = 0; i < len1; i++)
			{
				if (doc[i].username == search)
				{

					break;

				}

			}

			if (i == len1)
			{
				cout << "notfound" << endl;
				cin.get();
				main();

			}
			else
			{
				cout << "found!" << endl;
				cout << doc[i].password << "  " << i;
				cin.get();
				cin.get();
				doctor();

			}

		}
		else

		{
			cout << "found" << endl;
			cout << arr[i].password;
			username_pat = search;
			cin.get();
			cin.get();
			patient();
		}



		break;
	}
	case 2:
	{

		string search2;
		cout << "enter your remembered password" << endl;
		cin >> search2;

		int i;
		for (i = 0; i < len; i++)
		{
			if (arr[i].password == search2)
			{

				break;
			}
		}
		if (i == len)
		{

			for (i = 0; i < len1; i++)
			{
				if (doc[i].password == search2)
				{

					break;

				}

			}

			if (i == len1)
			{
				cout << "notfound" << endl;
				cin.get();
				main();

			}
			else
			{
				cout << "found!" << endl;
				cout << doc[i].username;
				cin.get();
				cin.get();
				doctor();

			}

		}
		else

		{
			cout << "found" << endl;
			cout << arr[i].username;
			username_pat = arr[i].username;
			cin.get();
			cin.get();
			patient();
		}








		break;
	}
	case 3:
	{main();
	break;
	}
	default:
	{
		cout << "error.....press any key to try again" << endl;
		cin.get();
		cin.get();
		forget();


	}

	}
}

void edit_data()
{
	string new_username, new_password;
	int  new_age;




	string old_username, old_password;
	int old_age;
	cout << "enter your username" << endl;;
	cin >> old_username;
	cout << "enter your Password" << endl;
	cin >> old_password;
	cout << "enter your age\n";
	cin >> old_age;
	int i;
	for (i = 0; i < len; i++)
	{
		if (arr[i].username == old_username && arr[i].password == old_password && arr[i].age == old_age)
		{

			break;
		}
	}
	if (i == len)
	{

		for (i = 0; i < len1; i++)
		{
			if (doc[i].username == old_username && doc[i].password == old_password && doc[i].age == old_age)
			{

				break;

			}

		}

		if (i == len1)
		{
			cout << "notfound" << endl;
			cin.get();
			main();

		}
		else
		{
			cout << "found!" << endl;
			cout << "enter the new username\n";
			cin >> new_username;
			doc[i].username = new_username;
			cout << "enter the new password\n";
			cin >> new_password;
			doc[i].password = new_password;
			cout << "enter the new age\n";
			cin >> new_age;
			doc[i].age = new_age;
			cout << "Enter your specialization: " << endl;
			cin >> doc[i].doc_speciality;
			cin.get();
			cin.get();
			doctor();

		}

	}
	else

	{
		cout << "found" << endl;
		cout << "enter the new username\n";
		cin >> new_username;
		arr[i].username = new_username;
		cout << "enter the new password\n";
		cin >> new_password;
		arr[i].password = new_password;
		cout << "enter the new age\n";
		cin >> new_age;
		arr[i].age = new_age;
		username_pat = new_username;
		cin.get();
		cin.get();
		patient();
	}






}
/////////////////////////////////////////////
void patient()
{
	system("cls");
	cout << "--------------------------------------Vezeeta Systeam-------------------------------------\n"
		"\n------------------Enter to open-------------------\n";
	cin.get();



	cout << "--------------\n";
	cout << "Welcome " << "\n";
	cout << "What you can do:\n";
	cout << "1-Show Specialties \n";
	cout << "2-Search for speciality or doctor\n";
	cout << "3-show doctors with booking\n";
	cout << "4_edit appointment\n";
	cout << "5-clear appointments history\n";
		cout << "6-Exit the program\n";
	int choice_doing;
	cout << "--------------\n";
	cin >> choice_doing;
	cout << "--------------\n";
	switch (choice_doing)
	{
	case 1:
		show_specialties();
		break;

	case 2:
		search();
		break;

	case 3:
		viewdoctor();
		break;
	case 4:
		edit_appointment();
		break;
	case 5:
		clear_history();
		break;
	default :
		cout << "error___invailde num\n";
		getchar();
		patient();
	}
}

void show_specialties()
{


	do {

		for (int i = 0; i < show_sp; i++)
		{
			cout << i + 1 << "- " << specialty[i] << "\n";
		}
		cout << "--------------\n";
		cout << "You can do:\n"
			"1-Choose speciality \n"
			"2-Exit the program\n";

		cout << "--------------\n";
		cin >> choisedoing2;

		cout << "--------------\n";
		if (choisedoing2 == 2)
			continue;
		switch (choisedoing2)
	case 1:

		cout << "Choose the number of speciality\n";
		int number_specia;
		cout << "--------------\n";
		cin >> number_specia;
		cout << "--------------\n";
		system("cls");
		cout << number_specia << "- " << specialty[number_specia - 1] << "\n";
		cout << "--------------\n";


		do {
			tm = true;
			for (int i = 0; i < len1; i++)
			{


				if (doc[i].doc_speciality == specialty[number_specia - 1])
				{
					cout << doc[i].do_num << "- " << doc[i].do_name << endl
						<< doc[i].doc_speciality << endl;
					for (int j = 0; j < doc[i].len_t1; j++)
					{
						cout << doc[i].doc_time1[j] << endl;
					}

					cout << "--------------\n";
					for (int j = 0; j < doc[i].len_t2; j++)
					{
						cout << doc[i].doc_time2[j] << endl;

					}
					cout << "--------------------------\n";
					cout << "price = " << doc[i].doc_price << endl;
					cout << "------------------------------------------------------------------\n";

				}

			}


			cout << "Choose a doctor\n";
			cout << "--------------\n";
			cin >> choose_doc;
			cout << "--------------\n";
			cout << "Chosse the day";
			cout << "--------------\n";
			cin >> choose_day;
			cout << "--------------\n";
			cout << "Choose the appropriate time\n";
			cout << "--------------\n";
			cin >> choose_time;
			cout << "--------------\n";

			if (choose_day == 1 && doc[choose_doc - 1].doc_time1[choose_time] != "0")

			{
				cout << "Your booking is confirm\n"
					<< "--------------\n"
					<< "\n------------------------------------\n";

				arr2[len2]._name_doctor = doc[choose_doc - 1].do_name;
				arr2[len2]._username_patient = username_pat;
				arr2[len2].day = doc[choose_doc - 1].doc_time1[0];
				arr2[len2].time = doc[choose_doc - 1].doc_time1[choose_time];
				len2++;
				cout << "you can do:\n"
					"1 - show speciality again \n"
					"2-Exit the program\n";
				cout << "--------------\n";
				cin >> choisedoing2;
				cout << "--------------\n";
			}
			else if (choose_day == 2 && doc[choose_doc].doc_time2[choose_time] != "0")
			{
				cout << "Your booking is confirm\n"
					<< "--------------\n"
					<< "\n------------------------------------\n";
				arr2[len2]._name_doctor = doc[choose_doc - 1].do_name;
				arr2[len2]._username_patient = username_pat;
				arr2[len2].day = doc[choose_doc - 1].doc_time2[0];
				arr2[len2].time = doc[choose_doc - 1].doc_time2[choose_time];
				len2++;

				cout << "you can do:\n"
					"1 - show speciality again \n"
					"2-Exit the program\n";
				cout << "--------------\n";
				cin >> choisedoing2;
				cout << "--------------\n";
			}


			else
			{
				cout << "This time is not available\n"
					"Choose another time\n";
				cout << "\n----------------------------\n";
				tm = false;
			}
			for (int i = 0; i < len1; i++)
			{
				if (doc[i].do_num == choose_doc && choose_day == 1)
				{
					doc[i].doc_time1[choose_time] = "0";


				}
				else if (doc[i].do_num == choose_doc && choose_day == 2)
				{
					doc[i].doc_time2[choose_time] = "0";

				}


			}
		} while (tm == false);



	} while (choisedoing2 != 2);


}

void viewdoctor()
{
	int c, c_delete, c_choice;
	cout << "doctors with your booking\n";
	for (int j = 0; j < len2; j++) {
		if (arr2[j]._username_patient == username_pat)
		{
			cout << j << "-" << arr2[j]._name_doctor << endl << arr2[j].day << endl << arr2[j].time << endl;

		}

	}
	cout << "to edit appointments ....press 1\n";
	cout << "to delete appointments.....press 2\n";
	cout << "to clear appointments history....press 3\n";
	cin >> c;
	switch (c)
	{
	case 1:
	{
		edit_appointment();
	}
	case 2:
	{
		do {
			cout << " choice the number of data you want to remove\n";
			cin >> c_delete;
			arr2[c_delete]._name_doctor.clear();
			arr2[c_delete]._username_patient.clear();
			arr2[c_delete].day.clear();
			arr2[c_delete].time.clear();
			cout << "if you want to remove data again.....press 1\n";
			cout << "if you want to the list ... press 2\n";
			cin >> c_choice;
		} while (c_choice == 1);
		break;
	}
	case 3:
		clear_history();
		break;
	}
	cin.get();
	cin.get();
	system("cls");
	patient();

}

void doctordata()
{
	doc[0].len_t1 = 5;
	doc[0].len_t2 = 5;
	doc[0].username = "eman";
	doc[0].password = "1";
	doc[0].age = 40;
	doc[0].do_num = 1;
	doc[0].do_name = "DoctorEmanTantawy";
	doc[0].doc_speciality = "Dentistry";
	doc[0].doc_time1[0] = "(1)Today";
	doc[0].doc_time1[1] = "1-10:30A.M";
	doc[0].doc_time1[2] = "2-12:00P.M";
	doc[0].doc_time1[3] = "3-10:30A.M";
	doc[0].doc_time1[4] = "4-1:00P.M";
	doc[0].doc_time2[0] = "(2)Tomorrow";
	doc[0].doc_time2[1] = "1-1:10P.M";
	doc[0].doc_time2[2] = "2-2.30P.M";
	doc[0].doc_time2[3] = "3-3:00P.M";
	doc[0].doc_time2[4] = "4-4:00P.M";
	doc[0].doc_price = 300;

	doc[1].len_t1 = 5;
	doc[1].len_t2 = 5;
	doc[1].username = "youssef";
	doc[1].password = "11";
	doc[1].age = 43;
	doc[1].do_num = 2;
	doc[1].do_name = "DoctorYoussefMohamoud";
	doc[1].doc_speciality = "Dentistry";
	doc[1].doc_time1[0] = "(1)Today";
	doc[1].doc_time1[1] = "1-10:40A.M";
	doc[1].doc_time1[2] = "2-12:05P.M";
	doc[1].doc_time1[3] = "3-10:30A.M";
	doc[1].doc_time1[4] = "4-1:00P.M";
	doc[1].doc_time2[0] = "(2)Tomorrow";
	doc[1].doc_time2[1] = "1-1:30P.M";
	doc[1].doc_time2[2] = "2-2.50P.M";
	doc[1].doc_time2[3] = "3-3:30P.M";
	doc[1].doc_time2[4] = "4-4:00P.M";
	doc[1].doc_price = 250;

	doc[2].len_t1 = 5;
	doc[2].len_t2 = 5;
	doc[2].username = "samar";
	doc[2].password = "1";
	doc[2].age = 40;
	doc[2].do_num = 3;
	doc[2].do_name = "DoctorSamarOmar";
	doc[2].doc_speciality = "Dermatology";
	doc[2].doc_time1[0] = "(1)Today";
	doc[2].doc_time1[1] = "1-11:30A.M";
	doc[2].doc_time1[2] = "2-12:00P.M";
	doc[2].doc_time1[3] = "3-12:30p.M";
	doc[2].doc_time1[4] = "4-1:00P.M";
	doc[2].doc_time2[0] = "(2)Tomorrow";
	doc[2].doc_time2[1] = "1-1:10P.M";
	doc[2].doc_time2[2] = "2-2.35P.M";
	doc[2].doc_time2[3] = "3-3:50P.M";
	doc[2].doc_time2[4] = "4-4:30P.M";
	doc[2].doc_price = 150;


	doc[3].len_t1 = 5;
	doc[3].len_t2 = 5;
	doc[3].username = "mohamed";
	doc[3].password = "1";
	doc[3].age = 40;
	doc[3].do_num = 4;
	doc[3].do_name = "DoctorMohamedElsayed";
	doc[3].doc_speciality = "Dermatology";
	doc[3].doc_time1[0] = "(1)Today";
	doc[3].doc_time1[1] = "1-9:30A.M";
	doc[3].doc_time1[2] = "2-12:00P.M";
	doc[3].doc_time1[3] = "3-12:30p.M";
	doc[3].doc_time1[4] = "4-1:00P.M";
	doc[3].doc_time2[0] = "(2)Tomorrow";
	doc[3].doc_time2[1] = "1-1:10P.M";
	doc[3].doc_time2[2] = "2-2.30P.M";
	doc[3].doc_time2[3] = "3-3:00P.M";
	doc[3].doc_time2[4] = "4-4:00P.M";
	doc[3].doc_price = 200;

	doc[4].len_t1 = 5;
	doc[4].len_t2 = 5;
	doc[4].username = "mona";
	doc[4].password = "1";
	doc[4].age = 40;
	doc[4].do_num = 5;
	doc[4].do_name = "DoctormonaTantawy";
	doc[4].doc_speciality = "Psychiatry";
	doc[4].doc_time1[0] = "(1)Today";
	doc[4].doc_time1[1] = "1-8:30A.M";
	doc[4].doc_time1[2] = "2-9:00P.M";
	doc[4].doc_time1[3] = "3-10:30A.M";
	doc[4].doc_time1[4] = "4-1:00P.M";
	doc[4].doc_time2[0] = "(2)Tomorrow";
	doc[4].doc_time2[1] = "1-4:10P.M";
	doc[4].doc_time2[2] = "2-5.30P.M";
	doc[4].doc_time2[3] = "3-6:00P.M";
	doc[4].doc_time2[4] = "4-7:00P.M";
	doc[4].doc_price = 300;

	doc[5].len_t1 = 5;
	doc[5].len_t2 = 5;
	doc[5].username = "ahmed";
	doc[5].password = "1";
	doc[5].age = 40;
	doc[5].do_num = 6;
	doc[5].do_name = "DoctorAhmedMohamoud";
	doc[5].doc_speciality = "Psychiatry";
	doc[5].doc_time1[0] = "(1)Today";
	doc[5].doc_time1[1] = "1-10:30A.M";
	doc[5].doc_time1[2] = "2-12:00P.M";
	doc[5].doc_time1[3] = "3-12:30p.M";
	doc[5].doc_time1[4] = "4-1:00P.M";
	doc[5].doc_time2[0] = "(2)Tomorrow";
	doc[5].doc_time2[1] = "1-1:10P.M";
	doc[5].doc_time2[2] = "2-2.30P.M";
	doc[5].doc_time2[3] = "3-3:00P.M";
	doc[5].doc_time2[4] = "4-4:00P.M";
	doc[5].doc_price = 250;


	doc[6].len_t1 = 5;
	doc[6].len_t2 = 5;
	doc[6].username = "eman";
	doc[6].password = "1";
	doc[6].age = 40;
	doc[6].do_num = 7;
	doc[6].do_name = "DoctorEmaMohamed";
	doc[6].doc_speciality = "PediatritricsandNewBorn";
	doc[6].doc_time1[0] = "(1)Today";
	doc[6].doc_time1[1] = "1-10:30A.M";
	doc[6].doc_time1[2] = "2-12:00P.M";
	doc[6].doc_time1[3] = "3-10:30A.M";
	doc[6].doc_time1[4] = "4-1:00P.M";
	doc[6].doc_time2[0] = "(2)Tomorrow";
	doc[6].doc_time2[1] = "1-1:10P.M";
	doc[6].doc_time2[2] = "2-2.30P.M";
	doc[6].doc_time2[3] = "3-3:00P.M";
	doc[6].doc_time2[4] = "4-4:00P.M";
	doc[6].doc_price = 300;

	doc[7].len_t1 = 5;
	doc[7].len_t2 = 5;
	doc[7].username = "Menna";
	doc[7].password = "1";
	doc[7].age = 40;
	doc[7].do_num = 8;
	doc[7].do_name = "DoctorMennaMohamoud";
	doc[7].doc_speciality = "PediatritricsandNewBorn";
	doc[7].doc_time1[0] = "(1)Today";
	doc[7].doc_time1[1] = "1-10:30A.M";
	doc[7].doc_time1[2] = "2-12:00P.M";
	doc[7].doc_time1[3] = "3-10:30A.M";
	doc[7].doc_time1[4] = "4-1:00P.M";
	doc[7].doc_time2[0] = "(2)Tomorrow";
	doc[7].doc_time2[1] = "1-1:10P.M";
	doc[7].doc_time2[2] = "2-2.30P.M";
	doc[7].doc_time2[3] = "3-3:00P.M";
	doc[7].doc_time2[4] = "4-4:00P.M";
	doc[7].doc_price = 250;

	doc[8].len_t1 = 5;
	doc[8].len_t2 = 5;
	doc[8].username = "khaled";
	doc[8].password = "1";
	doc[8].age = 40;
	doc[8].do_num = 9;
	doc[8].do_name = "DoctorKhaledMohammed";
	doc[8].doc_speciality = "Neurology";
	doc[8].doc_time1[0] = "(1)Today";
	doc[8].doc_time1[1] = "1-10:30A.M";
	doc[8].doc_time1[2] = "2-11:00P.M";
	doc[8].doc_time1[3] = "3-1:30A.M";
	doc[8].doc_time1[4] = "4-1:00P.M";
	doc[8].doc_time2[0] = "(2)Tomorrow";
	doc[8].doc_time2[1] = "1-1:10P.M";
	doc[8].doc_time2[2] = "2-2.30P.M";
	doc[8].doc_time2[3] = "3-3:00P.M";
	doc[8].doc_time2[4] = "4-4:00P.M";
	doc[8].doc_price = 300;

	doc[9].len_t1 = 5;
	doc[9].len_t2 = 5;
	doc[9].username = "mirna";
	doc[9].password = "1";
	doc[9].age = 40;
	doc[9].do_num = 10;
	doc[9].do_name = "DoctorMirnaMohamoud";
	doc[9].doc_speciality = "Neurology";
	doc[9].doc_time1[0] = "(1)Today";
	doc[9].doc_time1[1] = "1-10:30A.M";
	doc[9].doc_time1[2] = "2-12:00P.M";
	doc[9].doc_time1[3] = "3-10:30A.M";
	doc[9].doc_time1[4] = "4-1:00P.M";
	doc[9].doc_time2[0] = "(2)Tomorrow";
	doc[9].doc_time2[1] = "2-1:10P.M";
	doc[9].doc_time2[2] = "3-2.30P.M";
	doc[9].doc_time2[3] = "4-3:00P.M";
	doc[9].doc_time2[4] = "4-4:00P.M";
	doc[9].doc_price = 250;


	doc[10].len_t1 = 5;
	doc[10].len_t2 = 5;
	doc[10].username = "yassmina";
	doc[10].password = "1";
	doc[10].age = 40;
	doc[10].do_num = 11;
	doc[10].do_name = "DoctorYassminaTantawy";
	doc[10].doc_speciality = "Gynaecologyandinfertility";
	doc[10].doc_time1[0] = "(1)Today";
	doc[10].doc_time1[1] = "1-10:30A.M";
	doc[10].doc_time1[2] = "2-12:00P.M";
	doc[10].doc_time1[3] = "3-12:30A.M";
	doc[10].doc_time1[4] = "4-1:00P.M";
	doc[10].doc_time2[0] = "(2)Tomorrow";
	doc[10].doc_time2[1] = "1-1:10P.M";
	doc[10].doc_time2[2] = "2-2.30P.M";
	doc[10].doc_time2[3] = "3-3:00P.M";
	doc[10].doc_time2[4] = "4-4:00P.M";
	doc[10].doc_price = 300;

	doc[11].len_t1 = 5;
	doc[11].len_t2 = 5;
	doc[11].username = "eman";
	doc[11].password = "1";
	doc[11].age = 40;
	doc[11].do_num = 12;
	doc[11].do_name = "DoctorYoussefMohamoud";
	doc[11].doc_speciality = "Gynaecologyandinfertility";
	doc[11].doc_time1[0] = "(1)Today";
	doc[11].doc_time1[1] = "1-10:30A.M";
	doc[11].doc_time1[2] = "2-12:00P.M";
	doc[11].doc_time1[3] = "3-10:30A.M";
	doc[11].doc_time1[4] = "4-1:00P.M";
	doc[11].doc_time2[0] = "(2)Tomorrow";
	doc[11].doc_time2[1] = "1-1:10P.M";
	doc[11].doc_time2[2] = "2-2.30P.M";
	doc[11].doc_time2[3] = "3-3:00P.M";
	doc[11].doc_time2[4] = "4-4:00P.M";
	doc[11].doc_price = 250;

	doc[12].len_t1 = 5;
	doc[12].len_t2 = 5;
	doc[12].username = "osman";
	doc[12].password = "1";
	doc[12].age = 40;
	doc[12].do_num = 13;
	doc[12].do_name = "DoctorOsmanMohamoud";
	doc[12].doc_speciality = "Orthopedics";
	doc[12].doc_time1[0] = "(1)Today";
	doc[12].doc_time1[1] = "1-10:30A.M";
	doc[12].doc_time1[2] = "2-12:00P.M";
	doc[12].doc_time1[3] = "3-10:30A.M";
	doc[12].doc_time1[4] = "4-1:00P.M";
	doc[12].doc_time2[0] = "(2)Tomorrow";
	doc[12].doc_time2[1] = "1-1:10P.M";
	doc[12].doc_time2[2] = "2-2.30P.M";
	doc[12].doc_time2[3] = "3-3:00P.M";
	doc[12].doc_time2[4] = "4-4:00P.M";
	doc[12].doc_price = 150;

	doc[13].len_t1 = 5;
	doc[13].len_t2 = 5;
	doc[13].username = "weaam";
	doc[13].password = "1";
	doc[13].age = 40;
	doc[13].do_num = 14;
	doc[13].do_name = "DoctorWeaamMohamoud";
	doc[13].doc_speciality = "Orthopedics";
	doc[13].doc_time1[0] = "(1)Today";
	doc[13].doc_time1[1] = "1-8:30A.M";
	doc[13].doc_time1[2] = "2-19:00A.M";
	doc[13].doc_time1[3] = "3-10:30A.M";
	doc[13].doc_time1[4] = "4-1:00P.M";
	doc[13].doc_time2[0] = "(2)Tomorrow";
	doc[13].doc_time2[1] = "1-1:10P.M";
	doc[13].doc_time2[2] = "2-2.30P.M";
	doc[13].doc_time2[3] = "3-3:00P.M";
	doc[13].doc_time2[4] = "4-4:00P.M";
	doc[13].doc_price = 250;

	doc[14].len_t1 = 5;
	doc[14].len_t2 = 5;
	doc[14].username = "omar";
	doc[14].password = "1";
	doc[14].age = 40;
	doc[14].do_num = 15;
	doc[14].do_name = "DoctorOmarMohamoud";
	doc[14].doc_speciality = "Ear,NoseandThroat";
	doc[14].doc_time1[0] = "(1)Today";
	doc[14].doc_time1[1] = "1-10:30A.M";
	doc[14].doc_time1[2] = "2-12:00P.M";
	doc[14].doc_time1[3] = "3-10:30A.M";
	doc[14].doc_time1[4] = "4-1:00P.M";
	doc[14].doc_time2[0] = "(2)Tomorrow";
	doc[14].doc_time2[1] = "1-1:10P.M";
	doc[14].doc_time2[2] = "2-2.30P.M";
	doc[14].doc_time2[3] = "3-3:00P.M";
	doc[14].doc_time2[4] = "4-4:00P.M";
	doc[14].doc_price = 250;

	doc[15].len_t1 = 5;
	doc[15].len_t2 = 5;
	doc[15].username = "youssef";
	doc[15].password = "1";
	doc[15].age = 40;
	doc[15].do_num = 16;
	doc[15].do_name = "DoctorYoussefMohamoud";
	doc[15].doc_speciality = "Ear,NoseandThroat";
	doc[15].doc_time1[0] = "(1)Today";
	doc[15].doc_time1[1] = "1-10:30A.M";
	doc[15].doc_time1[2] = "2-12:00P.M";
	doc[15].doc_time1[3] = "3-10:30A.M";
	doc[15].doc_time1[4] = "4-1:00P.M";
	doc[15].doc_time2[0] = "(2)Tomorrow";
	doc[15].doc_time2[1] = "1-1:10P.M";
	doc[15].doc_time2[2] = "2-2.30P.M";
	doc[15].doc_time2[3] = "3-3:00P.M";
	doc[15].doc_time2[4] = "4-4:00P.M";
	doc[15].doc_price = 250;

	doc[16].len_t1 = 5;
	doc[16].len_t2 = 5;
	doc[16].username = "ali";
	doc[16].password = "1";
	doc[16].age = 40;
	doc[16].do_num = 17;
	doc[16].do_name = "DoctorAliMohamoud";
	doc[16].doc_speciality = "CardiologyandVascularDisease";
	doc[16].doc_time1[0] = "(1)Today";
	doc[16].doc_time1[1] = "1-10:30A.M";
	doc[16].doc_time1[2] = "2-12:00P.M";
	doc[16].doc_time1[3] = "3-10:30A.M";
	doc[16].doc_time1[4] = "4-1:00P.M";
	doc[16].doc_time2[0] = "(2)Tomorrow";
	doc[16].doc_time2[1] = "2-1:10P.M";
	doc[16].doc_time2[2] = "3-2.30P.M";
	doc[16].doc_time2[3] = "4-3:00P.M";
	doc[16].doc_time2[4] = "4-4:00P.M";
	doc[16].doc_price = 250;

	doc[17].len_t1 = 5;
	doc[17].len_t2 = 5;
	doc[17].username = "habiba";
	doc[17].password = "1";
	doc[17].age = 40;
	doc[17].do_num = 18;
	doc[17].do_name = "DoctorHabibaMohamoud";
	doc[17].doc_speciality = "CardiologyandVascularDisease";
	doc[17].doc_time1[0] = "(1)Today";
	doc[17].doc_time1[1] = "1-10:30A.M";
	doc[17].doc_time1[2] = "2-12:00P.M";
	doc[17].doc_time1[3] = "3-10:30A.M";
	doc[17].doc_time1[4] = "4-1:00P.M";
	doc[17].doc_time2[0] = "(2)Tomorrow";
	doc[17].doc_time2[1] = "2-1:10P.M";
	doc[17].doc_time2[2] = "3-2.30P.M";
	doc[17].doc_time2[3] = "4-3:00P.M";
	doc[17].doc_time2[4] = "4-4:00P.M";
	doc[17].doc_price = 250;

	doc[18].len_t1 = 5;
	doc[18].len_t2 = 5;
	doc[18].username = "layla";
	doc[18].password = "1";
	doc[18].age = 40;
	doc[18].do_num = 19;
	doc[18].do_name = "DoctorLaylaMohamoud";
	doc[18].doc_speciality = "Ophthalmology";
	doc[18].doc_time1[0] = "(1)Today";
	doc[18].doc_time1[1] = "1-10:30A.M";
	doc[18].doc_time1[2] = "2-12:00P.M";
	doc[18].doc_time1[3] = "3-10:30A.M";
	doc[18].doc_time1[4] = "4-1:00P.M";
	doc[18].doc_time2[0] = "(2)Tomorrow";
	doc[18].doc_time2[1] = "1-1:10P.M";
	doc[18].doc_time2[2] = "2-2.30P.M";
	doc[18].doc_time2[3] = "3-3:00P.M";
	doc[18].doc_time2[4] = "4-4:00P.M";
	doc[18].doc_price = 250;

	doc[19].len_t1 = 5;
	doc[19].len_t2 = 5;
	doc[19].username = "shahd";
	doc[19].password = "1";
	doc[19].age = 40;
	doc[19].do_num = 20;
	doc[19].do_name = "DoctorShahdMohamoud";
	doc[19].doc_speciality = "Ophthalmology";
	doc[19].doc_time1[0] = "(1)Today";
	doc[19].doc_time1[1] = "1-10:30A.M";
	doc[19].doc_time1[2] = "2-12:00P.M";
	doc[19].doc_time1[3] = "3-10:30A.M";
	doc[19].doc_time1[4] = "4-1:00P.M";
	doc[19].doc_time2[0] = "(2)Tomorrow";
	doc[19].doc_time2[1] = "1-1:10P.M";
	doc[19].doc_time2[2] = "2-2.30P.M";
	doc[19].doc_time2[3] = "3-3:00P.M";
	doc[19].doc_time2[4] = "4-4:00P.M";
	doc[19].doc_price = 250;

	doc[20].len_t1 = 5;
	doc[20].len_t2 = 5;
	doc[20].username = "malak";
	doc[20].password = "1";
	doc[20].age = 40;
	doc[20].do_num = 21;
	doc[20].do_name = "DoctorMalakMohamoud";
	doc[20].doc_speciality = "InternalMedicine";
	doc[20].doc_time1[0] = "(1)Today";
	doc[20].doc_time1[1] = "1-10:30A.M";
	doc[20].doc_time1[2] = "2-12:00P.M";
	doc[20].doc_time1[3] = "3-10:30A.M";
	doc[20].doc_time1[4] = "4-1:00P.M";
	doc[20].doc_time2[0] = "(2)Tomorrow";
	doc[20].doc_time2[1] = "1-1:10P.M";
	doc[20].doc_time2[2] = "2-2.30P.M";
	doc[20].doc_time2[3] = "3-3:00P.M";
	doc[20].doc_time2[4] = "4-4:00P.M";
	doc[20].doc_price = 250;

	doc[21].len_t1 = 5;
	doc[21].len_t2 = 5;
	doc[21].username = "dina";
	doc[21].password = "1";
	doc[21].age = 40;
	doc[21].do_num = 22;
	doc[21].do_name = "DoctorDinaMohamoud";
	doc[21].doc_speciality = "InternalMedicine";
	doc[21].doc_time1[0] = "(1)Today";
	doc[21].doc_time1[1] = "1-10:30A.M";
	doc[21].doc_time1[2] = "2-12:00P.M";
	doc[21].doc_time1[3] = "3-10:30A.M";
	doc[21].doc_time1[4] = "4-1:00P.M";
	doc[21].doc_time2[0] = "(2)Tomorrow";
	doc[21].doc_time2[1] = "1-1:10P.M";
	doc[21].doc_time2[2] = "2-2.30P.M";
	doc[21].doc_time2[3] = "3-3:00P.M";
	doc[21].doc_time2[4] = "4-4:00P.M";
	doc[21].doc_price = 250;


}

void searchofspeciality()
{


	bool flage = 0;
	string spec;//which the user search
	cout << "\n\t\tenter the name of speciality you search\n";
	cin >> spec;
	for (int i = 0; i < len1; i++)
	{
		if (doc[i].doc_speciality == spec)
		{
			cout << "the doctors exist in this speciality :\n";// cout << ( all information of doctor exist in struct of doctors)
			cout << doc[i].do_num << "- " << doc[i].do_name << endl
				<< doc[i].doc_speciality << endl;
			for (int j = 0; j < doc[i].len_t1; j++)
			{
				cout << doc[i].doc_time1[j] << endl;
			}

			cout << "--------------\n";
			for (int j = 0; j < doc[i].len_t2; j++)
			{
				cout << doc[i].doc_time2[j] << endl;

			}
			cout << "--------------------------\n";
			cout << "price = " << doc[i].doc_price << endl;
			cout << "------------------------------------------------------------------\n";
			flage = 1;


		}

	}//end for
	if (flage == 0)
	{
		cout << "sorry! but there are no doctors in this speciality \n saerch again ?(y/n)";
		char choice;
		cin >> choice;

		switch (choice)
		{
		case 'y':
		case'Y':
			system("cls");
			search();
			break;
		default:
			cout << " thank you !\n";
		}
	}
	cin.get();
	cin.get();
	patient();
}

void searchofdoctor()
{
	bool flage = 0;
	string nameofdoc;//which the user search
	cout << "\n\t\tenter the name of doctor you search\n";
	cin >> nameofdoc;
	for (int i = 0; i < len1; i++)
	{
		if (doc[i].do_name == nameofdoc)
		{
			cout << "the information of doctor you search:\n"; // cout << ( all information of doctor exist in struct of doctors)

			cout << doc[i].do_num << "- " << doc[i].do_name << endl
				<< doc[i].doc_speciality << endl;
			for (int j = 0; j < doc[i].len_t1; j++)
			{
				cout << doc[i].doc_time1[j] << endl;
			}

			cout << "--------------\n";
			for (int j = 0; j < doc[i].len_t2; j++)
			{
				cout << doc[i].doc_time2[j] << endl;

			}
			cout << "--------------------------\n";
			cout << "price = " << doc[i].doc_price << endl;
			cout << "------------------------------------------------------------------\n";
			flage = 1;
			break;
		}

	}//end for
	if (flage == 0)
	{
		cout << "sorry! but this doctor not exist \n saerch again ?(y/n)";
		char choice;
		cin >> choice;

		switch (choice)
		{
		case 'y':
		case'Y':
			system("cls");
			search();
			break;
		default:
			cout << " thank you !\n";
		}
	}
	cin.get();
	cin.get();
	patient();
}

void search()
{
	char choice;
	cout << "================================search===============================\n";
	cout << "please: press 1 to searth for a doctors:\npress 2 to search for speciality: \n";
	cin >> choice;
	switch (choice)
	{
	case '1':system("cls"); searchofdoctor(); break;
	case '2':system("cls");   searchofspeciality(); break;
	default:cout << "invalid number !! "; cin.get();
		system("cls"); search();
	}
};

////////////////////////////////////////////////

void viewpatients(int numofind)
{

	cout << "Patients with appointments: \n";
	for (int j = 0; j < len2; j++) {
		if (arr2[j]._name_doctor == doc[numofind].do_name)
		{
			cout << arr2[j]._username_patient << endl << arr2[j].day << endl << arr2[j].time << endl;
		}
	}
	cin.get();
	cin.get();
	doctor();


}

void show_your_data()
{
	system("cls");
	string user_name, user_special;
	cout << "enter your username\n";
	cin >> user_name;
	for (int i = 0; i < len1; i++)
	{
		if (doc[i].username == user_name)
		{
			cout << doc[i].do_num << "- " << doc[i].do_name << endl
				<< doc[i].doc_speciality << endl << "price = " << doc[i].doc_price << endl;
			cout << "today\n";
			for (int j = 0; j < doc[i].len_t1; j++)
			{
				cout << doc[i].doc_time1[j] << endl;
			}

			cout << "--------------\n";
			cout << "tomorrow\n";
			for (int j = 0; j < doc[i].len_t2; j++)
			{
				cout << doc[i].doc_time2[j] << endl;
			}


			
		
		}
	}

	cout << "Doctor data added successfully!" << endl;
	cin.get();
	cin.get();
	doctor();

}


void addtime(int  numofind)
{
	int i = numofind;

	system("cls");
	cout << doc[i].do_num << "- " << doc[i].do_name << endl
		<< doc[i].doc_speciality << endl << "price = " << doc[i].doc_price << endl;
	for (int j = 0; j < doc[i].len_t1; j++)
	{
		cout << doc[i].doc_time1[j] << endl;
	}

	cout << "--------------\n";
	for (int j = 0; j < doc[i].len_t2; j++)
	{
		cout << doc[i].doc_time2[j] << endl;
	}



	string timeadd;//the time thet the doctor will add
	int _add;
	int time12;
	cout << "--------------------- list of add availble time ----------------------------------------\n";
	cout << "todat....press 1\n";
	cout << "tomorrow....press 2\n";
	cin >> time12;
	switch (time12)
	{
	case 1:
	{
		for (int i = doc[numofind].len_t1; i < 10; i++)
		{
			cout << "enter the time you want to add\n";
			cin >> timeadd;
			doc[numofind].doc_time1[i] = timeadd;
			cout << "if you want to add time again..press 1" << endl;
			cin >> _add;
			doc[numofind].len_t1++;
			if (_add == 1)
			{
				continue;
			}
			else

				break;
		}
		break;
	}
	case 2:
	{
		for (int i = doc[numofind].len_t2; i < 10; i++)
		{
			cout << "enter the time you want to add\n";
			cin >> timeadd;
			doc[numofind].doc_time2[i] = timeadd;
			cout << "if you want to add time again..press 1" << endl;
			cin >> _add;
			doc[numofind].len_t2++;
			if (_add == 1)
			{
				continue;
			}
			else

				break;
		}
		break;
	}
	}
	cout << " the time is added (:\n\n";
	cin.get();
	cin.get();
	doctor();
}

void doctor()
{
	system("cls");
	int choice_num;
	char choice;
	string doctorid; // the id that the doctor will entered
	bool flageid = 0;
	int numofind;//the number of indexe thet the information of doctor stored in 
	cout << " welcome to vezeeta (:";
	cout << " enter your username "; cin >> doctorid;

	for (int i = 0; i < len1; i++)
	{
		if (doc[i].username == doctorid)
		{
			flageid = 1; numofind = i;
			break;
		}
	}
	if (flageid)
	{
		cout << "------------------------ services -----------------------\n\n";
		cout << "press\n 1   to show  your data\n"; //maybe will change and the doctor add the data when he sign up in first time only
		cout << " 2   to add availble time\n 3   to edit availble time\n 4   to remove availble time\n 5   to edit the price";
		cout << "\n 6   to view patients with appointments\n 7   to exit the program\n";
		cin >> choice_num;
		switch (choice_num)
		{
		case 1:show_your_data();          break;
		case 2: addtime(numofind);       break;
		case 3: edit_time(numofind);     break;
		case 4: removetime(numofind);    break;
		case 5: changeprice(numofind);   break;
		case 6: viewpatients(numofind);  break;
			//default: cout << "anvaild number ): \n please enter 1 , 2 , 3 , 4 , 5 or 6 . \n ";
				//	cin.get();
					//doctor();

		};
	}
	else
	{
		cout << "sorry!! but this ID is not exist ): \n\n\t\t do you want to try again ?(y/n)";
		cin >> choice;

		switch (choice)
		{
		case 'y':
		case'Y':
			system("cls");
			doctor();
			break;
		default:
			cout << " thank you (: !\n";
			cin.get();
			main();
		};
	}//end else


}

void changeprice(int numofind)
{
	int new_price;
	system("cls");
	cout << " --------------------- changing the price-----------------------\n\n";

	cout << "enter the new price \n";
	cin >> new_price;
	doc[numofind].doc_price = new_price;            //*  change the price  *
	cout << " the price is changing (:\n\n";
}

void edit_time(int numofind)
{
	int i = numofind;
	int time12;
	char choice;
	bool flagetime = 0;
	string oldtime, newtime;
	system("cls");
	cout << "---------------------- list of edit availble time ------------------------\n\n";
	cout << "today....press 1\n";
	cout << "tomorrow.....press 2\n";
	cin >> time12;
	switch (time12)
	{
	case 1:
	{
		cout << "the times exist : \n";
		for (int j = 0; j < doc[i].len_t1; j++)
		{
			cout << doc[numofind].doc_time1[j] << endl;
		}
		cout << "choice the time you want to change"; cin >> oldtime;
		cout << "\nchoice the time you want to add instead"; cin >> newtime;

		for (int j = 0; j < doc[i].len_t1; j++)
		{
			if (doc[numofind].doc_time1[j] == oldtime)
			{
				doc[numofind].doc_time1[j] = newtime; flagetime = 1;
				break;
			}
		}
		if (flagetime)
		{
			cout << "time is changed (: \n";
		}
		else
		{
			cout << "the time isnot exist ):\n\t try again?(y/n)";
			cin >> choice;

			switch (choice)
			{
			case 'y':
			case'Y':
				system("cls");
				edit_time(numofind);
				break;
			default:
				cout << " thank you (: !\n";
			};
		}
		break;
	}
	case 2:
	{
		cout << "the times exist : \n";
		for (int j = 0; j < doc[i].len_t2; j++)
		{
			cout << doc[numofind].doc_time2[j] << endl;
		}
		cout << "choice the time you want to change"; cin >> oldtime;
		cout << "\nchoice the time you want to add instead"; cin >> newtime;

		for (int j = 0; j < doc[i].len_t2; j++)
		{
			if (doc[numofind].doc_time2[j] == oldtime)
			{
				doc[numofind].doc_time2[j] = newtime; flagetime = 1;
				break;
			}
		}
		if (flagetime)
		{
			cout << "time is changed (: \n";
		}
		else
		{
			cout << "the time isnot exist ):\n\t try again?(y/n)";
			cin >> choice;

			switch (choice)
			{
			case 'y':
			case'Y':
				system("cls");
				edit_time(numofind);
				break;
			default:
				cout << " thank you (: !\n";
			};
		}
		break;
	}
	}
}

void removetime(int numofind)
{
	int time12;
	char choice;
	bool flagetime = 0;
	string time_remove;
	system("cls");
	cout << "---------------------- list of remove availble time ------------------------\n\n";
	cout << "today....press 1\n";
	cout << "tomorrow....press 2\n";
	cin >> time12;
	switch (time12)
	{
	case 1:
	{
		cout << "the times exist : \n";
		for (int i = 0; i < doc[numofind].len_t1; i++)
		{
			cout << doc[numofind].doc_time1[i] << endl;
		}


		cout << "choice the time you want to remove"; cin >> time_remove;


		for (int i = 0; i < 10; i++)
		{
			if (doc[numofind].doc_time1[i] == time_remove)
			{
				doc[numofind].doc_time1[i].clear(); flagetime = 1;
				break;
			}
		}
		if (flagetime)
		{
			cout << "time is removed (: \n";
		}
		else
		{
			cout << "the time is not exist ):\n\t try again?(y/n)";
			cin >> choice;

			switch (choice)
			{
			case 'y':
			case'Y':
				system("cls");
				removetime(numofind);
				break;
			default:
				cout << " thank you (: !\n";
			};
		}
	}
	case 2:
	{
		cout << "the times exist : \n";
		for (int i = 0; i < doc[numofind].len_t2; i++)
		{
			cout << doc[numofind].doc_time2[i] << endl;
		}


		cout << "choice the time you want to remove"; cin >> time_remove;


		for (int i = 0; i < 10; i++)
		{
			if (doc[numofind].doc_time2[i] == time_remove)
			{
				doc[numofind].doc_time2[i].clear(); flagetime = 1;
				break;
			}
		}
		if (flagetime)
		{
			cout << "time is removed (: \n";
		}
		else
		{
			cout << "the time is not exist ):\n\t try again?(y/n)";
			cin >> choice;

			switch (choice)
			{
			case 'y':
			case'Y':
				system("cls");
				removetime(numofind);
				break;
			default:
				cout << " thank you (: !\n";
			};
		}
	}
	}
}


void edit_appointment()
{
	string olddoctor, newday, oldday, newtime, oldtime;
	int indexeofapp, indexeofdoc;
	cout << "enter the day and time and doctor in the oppointment you want to edit\n";
	cout << " the doctor: "; cin >> olddoctor;
	cout << "\nthe day: "; cin >> oldday;
	cout << "\nthe time: "; cin >> oldtime;

	int co;
	char c;
	bool foundapp = false, timefound = false;
	for (int i = 0; i < len2; i++)
	{
		if (arr2[i]._username_patient == username_pat && arr2[i]._name_doctor == olddoctor && arr2[i].day == oldday && arr2[i].time == oldtime)
			//// to check if this appointment exist or not
		{
			foundapp = true;
			indexeofapp = i;
			break;
		}
	}
	for (int i = 0; i < len1; i++) //to find the indexe of the array of doctor
	{
		if (doc[i].do_name == olddoctor)
		{
			indexeofdoc = i;
			break;
		}
	}

	char cho, choice;
	if (foundapp)
	{
		cout << "to change day press 1\nto change time press 2\n"; cin >> co;
		switch (co)
		{
		case 1:
			cout << "enter the day you want to add instead: \n"; cin >> newday;

			arr2[indexeofapp].day = newday;
			cout << "it is done (:\n";
			cin.get();
			patient();

			break;
		case 2:
			cout << "enter the time you want to add instead: \n"; cin >> newtime;
			if (oldday == "today")
			{
				for (int i = 0; i < doc[indexeofdoc].len_t1; i++)
				{
					if (doc[indexeofdoc].doc_time1[i] == newtime)
					{
						arr2[indexeofapp].time == newtime;
						cout << "the time has changed successfully(:";
						timefound = true;
						break;
					}
				}

			}
			else
			{
				for (int i = 0; i < doc[indexeofdoc].len_t2; i++)
				{
					if (doc[indexeofdoc].doc_time2[i] == newtime)
					{
						arr2[indexeofapp].time == newtime;
						cout << "the time has changed successfully(:";
						timefound = true;
						break;
					}
				}
			};

			if (timefound == false)
			{
				cout << "sorry but this time not avaible ):\ntry again???(y/n)"; cin >> choice;
				switch (choice)
				{
				case 'y':
				case'Y':
					system("cls");
					edit_appointment();
					break;
				default:
					cout << " thank you !\n";
					cin.get();
					system("slc");
					patient();
				}
				//******************************************************************************************************************************

			}



		}
	}
	else
	{
		cout << " there is not appointment with the data you entered ): \ntry again??(y/n)"; getchar(); cin.get();

		cin >> c;
		switch (c)
		{
		case 'y':
		case'Y':
			system("cls");
			edit_appointment();
			break;
		default:
			cout << " thank you !\n";

			cin.get();
			cin.get();
			patient();
		}
	}

}

void clear_history()
{
	char choice;
	cout << "are you sure that you want to clear all history of appointments??\n press ( y ) if you reelly want: "; cin >> choice;

	if (choice == 'y' || choice == 'Y')
	{
		for (int i = 0; i < len2; i++)
		{
			if (arr2[i]._username_patient == username_pat)
			{
				arr2[i].day.clear();
				arr2[i].time.clear();
				arr2[i]._name_doctor.clear();
				arr2[i]._username_patient.clear();

			}


		}
		cout << "the oppointments have cleared susseccfully (:\n\t vezeeta hope you don't have to book oppointments again (:";
		cin.get();
		getchar();
		patient();




	}
	else {
		cin.get();
		system("cls");
		patient();
	}

}