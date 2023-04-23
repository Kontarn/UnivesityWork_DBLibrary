#pragma once
#include "FindForEditForm.h"
#include "StartMenuForm.h"
#include "DBLibLibrary.h"

namespace DBLibClient {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for editingWindowForm
	/// </summary>
	public ref class editingWindowForm : public System::Windows::Forms::Form
	{
	private:
		String^ nameBook;
		String^ nameAutor;
		String^ yearOfRelease;
		String^ availability;
		String^ oldInpString; // Ïåğåäàííàÿ ñòğîêà äëÿ ğåäàêòèğîâàíèÿ
		String^ typeOfLit;
	public:
		editingWindowForm(String^ nameBook, String^ nameAutor,
			String^ yearOfRelease, String^ availability, String^ TypeOfLit)
		{
			InitializeComponent();
			this->typeOfLit = TypeOfLit;
			this->nameBook = nameBook;
			this->nameAutor = nameAutor;
			this->yearOfRelease = yearOfRelease;
			this->availability = availability;
			// Ñòàğàÿ ñòğîêà
			oldInpString = nameBook + ", " + nameAutor + ", " + yearOfRelease + "; " + availability;

			nameBookTextBox->Text = nameBook;
			AutorNameTextBox->Text = nameAutor;
			yearOfReleaseTextBox->Text = yearOfRelease;
			AvailabilityTextBox->Text = availability;
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~editingWindowForm()
		{
			if (components)
			{
				delete components;
			}
		}
	public: System::Windows::Forms::TextBox^ AvailabilityTextBox;
	protected:
	private: System::Windows::Forms::Label^ label6;
	public: System::Windows::Forms::TextBox^ yearOfReleaseTextBox;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label4;
	public: System::Windows::Forms::TextBox^ AutorNameTextBox;
	private: System::Windows::Forms::Label^ label3;

	private: System::Windows::Forms::Button^ HelpButton;
	private: System::Windows::Forms::Label^ label1;

	private: System::Windows::Forms::Button^ BackButton;
	private: System::Windows::Forms::Button^ edititngDataButton;

	public: System::Windows::Forms::TextBox^ nameBookTextBox;
	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^ âûõîäToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ âûõîîäÍàÍà÷àëüíûéİêğàíToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ âûõîäÈçÏğîãğàììûToolStripMenuItem;

	protected:




	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->AvailabilityTextBox = (gcnew System::Windows::Forms::TextBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->yearOfReleaseTextBox = (gcnew System::Windows::Forms::TextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->AutorNameTextBox = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->HelpButton = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->BackButton = (gcnew System::Windows::Forms::Button());
			this->edititngDataButton = (gcnew System::Windows::Forms::Button());
			this->nameBookTextBox = (gcnew System::Windows::Forms::TextBox());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->âûõîäToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->âûõîîäÍàÍà÷àëüíûéİêğàíToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->âûõîäÈçÏğîãğàììûToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// AvailabilityTextBox
			// 
			this->AvailabilityTextBox->Location = System::Drawing::Point(754, 104);
			this->AvailabilityTextBox->Name = L"AvailabilityTextBox";
			this->AvailabilityTextBox->Size = System::Drawing::Size(77, 26);
			this->AvailabilityTextBox->TabIndex = 31;
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(750, 81);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(76, 20);
			this->label6->TabIndex = 30;
			this->label6->Text = L"Íàëè÷èå";
			// 
			// yearOfReleaseTextBox
			// 
			this->yearOfReleaseTextBox->Location = System::Drawing::Point(645, 104);
			this->yearOfReleaseTextBox->Name = L"yearOfReleaseTextBox";
			this->yearOfReleaseTextBox->Size = System::Drawing::Size(99, 26);
			this->yearOfReleaseTextBox->TabIndex = 29;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(641, 81);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(103, 20);
			this->label5->TabIndex = 28;
			this->label5->Text = L"Ãîä âûïóñêà";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(389, 81);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(56, 20);
			this->label4->TabIndex = 27;
			this->label4->Text = L"Àâòîğ";
			// 
			// AutorNameTextBox
			// 
			this->AutorNameTextBox->Location = System::Drawing::Point(393, 104);
			this->AutorNameTextBox->Name = L"AutorNameTextBox";
			this->AutorNameTextBox->Size = System::Drawing::Size(246, 26);
			this->AutorNameTextBox->TabIndex = 26;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(6, 81);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(129, 20);
			this->label3->TabIndex = 25;
			this->label3->Text = L"Íàçâàíèå êíèãè";
			// 
			// HelpButton
			// 
			this->HelpButton->Location = System::Drawing::Point(841, 100);
			this->HelpButton->Name = L"HelpButton";
			this->HelpButton->Size = System::Drawing::Size(97, 34);
			this->HelpButton->TabIndex = 23;
			this->HelpButton->Text = L"Ïîìîùü";
			this->HelpButton->UseVisualStyleBackColor = true;
			this->HelpButton->Click += gcnew System::EventHandler(this, &editingWindowForm::HelpButton_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(6, 55);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(142, 20);
			this->label1->TabIndex = 22;
			this->label1->Text = L"Ââåäèòå äàííûå:";
			// 
			// BackButton
			// 
			this->BackButton->Location = System::Drawing::Point(656, 152);
			this->BackButton->Name = L"BackButton";
			this->BackButton->Size = System::Drawing::Size(107, 47);
			this->BackButton->TabIndex = 20;
			this->BackButton->Text = L"Íàçàä";
			this->BackButton->UseVisualStyleBackColor = true;
			this->BackButton->Click += gcnew System::EventHandler(this, &editingWindowForm::BackButton_Click);
			// 
			// edititngDataButton
			// 
			this->edititngDataButton->Location = System::Drawing::Point(769, 152);
			this->edititngDataButton->Name = L"edititngDataButton";
			this->edititngDataButton->Size = System::Drawing::Size(166, 47);
			this->edititngDataButton->TabIndex = 19;
			this->edititngDataButton->Text = L"Ğåäàêòèğîâàòü";
			this->edititngDataButton->UseVisualStyleBackColor = true;
			this->edititngDataButton->Click += gcnew System::EventHandler(this, &editingWindowForm::edititngDataButton_Click);
			// 
			// nameBookTextBox
			// 
			this->nameBookTextBox->Location = System::Drawing::Point(10, 104);
			this->nameBookTextBox->Name = L"nameBookTextBox";
			this->nameBookTextBox->Size = System::Drawing::Size(377, 26);
			this->nameBookTextBox->TabIndex = 17;
			// 
			// menuStrip1
			// 
			this->menuStrip1->GripMargin = System::Windows::Forms::Padding(2, 2, 0, 2);
			this->menuStrip1->ImageScalingSize = System::Drawing::Size(24, 24);
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->âûõîäToolStripMenuItem });
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(948, 33);
			this->menuStrip1->TabIndex = 32;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// âûõîäToolStripMenuItem
			// 
			this->âûõîäToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->âûõîîäÍàÍà÷àëüíûéİêğàíToolStripMenuItem,
					this->âûõîäÈçÏğîãğàììûToolStripMenuItem
			});
			this->âûõîäToolStripMenuItem->Name = L"âûõîäToolStripMenuItem";
			this->âûõîäToolStripMenuItem->Size = System::Drawing::Size(80, 29);
			this->âûõîäToolStripMenuItem->Text = L"Âûõîä";
			// 
			// âûõîîäÍàÍà÷àëüíûéİêğàíToolStripMenuItem
			// 
			this->âûõîîäÍàÍà÷àëüíûéİêğàíToolStripMenuItem->Name = L"âûõîîäÍàÍà÷àëüíûéİêğàíToolStripMenuItem";
			this->âûõîîäÍàÍà÷àëüíûéİêğàíToolStripMenuItem->Size = System::Drawing::Size(347, 34);
			this->âûõîîäÍàÍà÷àëüíûéİêğàíToolStripMenuItem->Text = L"Âûõîîä íà íà÷àëüíûé ıêğàí";
			this->âûõîîäÍàÍà÷àëüíûéİêğàíToolStripMenuItem->Click += gcnew System::EventHandler(this, &editingWindowForm::âûõîîäÍàÍà÷àëüíûéİêğàíToolStripMenuItem_Click);
			// 
			// âûõîäÈçÏğîãğàììûToolStripMenuItem
			// 
			this->âûõîäÈçÏğîãğàììûToolStripMenuItem->Name = L"âûõîäÈçÏğîãğàììûToolStripMenuItem";
			this->âûõîäÈçÏğîãğàììûToolStripMenuItem->Size = System::Drawing::Size(347, 34);
			this->âûõîäÈçÏğîãğàììûToolStripMenuItem->Text = L"Âûõîä èç ïğîãğàììû";
			this->âûõîäÈçÏğîãğàììûToolStripMenuItem->Click += gcnew System::EventHandler(this, &editingWindowForm::âûõîäÈçÏğîãğàììûToolStripMenuItem_Click);
			// 
			// editingWindowForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(948, 210);
			this->Controls->Add(this->AvailabilityTextBox);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->yearOfReleaseTextBox);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->AutorNameTextBox);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->HelpButton);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->BackButton);
			this->Controls->Add(this->edititngDataButton);
			this->Controls->Add(this->nameBookTextBox);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->MaximizeBox = false;
			this->MaximumSize = System::Drawing::Size(970, 266);
			this->MinimumSize = System::Drawing::Size(970, 266);
			this->Name = L"editingWindowForm";
			this->ShowIcon = false;
			this->Text = L"Ğåäàêòèğîâàíèå çàïèñåé";
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void HelpButton_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void âûõîäÈçÏğîãğàììûToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void BackButton_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void âûõîîäÍàÍà÷àëüíûéİêğàíToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void edititngDataButton_Click(System::Object^ sender, System::EventArgs^ e);
	};
}

