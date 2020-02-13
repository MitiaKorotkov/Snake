#include<iostream>
#include<Windows.h>
#include<vector>
#include<time.h>

using namespace std;
const int Hight = 25;
const int Length = 50;
int score = 0;
vector < pair<int, int>> mass_of_fruits;

void Set_position(pair<int, int> _point)
{
	COORD point;
	point.X = _point.first;
	point.Y = _point.second;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), point);
}

void print_score()
{
	Set_position(pair<int, int>(0, Hight));
	cout << "Score:" << score;
}

//void game_over()
//{
// char matrix[100][50] ={};
// for (int i = 0; i < 100; i++)
// for (int j = 0; j < 50; j++)
// if ((i > 10 && i < 40) && ())
// matrix[i][j] = 254;
//}


class Field
{
public:

	Field()

	void Print()
	{
		for (int i = 0; i < Hight; i++)
		{
			Set_position(pair<int, int>(0, i));
			cout << char(179);
			Set_position(pair<int, int>(Length - 1, i));
			cout << char(179);
		}

		for (int j = 0; j < Length; j++)
		{
			Set_position(pair<int, int>(j, 0));
			cout << char(196);
			Set_position(pair<int, int>(j, Hight));
			cout << char(196);
		}

		Set_position(pair<int, int>(0, 0));
		cout << char(218);
		Set_position(pair<int, int>(0, Hight));
		cout << char(212);
		Set_position(pair<int, int>(Length - 1, 0));
		cout << char(191);
		Set_position(pair<int, int>(Length - 1, Hight));
		cout << char(217);
	}

	void print_fruits()
	{
		for (int i = 0; i < mass_of_fruits.size(); i++)
		{
			Set_position(mass_of_fruits[i]);
			cout << char(127);
		}
	}

	void gaeneration_of_fruit()
	{
		int a, b;

		a = rand() % 100;
		b = rand() % 100;

		if (mass_of_fruits.size() == 0/*abs(a - b)<5*/)
			mass_of_fruits.push_back(pair<int, int>(rand() % (Length - 2) + 1, rand() % (Hight - 2) + 1));
	}

private:

	char level[Hight][Length];

};

Field::Field()
{
	/*for (int i = 0; i < Hight; i++)
	for (int j = 0; j < Length; j++)
	{
	if (i == 0)
	level[i][j] = 254;
	else if (i == Hight - 1)
	level[i][j] = 254;
	else if (j == 0)
	level[i][j] = 254;
	else if (j == Length - 1)
	level[i][j] = 254;
	else
	level[i][j] = 32;

	}*/


}

class Snake
{
public:

	Snake(int _x0, int _y0);

	void eating(string _direction)
	{
		for (int i = 0; i < mass_of_fruits.size(); i++)

			if (Position[0]/*Position[Position.size()-2]*/ == mass_of_fruits[i])
			{
				mass_of_fruits.erase(mass_of_fruits.begin() + i);
				score++;
				Elongation();
			}
	}

	void Moove(string _direction)
	{
		if (_direction == "up")
		{
			if (y1 > 0)
				y1--;
			else
				y1 = y0;
		}
		else if (_direction == "down")
		{
			if (y1 < y0)
				y1++;
			else
				y1 = 0;
		}
		else if (_direction == "right")
		{
			if (x1 < x0)
				x1++;
			else
				x1 = 0;
		}
		else
		{
			if (x1 > 0)
				x1--;
			else
				x1 = x0;
		}
	}

	void Moovement()
	{
		for (int i = Position.size() - 1; i > 0; i--)
			Position[i] = Position[i - 1];

		Position[0] = pair<int, int>(x1, y1);
	}

