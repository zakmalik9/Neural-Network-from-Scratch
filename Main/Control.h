#pragma once
#include "NeuralNetwork.h"
#include "ImageData.h"
#include <vector>
#include <fstream>
#include <string>
#include <cstdio>
#include <cerrno>
using namespace std;

class NetworkController
{
	NeuralNetwork neural_net;
	vector<ImageData> training_images;
	vector<ImageData> test_images;
public:
	NetworkController(vector<int> layer_sizes) : neural_net(layer_sizes)
	{
		
	}
	float Train(int batch_size, int epoch, float initial_learn_rate, float learn_rate_decay, float regularization, float momentum)
	{
		ImportData();
		int num_batches = (int) training_images.size() / batch_size;
		float learn_rate = initial_learn_rate;
		for (int epoch_num = 0; epoch_num < epoch; epoch_num++)
		{
			for (int i = 0; i < num_batches; i++)
			{
				vector<ImageData> training_batch;
				for (int j = 0; j < batch_size; j++)
				{
					training_batch.push_back(training_images[i * batch_size + j]);
				}
				neural_net.Learn(training_batch, learn_rate, regularization, momentum);
			}
			learn_rate = (1.0f / (1.0f + learn_rate_decay * epoch_num)) * initial_learn_rate;
			cout << "Epoch " << epoch_num << endl;
			cout << "Accuracy: " << Test() << endl;
		}
		SaveNetwork();
		return Test();
	}
	float Test()
	{
		int count = 0;
		for (int i = 0; i < test_images.size(); i++)
		{
			vector<float> inputs = test_images[i].pixel_values;
			vector<float> expected_output = test_images[i].expected_outputs;
			vector<float> network_output = neural_net.CalculateOutput(inputs);
			
			// If Network Prediction was right, increment counter
			float max_value = 0.0f;
			int max_value_index = 0;
			bool isPredictionCorrect = false;
			OutputPrdeiction(expected_output, network_output, &isPredictionCorrect, &max_value, &max_value_index);
			if (isPredictionCorrect)
				count++;
		}
		float accuracy = (count / (float)test_images.size()) * 100;
		return accuracy;
	}
	void ForDisplay(int image_index, float* max_value, string* test_image_category, string* predicted_category)
	{
		ImportData();
		ImportNetwork();
		bool isPredictionCorrect = false;
		int max_value_index = 0;
		vector<float> expected_output = test_images[image_index].expected_outputs;
		vector<float> network_output = neural_net.CalculateOutput(test_images[image_index].pixel_values);
		OutputPrdeiction(expected_output, network_output, &isPredictionCorrect, max_value, &max_value_index);
		int test_image_max_value_index = 0;
		for (int j = 0; j < expected_output.size(); j++)
		{
			if (expected_output[j] == 1.0f)
			{
				test_image_max_value_index = j;
				break;
			}
		}
		*test_image_category = CategoryNumToName(test_image_max_value_index);
		*predicted_category = CategoryNumToName(max_value_index);
	}
	string CategoryNumToName(int category_num)
	{
		switch (category_num)
		{
			case 0:
				return "Bicycle";
			case 1:
				return "Cat";
			case 2:
				return "Cruiseship";
			case 3:
				return "Helicopter";
			case 4:
				return "Houseplant";
			case 5:
				return "Lollipop";
			case 6:
				return "Octopus";
			case 7:
				return "Tractor";
			case 8:
				return "Umbrella";
			case 9:
				return "Windmill";
		}
	}
	void OutputPrdeiction(vector<float> expected_output, vector<float> network_output, bool *isPredictionCorrect, float *max_value, int *max_value_index)
	{
		int max_val_id = 0;
		float max_val = 0;
		for (int k = 0; k < network_output.size(); k++)
		{
			if (network_output[k] > max_val)
			{
				max_val = network_output[k];
				max_val_id = k;
			}
		}
		*max_value = max_val;
		*max_value_index = max_val_id;
		for (int j = 0; j < expected_output.size(); j++)
		{
			if (expected_output[j] == 1.0f)
			{
				if (j == max_val_id)
				{
					*isPredictionCorrect = true;
					break;
				}
			}
		}
	}
	// Get Training and Test Images Data from txt files  
	void ImportData()
	{
		string train_data = get_file_contents("imgdata/traindata.txt");
		string train_img_data = "";
		for (auto x : train_data)
		{
			if (x == '\n')
			{
				ImageData img;
				img.expected_outputs = vector<float>(10, 0.0f);
				int category_num = 0;
				bool isCategoryNum = true;
				string pixel_data = "";
				for (auto y : train_img_data)
				{
					if (y == ' ')
					{
						if (isCategoryNum)
						{
							category_num = stoi(pixel_data);
							isCategoryNum = false;
						}
						else
						{
							float pixel = stof(pixel_data);
							pixel /= 255.0f;
							img.pixel_values.push_back(pixel);
						}
						pixel_data = "";
					}
					else
					{
						pixel_data += y;
					}
				}
				img.expected_outputs[category_num] = 1.0f;
				training_images.push_back(img);
				train_img_data = "";
			}
			else
			{
				train_img_data += x;
			}
		}

		string test_data = get_file_contents("imgdata/testdata.txt");
		string test_img_data = "";
		for (auto x : test_data)
		{
			if (x == '\n')
			{
				ImageData img;
				img.expected_outputs = vector<float>(10, 0.0f);
				int category_num = 0;
				bool isCategoryNum = true;
				string pixel_data = "";
				for (auto y : test_img_data)
				{
					if (y == ' ')
					{
						if (isCategoryNum)
						{
							category_num = stoi(pixel_data);
							isCategoryNum = false;
						}
						else
						{
							float pixel = stof(pixel_data);
							pixel /= 255.0f;
							img.pixel_values.push_back(pixel);
						}
						pixel_data = "";
					}
					else
					{
						pixel_data += y;
					}
				}
				img.expected_outputs[category_num] = 1.0f;
				test_images.push_back(img);
				test_img_data = "";
			}
			else
			{
				test_img_data += x;
			}
		}
	}
	// Save the Weights and Biases of the Trained Network to a txt file
	void SaveNetwork()
	{
		vector<vector<vector<float>>> weights = neural_net.GetWeights();
		vector<vector<float>> biases = neural_net.GetBiases();

		ofstream fout_weights("networkdata/weights.txt");
		string weights_string = "";
		// Weights of each Node stored with single space in between, then next line for next node, tab used to differentiate layers
		for (int i = 0; i < weights.size(); i++)
		{
			for (int j = 0; j < weights[i].size(); j++)
			{
				for (int k = 0; k < weights[i][j].size(); k++)
				{
					weights_string += to_string(weights[i][j][k]) + " ";
				}
				weights_string += "\n";
			}
			weights_string += "\t";
		}
		fout_weights << weights_string;
		fout_weights.close();

		ofstream fout_biases("networkdata/biases.txt");
		string biases_string = "";
		// Bias of each Layer stored with single space in between, then next line for next Layer
		for (int i = 0; i < biases.size(); i++)
		{
			for (int j = 0; j < biases[i].size(); j++)
			{
				biases_string += to_string(biases[i][j]) + " ";
			}
			biases_string += "\n";
		}
		fout_biases << biases_string;
		fout_biases.close();
	}
	// Get Weights and Biases Data from a txt file
	void ImportNetwork()
	{
		vector<vector<vector<float>>> network_weights;
		vector<vector<float>> network_biases;

		string network_weights_data = get_file_contents("networkdata/weights.txt");
		string layer_weights_data = "";
		for (auto x : network_weights_data)
		{
			if (x == '\t')
			{
				vector<vector<float>> layer_weights;
				string node_data = "";
				for (auto y : layer_weights_data)
				{
					if (y == '\n')
					{
						vector<float> node_weights;
						string weight = "";
						for (auto z : node_data)
						{
							if (z == ' ')
							{
								node_weights.push_back(stof(weight));
								weight = "";
							}
							else
							{
								weight += z;
							}
						}
						layer_weights.push_back(node_weights);
						node_data = "";
					}
					else
					{
						node_data += y;
					}
				}
				network_weights.push_back(layer_weights);
				layer_weights_data = "";
			}
			else 
			{
				layer_weights_data += x;
			}
		}

		string network_biases_data = get_file_contents("networkdata/biases.txt");
		string layer_biases_data = "";
		for (auto x : network_biases_data)
		{
			if (x == '\n')
			{
				vector<float> layer_biases;
				string bias = "";
				for (auto y : layer_biases_data)
				{
					if (y == ' ')
					{
						layer_biases.push_back(stof(bias));
						bias = "";
					}
					else
					{
						bias += y;
					}
				}
				network_biases.push_back(layer_biases);
				layer_biases_data = "";
			}
			else
			{
				layer_biases_data += x;
			}
		}

		neural_net.SaveWeights(network_weights);
		neural_net.SaveBiases(network_biases);
	}
	string get_file_contents(const char* filename)
	{
		#pragma warning(disable : 4996)
		FILE* fp = fopen(filename, "rb");
		if (fp)
		{
			string contents;
			fseek(fp, 0, SEEK_END);
			contents.resize(ftell(fp));
			rewind(fp);
			fread(&contents[0], 1, contents.size(), fp);
			fclose(fp);
			return(contents);
		}
		throw(errno);
	}
};