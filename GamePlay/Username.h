#pragma once


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
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->txtUsername = (gcnew System::Windows::Forms::TextBox());
			this->btnSetUsername = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Adobe Fan Heiti Std B", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(69, 21);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(128, 20);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Enter Username";
			this->label1->Click += gcnew System::EventHandler(this, &Username::label1_Click);
			// 
			// txtUsername
			// 
			this->txtUsername->Location = System::Drawing::Point(81, 83);
			this->txtUsername->Name = L"txtUsername";
			this->txtUsername->Size = System::Drawing::Size(116, 20);
			this->txtUsername->TabIndex = 1;
			this->txtUsername->TextChanged += gcnew System::EventHandler(this, &Username::textBox1_TextChanged);
			// 
			// btnSetUsername
			// 
			this->btnSetUsername->Location = System::Drawing::Point(81, 138);
			this->btnSetUsername->Name = L"btnSetUsername";
			this->btnSetUsername->Size = System::Drawing::Size(108, 35);
			this->btnSetUsername->TabIndex = 2;
			this->btnSetUsername->Text = L"Next";
			this->btnSetUsername->UseVisualStyleBackColor = true;
			this->btnSetUsername->Click += gcnew System::EventHandler(this, &Username::button1_Click);
			// 
			// Username
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(288, 225);
			this->Controls->Add(this->btnSetUsername);
			this->Controls->Add(this->txtUsername);
			this->Controls->Add(this->label1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Name = L"Username";
			this->Text = L"Username";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void label1_Click(System::Object^  sender, System::EventArgs^  e) {
		
	}
	private: System::Void textBox1_TextChanged(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
		if (txtUsername->TextLength == 0) {
			// Set Username function here
		}
		else {
			this->Close();
		}
	}
	};
}
