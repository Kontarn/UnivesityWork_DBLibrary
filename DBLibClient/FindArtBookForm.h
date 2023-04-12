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
	/// Summary for FindArtBookForm
	/// </summary>
	public ref class FindArtBookForm : public System::Windows::Forms::Form
	{
	public:
		FindArtBookForm(void)
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
		~FindArtBookForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	protected:
	private: System::Windows::Forms::ToolStripMenuItem^ âûõîäToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ âûõîäÂÍà÷àëüíîåÎêíîToolStripMenuItem;
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
			this->âûõîäToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->âûõîäÂÍà÷àëüíîåÎêíîToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->âûõîäÈçÏğîãğàììûToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
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
			this->menuStrip1->Size = System::Drawing::Size(502, 33);
			this->menuStrip1->TabIndex = 0;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// âûõîäToolStripMenuItem
			// 
			this->âûõîäToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->âûõîäÂÍà÷àëüíîåÎêíîToolStripMenuItem,
					this->âûõîäÈçÏğîãğàììûToolStripMenuItem
			});
			this->âûõîäToolStripMenuItem->Name = L"âûõîäToolStripMenuItem";
			this->âûõîäToolStripMenuItem->Size = System::Drawing::Size(80, 29);
			this->âûõîäToolStripMenuItem->Text = L"Âûõîä";
			// 
			// âûõîäÂÍà÷àëüíîåÎêíîToolStripMenuItem
			// 
			this->âûõîäÂÍà÷àëüíîåÎêíîToolStripMenuItem->Name = L"âûõîäÂÍà÷àëüíîåÎêíîToolStripMenuItem";
			this->âûõîäÂÍà÷àëüíîåÎêíîToolStripMenuItem->Size = System::Drawing::Size(327, 34);
			this->âûõîäÂÍà÷àëüíîåÎêíîToolStripMenuItem->Text = L"Âûõîä íà íà÷àëüíîå îêíî";
			this->âûõîäÂÍà÷àëüíîåÎêíîToolStripMenuItem->Click += gcnew System::EventHandler(this, &FindArtBookForm::âûõîäÂÍà÷àëüíîåÎêíîToolStripMenuItem_Click);
			// 
			// âûõîäÈçÏğîãğàììûToolStripMenuItem
			// 
			this->âûõîäÈçÏğîãğàììûToolStripMenuItem->Name = L"âûõîäÈçÏğîãğàììûToolStripMenuItem";
			this->âûõîäÈçÏğîãğàììûToolStripMenuItem->Size = System::Drawing::Size(327, 34);
			this->âûõîäÈçÏğîãğàììûToolStripMenuItem->Text = L"Âûõîä èç ïğîãğàììû";
			this->âûõîäÈçÏğîãğàììûToolStripMenuItem->Click += gcnew System::EventHandler(this, &FindArtBookForm::âûõîäÈçÏğîãğàììûToolStripMenuItem_Click);
			// 
			// FindArtBookForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(502, 397);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"FindArtBookForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Ïîèñê õóäîæåñòâåííîé ëèòåğàòóğû";
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void âûõîäÈçÏğîãğàììûToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void âûõîäÂÍà÷àëüíîåÎêíîToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
	};
}
