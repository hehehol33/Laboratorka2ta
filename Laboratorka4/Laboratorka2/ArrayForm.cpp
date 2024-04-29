#include "ArrayForm.h"
#include "TaQueues.h"
#include "GUI.h"
ArrQueue arrQueue;
unsigned long int elementCount = 0;

System::Void Laboratorka4::ArrayForm::button_save_Click(System::Object^ sender, System::EventArgs^ e)
{
    //кнпка реалізує виведення стопки робіт в лістбокс1 та черги на оціювання в лістбокс2
    String^ text_person = textBox_input->Text;

    // Додавання елемента до черги
    arrQueue.Enqueue(elementCount + 1);
    unsigned int arrQueueExecTime = arrQueue.ExecTime();
    elementCount++;
    String^ displayText = text_person + " " + elementCount;

    // Додавання елемента до listBox1 разом з підрахунком на початок списку
    listBox1->Items->Insert(0, displayText);
    listBox2->Items->Add( displayText);
    textBox_input->Clear();
    
    label_execution_time->Text = "ArrQueue Execution Time: " + arrQueueExecTime.ToString();
}

System::Void Laboratorka4::ArrayForm::ArrayForm_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e)
{
    // Скидання підрахунку до початкового значення при закритті форми
    elementCount = 0;
}



System::Void Laboratorka4::ArrayForm::button_save2_Click(System::Object^ sender, System::EventArgs^ e) {
    int selectedIndex = listBox2->SelectedIndex;
    if (selectedIndex >= 0 && selectedIndex < listBox2->Items->Count) {
        String^ selectedText = listBox2->Items[selectedIndex]->ToString();
        String^ grade = textBox_input_grade->Text;

        // перевірка валідності оцінки
        int gradeValue;
        if (Int32::TryParse(grade, gradeValue) && gradeValue >= 1 && gradeValue <= 100) {
            int lastPipeIndex = selectedText->LastIndexOf("|");
            if (lastPipeIndex >= 0) {
                String^ textWithoutGrade = selectedText->Substring(0, lastPipeIndex);
                listBox2->Items[selectedIndex] = textWithoutGrade + "| " + grade;
            }
            else {
                String^ updatedText = selectedText + "  | " + grade;
                listBox2->Items[selectedIndex] = updatedText;
            }
            textBox_input_grade->Clear();
        }
        else {
            MessageBox::Show("The grade must be between 1 - 100");
        }
    }
    else {
        MessageBox::Show("Choose an assignment to grade.");
    }
}

System::Void Laboratorka4::ArrayForm::button_delete_Click(System::Object^ sender, System::EventArgs^ e)
{

    //кнопка видаляє останній доданий елемент черги в listbox1 та listbox2

    arrQueue.Dequeue();

    
    if (listBox1->Items->Count > 0)
    {
       
        listBox1->Items->RemoveAt(0);
    }
    else
    {
        MessageBox::Show("The list is empty.");
    }

    
    int lastIndex = listBox2->Items->Count - 1;

    
    if (lastIndex >= 0)
    {
        // Видалення останнього елемента з listBox2
        listBox2->Items->RemoveAt(lastIndex);
    }
    else
    {
        MessageBox::Show("The second list is empty.");
    }

    elementCount--;
}

System::Void Laboratorka4::ArrayForm::button_delete_grade_Click(System::Object^ sender, System::EventArgs^ e)
{
    //кнопка для видалення оцінки 
    int selectedIndex = listBox2->SelectedIndex;
    if (selectedIndex >= 0 && selectedIndex < listBox2->Items->Count)
    {
        
        String^ selectedText = listBox2->Items[selectedIndex]->ToString();

        
        int lastPipeIndex = selectedText->LastIndexOf("|");

       
        if (lastPipeIndex >= 0)
        {
            
            String^ textWithoutGrade = selectedText->Substring(0, lastPipeIndex);

            // оновлення вибраного рядка без оцінки
            listBox2->Items[selectedIndex] = textWithoutGrade;
        }
        else
        {
            MessageBox::Show("The selected element doesn't have a grade.");
        }
    }
    else
    {
        MessageBox::Show("Please select an item to remove the grade from.");
    }
}


System::Void Laboratorka4::ArrayForm::button_add_Click(System::Object^ sender, System::EventArgs^ e)
{
    //кнопка додає до відомості тільки роботи з вже витсавленими оцінками та онововлює лісбокс при зміні listbox2
    listBox3->Items->Clear();
    for (int i = 0; i < listBox2->Items->Count; i++)
    {
        String^ itemText = listBox2->Items[i]->ToString();

        
        int gradeIndex = itemText->LastIndexOf("|");

        // Перевірка, чи є оцінка у тексті елемента
        if (gradeIndex >= 0)
        {
            // Додавання елемента до listBox3
            listBox3->Items->Add(itemText);
        }
    }
   

}

