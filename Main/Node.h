#pragma once
#include <iostream>
#include <vector>
#include <cstdlib>
#include <time.h>
using namespace std;

class Node
{
	int num_weights;
	vector<float> weights;
	float bias;
	vector<float> weight_velocities;
	float bias_velocity;
public:
	Node(int num_weights)
	{
		this->num_weights = num_weights;
		// Weights and Bias initialized Randomly between -1 and 1
		for (int i = 0; i < num_weights; i++)
		{
			float x = ((float)rand() / RAND_MAX) * 2 - 1;
			weights.push_back(x);
		}
		bias = ((float)rand() / RAND_MAX) * 2 - 1;
		weight_velocities = vector<float>(num_weights, 0.0f);
		bias_velocity = 0.0f;
	}
	float CalculateOutput(vector<float> inputs)
	{
		float output = 0;
		for (int i = 0; i < num_weights; i++)
		{
			output += inputs[i] * weights[i];
		}
		output += bias;
		return output;
	}
	float GetWeight(int index)
	{
		return weights[index];
	}
	void UpdateWeightsBiases(vector<float> weight_gradients, float bias_gradient, float learn_rate, float regularization, float momentum)
	{
		float weight_decay = 1 - regularization * learn_rate;
		for (int i = 0; i < num_weights; i++)
		{
			float new_weight_velocity = weight_velocities[i] * momentum - weight_gradients[i] * learn_rate;
			weight_velocities[i] = new_weight_velocity;
			weights[i] = weights[i] * weight_decay + new_weight_velocity;
		}
		float new_bias_velocity = bias_velocity * momentum - bias_gradient * learn_rate;
		bias_velocity = new_bias_velocity;
		bias += new_bias_velocity;
	}
	vector<float> GetWeights()
	{
		return weights;
	}
	float GetBias()
	{
		return bias;
	}
	void SaveWeights(vector<float> weights)
	{
		this->weights = weights;
	}
	void SaveBias(float bias)
	{
		this->bias = bias;
	}
};
