#pragma once
class Cell
{
	bool isboom, ishide, ischeck; //
	int nearboom_count; //ÀÌ¼¿ ÁÖº¯ ÆøÅº °¹¼ö ´ãÀ» ÇÔ¼ö
	static int show_count;
public:
	Cell();
	~Cell();
	static Cell **makeMap(int&row, int&col);
	static void hideBoom(Cell **(&map), const int&row, const int&col, int& boomcount);
	static void showMap(Cell **(&map), const int &row, const int &col);
	static void deleteMap(Cell **(&map), const int &row, const int &col);
	static void playGame();
	static bool select_cell(Cell **(&map), const int&row, const int &col,int& x, int& y);
	static void cell_hideoff(Cell **(&map), const int&row, const int &col,int x, int y);
	void printcell(int x, int y) const;
	
};
