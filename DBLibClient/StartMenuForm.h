#pragma once
#include "FindTechBookForm.h"
#include "FindArtBookForm.h"
#include "AutorizationForm.h"
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
	private: System::Windows::Forms::ToolStripMenuItem^ Ù‡ÈÎToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ ‚˚ıÓ‰ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ ÓœÓ„‡ÏÏÂToolStripMenuItem;
	private: System::Windows::Forms::Button^ TechBookButt;

	private: System::Windows::Forms::Button^ ArtBookButt;
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
			this->Ù‡ÈÎToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->‚˚ıÓ‰ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->ÓœÓ„‡ÏÏÂToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->TechBookButt = (gcnew System::Windows::Forms::Button());
			this->ArtBookButt = (gcnew System::Windows::Forms::Button());
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
				this->Ù‡ÈÎToolStripMenuItem,
					this->ÓœÓ„‡ÏÏÂToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(325, 33);
			this->menuStrip1->TabIndex = 0;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// Ù‡ÈÎToolStripMenuItem
			// 
			this->Ù‡ÈÎToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->‚˚ıÓ‰ToolStripMenuItem });
			this->Ù‡ÈÎToolStripMenuItem->Name = L"Ù‡ÈÎToolStripMenuItem";
			this->Ù‡ÈÎToolStripMenuItem->Size = System::Drawing::Size(69, 29);
			this->Ù‡ÈÎToolStripMenuItem->Text = L"‘‡ÈÎ";
			// 
			// ‚˚ıÓ‰ToolStripMenuItem
			// 
			this->‚˚ıÓ‰ToolStripMenuItem->Name = L"‚˚ıÓ‰ToolStripMenuItem";
			this->‚˚ıÓ‰ToolStripMenuItem->Size = System::Drawing::Size(166, 34);
			this->‚˚ıÓ‰ToolStripMenuItem->Text = L"¬˚ıÓ‰";
			this->‚˚ıÓ‰ToolStripMenuItem->Click += gcnew System::EventHandler(this, &StartMenuForm::‚˚ıÓ‰ToolStripMenuItem_Click);
			// 
			// ÓœÓ„‡ÏÏÂToolStripMenuItem
			// 
			this->ÓœÓ„‡ÏÏÂToolStripMenuItem->Name = L"ÓœÓ„‡ÏÏÂToolStripMenuItem";
			this->ÓœÓ„‡ÏÏÂToolStripMenuItem->Size = System::Drawing::Size(141, 29);
			this->ÓœÓ„‡ÏÏÂToolStripMenuItem->Text = L"Œ ÔÓ„‡ÏÏÂ";
			this->ÓœÓ„‡ÏÏÂToolStripMenuItem->Click += gcnew System::EventHandler(this, &StartMenuForm::ÓœÓ„‡ÏÏÂToolStripMenuItem_Click);
			// 
			// TechBookButt
			// 
			this->TechBookButt->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->TechBookButt->Location = System::Drawing::Point(21, 64);
			this->TechBookButt->Name = L"TechBookButt";
			this->TechBookButt->Size = System::Drawing::Size(266, 46);
			this->TechBookButt->TabIndex = 1;
			this->TechBookButt->Text = L"“ÂıÌË˜ÂÒÍ‡ˇ";
			this->TechBookButt->UseVisualStyleBackColor = true;
			this->TechBookButt->Click += gcnew System::EventHandler(this, &StartMenuForm::TechBookButt_Click);
			// 
			// ArtBookButt
			// 
			this->ArtBookButt->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->ArtBookButt->Location = System::Drawing::Point(21, 128);
			this->ArtBookButt->Name = L"ArtBookButt";
			this->ArtBookButt->Size = System::Drawing::Size(266, 45);
			this->ArtBookButt->TabIndex = 2;
			this->ArtBookButt->Text = L"’Û‰ÓÊÂÒÚ‚ÂÌÌ‡ˇ";
			this->ArtBookButt->UseVisualStyleBackColor = true;
			this->ArtBookButt->Click += gcnew System::EventHandler(this, &StartMenuForm::ArtBookButt_Click);
			// 
			// AdminButt
			// 
			this->AdminButt->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->AdminButt->Location = System::Drawing::Point(21, 41);
			this->AdminButt->Name = L"AdminButt";
			this->AdminButt->Size = System::Drawing::Size(266, 97);
			this->AdminButt->TabIndex = 3;
			this->AdminButt->Text = L"–Â‰‡ÍÚËÓ‚‡ÌËÂ ·‡Á˚ ‰‡ÌÌ˚ı";
			this->AdminButt->UseVisualStyleBackColor = true;
			this->AdminButt->Click += gcnew System::EventHandler(this, &StartMenuForm::AdminButt_Click);
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->ArtBookButt);
			this->groupBox1->Controls->Add(this->TechBookButt);
			this->groupBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->groupBox1->Location = System::Drawing::Point(12, 51);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(301, 200);
			this->groupBox1->TabIndex = 4;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"œÓËÒÍ ÎËÚÂ‡ÚÛ˚ ÔÓ Ì‡Ô‡‚ÎÂÌËˇÏ:";
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->AdminButt);
			this->groupBox2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->groupBox2->Location = System::Drawing::Point(12, 257);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(301, 144);
			this->groupBox2->TabIndex = 5;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"ƒÎˇ ÒÓÚÛ‰ÌËÍÓ‚";
			// 
			// Exit
			// 
			this->Exit->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->Exit->Location = System::Drawing::Point(33, 419);
			this->Exit->Name = L"Exit";
			this->Exit->Size = System::Drawing::Size(266, 67);
			this->Exit->TabIndex = 6;
			this->Exit->Text = L"¬˚ıÓ‰";
			this->Exit->UseVisualStyleBackColor = true;
			this->Exit->Click += gcnew System::EventHandler(this, &StartMenuForm::Exit_Click);
			// 
			// StartMenuForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(325, 498);
			this->Controls->Add(this->Exit);
			this->Controls->Add(this->menuStrip1);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->groupBox2);
			this->MainMenuStrip = this->menuStrip1;
			this->MaximizeBox = false;
			this->MaximumSize = System::Drawing::Size(347, 554);
			this->MinimumSize = System::Drawing::Size(347, 554);
			this->Name = L"StartMenuForm";
			this->ShowIcon = false;
			this->ShowInTaskbar = false;
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"ÃÂÌ˛";
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->groupBox1->ResumeLayout(false);
			this->groupBox2->ResumeLayout(false);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: System::Void ‚˚ıÓ‰ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void ÓœÓ„‡ÏÏÂToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);

private: System::Void Exit_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void TechBookButt_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void ArtBookButt_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void AdminButt_Click(System::Object^ sender, System::EventArgs^ e);
};
}
