#include "libs.h"
#include "Block.h"
#include "FlyWeight.h"


list<Block*> FlyWeigth::list;

void main() 
{
	string image = "test_image_code";
	setlocale(LC_CTYPE, "ukr");
	int size = 100;
	int csize = 0;
	Block** block = new Block * [size];

	int ch;
	int counter = 1;
	int counter_ = 1;
	while (true) 
	{
		do 
		{
			system("cls");
			cout << "Наведiть мишкою на блок яким користуєтесь:" << endl;
			cout << "Добавити або видалити блок тиснiть 'r'" << endl;
		     for (int i = 0; i< csize; i++) 
		     {
		     	if (counter_-1 == i) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
		     	cout << i+1 << ": ";
		     	block[i]->GetImg();
		     	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
		     }
			 ch = _getch();

			 switch (ch)
			 {
			 case 224:
			 {
				 switch (_getch())
				 {
				 case 80:counter_ < csize ? counter_++ : counter_ = 1; break;
				 case 72:counter_ > 1 ? counter_-- : counter_ = csize; break;
				 }
			 }
			 }

			 if (ch == 'r') 
			 {
		do 
		{
		system("cls");
		if (counter == 1) cout << "=>";
		cout << "1. Додати блок" << endl;
		if (counter == 2) cout << "=>";
		cout << "2. Забрати блок" << endl;
		ch = _getch();

		switch (ch) 
		{
		    case 224: 
		    {
				switch (_getch()) 
				{
				case 72:counter < 2 ? counter++ : counter = 1; break;
				case 80:counter > 1 ? counter-- : counter = 2; break;
				}
		    }
		}

		} while (ch != 13);

		switch (counter) 
		{
		case 1: 
		{
			string img = image;
			string newBlock;
			int id;
			cout << "Enter id code: ";
			cin >> id;
			cout << "Enter name new Block - ";
			cin >> newBlock;
			img.append("_");
			img.append(newBlock);
			block[csize] = FlyWeigth::GetImage(id, img);
			csize++;
			break;
		}
		case 2: 
		{
			int id;
			for (int i = 0; i< csize; i++)
			{
				cout << "-----------" << endl;
				cout << "id - " << block[i]->GetId() << endl;
				cout << "block name - "; 
				block[i]->GetImg();
				cout << "-----------" << endl;
			}
			cout << "Enter id - ";
			cin >> id;
			for (int i = 0; i < csize; i++)
			{
				if (block[i]->GetId() == id) 
				{
					delete block[i];
					for (int k = i + 1; k < csize; k++) 
					{
						block[k - 1] = block[k];
					}
					break;
				}
			}
			csize--;
			break;
		}
		}
			 }


		} while (ch != 13);
		
	}

	for (int i = 0; i < csize; i++) 
	{
		delete[] block[i];
	}

	delete[] block;
}