#pragma once

namespace Laboratorka4 {

    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;

    public ref class ArrayForm : public System::Windows::Forms::Form
    {
    public:
        ArrayForm(void)
        {
            InitializeComponent();
            //
            //TODO: Додайте код конструктора тут
            //
        }

    private:
        // Оголошення змінних на рівні класу
        System::String^ text_person;
    private: System::Windows::Forms::ListBox^ listBox3;
    private: System::Windows::Forms::Label^ label3;
    private: System::Windows::Forms::Button^ button_delete;
    private: System::Windows::Forms::Button^ button_delete_grade;

           System::String^ text_grade;

    protected:
        /// <summary>
        /// Відчистити всі використані ресурси.
        /// </summary>
        ~ArrayForm()
        {
            if (components)
            {
                delete components;
            }
        }

    private: System::Windows::Forms::ListBox^ listBox1;
    protected:

    private: System::Windows::Forms::ListBox^ listBox2;
    private: System::Windows::Forms::Label^ label1;
    private: System::Windows::Forms::Label^ label2;
    private: System::Windows::Forms::TextBox^ textBox_input;

    private: System::Windows::Forms::Button^ button_save;
    private: System::Windows::Forms::TextBox^ textBox_input_grade;

    private: System::Windows::Forms::Button^ button_save2;
    private: System::Windows::Forms::Button^ button_add;


    private:
        /// <summary>
        /// Важлива змінна для дизайнера форм.
        /// </summary>
        System::ComponentModel::Container^ components;

#pragma region Візуальний дизайнер форми

        /// <summary>
        /// Обов'язковий метод для підтримки конструктора - не змінювати
        /// зміст цього методу з допомогою редактора коду.
        /// </summary>
        void InitializeComponent(void)
        {
            this->listBox1 = (gcnew System::Windows::Forms::ListBox());
            this->listBox2 = (gcnew System::Windows::Forms::ListBox());
            this->label1 = (gcnew System::Windows::Forms::Label());
            this->label2 = (gcnew System::Windows::Forms::Label());
            this->textBox_input = (gcnew System::Windows::Forms::TextBox());
            this->button_save = (gcnew System::Windows::Forms::Button());
            this->textBox_input_grade = (gcnew System::Windows::Forms::TextBox());
            this->button_save2 = (gcnew System::Windows::Forms::Button());
            this->button_add = (gcnew System::Windows::Forms::Button());
            this->listBox3 = (gcnew System::Windows::Forms::ListBox());
            this->label3 = (gcnew System::Windows::Forms::Label());
            this->button_delete = (gcnew System::Windows::Forms::Button());
            this->button_delete_grade = (gcnew System::Windows::Forms::Button());
            this->SuspendLayout();
            // 
            // listBox1
            // 
            this->listBox1->FormattingEnabled = true;
            this->listBox1->ItemHeight = 16;
            this->listBox1->Location = System::Drawing::Point(19, 58);
            this->listBox1->Name = L"listBox1";
            this->listBox1->Size = System::Drawing::Size(329, 388);
            this->listBox1->TabIndex = 0;
            // 
            // listBox2
            // 
            this->listBox2->FormattingEnabled = true;
            this->listBox2->ItemHeight = 16;
            this->listBox2->Location = System::Drawing::Point(375, 58);
            this->listBox2->Name = L"listBox2";
            this->listBox2->Size = System::Drawing::Size(329, 388);
            this->listBox2->TabIndex = 1;
            // 
            // label1
            // 
            this->label1->AutoSize = true;
            this->label1->BackColor = System::Drawing::SystemColors::GradientActiveCaption;
            this->label1->Location = System::Drawing::Point(96, 39);
            this->label1->Name = L"label1";
            this->label1->Size = System::Drawing::Size(158, 16);
            this->label1->TabIndex = 2;
            this->label1->Text = L"Стопка робіт студентів";
            // 
            // label2
            // 
            this->label2->AutoSize = true;
            this->label2->BackColor = System::Drawing::SystemColors::GradientActiveCaption;
            this->label2->Location = System::Drawing::Point(484, 39);
            this->label2->Name = L"label2";
            this->label2->Size = System::Drawing::Size(85, 16);
            this->label2->TabIndex = 3;
            this->label2->Text = L"Оцінювання";
            // 
            // textBox_input
            // 
            this->textBox_input->Location = System::Drawing::Point(28, 477);
            this->textBox_input->Name = L"textBox_input";
            this->textBox_input->Size = System::Drawing::Size(200, 22);
            this->textBox_input->TabIndex = 4;
            // 
            // button_save
            // 
            this->button_save->BackColor = System::Drawing::Color::LightSteelBlue;
            this->button_save->FlatAppearance->BorderColor = System::Drawing::Color::Navy;
            this->button_save->FlatAppearance->BorderSize = 3;
            this->button_save->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->button_save->ForeColor = System::Drawing::SystemColors::ControlText;
            this->button_save->Location = System::Drawing::Point(249, 468);
            this->button_save->Name = L"button_save";
            this->button_save->Size = System::Drawing::Size(94, 41);
            this->button_save->TabIndex = 5;
            this->button_save->Text = L"Зберегти";
            this->button_save->UseVisualStyleBackColor = false;
            this->button_save->Click += gcnew System::EventHandler(this, &ArrayForm::button_save_Click);
            // 
            // textBox_input_grade
            // 
            this->textBox_input_grade->Location = System::Drawing::Point(410, 477);
            this->textBox_input_grade->Name = L"textBox_input_grade";
            this->textBox_input_grade->Size = System::Drawing::Size(132, 22);
            this->textBox_input_grade->TabIndex = 6;
            // 
            // button_save2
            // 
            this->button_save2->BackColor = System::Drawing::Color::LightSteelBlue;
            this->button_save2->FlatAppearance->BorderColor = System::Drawing::Color::Navy;
            this->button_save2->FlatAppearance->BorderSize = 3;
            this->button_save2->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->button_save2->ForeColor = System::Drawing::SystemColors::ControlText;
            this->button_save2->Location = System::Drawing::Point(581, 468);
            this->button_save2->Name = L"button_save2";
            this->button_save2->Size = System::Drawing::Size(94, 41);
            this->button_save2->TabIndex = 7;
            this->button_save2->Text = L"Зберегти";
            this->button_save2->UseVisualStyleBackColor = false;
            this->button_save2->Click += gcnew System::EventHandler(this, &ArrayForm::button_save2_Click);
            // 
            // button_add
            // 
            this->button_add->BackColor = System::Drawing::Color::DarkSeaGreen;
            this->button_add->Location = System::Drawing::Point(779, 479);
            this->button_add->Name = L"button_add";
            this->button_add->Size = System::Drawing::Size(237, 54);
            this->button_add->TabIndex = 8;
            this->button_add->Text = L"Занести у відомість";
            this->button_add->UseVisualStyleBackColor = false;
            this->button_add->Click += gcnew System::EventHandler(this, &ArrayForm::button_add_Click);
            // 
            // listBox3
            // 
            this->listBox3->FormattingEnabled = true;
            this->listBox3->ItemHeight = 16;
            this->listBox3->Location = System::Drawing::Point(727, 58);
            this->listBox3->Name = L"listBox3";
            this->listBox3->Size = System::Drawing::Size(329, 388);
            this->listBox3->TabIndex = 9;
            // 
            // label3
            // 
            this->label3->AutoSize = true;
            this->label3->BackColor = System::Drawing::SystemColors::GradientActiveCaption;
            this->label3->Location = System::Drawing::Point(864, 39);
            this->label3->Name = L"label3";
            this->label3->Size = System::Drawing::Size(55, 16);
            this->label3->TabIndex = 10;
            this->label3->Text = L"Кампус";
            // 
            // button_delete
            // 
            this->button_delete->BackColor = System::Drawing::Color::MistyRose;
            this->button_delete->FlatAppearance->BorderColor = System::Drawing::Color::Red;
            this->button_delete->FlatAppearance->BorderSize = 2;
            this->button_delete->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->button_delete->Location = System::Drawing::Point(59, 529);
            this->button_delete->Name = L"button_delete";
            this->button_delete->Size = System::Drawing::Size(253, 30);
            this->button_delete->TabIndex = 11;
            this->button_delete->Text = L"Прибрати елемент зі стопки";
            this->button_delete->UseVisualStyleBackColor = false;
            this->button_delete->Click += gcnew System::EventHandler(this, &ArrayForm::button_delete_Click);
            // 
            // button_delete_grade
            // 
            this->button_delete_grade->BackColor = System::Drawing::Color::MistyRose;
            this->button_delete_grade->FlatAppearance->BorderColor = System::Drawing::Color::Red;
            this->button_delete_grade->FlatAppearance->BorderSize = 2;
            this->button_delete_grade->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->button_delete_grade->Location = System::Drawing::Point(477, 529);
            this->button_delete_grade->Name = L"button_delete_grade";
            this->button_delete_grade->Size = System::Drawing::Size(142, 30);
            this->button_delete_grade->TabIndex = 12;
            this->button_delete_grade->Text = L"Видалити оцінку";
            this->button_delete_grade->UseVisualStyleBackColor = false;
            this->button_delete_grade->Click += gcnew System::EventHandler(this, &ArrayForm::button_delete_grade_Click);
            // 
            // ArrayForm
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
            this->Location = System::Drawing::Point(133, 133);
            this->Name = L"ArrayForm";
            this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
            this->Text = L"ArrayForm";
            this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &ArrayForm::ArrayForm_FormClosing);
            this->ResumeLayout(false);
            this->PerformLayout();

        }
#pragma endregion

    private:
        System::Void button_save_Click(System::Object^ sender, System::EventArgs^ e);
        System::Void button_save2_Click(System::Object^ sender, System::EventArgs^ e);
        System::Void button_add_Click(System::Object^ sender, System::EventArgs^ e);
        System::Void ArrayForm_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e);
    private: System::Void button_delete_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void button_delete_grade_Click(System::Object^ sender, System::EventArgs^ e);
};
}
