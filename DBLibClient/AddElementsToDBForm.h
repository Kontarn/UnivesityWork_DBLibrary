#pragma once
#include "ChoiceOfMethodEditForm.h"
#include "StartMenuForm.h"
#include "DBLibLibrary.h"
#include <cstring>
#include <string>
#include <vcclr.h>

namespace DBLibClient {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Runtime::InteropServices;

	/// <summary>
	/// Summary for AddElementsToDBForm
	/// </summary>
	public ref class AddElementsToDBForm : public System::Windows::Forms::Form
	{
	public:
		AddElementsToDBForm(void)
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
		~AddElementsToDBForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^ nameBookTextBox;
	protected:

	private: System::Windows::Forms::Button^ toStartButton;
	private: System::Windows::Forms::Button^ AddDataButton;
	protected:


	private: System::Windows::Forms::Button^ BackButton;
	private: System::Windows::Forms::ComboBox^ typeBookComboBox;


	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^ ‚˚ıÓ‰ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ ‚˚ıÓ‰Õ‡Õ‡˜‡Î¸Ì˚È›Í‡ÌToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ ‚˚ıÓ‰»ÁœÓ„‡ÏÏ˚ToolStripMenuItem;
	private: System::Windows::Forms::Button^ HelpButton;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::TextBox^ AutorNameTextBox;

	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label5;


	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::TextBox^ AvailabilityTextBox;
	private: System::Windows::Forms::ComboBox^ yearOfReleaseComboBox;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::TextBox^ priceTextBox;



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
			this->nameBookTextBox = (gcnew System::Windows::Forms::TextBox());
			this->toStartButton = (gcnew System::Windows::Forms::Button());
			this->AddDataButton = (gcnew System::Windows::Forms::Button());
			this->BackButton = (gcnew System::Windows::Forms::Button());
			this->typeBookComboBox = (gcnew System::Windows::Forms::ComboBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->‚˚ıÓ‰ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->‚˚ıÓ‰Õ‡Õ‡˜‡Î¸Ì˚È›Í‡ÌToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->‚˚ıÓ‰»ÁœÓ„‡ÏÏ˚ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->HelpButton = (gcnew System::Windows::Forms::Button());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->AutorNameTextBox = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->AvailabilityTextBox = (gcnew System::Windows::Forms::TextBox());
			this->yearOfReleaseComboBox = (gcnew System::Windows::Forms::ComboBox());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->priceTextBox = (gcnew System::Windows::Forms::TextBox());
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// nameBookTextBox
			// 
			this->nameBookTextBox->Location = System::Drawing::Point(8, 60);
			this->nameBookTextBox->Margin = System::Windows::Forms::Padding(2);
			this->nameBookTextBox->Name = L"nameBookTextBox";
			this->nameBookTextBox->Size = System::Drawing::Size(253, 20);
			this->nameBookTextBox->TabIndex = 0;
			// 
			// toStartButton
			// 
			this->toStartButton->Location = System::Drawing::Point(546, 101);
			this->toStartButton->Margin = System::Windows::Forms::Padding(2);
			this->toStartButton->Name = L"toStartButton";
			this->toStartButton->Size = System::Drawing::Size(69, 24);
			this->toStartButton->TabIndex = 1;
			this->toStartButton->Text = L"¬ Ì‡˜‡ÎÓ";
			this->toStartButton->UseVisualStyleBackColor = true;
			this->toStartButton->Click += gcnew System::EventHandler(this, &AddElementsToDBForm::toStartButton_Click);
			// 
			// AddDataButton
			// 
			this->AddDataButton->Location = System::Drawing::Point(619, 101);
			this->AddDataButton->Margin = System::Windows::Forms::Padding(2);
			this->AddDataButton->Name = L"AddDataButton";
			this->AddDataButton->Size = System::Drawing::Size(67, 24);
			this->AddDataButton->TabIndex = 2;
			this->AddDataButton->Text = L"ƒÓ·‡‚ËÚ¸";
			this->AddDataButton->UseVisualStyleBackColor = true;
			this->AddDataButton->Click += gcnew System::EventHandler(this, &AddElementsToDBForm::AddDataButton_Click);
			// 
			// BackButton
			// 
			this->BackButton->Location = System::Drawing::Point(492, 101);
			this->BackButton->Margin = System::Windows::Forms::Padding(2);
			this->BackButton->Name = L"BackButton";
			this->BackButton->Size = System::Drawing::Size(50, 24);
			this->BackButton->TabIndex = 3;
			this->BackButton->Text = L"Õ‡Á‡‰";
			this->BackButton->UseVisualStyleBackColor = true;
			this->BackButton->Click += gcnew System::EventHandler(this, &AddElementsToDBForm::BackButton_Click);
			// 
			// typeBookComboBox
			// 
			this->typeBookComboBox->FormattingEnabled = true;
			this->typeBookComboBox->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"“ÂıÌË˜ÂÒÍ‡ˇ", L"’Û‰ÓÊÂÒÚ‚ÂÌÌ‡ˇ" });
			this->typeBookComboBox->Location = System::Drawing::Point(8, 104);
			this->typeBookComboBox->Margin = System::Windows::Forms::Padding(2);
			this->typeBookComboBox->Name = L"typeBookComboBox";
			this->typeBookComboBox->Size = System::Drawing::Size(111, 21);
			this->typeBookComboBox->TabIndex = 4;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(5, 29);
			this->label1->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(93, 13);
			this->label1->TabIndex = 5;
			this->label1->Text = L"¬‚Â‰ËÚÂ ‰‡ÌÌ˚Â:";
			// 
			// menuStrip1
			// 
			this->menuStrip1->ImageScalingSize = System::Drawing::Size(24, 24);
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->‚˚ıÓ‰ToolStripMenuItem });
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Padding = System::Windows::Forms::Padding(4, 1, 0, 1);
			this->menuStrip1->Size = System::Drawing::Size(697, 24);
			this->menuStrip1->TabIndex = 6;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// ‚˚ıÓ‰ToolStripMenuItem
			// 
			this->‚˚ıÓ‰ToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->‚˚ıÓ‰Õ‡Õ‡˜‡Î¸Ì˚È›Í‡ÌToolStripMenuItem,
					this->‚˚ıÓ‰»ÁœÓ„‡ÏÏ˚ToolStripMenuItem
			});
			this->‚˚ıÓ‰ToolStripMenuItem->Name = L"‚˚ıÓ‰ToolStripMenuItem";
			this->‚˚ıÓ‰ToolStripMenuItem->Size = System::Drawing::Size(54, 22);
			this->‚˚ıÓ‰ToolStripMenuItem->Text = L"¬˚ıÓ‰";
			// 
			// ‚˚ıÓ‰Õ‡Õ‡˜‡Î¸Ì˚È›Í‡ÌToolStripMenuItem
			// 
			this->‚˚ıÓ‰Õ‡Õ‡˜‡Î¸Ì˚È›Í‡ÌToolStripMenuItem->Name = L"‚˚ıÓ‰Õ‡Õ‡˜‡Î¸Ì˚È›Í‡ÌToolStripMenuItem";
			this->‚˚ıÓ‰Õ‡Õ‡˜‡Î¸Ì˚È›Í‡ÌToolStripMenuItem->Size = System::Drawing::Size(225, 22);
			this->‚˚ıÓ‰Õ‡Õ‡˜‡Î¸Ì˚È›Í‡ÌToolStripMenuItem->Text = L"¬˚ıÓ‰ Ì‡ Ì‡˜‡Î¸Ì˚È ˝Í‡Ì";
			this->‚˚ıÓ‰Õ‡Õ‡˜‡Î¸Ì˚È›Í‡ÌToolStripMenuItem->Click += gcnew System::EventHandler(this, &AddElementsToDBForm::‚˚ıÓ‰Õ‡Õ‡˜‡Î¸Ì˚È›Í‡ÌToolStripMenuItem_Click);
			// 
			// ‚˚ıÓ‰»ÁœÓ„‡ÏÏ˚ToolStripMenuItem
			// 
			this->‚˚ıÓ‰»ÁœÓ„‡ÏÏ˚ToolStripMenuItem->Name = L"‚˚ıÓ‰»ÁœÓ„‡ÏÏ˚ToolStripMenuItem";
			this->‚˚ıÓ‰»ÁœÓ„‡ÏÏ˚ToolStripMenuItem->Size = System::Drawing::Size(225, 22);
			this->‚˚ıÓ‰»ÁœÓ„‡ÏÏ˚ToolStripMenuItem->Text = L"¬˚ıÓ‰ ËÁ ÔÓ„‡ÏÏ˚";
			this->‚˚ıÓ‰»ÁœÓ„‡ÏÏ˚ToolStripMenuItem->Click += gcnew System::EventHandler(this, &AddElementsToDBForm::‚˚ıÓ‰»ÁœÓ„‡ÏÏ˚ToolStripMenuItem_Click);
			// 
			// HelpButton
			// 
			this->HelpButton->Location = System::Drawing::Point(621, 58);
			this->HelpButton->Margin = System::Windows::Forms::Padding(2);
			this->HelpButton->Name = L"HelpButton";
			this->HelpButton->Size = System::Drawing::Size(65, 22);
			this->HelpButton->TabIndex = 7;
			this->HelpButton->Text = L"œÓÏÓ˘¸";
			this->HelpButton->UseVisualStyleBackColor = true;
			this->HelpButton->Click += gcnew System::EventHandler(this, &AddElementsToDBForm::HelpButton_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(5, 89);
			this->label2->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(210, 13);
			this->label2->TabIndex = 8;
			this->label2->Text = L"¬˚·ÂËÚÂ ÚËÔ ‰Ó·‡‚ÎˇÂÏÓÈ ÎËÚÂ‡ÚÛ˚";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(5, 46);
			this->label3->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(89, 13);
			this->label3->TabIndex = 9;
			this->label3->Text = L"Õ‡Á‚‡ÌËÂ ÍÌË„Ë";
			// 
			// AutorNameTextBox
			// 
			this->AutorNameTextBox->Location = System::Drawing::Point(263, 60);
			this->AutorNameTextBox->Margin = System::Windows::Forms::Padding(2);
			this->AutorNameTextBox->Name = L"AutorNameTextBox";
			this->AutorNameTextBox->Size = System::Drawing::Size(165, 20);
			this->AutorNameTextBox->TabIndex = 10;
			this->AutorNameTextBox->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &AddElementsToDBForm::AutorNameTextBox_KeyPress);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(261, 46);
			this->label4->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(37, 13);
			this->label4->TabIndex = 11;
			this->label4->Text = L"¿‚ÚÓ";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(429, 46);
			this->label5->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(71, 13);
			this->label5->TabIndex = 12;
			this->label5->Text = L"√Ó‰ ‚˚ÔÛÒÍ‡";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(501, 46);
			this->label6->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(50, 13);
			this->label6->TabIndex = 15;
			this->label6->Text = L"Õ‡ÎË˜ËÂ";
			// 
			// AvailabilityTextBox
			// 
			this->AvailabilityTextBox->Location = System::Drawing::Point(504, 60);
			this->AvailabilityTextBox->Margin = System::Windows::Forms::Padding(2);
			this->AvailabilityTextBox->Name = L"AvailabilityTextBox";
			this->AvailabilityTextBox->Size = System::Drawing::Size(49, 20);
			this->AvailabilityTextBox->TabIndex = 16;
			this->AvailabilityTextBox->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &AddElementsToDBForm::AvailabilityTextBox_KeyPress);
			this->AvailabilityTextBox->Validating += gcnew System::ComponentModel::CancelEventHandler(this, &AddElementsToDBForm::AvailabilityTextBox_Validating);
			// 
			// yearOfReleaseComboBox
			// 
			this->yearOfReleaseComboBox->FormattingEnabled = true;
			this->yearOfReleaseComboBox->Location = System::Drawing::Point(432, 59);
			this->yearOfReleaseComboBox->Name = L"yearOfReleaseComboBox";
			this->yearOfReleaseComboBox->Size = System::Drawing::Size(67, 21);
			this->yearOfReleaseComboBox->TabIndex = 17;
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(558, 46);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(33, 13);
			this->label7->TabIndex = 18;
			this->label7->Text = L"÷ÂÌ‡";
			// 
			// priceTextBox
			// 
			this->priceTextBox->Location = System::Drawing::Point(559, 60);
			this->priceTextBox->Name = L"priceTextBox";
			this->priceTextBox->Size = System::Drawing::Size(57, 20);
			this->priceTextBox->TabIndex = 19;
			this->priceTextBox->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &AddElementsToDBForm::priceTextBox_KeyPress);
			// 
			// AddElementsToDBForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(697, 144);
			this->Controls->Add(this->priceTextBox);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->yearOfReleaseComboBox);
			this->Controls->Add(this->AvailabilityTextBox);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->AutorNameTextBox);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->HelpButton);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->typeBookComboBox);
			this->Controls->Add(this->BackButton);
			this->Controls->Add(this->AddDataButton);
			this->Controls->Add(this->toStartButton);
			this->Controls->Add(this->nameBookTextBox);
			this->Controls->Add(this->menuStrip1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MainMenuStrip = this->menuStrip1;
			this->Margin = System::Windows::Forms::Padding(2);
			this->MaximizeBox = false;
			this->Name = L"AddElementsToDBForm";
			this->ShowIcon = false;
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"ƒÓ·‡‚ÎÂÌËÂ ÌÓ‚˚ı Á‡ÔËÒÂÈ";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &AddElementsToDBForm::AddElementsToDBForm_FormClosing);
			this->Load += gcnew System::EventHandler(this, &AddElementsToDBForm::AddElementsToDBForm_Load);
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
private: System::Void HelpButton_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void BackButton_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void toStartButton_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void ‚˚ıÓ‰»ÁœÓ„‡ÏÏ˚ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void ‚˚ıÓ‰Õ‡Õ‡˜‡Î¸Ì˚È›Í‡ÌToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void AddDataButton_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void AddElementsToDBForm_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e);
private: System::Void AutorNameTextBox_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e);
private: System::Void AddElementsToDBForm_Load(System::Object^ sender, System::EventArgs^ e);
private: System::Void AvailabilityTextBox_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e);
private: System::Void AvailabilityTextBox_Validating(System::Object^ sender, System::ComponentModel::CancelEventArgs^ e);
private: System::Void priceTextBox_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e);
};
}
