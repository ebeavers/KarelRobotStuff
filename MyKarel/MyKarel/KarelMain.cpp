// conversion from string values from text file to integer values


#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
#include<cstring>

using namespace std;

int conversion_to_int(string info)
	{
	int value;
	stringstream convert(info);
			
			
			if (!(convert >> value))
				{
				value = 0;
				
				}
return value;
}



int main()
{
	
	ifstream infile;
	string temp;
	

	infile.open("world.txt");

	if(infile.fail())
	{
		cout << "file load falure " << endl;
		exit(1);
	}
	while(!infile.eof())
	{
		infile >> temp;

		if (temp == "world")
			{
			
			string col, row;
			
			infile >> col;
			infile >> row;
			
			int columns, rows;

			columns = conversion_to_int(col);
			rows = conversion_to_int(row);

			cout << columns << " " << rows << endl;
			}
		if(temp == "beepers")
			{
			string ave, strt, nmbprs;

			infile >> ave;
			infile >> strt;
			infile >> nmbprs;

			int avenue, street, numberofbeepers;

			avenue = conversion_to_int(ave);
			street = conversion_to_int(strt);
			numberofbeepers = conversion_to_int(nmbprs);

			cout << avenue << " " << street << " " << numberofbeepers << endl;
			}
		if(temp == "robot")
			{
			string roboave, robostrt, robodirct, holdbprs;

			infile >> roboave;
			infile >> robostrt;
			infile >> robodirct;
			infile >> holdbprs;

			int robotavenue, robotstreet, robotdirection, holdingbeepers;

			robotavenue = conversion_to_int(roboave);
			robotstreet = conversion_to_int(robostrt);
			robotdirection = conversion_to_int(robodirct);
			holdingbeepers = conversion_to_int(holdbprs);

			cout << robotavenue << " " << robotstreet << " " << robotdirection << " " << holdingbeepers << endl;

			}
		if(temp == "wall")
		{
			string wallave, wallstrt, walldrct;

			infile >> wallave;
			infile >> wallstrt;
			infile >> walldrct;

			int wallavenue, wallstreet, walldirection;

			wallavenue = conversion_to_int(wallave);
			wallstreet = conversion_to_int(wallstrt);
			walldirection = conversion_to_int(walldrct);

			cout << wallavenue << " " << wallstreet << " " << walldirection << endl;

		}

	}
	
	return 0;
}