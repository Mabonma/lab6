#include <iostream>
#include <string>
#include <string.h>
using namespace std;

int Check()
{
	while (true)
	{
		int a;
		std::cin >> a;

		if (cin.fail())
		{
			cin.clear();
			cin.ignore(32767, '\n');
			cout << "Oops, that input is invalid.  Please try again.\n";
		}
		else
		{
			cin.ignore(32767, '\n'); // удаляем лишние значения

			return a;
		}
	}
}

int CheckEnum()
{
	while (true)
	{
		int a;
		cin >> a;

		if (cin.fail())
		{
			cin.clear();
			cin.ignore(32767, '\n');
			cout << "Oops, that input is invalid.  Please try again.\n";
		}
		else
		{
			cin.ignore(32767, '\n');

			if ((a >= 1) && (a <= 3))
			{
				return a;
			}

			cout << "Oops, that input is invalid.  Please try again.\n";
		}
	}
}

int CheckBool()
{
	while (true)
	{
		int a;
		cin >> a;

		if (cin.fail())
		{
			cin.clear();
			cin.ignore(32767, '\n');
			cout << "Oops, that input is invalid.  Please try again.\n";
		}
		else
		{
			cin.ignore(32767, '\n');

			if ((a >= 0) && (a <= 1))
			{
				return a;
			}

			cout << "Oops, that input is invalid.  Please try again.\n";
		}
	}
}

class Programming
{
public:

	//constructors
	Programming() { }
	Programming(string name_lang, string libr) : name_of_language(name_lang), library(libr) { }

	//properties
	string Name_of_language()
	{
		return name_of_language;
	}
	string Library()
	{
		return library;
	}

	//metods
	void Print()
	{
		cout << "Class Programming" << endl;
	}
	string ToString()
	{
		return "Class Programming";
	}

protected:
	string name_of_language = "";
	string library = "";
};

enum class TypesInheritance
{
	SingleInher,
	MultiInher,
	HybridInher
};

string TypeInher(TypesInheritance inher)
{
	switch (inher)
	{
	case TypesInheritance::SingleInher: return "Single Inheritance";
	case TypesInheritance::MultiInher: return "Multi Inheritance";
	case TypesInheritance::HybridInher: return "Hybrid Inheritance";
	}
}

/// <summary>
/// enter int value and return type inheritance
/// </summary>
/// <param name="buf">int value of inheritance: 1-single, 2-multi, 3-hybrid</param>
/// <returns></returns>
TypesInheritance SetInher(int buf)
{
	switch (buf)
	{
	case 1: return TypesInheritance::SingleInher;
	case 2: return TypesInheritance::MultiInher;
	case 3: return TypesInheritance::HybridInher;
	default:
		throw "Index_Not_In_Enum_Value";
		break;
	}
}

class OOP : virtual public Programming
{
public:

	//constructors
	OOP() { };

	OOP(string name_lang, string libr, TypesInheritance inherit, bool auto_encaps, bool true_polymorf) : Programming(name_lang, libr)
	{
		inheritance = inherit;
		automat_Encapsulation = auto_encaps;
		is_true_Polymorphism = true_polymorf;
	}

	//properties
	TypesInheritance Inheritance()
	{
		return inheritance;
	}

	bool Automat_Encapsulation()
	{
		return automat_Encapsulation;
	}

	bool Is_True_Polymorphism()
	{
		return is_true_Polymorphism;
	}

	//methods
	void Print()
	{
		cout << "Name of language - " << name_of_language << ". Using library - " << library << ". Support inheritance - " +
			TypeInher(inheritance) << ". Encapsulation is " << ((automat_Encapsulation) ? "fully " : "not ")
			<< "automated. And Polymorphism " << ((is_true_Polymorphism) ? "is" : "is`n") << " true." << endl;
	}

	string ToString()
	{
		return "Name of language - " + name_of_language + ". Using library - " + library + ". Support inheritance - " +
			TypeInher(inheritance) + ". Encapsulation is " + ((automat_Encapsulation) ? "fully " : "not ") + "automated. And Polymorphism "
			+ ((is_true_Polymorphism) ? "is" : "is`n") + " true.";
	}

protected:
	TypesInheritance inheritance = TypesInheritance::SingleInher;
	bool automat_Encapsulation = false, is_true_Polymorphism = false;
};

class Markup : virtual public Programming
{
public:
	//constructors
	Markup() { }
	Markup(string name_lang, string libr, string tagnam, string framename) : Programming(name_lang, libr)
	{
		tag = tagnam;
		framework = framename;
	}

	//properties
	string Tag()
	{
		return tag;
	}
	string Framework()
	{
		return framework;
	}

	//methods
	void Print()
	{
		cout << "Name of language - " + name_of_language << ". Using library - " + library << ". Using tag - " + tag << " in framework - "
			+ framework << "." << endl;
	}
	string ToString()
	{
		return "Name of language - " + name_of_language + ". Using library - " + library + ". Using tag - " + tag + " in framework - "
			+ framework + ".";
	}

