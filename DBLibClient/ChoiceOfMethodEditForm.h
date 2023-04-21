#pragma once
#include "StartMenuForm.h"
#include "FindForEditForm.h"
#include "AddElementsToDBForm.h"

namespace DBLibClient {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for ChoiceOfMethodEditForm
	/// </summary>
	public ref class ChoiceOfMethodEditForm : public System::Windows::Forms::Form
	{
	public:
		ChoiceOfMethodEditForm(void)
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
		~ChoiceOfMethodEditForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::GroupBox^ groupBox1;
	protected:
	private: System::Windows::Forms::Button^ EditElementsButton;
	private: System::Windows::Forms::Button^ AddElementsButton;
	private: System::Windows::Forms::Button^ toStart;
	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^ âûõîäToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ âûõîäÍàÍà÷àëüíûéİêğàíToolStripMenuItem;
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
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->EditElementsButton = (gcnew System::Windows::Forms::Button());
			this->AddElementsButton = (gcnew System::Windows::Forms::Button());
			this->toStart = (gcnew System::Windows::Forms::Button());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->âûõîäToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->âûõîäÍàÍà÷àëüíûéİêğàíToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->âûõîäÈçÏğîãğàììûToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->groupBox1->SuspendLayout();
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->EditElementsButton);
			this->groupBox1->Controls->Add(this->AddElementsButton);
			this->groupBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->groupBox1->Location = System::Drawing::Point(24, 36);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(390, 158);
			this->groupBox1->TabIndex = 0;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Âûáåğèòå ñïîñîá ğåäàêòèğîâàíèÿ";
			// 
			// EditElementsButton
			// 
			this->EditElementsButton->Location = System::Drawing::Point(6, 86);
			this->EditElementsButton->Name = L"EditElementsButton";
			this->EditElementsButton->Size = System::Drawing::Size(378, 58);
			this->EditElementsButton->TabIndex = 1;
			this->EditElementsButton->Text = L"Ğåäàêòèğîâàíèå ñóùåñòâóşùèõ";
			this->EditElementsButton->UseMnemonic = false;
			this->EditElementsButton->UseVisualStyleBackColor = true;
			this->EditElementsButton->Click += gcnew System::EventHandler(this, &ChoiceOfMethodEditForm::EditElementsButton_Click);
			// 
			// AddElementsButton
			// 
			this->AddElementsButton->Location = System::Drawing::Point(6, 25);
			this->AddElementsButton->Name = L"AddElementsButton";
			this->AddElementsButton->Size = System::Drawing::Size(378, 55);
			this->AddElementsButton->TabIndex = 0;
			this->AddElementsButton->Text = L"Äîáàâëåíèå ıëåìåíòîâ";
			this->AddElementsButton->UseVisualStyleBackColor = true;
			this->AddElementsButton->Click += gcnew System::EventHandler(this, &ChoiceOfMethodEditForm::AddElementsButton_Click);
			// 
			// toStart
			// 
			this->toStart->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->toStart->Location = System::Drawing::Point(277, 200);
			this->toStart->Name = L"toStart";
			this->toStart->Size = System::Drawing::Size(137, 43);
			this->toStart->TabIndex = 1;
			this->toStart->Text = L"Â íà÷àëî";
			this->toStart->UseVisualStyleBackColor = true;
			this->toStart->Click += gcnew System::EventHandler(this, &ChoiceOfMethodEditForm::toStart_Click);
			// 
			// menuStrip1
			// 
			this->menuStrip1->GripMargin = System::Windows::Forms::Padding(2, 2, 0, 2);
			this->menuStrip1->ImageScalingSize = System::Drawing::Size(24, 24);
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->âûõîäToolStripMenuItem });
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(426, 33);
			this->menuStrip1->TabIndex = 2;
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
			this->âûõîäÍàÍà÷àëüíûéİêğàíToolStripMenuItem->Click += gcnew System::EventHandler(this, &ChoiceOfMethodEditForm::âûõîäÍàÍà÷àëüíûéİêğàíToolStripMenuItem_Click);
			// 
			// âûõîäÈçÏğîãğàììûToolStripMenuItem
			// 
			this->âûõîäÈçÏğîãğàììûToolStripMenuItem->Name = L"âûõîäÈçÏğîãğàììûToolStripMenuItem";
			this->âûõîäÈçÏğîãğàììûToolStripMenuItem->Size = System::Drawing::Size(336, 34);
			this->âûõîäÈçÏğîãğàììûToolStripMenuItem->Text = L"Âûõîä èç ïğîãğàììû";
			this->âûõîäÈçÏğîãğàììûToolStripMenuItem->Click += gcnew System::EventHandler(this, &ChoiceOfMethodEditForm::âûõîäÈçÏğîãğàììûToolStripMenuItem_Click);
			// 
			// ChoiceOfMethodEditForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(426, 249);
			this->Controls->Add(this->toStart);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->MaximizeBox = false;
			this->MaximumSize = System::Drawing::Size(448, 305);
			this->MinimumSize = System::Drawing::Size(448, 305);
			this->Name = L"ChoiceOfMethodEditForm";
			this->ShowIcon = false;
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Ğåäàêòèğîâàíèÿ ÁÄ";
			this->groupBox1->ResumeLayout(false);
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void toStart_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void âûõîäÍàÍà÷àëüíûéİêğàíToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void âûõîäÈçÏğîãğàììûToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void EditElementsButton_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void AddElementsButton_Click(System::Object^ sender, System::EventArgs^ e);
};
}
