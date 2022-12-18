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
            std::cout << "[要素の操作]" << std::endl;
            std::cout << "1.要素の表示" << std::endl;
            std::cout << "2.要素の挿入" << std::endl;
            std::cout << "3.要素の編集" << std::endl;
            std::cout << "4.要素の削除" << std::endl;
            std::cout << std::endl;
            std::cout << "------------------------------------" << std::endl;
            std::cout << "操作を選択してください" << std::endl;
            std::cout << "_";
            std::cin >> tmpStr;
            std::cout << std::endl;
            if (IsNumberOnly(tmpStr)) {
                if (5 < atoi(tmpStr.c_str()) || atoi(tmpStr.c_str()) < 1) {
                    std::cout << std::endl;
                    std::cout << "操作範囲外の値を入力しないでください" << std::endl;
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
                std::cout << "数字以外を入力しないでください" << std::endl;
                std::cout << std::endl;
            }
        }
        else if (state == MState::DISPLAY) {
            std::cout << "[要素の表示]" << std::endl;
            std::cout << "1.要素の一覧表示" << std::endl;
            std::cout << "2.順番を指定して要素を表示" << std::endl;
            std::cout << "9.要素操作に戻る" << std::endl;
            std::cout << std::endl;
            std::cout << "操作を選択してください" << std::endl;
            std::cout << "_";
            std::cin >> tmpStr;
            std::cout << std::endl;
            if (IsNumberOnly(tmpStr)) {
                if (atoi(tmpStr.c_str()) < 1 || 2 < atoi(tmpStr.c_str()) && atoi(tmpStr.c_str()) < 9 || 9 < atoi(tmpStr.c_str())) {
                    std::cout << std::endl;
                    std::cout << "操作範囲外の値を入力しないでください" << std::endl;
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
                std::cout << "数字以外を入力しないでください" << std::endl;
                std::cout << std::endl;
            }
        }
        else if (state == MState::DISPLAY_ALL) {
            std::cout << "[要素の一覧表示]" << std::endl;
            std::cout << "要素一覧:{" << std::endl;
            for (size_t i = 1; i < list.Size(); i++) {
                std::cout << " " << i << ": " << "\"" << list.GetValue(i - 1) << "\"" << std::endl;
            }
            std::cout << "}" << std::endl;
            std::cout << std::endl;
            std::cout << "要素数: " << list.Size() - 1 << std::endl;
            std::cout << std::endl;
            std::cout << "------------------------------------" << std::endl;
            std::cout << std::endl;
            std::cout << "1.要素の表示に戻る" << std::endl;
            std::cout << "2.要素の操作に戻る" << std::endl;
            std::cout << "_";
            std::cin >> tmpStr;
            std::cout << std::endl;
            if (IsNumberOnly(tmpStr)) {
                if (atoi(tmpStr.c_str()) < 1 || 2 < atoi(tmpStr.c_str())) {
                    std::cout << std::endl;
                    std::cout << "操作範囲外の値を入力しないでください" << std::endl;
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
                std::cout << "数字以外を入力しないでください" << std::endl;
                std::cout << std::endl;
            }
        }
        else if (state == MState::DISPLAY_PART) {
            std::cout << "[順番を指定して要素を表示]" << std::endl;
            std::cout << "表示したい要素の順番を指定してください。" << std::endl;
            std::cout << "_";
            std::cin >> tmpStr;
            std::cout << std::endl;
            if (IsNumberOnly(tmpStr)) {
                if (atoi(tmpStr.c_str()) < 0 || list.Size() - 1 < atoi(tmpStr.c_str())) {
                    std::cout << std::endl;
                    std::cout << "操作範囲外の値を入力しないでください" << std::endl;
                    std::cout << std::endl;
                }
                else {
                    std::cout << tmpStr.c_str() << ": " << list.GetValue(atoi(tmpStr.c_str()) - 1) << std::endl;
                    std::cout << std::endl;
                }
            }
            else {
                std::cout << std::endl;
                std::cout << "数字以外を入力しないでください" << std::endl;
                std::cout << std::endl;
            }
            std::cout << "------------------------------------" << std::endl;
            std::cout << std::endl;
            std::cout << "1.要素の表示に戻る" << std::endl;
            std::cout << "2.要素の操作に戻る" << std::endl;
            std::cout << "_";
            std::cin >> tmpStr;
            std::cout << std::endl;
            if (IsNumberOnly(tmpStr)) {
                if (atoi(tmpStr.c_str()) < 1 || 2 < atoi(tmpStr.c_str())) {
                    std::cout << std::endl;
                    std::cout << "操作範囲外の値を入力しないでください" << std::endl;
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
                std::cout << "数字以外を入力しないでください" << std::endl;
                std::cout << std::endl;
            }
        }
        else if (state == MState::INSERT) {
        std::cout << "[リスト要素の挿入]" << std::endl;
        std::cout << "要素を追加する場所を指定してください" << std::endl;
        std::cout << "_";
        std::cin >> tmpStr;
        std::cout << std::endl;
        if (IsNumberOnly(tmpStr)) {
            if (atoi(tmpStr.c_str()) < 0 || list.Size() - 1 < atoi(tmpStr.c_str())) {
                std::cout << std::endl;
                std::cout << atoi(tmpStr.c_str()) << "番目の要素は存在しません。。" << std::endl;
                std::cout << std::endl;
            }
            else {
                std::cout << atoi(tmpStr.c_str()) << "追加する要素の値を入力してください。" << std::endl;
            }
        }
        else {
            std::cout << std::endl;
            std::cout << "数字以外を入力しないでください" << std::endl;
            std::cout << std::endl;
        }
        int tmpNum = atoi(tmpStr.c_str());

        std::cout << "_";
        std::cin >> tmpStr;
        std::cout << std::endl;
        std::cout << "要素\"" << tmpStr << "\"が" << tmpNum << "に挿入されました" << std::endl;
        std::cout << std::endl;
        state = MState::BEGIN;
        }
        else if (state == MState::EDIT) {
            std::cout << "[要素の編集]" << std::endl;
            std::cout << "編集したい要素の番号を指定してください。" << std::endl;
            std::cout << "_";
            std::cin >> tmpStr;
            std::cout << std::endl;
            if (IsNumberOnly(tmpStr)) {
                if (atoi(tmpStr.c_str()) < 0 || /*size*/ 9 < atoi(tmpStr.c_str())) {
                    std::cout << std::endl;
                    std::cout << atoi(tmpStr.c_str()) << "番目の要素が見つかりませんでした。" << std::endl;
                    std::cout << std::endl;
                }
                else {
                    std::cout << atoi(tmpStr.c_str()) << "番目の要素の変更する値を入力してください。" << std::endl;
                }
            }
            else {
                std::cout << std::endl;
                std::cout << "数字以外を入力しないでください" << std::endl;
                std::cout << std::endl;
            }
            int tmpNum = atoi(tmpStr.c_str());

            std::cout << "_";
            std::cin >> tmpStr;
            std::cout << std::endl;
            std::cout << tmpNum << "番目の要素の値が\"" << tmpStr << "\"に変更されました" << std::endl;
            std::cout << std::endl;
            state = MState::BEGIN;
        }
        else if (state == MState::REMOVE) {
            std::cout << "[要素の削除]" << std::endl;
            std::cout << "削除したい要素の番号を指定してください。" << std::endl;
            std::cout << "_";
            std::cin >> tmpStr;
            std::cout << std::endl;
            if (IsNumberOnly(tmpStr)) {
                if (atoi(tmpStr.c_str()) < 0 || list.Size() - 1 < atoi(tmpStr.c_str())) {
                    std::cout << std::endl;
                    std::cout << atoi(tmpStr.c_str()) << "番目の要素が見つかりませんでした。。" << std::endl;
                    std::cout << std::endl;
                }
                else {
                    std::cout << atoi(tmpStr.c_str()) << "番目の要素を削除しました。" << std::endl;
                    std::cout << std::endl;
                    list.Remove(atoi(tmpStr.c_str()));
                }
            }
            else {
                std::cout << std::endl;
                std::cout << "数字以外を入力しないでください" << std::endl;
                std::cout << std::endl;
            }
            state = MState::BEGIN;
        }
    }
}