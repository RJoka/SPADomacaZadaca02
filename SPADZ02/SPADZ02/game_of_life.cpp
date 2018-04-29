#include <ctime>
#include "game_of_life.h"


bool game_of_life::slucajna_vrijednost()
{
	
	if (slucajniBroj(0, 3) == 0)
	{
		return true;
	}
	return false;
}

int game_of_life::slucajniBroj(int min, int max)
{
	return rand() % (max - min + 1) + min;
}

bool game_of_life::celija_zauzeta(int i, int j)
{
	if (i < 0 || j < 0 || i>REDAKA || j>STUPACA)  
	{
		return false;
	}
	else if (_generacija[i][j])   
	{
		return true;
	}
	return false;
}

bool game_of_life::ziviDalje(int i, int j)
{
	zivih = 0;

	for (int g = -1; g < 2; g++)
	{
		for (int h = -1; h < 2; h++)
		{
			if (g == 0 && h == 0)
			{
				continue;
			}
			else if (celija_zauzeta(i + g, j + h))
			{
				zivih++;
			}
		}
	}


	if (!celija_zauzeta(i, j))
	{
		if (zivih == 3)
		{
			return true;
		}
	}

	else if (zivih == 2 || zivih == 3)
	{
		return true;
	}

	return false;
}

game_of_life::game_of_life()
{
	for (int i = 0; i < REDAKA; i++)
	{
		for (int j = 0; j < STUPACA; j++)
		{
			_generacija[i][j] = slucajna_vrijednost();
		}
	}
}

void game_of_life::sljedeca_generacija()
{
	for (int i = 0; i < REDAKA; i++)
	{
		for (int j = 0; j < STUPACA; j++)
		{
			if (ziviDalje(i, j))
			{
				_sljedeca_generacija[i][j] = true;
			}
			else
			{
				_sljedeca_generacija[i][j] = false;
			}
		}
	}
	for (int i = 0; i < REDAKA; i++)
	{
		for (int j = 0; j < STUPACA; j++)
		{
			_generacija[i][j] = _sljedeca_generacija[i][j];
		}
	}
}

void game_of_life::iscrtaj()
{

	cout << endl;
	for (int i = 0; i < REDAKA; i++)
	{
		for (int j = 0; j < STUPACA; j++)
		{
			if (_generacija[i][j])
			{
				cout << "*";
			}
			else
			{
				cout << "-";
			}

		}
		cout << endl;
	}
}
