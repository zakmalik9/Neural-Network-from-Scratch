#pragma once
#include <iostream>
#include <vector>
using namespace std;

class ImageData
{
public:
	vector<float> pixel_values;
	vector<float> expected_outputs;
	vector<float> predicted_outputs;
	ImageData()
	{

	}
};