	void Print()
	{
		Set_position(Position[0]);
		cout << char(253);

		for (int i = 1; i < Position.size() - 1; i++)
		{
			Set_position(Position[i]);
			if (((Position[i].first > Position[i - 1].first) && (Position[i].first == Position[i + 1].first) && (Position[i].second < Position[i + 1].second)) || ((Position[i].first == Position[i - 1].first) && (Position[i].first > Position[i + 1].first) && (Position[i].second < Position[i - 1].second)))
				cout << char(187);
			else if (((Position[i].first < Position[i - 1].first) && (Position[i].first == Position[i + 1].first) && (Position[i].second < Position[i + 1].second)) || ((Position[i].first == Position[i - 1].first) && (Position[i].first < Position[i + 1].first) && (Position[i].second < Position[i - 1].second)))
				cout << char(201);
			else if (((Position[i].first < Position[i - 1].first) && (Position[i].first == Position[i + 1].first) && (Position[i].second > Position[i + 1].second)) || ((Position[i].first == Position[i - 1].first) && (Position[i].first < Position[i + 1].first) && (Position[i].second >

				Position[i - 1].second)))
				cout << char(200);
			else if (((Position[i].first > Position[i - 1].first) && (Position[i].first == Position[i + 1].first) && (Position[i].second > Position[i + 1].second)) || ((Position[i].first == Position[i - 1].first) && (Position[i].first > Position[i + 1].first) && (Position[i].second > Position[i - 1].second)))
				cout << char(188);
			else if ((Position[i].first > Position[i - 1].first) || (Position[i].first < Position[i - 1].first))
				cout << char(205);
			else if ((Position[i].first == Position[i - 1].first) || (Position[i].first == Position[i - 1].first))
				cout << char(186);
		}

	}

	void Elongation()
	{
		if (Position[Position.size() - 1].first > Position[Position.size() - 2].first)
			Position.push_back(pair<int, int>(Position[Position.size() - 1].first + 1, Position[Position.size() - 1].second));
		else if (Position[Position.size() - 1].first < Position[Position.size() - 2].first)
			Position.push_back(pair<int, int>(Position[Position.size() - 1].first - 1, Position[Position.size() - 1].second));
		else if (Position[Position.size() - 1].second < Position[Position.size() - 2].second)
			Position.push_back(pair<int, int>(Position[Position.size() - 1].first, Position[Position.size() - 1].second - 1));
		else if (Position[Position.size() - 1].second > Position[Position.size() - 2].second)
			Position.push_back(pair<int, int>(Position[Position.size() - 1].first, Position[Position.size() - 1].second + 1));
	}

	int length()
	{
		return Position.size();
	}

	void Set_size(int _length)
	{
		for (int i = 0; i < _length; i++)
			Position.push_back(pair<int, int>(x1 - i, y1));
	}

	bool collision()
	{
		bool flag = false;

		for (int i = 1; i < Position.size(); i++)
			if (Position[i] == Position[0])
				flag = true;

		if (flag)
			return true;
		else
			return false;
	}

	void Set_x1(int _x)
	{
		x1 = _x;
	}

	void Set_y1(int _y)
	{
		y1 = _y;
	}

	int Get_x1()
	{
		return x1;
	}

	int Get_y1()
	{
		return y1;
	}

	int get_L()
	{
		return L;
	}

private:

	vector < pair<int, int>> Position;
	int x1, y1;
	int y0 = Hight;
	int x0 = Length;
	int L = 5;
	char Body = 205;

};

Snake::Snake(int _x1, int _y1)
{
	x1 = _x1;
	y1 = _y1;
}


int main()
{
	srand(time(NULL));

	bool up = false;
	bool right = true;
	bool down = false;
	bool left = false;
	int V = 5;
	int T = 100 / V;
	string direction = "right";
	Field Field1;
	Snake Snake1(3, 1);

	Snake1.Set_size(Snake1.get_L());

	while (!Snake1.collision())
	{
		Field1.Print();
		Field1.gaeneration_of_fruit();
		Field1.print_fruits();

		if ((GetKeyState(VK_UP) & 0x8000) && (direction != "down"))
		{
			direction = "up";
			T = 200 / V;
		}
		if ((GetKeyState(VK_RIGHT) & 0x8000) && (direction != "left"))
		{
			direction = "right";
			T = 100 / V;
		}
		if ((GetKeyState(VK_DOWN) & 0x8000) && (direction != "up"))
		{
			direction = "down";
			T = 200 / V;
		}
		if ((GetKeyState(VK_LEFT) & 0x8000) && (direction != "right"))
		{
			direction = "left";
			T = 100 / V;
		}

		Snake1.eating(direction);
		print_score();
		Snake1.Moove(direction);
		Snake1.Moovement();
		Snake1.Print();
		Sleep(T);
		system("cls");
	}

	cout << endl << "Game Over" << endl;

	return 0;
}