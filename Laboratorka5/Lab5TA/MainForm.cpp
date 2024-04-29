#include "MainForm.h"
#include "TASimpleHash.h"
#include <sstream>
#include <msclr/marshal_cppstd.h>
#include <string>
#define HASH_TABLE_SIZE 7
 // For string conversions
using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]
void main(cli::array<String^>^ args) {
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);
   
    Lab5TA::MainForm^ form = gcnew Lab5TA::MainForm();
    Application::Run(form);
}

static Hash h(HASH_TABLE_SIZE);// Hash table with 7 cells

System::Void Lab5TA::MainForm::button_add_Click(System::Object^ sender, System::EventArgs^ e) {
    System::String^ selectedMode = comboBox_method->SelectedItem ? comboBox_method->SelectedItem->ToString() : "";

    if (selectedMode == "Multification") {
        h.setModeMultiplication();
    }
    else if (selectedMode == "Division") {
        h.setModeDivision();
    }
    else {
        MessageBox::Show("Будь ласка, виберіть метод", "Помилка", MessageBoxButtons::OK, MessageBoxIcon::Error);
        return;
    }

    // Конвертація System::String^ в std::string
    System::String^ nameClr = textBox_name->Text;
    std::string name = msclr::interop::marshal_as<std::string>(nameClr);

    label3->Text = nameClr; // Відображаємо ім'я

    int score;
    if (Int32::TryParse(textBox_grade->Text, score)) {
        h.insertItem(name, score);

        listBox_students->Items->Clear(); // Очистка ListBox

        std::string hashOutput = h.displayHash(); // Отримання даних з хеш-таблиці
        System::String^ hashOutputClr = gcnew System::String(hashOutput.c_str(), 0, hashOutput.length(), System::Text::Encoding::UTF8); // Перетворення std::string в System::String^

        cli::array<System::String^>^ entries = hashOutputClr->Split('\n'); // Розбиття рядка на елементи
        for (int i = 0; i < entries->Length; i++) {
            if (!System::String::IsNullOrWhiteSpace(entries[i])) {
                listBox_students->Items->Add(entries[i]); // Додавання до ListBox
            }
        }

        textBox_name->Clear(); // Очищення полів
        textBox_grade->Clear();
        unsigned int execTime = h.getExecutionTime();
        label_time->Text = "Execution Time: " + execTime.ToString() + " ns"; // Відображення на етикетці
    }
    else {
        MessageBox::Show("Будь ласка, введіть дійсний цілий бал.", "Невірний ввід", MessageBoxButtons::OK, MessageBoxIcon::Error);
    }
}


System::Void Lab5TA::MainForm::button_delete_Click(System::Object^ sender, System::EventArgs^ e) {
    if (listBox_students->SelectedItem != nullptr) {
        // Get selected item
        System::String^ selectedItem = listBox_students->SelectedItem->ToString();

        // Convert from System::String^ to std::string
        std::string stdSelectedItem = msclr::interop::marshal_as<std::string>(selectedItem);

        // Find start and end positions for extraction
        std::size_t startPos = stdSelectedItem.find('(');
        std::size_t endPos = stdSelectedItem.find(',', startPos);

        if (startPos != std::string::npos && endPos != std::string::npos && endPos > startPos) {
            // Extract the substring between '(' and ','
            std::string subString = stdSelectedItem.substr(startPos + 1, endPos - startPos - 1);

            // Delete item from hash table
            h.deleteItem(subString);

            // Clear and update ListBox
            listBox_students->Items->Clear();
            std::string hashOutput = h.displayHash();
            System::String^ hashOutputClr = gcnew System::String(hashOutput.c_str());

            cli::array<System::String^>^ entries = hashOutputClr->Split('\n');
            for (int i = 0; i < entries->Length; i++) {
                if (!System::String::IsNullOrWhiteSpace(entries[i])) {
                    listBox_students->Items->Add(entries[i]);
                }
            }
            unsigned int execTime = h.getExecutionTime();
            label_time->Text = "Execution Time: " + execTime.ToString() + " ns";
        }
        else {
            MessageBox::Show("Не знайдено відповідних символів '(' та ','.", "Помилка", MessageBoxButtons::OK, MessageBoxIcon::Error);
        }
    }
    else {
        MessageBox::Show("Будь ласка, виберіть елемент для видалення.", "Помилка", MessageBoxButtons::OK, MessageBoxIcon::Error);
    }
}

System::Void Lab5TA::MainForm::button_find_Click(System::Object^ sender, System::EventArgs^ e)
{
    int index;

    // Перевірка введеного значення на цілість та діапазон
    if (!Int32::TryParse(textBox_find->Text, index) || index < 0 || index >= HASH_TABLE_SIZE) {
        MessageBox::Show("Будь ласка, введіть дійсний індекс від 0 до " + (HASH_TABLE_SIZE - 1).ToString(), "Невірний ввід", MessageBoxButtons::OK, MessageBoxIcon::Error);
        return;
    }

    // Отримання вмісту бакета з заданим індексом
    std::string bucketContent = h.dehashItem(index);
    System::String^ outputMessage;

    if (!bucketContent.empty()) {
        // Якщо бакет не порожній, зберігаємо весь його вміст
        outputMessage = gcnew System::String(("Bucket " + std::to_string(index) + ":\n" + bucketContent).c_str());
    }
    else {
        // Якщо бакет порожній, повідомляємо користувача
        outputMessage = "Bucket " + index.ToString() + " is empty.";
    }

    // Виводимо результат у спливаючому вікні
    MessageBox::Show(outputMessage, "Результат", MessageBoxButtons::OK, MessageBoxIcon::Information);

    // Відображення часу виконання
    unsigned int execTime = h.getExecutionTime();
    label_time->Text = "Час виконання: " + execTime.ToString() + " ns";
    textBox_find->Text = "";
}
