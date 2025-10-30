#pragma once
#include "StartMenuForm.h"
namespace DBLibClient {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for LibrarySearchForm
	/// </summary>
	public ref class LibrarySearchForm : public System::Windows::Forms::Form
	{
	public:
		LibrarySearchForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~LibrarySearchForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::DataGridView^ dataGridView1;
	protected:




	private: System::Windows::Forms::Button^ ExitButton;
	private: System::Windows::Forms::Button^ ShowAllLinesButton;
	private: System::Windows::Forms::Button^ helpOfSearchButton;
	private: System::Windows::Forms::Button^ BackToMenu;
	private: System::Windows::Forms::Label^ label3;

	private: System::Windows::Forms::Button^ FindButton;
	private: System::Windows::Forms::TextBox^ nameBookTextBox;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::ComboBox^ choiceOfTypeBook;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::ComboBox^ choiceOfSortingMethod;




	private: System::Windows::Forms::CheckBox^ checkBox1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ nameBook;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ nameAutor;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ yearOfRelease;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Availability;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ priceColumn;
















	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle1 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle2 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle3 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle4 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->nameBook = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->nameAutor = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->yearOfRelease = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Availability = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->priceColumn = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->ExitButton = (gcnew System::Windows::Forms::Button());
			this->ShowAllLinesButton = (gcnew System::Windows::Forms::Button());
			this->helpOfSearchButton = (gcnew System::Windows::Forms::Button());
			this->BackToMenu = (gcnew System::Windows::Forms::Button());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->FindButton = (gcnew System::Windows::Forms::Button());
			this->nameBookTextBox = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->choiceOfTypeBook = (gcnew System::Windows::Forms::ComboBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->choiceOfSortingMethod = (gcnew System::Windows::Forms::ComboBox());
			this->checkBox1 = (gcnew System::Windows::Forms::CheckBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// dataGridView1
			// 
			dataGridViewCellStyle1->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
			dataGridViewCellStyle1->BackColor = System::Drawing::SystemColors::Control;
			dataGridViewCellStyle1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			dataGridViewCellStyle1->ForeColor = System::Drawing::SystemColors::WindowText;
			dataGridViewCellStyle1->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle1->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle1->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			this->dataGridView1->ColumnHeadersDefaultCellStyle = dataGridViewCellStyle1;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(5) {
				this->nameBook,
					this->nameAutor, this->yearOfRelease, this->Availability, this->priceColumn
			});
			this->dataGridView1->Location = System::Drawing::Point(13, 13);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->RowHeadersWidth = 62;
			this->dataGridView1->RowTemplate->Height = 28;
			this->dataGridView1->Size = System::Drawing::Size(1064, 376);
			this->dataGridView1->TabIndex = 16;
			// 
			// nameBook
			// 
			this->nameBook->HeaderText = L"Название";
			this->nameBook->MinimumWidth = 8;
			this->nameBook->Name = L"nameBook";
			this->nameBook->Width = 350;
			// 
			// nameAutor
			// 
			this->nameAutor->HeaderText = L"Автор";
			this->nameAutor->MinimumWidth = 8;
			this->nameAutor->Name = L"nameAutor";
			this->nameAutor->Width = 250;
			// 
			// yearOfRelease
			// 
			dataGridViewCellStyle2->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleRight;
			dataGridViewCellStyle2->Format = L"N0";
			dataGridViewCellStyle2->NullValue = nullptr;
			this->yearOfRelease->DefaultCellStyle = dataGridViewCellStyle2;
			this->yearOfRelease->HeaderText = L"Год выпуска";
			this->yearOfRelease->MinimumWidth = 8;
			this->yearOfRelease->Name = L"yearOfRelease";
			this->yearOfRelease->Width = 150;
			// 
			// Availability
			// 
			dataGridViewCellStyle3->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleRight;
			dataGridViewCellStyle3->Format = L"N0";
			dataGridViewCellStyle3->NullValue = nullptr;
			this->Availability->DefaultCellStyle = dataGridViewCellStyle3;
			this->Availability->HeaderText = L"Наличие";
			this->Availability->MinimumWidth = 8;
			this->Availability->Name = L"Availability";
			this->Availability->Width = 150;
			// 
			// priceColumn
			// 
			dataGridViewCellStyle4->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleRight;
			dataGridViewCellStyle4->Format = L"C2";
			dataGridViewCellStyle4->NullValue = nullptr;
			this->priceColumn->DefaultCellStyle = dataGridViewCellStyle4;
			this->priceColumn->HeaderText = L"Цена";
			this->priceColumn->Name = L"priceColumn";
			// 
			// ExitButton
			// 
			this->ExitButton->Location = System::Drawing::Point(886, 481);
			this->ExitButton->Name = L"ExitButton";
			this->ExitButton->Size = System::Drawing::Size(82, 37);
			this->ExitButton->TabIndex = 30;
			this->ExitButton->Text = L"Выход";
			this->ExitButton->UseVisualStyleBackColor = true;
			this->ExitButton->Click += gcnew System::EventHandler(this, &LibrarySearchForm::ExitButton_Click);
			// 
			// ShowAllLinesButton
			// 
			this->ShowAllLinesButton->Location = System::Drawing::Point(104, 481);
			this->ShowAllLinesButton->Name = L"ShowAllLinesButton";
			this->ShowAllLinesButton->Size = System::Drawing::Size(214, 37);
			this->ShowAllLinesButton->TabIndex = 29;
			this->ShowAllLinesButton->Text = L"Показать все записи";
			this->ShowAllLinesButton->UseVisualStyleBackColor = true;
			this->ShowAllLinesButton->Click += gcnew System::EventHandler(this, &LibrarySearchForm::ShowAllLinesButton_Click);
			// 
			// helpOfSearchButton
			// 
			this->helpOfSearchButton->Location = System::Drawing::Point(323, 407);
			this->helpOfSearchButton->Name = L"helpOfSearchButton";
			this->helpOfSearchButton->Size = System::Drawing::Size(177, 33);
			this->helpOfSearchButton->TabIndex = 27;
			this->helpOfSearchButton->Text = L"Правила поиска";
			this->helpOfSearchButton->UseVisualStyleBackColor = true;
			this->helpOfSearchButton->Click += gcnew System::EventHandler(this, &LibrarySearchForm::helpOfSearchButton_Click);
			// 
			// BackToMenu
			// 
			this->BackToMenu->Location = System::Drawing::Point(974, 481);
			this->BackToMenu->Name = L"BackToMenu";
			this->BackToMenu->Size = System::Drawing::Size(81, 37);
			this->BackToMenu->TabIndex = 26;
			this->BackToMenu->Text = L"Назад";
			this->BackToMenu->UseVisualStyleBackColor = true;
			this->BackToMenu->Click += gcnew System::EventHandler(this, &LibrarySearchForm::BackToMenu_Click);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(13, 418);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(171, 15);
			this->label3->TabIndex = 25;
			this->label3->Text = L"Введите данные для поиска";
			// 
			// FindButton
			// 
			this->FindButton->Location = System::Drawing::Point(14, 481);
			this->FindButton->Name = L"FindButton";
			this->FindButton->Size = System::Drawing::Size(83, 37);
			this->FindButton->TabIndex = 23;
			this->FindButton->Text = L"Поиск";
			this->FindButton->UseVisualStyleBackColor = true;
			this->FindButton->Click += gcnew System::EventHandler(this, &LibrarySearchForm::FindButton_Click);
			// 
			// nameBookTextBox
			// 
			this->nameBookTextBox->Location = System::Drawing::Point(14, 446);
			this->nameBookTextBox->Name = L"nameBookTextBox";
			this->nameBookTextBox->Size = System::Drawing::Size(485, 21);
			this->nameBookTextBox->TabIndex = 22;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(862, 417);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(101, 15);
			this->label1->TabIndex = 21;
			this->label1->Text = L"Тип литературы";
			// 
			// choiceOfTypeBook
			// 
			this->choiceOfTypeBook->AutoCompleteCustomSource->AddRange(gcnew cli::array< System::String^  >(2) { L"Техническая", L"Художественная" });
			this->choiceOfTypeBook->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->choiceOfTypeBook->FormattingEnabled = true;
			this->choiceOfTypeBook->Items->AddRange(gcnew cli::array< System::Object^  >(3) { L"Техническая", L"Художественная", L"Оба типа" });
			this->choiceOfTypeBook->Location = System::Drawing::Point(866, 445);
			this->choiceOfTypeBook->Name = L"choiceOfTypeBook";
			this->choiceOfTypeBook->Size = System::Drawing::Size(189, 23);
			this->choiceOfTypeBook->TabIndex = 20;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(593, 417);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(131, 15);
			this->label2->TabIndex = 32;
			this->label2->Text = L"Способ отображения";
			// 
			// choiceOfSortingMethod
			// 
			this->choiceOfSortingMethod->AutoCompleteCustomSource->AddRange(gcnew cli::array< System::String^  >(2) {
				L"Техническая",
					L"Художественная"
			});
			this->choiceOfSortingMethod->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->choiceOfSortingMethod->FormattingEnabled = true;
			this->choiceOfSortingMethod->Items->AddRange(gcnew cli::array< System::Object^  >(4) {
				L"по названию, по алфавиту", L"по автору, по алфавиту",
					L"по году, в порядке возрастания", L"по году, в порядке убывания"
			});
			this->choiceOfSortingMethod->Location = System::Drawing::Point(597, 445);
			this->choiceOfSortingMethod->Name = L"choiceOfSortingMethod";
			this->choiceOfSortingMethod->Size = System::Drawing::Size(262, 23);
			this->choiceOfSortingMethod->TabIndex = 31;
			// 
			// checkBox1
			// 
			this->checkBox1->AutoSize = true;
			this->checkBox1->Location = System::Drawing::Point(597, 480);
			this->checkBox1->Name = L"checkBox1";
			this->checkBox1->Size = System::Drawing::Size(121, 19);
			this->checkBox1->TabIndex = 33;
			this->checkBox1->Text = L"Книги в наличии";
			this->checkBox1->UseVisualStyleBackColor = true;
			// 
			// LibrarySearchForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(7, 15);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1089, 545);
			this->Controls->Add(this->checkBox1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->choiceOfSortingMethod);
			this->Controls->Add(this->ExitButton);
			this->Controls->Add(this->ShowAllLinesButton);
			this->Controls->Add(this->helpOfSearchButton);
			this->Controls->Add(this->BackToMenu);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->FindButton);
			this->Controls->Add(this->nameBookTextBox);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->choiceOfTypeBook);
			this->Controls->Add(this->dataGridView1);
			this->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MaximizeBox = false;
			this->Name = L"LibrarySearchForm";
			this->ShowIcon = false;
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Поиск литературы";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &LibrarySearchForm::LibrarySearchForm_FormClosing);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
private: System::Void ExitButton_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void BackToMenu_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void helpOfSearchButton_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void FindButton_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void ShowAllLinesButton_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void LibrarySearchForm_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e);
};
}
