#pragma once
#include "ChoiceOfMethodEditForm.h"
namespace DBLibClient {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for StartMenuForm
	/// </summary>
	public ref class StartMenuForm : public System::Windows::Forms::Form
	{
	public:
		StartMenuForm(void)
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
		~StartMenuForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	protected:
	private: System::Windows::Forms::ToolStripMenuItem^ ����ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ �����ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ ����������ToolStripMenuItem;
	private: System::Windows::Forms::Button^ DataBaseSearch;




	private: System::Windows::Forms::Button^ AdminButt;
	private: System::Windows::Forms::GroupBox^ groupBox1;
	private: System::Windows::Forms::GroupBox^ groupBox2;
	private: System::Windows::Forms::Button^ Exit;


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
			this->����ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->�����ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->����������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->DataBaseSearch = (gcnew System::Windows::Forms::Button());
			this->AdminButt = (gcnew System::Windows::Forms::Button());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->Exit = (gcnew System::Windows::Forms::Button());
			this->menuStrip1->SuspendLayout();
			this->groupBox1->SuspendLayout();
			this->groupBox2->SuspendLayout();
			this->SuspendLayout();
			// 
			// menuStrip1
			// 
			this->menuStrip1->GripMargin = System::Windows::Forms::Padding(2, 2, 0, 2);
			this->menuStrip1->ImageScalingSize = System::Drawing::Size(24, 24);
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->����ToolStripMenuItem,
					this->����������ToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(327, 33);
			this->menuStrip1->TabIndex = 0;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// ����ToolStripMenuItem
			// 
			this->����ToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->�����ToolStripMenuItem });
			this->����ToolStripMenuItem->Name = L"����ToolStripMenuItem";
			this->����ToolStripMenuItem->Size = System::Drawing::Size(69, 29);
			this->����ToolStripMenuItem->Text = L"����";
			// 
			// �����ToolStripMenuItem
			// 
			this->�����ToolStripMenuItem->Name = L"�����ToolStripMenuItem";
			this->�����ToolStripMenuItem->Size = System::Drawing::Size(166, 34);
			this->�����ToolStripMenuItem->Text = L"�����";
			this->�����ToolStripMenuItem->Click += gcnew System::EventHandler(this, &StartMenuForm::�����ToolStripMenuItem_Click);
			// 
			// ����������ToolStripMenuItem
			// 
			this->����������ToolStripMenuItem->Name = L"����������ToolStripMenuItem";
			this->����������ToolStripMenuItem->Size = System::Drawing::Size(141, 29);
			this->����������ToolStripMenuItem->Text = L"� ���������";
			this->����������ToolStripMenuItem->Click += gcnew System::EventHandler(this, &StartMenuForm::����������ToolStripMenuItem_Click);
			// 
			// DataBaseSearch
			// 
			this->DataBaseSearch->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->DataBaseSearch->Location = System::Drawing::Point(21, 61);
			this->DataBaseSearch->Name = L"DataBaseSearch";
			this->DataBaseSearch->Size = System::Drawing::Size(266, 66);
			this->DataBaseSearch->TabIndex = 2;
			this->DataBaseSearch->Text = L"������ �����";
			this->DataBaseSearch->UseVisualStyleBackColor = true;
			this->DataBaseSearch->Click += gcnew System::EventHandler(this, &StartMenuForm::DataBaseSearch_Click_1);
			// 
			// AdminButt
			// 
			this->AdminButt->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->AdminButt->Location = System::Drawing::Point(21, 41);
			this->AdminButt->Name = L"AdminButt";
			this->AdminButt->Size = System::Drawing::Size(266, 97);
			this->AdminButt->TabIndex = 3;
			this->AdminButt->Text = L"�������������� ���� ������";
			this->AdminButt->UseVisualStyleBackColor = true;
			this->AdminButt->Click += gcnew System::EventHandler(this, &StartMenuForm::AdminButt_Click);
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->DataBaseSearch);
			this->groupBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->groupBox1->Location = System::Drawing::Point(12, 45);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(301, 140);
			this->groupBox1->TabIndex = 4;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"����� ���������� � ���� ������:";
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->AdminButt);
			this->groupBox2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->groupBox2->Location = System::Drawing::Point(12, 208);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(301, 144);
			this->groupBox2->TabIndex = 5;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"��� �����������";
			// 
			// Exit
			// 
			this->Exit->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->Exit->Location = System::Drawing::Point(33, 370);
			this->Exit->Name = L"Exit";
			this->Exit->Size = System::Drawing::Size(266, 67);
			this->Exit->TabIndex = 6;
			this->Exit->Text = L"�����";
			this->Exit->UseVisualStyleBackColor = true;
			this->Exit->Click += gcnew System::EventHandler(this, &StartMenuForm::Exit_Click);
			// 
			// StartMenuForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(327, 456);
			this->Controls->Add(this->Exit);
			this->Controls->Add(this->menuStrip1);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->groupBox2);
			this->MainMenuStrip = this->menuStrip1;
			this->MaximizeBox = false;
			this->MaximumSize = System::Drawing::Size(349, 512);
			this->MinimumSize = System::Drawing::Size(349, 512);
			this->Name = L"StartMenuForm";
			this->ShowIcon = false;
			this->ShowInTaskbar = false;
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"����";
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->groupBox1->ResumeLayout(false);
			this->groupBox2->ResumeLayout(false);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: System::Void �����ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void ����������ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);

private: System::Void Exit_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void AdminButt_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void DataBaseSearch_Click_1(System::Object^ sender, System::EventArgs^ e);
};
}
