#include "Fl_Single_Choice_Question.hpp"
Fl_Single_Choice_Question::Fl_Single_Choice_Question(
                                                        Fl_Window *window, 
                                                        const char *text_question, 
                                                        const char* answer1, 
                                                        const char* answer2, 
                                                        const char* answer3, 
                                                        const char* answer4,
                                                        int right_answ
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

    answers[0]->label(answer1);
    answers[1]->label(answer2);
    answers[2]->label(answer3);
    answers[3]->label(answer4);
    this->right_answ = right_answ;

};

int Fl_Single_Choice_Question::check_answer()
{
    
    if((this->answers[this->right_answ]->value() == 1))
    {
        return 1;
    }
    return 0;
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