#pragma once

#include "imageview.h"
#include "../Start/Control.h"
#include <vector>
namespace GUI {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;


	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		
		MyForm(void)
		{
			InitializeComponent();
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ button1;
	protected:
	private: System::Windows::Forms::Button^ button2;

	private: System::Windows::Forms::TextBox^ LayerBox;
	private: System::Windows::Forms::TextBox^ Bbox;
	private: System::Windows::Forms::TextBox^ lrbox;
	private: System::Windows::Forms::TextBox^ regbox;




	private: System::Windows::Forms::TextBox^ Ebox;
	private: System::Windows::Forms::TextBox^ lrdbox;
	private: System::Windows::Forms::TextBox^ mbox;




	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ label7;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->LayerBox = (gcnew System::Windows::Forms::TextBox());
			this->Bbox = (gcnew System::Windows::Forms::TextBox());
			this->lrbox = (gcnew System::Windows::Forms::TextBox());
			this->regbox = (gcnew System::Windows::Forms::TextBox());
			this->Ebox = (gcnew System::Windows::Forms::TextBox());
			this->lrdbox = (gcnew System::Windows::Forms::TextBox());
			this->mbox = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(34, 48);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(221, 79);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Train";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(319, 48);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(221, 79);
			this->button2->TabIndex = 1;
			this->button2->Text = L"Display";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// LayerBox
			// 
			this->LayerBox->Location = System::Drawing::Point(34, 192);
			this->LayerBox->Name = L"LayerBox";
			this->LayerBox->Size = System::Drawing::Size(140, 22);
			this->LayerBox->TabIndex = 3;
			this->LayerBox->Text = L"400,100";
			// 
			// Bbox
			// 
			this->Bbox->Location = System::Drawing::Point(34, 262);
			this->Bbox->Name = L"Bbox";
			this->Bbox->Size = System::Drawing::Size(140, 22);
			this->Bbox->TabIndex = 4;
			this->Bbox->Text = L"32";
			// 
			// lrbox
			// 
			this->lrbox->Location = System::Drawing::Point(259, 262);
			this->lrbox->Name = L"lrbox";
			this->lrbox->Size = System::Drawing::Size(139, 22);
			this->lrbox->TabIndex = 5;
			this->lrbox->Text = L"0.05";
			// 
			// regbox
			// 
			this->regbox->Location = System::Drawing::Point(478, 262);
			this->regbox->Name = L"regbox";
			this->regbox->Size = System::Drawing::Size(134, 22);
			this->regbox->TabIndex = 6;
			this->regbox->Text = L"0.1";
			// 
			// Ebox
			// 
			this->Ebox->Location = System::Drawing::Point(259, 192);
			this->Ebox->Name = L"Ebox";
			this->Ebox->Size = System::Drawing::Size(139, 22);
			this->Ebox->TabIndex = 7;
			this->Ebox->Text = L"10";
			// 
			// lrdbox
			// 
			this->lrdbox->Location = System::Drawing::Point(478, 192);
			this->lrdbox->Name = L"lrdbox";
			this->lrdbox->Size = System::Drawing::Size(134, 22);
			this->lrdbox->TabIndex = 8;
			this->lrdbox->Text = L"0.01";
			// 
			// mbox
			// 
			this->mbox->Location = System::Drawing::Point(700, 192);
			this->mbox->Name = L"mbox";
			this->mbox->Size = System::Drawing::Size(134, 22);
			this->mbox->TabIndex = 9;
			this->mbox->Text = L"0.9";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(31, 165);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(124, 16);
			this->label1->TabIndex = 10;
			this->label1->Text = L"Hidden Layer Sizes";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(31, 232);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(70, 16);
			this->label2->TabIndex = 11;
			this->label2->Text = L"Batch Size";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(256, 165);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(46, 16);
			this->label3->TabIndex = 12;
			this->label3->Text = L"Epoch";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(256, 232);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(103, 16);
			this->label4->TabIndex = 13;
			this->label4->Text = L"Inital Learn Rate";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(475, 165);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(116, 16);
			this->label5->TabIndex = 14;
			this->label5->Text = L"Learn Rate Decay";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(475, 232);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(93, 16);
			this->label6->TabIndex = 15;
			this->label6->Text = L"Regularization";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(697, 165);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(73, 16);
			this->label7->TabIndex = 16;
			this->label7->Text = L"Momentum";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(870, 306);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->mbox);
			this->Controls->Add(this->lrdbox);
			this->Controls->Add(this->Ebox);
			this->Controls->Add(this->regbox);
			this->Controls->Add(this->lrbox);
			this->Controls->Add(this->Bbox);
			this->Controls->Add(this->LayerBox);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Name = L"MyForm";
			this->Text = L"NeuralNetworkGUI";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ text = LayerBox->Text;
		cli::array<String^>^ pieces = text->Split('.');
		vector<int> sizes;
		sizes.push_back(784);
		for (int i = 0; i < pieces->Length; ++i)
		{
			sizes.push_back(System::Convert::ToInt16(pieces[i]));
		}
		sizes.push_back(10);
		int batch = System::Convert::ToInt16(Bbox->Text);
		int ep = System::Convert::ToInt16(Ebox->Text);
		double lr = System::Convert::ToDouble(lrbox->Text);
		double lrd = System::Convert::ToDouble(lrdbox->Text);
		double reg = System::Convert::ToDouble(regbox->Text);
		double m = System::Convert::ToDouble(mbox->Text);

		NetworkController control(sizes);
		float accuracy = control.Train(batch, ep, lr, lrd, reg, m);

	}
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ text = LayerBox->Text;
		cli::array<String^>^ pieces = text->Split(',');
		vector<int> sizes;
		for (int i = 0; i < pieces->Length; ++i)
		{
			sizes.push_back(System::Convert::ToInt16(pieces[i]));
		}
		imageview^ f2 = gcnew imageview(sizes);
		f2->ShowDialog();
	}
	};
}
