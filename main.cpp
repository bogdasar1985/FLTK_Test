#include <Fl/Fl.H>
#include <Fl/Fl_Window.H>
#include <Fl/Fl_Text_Display.H>
#include <Fl/Fl_Radio_Round_Button.H>
#include <Fl/Fl_Button.H>
#include <Fl/Fl_Box.H>
#include <string>
#include "Fl_Single_Choice_Question.hpp"
#include "Fl_Many_Choice_Question.hpp"
//TODO: создать пул вопросов, используя идентификаторы QuestionType
int question_number = 0;
int counter = 0;    // count of right answers
int count_of_questions = 6;

enum
{
    spacing_w = 20,
    spacing_h = 20,
    text_display_w = 600,
    text_display_h = 50,
    radio_round_button_w = 20,
    radio_round_button_h = 20,
    button_h = 30,
    button_w = 90
};

const char *questions[]
{
    "2 + 2 = ?",
    "3 + 5 = ?",
    "2 + 7 = ?",
    "4 + 9 = ?",
    "3 + 1 = ?",
    "В чём смысл жизни?"
};

const char* answers[][4]
{
    {"3", "4", "1", "2"},
    {"8", "1", "4", "9"},
    {"1", "0", "9", "12"},
    {"13", "5", "-4", "1"},
    {"11", "4", "5", "2"},
    {"1", "2", "3", "4"}
};

int right_answers[]
{
    1,
    0,
    2,
    0,
    1,
    -1
};

int right_answers_many[][4]
{
    {-1,-1,-1,-1},
    {-1,-1,-1,-1},
    {-1,-1,-1,-1},
    {-1,-1,-1,-1},
    {-1,-1,-1,-1},
    {1, 1, 0, 1}
};

QuestionType question_types[]
{
    QuestionType::SINGLE_CHOICE,
    QuestionType::SINGLE_CHOICE,
    QuestionType::SINGLE_CHOICE,
    QuestionType::SINGLE_CHOICE,
    QuestionType::SINGLE_CHOICE,
    QuestionType::MANY_CHOICE
};

static void _check_callback(Fl_Widget *widget, void *user)
{
    // Меняем вопрос в любом случае
    Fl_Question** question = (Fl_Question**)user;
    if((*question)->check_answer() == 1)
    {
        printf("%s\n", "RIGHT!\n");
        counter++;
    }
    else
    {
        printf("%s\n", "WRONG!\n");
    }
    if(question_number == count_of_questions-1)
    {
        char *res = (char*)malloc(5);
        sprintf(res, "%d/%d", counter, count_of_questions);
        (*question)->set_question(res);
        return;
    }
    // Выставляем следующий вопрос
    (*question)->parent()->begin();
    // Удаляем предыдущий
    (*question)->delete_widgets();
    // Следующий
    question_number++;
    (*question)->set_question(questions[question_number]);
    if(question_types[question_number] == QuestionType::SINGLE_CHOICE)
    {
        Fl_Single_Choice_Question **s_question = (Fl_Single_Choice_Question**)question;
        (*s_question) = new Fl_Single_Choice_Question((Fl_Window*)((*question)->parent()), questions[question_number]);
        (*s_question)->init_widgets();
        (*s_question)->set_answers(answers[question_number][0], answers[question_number][1], answers[question_number][2], answers[question_number][3]);
        (*s_question)->set_right_answer(right_answers[question_number]);
    }
    if(question_types[question_number] == QuestionType::MANY_CHOICE)
    {
        Fl_Many_Choice_Question **m_question = (Fl_Many_Choice_Question**)question;
        (*m_question) = new Fl_Many_Choice_Question((Fl_Window*)((*question)->parent()), questions[question_number]);
        (*m_question)->init_widgets();
        (*m_question)->set_answers(answers[question_number][0], answers[question_number][1], answers[question_number][2], answers[question_number][3]);
        (*m_question)->set_right_answers(right_answers_many[question_number][0], right_answers_many[question_number][1], right_answers_many[question_number][2],right_answers_many[question_number][3]);
    }
    (*question)->parent()->end();
}

int main()
{
    int win_w = 640;
    int win_h = 480;

    Fl_Window *window = new Fl_Window(win_w, win_h, "TEST");
    Fl_Button *button = new Fl_Button(window->w() / 2 - button_w / 2, window->h() - button_h - spacing_h, button_w, button_h, "Check!");
    
    Fl_Single_Choice_Question *question = new Fl_Single_Choice_Question(window, questions[0]);
    question->set_answers(answers[0][0], answers[0][1], answers[0][2], answers[0][3]);
    question->set_right_answer(right_answers[0]);
    button->callback(_check_callback, &question);

    window->end();
    window->show();
    return Fl::run();
}
