//---------------------------------------------------------------------------

#include <fmx.h>
#include <queue>
#pragma hdrstop

#include "Unit2.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"

class Question
{
  public:
    char* Text;
    char* Answer1;
    char* Answer2;
    char* Answer3;
    int CorrectAnswer;

    Question() {}
    Question(char* text, char* ans1, char* ans2, char* ans3, int correctAns)
    {
        Text = text;
        Answer1 = ans1;
        Answer2 = ans2;
        Answer3 = ans3;
        CorrectAnswer = correctAns;
    }
};

std::queue<Question> LoadQuestions()
{
    Question q1 = Question(
        "1. Who has the most number of stumpings in an innings of a test match?",
        "MS Dhoni", "KS More", "Rishab Pant", 2);
    Question q2 = Question(
        "2.Who was the Man of the Match of the asia cup final played between India and Sri lanka?",
        "Kuldeep Yadav", "Shubman Gill", "Md. Siraj", 3);
    Question q3 = Question(
        "3. Who is the captain of the Indian Cricket team that is competing this year at Asian Games?",
        "Ruturaj Gaikwad", "Shivam Dube", "Rinku Singh", 1);

    std::queue<Question> questions;
    questions.push(q1);
    questions.push(q2);
    questions.push(q3);

    return questions;
}

std::queue<Question> questions;
Question currentQuestion;
int selectedAnswer;
int points = 0;
TForm2* Form2;
//---------------------------------------------------------------------------
__fastcall TForm2::TForm2(TComponent* Owner) : TForm(Owner)

{
    questions = LoadQuestions();
    currentQuestion = questions.front();

    QuestionLabel->Text = currentQuestion.Text;
    Answer1RadioButton->Text = currentQuestion.Answer1;
    Answer2RadioButton->Text = currentQuestion.Answer2;
    Answer3RadioButton->Text = currentQuestion.Answer3;

	questions.pop();
    PointsLabel->Text=points;
}
//---------------------------------------------------------------------------

void __fastcall TForm2::Answer1RadioButtonChange(TObject* Sender)
{
    selectedAnswer = 1;
}
//---------------------------------------------------------------------------

void __fastcall TForm2::Answer2RadioButtonChange(TObject* Sender)
{
    selectedAnswer = 2;
}
//---------------------------------------------------------------------------

void __fastcall TForm2::Answer3RadioButtonChange(TObject* Sender)
{
    selectedAnswer = 3;
}
//---------------------------------------------------------------------------

void __fastcall TForm2::ConfirmButtonClick(TObject* Sender)
{
    if (selectedAnswer == currentQuestion.CorrectAnswer) {
        points++;
        PointsLabel->Text = points;
    }

    if (!questions.empty()) {
        currentQuestion = questions.front();

        QuestionLabel->Text = currentQuestion.Text;
        Answer1RadioButton->Text = currentQuestion.Answer1;
        Answer2RadioButton->Text = currentQuestion.Answer2;
        Answer3RadioButton->Text = currentQuestion.Answer3;

        questions.pop();
		Answer1RadioButton->IsChecked = false;
		Answer2RadioButton->IsChecked = false;
        Answer3RadioButton->IsChecked = false;
	}
	else{
		ConfirmButton->Enabled=false;
        ConfirmButton->Text="The End";
    }
}
//---------------------------------------------------------------------------

