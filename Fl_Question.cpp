#include "Fl_Question.hpp"
Fl_Question::Fl_Question(const Fl_Window* window, const char* question_text, QuestionType qt) : Fl_Group(0, 0, window->w(), window->h(), nullptr)
{
    question = new Fl_Box(spacing_w, spacing_h, text_display_w, text_display_h, nullptr);
    question->box(FL_BORDER_BOX);
    question->label(question_text);
    question->labelsize(14);
    question_type = qt;
    //enter = new Fl_Button(window->w() / 2 - button_w / 2, window->h() - button_h - spacing_h, button_w, button_h, "Check!");
}

void Fl_Question::set_question(const char* q)
{
    question->label(q);
}

QuestionType Fl_Question::get_type()
{
    return question_type;
}