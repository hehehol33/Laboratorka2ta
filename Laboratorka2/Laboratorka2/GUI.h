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

	private: System::Windows::Forms::Button^ btnSelectStartPoint;
	private: System::Windows::Forms::GroupBox^ groupBoxAlgorithm;
	private: System::Windows::Forms::RadioButton^ radioButtonBellmanFord;
	private: System::Windows::Forms::RadioButton^ radioButtonDijkstra;
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






	private:
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->btnSelectStartPoint = (gcnew System::Windows::Forms::Button());
			this->groupBoxAlgorithm = (gcnew System::Windows::Forms::GroupBox());
			this->radioButtonBellmanFord = (gcnew System::Windows::Forms::RadioButton());
			this->radioButtonDijkstra = (gcnew System::Windows::Forms::RadioButton());
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
			this->groupBoxAlgorithm->SuspendLayout();
			this->GroupBoxStart->SuspendLayout();
			this->SuspendLayout();
			// 
			// btnSelectStartPoint
			// 
			this->btnSelectStartPoint->BackColor = System::Drawing::Color::CornflowerBlue;
			this->btnSelectStartPoint->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->btnSelectStartPoint->Font = (gcnew System::Drawing::Font(L"Imprint MT Shadow", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnSelectStartPoint->ForeColor = System::Drawing::Color::Black;
			this->btnSelectStartPoint->Location = System::Drawing::Point(399, 286);
			this->btnSelectStartPoint->Name = L"btnSelectStartPoint";
			this->btnSelectStartPoint->Size = System::Drawing::Size(226, 83);
			this->btnSelectStartPoint->TabIndex = 0;
			this->btnSelectStartPoint->Text = L"Знайти найкоротший маршрут";
			this->btnSelectStartPoint->UseVisualStyleBackColor = false;
			this->btnSelectStartPoint->Click += gcnew System::EventHandler(this, &MainForm::btnSelectStartPoint_Click);
			// 
			// groupBoxAlgorithm
			// 
			this->groupBoxAlgorithm->Controls->Add(this->radioButtonBellmanFord);
			this->groupBoxAlgorithm->Controls->Add(this->radioButtonDijkstra);
			this->groupBoxAlgorithm->Font = (gcnew System::Drawing::Font(L"Imprint MT Shadow", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->groupBoxAlgorithm->ForeColor = System::Drawing::SystemColors::Control;
			this->groupBoxAlgorithm->Location = System::Drawing::Point(33, 536);
			this->groupBoxAlgorithm->Name = L"groupBoxAlgorithm";
			this->groupBoxAlgorithm->Size = System::Drawing::Size(326, 100);
			this->groupBoxAlgorithm->TabIndex = 1;
			this->groupBoxAlgorithm->TabStop = false;
			this->groupBoxAlgorithm->Text = L"Вибір алгоитму";
			this->groupBoxAlgorithm->Enter += gcnew System::EventHandler(this, &MainForm::groupBoxAlgorithm_Enter);
			// 
			// radioButtonBellmanFord
			// 
			this->radioButtonBellmanFord->AutoSize = true;
			this->radioButtonBellmanFord->Location = System::Drawing::Point(21, 54);
			this->radioButtonBellmanFord->Name = L"radioButtonBellmanFord";
			this->radioButtonBellmanFord->Size = System::Drawing::Size(148, 28);
			this->radioButtonBellmanFord->TabIndex = 1;
			this->radioButtonBellmanFord->TabStop = true;
			this->radioButtonBellmanFord->Text = L"Белмана-Форда";
			this->radioButtonBellmanFord->UseVisualStyleBackColor = true;
			// 
			// radioButtonDijkstra
			// 
			this->radioButtonDijkstra->AutoSize = true;
			this->radioButtonDijkstra->Location = System::Drawing::Point(21, 27);
			this->radioButtonDijkstra->Name = L"radioButtonDijkstra";
			this->radioButtonDijkstra->Size = System::Drawing::Size(98, 28);
			this->radioButtonDijkstra->TabIndex = 0;
			this->radioButtonDijkstra->TabStop = true;
			this->radioButtonDijkstra->Text = L"Дейкстра";
			this->radioButtonDijkstra->UseVisualStyleBackColor = true;
			// 
			// labelRoute
			// 
			this->labelRoute->AutoSize = true;
			this->labelRoute->Location = System::Drawing::Point(43, 173);
			this->labelRoute->Name = L"labelRoute";
			this->labelRoute->Size = System::Drawing::Size(0, 24);
			this->labelRoute->TabIndex = 2;
			// 
			// radioButtonRedUniversity
			// 
			this->radioButtonRedUniversity->AutoSize = true;
			this->radioButtonRedUniversity->Location = System::Drawing::Point(6, 21);
			this->radioButtonRedUniversity->Name = L"radioButtonRedUniversity";
			this->radioButtonRedUniversity->Size = System::Drawing::Size(175, 28);
			this->radioButtonRedUniversity->TabIndex = 3;
			this->radioButtonRedUniversity->TabStop = true;
			this->radioButtonRedUniversity->Text = L"Червоний унівеситет";
			this->radioButtonRedUniversity->UseVisualStyleBackColor = true;
			// 
			// radioButtonAndriivskaChurch
			// 
			this->radioButtonAndriivskaChurch->AutoSize = true;
			this->radioButtonAndriivskaChurch->Location = System::Drawing::Point(6, 60);
			this->radioButtonAndriivskaChurch->Name = L"radioButtonAndriivskaChurch";
			this->radioButtonAndriivskaChurch->Size = System::Drawing::Size(164, 28);
			this->radioButtonAndriivskaChurch->TabIndex = 4;
			this->radioButtonAndriivskaChurch->TabStop = true;
			this->radioButtonAndriivskaChurch->Text = L"Андріївська церква";
			this->radioButtonAndriivskaChurch->UseVisualStyleBackColor = true;
			// 
			// radioButtonGoldenGate
			// 
			this->radioButtonGoldenGate->AutoSize = true;
			this->radioButtonGoldenGate->Location = System::Drawing::Point(6, 136);
			this->radioButtonGoldenGate->Name = L"radioButtonGoldenGate";
			this->radioButtonGoldenGate->Size = System::Drawing::Size(132, 28);
			this->radioButtonGoldenGate->TabIndex = 6;
			this->radioButtonGoldenGate->TabStop = true;
			this->radioButtonGoldenGate->Text = L"Золоті ворота";
			this->radioButtonGoldenGate->UseVisualStyleBackColor = true;
			// 
			// radioButtonStMichaelsCathedral
			// 
			this->radioButtonStMichaelsCathedral->AutoSize = true;
			this->radioButtonStMichaelsCathedral->Location = System::Drawing::Point(6, 96);
			this->radioButtonStMichaelsCathedral->Name = L"radioButtonStMichaelsCathedral";
			this->radioButtonStMichaelsCathedral->Size = System::Drawing::Size(183, 28);
			this->radioButtonStMichaelsCathedral->TabIndex = 5;
			this->radioButtonStMichaelsCathedral->TabStop = true;
			this->radioButtonStMichaelsCathedral->Text = L"Михайлівський собор";
			this->radioButtonStMichaelsCathedral->UseVisualStyleBackColor = true;
			// 
			// radioButtonFountainOnKhreshchatyk
			// 
			this->radioButtonFountainOnKhreshchatyk->AutoSize = true;
			this->radioButtonFountainOnKhreshchatyk->Location = System::Drawing::Point(6, 291);
			this->radioButtonFountainOnKhreshchatyk->Name = L"radioButtonFountainOnKhreshchatyk";
			this->radioButtonFountainOnKhreshchatyk->Size = System::Drawing::Size(185, 28);
			this->radioButtonFountainOnKhreshchatyk->TabIndex = 11;
			this->radioButtonFountainOnKhreshchatyk->TabStop = true;
			this->radioButtonFountainOnKhreshchatyk->Text = L"Фонтан на Хрещатику";
			this->radioButtonFountainOnKhreshchatyk->UseVisualStyleBackColor = true;
			// 
			// radioButtonKPI
			// 
			this->radioButtonKPI->AutoSize = true;
			this->radioButtonKPI->Location = System::Drawing::Point(6, 250);
			this->radioButtonKPI->Name = L"radioButtonKPI";
			this->radioButtonKPI->Size = System::Drawing::Size(55, 28);
			this->radioButtonKPI->TabIndex = 10;
			this->radioButtonKPI->TabStop = true;
			this->radioButtonKPI->Text = L"КПІ";
			this->radioButtonKPI->UseVisualStyleBackColor = true;
			// 
			// radioButtonFunicular
			// 
			this->radioButtonFunicular->AutoSize = true;
			this->radioButtonFunicular->Location = System::Drawing::Point(6, 210);
			this->radioButtonFunicular->Name = L"radioButtonFunicular";
			this->radioButtonFunicular->Size = System::Drawing::Size(102, 28);
			this->radioButtonFunicular->TabIndex = 9;
			this->radioButtonFunicular->TabStop = true;
			this->radioButtonFunicular->Text = L"Фунікулер";
			this->radioButtonFunicular->UseVisualStyleBackColor = true;
			// 
			// radioButtonLyadskiGate
			// 
			this->radioButtonLyadskiGate->AutoSize = true;
			this->radioButtonLyadskiGate->Location = System::Drawing::Point(6, 172);
			this->radioButtonLyadskiGate->Name = L"radioButtonLyadskiGate";
			this->radioButtonLyadskiGate->Size = System::Drawing::Size(140, 28);
			this->radioButtonLyadskiGate->TabIndex = 8;
			this->radioButtonLyadskiGate->TabStop = true;
			this->radioButtonLyadskiGate->Text = L"Лядські ворота";
			this->radioButtonLyadskiGate->UseVisualStyleBackColor = true;
			// 
			// radioButtonOneStreetMuseum
			// 
			this->radioButtonOneStreetMuseum->AutoSize = true;
			this->radioButtonOneStreetMuseum->Location = System::Drawing::Point(6, 423);
			this->radioButtonOneStreetMuseum->Name = L"radioButtonOneStreetMuseum";
			this->radioButtonOneStreetMuseum->Size = System::Drawing::Size(168, 28);
			this->radioButtonOneStreetMuseum->TabIndex = 15;
			this->radioButtonOneStreetMuseum->TabStop = true;
			this->radioButtonOneStreetMuseum->Text = L"Музей однієї вулиці";
			this->radioButtonOneStreetMuseum->UseVisualStyleBackColor = true;
			// 
			// radioButtonNationalPhilharmonic
			// 
			this->radioButtonNationalPhilharmonic->AutoSize = true;
			this->radioButtonNationalPhilharmonic->Location = System::Drawing::Point(6, 384);
			this->radioButtonNationalPhilharmonic->Name = L"radioButtonNationalPhilharmonic";
			this->radioButtonNationalPhilharmonic->Size = System::Drawing::Size(204, 28);
			this->radioButtonNationalPhilharmonic->TabIndex = 14;
			this->radioButtonNationalPhilharmonic->TabStop = true;
			this->radioButtonNationalPhilharmonic->Text = L"Національна філармонія";
			this->radioButtonNationalPhilharmonic->UseVisualStyleBackColor = true;
			// 
			// radioButtonStSophiaCathedral
			// 
			this->radioButtonStSophiaCathedral->AutoSize = true;
			this->radioButtonStSophiaCathedral->Location = System::Drawing::Point(6, 335);
			this->radioButtonStSophiaCathedral->Name = L"radioButtonStSophiaCathedral";
			this->radioButtonStSophiaCathedral->Size = System::Drawing::Size(163, 28);
			this->radioButtonStSophiaCathedral->TabIndex = 13;
			this->radioButtonStSophiaCathedral->TabStop = true;
			this->radioButtonStSophiaCathedral->Text = L"Софійський собор";
			this->radioButtonStSophiaCathedral->UseVisualStyleBackColor = true;
			// 
			// GroupBoxStart
			// 
			this->GroupBoxStart->Controls->Add(this->radioButtonOneStreetMuseum);
			this->GroupBoxStart->Controls->Add(this->labelRoute);
			this->GroupBoxStart->Controls->Add(this->radioButtonRedUniversity);
			this->GroupBoxStart->Controls->Add(this->radioButtonNationalPhilharmonic);
			this->GroupBoxStart->Controls->Add(this->radioButtonAndriivskaChurch);
			this->GroupBoxStart->Controls->Add(this->radioButtonStSophiaCathedral);
			this->GroupBoxStart->Controls->Add(this->radioButtonStMichaelsCathedral);
			this->GroupBoxStart->Controls->Add(this->radioButtonGoldenGate);
			this->GroupBoxStart->Controls->Add(this->radioButtonFountainOnKhreshchatyk);
			this->GroupBoxStart->Controls->Add(this->radioButtonLyadskiGate);
			this->GroupBoxStart->Controls->Add(this->radioButtonKPI);
			this->GroupBoxStart->Controls->Add(this->radioButtonFunicular);
			this->GroupBoxStart->Font = (gcnew System::Drawing::Font(L"Imprint MT Shadow", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->GroupBoxStart->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->GroupBoxStart->Location = System::Drawing::Point(33, 39);
			this->GroupBoxStart->Name = L"GroupBoxStart";
			this->GroupBoxStart->Size = System::Drawing::Size(326, 459);
			this->GroupBoxStart->TabIndex = 17;
			this->GroupBoxStart->TabStop = false;
			this->GroupBoxStart->Text = L"Початкова точка";
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::MidnightBlue;
			this->ClientSize = System::Drawing::Size(665, 737);
			this->Controls->Add(this->GroupBoxStart);
			this->Controls->Add(this->groupBoxAlgorithm);
			this->Controls->Add(this->btnSelectStartPoint);
			this->Location = System::Drawing::Point(100, 100);
			this->Name = L"MainForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::Manual;
			this->Text = L"MainForm";
			this->Load += gcnew System::EventHandler(this, &MainForm::MainForm_Load);
			this->groupBoxAlgorithm->ResumeLayout(false);
			this->groupBoxAlgorithm->PerformLayout();
			this->GroupBoxStart->ResumeLayout(false);
			this->GroupBoxStart->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
		private: System::Void secondForm_FormClosed(System::Object^ sender, System::Windows::Forms::FormClosedEventArgs^ e)
		{
			// Очистіть вибір радіобатонів на головній формі
			radioButtonRedUniversity->Checked = false;
			radioButtonAndriivskaChurch->Checked = false;
			radioButtonStMichaelsCathedral->Checked = false;
			radioButtonGoldenGate->Checked = false;
			radioButtonLyadskiGate->Checked = false;
			radioButtonFunicular->Checked = false;
			radioButtonKPI->Checked = false;
			radioButtonFountainOnKhreshchatyk->Checked = false;
			radioButtonStSophiaCathedral->Checked = false;
			radioButtonNationalPhilharmonic->Checked = false;
			radioButtonOneStreetMuseum->Checked = false;\
				radioButtonDijkstra->Checked = false;
			radioButtonBellmanFord->Checked = false;
		}
	private: System::Void btnSelectStartPoint_Click(System::Object^ sender, System::EventArgs^ e)
	{
		// Отримання вибраного початкового пункту та алгоритму
		String^ startPoint;
		String^ algorithm;

		if (radioButtonDijkstra->Checked) {
			algorithm = "Dijkstra";
		}
		else if (radioButtonBellmanFord->Checked) {
			algorithm = "Bellman-Ford";
		}
		const std::string Places[] = {
			"Red University",
			"Andriivska Church",
			"St. Michael's Cathedral",
			"Golden Gate",
			"Lyadski Gate",
			"Funicular",
			"KPI",
			"Fountain on Khreshchatyk",
			"St. Sophia Cathedral",
			"National Philharmonic",
			"One Street Museum"
		};

		// Виконання алгоритму та виведення результатів
		if (algorithm != nullptr) {
			int sourceVertex = -1;
			// Визначення номера вершини відповідно до вибраного початкового пункту
			if (radioButtonRedUniversity->Checked) sourceVertex = 0;
			else if (radioButtonAndriivskaChurch->Checked) sourceVertex = 1;
			else if (radioButtonStMichaelsCathedral->Checked) sourceVertex = 2;
			else if (radioButtonGoldenGate->Checked) sourceVertex = 3;
			else if (radioButtonLyadskiGate->Checked) sourceVertex = 4;
			else if (radioButtonFunicular->Checked) sourceVertex = 5;
			else if (radioButtonKPI->Checked) sourceVertex = 6;
			else if (radioButtonFountainOnKhreshchatyk->Checked) sourceVertex = 7;
			else if (radioButtonStSophiaCathedral->Checked) sourceVertex = 8;
			else if (radioButtonNationalPhilharmonic->Checked) sourceVertex = 9;
			else if (radioButtonOneStreetMuseum->Checked) sourceVertex = 10;

			// Виклик алгоритму та отримання результату
			if (sourceVertex != -1) {
				double graph[V][V] = {
					{0, 2, 1.7, 0.9, 0, 2.5, 5, 1, 0, 2.5, 0},
					{0, 0, 0.6, 1.3, 0, 0, 0, 2, 0.95, 0, 0.6},
					{1.7, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0},
					{0.9, 1.3, 0, 0, 0, 0, 0, 1, 0.55, 0, 0},
					{0, 0, 0.5, 0, 0, 0, 0, 1.1, 0, 0, 0},
					{0, 0, 0, 0, 0, 0, 0, 0, 0, 0.75, 0},
					{5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
					{1, 2, 0, 0, 1.1, 0, 0, 0, 0, 0, 0},
					{1.3, 0.95, 0, 0.55, 0.75, 0, 0, 0, 0, 0, 0},
					{2.3, 0, 0, 0, 0, 0.75, 0, 0, 0, 0, 0},
					{0, 0.6, 0, 0, 0, 0.8, 0, 0, 0, 0, 0}
				};

				ShortestPathResult result;
				// Виклик відповідного алгоритму в залежності від вибору
				if (algorithm == "Dijkstra") {
					result = Dijkstra(graph, sourceVertex);
				}
				else if (algorithm == "Bellman-Ford") {
					result = BellmanFord(graph, sourceVertex);
				}

				// Відображення результатів на формі
				String^ routeText = "";
				for (int i = 0; i < V; i++)
				{
					routeText += gcnew String(result.route[i].c_str()) + "\n";
				}
				labelRoute->Text = routeText;

				// Перехід на наступну форму
				System::ComponentModel::IContainer^ container = gcnew System::ComponentModel::Container();
				SecondForm^ secondForm = gcnew SecondForm(container);
				secondForm->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &MainForm::secondForm_FormClosed);
				secondForm->SetRouteText(result, Places, sourceVertex, graph); // Встановлення тексту на другій формі

				secondForm->Show();
				// Сховати поточну форму
			}
		}
	}


	private: System::Void MainForm_Load(System::Object^ sender, System::EventArgs^ e) {

	}

	private: System::Void groupBoxAlgorithm_Enter(System::Object^ sender, System::EventArgs^ e) {
	}
};
}
