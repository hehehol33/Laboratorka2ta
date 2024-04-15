#pragma once

namespace Laboratorka4 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for PointerForm
	/// </summary>
	public ref class PointerForm : public System::Windows::Forms::Form
	{
	public:
		PointerForm(void)
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
		~PointerForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ button_delete_grade;
	protected:
	private: System::Windows::Forms::Button^ button_delete;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::ListBox^ listBox3;
	private: System::Windows::Forms::Button^ button_add;
	private: System::Windows::Forms::Button^ button_save2;
	private: System::Windows::Forms::TextBox^ textBox_input_grade;
	private: System::Windows::Forms::Button^ button_save;
	private: System::Windows::Forms::TextBox^ textBox_input;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::ListBox^ listBox2;
	private: System::Windows::Forms::ListBox^ listBox1;

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
			this->button_delete_grade = (gcnew System::Windows::Forms::Button());
			this->button_delete = (gcnew System::Windows::Forms::Button());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->listBox3 = (gcnew System::Windows::Forms::ListBox());
			this->button_add = (gcnew System::Windows::Forms::Button());
			this->button_save2 = (gcnew System::Windows::Forms::Button());
			this->textBox_input_grade = (gcnew System::Windows::Forms::TextBox());
			this->button_save = (gcnew System::Windows::Forms::Button());
			this->textBox_input = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->listBox2 = (gcnew System::Windows::Forms::ListBox());
			this->listBox1 = (gcnew System::Windows::Forms::ListBox());
			this->SuspendLayout();
			// 
			// button_delete_grade
			// 
			this->button_delete_grade->BackColor = System::Drawing::Color::MistyRose;
			this->button_delete_grade->FlatAppearance->BorderColor = System::Drawing::Color::Red;
			this->button_delete_grade->FlatAppearance->BorderSize = 2;
			this->button_delete_grade->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button_delete_grade->Location = System::Drawing::Point(481, 548);
			this->button_delete_grade->Name = L"button_delete_grade";
			this->button_delete_grade->Size = System::Drawing::Size(142, 30);
			this->button_delete_grade->TabIndex = 25;
			this->button_delete_grade->Text = L"Видалити оцінку";
			this->button_delete_grade->UseVisualStyleBackColor = false;
			this->button_delete_grade->Click += gcnew System::EventHandler(this, &PointerForm::button_delete_grade_Click);
			// 
			// button_delete
			// 
			this->button_delete->BackColor = System::Drawing::Color::MistyRose;
			this->button_delete->FlatAppearance->BorderColor = System::Drawing::Color::Red;
			this->button_delete->FlatAppearance->BorderSize = 2;
			this->button_delete->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button_delete->Location = System::Drawing::Point(63, 548);
			this->button_delete->Name = L"button_delete";
			this->button_delete->Size = System::Drawing::Size(253, 30);
			this->button_delete->TabIndex = 24;
			this->button_delete->Text = L"Прибрати елемент зі стопки";
			this->button_delete->UseVisualStyleBackColor = false;
			this->button_delete->Click += gcnew System::EventHandler(this, &PointerForm::button_delete_Click);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->BackColor = System::Drawing::SystemColors::GradientActiveCaption;
			this->label3->Location = System::Drawing::Point(868, 58);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(55, 16);
			this->label3->TabIndex = 23;
			this->label3->Text = L"Кампус";
			// 
			// listBox3
			// 
			this->listBox3->FormattingEnabled = true;
			this->listBox3->ItemHeight = 16;
			this->listBox3->Location = System::Drawing::Point(731, 77);
			this->listBox3->Name = L"listBox3";
			this->listBox3->Size = System::Drawing::Size(329, 388);
			this->listBox3->TabIndex = 22;
			// 
			// button_add
			// 
			this->button_add->BackColor = System::Drawing::Color::DarkSeaGreen;
			this->button_add->Location = System::Drawing::Point(783, 498);
			this->button_add->Name = L"button_add";
			this->button_add->Size = System::Drawing::Size(237, 54);
			this->button_add->TabIndex = 21;
			this->button_add->Text = L"Занести у відомість";
			this->button_add->UseVisualStyleBackColor = false;
			this->button_add->Click += gcnew System::EventHandler(this, &PointerForm::button_add_Click);
			// 
			// button_save2
			// 
			this->button_save2->BackColor = System::Drawing::Color::LightSteelBlue;
			this->button_save2->FlatAppearance->BorderColor = System::Drawing::Color::Navy;
			this->button_save2->FlatAppearance->BorderSize = 3;
			this->button_save2->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button_save2->ForeColor = System::Drawing::SystemColors::ControlText;
			this->button_save2->Location = System::Drawing::Point(585, 487);
			this->button_save2->Name = L"button_save2";
			this->button_save2->Size = System::Drawing::Size(94, 41);
			this->button_save2->TabIndex = 20;
			this->button_save2->Text = L"Зберегти";
			this->button_save2->UseVisualStyleBackColor = false;
			this->button_save2->Click += gcnew System::EventHandler(this, &PointerForm::button_save2_Click);
			// 
			// textBox_input_grade
			// 
			this->textBox_input_grade->Location = System::Drawing::Point(414, 496);
			this->textBox_input_grade->Name = L"textBox_input_grade";
			this->textBox_input_grade->Size = System::Drawing::Size(132, 22);
			this->textBox_input_grade->TabIndex = 19;
			// 
			// button_save
			// 
			this->button_save->BackColor = System::Drawing::Color::LightSteelBlue;
			this->button_save->FlatAppearance->BorderColor = System::Drawing::Color::Navy;
			this->button_save->FlatAppearance->BorderSize = 3;
			this->button_save->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button_save->ForeColor = System::Drawing::SystemColors::ControlText;
			this->button_save->Location = System::Drawing::Point(253, 487);
			this->button_save->Name = L"button_save";
			this->button_save->Size = System::Drawing::Size(94, 41);
			this->button_save->TabIndex = 18;
			this->button_save->Text = L"Зберегти";
			this->button_save->UseVisualStyleBackColor = false;
			this->button_save->Click += gcnew System::EventHandler(this, &PointerForm::button_save_Click);
			// 
			// textBox_input
			// 
			this->textBox_input->Location = System::Drawing::Point(32, 496);
			this->textBox_input->Name = L"textBox_input";
			this->textBox_input->Size = System::Drawing::Size(200, 22);
			this->textBox_input->TabIndex = 17;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->BackColor = System::Drawing::SystemColors::GradientActiveCaption;
			this->label2->Location = System::Drawing::Point(488, 58);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(85, 16);
			this->label2->TabIndex = 16;
			this->label2->Text = L"Оцінювання";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::SystemColors::GradientActiveCaption;
			this->label1->Location = System::Drawing::Point(100, 58);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(158, 16);
			this->label1->TabIndex = 15;
			this->label1->Text = L"Стопка робіт студентів";
			// 
			// listBox2
			// 
			this->listBox2->FormattingEnabled = true;
			this->listBox2->ItemHeight = 16;
			this->listBox2->Location = System::Drawing::Point(379, 77);
			this->listBox2->Name = L"listBox2";
			this->listBox2->Size = System::Drawing::Size(329, 388);
			this->listBox2->TabIndex = 14;
			// 
			// listBox1
			// 
			this->listBox1->FormattingEnabled = true;
			this->listBox1->ItemHeight = 16;
			this->listBox1->Location = System::Drawing::Point(23, 77);
			this->listBox1->Name = L"listBox1";
			this->listBox1->Size = System::Drawing::Size(329, 388);
			this->listBox1->TabIndex = 13;
			// 
			// PointerForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::GradientInactiveCaption;
			this->ClientSize = System::Drawing::Size(1082, 636);
			this->Controls->Add(this->button_delete_grade);
			this->Controls->Add(this->button_delete);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->listBox3);
			this->Controls->Add(this->button_add);
			this->Controls->Add(this->button_save2);
			this->Controls->Add(this->textBox_input_grade);
			this->Controls->Add(this->button_save);
			this->Controls->Add(this->textBox_input);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->listBox2);
			this->Controls->Add(this->listBox1);
			this->Name = L"PointerForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"PointerForm";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &PointerForm::PointerForm_FormClosing);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button_save_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void button_save2_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void button_delete_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void button_delete_grade_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void button_add_Click(System::Object^ sender, System::EventArgs^ e);
	   System::Void PointerForm_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e);
};
}
