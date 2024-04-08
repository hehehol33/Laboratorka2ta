#include "GUI.h" // Подключаем файл заголовка для формы
#include "TaQueues.h" // А это уже файл заголовка для алгоритмов очереди


using namespace System; // Нужные пространства имен для работы с формами и не только
using namespace System::Windows::Forms;

#define QUEUE_SIZE 25 // Добавил изменяемость для размера очереди 


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
    ArrQueue names;
    unsigned long int totalTime = 0;

    for (int i = 1; i <= QUEUE_SIZE; ++i) {
        String^ message = "The teacher is checking assignment " + i.ToString();
        listBox1->Items->Add(message);
        

        names.Enqueue(i);
        std::string queueOutput = "Queue: ";
        unsigned short queueSize = names.getSize();
        unsigned short* queueArray = names.GetQueue();
        for (unsigned short j = 0; j < queueSize; ++j) {
            queueOutput += std::to_string(queueArray[j]) + " ";
        }

        listBox1->Items->Add(gcnew System::String(queueOutput.c_str()));
        

        totalTime += names.ExecTime();
    }

    listBox1->Items->Add("Execution Time: " + totalTime.ToString() + "ns");
    

    totalTime = 0;

    for (int i = 1; i <= QUEUE_SIZE; ++i) {
        unsigned short removed_item = names.Dequeue();

        String^ message = "Assignments marked in Campus: " + System::Convert::ToString(removed_item);
        listBox2->Items->Add(message);
        std::string queueOutput = "Queue: ";
        unsigned short queueSize = names.getSize();
        unsigned short* queueArray = names.GetQueue();
        for (unsigned short j = 0; j < queueSize; ++j) {
            queueOutput += std::to_string(queueArray[j]) + " ";
        }

        listBox2->Items->Add(gcnew System::String(queueOutput.c_str()));
        

        totalTime += names.ExecTime();
    }

    listBox2->Items->Add("Execution Time: " + totalTime.ToString() + "ns");
    
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
            

            names.Enqueue(i);
            std::string queueOutput = "Queue: ";
            unsigned short queueSize = names.getSize();
            unsigned short* queueArray = names.GetQueue();
            for (unsigned short j = 0; j < queueSize; ++j) {
                queueOutput += std::to_string(queueArray[j]) + " ";
            }

            listBox1->Items->Add(gcnew System::String(queueOutput.c_str()));
            

            totalTime += names.ExecTime();
        }

        listBox1->Items->Add("Execution Time: " + totalTime.ToString() + "ns");
        
    
         totalTime = 0;

        for (int i = 1; i <= QUEUE_SIZE; ++i) {
            unsigned short removed_item = names.Dequeue();

            String^ message = "Assignments marked in Campus: " + System::Convert::ToString(removed_item);
            listBox2->Items->Add(message);
            

            std::string queueOutput = "Queue: ";
            unsigned short queueSize = names.getSize();
            unsigned short* queueArray = names.GetQueue();
            for (unsigned short j = 0; j < queueSize; ++j) {
                queueOutput += std::to_string(queueArray[j]) + " ";
            }

            listBox2->Items->Add(gcnew System::String(queueOutput.c_str()));
            

            totalTime += names.ExecTime();
        }

        listBox2->Items->Add("Execution Time: " + totalTime.ToString() + "ns");
        
}

System::Void Laboratorka4::MainForm::button_clean_Click(System::Object^ sender, System::EventArgs^ e)
{
    listBox1->Items->Clear();
    listBox2->Items->Clear();
}
