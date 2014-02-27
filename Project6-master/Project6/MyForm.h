#pragma once

#include"Karel.h"
#include"Cell.h"
#include<array>

namespace Project6 {

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
			//
			//TODO: Add the constructor code here
			//
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
	private: System::Windows::Forms::Panel^  panel1;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::Button^  button4;
	private: System::Windows::Forms::Button^  button5;

	protected: 

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// panel1
			// 
			this->panel1->Location = System::Drawing::Point(37, 12);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(500, 400);
			this->panel1->TabIndex = 0;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(37, 449);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 1;
			this->button1->Text = L"Start Maze";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(342, 447);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(58, 23);
			this->button2->TabIndex = 0;
			this->button2->Text = L"Turn Left";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(342, 418);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(75, 23);
			this->button3->TabIndex = 2;
			this->button3->Text = L"Move";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(447, 418);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(90, 23);
			this->button4->TabIndex = 3;
			this->button4->Text = L"Place Beeper";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &MyForm::button4_Click);
			// 
			// button5
			// 
			this->button5->Location = System::Drawing::Point(447, 449);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(90, 23);
			this->button5->TabIndex = 4;
			this->button5->Text = L"Take Beeper";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &MyForm::button5_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(584, 512);
			this->Controls->Add(this->button5);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->panel1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->ResumeLayout(false);

		}
#pragma endregion

		private: void drawMaze()
				{
					int ave;
					int street;
					int x;
					int y;

					panel1->Refresh();

					for(street = 0; street < 16; street++)
						for(ave = 0; ave < 20; ave++)
							{
							x = ave * CELLSIZE;
							y = street * CELLSIZE;
							Rectangle gridRect = Rectangle(x,y, CELLSIZE-1,CELLSIZE-1);
							g->FillRectangle(whiteBrush,gridRect);
							g->DrawRectangle(blackPen,gridRect);

							
							}
				 }



		
		array<Cell^,2>^ world;
		char direction;
		
		Graphics^ g;
		Brush^ grayBrush;
		Brush^ whiteBrush;
		Pen^ blackPen;
		Brush^ TestBeacon;


		static const int CELLSIZE = 25;
	private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e) {

				 int ave;
				 int street;
				 
				 g = panel1->CreateGraphics();
				 grayBrush = gcnew System::Drawing::SolidBrush(Color::Gray);
				 whiteBrush = gcnew System::Drawing::SolidBrush(Color::White);
				 blackPen = gcnew System::Drawing::Pen(Color::Black);
				 TestBeacon = gcnew System::Drawing::SolidBrush(Color::DarkOrange);
				 world = gcnew array<Cell^,2> (16,20);
				 for(street = 0; street < 16; street++)
					 for(ave = 0; ave < 20; ave++)
						 world[street,ave] = gcnew Cell(street, ave, true);
				  
				 
			 }

				

				 
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
				 int x;
				 int y;

				 int karelStreet = 8;
				 int karelAve = 8;
				 int karelBeeper = 0;
				 Karel^ k1;
				 k1 = gcnew Karel(karelAve, karelStreet);


				 drawMaze();

				 k1->setStreet(karelStreet);
				 k1->setAve(karelAve);

				 x = karelAve * CELLSIZE;
				 y = karelStreet * CELLSIZE;

				 Rectangle karelRect = Rectangle(x,y,CELLSIZE,CELLSIZE);
				 g->DrawIcon(k1->getIcon(),karelRect);

				 
			 }
private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
						
		 }
private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			
		 }
private: System::Void button4_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			
			 int x=25;
			 int y=25;
			
			 Rectangle beaconRect = Rectangle(x,y, CELLSIZE-1,CELLSIZE-1);
			 g->DrawRectangle(blackPen,beaconRect);
			 g->FillRectangle(TestBeacon,beaconRect);
							

		 }
private: System::Void button5_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 int x = 25;
			 int y = 25;
			 Rectangle beaconRect = Rectangle(x,y, CELLSIZE-1,CELLSIZE-1);
			
			 g->DrawRectangle(blackPen,beaconRect);
             g->FillRectangle(whiteBrush,beaconRect);
		 }
};
			 

}

