#ifndef FL_SINGLE_CHOICE_QUESTION
#define FL_SINGLE_CHOICE_QUESTION
#include "Fl_Question.hpp"
#include <Fl/Fl_Radio_Round_Button.H>
class Fl_Single_Choice_Question : public Fl_Question
{
public:
    Fl_Single_Choice_Question(Fl_Window *window, const char *text_question);
    virtual int check_answer();
    virtual void reset_answers();
    void set_answers(const char* answer1, const char* answer2, const char* answer3, const char* answer4);
    void set_right_answer(int ra);
    void delete_widgets();
    void init_widgets();
private:
    Fl_Radio_Round_Button *answers[4];
    int right_answ; //from 0 to 3
};
#endif