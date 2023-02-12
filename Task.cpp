#include "Task.h"
#include <iostream>

Task::Task(int32_t id, Pic pic, std::string subject, std::string detail, Priority priority, std::string deadline)
    : id_(id), pic_(pic), subject_(subject), detail_(detail), priority_(priority), deadline_(deadline)
{
}

void Task::SetPic(int32_t pic_id, std::string name, std::string classroom)
{
    pic_.id_ = pic_id;
    pic_.name_ = name;
    pic_.classroom_ = classroom;
}

void Task::DrawIdentifier(void)
{
    std::cout << "TaskID : " << id_ << ", ‘è–¼ : " << subject_ << ", ’S“–ŽÒ : " << pic_.name_ << std::endl;
}

void Task::DrawAll(void)
{
    std::cout << "=============== ƒ^ƒXƒNî•ñ ===============" << std::endl;
    std::cout << "’S“–ŽÒ : ";
    pic_.DrawAll();
    std::cout << "‘è–¼ : " << subject_ << std::endl;
    std::cout << "“à—e : " << detail_ << std::endl;
    std::cout << "—Dæ“x : " ;
    switch (priority_)
    {
    case Priority::LOW:
        std::cout << "LOW" << std::endl;
        break;
    case Priority::MIDDLE:
        std::cout << "MIDDLE" << std::endl;
        break;
    case Priority::HIGH:
        std::cout << "HIGH" << std::endl;
        break;
    case Priority::TOP:
        std::cout << "TOP" << std::endl;
        break;
    }
    std::cout << "’÷Ø : " << deadline_ << std::endl;
    std::cout << "i’» : ";
    if (status_) std::cout << "Š®—¹" << std::endl;
    else std::cout << "–¢Š®—¹" << std::endl;
    std::cout << "==========================================" << std::endl;
}
