#pragma once
#include "Pic.h"

enum class Priority
{
    LOW,
    MIDDLE,
    HIGH,
    TOP,
};

class Task
{
private:
    int32_t id_{};
    Pic pic_{};
    std::string subject_{};
    std::string detail_{};
    Priority priority_{};
    std::string deadline_{};
    bool status_{};

public:
    Task(void) {}
    Task(int32_t id, Pic pic, std::string subject, std::string detail, Priority priority, std::string deadline);

    inline void SetId(int32_t id) { id_ = id; }
    inline void SetPic(Pic pic) { pic_ = pic; }
    void SetPic(int32_t pic_id, std::string name, std::string classroom);
    inline void SetSubject(std::string subject) { subject_ = subject; }
    inline void SetDetail(std::string detail) { detail_ = detail; }
    inline void SetPriority(Priority priority) { priority_ = priority; }
    inline void SetDeadline(std::string deadline) { deadline_ = deadline; }
    inline void SetStatus(bool status) { status_ = status; }

    inline int32_t GetId(void) { return id_; }

    void DrawIdentifier(void);
    void DrawAll(void);
};

