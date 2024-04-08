#include "GUI.h" // Подключаем файл заголовка для формы
#include "TaQueues.h" // А это уже файл заголовка для алгоритмов очереди


using namespace System; // Нужные пространства имен для работы с формами и не только
using namespace System::Windows::Forms;

#define QUEUE_SIZE 20 // Добавил изменяемость для размера очереди 


[STAThreadAttribute]
void main(array<String^>^ args)
{
    // Без цієї штуки форма не буде працювати
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);
    Laboratorka4::MainForm form;
    Application::Run(% form);
}

System::Void Laboratorka4::MainForm::button_arr_Click(System::Object^ sender, System::EventArgs^ e)
{
    listBox1->Items->Clear();
    listBox2->Items->Clear();
    QueueArr names;
    unsigned long int totalTime = 0;

    for (int i = 1; i <= QUEUE_SIZE; ++i) {
        String^ message = "The teacher is checking assignment " + i.ToString();
        listBox1->Items->Add(message);
        listBox1->Refresh();

        names.Enqueue(std::to_string(i));
        std::string queueOutput = "Queue: ";
        unsigned short queueSize = names.getSize();
        std::string* queueArray = names.GetQueue();
        for (unsigned short j = 0; j < queueSize; ++j) {
            queueOutput += queueArray[j] + " ";
        }

        listBox1->Items->Add(gcnew System::String(queueOutput.c_str()));
        listBox1->Refresh();

        totalTime += names.ExecTime();
    }

    listBox1->Items->Add("Execution Time: " + totalTime.ToString() + "ns");
    listBox1->Refresh();

    totalTime = 0;

    for (int i = 1; i <= QUEUE_SIZE; ++i) {
        std::string removed_item = names.Dequeue();

        String^ message = "Assignments marked in Campus: " + gcnew System::String(removed_item.c_str());
        listBox2->Items->Add(message);
        listBox2->Refresh();

        std::string queueOutput = "Queue: ";
        unsigned short queueSize = names.getSize();
        std::string* queueArray = names.GetQueue();
        for (unsigned short j = 0; j < queueSize; ++j) {
            queueOutput += queueArray[j] + " ";
        }

        listBox2->Items->Add(gcnew System::String(queueOutput.c_str()));
        listBox2->Refresh();

        totalTime += names.ExecTime();
    }

    listBox2->Items->Add("Execution Time: " + totalTime.ToString() + "ns");
    listBox2->Refresh();
}

System::Void Laboratorka4::MainForm::button_point_Click(System::Object^ sender, System::EventArgs^ e)
{
        listBox1->Items->Clear();
        listBox2->Items->Clear();
        NodeQueue names;
        unsigned long int totalTime = 0;

        for (int i = 1; i <= QUEUE_SIZE; ++i) {
            String^ message = "The teacher is checking assignment " + i.ToString();
            listBox1->Items->Add(message);
            listBox1->Refresh();

            names.Enqueue(std::to_string(i));
            std::string queueOutput = "Queue: ";
            unsigned short queueSize = names.getSize();
            std::string* queueArray = names.GetQueue();
            for (unsigned short j = 0; j < queueSize; ++j) {
                queueOutput += queueArray[j] + " ";
            }

            listBox1->Items->Add(gcnew System::String(queueOutput.c_str()));
            listBox1->Refresh();

            totalTime += names.ExecTime();
        }

        listBox1->Items->Add("Execution Time: " + totalTime.ToString() + "ns");
        listBox1->Refresh();
    
         totalTime = 0;

        for (int i = 1; i <= QUEUE_SIZE; ++i) {
            std::string removed_item = names.Dequeue();

            String^ message = "Assignments marked in Campus: " + gcnew System::String(removed_item.c_str());
            listBox2->Items->Add(message);
            listBox2->Refresh();

            std::string queueOutput = "Queue: ";
            unsigned short queueSize = names.getSize();
            std::string* queueArray = names.GetQueue();
            for (unsigned short j = 0; j < queueSize; ++j) {
                queueOutput += queueArray[j] + " ";
            }

            listBox2->Items->Add(gcnew System::String(queueOutput.c_str()));
            listBox2->Refresh();

            totalTime += names.ExecTime();
        }

        listBox2->Items->Add("Execution Time: " + totalTime.ToString() + "ns");
        listBox2->Refresh();
}

System::Void Laboratorka4::MainForm::button_clean_Click(System::Object^ sender, System::EventArgs^ e)
{
    listBox1->Items->Clear();
    listBox2->Items->Clear();
}
