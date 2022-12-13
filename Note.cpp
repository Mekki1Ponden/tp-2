#include "Note.h"
#include "Keeper.h"

Note::Note() {
	cout << " The default constructor of the class was called Note" << endl;
	name = "No data available";
	surname = "No data available";
	sex = "No data available";
	phone_number = "No data available";
	data[0] = 0;
	data[1] = 0;
	data[2] = 0;
}


Note::Note(const Note& obj) {
	*this = obj;
}

Note::~Note() {
	cout << "The class destructor was called Note" << endl;
}

Note& Note::operator=(const Note& other) {
	this->name = other.name;
	this->surname = other.surname;
	this->sex = other.sex;
	this->data[0] = other.data[0];
	this->data[1] = other.data[1];
	this->data[2] = other.data[2];
	this->phone_number = other.phone_number;
	return *this;
}

ostream& operator<<(ostream& out, Note& obj) {
	out << "name: " << obj.name << endl;
	out << "Information about surname : " << obj.surname << endl;
	out << "Information about sex : " << obj.sex << endl;
	out << "Information about phone_number: " << obj.phone_number << endl;
	out << "Information about day born: " << obj.data[0] << endl;
	out << "Information about month born: " << obj.data[1] << endl;
	out << "Information about year born: " << obj.data[2] << endl;
	return out;

}

istream& operator>>(istream& in, Note& obj) {
	cout << "Input name: ";
	getchar();
	getline(in, obj.name);

	cout << "Input surname : ";
	getline(in, obj.surname);

	cout << "Input sex : ";
	getline(in, obj.sex);

	cout << "Input information about phone_number: ";
	getline(in, obj.phone_number);

	cout << "Input information day born: ";
	while (!(in >> obj.data[0]))
	{
		if (in.eof())
		{
			throw "eof";
		}
		in.clear(); //Сбрасываем флаг ошибки, если таковая была
		in.ignore(1000, '\n'); //Игнорируем оставшиеся в потоке данные
		cout << "Try again: ";
	}

	cout << "Input information month born: ";
	while (!(in >> obj.data[1]))
	{
		if (in.eof())
		{
			throw "eof";
		}
		in.clear(); //Сбрасываем флаг ошибки, если таковая была
		in.ignore(1000, '\n'); //Игнорируем оставшиеся в потоке данные
		cout << "Try again: ";
	}
	cout << "Input information year born: ";
	while (!(in >> obj.data[2]))
	{
		if (in.eof())
		{
			throw "eof";
		}
		in.clear(); //Сбрасываем флаг ошибки, если таковая была
		in.ignore(1000, '\n'); //Игнорируем оставшиеся в потоке данные
		cout << "Try again: ";
	}




	return in;
}
	
string Note::sort(Note& obj)
{
	string str = to_string(phone_number[0] + phone_number[1] + phone_number[2]);
	return str;
}
bool Note::search(Note& obj, string sname)
{
	return sname == obj.surname;
}
bool Note::search1(Note& obj, string sex)
{
	return sex == obj.sex;
}

ofstream& operator<<(ofstream& fout, Note& obj) {
	fout << obj.name << endl;
	fout << obj.surname << endl;
	fout << obj.sex << endl;
	fout << obj.phone_number << endl;
	fout << obj.data[0] << endl;
	fout << obj.data[1] << endl;
	fout << obj.data[2] << endl;

	return fout;
}

ifstream& operator>>(ifstream& fin, Note& obj) {

	fin.get();
	/*getline(fin, obj.name);
	//fin.get();
	getline(fin, obj.surname);
	//fin.get();
	getline(fin, obj.sex);
	getline(fin, obj.phone_number);*/
	fin >> obj.name;
	fin >> obj.surname;
	fin >> obj.sex;
	fin >> obj.phone_number;
	fin >> obj.data[0];
	fin >> obj.data[1];
	fin >> obj.data[2];
	fin.get();
	return fin;
}



void Note::redact(Note& obj)
{

	int index;
	cout << "What you want to redact (1-5) 6-exit: " << endl;
	cin >> index;
	switch (index)
	{
	case 1:
		cout << "Input  new information about name: ";
		getchar();
		getline(cin, obj.name);
		break;
	case 2:
		cout << "Input  new surname: ";
		cin >> obj.surname;
		break;
	case 3:
		cout << "Input  new sex: ";
		cin >> obj.sex;
		break;
	case 4:
		cout << "Input new information about  phone_number: ";
		cin >> obj.phone_number;
		break;
	case 5:
		cout << "Input new information about day born: ";
		cin >> obj.data[0];
		cout << "Input new information about  month born: ";
		cin >> obj.data[1];
		cout << "Input new information about  year born: ";
		cin >> obj.data[2];
		break;

	case 6:
		cout << "succesesfuil redact" << endl;
		break;
	default:
		break;
	}

}