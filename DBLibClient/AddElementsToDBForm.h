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
	private: System::Windows::Forms::ToolStripMenuItem^ âûõîäToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ âûõîäÍàÍà÷àëüíûéİêğàíToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ âûõîäÈçÏğîãğàììûToolStripMenuItem;
	private: System::Windows::Forms::Button^ HelpButton;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::TextBox^ AutorNameTextBox;

	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::TextBox^ yearOfReleaseTextBox;

	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::TextBox^ AvailabilityTextBox;



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
			this->âûõîäToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->âûõîäÍàÍà÷àëüíûéİêğàíToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->âûõîäÈçÏğîãğàììûToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->HelpButton = (gcnew System::Windows::Forms::Button());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->AutorNameTextBox = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->yearOfReleaseTextBox = (gcnew System::Windows::Forms::TextBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->AvailabilityTextBox = (gcnew System::Windows::Forms::TextBox());
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// nameBookTextBox
			// 
			this->nameBookTextBox->Location = System::Drawing::Point(12, 93);
			this->nameBookTextBox->Name = L"nameBookTextBox";
			this->nameBookTextBox->Size = System::Drawing::Size(377, 26);
			this->nameBookTextBox->TabIndex = 0;
			// 
			// toStartButton
			// 
			this->toStartButton->Location = System::Drawing::Point(729, 151);
			this->toStartButton->Name = L"toStartButton";
			this->toStartButton->Size = System::Drawing::Size(104, 37);
			this->toStartButton->TabIndex = 1;
			this->toStartButton->Text = L"Â íà÷àëî";
			this->toStartButton->UseVisualStyleBackColor = true;
			this->toStartButton->Click += gcnew System::EventHandler(this, &AddElementsToDBForm::toStartButton_Click);
			// 
			// AddDataButton
			// 
			this->AddDataButton->Location = System::Drawing::Point(839, 151);
			this->AddDataButton->Name = L"AddDataButton";
			this->AddDataButton->Size = System::Drawing::Size(101, 37);
			this->AddDataButton->TabIndex = 2;
			this->AddDataButton->Text = L"Äîáàâèòü";
			this->AddDataButton->UseVisualStyleBackColor = true;
			this->AddDataButton->Click += gcnew System::EventHandler(this, &AddElementsToDBForm::AddDataButton_Click);
			// 
			// BackButton
			// 
			this->BackButton->Location = System::Drawing::Point(648, 151);
			this->BackButton->Name = L"BackButton";
			this->BackButton->Size = System::Drawing::Size(75, 37);
			this->BackButton->TabIndex = 3;
			this->BackButton->Text = L"Íàçàä";
			this->BackButton->UseVisualStyleBackColor = true;
			this->BackButton->Click += gcnew System::EventHandler(this, &AddElementsToDBForm::BackButton_Click);
			// 
			// typeBookComboBox
			// 
			this->typeBookComboBox->FormattingEnabled = true;
			this->typeBookComboBox->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"Òåõíè÷åñêàÿ", L"Õóäîæåñòâåííàÿ" });
			this->typeBookComboBox->Location = System::Drawing::Point(12, 160);
			this->typeBookComboBox->Name = L"typeBookComboBox";
			this->typeBookComboBox->Size = System::Drawing::Size(164, 28);
			this->typeBookComboBox->TabIndex = 4;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(8, 44);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(142, 20);
			this->label1->TabIndex = 5;
			this->label1->Text = L"Ââåäèòå äàííûå:";
			// 
			// menuStrip1
			// 
			this->menuStrip1->GripMargin = System::Windows::Forms::Padding(2, 2, 0, 2);
			this->menuStrip1->ImageScalingSize = System::Drawing::Size(24, 24);
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->âûõîäToolStripMenuItem });
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(952, 33);
			this->menuStrip1->TabIndex = 6;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// âûõîäToolStripMenuItem
			// 
			this->âûõîäToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->âûõîäÍàÍà÷àëüíûéİêğàíToolStripMenuItem,
					this->âûõîäÈçÏğîãğàììûToolStripMenuItem
			});
			this->âûõîäToolStripMenuItem->Name = L"âûõîäToolStripMenuItem";
			this->âûõîäToolStripMenuItem->Size = System::Drawing::Size(80, 29);
			this->âûõîäToolStripMenuItem->Text = L"Âûõîä";
			// 
			// âûõîäÍàÍà÷àëüíûéİêğàíToolStripMenuItem
			// 
			this->âûõîäÍàÍà÷àëüíûéİêğàíToolStripMenuItem->Name = L"âûõîäÍàÍà÷àëüíûéİêğàíToolStripMenuItem";
			this->âûõîäÍàÍà÷àëüíûéİêğàíToolStripMenuItem->Size = System::Drawing::Size(336, 34);
			this->âûõîäÍàÍà÷àëüíûéİêğàíToolStripMenuItem->Text = L"Âûõîä íà íà÷àëüíûé ıêğàí";
			this->âûõîäÍàÍà÷àëüíûéİêğàíToolStripMenuItem->Click += gcnew System::EventHandler(this, &AddElementsToDBForm::âûõîäÍàÍà÷àëüíûéİêğàíToolStripMenuItem_Click);
			// 
			// âûõîäÈçÏğîãğàììûToolStripMenuItem
			// 
			this->âûõîäÈçÏğîãğàììûToolStripMenuItem->Name = L"âûõîäÈçÏğîãğàììûToolStripMenuItem";
			this->âûõîäÈçÏğîãğàììûToolStripMenuItem->Size = System::Drawing::Size(336, 34);
			this->âûõîäÈçÏğîãğàììûToolStripMenuItem->Text = L"Âûõîä èç ïğîãğàììû";
			this->âûõîäÈçÏğîãğàììûToolStripMenuItem->Click += gcnew System::EventHandler(this, &AddElementsToDBForm::âûõîäÈçÏğîãğàììûToolStripMenuItem_Click);
			// 
			// HelpButton
			// 
			this->HelpButton->Location = System::Drawing::Point(843, 89);
			this->HelpButton->Name = L"HelpButton";
			this->HelpButton->Size = System::Drawing::Size(97, 34);
			this->HelpButton->TabIndex = 7;
			this->HelpButton->Text = L"Ïîìîùü";
			this->HelpButton->UseVisualStyleBackColor = true;
			this->HelpButton->Click += gcnew System::EventHandler(this, &AddElementsToDBForm::HelpButton_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(8, 137);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(319, 20);
			this->label2->TabIndex = 8;
			this->label2->Text = L"Âûáåğèòå òèï äîáàâëÿåìîé ëèòåğàòóğû";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(8, 70);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(129, 20);
			this->label3->TabIndex = 9;
			this->label3->Text = L"Íàçâàíèå êíèãè";
			// 
			// AutorNameTextBox
			// 
			this->AutorNameTextBox->Location = System::Drawing::Point(395, 93);
			this->AutorNameTextBox->Name = L"AutorNameTextBox";
			this->AutorNameTextBox->Size = System::Drawing::Size(246, 26);
			this->AutorNameTextBox->TabIndex = 10;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(391, 70);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(56, 20);
			this->label4->TabIndex = 11;
			this->label4->Text = L"Àâòîğ";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(643, 70);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(103, 20);
			this->label5->TabIndex = 12;
			this->label5->Text = L"Ãîä âûïóñêà";
			// 
			// yearOfReleaseTextBox
			// 
			this->yearOfReleaseTextBox->Location = System::Drawing::Point(647, 93);
			this->yearOfReleaseTextBox->Name = L"yearOfReleaseTextBox";
			this->yearOfReleaseTextBox->Size = System::Drawing::Size(99, 26);
			this->yearOfReleaseTextBox->TabIndex = 13;
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(752, 70);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(76, 20);
			this->label6->TabIndex = 15;
			this->label6->Text = L"Íàëè÷èå";
			// 
			// AvailabilityTextBox
			// 
			this->AvailabilityTextBox->Location = System::Drawing::Point(756, 93);
			this->AvailabilityTextBox->Name = L"AvailabilityTextBox";
			this->AvailabilityTextBox->Size = System::Drawing::Size(72, 26);
			this->AvailabilityTextBox->TabIndex = 16;
			// 
			// AddElementsToDBForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(952, 205);
			this->Controls->Add(this->AvailabilityTextBox);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->yearOfReleaseTextBox);
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
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"AddElementsToDBForm";
			this->ShowIcon = false;
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"AddElementsToDBForm";
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
private: System::Void HelpButton_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void BackButton_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void toStartButton_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void âûõîäÈçÏğîãğàììûToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void âûõîäÍàÍà÷àëüíûéİêğàíToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void AddDataButton_Click(System::Object^ sender, System::EventArgs^ e);
};
}
