#ifndef FL_QUESTION
#define FL_QUESTION
#include <Fl/Fl.H>
#include <Fl/Fl_Window.H>
#include <Fl/Fl_Button.H>
#include <Fl/Fl_Box.H>
#include <stdio.h>
enum class QuestionType
{
    SINGLE_CHOICE,
    MANY_CHOICE,
    TEXT_FIELD
};

class Fl_Question : public Fl_Group
{
public:
    Fl_Question(const Fl_Window* window, const char *question_text, QuestionType qt);
    virtual int check_answer() = 0;
    virtual void delete_widgets() = 0;
    virtual void init_widgets() = 0;
    void set_question(const char* q);
    QuestionType get_type();
protected:
    Fl_Box *question;
    QuestionType question_type;
    //Fl_Button *enter;
    enum
    {
        spacing_w = 20,
        spacing_h = 20,
        text_display_w = 940,
        text_display_h = 50,
        radio_round_button_w = 20,
        radio_round_button_h = 20,
        button_h = 30,
        button_w = 90
    };
};
#endif