	void ChangeTag()
	{
		cout << "Current tag - " + tag << "\nDo u want to Change? (1 - yes, 0 - no)" << endl;
		bool really = CheckBool();
		if (really)
		{
			cout << "Enter using tag" << endl;
			getline(cin, tag);
		}
		else
		{
			cout << "Canceling change tag" << endl;
		}
	}

protected:
	string tag = "", framework = "";
};

class Programmer : public OOP, public Markup
{
public:
	Programmer() { }

	Programmer(string name_lang, string libr, TypesInheritance inherit, bool auto_encaps, bool true_polymorf, 
		string tagnam, string framename, string prognam, string progsurnam) : OOP(name_lang, libr, inherit, auto_encaps, true_polymorf),
		Markup(name_lang, libr, tagnam, framename), Programming(name_lang, libr), name(prognam), surname(progsurnam) { }

	void PrintStatistic()
	{
		cout << "Young Programmer:\nName - " << name << ";\nSurname - " << surname << ".\nProgramming information:\nName of Language - "
			<< name_of_language << ";\nLibrary - " << library << ";\nOOP inheritance - " << TypeInher(inheritance) << 
			";\n OOP Encapsulation is " << ((automat_Encapsulation) ? "fully " : "not ") << "automated; \nOOP Polymorphism " << 
			((is_true_Polymorphism) ? "is" : "is`n") << " true;\n Markup use tag - " + tag + " in framework - " + framework + "." << endl;
	}

	void ChangeInformation()
	{
		PrintStatistic();
		cout << "Do u want to change this Informarion? (1 - yes, 0 - no)" << endl;
		bool really = CheckBool();
		if (really)
		{
			cout << "Enter name" << endl;
			string oopname, ooplibr;
			getline(cin, name);
			cout << "Enter surname" << endl;
			getline(cin, surname);

			cout << "Enter name of language in OOP" << endl;
			getline(cin, oopname);
			cout << "Enter name of using library in OOP" << endl;
			getline(cin, ooplibr);
			cout << "Enter type of inheritance:\n1 - single inher\n2 - multi inher\n3 - hybrid inher" << endl;
			inheritance = SetInher(CheckEnum());
			cout << "IDE is automatically encapsulating? (1 - yes, 0 - no)" << endl;
			automat_Encapsulation = CheckBool();
			cout << "Is it supply true polymorf? (1 - yes, 0 - no)" << endl;
			is_true_Polymorphism = CheckBool();

			cout << "Enter name of language in Markup" << endl;
			string markupname, markuplibr;
			getline(cin, markupname);
			cout << "Enter name of using library in Markup" << endl;
			getline(cin, markuplibr);
			cout << "Enter using tag" << endl;
			getline(cin, tag);
			cout << "Enter using framework" << endl;
			getline(cin, framework);

			name_of_language = oopname + "/" + markupname;
			library = ooplibr + "/" + markuplibr;

			cout << "New Data is saved" << endl;
		}
		else
		{
			cout << "Canceling change information" << endl;
		}
	}

private:
	string name = "", surname = "";
};



int main()
{
	cout << "Enter name" << endl;
	string name, surname, oopname, ooplibr;
	getline(cin, name);
	cout << "Enter surname" << endl;
	getline(cin, surname);

	cout << "Enter name of language in OOP" << endl;
	getline(cin, oopname);
	cout << "Enter name of using library in OOP" << endl;
	getline(cin, ooplibr);
	cout << "Enter type of inheritance:\n1 - single inher\n2 - multi inher\n3 - hybrid inher" << endl;
	TypesInheritance inher = SetInher(CheckEnum());
	cout << "IDE is automatically encapsulating? (1 - yes, 0 - no)" << endl;
	bool auto_encaps = CheckBool(), polymorf;
	cout << "Is it supply true polymorf? (1 - yes, 0 - no)" << endl;
	polymorf = CheckBool();

	/*OOP oop(name, libr, inher, auto_encaps, polymorf);
	oop.Print();
	cout << oop.ToString() << endl;*/

	//cout << "\n----------------------------------------------------------------\n" << endl;


	cout << "Enter name of language in Markup" << endl;
	string markupname, markuplibr;
	getline(cin, markupname);
	cout << "Enter name of using library in Markup" << endl;
	getline(cin, markuplibr);
	cout << "Enter using tag" << endl;
	string tag, framework;
	getline(cin, tag);
	cout << "Enter using framework" << endl;
	getline(cin, framework);

	/*Markup markup(name, libr, tag, framework);
	markup.Print();
	cout << markup.ToString() << endl;

	cout << "\n----------------------------------------------------------------\n" << endl;*/

	Programmer prog((oopname + "/" + markupname), (ooplibr + "/" + markuplibr), inher, auto_encaps, polymorf, tag, framework, name, surname);

	prog.OOP::Print();
	prog.PrintStatistic();
	prog.ChangeInformation();
}