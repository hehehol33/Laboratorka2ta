#pragma once

#include <vector>
#include <string>
#include <iostream>
#include "Algorithms.h"

public ref class SecondForm : public System::Windows::Forms::Form
{
    delegate void ReturnToPreviousFormDelegate();
    event ReturnToPreviousFormDelegate^ ReturnToPreviousForm;
private:
    System::Windows::Forms::Button^ buttonBack;

public:
    SecondForm(System::ComponentModel::IContainer^ container)
    {
        InitializeComponent();
    }

    void SetRouteText(ShortestPathResult result, const std::string Places[], int sourceVertex, double graph[V][V])
    {
        // Declare a variable to store the text
        System::String^ labelText = "";

        // Add information about each element of the structure to the text
        labelText += "Shortest paths from " + gcnew System::String(Places[sourceVertex].c_str()) + ":\n";

        for (int i = 0; i < V; i++)
        {
            if (sourceVertex != i) // Skip the source vertex itself
            {
                // Convert numbers to text and add to labelText
                labelText += "Route to " + gcnew System::String(Places[i].c_str()) + ":\n";

                // Display the shortest path route
                std::string shortestRoute = result.route[i];
                std::vector<int> vertices;
                int j = i;
                while (result.previous[j] != -1)
                {
                    vertices.push_back(j);
                    j = result.previous[j];
                }
                vertices.push_back(sourceVertex);

                // Convert vertex indices to place names with their ordinal numbers
                std::reverse(vertices.begin(), vertices.end());
                for (size_t k = 0; k < vertices.size(); k++)
                {
                    int placeIndex = vertices[k];
                    std::string placeName = Places[placeIndex];
                    int ordinalNumber = placeIndex + 1; // Ordinal number is index + 1
                    shortestRoute += " -> (" + std::to_string(ordinalNumber) + ") " + placeName;
                }

                // Append the shortest route to the label text
                labelText += gcnew System::String(shortestRoute.c_str()) + "\n";

                // Add the distance between the objects
                double distance = 0.0;
                for (size_t k = 1; k < vertices.size(); k++) {
                    distance += graph[vertices[k - 1]][vertices[k]];
                }
                labelText += "Distance: " + distance.ToString() + "\n";

                // Add separator
                labelText += "--------------------------------------------------------------------\n";

            }
        }





        labelText += "\n";

        // Set the text of labelRoute
        labelRoute->Text = labelText;
    }







protected:
    ~SecondForm()
    {
        if (components)
        {
            delete components;
        }
    }
private: System::Windows::Forms::Button^ button_back;







protected:

private:
    System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
    void InitializeComponent(void)
    {
        this->labelRoute = (gcnew System::Windows::Forms::Label());
        this->button_back = (gcnew System::Windows::Forms::Button());
        this->SuspendLayout();
        // 
        // labelRoute
        // 
        this->labelRoute->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 7.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
        this->labelRoute->ForeColor = System::Drawing::Color::Navy;
        this->labelRoute->Location = System::Drawing::Point(10, 9);
        this->labelRoute->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
        this->labelRoute->Name = L"labelRoute";
        this->labelRoute->Size = System::Drawing::Size(475, 740);
        this->labelRoute->TabIndex = 0;
        this->labelRoute->Text = L"-";
        // 
        // button_back
        // 
        this->button_back->BackColor = System::Drawing::Color::LightCyan;
        this->button_back->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
        this->button_back->Font = (gcnew System::Drawing::Font(L"Arial Narrow", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
        this->button_back->ForeColor = System::Drawing::Color::MidnightBlue;
        this->button_back->Location = System::Drawing::Point(491, 697);
        this->button_back->Margin = System::Windows::Forms::Padding(2);
        this->button_back->Name = L"button_back";
        this->button_back->Size = System::Drawing::Size(82, 43);
        this->button_back->TabIndex = 1;
        this->button_back->Text = L"Назад";
        this->button_back->UseVisualStyleBackColor = false;
        this->button_back->Click += gcnew System::EventHandler(this, &SecondForm::button_back_Click);
        // 
        // SecondForm
        // 
        this->AutoScaleDimensions = System::Drawing::SizeF(6, 16);
        this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
        this->BackColor = System::Drawing::Color::LightBlue;
        this->ClientSize = System::Drawing::Size(583, 751);
        this->Controls->Add(this->button_back);
        this->Controls->Add(this->labelRoute);
        this->Font = (gcnew System::Drawing::Font(L"Arial Narrow", 7.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
        this->Location = System::Drawing::Point(604, 20);
        this->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
        this->Name = L"SecondForm";
        this->StartPosition = System::Windows::Forms::FormStartPosition::Manual;
        this->Text = L"Result";
        this->ResumeLayout(false);

    }
#pragma endregion

private:
    System::Windows::Forms::Label^ labelRoute;
private: System::Void button_back_Click(System::Object^ sender, System::EventArgs^ e) {
    this->Close();
}
};
