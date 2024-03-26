#pragma once

#include "SecondForm.h" // Підключення файлу заголовка для другої форми
#include "Algorithms.h"

#include <string>
#include <limits>
#include <vector>

namespace Laboratorka2 {

	// Кількість вершин у графі
	const int V = 11;

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class Main : public System::Windows::Forms::Form
	{
	public:
		Main(void)
		{
			InitializeComponent();
		}

	protected:
		~Main()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::Button^ btnSelectStartPoint;
	private: System::Windows::Forms::GroupBox^ groupBoxAlgorithm;
	private: System::Windows::Forms::RadioButton^ radioButtonTarjan;

	private: System::Windows::Forms::RadioButton^ radioButtonKosaraju;

	private: System::Windows::Forms::Label^ labelRoute;
	private: System::Windows::Forms::RadioButton^ radioButtonRedUniversity;
	private: System::Windows::Forms::RadioButton^ radioButtonAndriivskaChurch;
	private: System::Windows::Forms::RadioButton^ radioButtonGoldenGate;
	private: System::Windows::Forms::RadioButton^ radioButtonStMichaelsCathedral;
	private: System::Windows::Forms::RadioButton^ radioButtonFountainOnKhreshchatyk;
	private: System::Windows::Forms::RadioButton^ radioButtonKPI;
	private: System::Windows::Forms::RadioButton^ radioButtonFunicular;
	private: System::Windows::Forms::RadioButton^ radioButtonLyadskiGate;

	private: System::Windows::Forms::RadioButton^ radioButtonOneStreetMuseum;
	private: System::Windows::Forms::RadioButton^ radioButtonNationalPhilharmonic;
	private: System::Windows::Forms::RadioButton^ radioButtonStSophiaCathedral;

	private: System::Windows::Forms::GroupBox^ GroupBoxStart;
	private: System::Windows::Forms::Label^ label11;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Label^ label10;
	private: System::Windows::Forms::Label^ label9;
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label1;








	private:
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->btnSelectStartPoint = (gcnew System::Windows::Forms::Button());
			this->groupBoxAlgorithm = (gcnew System::Windows::Forms::GroupBox());
			this->radioButtonTarjan = (gcnew System::Windows::Forms::RadioButton());
			this->radioButtonKosaraju = (gcnew System::Windows::Forms::RadioButton());
			this->labelRoute = (gcnew System::Windows::Forms::Label());
			this->radioButtonRedUniversity = (gcnew System::Windows::Forms::RadioButton());
			this->radioButtonAndriivskaChurch = (gcnew System::Windows::Forms::RadioButton());
			this->radioButtonGoldenGate = (gcnew System::Windows::Forms::RadioButton());
			this->radioButtonStMichaelsCathedral = (gcnew System::Windows::Forms::RadioButton());
			this->radioButtonFountainOnKhreshchatyk = (gcnew System::Windows::Forms::RadioButton());
			this->radioButtonKPI = (gcnew System::Windows::Forms::RadioButton());
			this->radioButtonFunicular = (gcnew System::Windows::Forms::RadioButton());
			this->radioButtonLyadskiGate = (gcnew System::Windows::Forms::RadioButton());
			this->radioButtonOneStreetMuseum = (gcnew System::Windows::Forms::RadioButton());
			this->radioButtonNationalPhilharmonic = (gcnew System::Windows::Forms::RadioButton());
			this->radioButtonStSophiaCathedral = (gcnew System::Windows::Forms::RadioButton());
			this->GroupBoxStart = (gcnew System::Windows::Forms::GroupBox());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->groupBoxAlgorithm->SuspendLayout();
			this->GroupBoxStart->SuspendLayout();
			this->SuspendLayout();
			// 
			// btnSelectStartPoint
			// 
			this->btnSelectStartPoint->BackColor = System::Drawing::Color::CornflowerBlue;
			this->btnSelectStartPoint->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->btnSelectStartPoint->Font = (gcnew System::Drawing::Font(L"Imprint MT Shadow", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnSelectStartPoint->ForeColor = System::Drawing::Color::Black;
			this->btnSelectStartPoint->Location = System::Drawing::Point(398, 285);
			this->btnSelectStartPoint->Name = L"btnSelectStartPoint";
			this->btnSelectStartPoint->Size = System::Drawing::Size(226, 83);
			this->btnSelectStartPoint->TabIndex = 0;
			this->btnSelectStartPoint->Text = L"Результат вибраного алгоритму";
			this->btnSelectStartPoint->UseVisualStyleBackColor = false;
			this->btnSelectStartPoint->Click += gcnew System::EventHandler(this, &Main::btnSelectStartPoint_Click);
			// 
			// groupBoxAlgorithm
			// 
			this->groupBoxAlgorithm->Controls->Add(this->radioButtonTarjan);
			this->groupBoxAlgorithm->Controls->Add(this->radioButtonKosaraju);
			this->groupBoxAlgorithm->Font = (gcnew System::Drawing::Font(L"Imprint MT Shadow", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->groupBoxAlgorithm->ForeColor = System::Drawing::SystemColors::Control;
			this->groupBoxAlgorithm->Location = System::Drawing::Point(33, 536);
			this->groupBoxAlgorithm->Name = L"groupBoxAlgorithm";
			this->groupBoxAlgorithm->Size = System::Drawing::Size(326, 100);
			this->groupBoxAlgorithm->TabIndex = 1;
			this->groupBoxAlgorithm->TabStop = false;
			this->groupBoxAlgorithm->Text = L"Вибір алгоитму";
			// 
			// radioButtonTarjan
			// 
			this->radioButtonTarjan->AutoSize = true;
			this->radioButtonTarjan->Location = System::Drawing::Point(21, 54);
			this->radioButtonTarjan->Name = L"radioButtonTarjan";
			this->radioButtonTarjan->Size = System::Drawing::Size(100, 24);
			this->radioButtonTarjan->TabIndex = 1;
			this->radioButtonTarjan->TabStop = true;
			this->radioButtonTarjan->Text = L"Тарйана";
			this->radioButtonTarjan->UseVisualStyleBackColor = true;
			// 
			// radioButtonKosaraju
			// 
			this->radioButtonKosaraju->AutoSize = true;
			this->radioButtonKosaraju->Location = System::Drawing::Point(21, 27);
			this->radioButtonKosaraju->Name = L"radioButtonKosaraju";
			this->radioButtonKosaraju->Size = System::Drawing::Size(122, 24);
			this->radioButtonKosaraju->TabIndex = 0;
			this->radioButtonKosaraju->TabStop = true;
			this->radioButtonKosaraju->Text = L"Косараджу";
			this->radioButtonKosaraju->UseVisualStyleBackColor = true;
			// 
			// labelRoute
			// 
			this->labelRoute->AutoSize = true;
			this->labelRoute->Enabled = false;
			this->labelRoute->Location = System::Drawing::Point(58, 172);
			this->labelRoute->Name = L"labelRoute";
			this->labelRoute->Size = System::Drawing::Size(0, 20);
			this->labelRoute->TabIndex = 2;
			this->labelRoute->Visible = false;
			// 
			// radioButtonRedUniversity
			// 
			this->radioButtonRedUniversity->Enabled = false;
			this->radioButtonRedUniversity->Location = System::Drawing::Point(21, 31);
			this->radioButtonRedUniversity->Name = L"radioButtonRedUniversity";
			this->radioButtonRedUniversity->Size = System::Drawing::Size(10, 10);
			this->radioButtonRedUniversity->TabIndex = 3;
			this->radioButtonRedUniversity->Text = L"Червоний унівеситет";
			this->radioButtonRedUniversity->UseVisualStyleBackColor = true;
			this->radioButtonRedUniversity->Visible = false;
			// 
			// radioButtonAndriivskaChurch
			// 
			this->radioButtonAndriivskaChurch->Enabled = false;
			this->radioButtonAndriivskaChurch->Location = System::Drawing::Point(21, 70);
			this->radioButtonAndriivskaChurch->Name = L"radioButtonAndriivskaChurch";
			this->radioButtonAndriivskaChurch->Size = System::Drawing::Size(10, 10);
			this->radioButtonAndriivskaChurch->TabIndex = 4;
			this->radioButtonAndriivskaChurch->Text = L"Андріївська церква";
			this->radioButtonAndriivskaChurch->UseVisualStyleBackColor = true;
			this->radioButtonAndriivskaChurch->Visible = false;
			// 
			// radioButtonGoldenGate
			// 
			this->radioButtonGoldenGate->Enabled = false;
			this->radioButtonGoldenGate->Location = System::Drawing::Point(21, 146);
			this->radioButtonGoldenGate->Name = L"radioButtonGoldenGate";
			this->radioButtonGoldenGate->Size = System::Drawing::Size(10, 10);
			this->radioButtonGoldenGate->TabIndex = 6;
			this->radioButtonGoldenGate->Text = L"Золоті ворота";
			this->radioButtonGoldenGate->UseVisualStyleBackColor = true;
			this->radioButtonGoldenGate->Visible = false;
			// 
			// radioButtonStMichaelsCathedral
			// 
			this->radioButtonStMichaelsCathedral->Enabled = false;
			this->radioButtonStMichaelsCathedral->Location = System::Drawing::Point(21, 106);
			this->radioButtonStMichaelsCathedral->Name = L"radioButtonStMichaelsCathedral";
			this->radioButtonStMichaelsCathedral->Size = System::Drawing::Size(10, 10);
			this->radioButtonStMichaelsCathedral->TabIndex = 5;
			this->radioButtonStMichaelsCathedral->Text = L"Михайлівський собор";
			this->radioButtonStMichaelsCathedral->UseVisualStyleBackColor = true;
			this->radioButtonStMichaelsCathedral->Visible = false;
			// 
			// radioButtonFountainOnKhreshchatyk
			// 
			this->radioButtonFountainOnKhreshchatyk->Enabled = false;
			this->radioButtonFountainOnKhreshchatyk->Location = System::Drawing::Point(21, 301);
			this->radioButtonFountainOnKhreshchatyk->Name = L"radioButtonFountainOnKhreshchatyk";
			this->radioButtonFountainOnKhreshchatyk->Size = System::Drawing::Size(10, 10);
			this->radioButtonFountainOnKhreshchatyk->TabIndex = 11;
			this->radioButtonFountainOnKhreshchatyk->Text = L"Фонтан на Хрещатику";
			this->radioButtonFountainOnKhreshchatyk->UseVisualStyleBackColor = true;
			this->radioButtonFountainOnKhreshchatyk->Visible = false;
			// 
			// radioButtonKPI
			// 
			this->radioButtonKPI->Enabled = false;
			this->radioButtonKPI->Location = System::Drawing::Point(21, 260);
			this->radioButtonKPI->Name = L"radioButtonKPI";
			this->radioButtonKPI->Size = System::Drawing::Size(10, 10);
			this->radioButtonKPI->TabIndex = 10;
			this->radioButtonKPI->Text = L"КПІ";
			this->radioButtonKPI->UseVisualStyleBackColor = true;
			this->radioButtonKPI->Visible = false;
			// 
			// radioButtonFunicular
			// 
			this->radioButtonFunicular->Enabled = false;
			this->radioButtonFunicular->Location = System::Drawing::Point(21, 220);
			this->radioButtonFunicular->Name = L"radioButtonFunicular";
			this->radioButtonFunicular->Size = System::Drawing::Size(10, 10);
			this->radioButtonFunicular->TabIndex = 9;
			this->radioButtonFunicular->Text = L"Фунікулер";
			this->radioButtonFunicular->UseVisualStyleBackColor = true;
			this->radioButtonFunicular->Visible = false;
			// 
			// radioButtonLyadskiGate
			// 
			this->radioButtonLyadskiGate->Enabled = false;
			this->radioButtonLyadskiGate->Location = System::Drawing::Point(21, 182);
			this->radioButtonLyadskiGate->Name = L"radioButtonLyadskiGate";
			this->radioButtonLyadskiGate->Size = System::Drawing::Size(10, 10);
			this->radioButtonLyadskiGate->TabIndex = 8;
			this->radioButtonLyadskiGate->Text = L"Лядські ворота";
			this->radioButtonLyadskiGate->UseVisualStyleBackColor = true;
			this->radioButtonLyadskiGate->Visible = false;
			// 
			// radioButtonOneStreetMuseum
			// 
			this->radioButtonOneStreetMuseum->Enabled = false;
			this->radioButtonOneStreetMuseum->Location = System::Drawing::Point(21, 427);
			this->radioButtonOneStreetMuseum->Name = L"radioButtonOneStreetMuseum";
			this->radioButtonOneStreetMuseum->Size = System::Drawing::Size(10, 10);
			this->radioButtonOneStreetMuseum->TabIndex = 15;
			this->radioButtonOneStreetMuseum->Text = L"Музей однієї вулиці";
			this->radioButtonOneStreetMuseum->UseVisualStyleBackColor = true;
			this->radioButtonOneStreetMuseum->Visible = false;
			// 
			// radioButtonNationalPhilharmonic
			// 
			this->radioButtonNationalPhilharmonic->Enabled = false;
			this->radioButtonNationalPhilharmonic->Location = System::Drawing::Point(21, 388);
			this->radioButtonNationalPhilharmonic->Name = L"radioButtonNationalPhilharmonic";
			this->radioButtonNationalPhilharmonic->Size = System::Drawing::Size(10, 10);
			this->radioButtonNationalPhilharmonic->TabIndex = 14;
			this->radioButtonNationalPhilharmonic->Text = L"Національна філармонія";
			this->radioButtonNationalPhilharmonic->UseVisualStyleBackColor = true;
			this->radioButtonNationalPhilharmonic->Visible = false;
			// 
			// radioButtonStSophiaCathedral
			// 
			this->radioButtonStSophiaCathedral->Enabled = false;
			this->radioButtonStSophiaCathedral->Location = System::Drawing::Point(21, 345);
			this->radioButtonStSophiaCathedral->Name = L"radioButtonStSophiaCathedral";
			this->radioButtonStSophiaCathedral->Size = System::Drawing::Size(10, 10);
			this->radioButtonStSophiaCathedral->TabIndex = 13;
			this->radioButtonStSophiaCathedral->Text = L"Софійський собор";
			this->radioButtonStSophiaCathedral->UseVisualStyleBackColor = true;
			this->radioButtonStSophiaCathedral->Visible = false;
			// 
			// GroupBoxStart
			// 
			this->GroupBoxStart->Controls->Add(this->label11);
			this->GroupBoxStart->Controls->Add(this->label7);
			this->GroupBoxStart->Controls->Add(this->label10);
			this->GroupBoxStart->Controls->Add(this->label9);
			this->GroupBoxStart->Controls->Add(this->label8);
			this->GroupBoxStart->Controls->Add(this->label6);
			this->GroupBoxStart->Controls->Add(this->label5);
			this->GroupBoxStart->Controls->Add(this->label4);
			this->GroupBoxStart->Controls->Add(this->label3);
			this->GroupBoxStart->Controls->Add(this->label2);
			this->GroupBoxStart->Controls->Add(this->label1);
			this->GroupBoxStart->Controls->Add(this->radioButtonOneStreetMuseum);
			this->GroupBoxStart->Controls->Add(this->radioButtonStSophiaCathedral);
			this->GroupBoxStart->Controls->Add(this->radioButtonFountainOnKhreshchatyk);
			this->GroupBoxStart->Controls->Add(this->labelRoute);
			this->GroupBoxStart->Controls->Add(this->radioButtonGoldenGate);
			this->GroupBoxStart->Controls->Add(this->radioButtonLyadskiGate);
			this->GroupBoxStart->Controls->Add(this->radioButtonRedUniversity);
			this->GroupBoxStart->Controls->Add(this->radioButtonStMichaelsCathedral);
			this->GroupBoxStart->Controls->Add(this->radioButtonNationalPhilharmonic);
			this->GroupBoxStart->Controls->Add(this->radioButtonKPI);
			this->GroupBoxStart->Controls->Add(this->radioButtonFunicular);
			this->GroupBoxStart->Controls->Add(this->radioButtonAndriivskaChurch);
			this->GroupBoxStart->Font = (gcnew System::Drawing::Font(L"Imprint MT Shadow", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->GroupBoxStart->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->GroupBoxStart->Location = System::Drawing::Point(33, 39);
			this->GroupBoxStart->Name = L"GroupBoxStart";
			this->GroupBoxStart->Size = System::Drawing::Size(326, 459);
			this->GroupBoxStart->TabIndex = 17;
			this->GroupBoxStart->TabStop = false;
			this->GroupBoxStart->Text = L"Місця Києва";
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Location = System::Drawing::Point(17, 419);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(189, 20);
			this->label11->TabIndex = 40;
			this->label11->Text = L"11.Музей однієї вулиці";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(17, 260);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(50, 20);
			this->label7->TabIndex = 38;
			this->label7->Text = L"7.КПІ";
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Location = System::Drawing::Point(17, 379);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(236, 20);
			this->label10->TabIndex = 39;
			this->label10->Text = L"10.Національна філармонія";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(17, 338);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(175, 20);
			this->label9->TabIndex = 37;
			this->label9->Text = L"9.Софійський собор";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(17, 297);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(209, 20);
			this->label8->TabIndex = 36;
			this->label8->Text = L"8.Фонтан на Хрещатику";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(17, 220);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(107, 20);
			this->label6->TabIndex = 35;
			this->label6->Text = L"6.Фунікулер";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(17, 181);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(152, 20);
			this->label5->TabIndex = 34;
			this->label5->Text = L"5.Лядські ворота";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(17, 143);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(142, 20);
			this->label4->TabIndex = 33;
			this->label4->Text = L"4.Золоті ворота";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(17, 104);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(199, 20);
			this->label3->TabIndex = 32;
			this->label3->Text = L"3.Михайлівський собор";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(17, 64);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(187, 20);
			this->label2->TabIndex = 31;
			this->label2->Text = L"2.Андріївська церква";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(17, 24);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(198, 20);
			this->label1->TabIndex = 30;
			this->label1->Text = L"1.Червоний унівеситет";
			// 
			// Main
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::MidnightBlue;
			this->ClientSize = System::Drawing::Size(665, 673);
			this->Controls->Add(this->GroupBoxStart);
			this->Controls->Add(this->groupBoxAlgorithm);
			this->Controls->Add(this->btnSelectStartPoint);
			this->Location = System::Drawing::Point(100, 100);
			this->Name = L"Main";
			this->StartPosition = System::Windows::Forms::FormStartPosition::Manual;
			this->Text = L"MainForm";
			this->groupBoxAlgorithm->ResumeLayout(false);
			this->groupBoxAlgorithm->PerformLayout();
			this->GroupBoxStart->ResumeLayout(false);
			this->GroupBoxStart->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void secondForm_FormClosed(System::Object^ sender, System::Windows::Forms::FormClosedEventArgs^ e)
	{

	}
	private: System::Void btnSelectStartPoint_Click(System::Object^ sender, System::EventArgs^ e)
	{
		// Отримання вибраного початкового пункту та алгоритму
		String^ startPoint;
		String^ algorithm;
		String^ sccKosarajuResult;
		String^ sccTarjanResult;
		if (radioButtonKosaraju->Checked) {
			algorithm = "Kosaraju";
		}
		else if (radioButtonTarjan->Checked) {
			algorithm = "Tarjan";
		}

		// Виконання алгоритму та виведення результатів
		if (algorithm != nullptr) {




			double graph[rozmir][rozmir] = { // Сама матриця магічних циферок
	   {0, 2, 1.7, 0.9, 0, 2.5, 5, 1, 0, 2.5, 0},
	   {0, 0, 0.6, 1.3, 0, 0, 0, 2, 0.95, 0, 0.6},
	   {1.7, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0},
	   {0.9, 1.3, 0, 0, 0, 0, 0, 1, 0.55, 0, 0},
	   {0, 0, 0.5, 0, 0, 0, 0, 1.1, 0, 0, 0},
	   {0, 0, 0, 0, 0, 0, 0, 0, 0, 0.75, 0},
	   {5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	   {1, 2, 0, 0, 1.1, 0, 0, 0, 0, 0, 0},
	   {1.3, 0.95, 0, 0.55, 0.75, 0, 0, 0, 0, 0, 0},
	   {2.5, 0, 0, 0, 0, 0.75, 0, 0, 0, 0, 0},
	   {0, 0.6, 0, 0, 0, 0.8, 0, 0, 0, 0, 0} };



			Graph g(rozmir);
			g.addTable(graph);

			ShortestPathResult result;
			// Виклик відповідного алгоритму в залежності від вибору
			if (algorithm == "Kosaraju") {
				sccKosarajuResult = gcnew String(g.SccKosaraju().c_str());
			}
			else if (algorithm == "Tarjan") {
				sccTarjanResult = gcnew String(g.SccTarjan().c_str());
			}

			// Відображення результатів на формі
			String^ routeText = "";
			if (algorithm == "Kosaraju") {
				labelRoute->Text = sccKosarajuResult;
			}
			else if (algorithm == "Tarjan") {
				labelRoute->Text = sccTarjanResult;
			}
			int execution_time = g.GetTime();
			// Перехід на наступну форму
			 // Отримання часу виконання з графа
			System::ComponentModel::IContainer^ container = gcnew System::ComponentModel::Container();
			SecondForm^ secondForm = gcnew SecondForm(container);
			secondForm->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &Main::secondForm_FormClosed);
			if (algorithm == "Kosaraju") {
				secondForm->SetRouteText(sccKosarajuResult, algorithm, execution_time);
			}
			else if (algorithm == "Tarjan") {
				secondForm->SetRouteText(sccTarjanResult, algorithm, execution_time);
			}
			secondForm->Show();
			// Сховати поточну форму
		}
	}
	};



}

