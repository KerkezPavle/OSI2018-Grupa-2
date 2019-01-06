#pragma once
#include <Windows.h>
#include "Username.h"
#include "XMLDataFile.h"
#include "EnterCodeForm.h"
#include "ShowStatistics.h"
#include "csvfile.h"
#include <string>


namespace GamePlay {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Windows::Forms;
	using namespace System::Runtime::InteropServices;


	/// <summary>
	/// Summary for HomeForm
	/// </summary>
	public ref class HomeForm : public System::Windows::Forms::Form
	{
	public:
		HomeForm(void)
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
		~HomeForm()
		{
			if (components)
			{
				delete components;
			}
		}

	protected:

	protected:
	private: System::Windows::Forms::Label^  label1;

	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Button^  btnStartGame1;
	private: System::Windows::Forms::Button^  btnUGame1;




	private: System::Windows::Forms::MenuStrip^  menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^  toolStripMenuItem1;
	private: System::Windows::Forms::ToolStripMenuItem^  exitToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  aboutToolStripMenuItem;
	private: System::Windows::Forms::Label^  lblKviz;
	private: System::Windows::Forms::Label^  lblbingo;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Button^  btnUGame2;

	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::Button^  btnUGame3;

	private: System::Windows::Forms::Button^  btnStartBingo;
	private: System::Windows::Forms::Button^  btnUGame4;


	private: System::Windows::Forms::Button^  button7;


	private: System::Windows::Forms::Label^  lblUsername;
	private: System::Windows::Forms::ToolStripMenuItem^  optionsToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  clearUsernameToolStripMenuItem;
	private: System::Windows::Forms::Button^  btnStats;
	private: System::Windows::Forms::ToolStripMenuItem^  saveStatisticsToCSVToolStripMenuItem;


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
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->btnStartGame1 = (gcnew System::Windows::Forms::Button());
			this->btnUGame1 = (gcnew System::Windows::Forms::Button());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->toolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->exitToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->optionsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->saveStatisticsToCSVToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->clearUsernameToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->aboutToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->lblKviz = (gcnew System::Windows::Forms::Label());
			this->lblbingo = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->btnUGame2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->btnUGame3 = (gcnew System::Windows::Forms::Button());
			this->btnStartBingo = (gcnew System::Windows::Forms::Button());
			this->btnUGame4 = (gcnew System::Windows::Forms::Button());
			this->button7 = (gcnew System::Windows::Forms::Button());
			this->lblUsername = (gcnew System::Windows::Forms::Label());
			this->btnStats = (gcnew System::Windows::Forms::Button());
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Cambria", 21.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(12, 38);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(148, 34);
			this->label1->TabIndex = 1;
			this->label1->Text = L"GamePlay";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Adobe Fan Heiti Std B", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(47, 125);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(118, 16);
			this->label2->TabIndex = 3;
			this->label2->Text = L"Guess the number";
			this->label2->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// btnStartGame1
			// 
			this->btnStartGame1->Location = System::Drawing::Point(50, 225);
			this->btnStartGame1->Name = L"btnStartGame1";
			this->btnStartGame1->Size = System::Drawing::Size(109, 38);
			this->btnStartGame1->TabIndex = 4;
			this->btnStartGame1->Text = L" START";
			this->btnStartGame1->UseVisualStyleBackColor = true;
			this->btnStartGame1->Click += gcnew System::EventHandler(this, &HomeForm::btnGame1_Click);
			// 
			// btnUGame1
			// 
			this->btnUGame1->Location = System::Drawing::Point(50, 172);
			this->btnUGame1->Name = L"btnUGame1";
			this->btnUGame1->Size = System::Drawing::Size(109, 37);
			this->btnUGame1->TabIndex = 6;
			this->btnUGame1->Text = L"Unlock the game";
			this->btnUGame1->UseVisualStyleBackColor = true;
			this->btnUGame1->Click += gcnew System::EventHandler(this, &HomeForm::button1_Click_1);
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->toolStripMenuItem1,
					this->optionsToolStripMenuItem, this->aboutToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(744, 24);
			this->menuStrip1->TabIndex = 7;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// toolStripMenuItem1
			// 
			this->toolStripMenuItem1->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->exitToolStripMenuItem });
			this->toolStripMenuItem1->Name = L"toolStripMenuItem1";
			this->toolStripMenuItem1->Size = System::Drawing::Size(37, 20);
			this->toolStripMenuItem1->Text = L"File";
			// 
			// exitToolStripMenuItem
			// 
			this->exitToolStripMenuItem->Name = L"exitToolStripMenuItem";
			this->exitToolStripMenuItem->Size = System::Drawing::Size(92, 22);
			this->exitToolStripMenuItem->Text = L"Exit";
			this->exitToolStripMenuItem->Click += gcnew System::EventHandler(this, &HomeForm::exitToolStripMenuItem_Click);
			// 
			// optionsToolStripMenuItem
			// 
			this->optionsToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->saveStatisticsToCSVToolStripMenuItem,
					this->clearUsernameToolStripMenuItem
			});
			this->optionsToolStripMenuItem->Name = L"optionsToolStripMenuItem";
			this->optionsToolStripMenuItem->Size = System::Drawing::Size(61, 20);
			this->optionsToolStripMenuItem->Text = L"Options";
			// 
			// saveStatisticsToCSVToolStripMenuItem
			// 
			this->saveStatisticsToCSVToolStripMenuItem->Name = L"saveStatisticsToCSVToolStripMenuItem";
			this->saveStatisticsToCSVToolStripMenuItem->Size = System::Drawing::Size(184, 22);
			this->saveStatisticsToCSVToolStripMenuItem->Text = L"Save statistics to CSV";
			this->saveStatisticsToCSVToolStripMenuItem->Click += gcnew System::EventHandler(this, &HomeForm::saveStatisticsToCSVToolStripMenuItem_Click);
			// 
			// clearUsernameToolStripMenuItem
			// 
			this->clearUsernameToolStripMenuItem->Name = L"clearUsernameToolStripMenuItem";
			this->clearUsernameToolStripMenuItem->Size = System::Drawing::Size(184, 22);
			this->clearUsernameToolStripMenuItem->Text = L"Clear Username";
			this->clearUsernameToolStripMenuItem->Click += gcnew System::EventHandler(this, &HomeForm::clearUsernameToolStripMenuItem_Click);
			// 
			// aboutToolStripMenuItem
			// 
			this->aboutToolStripMenuItem->Name = L"aboutToolStripMenuItem";
			this->aboutToolStripMenuItem->Size = System::Drawing::Size(52, 20);
			this->aboutToolStripMenuItem->Text = L"About";
			// 
			// lblKviz
			// 
			this->lblKviz->AutoSize = true;
			this->lblKviz->Font = (gcnew System::Drawing::Font(L"Adobe Fan Heiti Std B", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblKviz->Location = System::Drawing::Point(274, 125);
			this->lblKviz->Name = L"lblKviz";
			this->lblKviz->Size = System::Drawing::Size(34, 16);
			this->lblKviz->TabIndex = 8;
			this->lblKviz->Text = L"Quiz";
			// 
			// lblbingo
			// 
			this->lblbingo->AutoSize = true;
			this->lblbingo->Font = (gcnew System::Drawing::Font(L"Adobe Fan Heiti Std B", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblbingo->Location = System::Drawing::Point(443, 125);
			this->lblbingo->Name = L"lblbingo";
			this->lblbingo->Size = System::Drawing::Size(43, 16);
			this->lblbingo->TabIndex = 9;
			this->lblbingo->Text = L"Bingo";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Adobe Fan Heiti Std B", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label5->Location = System::Drawing::Point(598, 125);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(87, 16);
			this->label5->TabIndex = 10;
			this->label5->Text = L"Minesweeper";
			// 
			// btnUGame2
			// 
			this->btnUGame2->Location = System::Drawing::Point(234, 172);
			this->btnUGame2->Name = L"btnUGame2";
			this->btnUGame2->Size = System::Drawing::Size(109, 37);
			this->btnUGame2->TabIndex = 11;
			this->btnUGame2->Text = L"Unlock the game";
			this->btnUGame2->UseVisualStyleBackColor = true;
			this->btnUGame2->Click += gcnew System::EventHandler(this, &HomeForm::button2_Click);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(234, 225);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(109, 38);
			this->button3->TabIndex = 12;
			this->button3->Text = L"START";
			this->button3->UseVisualStyleBackColor = true;
			// 
			// btnUGame3
			// 
			this->btnUGame3->Location = System::Drawing::Point(411, 172);
			this->btnUGame3->Name = L"btnUGame3";
			this->btnUGame3->Size = System::Drawing::Size(109, 37);
			this->btnUGame3->TabIndex = 13;
			this->btnUGame3->Text = L"Unlock the game";
			this->btnUGame3->UseVisualStyleBackColor = true;
			this->btnUGame3->Click += gcnew System::EventHandler(this, &HomeForm::button4_Click);
			// 
			// btnStartBingo
			// 
			this->btnStartBingo->Location = System::Drawing::Point(411, 225);
			this->btnStartBingo->Name = L"btnStartBingo";
			this->btnStartBingo->Size = System::Drawing::Size(109, 38);
			this->btnStartBingo->TabIndex = 14;
			this->btnStartBingo->Text = L"START";
			this->btnStartBingo->UseVisualStyleBackColor = true;
			this->btnStartBingo->Click += gcnew System::EventHandler(this, &HomeForm::button5_Click);
			// 
			// btnUGame4
			// 
			this->btnUGame4->Location = System::Drawing::Point(592, 172);
			this->btnUGame4->Name = L"btnUGame4";
			this->btnUGame4->Size = System::Drawing::Size(96, 37);
			this->btnUGame4->TabIndex = 15;
			this->btnUGame4->Text = L"Unlock the game";
			this->btnUGame4->UseVisualStyleBackColor = true;
			this->btnUGame4->Click += gcnew System::EventHandler(this, &HomeForm::button6_Click);
			// 
			// button7
			// 
			this->button7->Location = System::Drawing::Point(592, 225);
			this->button7->Name = L"button7";
			this->button7->Size = System::Drawing::Size(96, 38);
			this->button7->TabIndex = 16;
			this->button7->Text = L"START";
			this->button7->UseVisualStyleBackColor = true;
			// 
			// lblUsername
			// 
			this->lblUsername->AutoSize = true;
			this->lblUsername->Font = (gcnew System::Drawing::Font(L"Cambria", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblUsername->Location = System::Drawing::Point(194, 48);
			this->lblUsername->Name = L"lblUsername";
			this->lblUsername->Size = System::Drawing::Size(60, 22);
			this->lblUsername->TabIndex = 19;
			this->lblUsername->Text = L"Hello, " + getUsername();
			// 
			// btnStats
			// 
			this->btnStats->Location = System::Drawing::Point(592, 334);
			this->btnStats->Name = L"btnStats";
			this->btnStats->Size = System::Drawing::Size(96, 38);
			this->btnStats->TabIndex = 20;
			this->btnStats->Text = L"Statistics";
			this->btnStats->UseVisualStyleBackColor = true;
			this->btnStats->Click += gcnew System::EventHandler(this, &HomeForm::btnStats_Click);
			// 
			// HomeForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoScroll = true;
			this->ClientSize = System::Drawing::Size(744, 399);
			this->Controls->Add(this->btnStats);
			this->Controls->Add(this->lblUsername);
			this->Controls->Add(this->button7);
			this->Controls->Add(this->btnUGame4);
			this->Controls->Add(this->btnStartBingo);
			this->Controls->Add(this->btnUGame3);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->btnUGame2);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->lblbingo);
			this->Controls->Add(this->lblKviz);
			this->Controls->Add(this->btnUGame1);
			this->Controls->Add(this->btnStartGame1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"HomeForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"GamePlay";
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
	
	}
	private: System::Void btnGame1_Click(System::Object^  sender, System::EventArgs^  e) {
		insertDataIntoStats(1, 10);
		insertDataIntoStats(1, 20);
		insertDataIntoStats(1, 30);
		insertDataIntoStats(1, 40);
		
	}
	private: System::Void btnSettings_Click(System::Object^  sender, System::EventArgs^  e) {

	}
	private: System::Void exitToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
		Application::Exit();
	}
	private: System::Void button9_Click(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void button8_Click(System::Object^  sender, System::EventArgs^  e) {

	}
	private: System::Void button5_Click(System::Object^  sender, System::EventArgs^  e) {
		testFun();
	}
private: System::Void clearUsernameToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	HomeForm::Hide();
	clearUsername();
	this->lblUsername->Text = "Hello, " + getUsername();
	HomeForm::Show();
}
private: System::Void button1_Click_1(System::Object^  sender, System::EventArgs^  e) {
	EnterCodeForm frm;
	frm.GameCode = "1";
	frm.ShowDialog();
}
private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
	EnterCodeForm frm;
	frm.GameCode = "2";
	frm.ShowDialog();
}
private: System::Void button4_Click(System::Object^  sender, System::EventArgs^  e) {
	EnterCodeForm frm;
	frm.GameCode = "3";
	frm.ShowDialog();
}
private: void SaveStatisticsCSV() {
	SaveFileDialog^ saveFileDialog1 = gcnew SaveFileDialog();
	saveFileDialog1->Filter = "File|*.csv";
	saveFileDialog1->Title = "Save Score To";
	System::String^ name = getUsername();
	saveFileDialog1->FileName = name;
	saveFileDialog1->AddExtension = ".csv";
	if (saveFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
		MakeCSV((char*)(void*)Marshal::StringToHGlobalAnsi(saveFileDialog1->FileName));
}
private: System::Void button6_Click(System::Object^  sender, System::EventArgs^  e) {
	EnterCodeForm frm;
	frm.GameCode = "4";
	frm.ShowDialog();
}
private: System::Void btnStats_Click(System::Object^  sender, System::EventArgs^  e) {
	ShowStatistics frm;
	frm.seedData();
	frm.ShowDialog();
}
private: System::Void saveStatisticsToCSVToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	SaveStatisticsCSV();
}
};
}


