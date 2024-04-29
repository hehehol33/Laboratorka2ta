#include <msclr/marshal_cppstd.h>
#include "MainForm.h"
#include "TaOpenAdressingHashing.h"
using namespace System;
using namespace System::Windows::Forms;

OpenAddressingHashTable* hashTable = nullptr;
int tableSize;
bool isLinearProbe;

[STAThreadAttribute]
void main(array<String^>^ args) {
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);
    Lab6TA::MainForm^ form = gcnew Lab6TA::MainForm();
    Application::Run(form);
}

System::Void Lab6TA::MainForm::button_create_Click(System::Object^ sender, System::EventArgs^ e) {
    System::String^ textBoxValue = textBox_size->Text;
    tableSize = System::Convert::ToInt32(textBoxValue);

    if (tableSize <= 0) {
        MessageBox::Show("Table size must be greater than 0.");
        return;
    }

    if (hashTable != nullptr) {
        delete hashTable;
    }

    hashTable = new OpenAddressingHashTable(tableSize);

    isLinearProbe = comboBox_method->SelectedIndex == 0;
    textBox_size->Text = "";
    unsigned int execTime = hashTable->getExecutionTime();
    label_time->Text = "Execution Time: " + execTime.ToString() + " ns";
    MessageBox::Show("Hash table created successfully.");

   
}

System::Void Lab6TA::MainForm::button_add_Click(System::Object^ sender, System::EventArgs^ e) {
    if (hashTable == nullptr) {
        MessageBox::Show("Hash table has not been created.");
        return;
    }

    try {
        System::String^ name = textBox_name->Text;
        System::String^ scoreString = textBox_grade->Text;

        std::string nameStr = msclr::interop::marshal_as<std::string>(name);
        unsigned short score = System::Convert::ToUInt16(scoreString);

        if (!hashTable->insert(nameStr, score)) {
            MessageBox::Show("Failed to insert into the hash table. It might be full.");
        }
        else {
          

            listBox_students->Items->Clear(); // Очистка ListBox перед оновленням

            std::vector<Student> outputTable = hashTable->getHashTable();
            short i = 0;

            for (const auto& key : outputTable) {
                System::String^ displayText;

                if (key.str.empty()) {
                    displayText = gcnew System::String((std::to_string(i) + ": -").c_str());
                }
                else {
                    displayText = gcnew System::String(
                        (std::to_string(i) + ": Student " + key.str + ", " + std::to_string(key.num)).c_str());
                }

                listBox_students->Items->Add(displayText);// Додавання елементів
                textBox_name->Text = "";
                textBox_grade->Text = "";
                unsigned int execTime = hashTable->getExecutionTime();
                label_time->Text = "Execution Time: " + execTime.ToString() + " ns";
                i++;
            }
        }
    }
    catch (System::FormatException^) {
        MessageBox::Show("Please enter a valid score.");
    }
    catch (System::Exception^ ex) {
        MessageBox::Show("An error occurred: " + ex->Message);
    }
}

System::Void Lab6TA::MainForm::button_delete_Click(System::Object^ sender, System::EventArgs^ e)
{
    if (hashTable == nullptr) {
        MessageBox::Show("Hash table has not been created.");
        return;
    }

    int selectedIndex = listBox_students->SelectedIndex; // Отримати вибраний індекс із ListBox

    if (selectedIndex < 0) {
        MessageBox::Show("Please select an item to remove.");
        return;
    }

    System::String^ selectedItem = listBox_students->Items[selectedIndex]->ToString(); // Отримати обраний елемент
    if (selectedItem->Contains("-")) { // Перевірка, чи вказує на порожній слот
        MessageBox::Show("Slot is already empty.");
        return;
    }

    std::string itemStr = msclr::interop::marshal_as<std::string>(selectedItem); // Конвертація в std::string
    std::string delimiter = "|";
    size_t pos = itemStr.find(delimiter); // Знаходження позиції вертикальної риски
   

    std::string indexStr = itemStr.substr(0, pos); // Отримання індексу як рядка
    int index = std::stoi(indexStr); // Конвертація в число

    // Видалення даних із хеш-таблиці та оновлення ListBox
    if (hashTable->Remove(index)) { // Видалення з хеш-таблиці
        listBox_students->Items[selectedIndex] = System::String::Format("{0}: -", index); // Оновити ListBox
       
    }
    unsigned int execTime = hashTable->getExecutionTime();
    label_time->Text = "Execution Timeee: " + execTime.ToString() + " ns";
}

System::Void Lab6TA::MainForm::button_find_Click(System::Object^ sender, System::EventArgs^ e) {
    System::String^ inputText = textBox_find->Text;
    unsigned short index;

    try {
        index = System::Convert::ToUInt16(inputText);  // Конвертуємо у число
    }
    catch (System::FormatException^) {
        MessageBox::Show("Invalid input. Please enter a valid number.");
        return;
    }

    Student result = hashTable->search(index);
    if (result.str.empty() && result.num == 0) {
        MessageBox::Show("No record found at this index.");
    }
    else {
        // Конвертуємо std::string до System::String
        System::String^ studentName = msclr::interop::marshal_as<System::String^>(result.str);

        // Використовуємо String::Format для форматування
        System::String^ studentInfo = System::String::Format("Student: {0}, Score: {1}", studentName, result.num);

        MessageBox::Show(studentInfo);
        unsigned int execTime = hashTable->getExecutionTime();
        label_time->Text = "Execution Timeee: " + execTime.ToString() + " ns";
    }
}

System::Void Lab6TA::MainForm::button1_Click(System::Object^ sender, System::EventArgs^ e)
{
   
    if (hashTable != nullptr) { // перевірити, чи таблиця не є null
        delete hashTable; // виклик деструктора
        hashTable = nullptr; // встановити вказівник у null, щоб запобігти висячому вказівник
        
    }


    listBox_students->Items->Clear();
}

