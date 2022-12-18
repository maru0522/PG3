#include "list.h"
#include <stdio.h>
#include <string.h>
#include <iostream>

List::List(void)
{
    first_ = NewCell();
    size_++;
}

List::~List(void)
{
    CELL* cell = first_;
    while (cell != nullptr) {
        CELL* tmp = cell->next;
        delete cell;
        cell = tmp;
    }
}

void List::Append(const char* buff)
{
    Insert(buff, size_);
}

void List::Insert(const char* buff, int idx)
{
    if (size_ < idx) {
        return;
    }

    CELL* cell = Get(idx);
    CELL* newCell = NewCell();

    strcpy_s(newCell->str, 8, buff);

    // 先頭ノードの場合
    if (cell == first_) {
        cell->prev = newCell;
        newCell->next = cell;
        first_ = newCell;
    }
    // 終端ノードの場合
    else if (size_ == idx) {
        cell->next = newCell;
        newCell->prev = cell;
    }
    // 中間にあるノードの場合
    else {
        CELL* prevCell = cell->prev;
        // 前のセルとの接続
        prevCell->next = newCell;
        newCell->prev = prevCell;
        // 後ろのセルとの接続
        cell->prev = newCell;
        newCell->next = cell;
    }
    size_++;
}

void List::Remove(int idx) {
    if (size_ <= idx) {
        return;
    }
    CELL* cell = Get(idx);
    if (idx == 0) {
        CELL* nextCell = cell->next;
        nextCell->prev = nullptr;
        first_ = nextCell;
    }
    else if (idx == size_ - 1) {
        CELL* prevCell = cell->prev;
        prevCell->next = nullptr;
    }
    else {
        CELL* prevCell = cell->prev;
        CELL* nextCell = cell->next;
        prevCell->next = nextCell;
        nextCell->prev = prevCell;
    }
    delete cell;
    size_--;
}

CELL* List::Get(int idx) const
{
    CELL* cell = first_;
    for (int i = 0; i < idx; i++) {
        if (!cell->next) {
            break;
        }
        cell = cell->next;
    }

    return cell;
}

const char* List::GetValue(int idx) const
{
    return Get(idx)->str;
}

const void List::SetValue(const char* buff, int idx)
{
    strcpy_s(Get(idx)->str, 8, buff);
}

void List::Display()
{
    CELL* cell = first_;
    int no = 0;
    while (cell->next != nullptr) {
        cell = cell->next;
        printf("%d", no);
        printf("%p", cell->prev);
        printf("%s", cell->str);
        printf("(%p)", cell);
        printf("%p\n", cell->next);
        no++;
    }
}

CELL* List::NewCell(void)
{
    CELL* newCell = new CELL;
    newCell->prev = nullptr;
    newCell->next = nullptr;

    return newCell;
}
