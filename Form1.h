#pragma once

#include "processEverything.h"
#include <msclr/marshal.h> // Include marshal.h for marshal_context 
#include <msclr/marshal_cppstd.h>
#include "pch.h"


//using namespace System::Windows::Forms;
#include <iostream>
#include <string>
using namespace msclr::interop; // Namespace for marshal_context

namespace CppCLRWinFormsProject {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Form1
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
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
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::ComboBox^ comboBox1;
	private: System::Windows::Forms::TrackBar^ trackBar1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ label7;


	private: System::ComponentModel::IContainer^ components;

	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->trackBar1 = (gcnew System::Windows::Forms::TrackBar());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar1))->BeginInit();
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(109, 208);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Create File!";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(9, 182);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(376, 20);
			this->textBox1->TabIndex = 1;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(6, 115);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(358, 13);
			this->label1->TabIndex = 2;
			this->label1->Text = L"Enter the full path for the file and its name, it should be in a format like this"
				L": ";
			this->label1->Click += gcnew System::EventHandler(this, &Form1::label1_Click);
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(9, 131);
			this->textBox2->Name = L"textBox2";
			this->textBox2->ReadOnly = true;
			this->textBox2->Size = System::Drawing::Size(267, 20);
			this->textBox2->TabIndex = 3;
			this->textBox2->Text = L"C:\\\\Users\\\\user\\\\OneDrive\\\\Desktop\\\\filename.wav";
			// 
			// comboBox1
			// 
			this->comboBox1->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Items->AddRange(gcnew cli::array< System::Object^  >(4) { L"sine", L"sawtooth", L"square", L"triangle" });
			this->comboBox1->Location = System::Drawing::Point(9, 44);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(121, 21);
			this->comboBox1->TabIndex = 4;
			this->comboBox1->SelectedIndexChanged += gcnew System::EventHandler(this, &Form1::comboBox1_SelectedIndexChanged);
			// 
			// trackBar1
			// 
			this->trackBar1->Cursor = System::Windows::Forms::Cursors::Hand;
			this->trackBar1->Location = System::Drawing::Point(253, 44);
			this->trackBar1->Maximum = 20;
			this->trackBar1->Minimum = 1;
			this->trackBar1->Name = L"trackBar1";
			this->trackBar1->Size = System::Drawing::Size(132, 45);
			this->trackBar1->TabIndex = 5;
			this->trackBar1->Value = 1;
			this->trackBar1->Scroll += gcnew System::EventHandler(this, &Form1::trackBar1_Scroll);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(13, 25);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(115, 13);
			this->label2->TabIndex = 6;
			this->label2->Text = L"Select Waveform type:";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(250, 25);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(135, 13);
			this->label3->TabIndex = 7;
			this->label3->Text = L"Select duration in seconds:";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(263, 76);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(13, 13);
			this->label4->TabIndex = 8;
			this->label4->Text = L"1";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(366, 76);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(19, 13);
			this->label5->TabIndex = 9;
			this->label5->Text = L"20";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->label6->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->label6->Location = System::Drawing::Point(390, 25);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(15, 15);
			this->label6->TabIndex = 10;
			this->label6->Text = L"1";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(6, 154);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(420, 13);
			this->label7->TabIndex = 11;
			this->label7->Text = L"(if only type the filename.wav the file will be created in the same folder where "
				L"the .exe is)";
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(438, 261);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->trackBar1);
			this->Controls->Add(this->comboBox1);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->button1);
			this->Name = L"Form1";
			this->Text = L"Sound Generator ";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {

		// Convert System::String^ to const char*
		System::String^ managedStr = textBox1->Text;
		marshal_context context;
		const char* outputFileName = context.marshal_as<const char*>(managedStr);

//  D:\\maynooth\\music system progr 2\\csound and libsndfile\\archivaso.wav   --like this should be passed full path
		processEverything(outputFileName);
	//	processEverything();
	//	MessageBox::Show("me clickeastee and the text box says: "+  textBox1->Text );
	

	}
	private: System::Void Form1_Load(System::Object^ sender, System::EventArgs^ e) {
		comboBox1->SelectedIndex = 0;
	}
	private: System::Void comboBox1_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
	
		System::String^ managedStr = comboBox1->Text;
		marshal_context context;
		waveName = context.marshal_as<std::string>(managedStr);
		//waveName = msclr::interop::marshal_as<std::string>(managedStr); // is the same
		//	MessageBox::Show(managedStr);
	}
private: System::Void trackBar1_Scroll(System::Object^ sender, System::EventArgs^ e) {
	label6->Text = (trackBar1->Value).ToString();
	LenghtInSeconds = trackBar1->Value;
}
private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
}
};
}
