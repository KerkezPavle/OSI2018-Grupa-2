#pragma once

namespace GamePlay {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for InfoAboutUs
	/// </summary>
	public ref class InfoAboutUs : public System::Windows::Forms::Form
	{
	public:
		InfoAboutUs(void)
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
		~InfoAboutUs()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::ListView^  listView1;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::ColumnHeader^  columnHeader1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::PictureBox^  pictureBox1;
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
			System::Windows::Forms::ListViewItem^  listViewItem1 = (gcnew System::Windows::Forms::ListViewItem(gcnew cli::array< System::String^  >(1) { L"Dusko Djudjic" },
				-1, System::Drawing::Color::Empty, System::Drawing::Color::Empty, (gcnew System::Drawing::Font(L"Cambria", 12))));
			System::Windows::Forms::ListViewItem^  listViewItem2 = (gcnew System::Windows::Forms::ListViewItem(gcnew cli::array< System::String^  >(1) { L"Zeljko Illic" },
				-1, System::Drawing::Color::Empty, System::Drawing::Color::Empty, (gcnew System::Drawing::Font(L"Cambria", 12))));
			System::Windows::Forms::ListViewItem^  listViewItem3 = (gcnew System::Windows::Forms::ListViewItem(gcnew cli::array< System::String^  >(1) { L"Samuel Karic" },
				-1, System::Drawing::Color::Empty, System::Drawing::Color::Empty, (gcnew System::Drawing::Font(L"Cambria", 12))));
			System::Windows::Forms::ListViewItem^  listViewItem4 = (gcnew System::Windows::Forms::ListViewItem(gcnew cli::array< System::String^  >(1) { L"Pavle Kerkez" },
				-1, System::Drawing::Color::Empty, System::Drawing::Color::Empty, (gcnew System::Drawing::Font(L"Cambria", 12))));
			System::Windows::Forms::ListViewItem^  listViewItem5 = (gcnew System::Windows::Forms::ListViewItem(gcnew cli::array< System::String^  >(1) { L"Marija Kovac" },
				-1, System::Drawing::Color::Empty, System::Drawing::Color::Empty, (gcnew System::Drawing::Font(L"Cambria", 12))));
			System::Windows::Forms::ListViewItem^  listViewItem6 = (gcnew System::Windows::Forms::ListViewItem(gcnew cli::array< System::String^  >(1) { L"Zelimir Maletic" },
				-1, System::Drawing::Color::Empty, System::Drawing::Color::Empty, (gcnew System::Drawing::Font(L"Cambria", 12))));
			System::Windows::Forms::ListViewItem^  listViewItem7 = (gcnew System::Windows::Forms::ListViewItem(gcnew cli::array< System::String^  >(1) { L"Ratko Rajkovic" },
				-1, System::Drawing::Color::Empty, System::Drawing::Color::Empty, (gcnew System::Drawing::Font(L"Cambria", 12))));
			System::Windows::Forms::ListViewItem^  listViewItem8 = (gcnew System::Windows::Forms::ListViewItem(gcnew cli::array< System::String^  >(1) { L"Ognjen Stefanovic" },
				-1, System::Drawing::Color::Empty, System::Drawing::Color::Empty, (gcnew System::Drawing::Font(L"Cambria", 12))));
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(InfoAboutUs::typeid));
			this->listView1 = (gcnew System::Windows::Forms::ListView());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->columnHeader1 = (gcnew System::Windows::Forms::ColumnHeader());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// listView1
			// 
			this->listView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::ColumnHeader^  >(1) { this->columnHeader1 });
			this->listView1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ListViewItem^  >(8) {
				listViewItem1, listViewItem2,
					listViewItem3, listViewItem4, listViewItem5, listViewItem6, listViewItem7, listViewItem8
			});
			this->listView1->Location = System::Drawing::Point(12, 130);
			this->listView1->Name = L"listView1";
			this->listView1->Size = System::Drawing::Size(508, 119);
			this->listView1->TabIndex = 0;
			this->listView1->UseCompatibleStateImageBehavior = false;
			this->listView1->View = System::Windows::Forms::View::Tile;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Cambria", 20.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(13, 13);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(144, 32);
			this->label1->TabIndex = 1;
			this->label1->Text = L"O autorima";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(16, 100);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(133, 13);
			this->label2->TabIndex = 2;
			this->label2->Text = L"Ovu aplikaciju su napravili:";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(19, 49);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(202, 13);
			this->label3->TabIndex = 3;
			this->label3->Text = L"Grupa 2 - Osnovi softwerskog inzinjerstva";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(16, 73);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(101, 13);
			this->label4->TabIndex = 4;
			this->label4->Text = L"2018 / 2019 godina";
			// 
			// pictureBox1
			// 
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(404, 12);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(116, 100);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox1->TabIndex = 5;
			this->pictureBox1->TabStop = false;
			// 
			// InfoAboutUs
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(532, 261);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->listView1);
			this->Name = L"InfoAboutUs";
			this->Text = L"O autorima";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	};
}
