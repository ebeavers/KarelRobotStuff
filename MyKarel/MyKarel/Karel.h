#pragma once

class Karel
{
	private:
		int row;
		int column;

	public:
		Karel();
		Karel(int, int);
		int getRow();
		int getCol();
		int getIcon();
		int setRow(int);
		int setCol(int);



};