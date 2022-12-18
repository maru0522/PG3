#pragma once
#include <stdio.h>
#include <stdlib.h>

typedef struct CELL
{
    char str[8];
    CELL* prev;
    CELL* next;
};

class List
{
public: // 関数
    List(void);
    ~List(void);

    void Append(const char* buff);
    void Insert(const char* buff, int idx);
    void Remove(int idx);

    CELL* Get(int idx) const;
    const char* GetValue(int idx) const;
    const void SetValue(const char* buff, int idx);

    void Display();

    const size_t Size(void) const { return size_; }
    CELL* GetFirst(void) { return first_; }

private:
    CELL* NewCell(void);

private: // 変数
    CELL* first_{ nullptr };
    size_t size_{ 0 };
};