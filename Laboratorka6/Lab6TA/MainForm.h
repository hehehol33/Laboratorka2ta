#pragma once
#include "TaOpenAdressingHashing.h"
#include <string> // Наприклад, для std::string
#include <vector> 
namespace Lab6TA {
	
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MainForm
	/// </summary>
	public ref class MainForm : public System::Windows::Forms::Form
	{
	
	public:
		MainForm(void)
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
		~MainForm()
		{
			if (components)
			{
				delete components;
			}
		}
	
	private: System::Windows::Forms::Label^ label6;
	protected:
	private: System::Windows::Forms::TextBox^ textBox_find;
	private: System::Windows::Forms::Button^ button_find;
	private: System::Windows::Forms::Label^ label_time;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Button^ button_delete;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Button^ button_add;
	private: System::Windows::Forms::TextBox^ textBox_grade;
	private: System::Windows::Forms::TextBox^ textBox_name;
	private: System::Windows::Forms::ComboBox^ comboBox_method;
	private: System::Windows::Forms::ListBox^ listBox_students;
	private: System::Windows::Forms::TextBox^ textBox_size;

	private: System::Windows::Forms::Button^ button_create;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Button^ button1;

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
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->textBox_find = (gcnew System::Windows::Forms::TextBox());
			this->button_find = (gcnew System::Windows::Forms::Button());
			this->label_time = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->button_delete = (gcnew System::Windows::Forms::Button());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->button_add = (gcnew System::Windows::Forms::Button());
			this->textBox_grade = (gcnew System::Windows::Forms::TextBox());
			this->textBox_name = (gcnew System::Windows::Forms::TextBox());
			this->comboBox_method = (gcnew System::Windows::Forms::ComboBox());
			this->listBox_students = (gcnew System::Windows::Forms::ListBox());
			this->textBox_size = (gcnew System::Windows::Forms::TextBox());
			this->button_create = (gcnew System::Windows::Forms::Button());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(147)), static_cast<System::Int32>(static_cast<System::Byte>(71)),
				static_cast<System::Int32>(static_cast<System::Byte>(227)));
			this->label6->Location = System::Drawing::Point(89, 447);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(101, 16);
			this->label6->TabIndex = 30;
			this->label6->Text = L"Введіть індекс";
			// 
			// textBox_find
			// 
			this->textBox_find->Location = System::Drawing::Point(28, 466);
			this->textBox_find->Name = L"textBox_find";
			this->textBox_find->Size = System::Drawing::Size(234, 22);
			this->textBox_find->TabIndex = 29;
			// 
			// button_find
			// 
			this->button_find->BackColor = System::Drawing::Color::AliceBlue;
			this->button_find->Location = System::Drawing::Point(27, 375);
			this->button_find->Name = L"button_find";
			this->button_find->Size = System::Drawing::Size(235, 69);
			this->button_find->TabIndex = 28;
			this->button_find->Text = L"Знайти студента за хеш-індексом";
			this->button_find->UseVisualStyleBackColor = false;
			this->button_find->Click += gcnew System::EventHandler(this, &MainForm::button_find_Click);
			// 
			// label_time
			// 
			this->label_time->AutoSize = true;
			this->label_time->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(147)), static_cast<System::Int32>(static_cast<System::Byte>(71)),
				static_cast<System::Int32>(static_cast<System::Byte>(227)));
			this->label_time->Location = System::Drawing::Point(25, 580);
			this->label_time->Name = L"label_time";
			this->label_time->Size = System::Drawing::Size(11, 16);
			this->label_time->TabIndex = 27;
			this->label_time->Text = L"-";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Verdana", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label5->Location = System::Drawing::Point(282, 459);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(468, 25);
			this->label5->TabIndex = 26;
			this->label5->Text = L"Тема: Пошук у масиві. Закрите хешування.";
			// 
			// label4
			// 
			this->label4->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(147)), static_cast<System::Int32>(static_cast<System::Byte>(71)),
				static_cast<System::Int32>(static_cast<System::Byte>(227)));
			this->label4->Font = (gcnew System::Drawing::Font(L"Arial Nova Cond", 24, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->Location = System::Drawing::Point(279, 399);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(610, 48);
			this->label4->TabIndex = 25;
			this->label4->Text = L"Комп’ютерний практикум №6 ";
			// 
			// button_delete
			// 
			this->button_delete->BackColor = System::Drawing::Color::AliceBlue;
			this->button_delete->Location = System::Drawing::Point(27, 300);
			this->button_delete->Name = L"button_delete";
			this->button_delete->Size = System::Drawing::Size(235, 69);
			this->button_delete->TabIndex = 24;
			this->button_delete->Text = L"Видалити елемент з хеш-таблиці";
			this->button_delete->UseVisualStyleBackColor = false;
			this->button_delete->Click += gcnew System::EventHandler(this, &MainForm::button_delete_Click);
			// 
			// label3
			// 
			this->label3->Location = System::Drawing::Point(275, 399);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(44, 25);
			this->label3->TabIndex = 23;
			this->label3->Text = L"-";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(147)), static_cast<System::Int32>(static_cast<System::Byte>(71)),
				static_cast<System::Int32>(static_cast<System::Byte>(227)));
			this->label2->Location = System::Drawing::Point(99, 177);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(84, 16);
			this->label2->TabIndex = 22;
			this->label2->Text = L"Введіть бал";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(147)), static_cast<System::Int32>(static_cast<System::Byte>(71)),
				static_cast<System::Int32>(static_cast<System::Byte>(227)));
			this->label1->Location = System::Drawing::Point(72, 124);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(146, 16);
			this->label1->TabIndex = 21;
			this->label1->Text = L"Введіть ПІБ студента";
			// 
			// button_add
			// 
			this->button_add->BackColor = System::Drawing::Color::AliceBlue;
			this->button_add->Location = System::Drawing::Point(27, 228);
			this->button_add->Name = L"button_add";
			this->button_add->Size = System::Drawing::Size(235, 66);
			this->button_add->TabIndex = 20;
			this->button_add->Text = L"Додати до Хеш Таблиці";
			this->button_add->UseVisualStyleBackColor = false;
			this->button_add->Click += gcnew System::EventHandler(this, &MainForm::button_add_Click);
			// 
			// textBox_grade
			// 
			this->textBox_grade->Location = System::Drawing::Point(27, 196);
			this->textBox_grade->Name = L"textBox_grade";
			this->textBox_grade->Size = System::Drawing::Size(235, 22);
			this->textBox_grade->TabIndex = 19;
			// 
			// textBox_name
			// 
			this->textBox_name->Location = System::Drawing::Point(27, 143);
			this->textBox_name->Name = L"textBox_name";
			this->textBox_name->Size = System::Drawing::Size(235, 22);
			this->textBox_name->TabIndex = 18;
			// 
			// comboBox_method
			// 
			this->comboBox_method->FormattingEnabled = true;
			this->comboBox_method->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"QuadraticProbing", L"LinearProbing" });
			this->comboBox_method->Location = System::Drawing::Point(27, 80);
			this->comboBox_method->Name = L"comboBox_method";
			this->comboBox_method->Size = System::Drawing::Size(235, 24);
			this->comboBox_method->TabIndex = 17;
			this->comboBox_method->Text = L"Вибрати метод";
			// 
			// listBox_students
			// 
			this->listBox_students->ItemHeight = 16;
			this->listBox_students->Location = System::Drawing::Point(279, 33);
			this->listBox_students->Name = L"listBox_students";
			this->listBox_students->Size = System::Drawing::Size(610, 340);
			this->listBox_students->TabIndex = 16;
			// 
			// textBox_size
			// 
			this->textBox_size->Location = System::Drawing::Point(27, 33);
			this->textBox_size->Name = L"textBox_size";
			this->textBox_size->Size = System::Drawing::Size(126, 22);
			this->textBox_size->TabIndex = 31;
			// 
			// button_create
			// 
			this->button_create->Location = System::Drawing::Point(159, 32);
			this->button_create->Name = L"button_create";
			this->button_create->Size = System::Drawing::Size(103, 23);
			this->button_create->TabIndex = 32;
			this->button_create->Text = L"Створити";
			this->button_create->UseVisualStyleBackColor = true;
			this->button_create->Click += gcnew System::EventHandler(this, &MainForm::button_create_Click);
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(147)), static_cast<System::Int32>(static_cast<System::Byte>(71)),
				static_cast<System::Int32>(static_cast<System::Byte>(227)));
			this->label7->Location = System::Drawing::Point(51, 14);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(184, 16);
			this->label7->TabIndex = 33;
			this->label7->Text = L"Введіть розмір хеш-таблиці";
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::MistyRose;
			this->button1->Location = System::Drawing::Point(27, 494);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(235, 59);
			this->button1->TabIndex = 34;
			this->button1->Text = L"Видалити хеш-таблицю";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &MainForm::button1_Click);
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(203)), static_cast<System::Int32>(static_cast<System::Byte>(166)),
				static_cast<System::Int32>(static_cast<System::Byte>(242)));
			this->ClientSize = System::Drawing::Size(937, 605);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->button_create);
			this->Controls->Add(this->textBox_size);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->textBox_find);
			this->Controls->Add(this->button_find);
			this->Controls->Add(this->label_time);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->button_delete);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button_add);
			this->Controls->Add(this->textBox_grade);
			this->Controls->Add(this->textBox_name);
			this->Controls->Add(this->comboBox_method);
			this->Controls->Add(this->listBox_students);
			this->Name = L"MainForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"КП №6";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button_create_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void button_add_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void button_delete_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void button_find_Click(System::Object^ sender, System::EventArgs^ e);

private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e);
};
}
