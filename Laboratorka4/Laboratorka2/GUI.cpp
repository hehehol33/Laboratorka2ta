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

System::Void Laboratorka4::MainForm::UpdateListBoxItem(System::Windows::Forms::ListBox^ listBox, System::Windows::Forms::TextBox^ textBox_grade)
{
    int selectedIndex = listBox->SelectedIndex;
    if (selectedIndex >= 0 && selectedIndex < listBox->Items->Count) {
        String^ selectedText = listBox->Items[selectedIndex]->ToString();
        String^ grade = textBox_grade->Text;

        // перевірка валідності оцінки
        int gradeValue;
        if (Int32::TryParse(grade, gradeValue) && gradeValue >= 1 && gradeValue <= 100) {
            int lastPipeIndex = selectedText->LastIndexOf("|");
            if (lastPipeIndex >= 0) {
                String^ textWithoutGrade = selectedText->Substring(0, lastPipeIndex);
                listBox->Items[selectedIndex] = textWithoutGrade + "| " + grade;
            }
            else {
                String^ updatedText = selectedText + "  | " + grade;
                listBox->Items[selectedIndex] = updatedText;
            }
            textBox_grade->Clear();
        }
        else {
            MessageBox::Show("The grade must be between 1 - 100");
        }
    }
    else {
        MessageBox::Show("Choose an assignment to grade.");
    }
}

