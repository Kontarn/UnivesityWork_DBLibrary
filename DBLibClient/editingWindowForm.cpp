#include "editingWindowForm.h"

System::Void DBLibClient::editingWindowForm::HelpButton_Click(System::Object^ sender, System::EventArgs^ e)
{
    MessageBox::Show("Ввод производится без знаков ',' и ';'", "Внимание",
        MessageBoxButtons::OK,
        MessageBoxIcon::Error);
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
    Admin admin;
    char* cOldInpString = (char*)(Marshal::StringToHGlobalAnsi(oldInpString)).ToPointer();
    std::string sOldInpString(cOldInpString);
    Marshal::FreeHGlobal((IntPtr)cOldInpString);
    if (nameBookTextBox->Text == "" || AutorNameTextBox->Text == "" || 
        yearOfReleaseComboBox->Text == "" || AvailabilityTextBox->Text == "" || priceTextBox->Text == "") {
        MessageBox::Show("Заполните все поля", "Внимание");
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
        MessageBox::Show("Запись успешно отредактирована\nНажмите 'Показать все записи', что бы увидеть изменения.", "Успешно",
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
            MessageBox::Show("Цена должна быть вещественной и иметь два знака после запятой", "Ошибка",
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
            MessageBox::Show("Год выпуска книги должен быть в диапазоне от 1900 до 2025", "Ошибка",
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

System::Void DBLibClient::editingWindowForm::priceTextBox_Leave(System::Object^ sender, System::EventArgs^ e) {
    auto tb = safe_cast<System::Windows::Forms::TextBox^>(sender);
    if (String::IsNullOrWhiteSpace(tb->Text))
        return;

    try
    {
        // Используем Double::Parse с InvariantCulture для точки как разделителя
        double value = Double::Parse(tb->Text, System::Globalization::CultureInfo::InvariantCulture);

        // Округляем до 2 знаков
        value = System::Math::Round(value, 2);

        // Форматируем как "0.00"
        tb->Text = value.ToString("F2", System::Globalization::CultureInfo::InvariantCulture);
    }
    catch (System::FormatException^)
    {
        // Некорректный ввод
        System::Windows::Forms::MessageBox::Show(
            "Пожалуйста, введите корректное число.",
            "Ошибка ввода",
            System::Windows::Forms::MessageBoxButtons::OK,
            System::Windows::Forms::MessageBoxIcon::Warning
        );
        tb->Text = "";
        tb->Focus();
    }
    catch (System::OverflowException^)
    {
        System::Windows::Forms::MessageBox::Show(
            "Число слишком большое.",
            "Ошибка",
            System::Windows::Forms::MessageBoxButtons::OK,
            System::Windows::Forms::MessageBoxIcon::Error
        );
        tb->Text = "";
        tb->Focus();
    }
}



