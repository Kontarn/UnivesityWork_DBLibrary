#pragma once
#include "StartMenuForm.h"
#include "DBLibLibrary.h"
#include "editingWindowForm.h"
#include <string>
#include <vcclr.h>
#include <set>

namespace DBLibClient {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for EditDBLibForm
	/// </summary>
	public ref class FindForEditForm : public System::Windows::Forms::Form
	{
	public:
		FindForEditForm(void)
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
		~FindForEditForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	protected:
	private: System::Windows::Forms::ToolStripMenuItem^ выходToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ вернутс€ЌаЌачальныйЁкранToolStripMenuItem1;
	private: System::Windows::Forms::ToolStripMenuItem^ выход»зѕрограммыToolStripMenuItem1;
	private: System::Windows::Forms::ComboBox^ choiceOfTypeBook;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TextBox^ nameBookTextBox;
	private: System::Windows::Forms::Button^ FindButton;
	private: System::Windows::Forms::Button^ BackToStartMenu;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Button^ BackToMenu;
	private: System::Windows::Forms::Button^ helpOfSearchButton;
	private: System::Windows::Forms::DataGridView^ dataGridView1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ nameBook;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ nameAutor;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ yearOfRelease;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Availability;
	private: System::Windows::Forms::Button^ EditEntryButton;
	private: System::ComponentModel::BackgroundWorker^ backgroundWorker1;
	private: System::Windows::Forms::Button^ ShowAllLinesButton;
	private: System::Windows::Forms::Button^ ExitButton;
	private: System::Windows::Forms::Button^ deleteLineButton;
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
			this->выходToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->вернутс€ЌаЌачальныйЁкранToolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->выход»зѕрограммыToolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->choiceOfTypeBook = (gcnew System::Windows::Forms::ComboBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->nameBookTextBox = (gcnew System::Windows::Forms::TextBox());
			this->FindButton = (gcnew System::Windows::Forms::Button());
			this->BackToStartMenu = (gcnew System::Windows::Forms::Button());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->BackToMenu = (gcnew System::Windows::Forms::Button());
			this->helpOfSearchButton = (gcnew System::Windows::Forms::Button());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->nameBook = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->nameAutor = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->yearOfRelease = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Availability = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->EditEntryButton = (gcnew System::Windows::Forms::Button());
			this->backgroundWorker1 = (gcnew System::ComponentModel::BackgroundWorker());
			this->ShowAllLinesButton = (gcnew System::Windows::Forms::Button());
			this->ExitButton = (gcnew System::Windows::Forms::Button());
			this->deleteLineButton = (gcnew System::Windows::Forms::Button());
			this->menuStrip1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// menuStrip1
			// 
			this->menuStrip1->GripMargin = System::Windows::Forms::Padding(2, 2, 0, 2);
			this->menuStrip1->ImageScalingSize = System::Drawing::Size(24, 24);
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->выходToolStripMenuItem });
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Padding = System::Windows::Forms::Padding(10, 3, 0, 3);
			this->menuStrip1->Size = System::Drawing::Size(992, 35);
			this->menuStrip1->TabIndex = 0;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// выходToolStripMenuItem
			// 
			this->выходToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->вернутс€ЌаЌачальныйЁкранToolStripMenuItem1,
					this->выход»зѕрограммыToolStripMenuItem1
			});
			this->выходToolStripMenuItem->Name = L"выходToolStripMenuItem";
			this->выходToolStripMenuItem->Size = System::Drawing::Size(80, 29);
			this->выходToolStripMenuItem->Text = L"¬ыход";
			// 
			// вернутс€ЌаЌачальныйЁкранToolStripMenuItem1
			// 
			this->вернутс€ЌаЌачальныйЁкранToolStripMenuItem1->Name = L"вернутс€ЌаЌачальныйЁкранToolStripMenuItem1";
			this->вернутс€ЌаЌачальныйЁкранToolStripMenuItem1->Size = System::Drawing::Size(357, 34);
			this->вернутс€ЌаЌачальныйЁкранToolStripMenuItem1->Text = L"¬ернутс€ на начальный экран";
			this->вернутс€ЌаЌачальныйЁкранToolStripMenuItem1->Click += gcnew System::EventHandler(this, &FindForEditForm::вернутс€ЌаЌачальныйЁкранToolStripMenuItem1_Click);
			// 
			// выход»зѕрограммыToolStripMenuItem1
			// 
			this->выход»зѕрограммыToolStripMenuItem1->Name = L"выход»зѕрограммыToolStripMenuItem1";
			this->выход»зѕрограммыToolStripMenuItem1->Size = System::Drawing::Size(357, 34);
			this->выход»зѕрограммыToolStripMenuItem1->Text = L"¬ыход из программы";
			this->выход»зѕрограммыToolStripMenuItem1->Click += gcnew System::EventHandler(this, &FindForEditForm::выход»зѕрограммыToolStripMenuItem1_Click);
			// 
			// choiceOfTypeBook
			// 
			this->choiceOfTypeBook->AutoCompleteCustomSource->AddRange(gcnew cli::array< System::String^  >(2) { L"“ехническа€", L"’удожественна€" });
			this->choiceOfTypeBook->FormattingEnabled = true;
			this->choiceOfTypeBook->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"“ехническа€", L"’удожественна€" });
			this->choiceOfTypeBook->Location = System::Drawing::Point(710, 401);
			this->choiceOfTypeBook->Name = L"choiceOfTypeBook";
			this->choiceOfTypeBook->Size = System::Drawing::Size(236, 30);
			this->choiceOfTypeBook->TabIndex = 1;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(706, 378);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(229, 22);
			this->label1->TabIndex = 2;
			this->label1->Text = L"¬ыберите тип литературы";
			// 
			// nameBookTextBox
			// 
			this->nameBookTextBox->Location = System::Drawing::Point(13, 403);
			this->nameBookTextBox->Name = L"nameBookTextBox";
			this->nameBookTextBox->Size = System::Drawing::Size(437, 28);
			this->nameBookTextBox->TabIndex = 3;
			// 
			// FindButton
			// 
			this->FindButton->Location = System::Drawing::Point(186, 453);
			this->FindButton->Name = L"FindButton";
			this->FindButton->Size = System::Drawing::Size(75, 34);
			this->FindButton->TabIndex = 6;
			this->FindButton->Text = L"ѕоиск";
			this->FindButton->UseVisualStyleBackColor = true;
			this->FindButton->Click += gcnew System::EventHandler(this, &FindForEditForm::FindButton_Click);
			// 
			// BackToStartMenu
			// 
			this->BackToStartMenu->Location = System::Drawing::Point(869, 453);
			this->BackToStartMenu->Name = L"BackToStartMenu";
			this->BackToStartMenu->Size = System::Drawing::Size(108, 34);
			this->BackToStartMenu->TabIndex = 8;
			this->BackToStartMenu->Text = L"¬ начало";
			this->BackToStartMenu->UseVisualStyleBackColor = true;
			this->BackToStartMenu->Click += gcnew System::EventHandler(this, &FindForEditForm::BackToStartMenu_Click);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(12, 378);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(249, 22);
			this->label3->TabIndex = 9;
			this->label3->Text = L"¬ведите данные дл€ поиска";
			// 
			// BackToMenu
			// 
			this->BackToMenu->Location = System::Drawing::Point(790, 453);
			this->BackToMenu->Name = L"BackToMenu";
			this->BackToMenu->Size = System::Drawing::Size(73, 34);
			this->BackToMenu->TabIndex = 11;
			this->BackToMenu->Text = L"Ќазад";
			this->BackToMenu->UseVisualStyleBackColor = true;
			this->BackToMenu->Click += gcnew System::EventHandler(this, &FindForEditForm::BackToMenu_Click);
			// 
			// helpOfSearchButton
			// 
			this->helpOfSearchButton->Location = System::Drawing::Point(466, 401);
			this->helpOfSearchButton->Name = L"helpOfSearchButton";
			this->helpOfSearchButton->Size = System::Drawing::Size(159, 30);
			this->helpOfSearchButton->TabIndex = 14;
			this->helpOfSearchButton->Text = L"ѕравила поиска";
			this->helpOfSearchButton->UseVisualStyleBackColor = true;
			this->helpOfSearchButton->Click += gcnew System::EventHandler(this, &FindForEditForm::helpOfSearchButton_Click);
			// 
			// dataGridView1
			// 
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(4) {
				this->nameBook,
					this->nameAutor, this->yearOfRelease, this->Availability
			});
			this->dataGridView1->Location = System::Drawing::Point(13, 38);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->RowHeadersWidth = 62;
			this->dataGridView1->RowTemplate->Height = 28;
			this->dataGridView1->Size = System::Drawing::Size(964, 313);
			this->dataGridView1->TabIndex = 15;
			// 
			// nameBook
			// 
			this->nameBook->HeaderText = L"Ќазвание";
			this->nameBook->MinimumWidth = 8;
			this->nameBook->Name = L"nameBook";
			this->nameBook->Width = 350;
			// 
			// nameAutor
			// 
			this->nameAutor->HeaderText = L"јвтор";
			this->nameAutor->MinimumWidth = 8;
			this->nameAutor->Name = L"nameAutor";
			this->nameAutor->Width = 250;
			// 
			// yearOfRelease
			// 
			this->yearOfRelease->HeaderText = L"√од выпуска";
			this->yearOfRelease->MinimumWidth = 8;
			this->yearOfRelease->Name = L"yearOfRelease";
			this->yearOfRelease->Width = 150;
			// 
			// Availability
			// 
			this->Availability->HeaderText = L"Ќаличие";
			this->Availability->MinimumWidth = 8;
			this->Availability->Name = L"Availability";
			this->Availability->Width = 150;
			// 
			// EditEntryButton
			// 
			this->EditEntryButton->Location = System::Drawing::Point(13, 453);
			this->EditEntryButton->Name = L"EditEntryButton";
			this->EditEntryButton->Size = System::Drawing::Size(167, 34);
			this->EditEntryButton->TabIndex = 16;
			this->EditEntryButton->Text = L"–едактирование";
			this->EditEntryButton->UseVisualStyleBackColor = true;
			this->EditEntryButton->Click += gcnew System::EventHandler(this, &FindForEditForm::EditEntryButton_Click);
			// 
			// ShowAllLinesButton
			// 
			this->ShowAllLinesButton->Location = System::Drawing::Point(267, 453);
			this->ShowAllLinesButton->Name = L"ShowAllLinesButton";
			this->ShowAllLinesButton->Size = System::Drawing::Size(193, 34);
			this->ShowAllLinesButton->TabIndex = 17;
			this->ShowAllLinesButton->Text = L"ѕоказать все записи";
			this->ShowAllLinesButton->UseVisualStyleBackColor = true;
			this->ShowAllLinesButton->Click += gcnew System::EventHandler(this, &FindForEditForm::ShowAllLinesButton_Click);
			// 
			// ExitButton
			// 
			this->ExitButton->Location = System::Drawing::Point(710, 453);
			this->ExitButton->Name = L"ExitButton";
			this->ExitButton->Size = System::Drawing::Size(74, 34);
			this->ExitButton->TabIndex = 18;
			this->ExitButton->Text = L"¬ыход";
			this->ExitButton->UseVisualStyleBackColor = true;
			this->ExitButton->Click += gcnew System::EventHandler(this, &FindForEditForm::ExitButton_Click);
			// 
			// deleteLineButton
			// 
			this->deleteLineButton->Location = System::Drawing::Point(466, 453);
			this->deleteLineButton->Name = L"deleteLineButton";
			this->deleteLineButton->Size = System::Drawing::Size(159, 34);
			this->deleteLineButton->TabIndex = 19;
			this->deleteLineButton->Text = L"”далить запись";
			this->deleteLineButton->UseVisualStyleBackColor = true;
			this->deleteLineButton->Click += gcnew System::EventHandler(this, &FindForEditForm::deleteLineButton_Click);
			// 
			// FindForEditForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(10, 22);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(992, 503);
			this->Controls->Add(this->deleteLineButton);
			this->Controls->Add(this->ExitButton);
			this->Controls->Add(this->ShowAllLinesButton);
			this->Controls->Add(this->EditEntryButton);
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->helpOfSearchButton);
			this->Controls->Add(this->BackToMenu);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->BackToStartMenu);
			this->Controls->Add(this->FindButton);
			this->Controls->Add(this->nameBookTextBox);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->choiceOfTypeBook);
			this->Controls->Add(this->menuStrip1);
			this->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->MainMenuStrip = this->menuStrip1;
			this->MaximizeBox = false;
			this->MaximumSize = System::Drawing::Size(1014, 559);
			this->MinimumSize = System::Drawing::Size(1014, 559);
			this->Name = L"FindForEditForm";
			this->ShowIcon = false;
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"ѕоиск наличи€ записи";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &FindForEditForm::FindForEditForm_FormClosing);
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void выход»зѕрограммыToolStripMenuItem1_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void вернутс€ЌаЌачальныйЁкранToolStripMenuItem1_Click(System::Object^ sender, System::EventArgs^ e);

private: System::Void BackToStartMenu_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void BackToMenu_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void FindButton_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void helpOfSearchButton_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void ShowAllLinesButton_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void ExitButton_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void EditEntryButton_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void deleteLineButton_Click(System::Object^ sender, System::EventArgs^ e);
	   
private: System::Void FindForEditForm_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e);
};

}
