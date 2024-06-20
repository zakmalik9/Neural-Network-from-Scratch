#pragma once
#include "Node.h"
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Layer
{
	int num_inputs;
	int num_nodes;
	vector<Node> nodes;
	vector<float> inputs;
	vector<float> weighted_inputs;
	vector<float> activations;
	vector<vector<float>> cost_gradient_wrt_weights;
	vector<float> cost_gradient_wrt_biases;
public:
	Layer(int num_inputs, int num_nodes)
	{
		this->num_inputs = num_inputs;
		this->num_nodes = num_nodes;
		for (int i = 0; i < num_nodes; i++)
		{
			nodes.push_back(Node(num_inputs));
		}
		ClearGradients();
	}
	vector<float> CalculateOutput(vector<float> inputs, bool isOutputLayer)
	{
		this->inputs = inputs;
		vector<float> outputs;
		for (int i = 0; i < num_nodes; i++)
		{

			float node_out = nodes[i].CalculateOutput(inputs);
			weighted_inputs.push_back(node_out);
			// Dont apply Activation if this is output layer
			if (!isOutputLayer)
				node_out = Activation(node_out);
			outputs.push_back(node_out);
		}
		activations = outputs;
		return outputs;
	}
	// Sigmoid Activation Function
	float Activation(float val)
	{
		return 1.0f / (1.0f + exp(-val));
		//return ((val >= 0) ? val : 0.0f);
	}
	float ActivationDerivative(float val)
	{
		float a = Activation(val);
		return a * (1 - a);
		//return ((val > 0) ? 1.0f : 0.0f);
	}
	void CalculateGradients(vector<float> delta_values)
	{
		for (int i = 0; i < delta_values.size(); i++)
		{
			for (int j = 0; j < num_nodes; j++)
			{
				float g = inputs[j] * delta_values[i];
				cost_gradient_wrt_weights[i][j] += g;
			}
			cost_gradient_wrt_biases[i] = 1 * delta_values[i];
		}
	}
	vector<float> CalculateDeltaValues(Layer next_layer, vector<float> old_delta_values)
	{
		vector<float> new_delta_values;
		for (int i = 0; i < num_nodes; i++)
		{
			float new_value = 0.0f;
			for (int j = 0; j < old_delta_values.size(); j++)
			{
				new_value += next_layer.nodes[j].GetWeight(i) * old_delta_values[j];
			}
			new_value *= ActivationDerivative(weighted_inputs[i]);
			new_delta_values.push_back(new_value);
		}
		return new_delta_values;
	}
	void ApplyGradients(float learn_rate, float regularization, float momentum)
	{
		for (int i = 0; i < num_nodes; i++)
		{
			nodes[i].UpdateWeightsBiases(cost_gradient_wrt_weights[i], cost_gradient_wrt_biases[i], learn_rate, regularization, momentum);
		}
		ClearGradients();
	}
	void ClearGradients()
	{
		cost_gradient_wrt_weights = vector<vector<float>>(num_nodes, vector<float>(num_inputs, 0.0f));
		cost_gradient_wrt_biases = vector<float>(num_nodes, 0.0f);
	}
	vector<vector<float>> GetWeights()
	{
		vector<vector<float>> weights;
		for (int i = 0; i < num_nodes; i++)
		{
			weights.push_back(nodes[i].GetWeights());
		}
		return weights;
	}
	vector<float> GetBiases()
	{
		vector<float> biases;
		for (int i = 0; i < num_nodes; i++)
		{
			biases.push_back(nodes[i].GetBias());
		}
		return biases;
	}
	void SaveWeights(vector<vector<float>> weights)
	{
		for (int i = 0; i < num_nodes; i++)
		{
			nodes[i].SaveWeights(weights[i]);
		}
	}
	void SaveBiases(vector<float> biases)
	{
		for (int i = 0; i < num_nodes; i++)
		{
			nodes[i].SaveBias(biases[i]);
		}
	}
};
