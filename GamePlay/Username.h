#pragma once
#include "tinyxml2.h"
#include "XMLDataFile.h"
#include <msclr\marshal_cppstd.h>

namespace GamePlay {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Username
	/// </summary>
	public ref class Username : public System::Windows::Forms::Form
	{
	public:
		Username(void)
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
		~Username()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::TextBox^  txtUsername;
	private: System::Windows::Forms::Button^  btnSetUsername;
	private: System::Windows::Forms::Label^  lblTitle;
	private: System::Windows::Forms::Button^  btnCancel;


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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Username::typeid));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->txtUsername = (gcnew System::Windows::Forms::TextBox());
			this->btnSetUsername = (gcnew System::Windows::Forms::Button());
			this->lblTitle = (gcnew System::Windows::Forms::Label());
			this->btnCancel = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Adobe Heiti Std R", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(128)));
			this->label1->Location = System::Drawing::Point(14, 101);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(102, 19);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Korisniko ime";
			// 
			// txtUsername
			// 
			this->txtUsername->Font = (gcnew System::Drawing::Font(L"Adobe Gurmukhi", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->txtUsername->Location = System::Drawing::Point(151, 96);
			this->txtUsername->MaximumSize = System::Drawing::Size(116, 27);
			this->txtUsername->Name = L"txtUsername";
			this->txtUsername->Size = System::Drawing::Size(116, 27);
			this->txtUsername->TabIndex = 1;
			this->txtUsername->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->txtUsername->TextChanged += gcnew System::EventHandler(this, &Username::textBox1_TextChanged);
			// 
			// btnSetUsername
			// 
			this->btnSetUsername->Font = (gcnew System::Drawing::Font(L"Adobe Fan Heiti Std B", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnSetUsername->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnSetUsername.Image")));
			this->btnSetUsername->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->btnSetUsername->Location = System::Drawing::Point(18, 161);
			this->btnSetUsername->Name = L"btnSetUsername";
			this->btnSetUsername->Padding = System::Windows::Forms::Padding(10, 0, 0, 0);
			this->btnSetUsername->Size = System::Drawing::Size(113, 35);
			this->btnSetUsername->TabIndex = 2;
			this->btnSetUsername->Text = L"      Dalje";
			this->btnSetUsername->UseVisualStyleBackColor = true;
			this->btnSetUsername->Click += gcnew System::EventHandler(this, &Username::button1_Click);
			// 
			// lblTitle
			// 
			this->lblTitle->AutoSize = true;
			this->lblTitle->Font = (gcnew System::Drawing::Font(L"Adobe Fan Heiti Std B", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblTitle->Location = System::Drawing::Point(97, 23);
			this->lblTitle->Name = L"lblTitle";
			this->lblTitle->Size = System::Drawing::Size(96, 24);
			this->lblTitle->TabIndex = 3;
			this->lblTitle->Text = L"GamePlay";
			// 
			// btnCancel
			// 
			this->btnCancel->Font = (gcnew System::Drawing::Font(L"Adobe Fan Heiti Std B", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnCancel->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnCancel.Image")));
			this->btnCancel->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->btnCancel->Location = System::Drawing::Point(154, 161);
			this->btnCancel->Name = L"btnCancel";
			this->btnCancel->Padding = System::Windows::Forms::Padding(2, 0, 0, 0);
			this->btnCancel->Size = System::Drawing::Size(113, 35);
			this->btnCancel->TabIndex = 4;
			this->btnCancel->Text = L"      Odustani";
			this->btnCancel->UseVisualStyleBackColor = true;
			this->btnCancel->Click += gcnew System::EventHandler(this, &Username::btnCancel_Click);
			// 
			// Username
			// 
			this->AcceptButton = this->btnSetUsername;
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoValidate = System::Windows::Forms::AutoValidate::EnablePreventFocusChange;
			this->BackColor = System::Drawing::SystemColors::Control;
			this->ClientSize = System::Drawing::Size(288, 225);
			this->Controls->Add(this->btnCancel);
			this->Controls->Add(this->lblTitle);
			this->Controls->Add(this->btnSetUsername);
			this->Controls->Add(this->txtUsername);
			this->Controls->Add(this->label1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Name = L"Username";
			this->Padding = System::Windows::Forms::Padding(1);
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Username";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void textBox1_TextChanged(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
		if (txtUsername->TextLength == 0) {
			System::Windows::Forms::MessageBox::Show("Niste unijeli korisnicko ime!", "Greska", System::Windows::Forms::MessageBoxButtons::OK, System::Windows::Forms::MessageBoxIcon::Error);
		}
		else {
			System::String^ managedString = txtUsername->Text;

			msclr::interop::marshal_context context;
			std::string standardString = context.marshal_as<std::string>(managedString);
			setUserName(standardString);
			this->Close();
		}
	}
	private: System::Void btnCancel_Click(System::Object^  sender, System::EventArgs^  e) {
		Application::Exit();
	}
};
}
