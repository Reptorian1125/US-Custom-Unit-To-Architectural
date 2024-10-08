#include "pch.h"
#include <iostream>
#include <iomanip>
#include <cmath>
#include <sstream>
#include <string>
using namespace std;
int main()
{

	cout << "Welcome to the US Architectural Format to International Standard Application!\n";
	cout << "Please follow instruction.\n";
	cout << "\n";
	string meternote;
	string centimeternote;
	string millimeternote;
	string metricnote;
	int objectnum = 1;

	int globalprecision;
	for (; ; )
	{
		cout << "Enter precision of unit conversion - ";
		if (cin >> globalprecision && globalprecision >= 0 && cin.get() == '\n')
		{
			cout << "\n";
			break;
		}
		else
		{
			cout << "Invalid input\n";
			cin.clear();
			while (cin.get() != '\n'); // 'flush' cin stream
		}
	}

	for (; ;)
	{
		int ft;
		for (; ; )
		{
			cout << "Insert feet(s) input (Whole numbers only. Use 0 if feet(s) info are not provided.): ";
			if (cin >> ft && ft >= 0 && cin.get() == '\n')
			{
				break;
			}
			else
			{
				cout << "Invalid input\n";
				cin.clear();
				while (cin.get() != '\n'); // 'flush' cin stream
			}
		}

		int in;
		if (ft != 0) {
			for (; ; )
			{
				cout << "Insert inch(es) input (Whole numbers only, maximum number is 11): ";
				if (cin >> in && in >= 0 && in <= 11 && cin.get() == '\n')
				{
					break;
				}
				else
				{
					cout << "Invalid input\n";
					cin.clear();
					while (cin.get() != '\n'); // 'flush' cin stream
				}
			}
		}
		else {
			for (; ; )
			{
				cout << "Insert inch(es) input (Whole Numbers Only): ";
				if (cin >> in && in >= 0 && cin.get() == '\n')
				{
					break;
				}
				else
				{
					cout << "Invalid input\n";
					cin.clear();
					while (cin.get() != '\n'); // 'flush' cin stream
				}
			}
		};

		double a;
		for (; ; )
		{
			cout << "Insert numberator of fractional inches (Whole numbers Only): ";
			if (cin >> a && a >= 0 && cin.get() == '\n')
			{
				break;
			}
			else
			{
				cout << "Invalid input\n";
				cin.clear();
				while (cin.get() != '\n'); // 'flush' cin stream
			}
		}


		int b;
		if (a != 0) {
			for (; ; )
			{
				cout << "Insert denominator of fractional inches(Natural Numbers Only, and must be greater than numberator!): ";
				if (cin >> b && b >= 1 && b > a && cin.get() == '\n')
				{
					break;
				}
				else
				{
					cout << "Invalid input\n";
					cin.clear();
					while (cin.get() != '\n'); // 'flush' cin stream
				}
			}
		}
		else { b = 1; cout << "Numberator is defined as 0. Therefore - Denominator : 1" << endl; };

		int totalin, aft, ain;
		totalin = ft * 12 + in;
		aft = floor((ft * 12 + in) / 12);
		ain = totalin - aft * 12;

		int testinta;
		testinta = static_cast<int>(a);

		int rema;
		rema = (a - testinta) * 10;

		string txta;
		txta = testinta == a ? to_string(testinta) : to_string(testinta) + "." + to_string(rema);

		string txtfractiontotal;
		txtfractiontotal = a > 0 ? (totalin > 0 ? " " : "") + txta + "/" + to_string(b) + "\"" : "\"";

		string txtfractionain;
		txtfractionain = a > 0 ? (ain > 0 ? " " : "") + txta + "/" + to_string(b) + "\"" : "\"";

		string txt_standard_notation_X;
		txt_standard_notation_X = aft != 0 ? to_string(aft) + "\'" : "";

		string txt_standard_notation_rightside;
		txt_standard_notation_rightside = ain + a > 0 ? (ain > 0 ? to_string(ain): "") + txtfractionain : (a > 0 ? txtfractionain : "");

		string txtaftandain;
		txtaftandain = aft > 0 && ain + a > 0 ? txt_standard_notation_X + "- " + txt_standard_notation_rightside : (aft > 0 ? txt_standard_notation_X : "") + (ain + a > 0 ? txt_standard_notation_rightside : "");

		string txttotalinandfrac;
		txttotalinandfrac = (totalin > 0 ? to_string(totalin) : "") + txtfractiontotal;

		cout << "\n- Architectural Notation -\n";
		cout << "Architectural Inches Notation: " << txttotalinandfrac << endl;
		cout << "Full Architectural Imperial Notation: " << txtaftandain << endl;

		string header_metric_note;
		header_metric_note = "\n- US Architectural Notation to International Standard Notation for Object #" + to_string(objectnum) + " -\n";
		double uscustomarynotation, inches_to_meter;
		uscustomarynotation = totalin + a / b;
		inches_to_meter = .0254;

		ostringstream txtmeter;
		txtmeter << setprecision(globalprecision);
		txtmeter << fixed;
		txtmeter << (uscustomarynotation * inches_to_meter);
		string txtoutmeter = txtmeter.str();

		ostringstream txtcentimeter;
		txtcentimeter << setprecision(globalprecision);
		txtcentimeter << fixed;
		txtcentimeter << (uscustomarynotation * inches_to_meter * pow(10, 2));
		string txtoutcentimeter = txtcentimeter.str();

		ostringstream txtmillimeter;
		txtmillimeter << setprecision(globalprecision);
		txtmillimeter << fixed;
		txtmillimeter << (uscustomarynotation * inches_to_meter * pow(10, 3));
		string txtoutmillimeter = txtmillimeter.str();

		string convert_to_meter;
		convert_to_meter = txttotalinandfrac + " : " + txtaftandain + " : " + (globalprecision != 0 ? txtoutmeter : to_string(static_cast<int>(round(uscustomarynotation * inches_to_meter)))) + " meters\n";
		string convert_to_centimeter;
		convert_to_centimeter = txttotalinandfrac + " : " + txtaftandain + " : " + (globalprecision != 0 ? txtoutcentimeter : to_string(static_cast<int>(round(uscustomarynotation * inches_to_meter * pow(10, 2))))) + " centimeters\n";
		string convert_to_millimeter;
		convert_to_millimeter = txttotalinandfrac + " : " + txtaftandain + " : " + (globalprecision != 0 ? txtoutmillimeter : to_string(static_cast<int>(round(uscustomarynotation * inches_to_meter * pow(10, 3))))) + " millimeters\n";

		string outputmetric_per_object;
		outputmetric_per_object = header_metric_note + convert_to_meter + convert_to_centimeter + convert_to_millimeter;
		cout << outputmetric_per_object;

		metricnote     += outputmetric_per_object;
		meternote      += convert_to_meter + "\n";
		centimeternote += convert_to_centimeter + "\n";
		millimeternote += convert_to_millimeter + "\n";

	cout << "\nPress any key other than n to repeat. : ";
		if (cin.get() == 'n') 
		{
			cout << "________________" << endl;
			cout << "\n(0) All Units" << endl;
			cout << "(1) Meters" << endl;
			cout << "(2) Centimeters" << endl;
			cout << "(3) Millimeters\n" << endl;
			int choice;
			for (; ; )
			{
				cout << "Pick a number to display recorded output - ";
				if (cin >> choice && choice >= 0 && choice <= 3 && cin.get() == '\n')
				{
					break;
				}
				else
				{
					cout << "Invalid input\n";
					cin.clear();
					while (cin.get() != '\n'); // 'flush' cin stream
				}
			}
			switch (choice) {
			case 0: cout << "\n" << metricnote;
					break;
			case 1: cout << "\n" << meternote;
				break;
			case 2: cout << "\n" << centimeternote;
				break;
			case 3: cout << "\n" << millimeternote;
				break;
			default: break;
			}
			break;
		}
		else 
		{
			objectnum++;
			cout << "________________" << endl;
			cout << "\n- Another object is created for conversion! This is object #" << objectnum << " -\n" << endl; 
		}
	}

	cout << "\nPress any key to exit the application";
	cin.get();
	return 0;
}