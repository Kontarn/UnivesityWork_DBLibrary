#include "editingWindowForm.h"

System::Void DBLibClient::editingWindowForm::HelpButton_Click(System::Object^ sender, System::EventArgs^ e)
{
    MessageBox::Show("���� ������������ ��� ������ ',' � ';'", "��������",
        MessageBoxButtons::OK,
        MessageBoxIcon::Error);
    return;
}
// ������ ������ �� ���������, ������� ����� � menuStrip
System::Void DBLibClient::editingWindowForm::����������������ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
    Application::Exit();
}
// ������ ������� ���������� � ����� FindForEditForm
System::Void DBLibClient::editingWindowForm::BackButton_Click(System::Object^ sender, System::EventArgs^ e)
{
    FindForEditForm^ form = gcnew FindForEditForm();
    this->Hide();
    form->Show();
}
// ������ ������������ � ����� StartMenu
System::Void DBLibClient::editingWindowForm::����������������������ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
    StartMenuForm^ form = gcnew StartMenuForm();
    this->Hide();
    form->Show();
}
// ����������� ������
System::Void DBLibClient::editingWindowForm::edititngDataButton_Click(System::Object^ sender, System::EventArgs^ e)
{
    Admin admin;
    char* cOldInpString = (char*)(Marshal::StringToHGlobalAnsi(oldInpString)).ToPointer();
    std::string sOldInpString(cOldInpString);
    Marshal::FreeHGlobal((IntPtr)cOldInpString);
    if (nameBookTextBox->Text == "" || AutorNameTextBox->Text == "" || 
        yearOfReleaseComboBox->Text == "" || AvailabilityTextBox->Text == "" || priceTextBox->Text == "") {
        MessageBox::Show("��������� ��� ����", "��������");
        return;
    }
    else {
        String^ newString = 
            nameBookTextBox->Text + ", " + 
            AutorNameTextBox->Text + ", " + 
            yearOfReleaseComboBox->Text + "; " + 
            AvailabilityTextBox->Text + "; " +
            priceTextBox->Text;
        char* cTypeOfLit = (char*)(Marshal::StringToHGlobalAnsi(typeOfLit).ToPointer());
        char* cNewString = (char*)(Marshal::StringToHGlobalAnsi(newString).ToPointer());
        std::string sTypeOfLit(cTypeOfLit);
        std::string sNewString(cNewString);
        admin.EditingNotation(sOldInpString, sNewString, sTypeOfLit);
        MessageBox::Show("������ ������� ���������������\n������� '�������� ��� ������', ��� �� ������� ���������.", "�������",
            MessageBoxButtons::OK,
            MessageBoxIcon::Information);
        this->Hide();
    }
}

System::Void DBLibClient::editingWindowForm::priceTextBox_Validating(System::Object^ sender, System::ComponentModel::CancelEventArgs^ e)
{
    Decimal avail = 0;
    if (Decimal::TryParse(AvailabilityTextBox->Text, avail)) {
        if (avail < 0 || avail > 900) {
            MessageBox::Show("���� ������ ���� ������������ � ����� ��� ����� ����� �������", "������",
                MessageBoxButtons::OK,
                MessageBoxIcon::Error);
            e->Cancel = true;
        }
    }
}

System::Void DBLibClient::editingWindowForm::priceTextBox_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) {
    if (!(Char::IsControl(e->KeyChar) || e->KeyChar == '.' || Char::IsDigit(e->KeyChar))) {
        e->Handled = true;
    }
}

System::Void DBLibClient::editingWindowForm::editingWindowForm_Load(System::Object^ sender, System::EventArgs^ e)
{
    size_t currentYear = 2025;
    for (size_t i = 1900; i <= currentYear; i++) {
        yearOfReleaseComboBox->Items->Add(i);
    }
    //yearOfReleaseComboBox->SelectedIndex = currentYear - 1900;
}

System::Void DBLibClient::editingWindowForm::yearOfReleaseComboBox_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e)
{
    if (!(Char::IsControl(e->KeyChar) || Char::IsDigit(e->KeyChar))) {
        e->Handled = true;
    }
}

System::Void DBLibClient::editingWindowForm::yearOfReleaseComboBox_Validating(System::Object^ sender, System::ComponentModel::CancelEventArgs^ e)
{
    int yearOfRelease = 0;
    if (int::TryParse(yearOfReleaseComboBox->Text, yearOfRelease)) {
        if (yearOfRelease < 1900 || yearOfRelease > 2025) {
            MessageBox::Show("��� ������� ����� ������ ���� � ��������� �� 1900 �� 2025", "������",
                MessageBoxButtons::OK,
                MessageBoxIcon::Error);
            e->Cancel = true;
        }
    }
}

System::Void DBLibClient::editingWindowForm::AutorNameTextBox_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) {
    if (!(
        Char::IsLetter(e->KeyChar) ||
        Char::IsControl(e->KeyChar) ||
        e->KeyChar == '.' ||
        e->KeyChar == '-' ||
        Char::IsSeparator(e->KeyChar))
        ) {
        e->Handled = true;
    }
}

System::Void DBLibClient::editingWindowForm::AvailabilityTextBox_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) {
    if (!(Char::IsControl(e->KeyChar) || Char::IsDigit(e->KeyChar))) {
        e->Handled = true;
    }
}



