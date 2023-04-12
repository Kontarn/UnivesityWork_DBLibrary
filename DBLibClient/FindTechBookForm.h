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
	/// Summary for FindTechBookForm
	/// </summary>
	public ref class FindTechBookForm : public System::Windows::Forms::Form
	{
	public:
		FindTechBookForm(void)
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
		~FindTechBookForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	protected:
	private: System::Windows::Forms::MenuStrip^ menuStrip2;
	private: System::Windows::Forms::ToolStripMenuItem^ âûõîäToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ âûõîäÂÍà÷àëüíîåÌåíşToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ âûõîäÈçÏğîãğàììûToolStripMenuItem;

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
			this->menuStrip2 = (gcnew System::Windows::Forms::MenuStrip());
			this->âûõîäToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->âûõîäÂÍà÷àëüíîåÌåíşToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->âûõîäÈçÏğîãğàììûToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->menuStrip2->SuspendLayout();
			this->SuspendLayout();
			// 
			// menuStrip1
			// 
			this->menuStrip1->GripMargin = System::Windows::Forms::Padding(2, 2, 0, 2);
			this->menuStrip1->ImageScalingSize = System::Drawing::Size(24, 24);
			this->menuStrip1->Location = System::Drawing::Point(0, 33);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(460, 24);
			this->menuStrip1->TabIndex = 0;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// menuStrip2
			// 
			this->menuStrip2->GripMargin = System::Windows::Forms::Padding(2, 2, 0, 2);
			this->menuStrip2->ImageScalingSize = System::Drawing::Size(24, 24);
			this->menuStrip2->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->âûõîäToolStripMenuItem });
			this->menuStrip2->Location = System::Drawing::Point(0, 0);
			this->menuStrip2->Name = L"menuStrip2";
			this->menuStrip2->Size = System::Drawing::Size(460, 33);
			this->menuStrip2->TabIndex = 1;
			this->menuStrip2->Text = L"menuStrip2";
			// 
			// âûõîäToolStripMenuItem
			// 
			this->âûõîäToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->âûõîäÂÍà÷àëüíîåÌåíşToolStripMenuItem,
					this->âûõîäÈçÏğîãğàììûToolStripMenuItem
			});
			this->âûõîäToolStripMenuItem->Name = L"âûõîäToolStripMenuItem";
			this->âûõîäToolStripMenuItem->Size = System::Drawing::Size(80, 29);
			this->âûõîäToolStripMenuItem->Text = L"Âûõîä";
			// 
			// âûõîäÂÍà÷àëüíîåÌåíşToolStripMenuItem
			// 
			this->âûõîäÂÍà÷àëüíîåÌåíşToolStripMenuItem->Name = L"âûõîäÂÍà÷àëüíîåÌåíşToolStripMenuItem";
			this->âûõîäÂÍà÷àëüíîåÌåíşToolStripMenuItem->Size = System::Drawing::Size(324, 34);
			this->âûõîäÂÍà÷àëüíîåÌåíşToolStripMenuItem->Text = L"Âûõîä â íà÷àëüíîå ìåíş";
			this->âûõîäÂÍà÷àëüíîåÌåíşToolStripMenuItem->Click += gcnew System::EventHandler(this, &FindTechBookForm::âûõîäÂÍà÷àëüíîåÌåíşToolStripMenuItem_Click);
			// 
			// âûõîäÈçÏğîãğàììûToolStripMenuItem
			// 
			this->âûõîäÈçÏğîãğàììûToolStripMenuItem->Name = L"âûõîäÈçÏğîãğàììûToolStripMenuItem";
			this->âûõîäÈçÏğîãğàììûToolStripMenuItem->Size = System::Drawing::Size(324, 34);
			this->âûõîäÈçÏğîãğàììûToolStripMenuItem->Text = L"Âûõîä èç ïğîãğàììû";
			this->âûõîäÈçÏğîãğàììûToolStripMenuItem->Click += gcnew System::EventHandler(this, &FindTechBookForm::âûõîäÈçÏğîãğàììûToolStripMenuItem_Click);
			// 
			// FindTechBookForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(460, 363);
			this->Controls->Add(this->menuStrip1);
			this->Controls->Add(this->menuStrip2);
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"FindTechBookForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Ïîèñê òåõíè÷åñêîé ëèòåğàòóğû";
			this->menuStrip2->ResumeLayout(false);
			this->menuStrip2->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void âûõîäÈçÏğîãğàììûToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void âûõîäÂÍà÷àëüíîåÌåíşToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
};
}
