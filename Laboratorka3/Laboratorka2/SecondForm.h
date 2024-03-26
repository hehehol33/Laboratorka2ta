#pragma once

#include <vector>
#include <string>
#include <iostream>
#include "Algorithms.h"

namespace Laboratorka2 {

    public ref class SecondForm : public System::Windows::Forms::Form
    {

    private:


    public:
        SecondForm(System::ComponentModel::IContainer^ container)
        {
            InitializeComponent();
        }

        void SetRouteText(System::String^ routeText, System::String^ algorithm, int execution_time)
        {


            if (algorithm == "Kosaraju")
            {
                labelRoute->Text = "Strongly Connected Components using Kosaraju's Algorithm: \n" + routeText;
            }
            else if (algorithm == "Tarjan")
            {
                labelRoute->Text = "Strongly Connected Components using Tarjan's Algorithm: \n" + routeText;
            }

            labelTime->Text = "Execution Time: " + execution_time.ToString() + " microseconds";
        }







    protected:
        ~SecondForm()
        {
            if (components)
            {
                delete components;
            }
        }

    private: System::Windows::Forms::PictureBox^ pictureBox1;
    private: System::Windows::Forms::Button^ button_back;
    private: System::Windows::Forms::Label^ labelTime;










    protected:

    private:
        System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
        void InitializeComponent(void)
        {
            System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(SecondForm::typeid));
            this->labelRoute = (gcnew System::Windows::Forms::Label());
            this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
            this->button_back = (gcnew System::Windows::Forms::Button());
            this->labelTime = (gcnew System::Windows::Forms::Label());
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
            this->SuspendLayout();
            // 
            // labelRoute
            // 
            this->labelRoute->Font = (gcnew System::Drawing::Font(L"Times New Roman", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->labelRoute->ForeColor = System::Drawing::Color::Navy;
            this->labelRoute->Location = System::Drawing::Point(15, 16);
            this->labelRoute->Margin = System::Windows::Forms::Padding(6, 0, 6, 0);
            this->labelRoute->Name = L"labelRoute";
            this->labelRoute->Size = System::Drawing::Size(643, 205);
            this->labelRoute->TabIndex = 0;
            this->labelRoute->Text = L"-";
            // 
            // pictureBox1
            // 
            this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
            this->pictureBox1->Location = System::Drawing::Point(0, 130);
            this->pictureBox1->Name = L"pictureBox1";
            this->pictureBox1->Size = System::Drawing::Size(672, 360);
            this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
            this->pictureBox1->TabIndex = 2;
            this->pictureBox1->TabStop = false;
            // 
            // button_back
            // 
            this->button_back->BackColor = System::Drawing::Color::LightCyan;
            this->button_back->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->button_back->ForeColor = System::Drawing::Color::MidnightBlue;
            this->button_back->Location = System::Drawing::Point(547, 509);
            this->button_back->Name = L"button_back";
            this->button_back->Size = System::Drawing::Size(115, 46);
            this->button_back->TabIndex = 3;
            this->button_back->Text = L"Назад";
            this->button_back->UseVisualStyleBackColor = false;
            this->button_back->Click += gcnew System::EventHandler(this, &SecondForm::button_back_Click);
            // 
            // labelTime
            // 
            this->labelTime->ForeColor = System::Drawing::Color::Navy;
            this->labelTime->Location = System::Drawing::Point(12, 65);
            this->labelTime->Name = L"labelTime";
            this->labelTime->Size = System::Drawing::Size(621, 43);
            this->labelTime->TabIndex = 4;
            this->labelTime->Text = L"-";
            // 
            // SecondForm
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(10, 21);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->BackColor = System::Drawing::Color::LightBlue;
            this->ClientSize = System::Drawing::Size(672, 565);
            this->Controls->Add(this->labelTime);
            this->Controls->Add(this->button_back);
            this->Controls->Add(this->pictureBox1);
            this->Controls->Add(this->labelRoute);
            this->Font = (gcnew System::Drawing::Font(L"Arial", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->Location = System::Drawing::Point(604, 95);
            this->Margin = System::Windows::Forms::Padding(6);
            this->Name = L"SecondForm";
            this->StartPosition = System::Windows::Forms::FormStartPosition::Manual;
            this->Text = L"Result";
            this->Click += gcnew System::EventHandler(this, &SecondForm::button_back_Click);
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
            this->ResumeLayout(false);

        }
#pragma endregion

    private:
        System::Windows::Forms::Label^ labelRoute;



    private: System::Void button_back_Click(System::Object^ sender, System::EventArgs^ e) {
        this->Close();
    }
    };
}
