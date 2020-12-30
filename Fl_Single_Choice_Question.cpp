#include "Fl_Single_Choice_Question.hpp"
Fl_Single_Choice_Question::Fl_Single_Choice_Question(
                                                        Fl_Window *window, 
                                                        const char *text_question
                                                    ) 
                                                    : Fl_Question(
                                                        window, 
                                                        text_question,
                                                        QuestionType::SINGLE_CHOICE
                                                    )
{
    int rb_x = spacing_w;
    for(int i = 0; i < 2; i++)
    {
        answers[i] = new Fl_Radio_Round_Button(rb_x, text_display_h + spacing_h * 2, radio_round_button_w, radio_round_button_h, nullptr);
        rb_x += text_display_w / 2 - spacing_w;
    }

    rb_x = spacing_w;
    for(int i = 2; i < 4; i++)
    {
        answers[i] = new Fl_Radio_Round_Button(rb_x, text_display_h + spacing_h * 4, radio_round_button_w, radio_round_button_h, nullptr);
        rb_x += text_display_w / 2- spacing_w;
    }
};

int Fl_Single_Choice_Question::check_answer()
{
    int count = 0;  // Кол-во выбранных ответов.
    for(int i = 0; i < 4; i++)
    {
        if(answers[i]->value() == 1)
        {
            count++;
        }
    }
    if(count == 0)
    {
        return -1;  // Если ни одного ответа не выбрано
    }
    if((this->answers[this->right_answ]->value() == 1))
    {
        //this->answers[this->right_answ]->value(0);
        return 1;
    }
    return 0;
}

void Fl_Single_Choice_Question::reset_answers()
{
    for(int i = 0; i < 4; i++)
    {
        if(this->answers[i]->value())
        {
            this->answers[i]->value(0);
        }
    }
}

void Fl_Single_Choice_Question::set_answers(const char* answer1, const char* answer2, const char* answer3, const char* answer4)
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
}

void Fl_Single_Choice_Question::set_right_answer(int ra)
{
    right_answ = ra;
}

void Fl_Single_Choice_Question::delete_widgets()
{
    for(int i = 0; i < 4; i++)
    {
        Fl::delete_widget(answers[i]);
    }
}

void Fl_Single_Choice_Question::init_widgets()
{
    int rb_x = spacing_w;
    for(int i = 0; i < 2; i++)
    {
        answers[i] = new Fl_Radio_Round_Button(rb_x, text_display_h + spacing_h * 2, radio_round_button_w, radio_round_button_h, nullptr);
        rb_x += text_display_w / 2 - spacing_w;
    }

    rb_x = spacing_w;
    for(int i = 2; i < 4; i++)
    {
        answers[i] = new Fl_Radio_Round_Button(rb_x, text_display_h + spacing_h * 4, radio_round_button_w, radio_round_button_h, nullptr);
        rb_x += text_display_w / 2- spacing_w;
    }
}