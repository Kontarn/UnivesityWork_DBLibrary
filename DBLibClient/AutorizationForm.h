#pragma once
#include "StartMenuForm.h"
#include "ChoiceOfMethodEditForm.h"
namespace DBLibClient {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for EditDBForm
	/// </summary>
	public ref class AutorizationForm : public System::Windows::Forms::Form
	{
	public:
		AutorizationForm(void)
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
		~AutorizationForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	protected:
	private: System::Windows::Forms::ToolStripMenuItem^ âûõîäToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ âûõîäÍàÍà÷àëüíûéİêğàíToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ âûõîäÈçÏğîãğàììûToolStripMenuItem;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::GroupBox^ groupBox1;
	private: System::Windows::Forms::Button^ Autorization;
	private: System::Windows::Forms::Button^ BackToStartMenu;


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
			this->âûõîäÍàÍà÷àëüíûéİêğàíToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->âûõîäÈçÏğîãğàììûToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->Autorization = (gcnew System::Windows::Forms::Button());
			this->BackToStartMenu = (gcnew System::Windows::Forms::Button());
			this->menuStrip1->SuspendLayout();
			this->groupBox1->SuspendLayout();
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
			this->menuStrip1->Size = System::Drawing::Size(383, 36);
			this->menuStrip1->TabIndex = 0;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// âûõîäToolStripMenuItem
			// 
			this->âûõîäToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->âûõîäÍàÍà÷àëüíûéİêğàíToolStripMenuItem,
					this->âûõîäÈçÏğîãğàììûToolStripMenuItem
			});
			this->âûõîäToolStripMenuItem->Name = L"âûõîäToolStripMenuItem";
			this->âûõîäToolStripMenuItem->Size = System::Drawing::Size(80, 30);
			this->âûõîäToolStripMenuItem->Text = L"Âûõîä";
			// 
			// âûõîäÍàÍà÷àëüíûéİêğàíToolStripMenuItem
			// 
			this->âûõîäÍàÍà÷àëüíûéİêğàíToolStripMenuItem->Name = L"âûõîäÍàÍà÷àëüíûéİêğàíToolStripMenuItem";
			this->âûõîäÍàÍà÷àëüíûéİêğàíToolStripMenuItem->Size = System::Drawing::Size(336, 34);
			this->âûõîäÍàÍà÷àëüíûéİêğàíToolStripMenuItem->Text = L"Âûõîä íà íà÷àëüíûé ıêğàí";
			this->âûõîäÍàÍà÷àëüíûéİêğàíToolStripMenuItem->Click += gcnew System::EventHandler(this, &AutorizationForm::âûõîäÍàÍà÷àëüíûéİêğàíToolStripMenuItem_Click);
			// 
			// âûõîäÈçÏğîãğàììûToolStripMenuItem
			// 
			this->âûõîäÈçÏğîãğàììûToolStripMenuItem->Name = L"âûõîäÈçÏğîãğàììûToolStripMenuItem";
			this->âûõîäÈçÏğîãğàììûToolStripMenuItem->Size = System::Drawing::Size(336, 34);
			this->âûõîäÈçÏğîãğàììûToolStripMenuItem->Text = L"Âûõîä èç ïğîãğàììû";
			this->âûõîäÈçÏğîãğàììûToolStripMenuItem->Click += gcnew System::EventHandler(this, &AutorizationForm::âûõîäÈçÏğîãğàììûToolStripMenuItem_Click);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(7, 28);
			this->textBox1->Name = L"textBox1";
			this->textBox1->PasswordChar = '*';
			this->textBox1->Size = System::Drawing::Size(334, 28);
			this->textBox1->TabIndex = 1;
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->textBox1);
			this->groupBox1->Location = System::Drawing::Point(27, 57);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(354, 65);
			this->groupBox1->TabIndex = 2;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Ââåäèòå êîä äîñòóïà";
			// 
			// Autorization
			// 
			this->Autorization->Location = System::Drawing::Point(259, 129);
			this->Autorization->Name = L"Autorization";
			this->Autorization->Size = System::Drawing::Size(122, 43);
			this->Autorization->TabIndex = 3;
			this->Autorization->Text = L"Âîéòè";
			this->Autorization->UseVisualStyleBackColor = true;
			this->Autorization->Click += gcnew System::EventHandler(this, &AutorizationForm::Autorization_Click);
			// 
			// BackToStartMenu
			// 
			this->BackToStartMenu->Location = System::Drawing::Point(141, 129);
			this->BackToStartMenu->Name = L"BackToStartMenu";
			this->BackToStartMenu->Size = System::Drawing::Size(111, 43);
			this->BackToStartMenu->TabIndex = 4;
			this->BackToStartMenu->Text = L"Íàçàä";
			this->BackToStartMenu->UseVisualStyleBackColor = true;
			this->BackToStartMenu->Click += gcnew System::EventHandler(this, &AutorizationForm::BackToStartMenu_Click);
			// 
			// AutorizationForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(10, 22);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(383, 185);
			this->Controls->Add(this->BackToStartMenu);
			this->Controls->Add(this->Autorization);
			this->Controls->Add(this->menuStrip1);
			this->Controls->Add(this->groupBox1);
			this->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->MainMenuStrip = this->menuStrip1;
			this->MaximizeBox = false;
			this->MaximumSize = System::Drawing::Size(405, 241);
			this->MinimumSize = System::Drawing::Size(405, 241);
			this->Name = L"AutorizationForm";
			this->ShowIcon = false;
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Àâòîğèçàöèÿ";
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void âûõîäÍàÍà÷àëüíûéİêğàíToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void âûõîäÈçÏğîãğàììûToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);

private: System::Void BackToStartMenu_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void Autorization_Click(System::Object^ sender, System::EventArgs^ e);
};
}
