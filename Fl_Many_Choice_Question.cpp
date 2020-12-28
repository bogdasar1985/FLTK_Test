#include "Fl_Many_Choice_Question.hpp"
Fl_Many_Choice_Question::Fl_Many_Choice_Question(Fl_Window *window, const char *text_question) : Fl_Question(window, text_question, QuestionType::MANY_CHOICE) {};

int Fl_Many_Choice_Question::check_answer()
{
    for(int i = 0; i < 4; i++)
    {
        if(answers[i]->value() != right_answers[i])
        {
            return 0;
        }
    }
    return 1;
};

void Fl_Many_Choice_Question::set_answers(const char* answer1, const char* answer2, const char* answer3, const char* answer4)
{
    for(int i = 0; i < 4; i++)
    {
        answers[i]->hide();
    }
    answers[0]->label(answer1);
    answers[1]->label(answer2);
    answers[2]->label(answer3);
    answers[3]->label(answer4);
    for(int i = 0; i < 4; i++)
    {
        answers[i]->show();
    }
};

void Fl_Many_Choice_Question::set_right_answers(int answer1, int answer2, int answer3, int answer4)
{
    right_answers[0] = answer1;
    right_answers[1] = answer2;
    right_answers[2] = answer3;
    right_answers[3] = answer4;
};

void Fl_Many_Choice_Question::delete_widgets()
{
    for(int i = 0; i < 4; i++)
    {
        Fl::delete_widget(answers[i]);
    }
}

void Fl_Many_Choice_Question::init_widgets()
{
    int rb_x = spacing_w;
    for(int i = 0; i < 2; i++)
    {
        answers[i] = new Fl_Check_Button(rb_x, text_display_h + spacing_h * 2, radio_round_button_w, radio_round_button_h, nullptr);
        rb_x += text_display_w / 2 - spacing_w;
    }

    rb_x = spacing_w;
    for(int i = 2; i < 4; i++)
    {
        answers[i] = new Fl_Check_Button(rb_x, text_display_h + spacing_h * 4, radio_round_button_w, radio_round_button_h, nullptr);
        rb_x += text_display_w / 2- spacing_w;
    }
}