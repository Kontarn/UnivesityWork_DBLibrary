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
	private: System::Windows::Forms::ToolStripMenuItem^ âûõîäToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ âåğíóòñÿÍàÍà÷àëüíûéİêğàíToolStripMenuItem1;


	private: System::Windows::Forms::ToolStripMenuItem^ âûõîäÈçÏğîãğàììûToolStripMenuItem1;
	private: System::Windows::Forms::ComboBox^ choiceOfTypeBook;


	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TextBox^ textBox1;





	private: System::Windows::Forms::Button^ FindButton;

	private: System::Windows::Forms::Button^ BackToStartMenu;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Button^ Help;
	private: System::Windows::Forms::Button^ BackToMenu;


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
			this->âûõîäToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->âåğíóòñÿÍàÍà÷àëüíûéİêğàíToolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->âûõîäÈçÏğîãğàììûToolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->choiceOfTypeBook = (gcnew System::Windows::Forms::ComboBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->FindButton = (gcnew System::Windows::Forms::Button());
			this->BackToStartMenu = (gcnew System::Windows::Forms::Button());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->Help = (gcnew System::Windows::Forms::Button());
			this->BackToMenu = (gcnew System::Windows::Forms::Button());
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// menuStrip1
			// 
			this->menuStrip1->GripMargin = System::Windows::Forms::Padding(2, 2, 0, 2);
			this->menuStrip1->ImageScalingSize = System::Drawing::Size(24, 24);
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->âûõîäToolStripMenuItem });
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Padding = System::Windows::Forms::Padding(10, 3, 0, 3);
			this->menuStrip1->Size = System::Drawing::Size(412, 35);
			this->menuStrip1->TabIndex = 0;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// âûõîäToolStripMenuItem
			// 
			this->âûõîäToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->âåğíóòñÿÍàÍà÷àëüíûéİêğàíToolStripMenuItem1,
					this->âûõîäÈçÏğîãğàììûToolStripMenuItem1
			});
			this->âûõîäToolStripMenuItem->Name = L"âûõîäToolStripMenuItem";
			this->âûõîäToolStripMenuItem->Size = System::Drawing::Size(80, 29);
			this->âûõîäToolStripMenuItem->Text = L"Âûõîä";
			// 
			// âåğíóòñÿÍàÍà÷àëüíûéİêğàíToolStripMenuItem1
			// 
			this->âåğíóòñÿÍàÍà÷àëüíûéİêğàíToolStripMenuItem1->Name = L"âåğíóòñÿÍàÍà÷àëüíûéİêğàíToolStripMenuItem1";
			this->âåğíóòñÿÍàÍà÷àëüíûéİêğàíToolStripMenuItem1->Size = System::Drawing::Size(357, 34);
			this->âåğíóòñÿÍàÍà÷àëüíûéİêğàíToolStripMenuItem1->Text = L"Âåğíóòñÿ íà íà÷àëüíûé ıêğàí";
			this->âåğíóòñÿÍàÍà÷àëüíûéİêğàíToolStripMenuItem1->Click += gcnew System::EventHandler(this, &FindForEditForm::âåğíóòñÿÍàÍà÷àëüíûéİêğàíToolStripMenuItem1_Click);
			// 
			// âûõîäÈçÏğîãğàììûToolStripMenuItem1
			// 
			this->âûõîäÈçÏğîãğàììûToolStripMenuItem1->Name = L"âûõîäÈçÏğîãğàììûToolStripMenuItem1";
			this->âûõîäÈçÏğîãğàììûToolStripMenuItem1->Size = System::Drawing::Size(357, 34);
			this->âûõîäÈçÏğîãğàììûToolStripMenuItem1->Text = L"Âûõîä èç ïğîãğàììû";
			this->âûõîäÈçÏğîãğàììûToolStripMenuItem1->Click += gcnew System::EventHandler(this, &FindForEditForm::âûõîäÈçÏğîãğàììûToolStripMenuItem1_Click);
			// 
			// choiceOfTypeBook
			// 
			this->choiceOfTypeBook->AutoCompleteCustomSource->AddRange(gcnew cli::array< System::String^  >(2) { L"Òåõíè÷åñêàÿ", L"Õóäîæåñòâåííàÿ" });
			this->choiceOfTypeBook->FormattingEnabled = true;
			this->choiceOfTypeBook->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"Òåõíè÷åñêàÿ", L"Õóäîæåñòâåííàÿ" });
			this->choiceOfTypeBook->Location = System::Drawing::Point(18, 138);
			this->choiceOfTypeBook->Name = L"choiceOfTypeBook";
			this->choiceOfTypeBook->Size = System::Drawing::Size(236, 30);
			this->choiceOfTypeBook->TabIndex = 1;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(13, 113);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(229, 22);
			this->label1->TabIndex = 2;
			this->label1->Text = L"Âûáåğèòå òèï ëèòåğàòóğû";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(18, 72);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(370, 28);
			this->textBox1->TabIndex = 3;
			// 
			// FindButton
			// 
			this->FindButton->Location = System::Drawing::Point(317, 190);
			this->FindButton->Name = L"FindButton";
			this->FindButton->Size = System::Drawing::Size(83, 34);
			this->FindButton->TabIndex = 6;
			this->FindButton->Text = L"Ïîèñê";
			this->FindButton->UseVisualStyleBackColor = true;
			this->FindButton->Click += gcnew System::EventHandler(this, &FindForEditForm::FindButton_Click);
			// 
			// BackToStartMenu
			// 
			this->BackToStartMenu->Location = System::Drawing::Point(203, 190);
			this->BackToStartMenu->Name = L"BackToStartMenu";
			this->BackToStartMenu->Size = System::Drawing::Size(108, 34);
			this->BackToStartMenu->TabIndex = 8;
			this->BackToStartMenu->Text = L"Â íà÷àëî";
			this->BackToStartMenu->UseVisualStyleBackColor = true;
			this->BackToStartMenu->Click += gcnew System::EventHandler(this, &FindForEditForm::BackToStartMenu_Click);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(13, 46);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(249, 22);
			this->label3->TabIndex = 9;
			this->label3->Text = L"Ââåäèòå äàííûå äëÿ ïîèñêà";
			// 
			// Help
			// 
			this->Help->Location = System::Drawing::Point(296, 138);
			this->Help->Name = L"Help";
			this->Help->Size = System::Drawing::Size(104, 31);
			this->Help->TabIndex = 10;
			this->Help->Text = L"Ïîìîùü";
			this->Help->UseVisualStyleBackColor = true;
			this->Help->Click += gcnew System::EventHandler(this, &FindForEditForm::Help_Click);
			// 
			// BackToMenu
			// 
			this->BackToMenu->Location = System::Drawing::Point(89, 190);
			this->BackToMenu->Name = L"BackToMenu";
			this->BackToMenu->Size = System::Drawing::Size(108, 34);
			this->BackToMenu->TabIndex = 11;
			this->BackToMenu->Text = L"Íàçàä";
			this->BackToMenu->UseVisualStyleBackColor = true;
			this->BackToMenu->Click += gcnew System::EventHandler(this, &FindForEditForm::BackToMenu_Click);
			// 
			// FindForEditForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(10, 22);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(412, 241);
			this->Controls->Add(this->BackToMenu);
			this->Controls->Add(this->Help);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->BackToStartMenu);
			this->Controls->Add(this->FindButton);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->choiceOfTypeBook);
			this->Controls->Add(this->menuStrip1);
			this->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->MainMenuStrip = this->menuStrip1;
			this->MaximumSize = System::Drawing::Size(434, 297);
			this->MinimumSize = System::Drawing::Size(434, 297);
			this->Name = L"FindForEditForm";
			this->ShowIcon = false;
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Ïîèñê íàëè÷èÿ çàïèñè";
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void âûõîäÈçÏğîãğàììûToolStripMenuItem1_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void âåğíóòñÿÍàÍà÷àëüíûéİêğàíToolStripMenuItem1_Click(System::Object^ sender, System::EventArgs^ e);

private: System::Void BackToStartMenu_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void Help_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void BackToMenu_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void FindButton_Click(System::Object^ sender, System::EventArgs^ e);
};
}
