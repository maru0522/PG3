#include <stdio.h>
#include <list>
#include <vector>
#include <iostream>
#include <iterator>

int main(void){

	std::list<const char*> yamanoteLine1970{ 
		"Tokyo", "Kanda", "Akihabara", "Okachimachi", "Ueno",
		"Uguisudani", "Nippori", /*"Nishi-Nippori",*/ "Tabata", "Komagome",
		"Sugamo", "Ōtsuka", "Ikebukuro", "Mejiro", "Takadanobaba",
		"Shin-Ōkubo", "Shinjuku", "Yoyogi", "Harajuku", "Shibuya",
		"Ebisu", "Meguro", "Gotanda", "Ōsaki", "Shinagawa",
		/*"Takanawa-Gateway",*/ "Tamachi", "Hamamatsuchō", "Shimbashi", "Yūrakuchō"
	};

	auto it_ = yamanoteLine1970.begin();

	// 1970年代の駅
	std::cout << "1970年:" << std::endl;
	for (auto it = yamanoteLine1970.begin(); it != yamanoteLine1970.end(); it++) {
		std::cout << *it << std::endl;
	}

	// 西日暮里を挿入
	yamanoteLine1970.insert(std::next(yamanoteLine1970.begin(),7), "Nishi-Nippori");

	// 2020年代の駅
	std::cout << std::endl << "2020年:" << std::endl;
	for (auto it = yamanoteLine1970.begin(); it != yamanoteLine1970.end(); it++) {
		std::cout << *it << std::endl;
	}

	// 高輪ゲートウェイを挿入
	yamanoteLine1970.insert(std::prev(yamanoteLine1970.end(), 4), "Takanawa-Gateway");

	// 2022年代の駅
	std::cout << std::endl << "2022年:" << std::endl;
	for (auto it = yamanoteLine1970.begin(); it != yamanoteLine1970.end(); it++) {
		std::cout << *it << std::endl;
	}

	return 0;
}