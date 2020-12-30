#ifndef FL_MANY_CHOICE_QUESTION
#define FL_MANY_CHOICE_QUESTION
#include "Fl_Question.hpp"
#include <Fl/Fl_Check_Button.H>
class Fl_Many_Choice_Question : public Fl_Question
{
public:
    Fl_Many_Choice_Question(Fl_Window *window, const char *text_question);
    virtual int check_answer();
    virtual void reset_answers();
    void set_answers(const char* answer1, const char* answer2, const char* answer3, const char* answer4);
    void set_right_answers(int answer1, int answer2, int answer3, int answer4);
    void delete_widgets();
    void init_widgets();
private:
    Fl_Check_Button *answers[4];
    int right_answers[4]; // answers from 0 to 3, RIGHT if 1, WRONG if 0.
};
#endif