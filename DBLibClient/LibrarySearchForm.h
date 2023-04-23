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
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ nameBook;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ nameAutor;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ yearOfRelease;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Availability;
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
	private: System::Windows::Forms::ComboBox^ comboBox1;
	private: System::Windows::Forms::CheckBox^ checkBox1;

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
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->nameBook = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->nameAutor = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->yearOfRelease = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Availability = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
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
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->checkBox1 = (gcnew System::Windows::Forms::CheckBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// dataGridView1
			// 
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(4) {
				this->nameBook,
					this->nameAutor, this->yearOfRelease, this->Availability
			});
			this->dataGridView1->Location = System::Drawing::Point(13, 13);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->RowHeadersWidth = 62;
			this->dataGridView1->RowTemplate->Height = 28;
			this->dataGridView1->Size = System::Drawing::Size(965, 376);
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
			this->yearOfRelease->HeaderText = L"Год выпуска";
			this->yearOfRelease->MinimumWidth = 8;
			this->yearOfRelease->Name = L"yearOfRelease";
			this->yearOfRelease->Width = 150;
			// 
			// Availability
			// 
			this->Availability->HeaderText = L"Наличие";
			this->Availability->MinimumWidth = 8;
			this->Availability->Name = L"Availability";
			this->Availability->Width = 150;
			// 
			// ExitButton
			// 
			this->ExitButton->Location = System::Drawing::Point(809, 482);
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
			this->BackToMenu->Location = System::Drawing::Point(897, 482);
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
			this->label3->Size = System::Drawing::Size(249, 22);
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
			this->nameBookTextBox->Size = System::Drawing::Size(485, 28);
			this->nameBookTextBox->TabIndex = 22;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(785, 418);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(145, 22);
			this->label1->TabIndex = 21;
			this->label1->Text = L"Тип литературы";
			// 
			// choiceOfTypeBook
			// 
			this->choiceOfTypeBook->AutoCompleteCustomSource->AddRange(gcnew cli::array< System::String^  >(2) { L"Техническая", L"Художественная" });
			this->choiceOfTypeBook->FormattingEnabled = true;
			this->choiceOfTypeBook->Items->AddRange(gcnew cli::array< System::Object^  >(3) { L"Техническая", L"Художественная", L"Оба типа" });
			this->choiceOfTypeBook->Location = System::Drawing::Point(789, 446);
			this->choiceOfTypeBook->Name = L"choiceOfTypeBook";
			this->choiceOfTypeBook->Size = System::Drawing::Size(189, 30);
			this->choiceOfTypeBook->TabIndex = 20;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(516, 418);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(189, 22);
			this->label2->TabIndex = 32;
			this->label2->Text = L"Способ отображения";
			// 
			// comboBox1
			// 
			this->comboBox1->AutoCompleteCustomSource->AddRange(gcnew cli::array< System::String^  >(2) { L"Техническая", L"Художественная" });
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Items->AddRange(gcnew cli::array< System::Object^  >(4) {
				L"по названию, по алфавиту", L"по автору, по алфавиту",
					L"по году, в порядке возрастания", L"по году, в порядке убывания"
			});
			this->comboBox1->Location = System::Drawing::Point(520, 446);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(262, 30);
			this->comboBox1->TabIndex = 31;
			// 
			// checkBox1
			// 
			this->checkBox1->AutoSize = true;
			this->checkBox1->Location = System::Drawing::Point(520, 481);
			this->checkBox1->Name = L"checkBox1";
			this->checkBox1->Size = System::Drawing::Size(175, 26);
			this->checkBox1->TabIndex = 33;
			this->checkBox1->Text = L"Книги в наличии";
			this->checkBox1->UseVisualStyleBackColor = true;
			// 
			// LibrarySearchForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(10, 22);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(992, 528);
			this->Controls->Add(this->checkBox1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->comboBox1);
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
			this->MaximizeBox = false;
			this->MaximumSize = System::Drawing::Size(1014, 584);
			this->MinimumSize = System::Drawing::Size(1014, 584);
			this->Name = L"LibrarySearchForm";
			this->ShowIcon = false;
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Поиск литературы";
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
};
}
