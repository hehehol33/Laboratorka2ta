#include "GUI.h" // Подключаем файл заголовка для формы
// А это уже файл заголовка для алгоритмов
#include "TaQueues.h"
#include "PointerForm.h"
#include "ArrayForm.h"

using namespace System; // Нужные пространства имен для работы с формами и не только
using namespace System::Windows::Forms;




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
    ArrayForm^ arrayForm = gcnew ArrayForm();
    arrayForm->Show();
}

System::Void Laboratorka4::MainForm::button_point_Click(System::Object^ sender, System::EventArgs^ e)
{
    PointerForm^ pointerForm = gcnew PointerForm();
    pointerForm->Show();
}
