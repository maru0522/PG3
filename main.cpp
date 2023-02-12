#include <stdio.h>
#include <string>
#include <iostream>
#include "Task.h"
#include <vector>

enum class Screen
{
    LOBBY,
    CREATE_TASK,
    EDIT_TASK,
    CREATE_PIC,
    EDIT_PIC,
};

bool CheckNumberOnly(const std::string& str) {
    for (char const& c : str) {
        if (std::isdigit(c) == 0) return false;
    }
    return true;
}

int main(void) {
    std::vector<Task> taskManager{};
    std::vector<Pic> picManager{};
    Screen screen{ Screen::LOBBY };

    std::string container{};
    bool isContinue{ true };

    while (isContinue)
    {
        if (screen == Screen::LOBBY) {
            std::cout << "==========================================" << std::endl;
            std::cout << "������e����͂��Ă��������B" << std::endl;
            std::cout << "1.�^�X�N��V�K�ǉ�" << std::endl;
            std::cout << "2.�^�X�N��ҏW" << std::endl;
            std::cout << "3.�S���҂�V�K�ǉ�" << std::endl;
            std::cout << "4.�S���҂�ҏW" << std::endl;
            std::cout << "5.�I��" << std::endl;
            std::cout << "==========================================" << std::endl;
            std::cin >> container;
            while (!CheckNumberOnly(container) || 5 < atoi(container.c_str()) || atoi(container.c_str()) < 1) {
                std::cout << "����͈͊O�̒l����͂��Ȃ��ł��������B" << std::endl;
                std::cout << "������x���͂��Ă��������B" << std::endl;
                std::cout << std::endl;
                std::cin >> container;
            }

            // ��ʕύX
            if (std::stoi(container) == 5) {
                // �I��
                isContinue = false;
                continue;
            }
            else {
                // �R���e�i�̒��g����Ƃѐ�ݒ�
                screen = static_cast<Screen>(std::stoi(container));
                continue;
            }
        }
        else if (screen == Screen::CREATE_TASK) {
            std::cout << "------------------------------------------" << std::endl;
            std::cout << "�^�X�N�̐V�K�ǉ����s���܂��B" << std::endl;
            std::cout << "�V�K�ǉ���r���Ŋ��p����ꍇ��\"c\"����͂��Ă��������B" << std::endl;
            std::cout << "------------------------------------------" << std::endl;
            std::cout << std::endl;

            // �ꎞ�ϐ�
            Task tempTask{};
            std::string tempStr{};

            // id�ݒ�
            std::cout << "------------------------------------------" << std::endl;
            std::cout << "�^�X�N��ID�𐔎��Őݒ肵�Ă��������B" << std::endl;
            std::cout << "------------------------------------------" << std::endl;
            std::cout << std::endl;
            std::cin >> tempStr;
            while (!CheckNumberOnly(tempStr)) {
                if (tempStr == "c") break;
                std::cout << "������������\"c\"�ȊO����͂��Ȃ��ł��������B" << std::endl;
                std::cout << "������x���͂��Ă��������B" << std::endl;
                std::cout << std::endl;
                std::cin >> tempStr;
            }
            if (tempStr == "c") {
                std::cout << "------------------------------------------" << std::endl;
                std::cout << "�^�X�N�̐V�K�ǉ������p���܂����B" << std::endl;
                std::cout << "------------------------------------------" << std::endl;
                std::cout << std::endl;
                screen = Screen::LOBBY; // ��ʕύX����
                continue;
            }
            tempTask.SetId(std::stoi(tempStr));
            std::cout << "------------------------------------------" << std::endl;
            std::cout << tempStr << "��ID�Ƃ��Đݒ肵�܂����B" << std::endl;
            std::cout << "------------------------------------------" << std::endl;

            // �S���Ґݒ�
            std::cout << "------------------------------------------" << std::endl;
            std::cout << "�^�X�N�̒S���҂�ݒ肵�Ă��������B" << std::endl;
            std::cout << "------------------------------------------" << std::endl;
            std::cout << std::endl;
            if (picManager.size() == 0) {
                std::cout << "++++++++++++++++++++++++++++++++++++++++++" << std::endl;
                std::cout << "�S���҂��ǉ�����Ă��܂���B" << std::endl;
                std::cout << "�����ŒS���҂̐V�K�ǉ����s���܂����H" << std::endl;
                std::cout << "�s��Ȃ��ꍇ\"0\"���A�s���ꍇ\"1\"����͂��Ă��������B" << std::endl;
                std::cout << "�����ŐV�K�ǉ����s��Ȃ��ꍇ�����I�Ƀ^�X�N�̐V�K�ǉ������p����܂��B" << std::endl;
                std::cout << "++++++++++++++++++++++++++++++++++++++++++" << std::endl;
                std::cout << std::endl;
                std::cin >> tempStr;
                while (!CheckNumberOnly(tempStr) || 2 < std::stoi(tempStr) || std::stoi(tempStr) < 0) {
                    std::cout << "����͈͊O�̒l����͂��Ȃ��ł��������B" << std::endl;
                    std::cout << "������x���͂��Ă��������B" << std::endl;
                    std::cout << std::endl;
                    std::cin >> tempStr;
                }
                if (std::stoi(tempStr)) {
                    std::cout << "++++++++++++++++++++++++++++++++++++++++++" << std::endl;
                    std::cout << "�S���҂̐V�K�ǉ����s���܂��B" << std::endl;
                    std::cout << "++++++++++++++++++++++++++++++++++++++++++" << std::endl;
                    // �ꎞ�ϐ�
                    Pic tempPic{};

                    // �S���҂�id�ݒ�
                    std::cout << "++++++++++++++++++++++++++++++++++++++++++" << std::endl;
                    std::cout << "�S���҂�ID�𐔎��Őݒ肵�Ă�������" << std::endl;
                    std::cout << "++++++++++++++++++++++++++++++++++++++++++" << std::endl;
                    std::cin >> tempPic.id_;
                    while (!CheckNumberOnly(tempStr)) {
                        if (tempStr == "c") break;
                        std::cout << "������������\"c\"�ȊO����͂��Ȃ��ł��������B" << std::endl;
                        std::cout << "������x���͂��Ă��������B" << std::endl;
                        std::cout << std::endl;
                        std::cin >> tempStr;
                    }
                    std::cout << "++++++++++++++++++++++++++++++++++++++++++" << std::endl;
                    std::cout << tempPic.id_ << "��ID�Ƃ��Đݒ肵�܂����B" << std::endl;
                    std::cout << "++++++++++++++++++++++++++++++++++++++++++" << std::endl;
                    std::cout << std::endl;

                    // �S���҂̖��O�ݒ�
                    std::cout << "++++++++++++++++++++++++++++++++++++++++++" << std::endl;
                    std::cout << "�S���҂̖��O��ݒ肵�Ă��������B" << std::endl;
                    std::cout << "++++++++++++++++++++++++++++++++++++++++++" << std::endl;
                    std::cin >> tempPic.name_;
                    std::cout << "++++++++++++++++++++++++++++++++++++++++++" << std::endl;
                    std::cout << tempPic.name_ << "�𖼑O�Ƃ��Đݒ肵�܂����B" << std::endl;
                    std::cout << "++++++++++++++++++++++++++++++++++++++++++" << std::endl;
                    std::cout << std::endl;

                    // �S���҂̃N���X�ԍ��ݒ�
                    std::cout << "++++++++++++++++++++++++++++++++++++++++++" << std::endl;
                    std::cout << "�S���҂̃N���X��ݒ肵�Ă��������B" << std::endl;
                    std::cout << "++++++++++++++++++++++++++++++++++++++++++" << std::endl;
                    std::cin >> tempPic.classroom_;
                    std::cout << "++++++++++++++++++++++++++++++++++++++++++" << std::endl;
                    std::cout << tempPic.classroom_ << "���N���X�Ƃ��Đݒ肵�܂����B" << std::endl;
                    std::cout << "++++++++++++++++++++++++++++++++++++++++++" << std::endl;
                    std::cout << std::endl;

                    picManager.emplace_back(tempPic);
                    std::cout << "++++++++++++++++++++++++++++++++++++++++++" << std::endl;
                    std::cout << "���L�̏��ŒS���҂�V�K�ǉ����܂����B" << std::endl;
                    tempPic.DrawAll();
                    std::cout << "++++++++++++++++++++++++++++++++++++++++++" << std::endl;
                    std::cout << std::endl;

                    tempTask.SetPic(tempPic);
                    std::cout << "------------------------------------------" << std::endl;
                    std::cout << tempPic.name_ << "��S���҂Ƃ��Đݒ肵�܂����B" << std::endl;
                    std::cout << "------------------------------------------" << std::endl;
                    std::cout << std::endl;
                }
                else {
                    std::cout << "------------------------------------------" << std::endl;
                    std::cout << "�^�X�N�̐V�K�ǉ������p���܂����B" << std::endl;
                    std::cout << "------------------------------------------" << std::endl;
                    std::cout << std::endl;
                    screen = Screen::LOBBY; // ��ʕύX����
                    continue;
                }
            }
            else {
                std::cout << "------------------------------------------" << std::endl;
                std::cout << "���ݒǉ�����Ă���S���҈ꗗ�ł��B" << std::endl;
                for (size_t i = 0; i < picManager.size(); i++) {
                    picManager.at(i).DrawAll();
                }
                std::cout << "------------------------------------------" << std::endl;

                // ID�ƍ�
                std::cout << "------------------------------------------" << std::endl;
                std::cout << "�ݒ肷��S���҂�ID����͂��Ă��������B" << std::endl;
                std::cout << "------------------------------------------" << std::endl;
                std::cin >> tempStr;
                if (tempStr == "c") {
                    std::cout << "------------------------------------------" << std::endl;
                    std::cout << "�^�X�N�̐V�K�ǉ���r�����p���܂����B" << std::endl;
                    std::cout << "------------------------------------------" << std::endl;
                    std::cout << std::endl;
                    screen = Screen::LOBBY; // ��ʕύX����
                    continue;
                }
                std::cout << "------------------------------------------" << std::endl;
                for (size_t i = 0; i < picManager.size(); i++) {
                    if (picManager.at(i).id_ == std::stoi(tempStr)) {
                        tempTask.SetPic(picManager.at(i));
                        picManager.at(i).DrawAll();
                        break;
                    }
                }
                std::cout << "��S���҂Ƃ��Đݒ肵�܂����B" << std::endl;
                std::cout << "------------------------------------------" << std::endl;
            }

            // �薼�ݒ�
            std::cout << "------------------------------------------" << std::endl;
            std::cout << "�^�X�N�̑薼��ݒ肵�Ă��������B" << std::endl;
            std::cout << "------------------------------------------" << std::endl;
            std::cout << std::endl;
            std::cin >> tempStr;
            if (tempStr == "c") {
                std::cout << "------------------------------------------" << std::endl;
                std::cout << "�^�X�N�̐V�K�ǉ������p���܂����B" << std::endl;
                std::cout << "------------------------------------------" << std::endl;
                std::cout << std::endl;
                screen = Screen::LOBBY; // ��ʕύX����
                continue;
            }
            tempTask.SetSubject(tempStr);
            std::cout << "------------------------------------------" << std::endl;
            std::cout << tempStr << "��薼�Ƃ��Đݒ肵�܂����B" << std::endl;
            std::cout << "------------------------------------------" << std::endl;

            // ���e�ݒ�
            std::cout << "------------------------------------------" << std::endl;
            std::cout << "�^�X�N�̓��e��ݒ肵�Ă��������B" << std::endl;
            std::cout << "------------------------------------------" << std::endl;
            std::cout << std::endl;
            std::cin >> tempStr;
            if (tempStr == "c") {
                std::cout << "------------------------------------------" << std::endl;
                std::cout << "�^�X�N�̐V�K�ǉ������p���܂����B" << std::endl;
                std::cout << "------------------------------------------" << std::endl;
                std::cout << std::endl;
                screen = Screen::LOBBY; // ��ʕύX����
                continue;
            }
            tempTask.SetDetail(tempStr);
            std::cout << "------------------------------------------" << std::endl;
            std::cout << tempStr << "����e�Ƃ��Đݒ肵�܂����B" << std::endl;
            std::cout << "------------------------------------------" << std::endl;

            // �D��x�ݒ�
            std::cout << "------------------------------------------" << std::endl;
            std::cout << "�^�X�N�̗D��x�����L�̒����琔���Őݒ肵�Ă��������B" << std::endl;
            std::cout << "1.LOW" << std::endl;
            std::cout << "2.MIDDLE" << std::endl;
            std::cout << "3.HIGH" << std::endl;
            std::cout << "4.TOP" << std::endl;
            std::cout << "------------------------------------------" << std::endl;
            std::cout << std::endl;
            std::cin >> tempStr;
            if (tempStr == "c") {
                std::cout << "------------------------------------------" << std::endl;
                std::cout << "�^�X�N�̐V�K�ǉ������p���܂����B" << std::endl;
                std::cout << "------------------------------------------" << std::endl;
                std::cout << std::endl;
                screen = Screen::LOBBY; // ��ʕύX����
                continue;
            }
            std::cout << "------------------------------------------" << std::endl;
            tempTask.SetPriority(static_cast<Priority>(std::stoi(tempStr) - 1));
            switch (static_cast<Priority>(std::stoi(tempStr) - 1))
            {
            case Priority::LOW:
                std::cout << "LOW";
                break;
            case Priority::MIDDLE:
                std::cout << "MIDDLE";
                break;
            case Priority::HIGH:
                std::cout << "HIGH";
                break;
            case Priority::TOP:
                std::cout << "TOP";
                break;
            default:
                tempTask.SetPriority(Priority::LOW);
                std::cout << "LOW";
                break;
            }
            std::cout << "��D��x�Ƃ��Đݒ肵�܂����B" << std::endl;
            std::cout << "------------------------------------------" << std::endl;

            // ���ؐݒ�
            std::cout << "------------------------------------------" << std::endl;
            std::cout << "�^�X�N�̒��؂�ݒ肵�Ă��������B" << std::endl;
            std::cout << "------------------------------------------" << std::endl;
            std::cout << std::endl;
            std::cin >> tempStr;
            if (tempStr == "c") {
                std::cout << "------------------------------------------" << std::endl;
                std::cout << "�^�X�N�̐V�K�ǉ������p���܂����B" << std::endl;
                std::cout << "------------------------------------------" << std::endl;
                std::cout << std::endl;
                screen = Screen::LOBBY; // ��ʕύX����
                continue;
            }
            tempTask.SetDeadline(tempStr);
            std::cout << "------------------------------------------" << std::endl;
            std::cout << tempStr << "����؂Ƃ��Đݒ肵�܂����B" << std::endl;
            std::cout << "------------------------------------------" << std::endl;
            std::cout << std::endl;

            // �ǉ�
            taskManager.emplace_back(tempTask);
            std::cout << "�V�K�^�X�N��ǉ����܂����B���L���o�^���e�ł��B" << std::endl;
            tempTask.DrawAll();
            std::cout << std::endl;

            screen = Screen::LOBBY; // ��ʕύX����
            continue;
        }
        else if (screen == Screen::EDIT_TASK) {
            std::string tempStr{};

            std::cout << "##########################################" << std::endl;
            std::cout << "�^�X�N�̕ҏW���s���܂��B" << std::endl;
            std::cout << "##########################################" << std::endl;
            std::cout << std::endl;

            if (taskManager.size() == 0) {
                std::cout << "##########################################" << std::endl;
                std::cout << "�^�X�N���ǉ�����Ă��Ȃ����ߕҏW�͏o���܂���B" << std::endl;
                std::cout << "##########################################" << std::endl;
                screen = Screen::LOBBY; // ��ʕύX����
                continue;
            }

            std::cout << "##########################################" << std::endl;
            std::cout << "���ݒǉ�����Ă���^�X�N�ꗗ�ł��B" << std::endl;
            for (size_t i = 0; i < taskManager.size(); i++) {
                taskManager.at(i).DrawIdentifier();
            }
            std::cout << "##########################################" << std::endl;
            std::cout << std::endl;

            // ID�ƍ�
            std::cout << "##########################################" << std::endl;
            std::cout << "�ҏW����^�X�N��ID����͂��Ă��������B" << std::endl;
            std::cout << "##########################################" << std::endl;

            std::cin >> tempStr;
            int32_t editId{};
            std::cout << "##########################################" << std::endl;
            for (size_t i = 0; i < picManager.size(); i++) {
                if (taskManager.at(i).GetId() == std::stoi(tempStr)) {
                    taskManager.at(i).DrawAll();
                    editId = (int32_t)i;
                    break;
                }
            }
            std::cout << "��ҏW���܂��B" << std::endl;
            std::cout << "##########################################" << std::endl;
            std::cout << std::endl;

            std::cout << "##########################################" << std::endl;
            std::cout << "�ǂ̗v�f��ҏW���邩���L�����Ƃɐ�������͂��Ă��������B" << std::endl;
            std::cout << "�I�������^�X�N��[�폜]����ꍇ��\"8\"��I�����Ă��������B" << std::endl;
            std::cout << "1.ID" << std::endl;
            std::cout << "2.�S����" << std::endl;
            std::cout << "3.�薼" << std::endl;
            std::cout << "4.���e" << std::endl;
            std::cout << "5.�D��x" << std::endl;
            std::cout << "6.����" << std::endl;
            std::cout << "7.�i��" << std::endl;
            std::cout << "8.�폜" << std::endl;
            std::cout << "##########################################" << std::endl;

            std::cin >> tempStr;
            while (!CheckNumberOnly(tempStr) || 8 < atoi(tempStr.c_str()) || atoi(tempStr.c_str()) < 1) {
                std::cout << "����͈͊O�̒l����͂��Ȃ��ł��������B" << std::endl;
                std::cout << "������x���͂��Ă��������B" << std::endl;
                std::cout << std::endl;
                std::cin >> tempStr;
            }

            std::cout << "##########################################" << std::endl;
            switch (std::stoi(tempStr))
            {
            case 1:
                std::cout << "�ύX���ID����͂��Ă��������B" << std::endl;
                std::cout << "##########################################" << std::endl;
                std::cout << std::endl;

                std::cin >> tempStr;
                while (!CheckNumberOnly(tempStr)) {
                    std::cout << "�����ȊO����͂��Ȃ��ł��������B" << std::endl;
                    std::cout << "������x���͂��Ă��������B" << std::endl;
                    std::cout << std::endl;
                    std::cin >> tempStr;
                }
                taskManager.at(editId).SetId(std::stoi(tempStr));
                std::cout << "##########################################" << std::endl;
                std::cout << "���L���ύX�x�̃^�X�N���ł��B" << std::endl;
                taskManager.at(editId).DrawAll();
                std::cout << "##########################################" << std::endl;
                break;
            case 2:
                std::cout << "�ύX��̒S���҂�ID�œ��͂��Ă��������B" << std::endl;
                std::cout << "##########################################" << std::endl;
                std::cout << std::endl;

                std::cout << "++++++++++++++++++++++++++++++++++++++++++" << std::endl;
                std::cout << "���ݒǉ�����Ă���S���҈ꗗ�ł��B" << std::endl;
                for (size_t i = 0; i < picManager.size(); i++) {
                    picManager.at(i).DrawAll();
                }
                std::cout << "++++++++++++++++++++++++++++++++++++++++++" << std::endl;
                std::cin >> tempStr;
                while (!CheckNumberOnly(tempStr)) {
                    std::cout << "�����ȊO����͂��Ȃ��ł��������B" << std::endl;
                    std::cout << "������x���͂��Ă��������B" << std::endl;
                    std::cout << std::endl;
                    std::cin >> tempStr;
                }
                for (size_t i = 0; i < picManager.size(); i++) {
                    if (picManager.at(i).id_ == std::stoi(tempStr)) {
                        taskManager.at(editId).SetPic(picManager.at(i));
                        break;
                    }
                }
                std::cout << "##########################################" << std::endl;
                std::cout << "���L���ύX�x�̃^�X�N���ł��B" << std::endl;
                taskManager.at(editId).DrawAll();
                std::cout << "##########################################" << std::endl;
                break;
            case 3:
                std::cout << "�ύX��̑薼����͂��Ă��������B" << std::endl;
                std::cout << "##########################################" << std::endl;
                std::cout << std::endl;

                std::cin >> tempStr;
                taskManager.at(editId).SetSubject(tempStr);
                std::cout << "##########################################" << std::endl;
                std::cout << "���L���ύX�x�̃^�X�N���ł��B" << std::endl;
                taskManager.at(editId).DrawAll();
                std::cout << "##########################################" << std::endl;
                break;
            case 4:
                std::cout << "�ύX��̓��e����͂��Ă��������B" << std::endl;
                std::cout << "##########################################" << std::endl;
                std::cout << std::endl;

                std::cin >> tempStr;
                taskManager.at(editId).SetDetail(tempStr);
                std::cout << "##########################################" << std::endl;
                std::cout << "���L���ύX�x�̃^�X�N���ł��B" << std::endl;
                taskManager.at(editId).DrawAll();
                std::cout << "##########################################" << std::endl;
                break;
            case 5:
                std::cout << "�ύX��̗D��x�����L�̒����琔���œ��͂��Ă��������B" << std::endl;
                std::cout << "1.LOW" << std::endl;
                std::cout << "2.MIDDLE" << std::endl;
                std::cout << "3.HIGH" << std::endl;
                std::cout << "4.TOP" << std::endl;
                std::cout << "##########################################" << std::endl;
                std::cout << std::endl;

                std::cin >> tempStr;
                taskManager.at(editId).SetDetail(tempStr);
                std::cout << "##########################################" << std::endl;
                std::cout << "���L���ύX�x�̃^�X�N���ł��B" << std::endl;
                taskManager.at(editId).DrawAll();
                std::cout << "##########################################" << std::endl;
                break;
            case 6:
                std::cout << "�ύX��̒��؂���͂��Ă��������B" << std::endl;
                std::cout << "##########################################" << std::endl;
                std::cout << std::endl;

                std::cin >> tempStr;
                taskManager.at(editId).SetDetail(tempStr);
                std::cout << "##########################################" << std::endl;
                std::cout << "���L���ύX�x�̃^�X�N���ł��B" << std::endl;
                taskManager.at(editId).DrawAll();
                std::cout << "##########################################" << std::endl;
                break;
            case 7:
                std::cout << "�ύX��̐i�����A�������Ȃ�\"0\"�������Ȃ�\"1\"����͂��Ă��������B" << std::endl;
                std::cout << "0.������" << std::endl;
                std::cout << "1.����" << std::endl;
                std::cout << "##########################################" << std::endl;
                std::cout << std::endl;

                std::cin >> tempStr;
                while (!CheckNumberOnly(tempStr) || 1 <= atoi(tempStr.c_str()) || atoi(tempStr.c_str()) <= 0) {
                    std::cout << "����͈͊O�̒l����͂��Ȃ��ł��������B" << std::endl;
                    std::cout << "������x���͂��Ă��������B" << std::endl;
                    std::cout << std::endl;
                    std::cin >> tempStr;
                }
                if (std::stoi(tempStr)) taskManager.at(editId).SetStatus(true);
                else taskManager.at(editId).SetStatus(false);
                std::cout << "##########################################" << std::endl;
                std::cout << "���L���ύX�x�̃^�X�N���ł��B" << std::endl;
                taskManager.at(editId).DrawAll();
                std::cout << "##########################################" << std::endl;
                break;
            case 8:
                taskManager.erase(taskManager.begin() + editId);
                std::cout << "##########################################" << std::endl;
                std::cout << "[�폜]����܂����B" << std::endl;
                std::cout << "##########################################" << std::endl;
                std::cout << std::endl;
                break;
            }
            std::cout << std::endl;
            std::cout << "##########################################" << std::endl;

            screen = Screen::LOBBY; // ��ʕύX����
            continue;
        }
        else if (screen == Screen::CREATE_PIC) {
            std::cout << "++++++++++++++++++++++++++++++++++++++++++" << std::endl;
            std::cout << "�S���҂̐V�K�ǉ����s���܂��B" << std::endl;
            std::cout << "++++++++++++++++++++++++++++++++++++++++++" << std::endl;
            // �ꎞ�ϐ�
            Pic tempPic{};
            std::string tempStr{};

            // �S���҂�id�ݒ�
            std::cout << "++++++++++++++++++++++++++++++++++++++++++" << std::endl;
            std::cout << "�S���҂�ID�𐔎��Őݒ肵�Ă�������" << std::endl;
            std::cout << "++++++++++++++++++++++++++++++++++++++++++" << std::endl;
            std::cin >> tempPic.id_;
            while (!CheckNumberOnly(tempStr)) {
                std::cout << "�����ȊO����͂��Ȃ��ł��������B" << std::endl;
                std::cout << "������x���͂��Ă��������B" << std::endl;
                std::cout << std::endl;
                std::cin >> tempStr;
            }
            std::cout << "++++++++++++++++++++++++++++++++++++++++++" << std::endl;
            std::cout << tempPic.id_ << "��ID�Ƃ��Đݒ肵�܂����B" << std::endl;
            std::cout << "++++++++++++++++++++++++++++++++++++++++++" << std::endl;
            std::cout << std::endl;

            // �S���҂̖��O�ݒ�
            std::cout << "++++++++++++++++++++++++++++++++++++++++++" << std::endl;
            std::cout << "�S���҂̖��O��ݒ肵�Ă��������B" << std::endl;
            std::cout << "++++++++++++++++++++++++++++++++++++++++++" << std::endl;
            std::cin >> tempPic.name_;
            std::cout << "++++++++++++++++++++++++++++++++++++++++++" << std::endl;
            std::cout << tempPic.name_ << "�𖼑O�Ƃ��Đݒ肵�܂����B" << std::endl;
            std::cout << "++++++++++++++++++++++++++++++++++++++++++" << std::endl;
            std::cout << std::endl;

            // �S���҂̃N���X�ԍ��ݒ�
            std::cout << "++++++++++++++++++++++++++++++++++++++++++" << std::endl;
            std::cout << "�S���҂̃N���X��ݒ肵�Ă��������B" << std::endl;
            std::cout << "++++++++++++++++++++++++++++++++++++++++++" << std::endl;
            std::cin >> tempPic.classroom_;
            std::cout << "++++++++++++++++++++++++++++++++++++++++++" << std::endl;
            std::cout << tempPic.classroom_ << "���N���X�Ƃ��Đݒ肵�܂����B" << std::endl;
            std::cout << "++++++++++++++++++++++++++++++++++++++++++" << std::endl;
            std::cout << std::endl;

            picManager.emplace_back(tempPic);
            std::cout << "++++++++++++++++++++++++++++++++++++++++++" << std::endl;
            std::cout << "���L�̏��ŒS���҂�V�K�ǉ����܂����B" << std::endl;
            tempPic.DrawAll();
            std::cout << "++++++++++++++++++++++++++++++++++++++++++" << std::endl;
            std::cout << std::endl;

            screen = Screen::LOBBY; // ��ʕύX����
            continue;
        }
        else if (screen == Screen::EDIT_PIC) {
            std::string tempStr{};

            std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
            std::cout << "�S���҂̕ҏW���s���܂��B" << std::endl;
            std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
            std::cout << std::endl;

            if (picManager.size() == 0) {
                std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
                std::cout << "�S���҂��ǉ�����Ă��Ȃ����ߕҏW�͏o���܂���B" << std::endl;
                std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
                screen = Screen::LOBBY; // ��ʕύX����
                continue;
            }

            std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
            std::cout << "���ݒǉ�����Ă���S���҈ꗗ�ł��B" << std::endl;
            for (size_t i = 0; i < picManager.size(); i++) {
                picManager.at(i).DrawAll();
            }
            std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;

            // ID�ƍ�
            std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
            std::cout << "�ҏW����S���҂�ID����͂��Ă��������B" << std::endl;
            std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;

            std::cin >> tempStr;
            while (!CheckNumberOnly(tempStr)) {
                std::cout << "�����ȊO����͂��Ȃ��ł��������B" << std::endl;
                std::cout << "������x���͂��Ă��������B" << std::endl;
                std::cout << std::endl;
                std::cin >> tempStr;
            }

            int32_t editId{};
            std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
            for (size_t i = 0; i < picManager.size(); i++) {
                if (picManager.at(i).id_ == std::stoi(tempStr)) {
                    picManager.at(i).DrawAll();
                    editId = (int32_t)i;
                    break;
                }
            }
            std::cout << "��ҏW���܂��B" << std::endl;
            std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
            std::cout << std::endl;

            std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
            std::cout << "�ǂ̗v�f��ҏW���邩���L�����Ƃɐ�������͂��Ă��������B" << std::endl;
            std::cout << "�I�������S���҂�[�폜]����ꍇ��\"4\"��I�����Ă��������B" << std::endl;
            std::cout << "1.ID" << std::endl;
            std::cout << "2.���O" << std::endl;
            std::cout << "3.�N���X" << std::endl;
            std::cout << "4.�폜" << std::endl;
            std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;

            std::cin >> tempStr;
            while (!CheckNumberOnly(tempStr) || 4 < atoi(tempStr.c_str()) || atoi(tempStr.c_str()) < 1) {
                std::cout << "����͈͊O�̒l����͂��Ȃ��ł��������B" << std::endl;
                std::cout << "������x���͂��Ă��������B" << std::endl;
                std::cout << std::endl;
                std::cin >> tempStr;
            }

            switch (std::stoi(tempStr))
            {
            case 1:
                std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
                std::cout << "�ύX���ID�𐔎��œ��͂��Ă��������B" << std::endl;
                std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
                std::cout << std::endl;

                std::cin >> tempStr;
                while (!CheckNumberOnly(tempStr)) {
                    std::cout << "�����ȊO����͂��Ȃ��ł��������B" << std::endl;
                    std::cout << "������x���͂��Ă��������B" << std::endl;
                    std::cout << std::endl;
                    std::cin >> tempStr;
                }
                picManager.at(editId).id_ = std::stoi(tempStr);
                std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
                std::cout << "���L���ύX��̒S���ҏ��ł��B" << std::endl;
                picManager.at(editId).DrawAll();
                std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
                std::cout << std::endl;
                break;
            case 2:
                std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
                std::cout << "�ύX��̖��O����͂��Ă��������B" << std::endl;
                std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
                std::cout << std::endl;

                std::cin >> tempStr;

                picManager.at(editId).name_ = tempStr;
                std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
                std::cout << "���L���ύX��̒S���ҏ��ł��B" << std::endl;
                picManager.at(editId).DrawAll();
                std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
                std::cout << std::endl;
                break;
            case 3:
                std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
                std::cout << "�ύX��̃N���X����͂��Ă��������B" << std::endl;
                std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
                std::cout << std::endl;

                std::cin >> tempStr;

                picManager.at(editId).classroom_ = tempStr;
                std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
                std::cout << "���L���ύX��̒S���ҏ��ł��B" << std::endl;
                picManager.at(editId).DrawAll();
                std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
                std::cout << std::endl;
                break;
            case 4:
                picManager.erase(picManager.begin() + editId);
                std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
                std::cout << "[�폜]����܂����B" << std::endl;
                std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
                std::cout << std::endl;
                break;
            }
            screen = Screen::LOBBY; // ��ʕύX����
            continue;
        }
    }

    return 0;
}