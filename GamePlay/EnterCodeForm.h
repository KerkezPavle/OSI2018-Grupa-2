#pragma once
#include <cctype>

namespace GamePlay {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for EnterCodeForm
	/// </summary>
	public ref class EnterCodeForm : public System::Windows::Forms::Form
	{
	public:
		EnterCodeForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

		property System::String^ GameCode {
			System::String^ get() {
				return lblGameCode->Text;
			}

			void set(System::String^ text) {
				lblGameCode->Text = text;
				if (text == "1")
					lblGameName->Text = "Guess the Number";
				else if(text == "2")
					lblGameName->Text = "Quiz";
				else if(text == "3")
					lblGameName->Text = "Bingo";
				else if(text == "4")
					lblGameName->Text = "Minesweeper";
			}
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~EnterCodeForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^  txtCode1;
	private: System::Windows::Forms::TextBox^  txtCode2;
	protected:


	private: System::Windows::Forms::TextBox^  txtCode3;
	private: System::Windows::Forms::TextBox^  txtCode4;
	protected:



	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Label^  lblEnterCode;
	private: System::Windows::Forms::Label^  lblGameCode;
	private: System::Windows::Forms::Label^  lblGameName;


	protected:

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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(EnterCodeForm::typeid));
			this->txtCode1 = (gcnew System::Windows::Forms::TextBox());
			this->txtCode2 = (gcnew System::Windows::Forms::TextBox());
			this->txtCode3 = (gcnew System::Windows::Forms::TextBox());
			this->txtCode4 = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->lblEnterCode = (gcnew System::Windows::Forms::Label());
			this->lblGameCode = (gcnew System::Windows::Forms::Label());
			this->lblGameName = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// txtCode1
			// 
			this->txtCode1->Location = System::Drawing::Point(13, 113);
			this->txtCode1->MaxLength = 4;
			this->txtCode1->Name = L"txtCode1";
			this->txtCode1->Size = System::Drawing::Size(76, 20);
			this->txtCode1->TabIndex = 0;
			this->txtCode1->TextChanged += gcnew System::EventHandler(this, &EnterCodeForm::txtCode1_TextChanged);
			this->txtCode1->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &EnterCodeForm::txtCode1_KeyPress);
			// 
			// txtCode2
			// 
			this->txtCode2->Location = System::Drawing::Point(118, 113);
			this->txtCode2->MaxLength = 4;
			this->txtCode2->Name = L"txtCode2";
			this->txtCode2->Size = System::Drawing::Size(76, 20);
			this->txtCode2->TabIndex = 1;
			this->txtCode2->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &EnterCodeForm::txtCode1_KeyPress);
			// 
			// txtCode3
			// 
			this->txtCode3->Location = System::Drawing::Point(223, 113);
			this->txtCode3->MaxLength = 4;
			this->txtCode3->Name = L"txtCode3";
			this->txtCode3->Size = System::Drawing::Size(76, 20);
			this->txtCode3->TabIndex = 2;
			this->txtCode3->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &EnterCodeForm::txtCode1_KeyPress);
			// 
			// txtCode4
			// 
			this->txtCode4->Location = System::Drawing::Point(326, 113);
			this->txtCode4->MaxLength = 4;
			this->txtCode4->Name = L"txtCode4";
			this->txtCode4->Size = System::Drawing::Size(76, 20);
			this->txtCode4->TabIndex = 3;
			this->txtCode4->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &EnterCodeForm::txtCode1_KeyPress);
			// 
			// button1
			// 
			this->button1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button1.Image")));
			this->button1->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->button1->Location = System::Drawing::Point(103, 198);
			this->button1->Name = L"button1";
			this->button1->Padding = System::Windows::Forms::Padding(5, 0, 0, 0);
			this->button1->Size = System::Drawing::Size(91, 37);
			this->button1->TabIndex = 4;
			this->button1->Text = L"   Unlock";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &EnterCodeForm::button1_Click);
			// 
			// button2
			// 
			this->button2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button2.Image")));
			this->button2->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->button2->Location = System::Drawing::Point(223, 198);
			this->button2->Name = L"button2";
			this->button2->Padding = System::Windows::Forms::Padding(5, 0, 0, 0);
			this->button2->Size = System::Drawing::Size(92, 37);
			this->button2->TabIndex = 5;
			this->button2->Text = L"   Cancel";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &EnterCodeForm::button2_Click);
			// 
			// lblEnterCode
			// 
			this->lblEnterCode->AutoSize = true;
			this->lblEnterCode->Font = (gcnew System::Drawing::Font(L"Cambria", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblEnterCode->Location = System::Drawing::Point(14, 37);
			this->lblEnterCode->Name = L"lblEnterCode";
			this->lblEnterCode->Size = System::Drawing::Size(180, 22);
			this->lblEnterCode->TabIndex = 6;
			this->lblEnterCode->Text = L"Enter Code for game:";
			// 
			// lblGameCode
			// 
			this->lblGameCode->AutoSize = true;
			this->lblGameCode->Font = (gcnew System::Drawing::Font(L"Cambria", 14.25F));
			this->lblGameCode->Location = System::Drawing::Point(197, 37);
			this->lblGameCode->Name = L"lblGameCode";
			this->lblGameCode->Size = System::Drawing::Size(21, 22);
			this->lblGameCode->TabIndex = 7;
			this->lblGameCode->Text = L"1";
			this->lblGameCode->Click += gcnew System::EventHandler(this, &EnterCodeForm::lblGameCode_Click);
			// 
			// lblGameName
			// 
			this->lblGameName->AutoSize = true;
			this->lblGameName->Font = (gcnew System::Drawing::Font(L"Cambria", 14.25F));
			this->lblGameName->Location = System::Drawing::Point(224, 37);
			this->lblGameName->Name = L"lblGameName";
			this->lblGameName->Size = System::Drawing::Size(59, 22);
			this->lblGameName->TabIndex = 8;
			this->lblGameName->Text = L"label1";
			// 
			// EnterCodeForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(422, 261);
			this->Controls->Add(this->lblGameName);
			this->Controls->Add(this->lblGameCode);
			this->Controls->Add(this->lblEnterCode);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->txtCode4);
			this->Controls->Add(this->txtCode3);
			this->Controls->Add(this->txtCode2);
			this->Controls->Add(this->txtCode1);
			this->Name = L"EnterCodeForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
			this->Text = L"EnterCodeForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void lblGameCode_Click(System::Object^  sender, System::EventArgs^  e) {
		
	}
private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
	int num = int::Parse(lblGameCode->Text);
	System::String^ s1 = txtCode1->Text;
	System::String^ s2 = txtCode2->Text;
	System::String^ s3 = txtCode3->Text;
	System::String^ s4 = txtCode4->Text;
	System::String^ s = s1 + s2 + s3 + s4;
	if (s->Length < 16) {
		System::Windows::Forms::MessageBox::Show("Code is not corretly filled", "Game " + num, System::Windows::Forms::MessageBoxButtons::RetryCancel, System::Windows::Forms::MessageBoxIcon::Error);

	}
	else {
		System::Windows::Forms::MessageBox::Show(s, "Game " + num, System::Windows::Forms::MessageBoxButtons::OK, System::Windows::Forms::MessageBoxIcon::Information);
		this->Close();
	}

}
private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
	this->Close();
}
private: System::Void txtCode1_TextChanged(System::Object^  sender, System::EventArgs^  e) {

}
private: System::Void txtCode1_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) {
	if (e->KeyChar != '\b') {
		e->Handled = !std::isdigit(e->KeyChar);
	}
}
};
}
