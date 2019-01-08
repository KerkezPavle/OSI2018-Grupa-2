#pragma once
#include <Windows.h>
#include "Username.h"
#include "XMLDataFile.h"
#include "EnterCodeForm.h"
#include "ShowStatistics.h"
#include "csvfile.h"
#include <string>
#include <cstdlib>
#include "InfoAboutUs.h"
#include "KeysValidation.h"


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


	private: System::Windows::Forms::ToolStripMenuItem^  aboutToolStripMenuItem;
	private: System::Windows::Forms::Label^  lblKviz;
	private: System::Windows::Forms::Label^  lblbingo;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Button^  btnUGame2;
	private: System::Windows::Forms::Button^  btnStartGame2;


	private: System::Windows::Forms::Button^  btnUGame3;
	private: System::Windows::Forms::Button^  btnStartGame3;


	private: System::Windows::Forms::Button^  btnUGame4;
	private: System::Windows::Forms::Button^  btnStartGame4;





	private: System::Windows::Forms::Label^  lblUsername;
	private: System::Windows::Forms::ToolStripMenuItem^  optionsToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  clearUsernameToolStripMenuItem;
	private: System::Windows::Forms::Button^  btnStats;
	private: System::Windows::Forms::ToolStripMenuItem^  saveStatisticsToCSVToolStripMenuItem;
	private: System::Windows::Forms::Button^  btnCancelGame1;
	private: System::Windows::Forms::Button^  btnCancelGame2;
	private: System::Windows::Forms::Button^  btnCancelGame3;
	private: System::Windows::Forms::Button^  btnCancelGame4;
	private: System::Windows::Forms::ToolStripMenuItem^  izlazToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  oAplikacijiToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  oAutorimaToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  pomocToolStripMenuItem;






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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(HomeForm::typeid));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->btnStartGame1 = (gcnew System::Windows::Forms::Button());
			this->btnUGame1 = (gcnew System::Windows::Forms::Button());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->optionsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->saveStatisticsToCSVToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->clearUsernameToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->izlazToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->aboutToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->oAplikacijiToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->oAutorimaToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->lblKviz = (gcnew System::Windows::Forms::Label());
			this->lblbingo = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->btnUGame2 = (gcnew System::Windows::Forms::Button());
			this->btnStartGame2 = (gcnew System::Windows::Forms::Button());
			this->btnUGame3 = (gcnew System::Windows::Forms::Button());
			this->btnStartGame3 = (gcnew System::Windows::Forms::Button());
			this->btnUGame4 = (gcnew System::Windows::Forms::Button());
			this->btnStartGame4 = (gcnew System::Windows::Forms::Button());
			this->lblUsername = (gcnew System::Windows::Forms::Label());
			this->btnStats = (gcnew System::Windows::Forms::Button());
			this->btnCancelGame1 = (gcnew System::Windows::Forms::Button());
			this->btnCancelGame2 = (gcnew System::Windows::Forms::Button());
			this->btnCancelGame3 = (gcnew System::Windows::Forms::Button());
			this->btnCancelGame4 = (gcnew System::Windows::Forms::Button());
			this->pomocToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
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
			this->label2->Location = System::Drawing::Point(69, 129);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(91, 16);
			this->label2->TabIndex = 3;
			this->label2->Text = L"Pogodite broj";
			this->label2->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// btnStartGame1
			// 
			this->btnStartGame1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnStartGame1.Image")));
			this->btnStartGame1->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->btnStartGame1->Location = System::Drawing::Point(20, 176);
			this->btnStartGame1->Name = L"btnStartGame1";
			this->btnStartGame1->Padding = System::Windows::Forms::Padding(10, 0, 0, 0);
			this->btnStartGame1->Size = System::Drawing::Size(181, 46);
			this->btnStartGame1->TabIndex = 4;
			this->btnStartGame1->Text = L" START";
			this->btnStartGame1->UseVisualStyleBackColor = true;
			this->btnStartGame1->Click += gcnew System::EventHandler(this, &HomeForm::btnGame1_Click);
			// 
			// btnUGame1
			// 
			this->btnUGame1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnUGame1.Image")));
			this->btnUGame1->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->btnUGame1->Location = System::Drawing::Point(20, 234);
			this->btnUGame1->Name = L"btnUGame1";
			this->btnUGame1->Padding = System::Windows::Forms::Padding(2, 0, 0, 0);
			this->btnUGame1->Size = System::Drawing::Size(86, 37);
			this->btnUGame1->TabIndex = 6;
			this->btnUGame1->Text = L"      Otkljucajte";
			this->btnUGame1->UseVisualStyleBackColor = true;
			this->btnUGame1->Click += gcnew System::EventHandler(this, &HomeForm::button1_Click_1);
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->optionsToolStripMenuItem,
					this->aboutToolStripMenuItem, this->pomocToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(838, 24);
			this->menuStrip1->TabIndex = 7;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// optionsToolStripMenuItem
			// 
			this->optionsToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->saveStatisticsToCSVToolStripMenuItem,
					this->clearUsernameToolStripMenuItem, this->izlazToolStripMenuItem
			});
			this->optionsToolStripMenuItem->Name = L"optionsToolStripMenuItem";
			this->optionsToolStripMenuItem->Size = System::Drawing::Size(53, 20);
			this->optionsToolStripMenuItem->Text = L"Opcije";
			// 
			// saveStatisticsToCSVToolStripMenuItem
			// 
			this->saveStatisticsToCSVToolStripMenuItem->Name = L"saveStatisticsToCSVToolStripMenuItem";
			this->saveStatisticsToCSVToolStripMenuItem->Size = System::Drawing::Size(210, 22);
			this->saveStatisticsToCSVToolStripMenuItem->Text = L"Sacuvajte statistiku u CSV";
			this->saveStatisticsToCSVToolStripMenuItem->Click += gcnew System::EventHandler(this, &HomeForm::saveStatisticsToCSVToolStripMenuItem_Click);
			// 
			// clearUsernameToolStripMenuItem
			// 
			this->clearUsernameToolStripMenuItem->Name = L"clearUsernameToolStripMenuItem";
			this->clearUsernameToolStripMenuItem->Size = System::Drawing::Size(210, 22);
			this->clearUsernameToolStripMenuItem->Text = L"Restartujte korisnicko ime";
			this->clearUsernameToolStripMenuItem->Click += gcnew System::EventHandler(this, &HomeForm::clearUsernameToolStripMenuItem_Click);
			// 
			// izlazToolStripMenuItem
			// 
			this->izlazToolStripMenuItem->Name = L"izlazToolStripMenuItem";
			this->izlazToolStripMenuItem->Size = System::Drawing::Size(210, 22);
			this->izlazToolStripMenuItem->Text = L"Izlaz";
			this->izlazToolStripMenuItem->Click += gcnew System::EventHandler(this, &HomeForm::izlazToolStripMenuItem_Click);
			// 
			// aboutToolStripMenuItem
			// 
			this->aboutToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->oAplikacijiToolStripMenuItem,
					this->oAutorimaToolStripMenuItem
			});
			this->aboutToolStripMenuItem->Name = L"aboutToolStripMenuItem";
			this->aboutToolStripMenuItem->Size = System::Drawing::Size(79, 20);
			this->aboutToolStripMenuItem->Text = L"Informacije";
			// 
			// oAplikacijiToolStripMenuItem
			// 
			this->oAplikacijiToolStripMenuItem->Name = L"oAplikacijiToolStripMenuItem";
			this->oAplikacijiToolStripMenuItem->Size = System::Drawing::Size(134, 22);
			this->oAplikacijiToolStripMenuItem->Text = L"O aplikaciji";
			// 
			// oAutorimaToolStripMenuItem
			// 
			this->oAutorimaToolStripMenuItem->Name = L"oAutorimaToolStripMenuItem";
			this->oAutorimaToolStripMenuItem->Size = System::Drawing::Size(134, 22);
			this->oAutorimaToolStripMenuItem->Text = L"O autorima";
			this->oAutorimaToolStripMenuItem->Click += gcnew System::EventHandler(this, &HomeForm::oAutorimaToolStripMenuItem_Click);
			// 
			// lblKviz
			// 
			this->lblKviz->AutoSize = true;
			this->lblKviz->Font = (gcnew System::Drawing::Font(L"Adobe Fan Heiti Std B", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblKviz->Location = System::Drawing::Point(301, 129);
			this->lblKviz->Name = L"lblKviz";
			this->lblKviz->Size = System::Drawing::Size(32, 16);
			this->lblKviz->TabIndex = 8;
			this->lblKviz->Text = L"Kviz";
			// 
			// lblbingo
			// 
			this->lblbingo->AutoSize = true;
			this->lblbingo->Font = (gcnew System::Drawing::Font(L"Adobe Fan Heiti Std B", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblbingo->Location = System::Drawing::Point(496, 129);
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
			this->label5->Location = System::Drawing::Point(687, 129);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(69, 16);
			this->label5->TabIndex = 10;
			this->label5->Text = L"Minolovac";
			// 
			// btnUGame2
			// 
			this->btnUGame2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnUGame2.Image")));
			this->btnUGame2->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->btnUGame2->Location = System::Drawing::Point(224, 234);
			this->btnUGame2->Name = L"btnUGame2";
			this->btnUGame2->Padding = System::Windows::Forms::Padding(2, 0, 0, 0);
			this->btnUGame2->Size = System::Drawing::Size(88, 37);
			this->btnUGame2->TabIndex = 11;
			this->btnUGame2->Text = L"      Otkljucajte";
			this->btnUGame2->UseVisualStyleBackColor = true;
			this->btnUGame2->Click += gcnew System::EventHandler(this, &HomeForm::button2_Click);
			// 
			// btnStartGame2
			// 
			this->btnStartGame2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnStartGame2.Image")));
			this->btnStartGame2->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->btnStartGame2->Location = System::Drawing::Point(224, 176);
			this->btnStartGame2->Name = L"btnStartGame2";
			this->btnStartGame2->Padding = System::Windows::Forms::Padding(10, 0, 0, 0);
			this->btnStartGame2->Size = System::Drawing::Size(181, 46);
			this->btnStartGame2->TabIndex = 12;
			this->btnStartGame2->Text = L"START";
			this->btnStartGame2->UseVisualStyleBackColor = true;
			this->btnStartGame2->Click += gcnew System::EventHandler(this, &HomeForm::btnStartGame2_Click);
			// 
			// btnUGame3
			// 
			this->btnUGame3->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnUGame3.Image")));
			this->btnUGame3->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->btnUGame3->Location = System::Drawing::Point(428, 234);
			this->btnUGame3->Name = L"btnUGame3";
			this->btnUGame3->Padding = System::Windows::Forms::Padding(2, 0, 0, 0);
			this->btnUGame3->Size = System::Drawing::Size(88, 37);
			this->btnUGame3->TabIndex = 13;
			this->btnUGame3->Text = L"      Otkljucajte";
			this->btnUGame3->UseVisualStyleBackColor = true;
			this->btnUGame3->Click += gcnew System::EventHandler(this, &HomeForm::button4_Click);
			// 
			// btnStartGame3
			// 
			this->btnStartGame3->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnStartGame3.Image")));
			this->btnStartGame3->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->btnStartGame3->Location = System::Drawing::Point(428, 176);
			this->btnStartGame3->Name = L"btnStartGame3";
			this->btnStartGame3->Padding = System::Windows::Forms::Padding(10, 0, 0, 0);
			this->btnStartGame3->Size = System::Drawing::Size(181, 46);
			this->btnStartGame3->TabIndex = 14;
			this->btnStartGame3->Text = L"START";
			this->btnStartGame3->UseVisualStyleBackColor = true;
			this->btnStartGame3->Click += gcnew System::EventHandler(this, &HomeForm::button5_Click);
			// 
			// btnUGame4
			// 
			this->btnUGame4->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnUGame4.Image")));
			this->btnUGame4->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->btnUGame4->Location = System::Drawing::Point(632, 234);
			this->btnUGame4->Name = L"btnUGame4";
			this->btnUGame4->Padding = System::Windows::Forms::Padding(2, 0, 0, 0);
			this->btnUGame4->Size = System::Drawing::Size(88, 37);
			this->btnUGame4->TabIndex = 15;
			this->btnUGame4->Text = L"      Otkljucajte";
			this->btnUGame4->UseVisualStyleBackColor = true;
			this->btnUGame4->Click += gcnew System::EventHandler(this, &HomeForm::button6_Click);
			// 
			// btnStartGame4
			// 
			this->btnStartGame4->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnStartGame4.Image")));
			this->btnStartGame4->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->btnStartGame4->Location = System::Drawing::Point(632, 176);
			this->btnStartGame4->Name = L"btnStartGame4";
			this->btnStartGame4->Padding = System::Windows::Forms::Padding(10, 0, 0, 0);
			this->btnStartGame4->Size = System::Drawing::Size(181, 46);
			this->btnStartGame4->TabIndex = 16;
			this->btnStartGame4->Text = L"START";
			this->btnStartGame4->UseVisualStyleBackColor = true;
			this->btnStartGame4->Click += gcnew System::EventHandler(this, &HomeForm::btnStartGame4_Click);
			// 
			// lblUsername
			// 
			this->lblUsername->AutoSize = true;
			this->lblUsername->Font = (gcnew System::Drawing::Font(L"Cambria", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblUsername->Location = System::Drawing::Point(194, 48);
			this->lblUsername->Name = L"lblUsername";
			this->lblUsername->Size = System::Drawing::Size(76, 22);
			this->lblUsername->TabIndex = 19;
			this->lblUsername->Text = L"Zdravo, ";
			// 
			// btnStats
			// 
			this->btnStats->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnStats.Image")));
			this->btnStats->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->btnStats->Location = System::Drawing::Point(632, 330);
			this->btnStats->Name = L"btnStats";
			this->btnStats->Padding = System::Windows::Forms::Padding(5, 0, 0, 0);
			this->btnStats->Size = System::Drawing::Size(181, 46);
			this->btnStats->TabIndex = 20;
			this->btnStats->Text = L"Statistika";
			this->btnStats->UseVisualStyleBackColor = true;
			this->btnStats->Click += gcnew System::EventHandler(this, &HomeForm::btnStats_Click);
			// 
			// btnCancelGame1
			// 
			this->btnCancelGame1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnCancelGame1.Image")));
			this->btnCancelGame1->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->btnCancelGame1->Location = System::Drawing::Point(113, 234);
			this->btnCancelGame1->Name = L"btnCancelGame1";
			this->btnCancelGame1->Padding = System::Windows::Forms::Padding(2, 0, 0, 0);
			this->btnCancelGame1->Size = System::Drawing::Size(88, 37);
			this->btnCancelGame1->TabIndex = 21;
			this->btnCancelGame1->Text = L"      Ponistite";
			this->btnCancelGame1->UseVisualStyleBackColor = true;
			// 
			// btnCancelGame2
			// 
			this->btnCancelGame2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnCancelGame2.Image")));
			this->btnCancelGame2->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->btnCancelGame2->Location = System::Drawing::Point(318, 234);
			this->btnCancelGame2->Name = L"btnCancelGame2";
			this->btnCancelGame2->Padding = System::Windows::Forms::Padding(2, 0, 0, 0);
			this->btnCancelGame2->Size = System::Drawing::Size(88, 37);
			this->btnCancelGame2->TabIndex = 22;
			this->btnCancelGame2->Text = L"      Ponistite";
			this->btnCancelGame2->UseVisualStyleBackColor = true;
			// 
			// btnCancelGame3
			// 
			this->btnCancelGame3->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnCancelGame3.Image")));
			this->btnCancelGame3->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->btnCancelGame3->Location = System::Drawing::Point(522, 234);
			this->btnCancelGame3->Name = L"btnCancelGame3";
			this->btnCancelGame3->Padding = System::Windows::Forms::Padding(2, 0, 0, 0);
			this->btnCancelGame3->Size = System::Drawing::Size(88, 37);
			this->btnCancelGame3->TabIndex = 23;
			this->btnCancelGame3->Text = L"      Ponistite";
			this->btnCancelGame3->UseVisualStyleBackColor = true;
			// 
			// btnCancelGame4
			// 
			this->btnCancelGame4->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnCancelGame4.Image")));
			this->btnCancelGame4->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->btnCancelGame4->Location = System::Drawing::Point(726, 234);
			this->btnCancelGame4->Name = L"btnCancelGame4";
			this->btnCancelGame4->Padding = System::Windows::Forms::Padding(2, 0, 0, 0);
			this->btnCancelGame4->Size = System::Drawing::Size(88, 37);
			this->btnCancelGame4->TabIndex = 24;
			this->btnCancelGame4->Text = L"      Ponistite";
			this->btnCancelGame4->UseVisualStyleBackColor = true;
			// 
			// pomocToolStripMenuItem
			// 
			this->pomocToolStripMenuItem->Name = L"pomocToolStripMenuItem";
			this->pomocToolStripMenuItem->Size = System::Drawing::Size(57, 20);
			this->pomocToolStripMenuItem->Text = L"Pomoc";
			// 
			// HomeForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoScroll = true;
			this->ClientSize = System::Drawing::Size(838, 399);
			this->Controls->Add(this->btnCancelGame4);
			this->Controls->Add(this->btnCancelGame3);
			this->Controls->Add(this->btnCancelGame2);
			this->Controls->Add(this->btnCancelGame1);
			this->Controls->Add(this->btnStats);
			this->Controls->Add(this->lblUsername);
			this->Controls->Add(this->btnStartGame4);
			this->Controls->Add(this->btnUGame4);
			this->Controls->Add(this->btnStartGame3);
			this->Controls->Add(this->btnUGame3);
			this->Controls->Add(this->btnStartGame2);
			this->Controls->Add(this->btnUGame2);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->lblbingo);
			this->Controls->Add(this->lblKviz);
			this->Controls->Add(this->btnUGame1);
			this->Controls->Add(this->btnStartGame1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->menuStrip1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MainMenuStrip = this->menuStrip1;
			this->MaximizeBox = false;
			this->Name = L"HomeForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"GamePlay";
			this->Load += gcnew System::EventHandler(this, &HomeForm::HomeForm_Load);
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
	
	}
	private: System::Void btnGame1_Click(System::Object^  sender, System::EventArgs^  e) {
		testFun(1);
		
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
		testFun(3);
	}
private: System::Void clearUsernameToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	HomeForm::Hide();
	clearUsername();
	this->lblUsername->Text = "Zdravo, " + getUsername();
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
	saveFileDialog1->FileName = name + ".csv";
	//saveFileDialog1->AddExtension = ".csv";
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
private: System::Void HomeForm_Load(System::Object^  sender, System::EventArgs^  e) {
	btnStartGame1->Enabled = true;
	btnStartGame2->Enabled = true;
	btnStartGame3->Enabled = true;
	btnStartGame4->Enabled = true;

	btnCancelGame1->Enabled = true;
	btnCancelGame2->Enabled = true;
	btnCancelGame3->Enabled = true;
	btnCancelGame4->Enabled = true;

	btnUGame1->Enabled = true;
	btnUGame2->Enabled = true;
	btnUGame3->Enabled = true;
	btnUGame4->Enabled = true;

	this->lblUsername->Text = L"Zdravo, " + getUsername();

}
private: System::Void btnStartGame4_Click(System::Object^  sender, System::EventArgs^  e) {
	testFun(4);
}
private: System::Void btnStartGame2_Click(System::Object^  sender, System::EventArgs^  e) {
	testFun(2);
}
private: System::Void izlazToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	Application::Exit();
}
private: System::Void oAutorimaToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	InfoAboutUs frm;
	frm.ShowDialog();
}
};
}


