#pragma once
#ifndef TRELLISDRAWING_H
#define TRELLISDRAWING_H
#include<vector>
class trellisDrawing {

private:




public:
	std::vector<int> vec2;
	trellisDrawing();
	trellisDrawing(std::vector<int> vec);
	~trellisDrawing();
	void trellisTable();
	void saveToFile();
};
#endif