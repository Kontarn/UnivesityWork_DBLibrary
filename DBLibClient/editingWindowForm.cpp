#include "editingWindowForm.h"

System::Void DBLibClient::editingWindowForm::HelpButton_Click(System::Object^ sender, System::EventArgs^ e)
{
    MessageBox::Show("Ввод производится без знаков ',' и ';'");
    return;
}
// Кнопка выхода из программы, которая лежит в menuStrip
System::Void DBLibClient::editingWindowForm::выходИзПрограммыToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
    Application::Exit();
}
// Кнопка которая возвращает в форму FindForEditForm
System::Void DBLibClient::editingWindowForm::BackButton_Click(System::Object^ sender, System::EventArgs^ e)
{
    FindForEditForm^ form = gcnew FindForEditForm();
    this->Hide();
    form->Show();
}
// Кнопка возвращающая в форму StartMenu
System::Void DBLibClient::editingWindowForm::выхоодНаНачальныйЭкранToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
    StartMenuForm^ form = gcnew StartMenuForm();
    this->Hide();
    form->Show();
}
// Редактирует запись
System::Void DBLibClient::editingWindowForm::edititngDataButton_Click(System::Object^ sender, System::EventArgs^ e)
{
    LibInterface libInter;
    char* cOldInpString = (char*)(Marshal::StringToHGlobalAnsi(oldInpString)).ToPointer();
    std::string sOldInpString(cOldInpString);
    Marshal::FreeHGlobal((IntPtr)cOldInpString);
    if (nameBookTextBox->Text == "" || AutorNameTextBox->Text == "" || 
        yearOfReleaseTextBox->Text == "" || AvailabilityTextBox->Text == "") {
        MessageBox::Show("Заполните все поля", "Внимание");
        return;
    }
    else {
        String^ newString = nameBookTextBox->Text + ", " + 
            AutorNameTextBox->Text + ", " + yearOfReleaseTextBox->Text + "; " + AvailabilityTextBox->Text;
        char* cTypeOfLit = (char*)(Marshal::StringToHGlobalAnsi(typeOfLit).ToPointer());
        char* cNewString = (char*)(Marshal::StringToHGlobalAnsi(newString).ToPointer());
        std::string sTypeOfLit(cTypeOfLit);
        std::string sNewString(cNewString);
        libInter.EditingNotation(sOldInpString, sNewString, sTypeOfLit);
        MessageBox::Show("Запись успешно отредактирована\nНажмите 'Показать все записи', что бы увидеть изменения.", "Успешно");
        this->Hide();
    }
}


