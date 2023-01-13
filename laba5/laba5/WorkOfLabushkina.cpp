#include <ctime>
#include <conio.h>
#include "Console.h"
#include "GasTransmissionNetwork.h"
#include "Verification.h"

// ����� ����� � ���������
int main()
{
	Console::SetRusLocale();
	Console::SetTitleConsoleWindow();
	Console::ChangeConsoleFont(0, 20);
	GasTransmissionNetwork newNetwork;
	while (true)
	{
		Console::PrintMenu();
		switch (_getch())
		{
		case '1':
		{
			system("CLS");
			Console::PrintTitleText("\t\t\t\t\t\t������������� �����");
			newNetwork.AddPipe();
			break;
		}
		case '2':
		{
			system("CLS");
			Console::PrintTitleText("\t\t\t\t\t������������� ������������� �������");
			newNetwork.AddCS();
			break;
		}
		case '3':
		{
			system("ClS");
			Console::PrintTitleText("\n\t\t\t\t\t\t\t�������� ���� ����\n");
			newNetwork.PrintTablePipes();
			Console::PrintTitleText("\n\n\n\n\t\t\t\t\t\t\t�������� ���� ������������� �������\n");
			newNetwork.PrintTableCS();
			verification::GetPressEscape("\n\n\n����� ����� � ����, ������� ESC: ", "\n������� �� ����������, ������� ESC �� ����������, ���� ������ ��������� � ����!");
			break;
		}
		case '4':
		{
			system("CLS");
			Console::PrintTitleText("\n\t\t\t\t\t�������������� ����\n");
			newNetwork.ChangePipe();
			break;
		}
		case '5':
		{
			system("CLS");
			Console::PrintTitleText("\n\t\t\t\t\t�������������� ������������� �������\n");
			newNetwork.ChangeCS();
			break;
		}
		case '6':
		{
			system("CLS");
			Console::PrintTitleText("\n\t\t���������� ������ � ����\n");
			std::string fileName = verification::GetStringValue("������� ��� �����, � ������� �� ������ �� ��������� ������ (.txt, �������� 30 ��������): ",
				"������!!! �������� ����� �� ����� �������� ������ �� �������� ��� ������ ������ � ����� ����� ������ ��� 30 ��������!!!", 30);
			std::ofstream fout(fileName);
			if (fout.is_open())
			{
				newNetwork.SaveToFilePipeCollection(fout);
				fout << ' ' << std::endl;
				newNetwork.SaveToFileCSCollection(fout);
			}
			else
				Console::PrintErrorText("\n������!!! ���� �� ���������� ���� �� ������, ���� �� �� ����������!");
			fout.close();
			verification::GetPressEscape("\n\n����� ����� � ����, ������� ESC: ", "\n������� �� ����������, ������� ESC �� ����������, ���� ������ ��������� � ����!");
			break;
		}
		case '7':
		{
			system("CLS");
			Console::PrintTitleText("\n\t\t�������� ������ �� �����\n");
			std::string fileName = verification::GetStringValue("������� ��� �����, � ������� �� ������ �� ��������� ������ (.txt, �������� 30 ��������): ",
				"������!!! �������� ����� �� ����� �������� ������ �� �������� ��� ������ ������ � ����� ����� ������ ��� 30 ��������!!!", 30);
			std::ifstream fin(fileName);
			if (fin.is_open())
			{
				if (fin.peek() != -1)
				{
					newNetwork.DownloadFromFilePipeCollection(fin);
					fin.ignore(10000, '\n');
					newNetwork.DownloadFromFileCSCollection(fin);
				}
				else
				{
					Console::PrintErrorText("\n������ ��������� ������ �� ������� �����, ������� ����� ��������� ��� ������!!!");
				}
			}
			else
				Console::PrintErrorText("\n������!!! ���� �� ���������� ���� �� ������, ���� �� �� ����������!");
			fin.close();
			system("pause");
			break;
		}
		case '8':
		{
			system("CLS");
			Console::PrintTitleText("\n\t\t�������� �����");
			newNetwork.DeletePipe();
			break;
		}
		case '9':
		{
			system("CLS");
			Console::PrintTitleText("\n\t\t�������� ��");
			newNetwork.DeleteCS();
			break;
		}
		case 'a':
		{
			system("CLS");
			Console::PrintTitleText("\n\t\t\t�������� �������������� ����");
			newNetwork.BatchChangePipeCollection();
			break;
		}
		case 'b':
		{
			system("CLS");
			Console::PrintTitleText("\n\t\t\t\t�������� �������������� ��");
			newNetwork.BatchChangeCSCollection();
			break;
		}
		case 'c':
		{
			system("CLS");
			newNetwork.manageNetwork();
			break;
		}
		case '0':
		{
			system("CLS");
			Console::PrintTitleText("\n\t����, �� ������ �� �����, �� ���� ��������� ��������� ���� ����� ������.\n\t\t\t\t�� ������ �������! :)");
			Sleep(5000);
			return 0;
		}
		default:
		{
			Console::PrintErrorText("\n������������ ���� ������!!! ������� �� �����, ������� ������������ ������� �� ������!!!\n��������� ������� ����� 3 �������");
			Sleep(3000);
			break;
		}
		}
		system("CLS");
	}
};