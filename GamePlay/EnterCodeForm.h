#pragma once

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
	private: System::Windows::Forms::Label^  label1;

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
			this->txtCode1 = (gcnew System::Windows::Forms::TextBox());
			this->txtCode2 = (gcnew System::Windows::Forms::TextBox());
			this->txtCode3 = (gcnew System::Windows::Forms::TextBox());
			this->txtCode4 = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// txtCode1
			// 
			this->txtCode1->Location = System::Drawing::Point(13, 113);
			this->txtCode1->Name = L"txtCode1";
			this->txtCode1->Size = System::Drawing::Size(76, 20);
			this->txtCode1->TabIndex = 0;
			// 
			// txtCode2
			// 
			this->txtCode2->Location = System::Drawing::Point(118, 113);
			this->txtCode2->Name = L"txtCode2";
			this->txtCode2->Size = System::Drawing::Size(76, 20);
			this->txtCode2->TabIndex = 1;
			// 
			// txtCode3
			// 
			this->txtCode3->Location = System::Drawing::Point(223, 113);
			this->txtCode3->Name = L"txtCode3";
			this->txtCode3->Size = System::Drawing::Size(76, 20);
			this->txtCode3->TabIndex = 2;
			// 
			// txtCode4
			// 
			this->txtCode4->Location = System::Drawing::Point(326, 113);
			this->txtCode4->Name = L"txtCode4";
			this->txtCode4->Size = System::Drawing::Size(76, 20);
			this->txtCode4->TabIndex = 3;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(103, 198);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(91, 37);
			this->button1->TabIndex = 4;
			this->button1->Text = L"Unlock";
			this->button1->UseVisualStyleBackColor = true;
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(223, 198);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(92, 37);
			this->button2->TabIndex = 5;
			this->button2->Text = L"Cancel";
			this->button2->UseVisualStyleBackColor = true;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(193, 22);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(35, 13);
			this->label1->TabIndex = 6;
			this->label1->Text = L"label1";
			// 
			// EnterCodeForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(422, 261);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->txtCode4);
			this->Controls->Add(this->txtCode3);
			this->Controls->Add(this->txtCode2);
			this->Controls->Add(this->txtCode1);
			this->Name = L"EnterCodeForm";
			this->Text = L"EnterCodeForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	};
}
