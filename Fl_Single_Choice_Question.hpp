#ifndef FL_SINGLE_CHOICE_QUESTION
#define FL_SINGLE_CHOICE_QUESTION
#include "Fl_Question.hpp" 
class Fl_Single_Choice_Question : public Fl_Question
{
public:
    Fl_Single_Choice_Question(Fl_Window *window, const char *text_question, const char* answer1, const char* answer2, const char* answer3, const char* answer4, int right_answ);
    virtual int check_answer();
    void set_answers(const char* answer1, const char* answer2, const char* answer3, const char* answer4);
    void set_right_answer(int ra);
private:
    Fl_Radio_Round_Button *answers[4];
    int right_answ; //from 0 to 3
};
#endif