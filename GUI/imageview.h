#pragma once
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
	/// Summary for imageview
	/// </summary>
	public ref class imageview : public System::Windows::Forms::Form
	{
	public:
		imageview(vector<int> sizes)
		{
			InitializeComponent();
			string layer_data = "";
			for (int i = 0; i < sizes.size(); i++)
			{
				layer_data += to_string(sizes[i]);
				if (i != sizes.size() - 1)
					layer_data += ",";
			}
			layerlabel->Text = gcnew String(layer_data.c_str());
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~imageview()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ button1;
	protected:
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::Label^ truelabel;

	private: System::Windows::Forms::Label^ networklabel;

	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::TextBox^ imgNumBox;
	private: System::Windows::Forms::Label^ layerlabel;


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
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->truelabel = (gcnew System::Windows::Forms::Label());
			this->networklabel = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->imgNumBox = (gcnew System::Windows::Forms::TextBox());
			this->layerlabel = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(353, 235);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Open";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &imageview::button1_Click);
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->pictureBox1->Location = System::Drawing::Point(36, 26);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(200, 200);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox1->TabIndex = 1;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->Click += gcnew System::EventHandler(this, &imageview::pictureBox1_Click);
			// 
			// truelabel
			// 
			this->truelabel->AutoSize = true;
			this->truelabel->Location = System::Drawing::Point(406, 54);
			this->truelabel->Name = L"truelabel";
			this->truelabel->Size = System::Drawing::Size(58, 16);
			this->truelabel->TabIndex = 2;
			this->truelabel->Text = L"Windmill";
			// 
			// networklabel
			// 
			this->networklabel->AutoSize = true;
			this->networklabel->Location = System::Drawing::Point(406, 173);
			this->networklabel->Name = L"networklabel";
			this->networklabel->Size = System::Drawing::Size(58, 16);
			this->networklabel->TabIndex = 3;
			this->networklabel->Text = L"Windmill";
			this->networklabel->Click += gcnew System::EventHandler(this, &imageview::label2_Click);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(281, 54);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(85, 16);
			this->label3->TabIndex = 4;
			this->label3->Text = L"Actual Image";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(268, 173);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(116, 16);
			this->label4->TabIndex = 5;
			this->label4->Text = L"NetworkPrediction";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(36, 242);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(200, 16);
			this->label5->TabIndex = 6;
			this->label5->Text = L"Enter Test Image Number(0-999)";
			// 
			// imgNumBox
			// 
			this->imgNumBox->Location = System::Drawing::Point(97, 270);
			this->imgNumBox->Name = L"imgNumBox";
			this->imgNumBox->Size = System::Drawing::Size(74, 22);
			this->imgNumBox->TabIndex = 7;
			this->imgNumBox->Text = L"0";
			this->imgNumBox->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// layerlabel
			// 
			this->layerlabel->AutoSize = true;
			this->layerlabel->Location = System::Drawing::Point(365, 276);
			this->layerlabel->Name = L"layerlabel";
			this->layerlabel->Size = System::Drawing::Size(52, 16);
			this->layerlabel->TabIndex = 8;
			this->layerlabel->Text = L"400,100";
			// 
			// imageview
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->ClientSize = System::Drawing::Size(562, 304);
			this->Controls->Add(this->layerlabel);
			this->Controls->Add(this->imgNumBox);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->networklabel);
			this->Controls->Add(this->truelabel);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->button1);
			this->Name = L"imageview";
			this->Text = L"TestImagesViewer";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ img_num = imgNumBox->Text;
		Bitmap^ bmpPicture = gcnew Bitmap("imgdata\\testimages\\" + img_num + ".png");
		pictureBox1->Image = bmpPicture;
		pictureBox1->BackgroundImageLayout = ImageLayout(3);
		String^ text = layerlabel->Text;
		cli::array<String^>^ pieces = text->Split(',');
		vector<int> sizes;
		sizes.push_back(784);
		for (int i = 0; i < pieces->Length; ++i)
		{
			sizes.push_back(System::Convert::ToInt16(pieces[i]));
		}
		sizes.push_back(10);
		NetworkController control(sizes);

		float percentage_confidence = 0; 
		string test_image_category = "";
		string predicted_category = "";
		control.ForDisplay(System::Convert::ToInt16(img_num), &percentage_confidence, &test_image_category, &predicted_category);
		truelabel->Text = gcnew String(test_image_category.c_str());
		predicted_category += " " + to_string(percentage_confidence*100) + "%";
		networklabel->Text = gcnew String(predicted_category.c_str());
	}
	private: System::Void pictureBox1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void label2_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	};
}
