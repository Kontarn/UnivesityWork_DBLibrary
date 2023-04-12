#pragma once
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
	/// Summary for EditDBForm
	/// </summary>
	public ref class EditDBForm : public System::Windows::Forms::Form
	{
	public:
		EditDBForm(void)
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
		~EditDBForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	protected:
	private: System::Windows::Forms::ToolStripMenuItem^ âûõîäToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ âûõîäÈçÏğîãğàììûToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ âûõîäÍàÍà÷àëüíûéİêğàíToolStripMenuItem;
	private: System::Windows::Forms::Button^ BackToFindButton;

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
			this->âûõîäÈçÏğîãğàììûToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->âûõîäÍàÍà÷àëüíûéİêğàíToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->BackToFindButton = (gcnew System::Windows::Forms::Button());
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
			this->menuStrip1->Size = System::Drawing::Size(513, 33);
			this->menuStrip1->TabIndex = 0;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// âûõîäToolStripMenuItem
			// 
			this->âûõîäToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->âûõîäÈçÏğîãğàììûToolStripMenuItem,
					this->âûõîäÍàÍà÷àëüíûéİêğàíToolStripMenuItem
			});
			this->âûõîäToolStripMenuItem->Name = L"âûõîäToolStripMenuItem";
			this->âûõîäToolStripMenuItem->Size = System::Drawing::Size(80, 29);
			this->âûõîäToolStripMenuItem->Text = L"Âûõîä";
			// 
			// âûõîäÈçÏğîãğàììûToolStripMenuItem
			// 
			this->âûõîäÈçÏğîãğàììûToolStripMenuItem->Name = L"âûõîäÈçÏğîãğàììûToolStripMenuItem";
			this->âûõîäÈçÏğîãğàììûToolStripMenuItem->Size = System::Drawing::Size(336, 34);
			this->âûõîäÈçÏğîãğàììûToolStripMenuItem->Text = L"Âûõîä èç ïğîãğàììû";
			this->âûõîäÈçÏğîãğàììûToolStripMenuItem->Click += gcnew System::EventHandler(this, &EditDBForm::âûõîäÈçÏğîãğàììûToolStripMenuItem_Click);
			// 
			// âûõîäÍàÍà÷àëüíûéİêğàíToolStripMenuItem
			// 
			this->âûõîäÍàÍà÷àëüíûéİêğàíToolStripMenuItem->Name = L"âûõîäÍàÍà÷àëüíûéİêğàíToolStripMenuItem";
			this->âûõîäÍàÍà÷àëüíûéİêğàíToolStripMenuItem->Size = System::Drawing::Size(336, 34);
			this->âûõîäÍàÍà÷àëüíûéİêğàíToolStripMenuItem->Text = L"Âûõîä íà íà÷àëüíûé ıêğàí";
			this->âûõîäÍàÍà÷àëüíûéİêğàíToolStripMenuItem->Click += gcnew System::EventHandler(this, &EditDBForm::âûõîäÍàÍà÷àëüíûéİêğàíToolStripMenuItem_Click);
			// 
			// BackToFindButton
			// 
			this->BackToFindButton->Location = System::Drawing::Point(356, 198);
			this->BackToFindButton->Name = L"BackToFindButton";
			this->BackToFindButton->Size = System::Drawing::Size(130, 59);
			this->BackToFindButton->TabIndex = 1;
			this->BackToFindButton->Text = L"Íàçàä";
			this->BackToFindButton->UseVisualStyleBackColor = true;
			this->BackToFindButton->Click += gcnew System::EventHandler(this, &EditDBForm::BackToFindButton_Click);
			// 
			// EditDBForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(513, 278);
			this->Controls->Add(this->BackToFindButton);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"EditDBForm";
			this->ShowIcon = false;
			this->Text = L"Ğåäàêòèğîâàíèå çàïèñåé";
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void âûõîäÈçÏğîãğàììûToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void âûõîäÍàÍà÷àëüíûéİêğàíToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void BackToFindButton_Click(System::Object^ sender, System::EventArgs^ e);
};
}
