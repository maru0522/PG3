#include <stdio.h>
#include <Windows.h>
#include <time.h>
#include <iostream>
#include <string>
#include "list.h"

enum class MState
{
    BEGIN,
    DISPLAY,
    DISPLAY_ALL,
    DISPLAY_PART,
    INSERT,
    EDIT,
    REMOVE,
    SWAP
};

bool IsNumberOnly(const std::string& str) {
    for (char const& c : str) {
        if (std::isdigit(c) == 0) return false;
    }
    return true;
}

int main(void) {
    MState state{ MState::BEGIN };
    std::string tmpStr;
    List list;

    list.Append("banana");

    while (1) {
        if (state == MState::BEGIN) {
            std::cout << "[�v�f�̑���]" << std::endl;
            std::cout << "1.�v�f�̕\��" << std::endl;
            std::cout << "2.�v�f�̑}��" << std::endl;
            std::cout << "3.�v�f�̕ҏW" << std::endl;
            std::cout << "4.�v�f�̍폜" << std::endl;
            std::cout << std::endl;
            std::cout << "------------------------------------" << std::endl;
            std::cout << "�����I�����Ă�������" << std::endl;
            std::cout << "_";
            std::cin >> tmpStr;
            std::cout << std::endl;
            if (IsNumberOnly(tmpStr)) {
                if (5 < atoi(tmpStr.c_str()) || atoi(tmpStr.c_str()) < 1) {
                    std::cout << std::endl;
                    std::cout << "����͈͊O�̒l����͂��Ȃ��ł�������" << std::endl;
                    std::cout << std::endl;
                }
                else {
                    switch (atoi(tmpStr.c_str()))
                    {
                    case 1:
                        state = MState::DISPLAY;
                        break;
                    case 2:
                        state = MState::INSERT;
                        break;
                    case 3:
                        state = MState::EDIT;
                        break;
                    case 4:
                        state = MState::REMOVE;
                        break;
                    }
                }
            }
            else {
                std::cout << std::endl;
                std::cout << "�����ȊO����͂��Ȃ��ł�������" << std::endl;
                std::cout << std::endl;
            }
        }
        else if (state == MState::DISPLAY) {
            std::cout << "[�v�f�̕\��]" << std::endl;
            std::cout << "1.�v�f�̈ꗗ�\��" << std::endl;
            std::cout << "2.���Ԃ��w�肵�ėv�f��\��" << std::endl;
            std::cout << "9.�v�f����ɖ߂�" << std::endl;
            std::cout << std::endl;
            std::cout << "�����I�����Ă�������" << std::endl;
            std::cout << "_";
            std::cin >> tmpStr;
            std::cout << std::endl;
            if (IsNumberOnly(tmpStr)) {
                if (atoi(tmpStr.c_str()) < 1 || 2 < atoi(tmpStr.c_str()) && atoi(tmpStr.c_str()) < 9 || 9 < atoi(tmpStr.c_str())) {
                    std::cout << std::endl;
                    std::cout << "����͈͊O�̒l����͂��Ȃ��ł�������" << std::endl;
                    std::cout << std::endl;
                }
                else {
                    switch (atoi(tmpStr.c_str()))
                    {
                    case 1:
                        state = MState::DISPLAY_ALL;
                        break;
                    case 2:
                        state = MState::DISPLAY_PART;
                        break;
                    case 9:
                        state = MState::BEGIN;
                        break;
                    }
                }
            }
            else {
                std::cout << std::endl;
                std::cout << "�����ȊO����͂��Ȃ��ł�������" << std::endl;
                std::cout << std::endl;
            }
        }
        else if (state == MState::DISPLAY_ALL) {
            std::cout << "[�v�f�̈ꗗ�\��]" << std::endl;
            std::cout << "�v�f�ꗗ:{" << std::endl;
            for (size_t i = 1; i < list.Size(); i++) {
                std::cout << " " << i << ": " << "\"" << list.GetValue(i - 1) << "\"" << std::endl;
            }
            std::cout << "}" << std::endl;
            std::cout << std::endl;
            std::cout << "�v�f��: " << list.Size() - 1 << std::endl;
            std::cout << std::endl;
            std::cout << "------------------------------------" << std::endl;
            std::cout << std::endl;
            std::cout << "1.�v�f�̕\���ɖ߂�" << std::endl;
            std::cout << "2.�v�f�̑���ɖ߂�" << std::endl;
            std::cout << "_";
            std::cin >> tmpStr;
            std::cout << std::endl;
            if (IsNumberOnly(tmpStr)) {
                if (atoi(tmpStr.c_str()) < 1 || 2 < atoi(tmpStr.c_str())) {
                    std::cout << std::endl;
                    std::cout << "����͈͊O�̒l����͂��Ȃ��ł�������" << std::endl;
                    std::cout << std::endl;
                }
                else {
                    switch (atoi(tmpStr.c_str()))
                    {
                    case 1:
                        state = MState::DISPLAY;
                        break;
                    case 2:
                        state = MState::BEGIN;
                        break;
                    }
                }
            }
            else {
                std::cout << std::endl;
                std::cout << "�����ȊO����͂��Ȃ��ł�������" << std::endl;
                std::cout << std::endl;
            }
        }
        else if (state == MState::DISPLAY_PART) {
            std::cout << "[���Ԃ��w�肵�ėv�f��\��]" << std::endl;
            std::cout << "�\���������v�f�̏��Ԃ��w�肵�Ă��������B" << std::endl;
            std::cout << "_";
            std::cin >> tmpStr;
            std::cout << std::endl;
            if (IsNumberOnly(tmpStr)) {
                if (atoi(tmpStr.c_str()) < 0 || list.Size() - 1 < atoi(tmpStr.c_str())) {
                    std::cout << std::endl;
                    std::cout << "����͈͊O�̒l����͂��Ȃ��ł�������" << std::endl;
                    std::cout << std::endl;
                }
                else {
                    std::cout << tmpStr.c_str() << ": " << list.GetValue(atoi(tmpStr.c_str()) - 1) << std::endl;
                    std::cout << std::endl;
                }
            }
            else {
                std::cout << std::endl;
                std::cout << "�����ȊO����͂��Ȃ��ł�������" << std::endl;
                std::cout << std::endl;
            }
            std::cout << "------------------------------------" << std::endl;
            std::cout << std::endl;
            std::cout << "1.�v�f�̕\���ɖ߂�" << std::endl;
            std::cout << "2.�v�f�̑���ɖ߂�" << std::endl;
            std::cout << "_";
            std::cin >> tmpStr;
            std::cout << std::endl;
            if (IsNumberOnly(tmpStr)) {
                if (atoi(tmpStr.c_str()) < 1 || 2 < atoi(tmpStr.c_str())) {
                    std::cout << std::endl;
                    std::cout << "����͈͊O�̒l����͂��Ȃ��ł�������" << std::endl;
                    std::cout << std::endl;
                }
                else {
                    switch (atoi(tmpStr.c_str()))
                    {
                    case 1:
                        state = MState::DISPLAY;
                        break;
                    case 2:
                        state = MState::BEGIN;
                        break;
                    }
                }
            }
            else {
                std::cout << std::endl;
                std::cout << "�����ȊO����͂��Ȃ��ł�������" << std::endl;
                std::cout << std::endl;
            }
        }
        else if (state == MState::INSERT) {
        std::cout << "[���X�g�v�f�̑}��]" << std::endl;
        std::cout << "�v�f��ǉ�����ꏊ���w�肵�Ă�������" << std::endl;
        std::cout << "_";
        std::cin >> tmpStr;
        std::cout << std::endl;
        if (IsNumberOnly(tmpStr)) {
            if (atoi(tmpStr.c_str()) < 0 || list.Size() - 1 < atoi(tmpStr.c_str())) {
                std::cout << std::endl;
                std::cout << atoi(tmpStr.c_str()) << "�Ԗڂ̗v�f�͑��݂��܂���B�B" << std::endl;
                std::cout << std::endl;
            }
            else {
                std::cout << atoi(tmpStr.c_str()) << "�ǉ�����v�f�̒l����͂��Ă��������B" << std::endl;
            }
        }
        else {
            std::cout << std::endl;
            std::cout << "�����ȊO����͂��Ȃ��ł�������" << std::endl;
            std::cout << std::endl;
        }
        int tmpNum = atoi(tmpStr.c_str());

        std::cout << "_";
        std::cin >> tmpStr;
        std::cout << std::endl;
        std::cout << "�v�f\"" << tmpStr << "\"��" << tmpNum << "�ɑ}������܂���" << std::endl;
        std::cout << std::endl;
        state = MState::BEGIN;
        }
        else if (state == MState::EDIT) {
            std::cout << "[�v�f�̕ҏW]" << std::endl;
            std::cout << "�ҏW�������v�f�̔ԍ����w�肵�Ă��������B" << std::endl;
            std::cout << "_";
            std::cin >> tmpStr;
            std::cout << std::endl;
            if (IsNumberOnly(tmpStr)) {
                if (atoi(tmpStr.c_str()) < 0 || /*size*/ 9 < atoi(tmpStr.c_str())) {
                    std::cout << std::endl;
                    std::cout << atoi(tmpStr.c_str()) << "�Ԗڂ̗v�f��������܂���ł����B" << std::endl;
                    std::cout << std::endl;
                }
                else {
                    std::cout << atoi(tmpStr.c_str()) << "�Ԗڂ̗v�f�̕ύX����l����͂��Ă��������B" << std::endl;
                }
            }
            else {
                std::cout << std::endl;
                std::cout << "�����ȊO����͂��Ȃ��ł�������" << std::endl;
                std::cout << std::endl;
            }
            int tmpNum = atoi(tmpStr.c_str());

            std::cout << "_";
            std::cin >> tmpStr;
            std::cout << std::endl;
            std::cout << tmpNum << "�Ԗڂ̗v�f�̒l��\"" << tmpStr << "\"�ɕύX����܂���" << std::endl;
            std::cout << std::endl;
            state = MState::BEGIN;
        }
        else if (state == MState::REMOVE) {
            std::cout << "[�v�f�̍폜]" << std::endl;
            std::cout << "�폜�������v�f�̔ԍ����w�肵�Ă��������B" << std::endl;
            std::cout << "_";
            std::cin >> tmpStr;
            std::cout << std::endl;
            if (IsNumberOnly(tmpStr)) {
                if (atoi(tmpStr.c_str()) < 0 || list.Size() - 1 < atoi(tmpStr.c_str())) {
                    std::cout << std::endl;
                    std::cout << atoi(tmpStr.c_str()) << "�Ԗڂ̗v�f��������܂���ł����B�B" << std::endl;
                    std::cout << std::endl;
                }
                else {
                    std::cout << atoi(tmpStr.c_str()) << "�Ԗڂ̗v�f���폜���܂����B" << std::endl;
                    std::cout << std::endl;
                    list.Remove(atoi(tmpStr.c_str()));
                }
            }
            else {
                std::cout << std::endl;
                std::cout << "�����ȊO����͂��Ȃ��ł�������" << std::endl;
                std::cout << std::endl;
            }
            state = MState::BEGIN;
        }
    }
}