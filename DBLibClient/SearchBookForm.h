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
	/// Summary for SearchBookForm
	/// </summary>
	public ref class SearchBookForm : public System::Windows::Forms::Form
	{
	public:
		SearchBookForm(void)
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
		~SearchBookForm()
		{
			if (components)
			{
				delete components;
			}
		}

	protected:




	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^ �����ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ ����������������ToolStripMenuItem;
	private: System::Windows::Forms::Button^ ExitButton;
	private: System::Windows::Forms::Button^ ShowAllLinesButton;
	private: System::Windows::Forms::DataGridView^ dataGridView1;




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
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ nameBookColumn;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ nameAutorColumn;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ YearOfRelease;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ AvailabilityColumn;





















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
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->�����ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->����������������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->ExitButton = (gcnew System::Windows::Forms::Button());
			this->ShowAllLinesButton = (gcnew System::Windows::Forms::Button());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
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
			this->nameBookColumn = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->nameAutorColumn = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->YearOfRelease = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->AvailabilityColumn = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->menuStrip1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// menuStrip1
			// 
			this->menuStrip1->GripMargin = System::Windows::Forms::Padding(2, 2, 0, 2);
			this->menuStrip1->ImageScalingSize = System::Drawing::Size(24, 24);
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->�����ToolStripMenuItem });
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(984, 33);
			this->menuStrip1->TabIndex = 1;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// �����ToolStripMenuItem
			// 
			this->�����ToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->����������������ToolStripMenuItem });
			this->�����ToolStripMenuItem->Name = L"�����ToolStripMenuItem";
			this->�����ToolStripMenuItem->Size = System::Drawing::Size(80, 29);
			this->�����ToolStripMenuItem->Text = L"�����";
			// 
			// ����������������ToolStripMenuItem
			// 
			this->����������������ToolStripMenuItem->Name = L"����������������ToolStripMenuItem";
			this->����������������ToolStripMenuItem->Size = System::Drawing::Size(292, 34);
			this->����������������ToolStripMenuItem->Text = L"����� �� ���������";
			this->����������������ToolStripMenuItem->Click += gcnew System::EventHandler(this, &SearchBookForm::����������������ToolStripMenuItem_Click);
			// 
			// ExitButton
			// 
			this->ExitButton->Location = System::Drawing::Point(788, 446);
			this->ExitButton->Name = L"ExitButton";
			this->ExitButton->Size = System::Drawing::Size(89, 34);
			this->ExitButton->TabIndex = 31;
			this->ExitButton->Text = L"�����";
			this->ExitButton->UseVisualStyleBackColor = true;
			this->ExitButton->Click += gcnew System::EventHandler(this, &SearchBookForm::ExitButton_Click);
			// 
			// ShowAllLinesButton
			// 
			this->ShowAllLinesButton->Location = System::Drawing::Point(93, 451);
			this->ShowAllLinesButton->Name = L"ShowAllLinesButton";
			this->ShowAllLinesButton->Size = System::Drawing::Size(193, 34);
			this->ShowAllLinesButton->TabIndex = 30;
			this->ShowAllLinesButton->Text = L"�������� ��� ������";
			this->ShowAllLinesButton->UseVisualStyleBackColor = true;
			// 
			// dataGridView1
			// 
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(4) {
				this->nameBookColumn,
					this->nameAutorColumn, this->YearOfRelease, this->AvailabilityColumn
			});
			this->dataGridView1->Location = System::Drawing::Point(12, 36);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->RowHeadersWidth = 62;
			this->dataGridView1->RowTemplate->Height = 28;
			this->dataGridView1->Size = System::Drawing::Size(964, 313);
			this->dataGridView1->TabIndex = 28;
			// 
			// helpOfSearchButton
			// 
			this->helpOfSearchButton->Location = System::Drawing::Point(292, 451);
			this->helpOfSearchButton->Name = L"helpOfSearchButton";
			this->helpOfSearchButton->Size = System::Drawing::Size(157, 34);
			this->helpOfSearchButton->TabIndex = 27;
			this->helpOfSearchButton->Text = L"������� ������";
			this->helpOfSearchButton->UseVisualStyleBackColor = true;
			// 
			// BackToMenu
			// 
			this->BackToMenu->Location = System::Drawing::Point(883, 446);
			this->BackToMenu->Name = L"BackToMenu";
			this->BackToMenu->Size = System::Drawing::Size(93, 34);
			this->BackToMenu->TabIndex = 26;
			this->BackToMenu->Text = L"�����";
			this->BackToMenu->UseVisualStyleBackColor = true;
			this->BackToMenu->Click += gcnew System::EventHandler(this, &SearchBookForm::BackToMenu_Click);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(11, 376);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(228, 20);
			this->label3->TabIndex = 25;
			this->label3->Text = L"������� ������ ��� ������";
			// 
			// FindButton
			// 
			this->FindButton->Location = System::Drawing::Point(12, 451);
			this->FindButton->Name = L"FindButton";
			this->FindButton->Size = System::Drawing::Size(75, 34);
			this->FindButton->TabIndex = 23;
			this->FindButton->Text = L"�����";
			this->FindButton->UseVisualStyleBackColor = true;
			// 
			// nameBookTextBox
			// 
			this->nameBookTextBox->Location = System::Drawing::Point(12, 401);
			this->nameBookTextBox->Name = L"nameBookTextBox";
			this->nameBookTextBox->Size = System::Drawing::Size(437, 26);
			this->nameBookTextBox->TabIndex = 22;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(784, 376);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(131, 20);
			this->label1->TabIndex = 21;
			this->label1->Text = L"��� ����������";
			// 
			// choiceOfTypeBook
			// 
			this->choiceOfTypeBook->AutoCompleteCustomSource->AddRange(gcnew cli::array< System::String^  >(2) { L"�����������", L"��������������" });
			this->choiceOfTypeBook->FormattingEnabled = true;
			this->choiceOfTypeBook->Items->AddRange(gcnew cli::array< System::Object^  >(3) { L"��� ����", L"�����������", L"��������������" });
			this->choiceOfTypeBook->Location = System::Drawing::Point(788, 399);
			this->choiceOfTypeBook->Name = L"choiceOfTypeBook";
			this->choiceOfTypeBook->Size = System::Drawing::Size(188, 28);
			this->choiceOfTypeBook->TabIndex = 20;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(466, 376);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(233, 20);
			this->label2->TabIndex = 33;
			this->label2->Text = L"�������� ������ ����������";
			// 
			// comboBox1
			// 
			this->comboBox1->AutoCompleteCustomSource->AddRange(gcnew cli::array< System::String^  >(2) { L"�����������", L"��������������" });
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Items->AddRange(gcnew cli::array< System::Object^  >(5) {
				L"��� ����������", L"�� ��������, � ���������� �������",
					L"�� ������, � ���������� �������", L"�� ����, � ������� ����������", L"�� ����, � ������� ��������"
			});
			this->comboBox1->Location = System::Drawing::Point(467, 399);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(315, 28);
			this->comboBox1->TabIndex = 32;
			// 
			// checkBox1
			// 
			this->checkBox1->AutoSize = true;
			this->checkBox1->Location = System::Drawing::Point(470, 433);
			this->checkBox1->Name = L"checkBox1";
			this->checkBox1->Size = System::Drawing::Size(160, 24);
			this->checkBox1->TabIndex = 34;
			this->checkBox1->Text = L"����� � �������";
			this->checkBox1->UseVisualStyleBackColor = true;
			// 
			// nameBookColumn
			// 
			this->nameBookColumn->HeaderText = L"��������";
			this->nameBookColumn->MinimumWidth = 8;
			this->nameBookColumn->Name = L"nameBookColumn";
			this->nameBookColumn->ReadOnly = true;
			this->nameBookColumn->Width = 250;
			// 
			// nameAutorColumn
			// 
			this->nameAutorColumn->HeaderText = L"�����";
			this->nameAutorColumn->MinimumWidth = 8;
			this->nameAutorColumn->Name = L"nameAutorColumn";
			this->nameAutorColumn->ReadOnly = true;
			this->nameAutorColumn->Width = 180;
			// 
			// YearOfRelease
			// 
			this->YearOfRelease->HeaderText = L"��� �������";
			this->YearOfRelease->MinimumWidth = 8;
			this->YearOfRelease->Name = L"YearOfRelease";
			this->YearOfRelease->ReadOnly = true;
			this->YearOfRelease->Width = 80;
			// 
			// AvailabilityColumn
			// 
			this->AvailabilityColumn->HeaderText = L"�������";
			this->AvailabilityColumn->MinimumWidth = 8;
			this->AvailabilityColumn->Name = L"AvailabilityColumn";
			this->AvailabilityColumn->ReadOnly = true;
			this->AvailabilityColumn->Width = 65;
			// 
			// SearchBookForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(984, 492);
			this->Controls->Add(this->checkBox1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->comboBox1);
			this->Controls->Add(this->ExitButton);
			this->Controls->Add(this->ShowAllLinesButton);
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->helpOfSearchButton);
			this->Controls->Add(this->BackToMenu);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->FindButton);
			this->Controls->Add(this->nameBookTextBox);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->choiceOfTypeBook);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"SearchBookForm";
			this->ShowIcon = false;
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"����� ����������";
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void ExitButton_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void BackToMenu_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void ����������������ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
};
}
