#pragma once
#include "ChoiceOfMethodEditForm.h"
#include "LibrarySearchForm.h"
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

	protected:



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
			this->DataBaseSearch = (gcnew System::Windows::Forms::Button());
			this->AdminButt = (gcnew System::Windows::Forms::Button());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->Exit = (gcnew System::Windows::Forms::Button());
			this->groupBox1->SuspendLayout();
			this->groupBox2->SuspendLayout();
			this->SuspendLayout();
			// 
			// DataBaseSearch
			// 
			this->DataBaseSearch->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->DataBaseSearch->Location = System::Drawing::Point(21, 61);
			this->DataBaseSearch->Name = L"DataBaseSearch";
			this->DataBaseSearch->Size = System::Drawing::Size(266, 66);
			this->DataBaseSearch->TabIndex = 2;
			this->DataBaseSearch->Text = L"Начать поиск";
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
			this->AdminButt->Text = L"Редактирование базы данных";
			this->AdminButt->UseVisualStyleBackColor = true;
			this->AdminButt->Click += gcnew System::EventHandler(this, &StartMenuForm::AdminButt_Click);
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->DataBaseSearch);
			this->groupBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->groupBox1->Location = System::Drawing::Point(12, 38);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(301, 140);
			this->groupBox1->TabIndex = 4;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Поиск литературы в базе данных:";
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->AdminButt);
			this->groupBox2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->groupBox2->Location = System::Drawing::Point(12, 201);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(301, 144);
			this->groupBox2->TabIndex = 5;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Для сотрудников";
			// 
			// Exit
			// 
			this->Exit->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->Exit->Location = System::Drawing::Point(33, 363);
			this->Exit->Name = L"Exit";
			this->Exit->Size = System::Drawing::Size(266, 67);
			this->Exit->TabIndex = 6;
			this->Exit->Text = L"Выход";
			this->Exit->UseVisualStyleBackColor = true;
			this->Exit->Click += gcnew System::EventHandler(this, &StartMenuForm::Exit_Click);
			// 
			// StartMenuForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(328, 453);
			this->Controls->Add(this->Exit);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->groupBox2);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MaximizeBox = false;
			this->MaximumSize = System::Drawing::Size(350, 509);
			this->MinimumSize = System::Drawing::Size(350, 509);
			this->Name = L"StartMenuForm";
			this->ShowIcon = false;
			this->ShowInTaskbar = false;
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Меню";
			this->groupBox1->ResumeLayout(false);
			this->groupBox2->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion

private: System::Void Exit_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void AdminButt_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void DataBaseSearch_Click_1(System::Object^ sender, System::EventArgs^ e);
};
}
