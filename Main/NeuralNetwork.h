#pragma once
#include "Layer.h"
#include "ImageData.h"
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class NeuralNetwork
{
	int num_layers;
	vector<int> layer_sizes;
	vector<Layer> layers;
public:
	NeuralNetwork(vector<int> layer_sizes)
	{
		this->layer_sizes = layer_sizes;
		num_layers = (int)layer_sizes.size() - 1;
		// srand called to make sure weights and biases are initialized randomly and not same every time code compiled
		srand((unsigned) time(0));
		for (int i = 0; i < num_layers; i++)
		{
			layers.push_back(Layer(layer_sizes[i], layer_sizes[i + 1]));
		}
	}
	vector<float> CalculateOutput(vector<float> inputs)
	{
		vector<float> result = inputs;
		for (int i = 0; i < num_layers; i++)
		{
			if (i == num_layers - 1)
				result = layers[i].CalculateOutput(result, true);
			else
				result = layers[i].CalculateOutput(result, false);
		}
		return Softmax(result);
	}
	vector<float> Softmax(vector<float> z)
	{
		float exp_sum = 0;
		for (int i = 0; i < z.size(); i++)
		{
			exp_sum += exp(z[i]);
		}
		vector<float> probs;
		for (int i = 0; i < z.size(); i++)
		{
			float sigma_z = exp(z[i]) / exp_sum;
			probs.push_back(sigma_z);
		}
		return probs;
	}
	float Cost(ImageData img)
	{
		vector<float> predicted_outputs = img.predicted_outputs;
		vector<float> expected_outputs = img.expected_outputs;
		float cost = 0;
		for (int i = 0; i < predicted_outputs.size(); i++)
		{
			float t = expected_outputs[i];
			float a = predicted_outputs[i];
			// numeric limit min used to add small value to log so that log(0) does not happen
			float c = -t * log10(a + numeric_limits<float>::min()) - (1 - t) * log10(1 - a + numeric_limits<float>::min());
			cost += c;
		}
		return cost;
	}
	float AverageCost(vector<ImageData> imgs)
	{
		float total_cost = 0;
		for (int i = 0; i < imgs.size(); i++)
		{
			total_cost += Cost(imgs[i]);
		}
		return (total_cost / imgs.size());
	}
	// Derivative of Cost wrt Softmax x Derivative of Softmax wrt node output (basically Derivative of Cost wrt to node output)
	float OutputDerivative(float predicted_output, float expected_output)
	{
		return (predicted_output - expected_output);
	}
	// Train the Network by feeding it batch of data
	void Learn(vector<ImageData> training_data, float learn_rate, float regularization, float momentum)
	{
		for (int i = 0; i < training_data.size(); i++)
		{
			CalculateAllGradients(training_data[i]);
		}
		ApplyAllGradients(learn_rate / training_data.size(), regularization, momentum);
	}
	void CalculateAllGradients(ImageData img)
	{
		vector<float> inps = img.pixel_values;
		vector<float> expected_output = img.expected_outputs;
		vector<float> network_output = CalculateOutput(inps);
		// Calculate delta values for output layer
		vector<float> delta_values;
		for (int j = 0; j < network_output.size(); j++)
		{
			delta_values.push_back(OutputDerivative(network_output[j], expected_output[j]));
		}
		// Calculating Gradients for output layer
		layers[num_layers - 1].CalculateGradients(delta_values);
		// Calculating Gradients for hidden layers
		for (int k = num_layers - 2; k >= 0; k--)
		{
			layers[k].CalculateDeltaValues(layers[k + 1], delta_values);
			layers[k].CalculateGradients(delta_values);
		}
	}
	void ApplyAllGradients(float learn_rate, float regularization, float momentum)
	{
		for (int i = 0; i < num_layers; i++)
		{
			layers[i].ApplyGradients(learn_rate, regularization, momentum);
		}
	}
	vector<vector<vector<float>>> GetWeights()
	{
		vector<vector<vector<float>>> weights;
		for (int i = 0; i < num_layers; i++)
		{
			weights.push_back(layers[i].GetWeights());
		}
		return weights;
	}
	vector<vector<float>> GetBiases()
	{
		vector<vector<float>> biases;
		for (int i = 0; i < num_layers; i++)
		{
			biases.push_back(layers[i].GetBiases());
		}
		return biases;
	}
	void SaveWeights(vector<vector<vector<float>>> weights)
	{
		for (int i = 0; i < num_layers; i++)
		{
			layers[i].SaveWeights(weights[i]);
		}
	}
	void SaveBiases(vector<vector<float>> biases)
	{
		for (int i = 0; i < num_layers; i++)
		{
			layers[i].SaveBiases(biases[i]);
		}
	}
};