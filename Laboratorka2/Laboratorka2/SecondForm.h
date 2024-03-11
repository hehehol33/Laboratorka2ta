#pragma once

#include <vector>
#include <string>
#include <iostream>
#include "Algorithms.h"

public ref class SecondForm : public System::Windows::Forms::Form
{
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
                labelText += "-------------------------------------------------------------------------------------------------\n";
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

private:
    System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
    void InitializeComponent(void)
    {
        this->labelRoute = (gcnew System::Windows::Forms::Label());
        this->SuspendLayout();
        // 
        // labelRoute
        // 
        this->labelRoute->ForeColor = System::Drawing::Color::Navy;
        this->labelRoute->Location = System::Drawing::Point(13, 9);
        this->labelRoute->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
        this->labelRoute->Name = L"labelRoute";
        this->labelRoute->Size = System::Drawing::Size(616, 655);
        this->labelRoute->TabIndex = 0;
        this->labelRoute->Text = L"-";
        // 
        // SecondForm
        // 
        this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
        this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
        this->BackColor = System::Drawing::Color::PaleTurquoise;
        this->ClientSize = System::Drawing::Size(660, 673);
        this->Controls->Add(this->labelRoute);
        this->Margin = System::Windows::Forms::Padding(4);
        this->Name = L"SecondForm";
        this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
        this->Text = L"Result";
        this->ResumeLayout(false);

    }
#pragma endregion

private:
    System::Windows::Forms::Label^ labelRoute;
};
