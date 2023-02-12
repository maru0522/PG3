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
            std::cout << "操作内容を入力してください。" << std::endl;
            std::cout << "1.タスクを新規追加" << std::endl;
            std::cout << "2.タスクを編集" << std::endl;
            std::cout << "3.担当者を新規追加" << std::endl;
            std::cout << "4.担当者を編集" << std::endl;
            std::cout << "5.終了" << std::endl;
            std::cout << "==========================================" << std::endl;
            std::cin >> container;
            while (!CheckNumberOnly(container) || 5 < atoi(container.c_str()) || atoi(container.c_str()) < 1) {
                std::cout << "操作範囲外の値を入力しないでください。" << std::endl;
                std::cout << "もう一度入力してください。" << std::endl;
                std::cout << std::endl;
                std::cin >> container;
            }

            // 画面変更
            if (std::stoi(container) == 5) {
                // 終了
                isContinue = false;
                continue;
            }
            else {
                // コンテナの中身からとび先設定
                screen = static_cast<Screen>(std::stoi(container));
                continue;
            }
        }
        else if (screen == Screen::CREATE_TASK) {
            std::cout << "------------------------------------------" << std::endl;
            std::cout << "タスクの新規追加を行います。" << std::endl;
            std::cout << "新規追加を途中で棄却する場合は\"c\"を入力してください。" << std::endl;
            std::cout << "------------------------------------------" << std::endl;
            std::cout << std::endl;

            // 一時変数
            Task tempTask{};
            std::string tempStr{};

            // id設定
            std::cout << "------------------------------------------" << std::endl;
            std::cout << "タスクのIDを数字で設定してください。" << std::endl;
            std::cout << "------------------------------------------" << std::endl;
            std::cout << std::endl;
            std::cin >> tempStr;
            while (!CheckNumberOnly(tempStr)) {
                if (tempStr == "c") break;
                std::cout << "数字もしくは\"c\"以外を入力しないでください。" << std::endl;
                std::cout << "もう一度入力してください。" << std::endl;
                std::cout << std::endl;
                std::cin >> tempStr;
            }
            if (tempStr == "c") {
                std::cout << "------------------------------------------" << std::endl;
                std::cout << "タスクの新規追加を棄却しました。" << std::endl;
                std::cout << "------------------------------------------" << std::endl;
                std::cout << std::endl;
                screen = Screen::LOBBY; // 画面変更処理
                continue;
            }
            tempTask.SetId(std::stoi(tempStr));
            std::cout << "------------------------------------------" << std::endl;
            std::cout << tempStr << "をIDとして設定しました。" << std::endl;
            std::cout << "------------------------------------------" << std::endl;

            // 担当者設定
            std::cout << "------------------------------------------" << std::endl;
            std::cout << "タスクの担当者を設定してください。" << std::endl;
            std::cout << "------------------------------------------" << std::endl;
            std::cout << std::endl;
            if (picManager.size() == 0) {
                std::cout << "++++++++++++++++++++++++++++++++++++++++++" << std::endl;
                std::cout << "担当者が追加されていません。" << std::endl;
                std::cout << "ここで担当者の新規追加を行いますか？" << std::endl;
                std::cout << "行わない場合\"0\"を、行う場合\"1\"を入力してください。" << std::endl;
                std::cout << "ここで新規追加を行わない場合自動的にタスクの新規追加が棄却されます。" << std::endl;
                std::cout << "++++++++++++++++++++++++++++++++++++++++++" << std::endl;
                std::cout << std::endl;
                std::cin >> tempStr;
                while (!CheckNumberOnly(tempStr) || 2 < std::stoi(tempStr) || std::stoi(tempStr) < 0) {
                    std::cout << "操作範囲外の値を入力しないでください。" << std::endl;
                    std::cout << "もう一度入力してください。" << std::endl;
                    std::cout << std::endl;
                    std::cin >> tempStr;
                }
                if (std::stoi(tempStr)) {
                    std::cout << "++++++++++++++++++++++++++++++++++++++++++" << std::endl;
                    std::cout << "担当者の新規追加を行います。" << std::endl;
                    std::cout << "++++++++++++++++++++++++++++++++++++++++++" << std::endl;
                    // 一時変数
                    Pic tempPic{};

                    // 担当者のid設定
                    std::cout << "++++++++++++++++++++++++++++++++++++++++++" << std::endl;
                    std::cout << "担当者のIDを数字で設定してください" << std::endl;
                    std::cout << "++++++++++++++++++++++++++++++++++++++++++" << std::endl;
                    std::cin >> tempPic.id_;
                    while (!CheckNumberOnly(tempStr)) {
                        if (tempStr == "c") break;
                        std::cout << "数字もしくは\"c\"以外を入力しないでください。" << std::endl;
                        std::cout << "もう一度入力してください。" << std::endl;
                        std::cout << std::endl;
                        std::cin >> tempStr;
                    }
                    std::cout << "++++++++++++++++++++++++++++++++++++++++++" << std::endl;
                    std::cout << tempPic.id_ << "をIDとして設定しました。" << std::endl;
                    std::cout << "++++++++++++++++++++++++++++++++++++++++++" << std::endl;
                    std::cout << std::endl;

                    // 担当者の名前設定
                    std::cout << "++++++++++++++++++++++++++++++++++++++++++" << std::endl;
                    std::cout << "担当者の名前を設定してください。" << std::endl;
                    std::cout << "++++++++++++++++++++++++++++++++++++++++++" << std::endl;
                    std::cin >> tempPic.name_;
                    std::cout << "++++++++++++++++++++++++++++++++++++++++++" << std::endl;
                    std::cout << tempPic.name_ << "を名前として設定しました。" << std::endl;
                    std::cout << "++++++++++++++++++++++++++++++++++++++++++" << std::endl;
                    std::cout << std::endl;

                    // 担当者のクラス番号設定
                    std::cout << "++++++++++++++++++++++++++++++++++++++++++" << std::endl;
                    std::cout << "担当者のクラスを設定してください。" << std::endl;
                    std::cout << "++++++++++++++++++++++++++++++++++++++++++" << std::endl;
                    std::cin >> tempPic.classroom_;
                    std::cout << "++++++++++++++++++++++++++++++++++++++++++" << std::endl;
                    std::cout << tempPic.classroom_ << "をクラスとして設定しました。" << std::endl;
                    std::cout << "++++++++++++++++++++++++++++++++++++++++++" << std::endl;
                    std::cout << std::endl;

                    picManager.emplace_back(tempPic);
                    std::cout << "++++++++++++++++++++++++++++++++++++++++++" << std::endl;
                    std::cout << "下記の情報で担当者を新規追加しました。" << std::endl;
                    tempPic.DrawAll();
                    std::cout << "++++++++++++++++++++++++++++++++++++++++++" << std::endl;
                    std::cout << std::endl;

                    tempTask.SetPic(tempPic);
                    std::cout << "------------------------------------------" << std::endl;
                    std::cout << tempPic.name_ << "を担当者として設定しました。" << std::endl;
                    std::cout << "------------------------------------------" << std::endl;
                    std::cout << std::endl;
                }
                else {
                    std::cout << "------------------------------------------" << std::endl;
                    std::cout << "タスクの新規追加を棄却しました。" << std::endl;
                    std::cout << "------------------------------------------" << std::endl;
                    std::cout << std::endl;
                    screen = Screen::LOBBY; // 画面変更処理
                    continue;
                }
            }
            else {
                std::cout << "------------------------------------------" << std::endl;
                std::cout << "現在追加されている担当者一覧です。" << std::endl;
                for (size_t i = 0; i < picManager.size(); i++) {
                    picManager.at(i).DrawAll();
                }
                std::cout << "------------------------------------------" << std::endl;

                // ID照合
                std::cout << "------------------------------------------" << std::endl;
                std::cout << "設定する担当者のIDを入力してください。" << std::endl;
                std::cout << "------------------------------------------" << std::endl;
                std::cin >> tempStr;
                if (tempStr == "c") {
                    std::cout << "------------------------------------------" << std::endl;
                    std::cout << "タスクの新規追加を途中棄却しました。" << std::endl;
                    std::cout << "------------------------------------------" << std::endl;
                    std::cout << std::endl;
                    screen = Screen::LOBBY; // 画面変更処理
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
                std::cout << "を担当者として設定しました。" << std::endl;
                std::cout << "------------------------------------------" << std::endl;
            }

            // 題名設定
            std::cout << "------------------------------------------" << std::endl;
            std::cout << "タスクの題名を設定してください。" << std::endl;
            std::cout << "------------------------------------------" << std::endl;
            std::cout << std::endl;
            std::cin >> tempStr;
            if (tempStr == "c") {
                std::cout << "------------------------------------------" << std::endl;
                std::cout << "タスクの新規追加を棄却しました。" << std::endl;
                std::cout << "------------------------------------------" << std::endl;
                std::cout << std::endl;
                screen = Screen::LOBBY; // 画面変更処理
                continue;
            }
            tempTask.SetSubject(tempStr);
            std::cout << "------------------------------------------" << std::endl;
            std::cout << tempStr << "を題名として設定しました。" << std::endl;
            std::cout << "------------------------------------------" << std::endl;

            // 内容設定
            std::cout << "------------------------------------------" << std::endl;
            std::cout << "タスクの内容を設定してください。" << std::endl;
            std::cout << "------------------------------------------" << std::endl;
            std::cout << std::endl;
            std::cin >> tempStr;
            if (tempStr == "c") {
                std::cout << "------------------------------------------" << std::endl;
                std::cout << "タスクの新規追加を棄却しました。" << std::endl;
                std::cout << "------------------------------------------" << std::endl;
                std::cout << std::endl;
                screen = Screen::LOBBY; // 画面変更処理
                continue;
            }
            tempTask.SetDetail(tempStr);
            std::cout << "------------------------------------------" << std::endl;
            std::cout << tempStr << "を内容として設定しました。" << std::endl;
            std::cout << "------------------------------------------" << std::endl;

            // 優先度設定
            std::cout << "------------------------------------------" << std::endl;
            std::cout << "タスクの優先度を下記の中から数字で設定してください。" << std::endl;
            std::cout << "1.LOW" << std::endl;
            std::cout << "2.MIDDLE" << std::endl;
            std::cout << "3.HIGH" << std::endl;
            std::cout << "4.TOP" << std::endl;
            std::cout << "------------------------------------------" << std::endl;
            std::cout << std::endl;
            std::cin >> tempStr;
            if (tempStr == "c") {
                std::cout << "------------------------------------------" << std::endl;
                std::cout << "タスクの新規追加を棄却しました。" << std::endl;
                std::cout << "------------------------------------------" << std::endl;
                std::cout << std::endl;
                screen = Screen::LOBBY; // 画面変更処理
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
            std::cout << "を優先度として設定しました。" << std::endl;
            std::cout << "------------------------------------------" << std::endl;

            // 締切設定
            std::cout << "------------------------------------------" << std::endl;
            std::cout << "タスクの締切を設定してください。" << std::endl;
            std::cout << "------------------------------------------" << std::endl;
            std::cout << std::endl;
            std::cin >> tempStr;
            if (tempStr == "c") {
                std::cout << "------------------------------------------" << std::endl;
                std::cout << "タスクの新規追加を棄却しました。" << std::endl;
                std::cout << "------------------------------------------" << std::endl;
                std::cout << std::endl;
                screen = Screen::LOBBY; // 画面変更処理
                continue;
            }
            tempTask.SetDeadline(tempStr);
            std::cout << "------------------------------------------" << std::endl;
            std::cout << tempStr << "を締切として設定しました。" << std::endl;
            std::cout << "------------------------------------------" << std::endl;
            std::cout << std::endl;

            // 追加
            taskManager.emplace_back(tempTask);
            std::cout << "新規タスクを追加しました。下記が登録内容です。" << std::endl;
            tempTask.DrawAll();
            std::cout << std::endl;

            screen = Screen::LOBBY; // 画面変更処理
            continue;
        }
        else if (screen == Screen::EDIT_TASK) {
            std::string tempStr{};

            std::cout << "##########################################" << std::endl;
            std::cout << "タスクの編集を行います。" << std::endl;
            std::cout << "##########################################" << std::endl;
            std::cout << std::endl;

            if (taskManager.size() == 0) {
                std::cout << "##########################################" << std::endl;
                std::cout << "タスクが追加されていないため編集は出来ません。" << std::endl;
                std::cout << "##########################################" << std::endl;
                screen = Screen::LOBBY; // 画面変更処理
                continue;
            }

            std::cout << "##########################################" << std::endl;
            std::cout << "現在追加されているタスク一覧です。" << std::endl;
            for (size_t i = 0; i < taskManager.size(); i++) {
                taskManager.at(i).DrawIdentifier();
            }
            std::cout << "##########################################" << std::endl;
            std::cout << std::endl;

            // ID照合
            std::cout << "##########################################" << std::endl;
            std::cout << "編集するタスクのIDを入力してください。" << std::endl;
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
            std::cout << "を編集します。" << std::endl;
            std::cout << "##########################################" << std::endl;
            std::cout << std::endl;

            std::cout << "##########################################" << std::endl;
            std::cout << "どの要素を編集するか下記をもとに数字を入力してください。" << std::endl;
            std::cout << "選択したタスクを[削除]する場合は\"8\"を選択してください。" << std::endl;
            std::cout << "1.ID" << std::endl;
            std::cout << "2.担当者" << std::endl;
            std::cout << "3.題名" << std::endl;
            std::cout << "4.内容" << std::endl;
            std::cout << "5.優先度" << std::endl;
            std::cout << "6.締切" << std::endl;
            std::cout << "7.進捗" << std::endl;
            std::cout << "8.削除" << std::endl;
            std::cout << "##########################################" << std::endl;

            std::cin >> tempStr;
            while (!CheckNumberOnly(tempStr) || 8 < atoi(tempStr.c_str()) || atoi(tempStr.c_str()) < 1) {
                std::cout << "操作範囲外の値を入力しないでください。" << std::endl;
                std::cout << "もう一度入力してください。" << std::endl;
                std::cout << std::endl;
                std::cin >> tempStr;
            }

            std::cout << "##########################################" << std::endl;
            switch (std::stoi(tempStr))
            {
            case 1:
                std::cout << "変更後のIDを入力してください。" << std::endl;
                std::cout << "##########################################" << std::endl;
                std::cout << std::endl;

                std::cin >> tempStr;
                while (!CheckNumberOnly(tempStr)) {
                    std::cout << "数字以外を入力しないでください。" << std::endl;
                    std::cout << "もう一度入力してください。" << std::endl;
                    std::cout << std::endl;
                    std::cin >> tempStr;
                }
                taskManager.at(editId).SetId(std::stoi(tempStr));
                std::cout << "##########################################" << std::endl;
                std::cout << "下記が変更度のタスク情報です。" << std::endl;
                taskManager.at(editId).DrawAll();
                std::cout << "##########################################" << std::endl;
                break;
            case 2:
                std::cout << "変更後の担当者をIDで入力してください。" << std::endl;
                std::cout << "##########################################" << std::endl;
                std::cout << std::endl;

                std::cout << "++++++++++++++++++++++++++++++++++++++++++" << std::endl;
                std::cout << "現在追加されている担当者一覧です。" << std::endl;
                for (size_t i = 0; i < picManager.size(); i++) {
                    picManager.at(i).DrawAll();
                }
                std::cout << "++++++++++++++++++++++++++++++++++++++++++" << std::endl;
                std::cin >> tempStr;
                while (!CheckNumberOnly(tempStr)) {
                    std::cout << "数字以外を入力しないでください。" << std::endl;
                    std::cout << "もう一度入力してください。" << std::endl;
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
                std::cout << "下記が変更度のタスク情報です。" << std::endl;
                taskManager.at(editId).DrawAll();
                std::cout << "##########################################" << std::endl;
                break;
            case 3:
                std::cout << "変更後の題名を入力してください。" << std::endl;
                std::cout << "##########################################" << std::endl;
                std::cout << std::endl;

                std::cin >> tempStr;
                taskManager.at(editId).SetSubject(tempStr);
                std::cout << "##########################################" << std::endl;
                std::cout << "下記が変更度のタスク情報です。" << std::endl;
                taskManager.at(editId).DrawAll();
                std::cout << "##########################################" << std::endl;
                break;
            case 4:
                std::cout << "変更後の内容を入力してください。" << std::endl;
                std::cout << "##########################################" << std::endl;
                std::cout << std::endl;

                std::cin >> tempStr;
                taskManager.at(editId).SetDetail(tempStr);
                std::cout << "##########################################" << std::endl;
                std::cout << "下記が変更度のタスク情報です。" << std::endl;
                taskManager.at(editId).DrawAll();
                std::cout << "##########################################" << std::endl;
                break;
            case 5:
                std::cout << "変更後の優先度を下記の中から数字で入力してください。" << std::endl;
                std::cout << "1.LOW" << std::endl;
                std::cout << "2.MIDDLE" << std::endl;
                std::cout << "3.HIGH" << std::endl;
                std::cout << "4.TOP" << std::endl;
                std::cout << "##########################################" << std::endl;
                std::cout << std::endl;

                std::cin >> tempStr;
                taskManager.at(editId).SetDetail(tempStr);
                std::cout << "##########################################" << std::endl;
                std::cout << "下記が変更度のタスク情報です。" << std::endl;
                taskManager.at(editId).DrawAll();
                std::cout << "##########################################" << std::endl;
                break;
            case 6:
                std::cout << "変更後の締切を入力してください。" << std::endl;
                std::cout << "##########################################" << std::endl;
                std::cout << std::endl;

                std::cin >> tempStr;
                taskManager.at(editId).SetDetail(tempStr);
                std::cout << "##########################################" << std::endl;
                std::cout << "下記が変更度のタスク情報です。" << std::endl;
                taskManager.at(editId).DrawAll();
                std::cout << "##########################################" << std::endl;
                break;
            case 7:
                std::cout << "変更後の進捗が、未完了なら\"0\"を完了なら\"1\"を入力してください。" << std::endl;
                std::cout << "0.未完了" << std::endl;
                std::cout << "1.完了" << std::endl;
                std::cout << "##########################################" << std::endl;
                std::cout << std::endl;

                std::cin >> tempStr;
                while (!CheckNumberOnly(tempStr) || 1 <= atoi(tempStr.c_str()) || atoi(tempStr.c_str()) <= 0) {
                    std::cout << "操作範囲外の値を入力しないでください。" << std::endl;
                    std::cout << "もう一度入力してください。" << std::endl;
                    std::cout << std::endl;
                    std::cin >> tempStr;
                }
                if (std::stoi(tempStr)) taskManager.at(editId).SetStatus(true);
                else taskManager.at(editId).SetStatus(false);
                std::cout << "##########################################" << std::endl;
                std::cout << "下記が変更度のタスク情報です。" << std::endl;
                taskManager.at(editId).DrawAll();
                std::cout << "##########################################" << std::endl;
                break;
            case 8:
                taskManager.erase(taskManager.begin() + editId);
                std::cout << "##########################################" << std::endl;
                std::cout << "[削除]されました。" << std::endl;
                std::cout << "##########################################" << std::endl;
                std::cout << std::endl;
                break;
            }
            std::cout << std::endl;
            std::cout << "##########################################" << std::endl;

            screen = Screen::LOBBY; // 画面変更処理
            continue;
        }
        else if (screen == Screen::CREATE_PIC) {
            std::cout << "++++++++++++++++++++++++++++++++++++++++++" << std::endl;
            std::cout << "担当者の新規追加を行います。" << std::endl;
            std::cout << "++++++++++++++++++++++++++++++++++++++++++" << std::endl;
            // 一時変数
            Pic tempPic{};
            std::string tempStr{};

            // 担当者のid設定
            std::cout << "++++++++++++++++++++++++++++++++++++++++++" << std::endl;
            std::cout << "担当者のIDを数字で設定してください" << std::endl;
            std::cout << "++++++++++++++++++++++++++++++++++++++++++" << std::endl;
            std::cin >> tempPic.id_;
            while (!CheckNumberOnly(tempStr)) {
                std::cout << "数字以外を入力しないでください。" << std::endl;
                std::cout << "もう一度入力してください。" << std::endl;
                std::cout << std::endl;
                std::cin >> tempStr;
            }
            std::cout << "++++++++++++++++++++++++++++++++++++++++++" << std::endl;
            std::cout << tempPic.id_ << "をIDとして設定しました。" << std::endl;
            std::cout << "++++++++++++++++++++++++++++++++++++++++++" << std::endl;
            std::cout << std::endl;

            // 担当者の名前設定
            std::cout << "++++++++++++++++++++++++++++++++++++++++++" << std::endl;
            std::cout << "担当者の名前を設定してください。" << std::endl;
            std::cout << "++++++++++++++++++++++++++++++++++++++++++" << std::endl;
            std::cin >> tempPic.name_;
            std::cout << "++++++++++++++++++++++++++++++++++++++++++" << std::endl;
            std::cout << tempPic.name_ << "を名前として設定しました。" << std::endl;
            std::cout << "++++++++++++++++++++++++++++++++++++++++++" << std::endl;
            std::cout << std::endl;

            // 担当者のクラス番号設定
            std::cout << "++++++++++++++++++++++++++++++++++++++++++" << std::endl;
            std::cout << "担当者のクラスを設定してください。" << std::endl;
            std::cout << "++++++++++++++++++++++++++++++++++++++++++" << std::endl;
            std::cin >> tempPic.classroom_;
            std::cout << "++++++++++++++++++++++++++++++++++++++++++" << std::endl;
            std::cout << tempPic.classroom_ << "をクラスとして設定しました。" << std::endl;
            std::cout << "++++++++++++++++++++++++++++++++++++++++++" << std::endl;
            std::cout << std::endl;

            picManager.emplace_back(tempPic);
            std::cout << "++++++++++++++++++++++++++++++++++++++++++" << std::endl;
            std::cout << "下記の情報で担当者を新規追加しました。" << std::endl;
            tempPic.DrawAll();
            std::cout << "++++++++++++++++++++++++++++++++++++++++++" << std::endl;
            std::cout << std::endl;

            screen = Screen::LOBBY; // 画面変更処理
            continue;
        }
        else if (screen == Screen::EDIT_PIC) {
            std::string tempStr{};

            std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
            std::cout << "担当者の編集を行います。" << std::endl;
            std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
            std::cout << std::endl;

            if (picManager.size() == 0) {
                std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
                std::cout << "担当者が追加されていないため編集は出来ません。" << std::endl;
                std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
                screen = Screen::LOBBY; // 画面変更処理
                continue;
            }

            std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
            std::cout << "現在追加されている担当者一覧です。" << std::endl;
            for (size_t i = 0; i < picManager.size(); i++) {
                picManager.at(i).DrawAll();
            }
            std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;

            // ID照合
            std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
            std::cout << "編集する担当者のIDを入力してください。" << std::endl;
            std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;

            std::cin >> tempStr;
            while (!CheckNumberOnly(tempStr)) {
                std::cout << "数字以外を入力しないでください。" << std::endl;
                std::cout << "もう一度入力してください。" << std::endl;
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
            std::cout << "を編集します。" << std::endl;
            std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
            std::cout << std::endl;

            std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
            std::cout << "どの要素を編集するか下記をもとに数字を入力してください。" << std::endl;
            std::cout << "選択した担当者を[削除]する場合は\"4\"を選択してください。" << std::endl;
            std::cout << "1.ID" << std::endl;
            std::cout << "2.名前" << std::endl;
            std::cout << "3.クラス" << std::endl;
            std::cout << "4.削除" << std::endl;
            std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;

            std::cin >> tempStr;
            while (!CheckNumberOnly(tempStr) || 4 < atoi(tempStr.c_str()) || atoi(tempStr.c_str()) < 1) {
                std::cout << "操作範囲外の値を入力しないでください。" << std::endl;
                std::cout << "もう一度入力してください。" << std::endl;
                std::cout << std::endl;
                std::cin >> tempStr;
            }

            switch (std::stoi(tempStr))
            {
            case 1:
                std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
                std::cout << "変更後のIDを数字で入力してください。" << std::endl;
                std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
                std::cout << std::endl;

                std::cin >> tempStr;
                while (!CheckNumberOnly(tempStr)) {
                    std::cout << "数字以外を入力しないでください。" << std::endl;
                    std::cout << "もう一度入力してください。" << std::endl;
                    std::cout << std::endl;
                    std::cin >> tempStr;
                }
                picManager.at(editId).id_ = std::stoi(tempStr);
                std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
                std::cout << "下記が変更後の担当者情報です。" << std::endl;
                picManager.at(editId).DrawAll();
                std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
                std::cout << std::endl;
                break;
            case 2:
                std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
                std::cout << "変更後の名前を入力してください。" << std::endl;
                std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
                std::cout << std::endl;

                std::cin >> tempStr;

                picManager.at(editId).name_ = tempStr;
                std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
                std::cout << "下記が変更後の担当者情報です。" << std::endl;
                picManager.at(editId).DrawAll();
                std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
                std::cout << std::endl;
                break;
            case 3:
                std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
                std::cout << "変更後のクラスを入力してください。" << std::endl;
                std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
                std::cout << std::endl;

                std::cin >> tempStr;

                picManager.at(editId).classroom_ = tempStr;
                std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
                std::cout << "下記が変更後の担当者情報です。" << std::endl;
                picManager.at(editId).DrawAll();
                std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
                std::cout << std::endl;
                break;
            case 4:
                picManager.erase(picManager.begin() + editId);
                std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
                std::cout << "[削除]されました。" << std::endl;
                std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
                std::cout << std::endl;
                break;
            }
            screen = Screen::LOBBY; // 画面変更処理
            continue;
        }
    }

    return 0;
}