#pragma once



#include <string>
#include <limits>
#include <vector>

namespace Laboratorka4 {

	// Кількість вершин у графі
	const int V = 11;

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class MainForm : public System::Windows::Forms::Form
	{
		
	public:
		MainForm(void)
		{
			InitializeComponent();
		}

	protected:
		~MainForm()
		{
			if (components)
			{
				delete components;
			}
		}

	protected:

	private: System::Windows::Forms::Button^ button_arr;
	private: System::Windows::Forms::Button^ button_point;

	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label_time1;
	private: System::Windows::Forms::Label^ label_time2;





























	private:
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->button_arr = (gcnew System::Windows::Forms::Button());
			this->button_point = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label_time1 = (gcnew System::Windows::Forms::Label());
			this->label_time2 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// button_arr
			// 
			this->button_arr->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->button_arr->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button_arr->ForeColor = System::Drawing::SystemColors::ControlText;
			this->button_arr->Location = System::Drawing::Point(281, 267);
			this->button_arr->Name = L"button_arr";
			this->button_arr->Size = System::Drawing::Size(156, 92);
			this->button_arr->TabIndex = 2;
			this->button_arr->Text = L"Масиви";
			this->button_arr->UseVisualStyleBackColor = false;
			this->button_arr->Click += gcnew System::EventHandler(this, &MainForm::button_arr_Click);
			// 
			// button_point
			// 
			this->button_point->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->button_point->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button_point->ForeColor = System::Drawing::SystemColors::ControlText;
			this->button_point->Location = System::Drawing::Point(673, 267);
			this->button_point->Name = L"button_point";
			this->button_point->Size = System::Drawing::Size(157, 92);
			this->button_point->TabIndex = 3;
			this->button_point->Text = L"Показчики";
			this->button_point->UseVisualStyleBackColor = false;
			this->button_point->Click += gcnew System::EventHandler(this, &MainForm::button_point_Click);
			// 
			// label1
			// 
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::SystemColors::ButtonFace;
			this->label1->Location = System::Drawing::Point(145, 24);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(821, 34);
			this->label1->TabIndex = 5;
			this->label1->Text = L"Порівняння реалізацій абстрактних типів даних";
			// 
			// label_time1
			// 
			this->label_time1->AutoSize = true;
			this->label_time1->ForeColor = System::Drawing::SystemColors::ButtonFace;
			this->label_time1->Location = System::Drawing::Point(31, 707);
			this->label_time1->Name = L"label_time1";
			this->label_time1->Size = System::Drawing::Size(11, 16);
			this->label_time1->TabIndex = 6;
			this->label_time1->Text = L"-";
			// 
			// label_time2
			// 
			this->label_time2->AutoSize = true;
			this->label_time2->ForeColor = System::Drawing::SystemColors::ButtonFace;
			this->label_time2->Location = System::Drawing::Point(486, 707);
			this->label_time2->Name = L"label_time2";
			this->label_time2->Size = System::Drawing::Size(11, 16);
			this->label_time2->TabIndex = 7;
			this->label_time2->Text = L"-";
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(102)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(153)));
			this->ClientSize = System::Drawing::Size(1082, 636);
			this->Controls->Add(this->label_time2);
			this->Controls->Add(this->label_time1);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button_point);
			this->Controls->Add(this->button_arr);
			this->Location = System::Drawing::Point(100, 100);
			this->Name = L"MainForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Result";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion



	private: System::Void button_arr_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void button_point_Click(System::Object^ sender, System::EventArgs^ e);
		   //private: System::Void button_clean_Click(System::Object^ sender, System::EventArgs^ e);
		 

	};
}