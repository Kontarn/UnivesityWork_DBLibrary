#include "FindForEditForm.h"


System::Void DBLibClient::FindForEditForm::����������������ToolStripMenuItem1_Click(System::Object^ sender, System::EventArgs^ e)
{
    Application::Exit();
}

System::Void DBLibClient::FindForEditForm::������������������������ToolStripMenuItem1_Click(System::Object^ sender, System::EventArgs^ e)
{
	StartMenuForm^ form = gcnew StartMenuForm();
	this->Hide();
	form->Show();
}

System::Void DBLibClient::FindForEditForm::BackToStartMenu_Click(System::Object^ sender, System::EventArgs^ e)
{
	StartMenuForm^ form = gcnew StartMenuForm();
	this->Hide();
	form->Show();
}

System::Void DBLibClient::FindForEditForm::Help_Click(System::Object^ sender, System::EventArgs^ e)
{
	MessageBox::Show("���� ������ ������ ������ '�� ������ � ��������', �� ���� ������ ������������ �� ������� ������� '������� �.�., �������� �����'", "������� ����� ������");
}

System::Void DBLibClient::FindForEditForm::BackToMenu_Click(System::Object^ sender, System::EventArgs^ e)
{
	ChoiceOfMethodEditForm^ form = gcnew ChoiceOfMethodEditForm();
	this->Hide();
	form->Show();
}

System::Void DBLibClient::FindForEditForm::FindButton_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (choiceOfTypeBook->Text == "") MessageBox::Show("�������� ��� ���������� ��� ������", "��������");
	else if (choiceOfTypeBook->Text == "�����������") {

		/*else if (choiceOfWayFind->Text == "�� ������ � ��������") {

			MessageBox::Show("������������ ����� �� ������ � �������� �� ������� ����������� ����������", "�������");
		}
		else if (choiceOfWayFind->Text == "�� ������") {
			MessageBox::Show("������������ ����� �� ������ �� ������� ����������� ����������", "����������");
		}
		else if (choiceOfWayFind->Text == "�� ��������") {
			MessageBox::Show("������������ ����� �� �������� �� ������� ����������� ����������", "����������");
		}
		else if (choiceOfWayFind->Text == "�� ����") {
			MessageBox::Show("������������ ����� �� ���� �� ������� ����������� ����������", "����������");
		}*/
	}
	else if (choiceOfTypeBook->Text == "��������������") {
		//if (choiceOfWayFind->Text == "") MessageBox::Show("�������� ������ ������", "��������");
		//else if (choiceOfWayFind->Text == "�� ������ � ��������") {
		//	MessageBox::Show("������������ ����� �� ������ � �������� �� ������� �������������� ����������", "����������");
		//}
		//else if (choiceOfWayFind->Text == "�� ������") {
		//	MessageBox::Show("������������ ����� �� ������ �� ������� �������������� ����������", "����������");
		//}
		//else if (choiceOfWayFind->Text == "�� ��������") {
		//	MessageBox::Show("������������ ����� �� �������� �� ������� �������������� ����������", "����������");
		//}
		//else if (choiceOfWayFind->Text == "�� ����") {
		//	MessageBox::Show("������������ ����� �� ���� �� ������� �������������� ����������", "����������");
		//}
	}
}
