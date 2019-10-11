#pragma once
class Cell
{
	//string s = "¦¡¦¢¦£¦¤¦¥¦¦";

	bool isboom, ishide; //ÀÌ¼¿ÀÇ ÆøÅº ¿©ºÎ¸¦ ´ãÀ» ÇÔ¼ö
	int nearboom_count; //ÀÌ¼¿ ÁÖº¯ ÆøÅº °¹¼ö ´ãÀ» ÇÔ¼ö

public:
	Cell();
	~Cell();
	static Cell **makeMap(int&row, int&col);
	static void hideBoom(Cell **(&map), const int&row, const int&col, const int boomcount);
	static void showMap(const Cell **(&map), const int &row, const int &col);
	static void deleteMap(Cell **(&map), const int &row, const int &col);
	static void playGame();

	void printcell(int x,int y);
}
	

