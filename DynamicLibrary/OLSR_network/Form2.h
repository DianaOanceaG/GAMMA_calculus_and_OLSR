#pragma once
#include "Sets.h"
#include <vector>
#include "Olsr.h"
#include <fstream>
#include<sstream>
#include <string>
#include <time.h>//time_t
#include <iostream>
using namespace std;


extern vector<OLSR_protocol::Node> Nodelist;
extern vector<OLSR_protocol::Molecula_topologie> topologie;
//extern OLSR_protocol::Node Nodelist [10];
extern OLSR_protocol::Node getNode(int adr);

namespace OLSR_network {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Form2
	/// </summary>
	public ref class Form2 : public System::Windows::Forms::Form
	{
	public:
		
		PictureBox^ pctBox1,^ pctBox2,^ pctBox3,^ pctBox4,^ pctBox5,^ pctBox6,^ pctBox7,^ pctBox8,^ pctBox9,^ pctBox10;
	private: System::Windows::Forms::Button^  Startsimulation;
	public: 
		int data;
		Form2(void)
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
		~Form2()
		{
			if (components)
			{
				delete components;
			}
		}

	protected: 


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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Form2::typeid));
			this->Startsimulation = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// Startsimulation
			// 
			this->Startsimulation->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(192)), 
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->Startsimulation->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"Startsimulation.BackgroundImage")));
			this->Startsimulation->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->Startsimulation->Cursor = System::Windows::Forms::Cursors::Hand;
			this->Startsimulation->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->Startsimulation->Location = System::Drawing::Point(725, 147);
			this->Startsimulation->Name = L"Startsimulation";
			this->Startsimulation->Size = System::Drawing::Size(215, 73);
			this->Startsimulation->TabIndex = 0;
			this->Startsimulation->UseVisualStyleBackColor = false;
			this->Startsimulation->Click += gcnew System::EventHandler(this, &Form2::Startsimulation_Click);
			// 
			// Form2
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FloralWhite;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"$this.BackgroundImage")));
			this->ClientSize = System::Drawing::Size(952, 439);
			this->Controls->Add(this->Startsimulation);
			this->ForeColor = System::Drawing::Color::White;
			this->Name = L"Form2";
			this->Text = L"GAMMA Simulator";
			this->Load += gcnew System::EventHandler(this, &Form2::Form2_Load);
			this->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Form2::Form2_Paint);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void Form2_Load(System::Object^  sender, System::EventArgs^  e) {
				
				 string line;
				 int nr;
				 data=0;
				 ifstream file("input.txt");

				 if(file.is_open())
				 {
					 int count=0;
					while(getline(file,line))
					{
						if(count==0)
							data=atoi(line.c_str());
						else
						{
							string buf;
							stringstream ss(line); //insert the string into a stream
							ss>>buf;
							nr=atoi(buf.c_str());
							Nodelist.push_back(getNode(nr));
							while(ss>>buf)
							{
								OLSR_protocol::Molecula_topologie molecula;
								molecula.setXY(nr, atoi(buf.c_str()));
								topologie.push_back(molecula);
							}
						}
						count++;
					}
					file.close();
				 }
				 else 
					 {
						 MessageBox::Show("Eroare deschidere fisier input.txt!");
						 exit(1);
				     }

				 if(data==0)
				 {
					MessageBox::Show("Nu a fost furnizata configuratia!");
					exit(1);
				 }
				 	//for(int i=0;i<10;i++)
						//Nodelist[i].Main_addr=i+1;

				 
				 //pctBox1
			pctBox1=gcnew PictureBox;
			pctBox1->Location=Point(130,100);
			pctBox1->SizeMode=PictureBoxSizeMode::StretchImage;
			pctBox1->Size=System::Drawing::Size(40,40);
			pctBox1->Image=Image::FromFile("C:\\Users\\Diana\\Documents\\Visual Studio 2012\\Projects\\DynamicLibrary\\dot1.png");
			Controls->Add(pctBox1);
			pctBox1->Visible=false;
			this->pctBox1->Click+=gcnew System::EventHandler(this,&Form2::pctBox1_Click);

			//pctBox2
			pctBox2=gcnew PictureBox;
			pctBox2->Location=Point(360,100);
			pctBox2->SizeMode=PictureBoxSizeMode::StretchImage;
			pctBox2->Size=System::Drawing::Size(40,40);
			pctBox2->Image=Image::FromFile("C:\\Users\\Diana\\Documents\\Visual Studio 2012\\Projects\\DynamicLibrary\\dot2.png");
			Controls->Add(pctBox2);
			pctBox2->Visible=false;
			this->pctBox2->Click+=gcnew System::EventHandler(this,&Form2::pctBox2_Click);

			pctBox3=gcnew PictureBox;
			pctBox3->Location=Point(250,160);
			pctBox3->SizeMode=PictureBoxSizeMode::StretchImage;
			pctBox3->Size=System::Drawing::Size(40,40);
			pctBox3->Image=Image::FromFile("C:\\Users\\Diana\\Documents\\Visual Studio 2012\\Projects\\DynamicLibrary\\dot3.png");
			Controls->Add(pctBox3);
			pctBox3->Visible=false;
			this->pctBox3->Click+=gcnew System::EventHandler(this,&Form2::pctBox3_Click);

			pctBox4=gcnew PictureBox;
			pctBox4->Location=Point(150,200);
			pctBox4->SizeMode=PictureBoxSizeMode::StretchImage;
			pctBox4->Size=System::Drawing::Size(40,40);
			pctBox4->Image=Image::FromFile("C:\\Users\\Diana\\Documents\\Visual Studio 2012\\Projects\\DynamicLibrary\\dot4.png");
			Controls->Add(pctBox4);
			pctBox4->Visible=false;
			this->pctBox4->Click+=gcnew System::EventHandler(this,&Form2::pctBox4_Click);

			pctBox5=gcnew PictureBox;
			pctBox5->Location=Point(500,200);
			pctBox5->SizeMode=PictureBoxSizeMode::StretchImage;
			pctBox5->Size=System::Drawing::Size(40,40);
			pctBox5->Image=Image::FromFile("C:\\Users\\Diana\\Documents\\Visual Studio 2012\\Projects\\DynamicLibrary\\dot5.png");
			Controls->Add(pctBox5);
			pctBox5->Visible=false;
			this->pctBox5->Click+=gcnew System::EventHandler(this,&Form2::pctBox5_Click);

			pctBox6=gcnew PictureBox;
			pctBox6->Location=Point(400,250);
		    pctBox6->SizeMode=PictureBoxSizeMode::StretchImage;
			pctBox6->Size=System::Drawing::Size(40,40);
			pctBox6->Image=Image::FromFile("C:\\Users\\Diana\\Documents\\Visual Studio 2012\\Projects\\DynamicLibrary\\dot6.png");
			Controls->Add(pctBox6);
			pctBox6->Visible=false;
			this->pctBox6->Click+=gcnew System::EventHandler(this,&Form2::pctBox6_Click);

			pctBox7=gcnew PictureBox;
			pctBox7->Location=Point(250,290);
			pctBox7->SizeMode=PictureBoxSizeMode::StretchImage;
			pctBox7->Size=System::Drawing::Size(40,40);
			pctBox7->Image=Image::FromFile("C:\\Users\\Diana\\Documents\\Visual Studio 2012\\Projects\\DynamicLibrary\\dot7.png");
			Controls->Add(pctBox7);
			pctBox7->Visible=false;
			this->pctBox7->Click+=gcnew System::EventHandler(this,&Form2::pctBox7_Click);

			pctBox8=gcnew PictureBox;
			pctBox8->Location=Point(100,290);
			pctBox8->SizeMode=PictureBoxSizeMode::StretchImage;
			pctBox8->Size=System::Drawing::Size(40,40);
			pctBox8->Image=Image::FromFile("C:\\Users\\Diana\\Documents\\Visual Studio 2012\\Projects\\DynamicLibrary\\dot8.png");
			Controls->Add(pctBox8);
			pctBox8->Visible=false;
			this->pctBox8->Click+=gcnew System::EventHandler(this,&Form2::pctBox8_Click);

			pctBox9=gcnew PictureBox;
			pctBox9->Location=Point(450,350);
			pctBox9->SizeMode=PictureBoxSizeMode::StretchImage;
			pctBox9->Size=System::Drawing::Size(40,40);
			pctBox9->Image=Image::FromFile("C:\\Users\\Diana\\Documents\\Visual Studio 2012\\Projects\\DynamicLibrary\\dot9.png");
			Controls->Add(pctBox9);
			pctBox9->Visible=false;
			this->pctBox9->Click+=gcnew System::EventHandler(this,&Form2::pctBox9_Click);

			pctBox10=gcnew PictureBox;
			pctBox10->Location=Point(330,370);
			pctBox10->SizeMode=PictureBoxSizeMode::StretchImage;
			pctBox10->Size=System::Drawing::Size(40,40);
			pctBox10->Image=Image::FromFile("C:\\Users\\Diana\\Documents\\Visual Studio 2012\\Projects\\DynamicLibrary\\dot10.png");
			Controls->Add(pctBox10);
			pctBox10->Visible=false;
			this->pctBox10->Click+=gcnew System::EventHandler(this,&Form2::pctBox10_Click);
			}

	private: System::Void Form2_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {
				 
				 Graphics^ g=e->Graphics;

				 //create Pen
				 Pen^ greenPen=gcnew Pen(Color::Red,2);
				 // Set the DashCap to round.
				 greenPen->DashCap = System::Drawing::Drawing2D::DashCap::Round;
				 // Create a custom dash pattern. 
				 array<Single>^temp0 = {5.0F,3.0F,2.0F,4.0F};
				 greenPen->DashPattern = temp0;

				 Point p1,p2;

					 //create points that define line
					 
					 for(int k=0;k<(int)topologie.size();k++)
						 if(topologie[k].getX()==1 && topologie[k].getY()==2 || topologie[k].getX()==2 && topologie[k].getY()==1)
							{ 
								 p1.X=165;
								 p1.Y=120;
								 p2.X=360;
								 p2.Y=120;
								 g->DrawLine(greenPen,p1,p2);//1-2
							}
						 else
							 if(topologie[k].getX()==1 && topologie[k].getY()==3 || topologie[k].getX()==3 && topologie[k].getY()==1)
								 {
									 p1.X=165;
									 p1.Y=120;
									 p2.X=255;
									 p2.Y=175;
									 g->DrawLine(greenPen,p1,p2); //1-3
								}
							 else
								 if(topologie[k].getX()==1 && topologie[k].getY()==4 || topologie[k].getX()==4 && topologie[k].getY()==1)
									{
										 p1.X=140;
										 p1.Y=133;
										 p2.X=160;
										 p2.Y=202;
										 g->DrawLine(greenPen,p1,p2);//1-4
									}
								 else
									 if(topologie[k].getX()==1 && topologie[k].getY()==5 || topologie[k].getX()==5 && topologie[k].getY()==1)
										 {
											p1.X=165;
											p1.Y=120;
											p2.X=500;
											p2.Y=220;
											g->DrawLine(greenPen,p1,p2);//1-5
										 }
									 else
										 if(topologie[k].getX()==1 && topologie[k].getY()==6 || topologie[k].getX()==6 && topologie[k].getY()==1)
											 {
												p1.X=165;
												p1.Y=120;
												p2.X=400;
												p2.Y=260;
												g->DrawLine(greenPen,p1,p2);//1-6
											 }
										 else
											 if(topologie[k].getX()==1 && topologie[k].getY()==7 || topologie[k].getX()==7 && topologie[k].getY()==1)
											 {
												 p1.X=165;
												 p1.Y=120;
												 p2.X=250;
												 p2.Y=300;
												 g->DrawLine(greenPen,p1,p2);//1-7
											 }
											 else
												 if(topologie[k].getX()==1 && topologie[k].getY()==8 || topologie[k].getX()==8 && topologie[k].getY()==1)
												 {
													 p1.X=165;
													 p1.Y=120;
													 p2.X=130;
													 p2.Y=295;
													 g->DrawLine(greenPen,p1,p2);//1-8
												 }
												 else
													 if(topologie[k].getX()==1 && topologie[k].getY()==9 || topologie[k].getX()==9 && topologie[k].getY()==1)
													 {
														 p1.X=165;
														 p1.Y=120;
														 p2.X=455;
														 p2.Y=355;
														 g->DrawLine(greenPen,p1,p2);//1-9
													 }
													 else
														 if(topologie[k].getX()==1 && topologie[k].getY()==10 || topologie[k].getX()==10 && topologie[k].getY()==1)
														 {
															 p1.X=165;
															 p1.Y=120;
															 p2.X=330;
															 p2.Y=390;
															 g->DrawLine(greenPen,p1,p2);//1-10
														 }
														 else
															 if(topologie[k].getX()==2 && topologie[k].getY()==3 || topologie[k].getX()==3 && topologie[k].getY()==2)
															 {
																 p1.X=360;
																 p1.Y=120;
																 p2.X=280;
																 p2.Y=165;
																 g->DrawLine(greenPen,p1,p2);//2-3
															 }
															 else
																 if(topologie[k].getX()==2 && topologie[k].getY()==4 || topologie[k].getX()==4 && topologie[k].getY()==2)
																 {
																	 p1.X=360;
																	 p1.Y=120;
																	 p2.X=183;
																	 p2.Y=210;
																	 g->DrawLine(greenPen,p1,p2);//2-4
																 }
																 else
																	 if(topologie[k].getX()==2 && topologie[k].getY()==5 || topologie[k].getX()==5 && topologie[k].getY()==2 )
																	 {
																		 p1.X=365;
																		 p1.Y=120;
																		 p2.X=505;
																		 p2.Y=215;
																		 g->DrawLine(greenPen,p1,p2);//2-5
																	 }
																	 else 
																		 if(topologie[k].getX()==2 && topologie[k].getY()==6 || topologie[k].getX()==6 && topologie[k].getY()==2)
																		 {
																			 p1.X=375;
																			 p1.Y=125;
																			 p2.X=410;
																			 p2.Y=255;
																			 g->DrawLine(greenPen,p1,p2);//2-6
																		 }
																		 else
																			 if(topologie[k].getX()==2 && topologie[k].getY()==7 || topologie[k].getX()==7 && topologie[k].getY()==2)
																			 {
																				 p1.X=360;
																				 p1.Y=125;
																				 p2.X=280;
																				 p2.Y=290;
																				 g->DrawLine(greenPen,p1,p2);//2-7
																			 }
																			 else 
																				 if(topologie[k].getX()==2 && topologie[k].getY()==8 || topologie[k].getX()==8 && topologie[k].getY()==2)
																				 {
																					 p1.X=360;
																					 p1.Y=120;
																					 p2.X=135;
																					 p2.Y=306;
																					 g->DrawLine(greenPen,p1,p2);//2-8
																				 }
																				 else
																					 if(topologie[k].getX()==2 && topologie[k].getY()==9 || topologie[k].getX()==9 && topologie[k].getY()==2)
																					 {
																						 p1.X=365;
																						 p1.Y=120;
																						 p2.X=455;
																						 p2.Y=355;
																						 g->DrawLine(greenPen,p1,p2);//2-9
																					 }
																					 else
																						 if(topologie[k].getX()==2 && topologie[k].getY()==10 || topologie[k].getX()==10 && topologie[k].getY()==2)
																						 {
																							 p1.X=365;
																							 p1.Y=120;
																							 p2.X=360;
																							 p2.Y=385;
																							 g->DrawLine(greenPen,p1,p2);//2-10
																						 }
																						 else
																							 if(topologie[k].getX()==3 && topologie[k].getY()==4 || topologie[k].getX()==4 && topologie[k].getY()==3)
																							 {
																								 p1.X=255;
																								 p1.Y=190;
																								 p2.X=183;
																								 p2.Y=210;																						
																								 g->DrawLine(greenPen,p1,p2);//3-4
																							 }
																							 else
																								 if(topologie[k].getX()==3 && topologie[k].getY()==5 || topologie[k].getX()==5 && topologie[k].getY()==3)
																								 {
																									 p1.X=280;
																									 p1.Y=190;
																									 p2.X=505;
																									 p2.Y=225;
																									 g->DrawLine(greenPen,p1,p2);//3-5
																								 }
																								 else
																									 if(topologie[k].getX()==3 && topologie[k].getY()==6 || topologie[k].getX()==6 && topologie[k].getY()==3)
																									 {
																										 p1.X=260;
																										 p1.Y=190;
																										 p2.X=405;
																										 p2.Y=255;
																										 g->DrawLine(greenPen,p1,p2);//3-6
																									 }
																									 else
																										 if(topologie[k].getX()==3 && topologie[k].getY()==7 || topologie[k].getX()==7 && topologie[k].getY()==3)
																										 {
																											 p1.X=260;
																											 p1.Y=190;
																											 p2.X=270;
																											 p2.Y=300;
																											 g->DrawLine(greenPen,p1,p2);//3-7
																										 }
																										 else 
																											 if(topologie[k].getX()==3 && topologie[k].getY()==8 || topologie[k].getX()==8 && topologie[k].getY()==3)
																											 {
																												 p1.X=255;
																												 p1.Y=190;
																												 p2.X=135;
																												 p2.Y=306;
																												 g->DrawLine(greenPen,p1,p2);//3-8
																											 }
																											 else
																												 if(topologie[k].getX()==3 && topologie[k].getY()==9 || topologie[k].getX()==9 && topologie[k].getY()==3)
																												 {
																													 p1.X=260;
																													 p1.Y=190;
																													 p2.X=450;
																													 p2.Y=360;
																													 g->DrawLine(greenPen,p1,p2);//3-9
																												 }
																												 else
																													 if(topologie[k].getX()==3 && topologie[k].getY()==10 || topologie[k].getX()==10 && topologie[k].getY()==3)
																													 {
																														 p1.X=265;
																														 p1.Y=190;
																														 p2.X=335;
																														 p2.Y=385;
																														 g->DrawLine(greenPen,p1,p2);//3-10
																													 }
																													 else
																														 if(topologie[k].getX()==4 && topologie[k].getY()==5 || topologie[k].getX()==5 && topologie[k].getY()==4)
																														 {
																															 p1.X=183;
																															 p1.Y=220;
																															 p2.X=500;
																															 p2.Y=220;
																															 g->DrawLine(greenPen,p1,p2);//4-5
																														 }
																														 else
																															 if(topologie[k].getX()==4 && topologie[k].getY()==6 || topologie[k].getX()==6 && topologie[k].getY()==4)
																															 {
																																 p1.X=183;
																																 p1.Y=220;
																																 p2.X=400;
																																 p2.Y=260;
																																 g->DrawLine(greenPen,p1,p2);//4-6
																															 }
																															 else
																																 if(topologie[k].getX()==4 && topologie[k].getY()==7 || topologie[k].getX()==7 && topologie[k].getY()==4)
																																 {
																																	 p1.X=177;
																																	 p1.Y=233;
																																	 p2.X=250;
																																	 p2.Y=300;
																																	 g->DrawLine(greenPen,p1,p2);//4-7
																																 }
																																 else
																																	 if(topologie[k].getX()==4 && topologie[k].getY()==8 || topologie[k].getX()==8 && topologie[k].getY()==4)
																																	 {
																																		 p1.X=155;
																																		 p1.Y=230;
																																		 p2.X=130;
																																		 p2.Y=295;
																																		 g->DrawLine(greenPen,p1,p2);//4-8
																																	 }
																																	 else
																																		 if(topologie[k].getX()==4 && topologie[k].getY()==9 || topologie[k].getX()==9 && topologie[k].getY()==4)
																																		 {
																																			 p1.X=177;
																																			 p1.Y=233;
																																			 p2.X=455;
																																			 p2.Y=355;
																																			 g->DrawLine(greenPen,p1,p2);//4-9
																																		 }
																																		 else
																																			 if(topologie[k].getX()==4 && topologie[k].getY()==10 || topologie[k].getX()==10 && topologie[k].getY()==4)
																																			 {
																																				 p1.X=177;
																																				 p1.Y=233;
																																				 p2.X=335;
																																				 p2.Y=395;
																																				 g->DrawLine(greenPen,p1,p2);//4-10
																																			 }
																																			 else
																																				 if(topologie[k].getX()==5 && topologie[k].getY()==6 || topologie[k].getX()==6 && topologie[k].getY()==5)
																																				 {																									 
																																					 p1.X=500;
																																					 p1.Y=220;
																																					 p2.X=430;
																																					 p2.Y=265;
																																					 g->DrawLine(greenPen,p1,p2);//5-6
																																				 }
																																				 else
																																					 if(topologie[k].getX()==5 && topologie[k].getY()==7 || topologie[k].getX()==7 && topologie[k].getY()==5)
																																					 {
																																						p1.X=500;
																																						p1.Y=220;
																																						p2.X=280;
																																						p2.Y=290;
																																						g->DrawLine(greenPen,p1,p2);//5-7
																																					 }
																																					 else
																																						 if(topologie[k].getX()==5 && topologie[k].getY()==8 || topologie[k].getX()==8 && topologie[k].getY()==5)
																																						 {
																																							p1.X=500;
																																							p1.Y=220;
																																							p2.X=135;
																																							p2.Y=306;
																																							g->DrawLine(greenPen,p1,p2);//5-8
																																						 }
																																						 else
																																							 if(topologie[k].getX()==5 && topologie[k].getY()==9 || topologie[k].getX()==9 && topologie[k].getY()==5)
																																								{
																																									p1.X=510;
																																									p1.Y=230;
																																									p2.X=480;
																																									p2.Y=355;
																																									g->DrawLine(greenPen,p1,p2);//5-9
																																								}
																																							 else
																																								 if(topologie[k].getX()==5 && topologie[k].getY()==10 || topologie[k].getX()==10 && topologie[k].getY()==5)
																																								 {
																																									p1.X=510;
																																									p1.Y=230;
																																									p2.X=365;
																																									p2.Y=385;
																																									g->DrawLine(greenPen,p1,p2);//5-10
																																								 }
																																								 else
																																									 if(topologie[k].getX()==6 && topologie[k].getY()==7 || topologie[k].getX()==7 && topologie[k].getY()==6)
																																									 {
																																										 p1.X=400;
																																										 p1.Y=280;
																																										 p2.X=280;
																																										 p2.Y=305;																							
																																										 g->DrawLine(greenPen,p1,p2);//6-7
																																									 }
																																									 else
																																										 if(topologie[k].getX()==6 && topologie[k].getY()==8 || topologie[k].getX()==8 && topologie[k].getY()==6)
																																										 {
																																											p1.X=400;
																																											p1.Y=270;
																																											p2.X=135;
																																											p2.Y=306;
																																											g->DrawLine(greenPen,p1,p2);//6-8
																																										 }
																																										 else
																																											 if(topologie[k].getX()==6 && topologie[k].getY()==9 || topologie[k].getX()==9 && topologie[k].getY()==6)
																																											 {
																																												 p1.X=420;
																																												 p1.Y=285;
																																												 p2.X=455;
																																												 p2.Y=355;
																																												 g->DrawLine(greenPen,p1,p2);//6-9
																																											 }
																																											 else
																																												 if(topologie[k].getX()==6 && topologie[k].getY()==10 || topologie[k].getX()==10 && topologie[k].getY()==6)
																																												 {
																																													p1.X=415;
																																													p1.Y=285;
																																													p2.X=355;
																																													p2.Y=385;
																																													g->DrawLine(greenPen,p1,p2);//6-10
																																												 }
																																												 else
																																													 if(topologie[k].getX()==7 && topologie[k].getY()==8 || topologie[k].getX()==8 && topologie[k].getY()==7)
																																													 {
																																														 p1.X=250;
																																														 p1.Y=310;
																																														 p2.X=135;
																																														 p2.Y=310;																																													 
																																														 g->DrawLine(greenPen,p1,p2);//7-8
																																													 }
																																													 else
																																														 if(topologie[k].getX()==7 && topologie[k].getY()==9 || topologie[k].getX()==9 && topologie[k].getY()==7)
																																														 {
																																															p1.X=265;
																																															p1.Y=315;
																																															p2.X=455;
																																															p2.Y=360;
																																															g->DrawLine(greenPen,p1,p2);//7-9
																																														 }
																																														 else
																																															 if(topologie[k].getX()==7 && topologie[k].getY()==10 || topologie[k].getX()==10 && topologie[k].getY()==7)
																																															 {
																																																 p1.X=270;
																																																 p1.Y=325;
																																																 p2.X=330;
																																																 p2.Y=390;
																																																 g->DrawLine(greenPen,p1,p2);//7-10
																																															 }
																																															 else
																																																 if(topologie[k].getX()==8 && topologie[k].getY()==9 || topologie[k].getX()==9 && topologie[k].getY()==8)
																																																 {
																																																	p1.X=135;
																																																	p1.Y=317;
																																																	p2.X=455;
																																																	p2.Y=365;
																																																	g->DrawLine(greenPen,p1,p2);//8-9
																																																 }
																																																 else
																																																	 if(topologie[k].getX()==8 && topologie[k].getY()==10 || topologie[k].getX()==10 && topologie[k].getY()==8)
																																																	 {
																																																		p1.X=135;
																																																		p1.Y=323;
																																																		p2.X=335;
																																																		p2.Y=397;
																																																		g->DrawLine(greenPen,p1,p2);//8-10
																																																	 }
																																																	 else
																																																		 if(topologie[k].getX()==9 && topologie[k].getY()==10 || topologie[k].getX()==10 && topologie[k].getY()==9)
																																																		 {
																																																			 p1.X=450;
																																																			 p1.Y=370;
																																																			 p2.X=365;
																																																			 p2.Y=390;
																																																			 g->DrawLine(greenPen,p1,p2);//9-10
																																																		 }
														
			 if(data==10)
				 {
					 //picture
					 pctBox1->Visible=true;
					 pctBox2->Visible=true;
					 pctBox3->Visible=true;
					 pctBox4->Visible=true;
					 pctBox5->Visible=true;
					 pctBox6->Visible=true;
					 pctBox7->Visible=true;
					 pctBox8->Visible=true;
					 pctBox9->Visible=true;
					 pctBox10->Visible=true;
				 }
			 else
					 if(data==5)
					 {	
						 //picture
						 pctBox1->Visible=true;
						 pctBox2->Visible=true;
						 pctBox3->Visible=true;
						 pctBox4->Visible=true;
						 pctBox5->Visible=true;
					 }
					 else
						 if(data==6)
						 {
							 //picture
							 pctBox1->Visible=true;
							 pctBox2->Visible=true;
							 pctBox3->Visible=true;
							 pctBox4->Visible=true;
							 pctBox5->Visible=true;
							 pctBox6->Visible=true;

						 }
						 else
							 if(data==7)
							 {
								 //picture
								 pctBox1->Visible=true;
								 pctBox2->Visible=true;
								 pctBox3->Visible=true;
								 pctBox4->Visible=true;
								 pctBox5->Visible=true;
								 pctBox6->Visible=true;
								 pctBox7->Visible=true;
							 }
							 else 
								 if(data==8)
								 {
									 //picture
									 pctBox1->Visible=true;
									 pctBox2->Visible=true;
									 pctBox3->Visible=true;
									 pctBox4->Visible=true;
									 pctBox5->Visible=true;
									 pctBox6->Visible=true;
									 pctBox7->Visible=true;
									 pctBox8->Visible=true;
								 }
								 else
									 if(data==9)
									 {
										 //picture
										 pctBox1->Visible=true;
										 pctBox2->Visible=true;
										 pctBox3->Visible=true;
										 pctBox4->Visible=true;
										 pctBox5->Visible=true;
										 pctBox6->Visible=true;
										 pctBox7->Visible=true;
										 pctBox8->Visible=true;
										 pctBox9->Visible=true;
									 }

			 }

			private: System::Void pctBox1_Click(System::Object^  sender, System::EventArgs^  e)
					  {
						 Sets^ seti=gcnew Sets();
						 seti->Show();		
						 
						 DataGridViewRow^ row = gcnew DataGridViewRow();
						 int i=0;

						 //Link Set
						 if((int)Nodelist[0].L_set.size()>0)
						 {
							 seti->dataGridView2->Rows[0]->Cells[0]->Value=Nodelist[0].L_set[0].L_local_iface_addr;
							 seti->dataGridView2->Rows[0]->Cells[1]->Value=Nodelist[0].L_set[0].L_neighbor_iface_addr;
							 seti->dataGridView2->Rows[0]->Cells[2]->Value=Nodelist[0].L_set[0].L_SYM_time;
							 seti->dataGridView2->Rows[0]->Cells[3]->Value=Nodelist[0].L_set[0].L_ASYM_time;
							 seti->dataGridView2->Rows[0]->Cells[4]->Value=Nodelist[0].L_set[0].L_time;

							 for(i=1;i<(int)Nodelist[0].L_set.size();i++)
							 {
								 row = gcnew DataGridViewRow();
								 row->CreateCells(seti->dataGridView2);
								 row->Cells[0]->Value=Nodelist[0].L_set[i].L_local_iface_addr;
								 row->Cells[1]->Value=Nodelist[0].L_set[i].L_neighbor_iface_addr;
								 row->Cells[2]->Value=Nodelist[0].L_set[i].L_SYM_time;
								 row->Cells[3]->Value=Nodelist[0].L_set[i].L_ASYM_time;
								 row->Cells[4]->Value=Nodelist[0].L_set[i].L_time;
								 seti->dataGridView2->Rows->Add(row);
							 }
						 }

						 //Neighbor Set
						 if((int)Nodelist[0].N_set.size()>0)
						 {
							 seti->dataGridView1->Rows[0]->Cells[0]->Value=Nodelist[0].N_set[0].N_neighbor_main_addr;
							 seti->dataGridView1->Rows[0]->Cells[1]->Value=Nodelist[0].N_set[0].N_status;
							 seti->dataGridView1->Rows[0]->Cells[2]->Value=Nodelist[0].N_set[0].N_willingness;

							 for(i=1;i<(int)Nodelist[0].N_set.size();i++)
							 {
								 row = gcnew DataGridViewRow();
								 row->CreateCells(seti->dataGridView1);
								 row->Cells[0]->Value=Nodelist[0].N_set[i].N_neighbor_main_addr;
								 row->Cells[1]->Value=Nodelist[0].N_set[i].N_status;
								 row->Cells[2]->Value=Nodelist[0].N_set[i].N_willingness;
								 seti->dataGridView1->Rows->Add(row);
							 }
						 }

						 //2-hop Neighbor Set
						 if((int)Nodelist[0]._2hop_set.size()>0)
						 {
							 seti->dataGridView3->Rows[0]->Cells[0]->Value=Nodelist[0]._2hop_set[0].N_neighbor_main_addr;
							 seti->dataGridView3->Rows[0]->Cells[1]->Value=Nodelist[0]._2hop_set[0].N_2hop_addr;
							 seti->dataGridView3->Rows[0]->Cells[2]->Value=Nodelist[0]._2hop_set[0].N_time;

							 for(i=1;i<(int)Nodelist[0]._2hop_set.size();i++)
							 {
								 row=gcnew DataGridViewRow();
								 row->CreateCells(seti->dataGridView3);
								 row->Cells[0]->Value=Nodelist[0]._2hop_set[i].N_neighbor_main_addr;
								 row->Cells[1]->Value=Nodelist[0]._2hop_set[i].N_2hop_addr;
								 row->Cells[2]->Value=Nodelist[0]._2hop_set[i].N_time;
								 seti->dataGridView3->Rows->Add(row);
							 }
						 }

						 //MPR Set
						 if((int)Nodelist[0].Mpr_set.size()>0)
						 {
							 seti->dataGridView4->Rows[0]->Cells[0]->Value=Nodelist[0].Mpr_set[0].MPR_main_addr;

							 for(i=1;i<(int)Nodelist[0].Mpr_set.size();i++)
							 {
								 row=gcnew DataGridViewRow();
								 row->CreateCells(seti->dataGridView4);
								 row->Cells[0]->Value=Nodelist[0].Mpr_set[i].MPR_main_addr;
								 seti->dataGridView4->Rows->Add(row);
							 }
						 }

						 //MS Set
						 if((int)Nodelist[0].MS_set.size()>0)
						 {
							 seti->dataGridView5->Rows[0]->Cells[0]->Value=Nodelist[0].MS_set[0].MS_main_addr;
							 seti->dataGridView5->Rows[0]->Cells[1]->Value=Nodelist[0].MS_set[0].MS_time;

							 for(i=1;i<(int)Nodelist[0].MS_set.size();i++)
							 {
								row=gcnew DataGridViewRow();
								row->CreateCells(seti->dataGridView5);
								row->Cells[0]->Value=Nodelist[0].MS_set[i].MS_main_addr;
								row->Cells[1]->Value=Nodelist[0].MS_set[i].MS_time;
								seti->dataGridView5->Rows->Add(row);
							 }
						 }

						 //Topology Set
						 if((int)Nodelist[0].T_set.size()>0)
						 {
							 seti->dataGridView6->Rows[0]->Cells[0]->Value=Nodelist[0].T_set[0].T_dest_addr;
							 seti->dataGridView6->Rows[0]->Cells[1]->Value=Nodelist[0].T_set[0].T_last_addr;
							 seti->dataGridView6->Rows[0]->Cells[2]->Value=Nodelist[0].T_set[0].T_time;

							 for(i=1;i<(int)Nodelist[0].T_set.size();i++)
							 {
								row=gcnew DataGridViewRow();
								row->CreateCells(seti->dataGridView6);
								row->Cells[0]->Value=Nodelist[0].T_set[i].T_dest_addr;
								row->Cells[1]->Value=Nodelist[0].T_set[i].T_last_addr;
								row->Cells[2]->Value=Nodelist[0].T_set[i].T_time;
								seti->dataGridView6->Rows->Add(row);
							 }
						 }

						 //Routing table
						 if((int)Nodelist[0].R_table.size()>0)
						 {
							 seti->dataGridView7->Rows[0]->Cells[0]->Value=Nodelist[0].R_table[0].R_dest_addr;
							 seti->dataGridView7->Rows[0]->Cells[1]->Value=Nodelist[0].R_table[0].R_next_addr;
							 seti->dataGridView7->Rows[0]->Cells[2]->Value=Nodelist[0].R_table[0].R_dist;
							 seti->dataGridView7->Rows[0]->Cells[3]->Value=Nodelist[0].R_table[0].R_iface_addr;

							 for(i=1;i<(int)Nodelist[0].R_table.size();i++)
							 {
								 row = gcnew DataGridViewRow();
								 row->CreateCells(seti->dataGridView7);
								 row->Cells[0]->Value=Nodelist[0].R_table[i].R_dest_addr;
								 row->Cells[1]->Value=Nodelist[0].R_table[i].R_next_addr;
								 row->Cells[2]->Value=Nodelist[0].R_table[i].R_dist;
								 row->Cells[3]->Value=Nodelist[0].R_table[i].R_iface_addr;
								 seti->dataGridView7->Rows->Add(row);
							 }
						 }

					 }

			private: System::Void pctBox2_Click(System::Object^  sender, System::EventArgs^  e)
					  {
						 Sets^ seti=gcnew Sets();
						 seti->Show();	

						 DataGridViewRow^ row = gcnew DataGridViewRow();
						 int i=0;

						 //Link Set
						 if((int)Nodelist[1].L_set.size()>0)
						 {
							 seti->dataGridView2->Rows[0]->Cells[0]->Value=Nodelist[1].L_set[0].L_local_iface_addr;
							 seti->dataGridView2->Rows[0]->Cells[1]->Value=Nodelist[1].L_set[0].L_neighbor_iface_addr;
							 seti->dataGridView2->Rows[0]->Cells[2]->Value=Nodelist[1].L_set[0].L_SYM_time;
							 seti->dataGridView2->Rows[0]->Cells[3]->Value=Nodelist[1].L_set[0].L_ASYM_time;
							 seti->dataGridView2->Rows[0]->Cells[4]->Value=Nodelist[1].L_set[0].L_time;

							 for(i=1;i<(int)Nodelist[1].L_set.size();i++)
							 {
								 row = gcnew DataGridViewRow();
								 row->CreateCells(seti->dataGridView2);
								 row->Cells[0]->Value=Nodelist[1].L_set[i].L_local_iface_addr;
								 row->Cells[1]->Value=Nodelist[1].L_set[i].L_neighbor_iface_addr;
								 row->Cells[2]->Value=Nodelist[1].L_set[i].L_SYM_time;
								 row->Cells[3]->Value=Nodelist[1].L_set[i].L_ASYM_time;
								 row->Cells[4]->Value=Nodelist[1].L_set[i].L_time;
								 seti->dataGridView2->Rows->Add(row);
							 }
						 }

						 //Neighbor Set
						 if((int)Nodelist[1].N_set.size()>0)
						 {
							 seti->dataGridView1->Rows[0]->Cells[0]->Value=Nodelist[1].N_set[0].N_neighbor_main_addr;
							 seti->dataGridView1->Rows[0]->Cells[1]->Value=Nodelist[1].N_set[0].N_status;
							 seti->dataGridView1->Rows[0]->Cells[2]->Value=Nodelist[1].N_set[0].N_willingness;

							 for(i=1;i<(int)Nodelist[1].N_set.size();i++)
							 {
								 row = gcnew DataGridViewRow();
								 row->CreateCells(seti->dataGridView1);
								 row->Cells[0]->Value=Nodelist[1].N_set[i].N_neighbor_main_addr;
								 row->Cells[1]->Value=Nodelist[1].N_set[i].N_status;
								 row->Cells[2]->Value=Nodelist[1].N_set[i].N_willingness;
								 seti->dataGridView1->Rows->Add(row);
							 }
						 }

						 //2-hop Neighbor Set
						 if((int)Nodelist[1]._2hop_set.size()>0)
						 {
							 seti->dataGridView3->Rows[0]->Cells[0]->Value=Nodelist[1]._2hop_set[0].N_neighbor_main_addr;
							 seti->dataGridView3->Rows[0]->Cells[1]->Value=Nodelist[1]._2hop_set[0].N_2hop_addr;
							 seti->dataGridView3->Rows[0]->Cells[2]->Value=Nodelist[1]._2hop_set[0].N_time;

							 for(i=1;i<(int)Nodelist[1]._2hop_set.size();i++)
							 {
								 row=gcnew DataGridViewRow();
								 row->CreateCells(seti->dataGridView3);
								 row->Cells[0]->Value=Nodelist[1]._2hop_set[i].N_neighbor_main_addr;
								 row->Cells[1]->Value=Nodelist[1]._2hop_set[i].N_2hop_addr;
								 row->Cells[2]->Value=Nodelist[1]._2hop_set[i].N_time;
								 seti->dataGridView3->Rows->Add(row);
							 }
						 }

						 //MPR Set
						 if((int)Nodelist[1].Mpr_set.size()>0)
						 {
							 seti->dataGridView4->Rows[0]->Cells[0]->Value=Nodelist[1].Mpr_set[0].MPR_main_addr;

							 for(i=1;i<(int)Nodelist[1].Mpr_set.size();i++)
							 {
								 row=gcnew DataGridViewRow();
								 row->CreateCells(seti->dataGridView4);
								 row->Cells[0]->Value=Nodelist[1].Mpr_set[i].MPR_main_addr;
								 seti->dataGridView4->Rows->Add(row);
							 }
						 }

						 //MS Set
						 if((int)Nodelist[1].MS_set.size()>0)
						 {
							 seti->dataGridView5->Rows[0]->Cells[0]->Value=Nodelist[1].MS_set[0].MS_main_addr;
							 seti->dataGridView5->Rows[0]->Cells[1]->Value=Nodelist[1].MS_set[0].MS_time;

							 for(i=1;i<(int)Nodelist[1].MS_set.size();i++)
							 {
								row=gcnew DataGridViewRow();
								row->CreateCells(seti->dataGridView5);
								row->Cells[0]->Value=Nodelist[1].MS_set[i].MS_main_addr;
								row->Cells[1]->Value=Nodelist[1].MS_set[i].MS_time;
								seti->dataGridView5->Rows->Add(row);
							 }
						 }

						 //Topology Set
						 if((int)Nodelist[1].T_set.size()>0)
						 {
							 seti->dataGridView6->Rows[0]->Cells[0]->Value=Nodelist[1].T_set[0].T_dest_addr;
							 seti->dataGridView6->Rows[0]->Cells[1]->Value=Nodelist[1].T_set[0].T_last_addr;
							 seti->dataGridView6->Rows[0]->Cells[2]->Value=Nodelist[1].T_set[0].T_time;

							 for(i=1;i<(int)Nodelist[1].T_set.size();i++)
							 {
								row=gcnew DataGridViewRow();
								row->CreateCells(seti->dataGridView6);
								row->Cells[0]->Value=Nodelist[1].T_set[i].T_dest_addr;
								row->Cells[1]->Value=Nodelist[1].T_set[i].T_last_addr;
								row->Cells[2]->Value=Nodelist[1].T_set[i].T_time;
								seti->dataGridView6->Rows->Add(row);
							 }
						 }

						 //Routing table
						 if((int)Nodelist[1].R_table.size()>0)
						 {
							 seti->dataGridView7->Rows[0]->Cells[0]->Value=Nodelist[1].R_table[0].R_dest_addr;
							 seti->dataGridView7->Rows[0]->Cells[1]->Value=Nodelist[1].R_table[0].R_next_addr;
							 seti->dataGridView7->Rows[0]->Cells[2]->Value=Nodelist[1].R_table[0].R_dist;
							 seti->dataGridView7->Rows[0]->Cells[3]->Value=Nodelist[1].R_table[0].R_iface_addr;

							 for(i=1;i<(int)Nodelist[1].R_table.size();i++)
							 {
								 row = gcnew DataGridViewRow();
								 row->CreateCells(seti->dataGridView7);
								 row->Cells[0]->Value=Nodelist[1].R_table[i].R_dest_addr;
								 row->Cells[1]->Value=Nodelist[1].R_table[i].R_next_addr;
								 row->Cells[2]->Value=Nodelist[1].R_table[i].R_dist;
								 row->Cells[3]->Value=Nodelist[1].R_table[i].R_iface_addr;
								 seti->dataGridView7->Rows->Add(row);
							 }
						 }
					  }

			private: System::Void pctBox3_Click(System::Object^  sender, System::EventArgs^  e)
					  {
						 Sets^ seti=gcnew Sets();
						 seti->Show();				 
						 
						 DataGridViewRow^ row = gcnew DataGridViewRow();
						 int i=0;

						 //Link Set
						 if((int)Nodelist[2].L_set.size()>0)
						 {
							 seti->dataGridView2->Rows[0]->Cells[0]->Value=Nodelist[2].L_set[0].L_local_iface_addr;
							 seti->dataGridView2->Rows[0]->Cells[1]->Value=Nodelist[2].L_set[0].L_neighbor_iface_addr;
							 seti->dataGridView2->Rows[0]->Cells[2]->Value=Nodelist[2].L_set[0].L_SYM_time;
							 seti->dataGridView2->Rows[0]->Cells[3]->Value=Nodelist[2].L_set[0].L_ASYM_time;
							 seti->dataGridView2->Rows[0]->Cells[4]->Value=Nodelist[2].L_set[0].L_time;

							 for(i=1;i<(int)Nodelist[2].L_set.size();i++)
							 {
								 row = gcnew DataGridViewRow();
								 row->CreateCells(seti->dataGridView2);
								 row->Cells[0]->Value=Nodelist[2].L_set[i].L_local_iface_addr;
								 row->Cells[1]->Value=Nodelist[2].L_set[i].L_neighbor_iface_addr;
								 row->Cells[2]->Value=Nodelist[2].L_set[i].L_SYM_time;
								 row->Cells[3]->Value=Nodelist[2].L_set[i].L_ASYM_time;
								 row->Cells[4]->Value=Nodelist[2].L_set[i].L_time;
								 seti->dataGridView2->Rows->Add(row);
							 }
						 }

						 //Neighbor Set
						 if((int)Nodelist[2].N_set.size()>0)
						 {
							 seti->dataGridView1->Rows[0]->Cells[0]->Value=Nodelist[2].N_set[0].N_neighbor_main_addr;
							 seti->dataGridView1->Rows[0]->Cells[1]->Value=Nodelist[2].N_set[0].N_status;
							 seti->dataGridView1->Rows[0]->Cells[2]->Value=Nodelist[2].N_set[0].N_willingness;

							 for(i=1;i<(int)Nodelist[2].N_set.size();i++)
							 {
								 row = gcnew DataGridViewRow();
								 row->CreateCells(seti->dataGridView1);
								 row->Cells[0]->Value=Nodelist[2].N_set[i].N_neighbor_main_addr;
								 row->Cells[1]->Value=Nodelist[2].N_set[i].N_status;
								 row->Cells[2]->Value=Nodelist[2].N_set[i].N_willingness;
								 seti->dataGridView1->Rows->Add(row);
							 }
						 }

						 //2-hop Neighbor Set
						 if((int)Nodelist[2]._2hop_set.size()>0)
						 {
							 seti->dataGridView3->Rows[0]->Cells[0]->Value=Nodelist[2]._2hop_set[0].N_neighbor_main_addr;
							 seti->dataGridView3->Rows[0]->Cells[1]->Value=Nodelist[2]._2hop_set[0].N_2hop_addr;
							 seti->dataGridView3->Rows[0]->Cells[2]->Value=Nodelist[2]._2hop_set[0].N_time;

							 for(i=1;i<(int)Nodelist[2]._2hop_set.size();i++)
							 {
								 row=gcnew DataGridViewRow();
								 row->CreateCells(seti->dataGridView3);
								 row->Cells[0]->Value=Nodelist[2]._2hop_set[i].N_neighbor_main_addr;
								 row->Cells[1]->Value=Nodelist[2]._2hop_set[i].N_2hop_addr;
								 row->Cells[2]->Value=Nodelist[2]._2hop_set[i].N_time;
								 seti->dataGridView3->Rows->Add(row);
							 }
						 }

						 //MPR Set
						 if((int)Nodelist[2].Mpr_set.size()>0)
						 {
							 seti->dataGridView4->Rows[0]->Cells[0]->Value=Nodelist[2].Mpr_set[0].MPR_main_addr;

							 for(i=1;i<(int)Nodelist[2].Mpr_set.size();i++)
							 {
								 row=gcnew DataGridViewRow();
								 row->CreateCells(seti->dataGridView4);
								 row->Cells[0]->Value=Nodelist[2].Mpr_set[i].MPR_main_addr;
								 seti->dataGridView4->Rows->Add(row);
							 }
						 }

						 //MS Set
						 if((int)Nodelist[2].MS_set.size()>0)
						 {
							 seti->dataGridView5->Rows[0]->Cells[0]->Value=Nodelist[2].MS_set[0].MS_main_addr;
							 seti->dataGridView5->Rows[0]->Cells[1]->Value=Nodelist[2].MS_set[0].MS_time;

							 for(i=1;i<(int)Nodelist[2].MS_set.size();i++)
							 {
								row=gcnew DataGridViewRow();
								row->CreateCells(seti->dataGridView5);
								row->Cells[0]->Value=Nodelist[2].MS_set[i].MS_main_addr;
								row->Cells[1]->Value=Nodelist[2].MS_set[i].MS_time;
								seti->dataGridView5->Rows->Add(row);
							 }
						 }

						 //Topology Set
						 if((int)Nodelist[2].T_set.size()>0)
						 {
							 seti->dataGridView6->Rows[0]->Cells[0]->Value=Nodelist[2].T_set[0].T_dest_addr;
							 seti->dataGridView6->Rows[0]->Cells[1]->Value=Nodelist[2].T_set[0].T_last_addr;
							 seti->dataGridView6->Rows[0]->Cells[2]->Value=Nodelist[2].T_set[0].T_time;

							 for(i=1;i<(int)Nodelist[2].T_set.size();i++)
							 {
								row=gcnew DataGridViewRow();
								row->CreateCells(seti->dataGridView6);
								row->Cells[0]->Value=Nodelist[2].T_set[i].T_dest_addr;
								row->Cells[1]->Value=Nodelist[2].T_set[i].T_last_addr;
								row->Cells[2]->Value=Nodelist[2].T_set[i].T_time;
								seti->dataGridView6->Rows->Add(row);
							 }
						 }

						 //Routing table
						 if((int)Nodelist[2].R_table.size()>0)
						 {
							 seti->dataGridView7->Rows[0]->Cells[0]->Value=Nodelist[2].R_table[0].R_dest_addr;
							 seti->dataGridView7->Rows[0]->Cells[1]->Value=Nodelist[2].R_table[0].R_next_addr;
							 seti->dataGridView7->Rows[0]->Cells[2]->Value=Nodelist[2].R_table[0].R_dist;
							 seti->dataGridView7->Rows[0]->Cells[3]->Value=Nodelist[2].R_table[0].R_iface_addr;

							 for(i=1;i<(int)Nodelist[2].R_table.size();i++)
							 {
								 row = gcnew DataGridViewRow();
								 row->CreateCells(seti->dataGridView7);
								 row->Cells[0]->Value=Nodelist[2].R_table[i].R_dest_addr;
								 row->Cells[1]->Value=Nodelist[2].R_table[i].R_next_addr;
								 row->Cells[2]->Value=Nodelist[2].R_table[i].R_dist;
								 row->Cells[3]->Value=Nodelist[2].R_table[i].R_iface_addr;
								 seti->dataGridView7->Rows->Add(row);
							 }
						 }

					  }
			private: System::Void pctBox4_Click(System::Object^  sender, System::EventArgs^  e)
					  {
						 Sets^ seti=gcnew Sets();
						 seti->Show();	

						 DataGridViewRow^ row = gcnew DataGridViewRow();
						 int i=0;

						 //Link Set
						 if((int)Nodelist[3].L_set.size()>0)
						 {
							 seti->dataGridView2->Rows[0]->Cells[0]->Value=Nodelist[3].L_set[0].L_local_iface_addr;
							 seti->dataGridView2->Rows[0]->Cells[1]->Value=Nodelist[3].L_set[0].L_neighbor_iface_addr;
							 seti->dataGridView2->Rows[0]->Cells[2]->Value=Nodelist[3].L_set[0].L_SYM_time;
							 seti->dataGridView2->Rows[0]->Cells[3]->Value=Nodelist[3].L_set[0].L_ASYM_time;
							 seti->dataGridView2->Rows[0]->Cells[4]->Value=Nodelist[3].L_set[0].L_time;

							 for(i=1;i<(int)Nodelist[3].L_set.size();i++)
							 {
								 row = gcnew DataGridViewRow();
								 row->CreateCells(seti->dataGridView2);
								 row->Cells[0]->Value=Nodelist[3].L_set[i].L_local_iface_addr;
								 row->Cells[1]->Value=Nodelist[3].L_set[i].L_neighbor_iface_addr;
								 row->Cells[2]->Value=Nodelist[3].L_set[i].L_SYM_time;
								 row->Cells[3]->Value=Nodelist[3].L_set[i].L_ASYM_time;
								 row->Cells[4]->Value=Nodelist[3].L_set[i].L_time;
								 seti->dataGridView2->Rows->Add(row);
							 }
						 }

						 //Neighbor Set
						 if((int)Nodelist[3].N_set.size()>0)
						 {
							 seti->dataGridView1->Rows[0]->Cells[0]->Value=Nodelist[3].N_set[0].N_neighbor_main_addr;
							 seti->dataGridView1->Rows[0]->Cells[1]->Value=Nodelist[3].N_set[0].N_status;
							 seti->dataGridView1->Rows[0]->Cells[2]->Value=Nodelist[3].N_set[0].N_willingness;

							 for(i=1;i<(int)Nodelist[3].N_set.size();i++)
							 {
								 row = gcnew DataGridViewRow();
								 row->CreateCells(seti->dataGridView1);
								 row->Cells[0]->Value=Nodelist[3].N_set[i].N_neighbor_main_addr;
								 row->Cells[1]->Value=Nodelist[3].N_set[i].N_status;
								 row->Cells[2]->Value=Nodelist[3].N_set[i].N_willingness;
								 seti->dataGridView1->Rows->Add(row);
							 }
						 }

						 //2-hop Neighbor Set
						 if((int)Nodelist[3]._2hop_set.size()>0)
						 {
							 seti->dataGridView3->Rows[0]->Cells[0]->Value=Nodelist[3]._2hop_set[0].N_neighbor_main_addr;
							 seti->dataGridView3->Rows[0]->Cells[1]->Value=Nodelist[3]._2hop_set[0].N_2hop_addr;
							 seti->dataGridView3->Rows[0]->Cells[2]->Value=Nodelist[3]._2hop_set[0].N_time;

							 for(i=1;i<(int)Nodelist[3]._2hop_set.size();i++)
							 {
								 row=gcnew DataGridViewRow();
								 row->CreateCells(seti->dataGridView3);
								 row->Cells[0]->Value=Nodelist[3]._2hop_set[i].N_neighbor_main_addr;
								 row->Cells[1]->Value=Nodelist[3]._2hop_set[i].N_2hop_addr;
								 row->Cells[2]->Value=Nodelist[3]._2hop_set[i].N_time;
								 seti->dataGridView3->Rows->Add(row);
							 }
						 }

						 //MPR Set
						 if((int)Nodelist[3].Mpr_set.size()>0)
						 {
							 seti->dataGridView4->Rows[0]->Cells[0]->Value=Nodelist[3].Mpr_set[0].MPR_main_addr;

							 for(i=1;i<(int)Nodelist[3].Mpr_set.size();i++)
							 {
								 row=gcnew DataGridViewRow();
								 row->CreateCells(seti->dataGridView4);
								 row->Cells[0]->Value=Nodelist[3].Mpr_set[i].MPR_main_addr;
								 seti->dataGridView4->Rows->Add(row);
							 }
						 }

						 //MS Set
						 if((int)Nodelist[3].MS_set.size()>0)
						 {
							 seti->dataGridView5->Rows[0]->Cells[0]->Value=Nodelist[3].MS_set[0].MS_main_addr;
							 seti->dataGridView5->Rows[0]->Cells[1]->Value=Nodelist[3].MS_set[0].MS_time;

							 for(i=1;i<(int)Nodelist[3].MS_set.size();i++)
							 {
								row=gcnew DataGridViewRow();
								row->CreateCells(seti->dataGridView5);
								row->Cells[0]->Value=Nodelist[3].MS_set[i].MS_main_addr;
								row->Cells[1]->Value=Nodelist[3].MS_set[i].MS_time;
								seti->dataGridView5->Rows->Add(row);
							 }
						 }

						 //Topology Set
						 if((int)Nodelist[3].T_set.size()>0)
						 {
							 seti->dataGridView6->Rows[0]->Cells[0]->Value=Nodelist[3].T_set[0].T_dest_addr;
							 seti->dataGridView6->Rows[0]->Cells[1]->Value=Nodelist[3].T_set[0].T_last_addr;
							 seti->dataGridView6->Rows[0]->Cells[2]->Value=Nodelist[3].T_set[0].T_time;

							 for(i=1;i<(int)Nodelist[3].T_set.size();i++)
							 {
								row=gcnew DataGridViewRow();
								row->CreateCells(seti->dataGridView6);
								row->Cells[0]->Value=Nodelist[3].T_set[i].T_dest_addr;
								row->Cells[1]->Value=Nodelist[3].T_set[i].T_last_addr;
								row->Cells[2]->Value=Nodelist[3].T_set[i].T_time;
								seti->dataGridView6->Rows->Add(row);
							 }
						 }

						 //Routing table
						 if((int)Nodelist[3].R_table.size()>0)
						 {
							 seti->dataGridView7->Rows[0]->Cells[0]->Value=Nodelist[3].R_table[0].R_dest_addr;
							 seti->dataGridView7->Rows[0]->Cells[1]->Value=Nodelist[3].R_table[0].R_next_addr;
							 seti->dataGridView7->Rows[0]->Cells[2]->Value=Nodelist[3].R_table[0].R_dist;
							 seti->dataGridView7->Rows[0]->Cells[3]->Value=Nodelist[3].R_table[0].R_iface_addr;

							 for(i=1;i<(int)Nodelist[3].R_table.size();i++)
							 {
								 row = gcnew DataGridViewRow();
								 row->CreateCells(seti->dataGridView7);
								 row->Cells[0]->Value=Nodelist[3].R_table[i].R_dest_addr;
								 row->Cells[1]->Value=Nodelist[3].R_table[i].R_next_addr;
								 row->Cells[2]->Value=Nodelist[3].R_table[i].R_dist;
								 row->Cells[3]->Value=Nodelist[3].R_table[i].R_iface_addr;
								 seti->dataGridView7->Rows->Add(row);
							 }
						 }
					  }

		    private: System::Void pctBox5_Click(System::Object^  sender, System::EventArgs^  e)
					  {
						 Sets^ seti=gcnew Sets();
						 seti->Show();	

						 DataGridViewRow^ row = gcnew DataGridViewRow();
						 int i=0;

						 //Link Set
						 if((int)Nodelist[4].L_set.size()>0)
						 {
							 seti->dataGridView2->Rows[0]->Cells[0]->Value=Nodelist[4].L_set[0].L_local_iface_addr;
							 seti->dataGridView2->Rows[0]->Cells[1]->Value=Nodelist[4].L_set[0].L_neighbor_iface_addr;
							 seti->dataGridView2->Rows[0]->Cells[2]->Value=Nodelist[4].L_set[0].L_SYM_time;
							 seti->dataGridView2->Rows[0]->Cells[3]->Value=Nodelist[4].L_set[0].L_ASYM_time;
							 seti->dataGridView2->Rows[0]->Cells[4]->Value=Nodelist[4].L_set[0].L_time;

							 for(i=1;i<(int)Nodelist[4].L_set.size();i++)
							 {
								 row = gcnew DataGridViewRow();
								 row->CreateCells(seti->dataGridView2);
								 row->Cells[0]->Value=Nodelist[4].L_set[i].L_local_iface_addr;
								 row->Cells[1]->Value=Nodelist[4].L_set[i].L_neighbor_iface_addr;
								 row->Cells[2]->Value=Nodelist[4].L_set[i].L_SYM_time;
								 row->Cells[3]->Value=Nodelist[4].L_set[i].L_ASYM_time;
								 row->Cells[4]->Value=Nodelist[4].L_set[i].L_time;
								 seti->dataGridView2->Rows->Add(row);
							 }
						 }

						 //Neighbor Set
						 if((int)Nodelist[4].N_set.size()>0)
						 {
							 seti->dataGridView1->Rows[0]->Cells[0]->Value=Nodelist[4].N_set[0].N_neighbor_main_addr;
							 seti->dataGridView1->Rows[0]->Cells[1]->Value=Nodelist[4].N_set[0].N_status;
							 seti->dataGridView1->Rows[0]->Cells[2]->Value=Nodelist[4].N_set[0].N_willingness;

							 for(i=1;i<(int)Nodelist[4].N_set.size();i++)
							 {
								 row = gcnew DataGridViewRow();
								 row->CreateCells(seti->dataGridView1);
								 row->Cells[0]->Value=Nodelist[4].N_set[i].N_neighbor_main_addr;
								 row->Cells[1]->Value=Nodelist[4].N_set[i].N_status;
								 row->Cells[2]->Value=Nodelist[4].N_set[i].N_willingness;
								 seti->dataGridView1->Rows->Add(row);
							 }
						 }

						 //2-hop Neighbor Set
						 if((int)Nodelist[4]._2hop_set.size()>0)
						 {
							 seti->dataGridView3->Rows[0]->Cells[0]->Value=Nodelist[4]._2hop_set[0].N_neighbor_main_addr;
							 seti->dataGridView3->Rows[0]->Cells[1]->Value=Nodelist[4]._2hop_set[0].N_2hop_addr;
							 seti->dataGridView3->Rows[0]->Cells[2]->Value=Nodelist[4]._2hop_set[0].N_time;

							 for(i=1;i<(int)Nodelist[4]._2hop_set.size();i++)
							 {
								 row=gcnew DataGridViewRow();
								 row->CreateCells(seti->dataGridView3);
								 row->Cells[0]->Value=Nodelist[4]._2hop_set[i].N_neighbor_main_addr;
								 row->Cells[1]->Value=Nodelist[4]._2hop_set[i].N_2hop_addr;
								 row->Cells[2]->Value=Nodelist[4]._2hop_set[i].N_time;
								 seti->dataGridView3->Rows->Add(row);
							 }
						 }

						 //MPR Set
						 if((int)Nodelist[4].Mpr_set.size()>0)
						 {
							 seti->dataGridView4->Rows[0]->Cells[0]->Value=Nodelist[4].Mpr_set[0].MPR_main_addr;

							 for(i=1;i<(int)Nodelist[4].Mpr_set.size();i++)
							 {
								 row=gcnew DataGridViewRow();
								 row->CreateCells(seti->dataGridView4);
								 row->Cells[0]->Value=Nodelist[4].Mpr_set[i].MPR_main_addr;
								 seti->dataGridView4->Rows->Add(row);
							 }
						 }

						 //MS Set
						 if((int)Nodelist[4].MS_set.size()>0)
						 {
							 seti->dataGridView5->Rows[0]->Cells[0]->Value=Nodelist[4].MS_set[0].MS_main_addr;
							 seti->dataGridView5->Rows[0]->Cells[1]->Value=Nodelist[4].MS_set[0].MS_time;

							 for(i=1;i<(int)Nodelist[4].MS_set.size();i++)
							 {
								row=gcnew DataGridViewRow();
								row->CreateCells(seti->dataGridView5);
								row->Cells[0]->Value=Nodelist[4].MS_set[i].MS_main_addr;
								row->Cells[1]->Value=Nodelist[4].MS_set[i].MS_time;
								seti->dataGridView5->Rows->Add(row);
							 }
						 }

						 //Topology Set
						 if((int)Nodelist[4].T_set.size()>0)
						 {
							 seti->dataGridView6->Rows[0]->Cells[0]->Value=Nodelist[4].T_set[0].T_dest_addr;
							 seti->dataGridView6->Rows[0]->Cells[1]->Value=Nodelist[4].T_set[0].T_last_addr;
							 seti->dataGridView6->Rows[0]->Cells[2]->Value=Nodelist[4].T_set[0].T_time;

							 for(i=1;i<(int)Nodelist[4].T_set.size();i++)
							 {
								row=gcnew DataGridViewRow();
								row->CreateCells(seti->dataGridView6);
								row->Cells[0]->Value=Nodelist[4].T_set[i].T_dest_addr;
								row->Cells[1]->Value=Nodelist[4].T_set[i].T_last_addr;
								row->Cells[2]->Value=Nodelist[4].T_set[i].T_time;
								seti->dataGridView6->Rows->Add(row);
							 }
						 }

						 //Routing table
						 if((int)Nodelist[4].R_table.size()>0)
						 {
							 seti->dataGridView7->Rows[0]->Cells[0]->Value=Nodelist[4].R_table[0].R_dest_addr;
							 seti->dataGridView7->Rows[0]->Cells[1]->Value=Nodelist[4].R_table[0].R_next_addr;
							 seti->dataGridView7->Rows[0]->Cells[2]->Value=Nodelist[4].R_table[0].R_dist;
							 seti->dataGridView7->Rows[0]->Cells[3]->Value=Nodelist[4].R_table[0].R_iface_addr;

							 for(i=1;i<(int)Nodelist[4].R_table.size();i++)
							 {
								 row = gcnew DataGridViewRow();
								 row->CreateCells(seti->dataGridView7);
								 row->Cells[0]->Value=Nodelist[4].R_table[i].R_dest_addr;
								 row->Cells[1]->Value=Nodelist[4].R_table[i].R_next_addr;
								 row->Cells[2]->Value=Nodelist[4].R_table[i].R_dist;
								 row->Cells[3]->Value=Nodelist[4].R_table[i].R_iface_addr;
								 seti->dataGridView7->Rows->Add(row);
							 }
						 }
					  }

			private: System::Void pctBox6_Click(System::Object^  sender, System::EventArgs^  e)
					  {
						 Sets^ seti=gcnew Sets();
						 seti->Show();				 

						 DataGridViewRow^ row = gcnew DataGridViewRow();
						 int i=0;

						 //Link Set
						 if((int)Nodelist[5].L_set.size()>0)
						 {
							 seti->dataGridView2->Rows[0]->Cells[0]->Value=Nodelist[5].L_set[0].L_local_iface_addr;
							 seti->dataGridView2->Rows[0]->Cells[1]->Value=Nodelist[5].L_set[0].L_neighbor_iface_addr;
							 seti->dataGridView2->Rows[0]->Cells[2]->Value=Nodelist[5].L_set[0].L_SYM_time;
							 seti->dataGridView2->Rows[0]->Cells[3]->Value=Nodelist[5].L_set[0].L_ASYM_time;
							 seti->dataGridView2->Rows[0]->Cells[4]->Value=Nodelist[5].L_set[0].L_time;

							 for(i=1;i<(int)Nodelist[5].L_set.size();i++)
							 {
								 row = gcnew DataGridViewRow();
								 row->CreateCells(seti->dataGridView2);
								 row->Cells[0]->Value=Nodelist[5].L_set[i].L_local_iface_addr;
								 row->Cells[1]->Value=Nodelist[5].L_set[i].L_neighbor_iface_addr;
								 row->Cells[2]->Value=Nodelist[5].L_set[i].L_SYM_time;
								 row->Cells[3]->Value=Nodelist[5].L_set[i].L_ASYM_time;
								 row->Cells[4]->Value=Nodelist[5].L_set[i].L_time;
								 seti->dataGridView2->Rows->Add(row);
							 }
						 }

						 //Neighbor Set
						 if((int)Nodelist[5].N_set.size()>0)
						 {
							 seti->dataGridView1->Rows[0]->Cells[0]->Value=Nodelist[5].N_set[0].N_neighbor_main_addr;
							 seti->dataGridView1->Rows[0]->Cells[1]->Value=Nodelist[5].N_set[0].N_status;
							 seti->dataGridView1->Rows[0]->Cells[2]->Value=Nodelist[5].N_set[0].N_willingness;

							 for(i=1;i<(int)Nodelist[5].N_set.size();i++)
							 {
								 row = gcnew DataGridViewRow();
								 row->CreateCells(seti->dataGridView1);
								 row->Cells[0]->Value=Nodelist[5].N_set[i].N_neighbor_main_addr;
								 row->Cells[1]->Value=Nodelist[5].N_set[i].N_status;
								 row->Cells[2]->Value=Nodelist[5].N_set[i].N_willingness;
								 seti->dataGridView1->Rows->Add(row);
							 }
						 }

						 //2-hop Neighbor Set
						 if((int)Nodelist[5]._2hop_set.size()>0)
						 {
							 seti->dataGridView3->Rows[0]->Cells[0]->Value=Nodelist[5]._2hop_set[0].N_neighbor_main_addr;
							 seti->dataGridView3->Rows[0]->Cells[1]->Value=Nodelist[5]._2hop_set[0].N_2hop_addr;
							 seti->dataGridView3->Rows[0]->Cells[2]->Value=Nodelist[5]._2hop_set[0].N_time;

							 for(i=1;i<(int)Nodelist[5]._2hop_set.size();i++)
							 {
								 row=gcnew DataGridViewRow();
								 row->CreateCells(seti->dataGridView3);
								 row->Cells[0]->Value=Nodelist[5]._2hop_set[i].N_neighbor_main_addr;
								 row->Cells[1]->Value=Nodelist[5]._2hop_set[i].N_2hop_addr;
								 row->Cells[2]->Value=Nodelist[5]._2hop_set[i].N_time;
								 seti->dataGridView3->Rows->Add(row);
							 }
						 }

						 //MPR Set
						 if((int)Nodelist[5].Mpr_set.size()>0)
						 {
							 seti->dataGridView4->Rows[0]->Cells[0]->Value=Nodelist[5].Mpr_set[0].MPR_main_addr;

							 for(i=1;i<(int)Nodelist[5].Mpr_set.size();i++)
							 {
								 row=gcnew DataGridViewRow();
								 row->CreateCells(seti->dataGridView4);
								 row->Cells[0]->Value=Nodelist[5].Mpr_set[i].MPR_main_addr;
								 seti->dataGridView4->Rows->Add(row);
							 }
						 }

						 //MS Set
						 if((int)Nodelist[5].MS_set.size()>0)
						 {
							 seti->dataGridView5->Rows[0]->Cells[0]->Value=Nodelist[5].MS_set[0].MS_main_addr;
							 seti->dataGridView5->Rows[0]->Cells[1]->Value=Nodelist[5].MS_set[0].MS_time;

							 for(i=1;i<(int)Nodelist[5].MS_set.size();i++)
							 {
								row=gcnew DataGridViewRow();
								row->CreateCells(seti->dataGridView5);
								row->Cells[0]->Value=Nodelist[5].MS_set[i].MS_main_addr;
								row->Cells[1]->Value=Nodelist[5].MS_set[i].MS_time;
								seti->dataGridView5->Rows->Add(row);
							 }
						 }

						 //Topology Set
						 if((int)Nodelist[5].T_set.size()>0)
						 {
							 seti->dataGridView6->Rows[0]->Cells[0]->Value=Nodelist[5].T_set[0].T_dest_addr;
							 seti->dataGridView6->Rows[0]->Cells[1]->Value=Nodelist[5].T_set[0].T_last_addr;
							 seti->dataGridView6->Rows[0]->Cells[2]->Value=Nodelist[5].T_set[0].T_time;

							 for(i=1;i<(int)Nodelist[5].T_set.size();i++)
							 {
								row=gcnew DataGridViewRow();
								row->CreateCells(seti->dataGridView6);
								row->Cells[0]->Value=Nodelist[5].T_set[i].T_dest_addr;
								row->Cells[1]->Value=Nodelist[5].T_set[i].T_last_addr;
								row->Cells[2]->Value=Nodelist[5].T_set[i].T_time;
								seti->dataGridView6->Rows->Add(row);
							 }
						 }

						 //Routing table
						 if((int)Nodelist[5].R_table.size()>0)
						 {
							 seti->dataGridView7->Rows[0]->Cells[0]->Value=Nodelist[5].R_table[0].R_dest_addr;
							 seti->dataGridView7->Rows[0]->Cells[1]->Value=Nodelist[5].R_table[0].R_next_addr;
							 seti->dataGridView7->Rows[0]->Cells[2]->Value=Nodelist[5].R_table[0].R_dist;
							 seti->dataGridView7->Rows[0]->Cells[3]->Value=Nodelist[5].R_table[0].R_iface_addr;

							 for(i=1;i<(int)Nodelist[5].R_table.size();i++)
							 {
								 row = gcnew DataGridViewRow();
								 row->CreateCells(seti->dataGridView7);
								 row->Cells[0]->Value=Nodelist[5].R_table[i].R_dest_addr;
								 row->Cells[1]->Value=Nodelist[5].R_table[i].R_next_addr;
								 row->Cells[2]->Value=Nodelist[5].R_table[i].R_dist;
								 row->Cells[3]->Value=Nodelist[5].R_table[i].R_iface_addr;
								 seti->dataGridView7->Rows->Add(row);
							 }
						 }
					  }

			private: System::Void pctBox7_Click(System::Object^  sender, System::EventArgs^  e)
					  {
						 Sets^ seti=gcnew Sets();
						 seti->Show();		

						 DataGridViewRow^ row = gcnew DataGridViewRow();
						 int i=0;

						 //Link Set
						 if((int)Nodelist[6].L_set.size()>0)
						 {
							 seti->dataGridView2->Rows[0]->Cells[0]->Value=Nodelist[6].L_set[0].L_local_iface_addr;
							 seti->dataGridView2->Rows[0]->Cells[1]->Value=Nodelist[6].L_set[0].L_neighbor_iface_addr;
							 seti->dataGridView2->Rows[0]->Cells[2]->Value=Nodelist[6].L_set[0].L_SYM_time;
							 seti->dataGridView2->Rows[0]->Cells[3]->Value=Nodelist[6].L_set[0].L_ASYM_time;
							 seti->dataGridView2->Rows[0]->Cells[4]->Value=Nodelist[6].L_set[0].L_time;

							 for(i=1;i<(int)Nodelist[6].L_set.size();i++)
							 {
								 row = gcnew DataGridViewRow();
								 row->CreateCells(seti->dataGridView2);
								 row->Cells[0]->Value=Nodelist[6].L_set[i].L_local_iface_addr;
								 row->Cells[1]->Value=Nodelist[6].L_set[i].L_neighbor_iface_addr;
								 row->Cells[2]->Value=Nodelist[6].L_set[i].L_SYM_time;
								 row->Cells[3]->Value=Nodelist[6].L_set[i].L_ASYM_time;
								 row->Cells[4]->Value=Nodelist[6].L_set[i].L_time;
								 seti->dataGridView2->Rows->Add(row);
							 }
						 }

						 //Neighbor Set
						 if((int)Nodelist[6].N_set.size()>0)
						 {
							 seti->dataGridView1->Rows[0]->Cells[0]->Value=Nodelist[6].N_set[0].N_neighbor_main_addr;
							 seti->dataGridView1->Rows[0]->Cells[1]->Value=Nodelist[6].N_set[0].N_status;
							 seti->dataGridView1->Rows[0]->Cells[2]->Value=Nodelist[6].N_set[0].N_willingness;

							 for(i=1;i<(int)Nodelist[6].N_set.size();i++)
							 {
								 row = gcnew DataGridViewRow();
								 row->CreateCells(seti->dataGridView1);
								 row->Cells[0]->Value=Nodelist[6].N_set[i].N_neighbor_main_addr;
								 row->Cells[1]->Value=Nodelist[6].N_set[i].N_status;
								 row->Cells[2]->Value=Nodelist[6].N_set[i].N_willingness;
								 seti->dataGridView1->Rows->Add(row);
							 }
						 }

						 //2-hop Neighbor Set
						 if((int)Nodelist[6]._2hop_set.size()>0)
						 {
							 seti->dataGridView3->Rows[0]->Cells[0]->Value=Nodelist[6]._2hop_set[0].N_neighbor_main_addr;
							 seti->dataGridView3->Rows[0]->Cells[1]->Value=Nodelist[6]._2hop_set[0].N_2hop_addr;
							 seti->dataGridView3->Rows[0]->Cells[2]->Value=Nodelist[6]._2hop_set[0].N_time;

							 for(i=1;i<(int)Nodelist[6]._2hop_set.size();i++)
							 {
								 row=gcnew DataGridViewRow();
								 row->CreateCells(seti->dataGridView3);
								 row->Cells[0]->Value=Nodelist[6]._2hop_set[i].N_neighbor_main_addr;
								 row->Cells[1]->Value=Nodelist[6]._2hop_set[i].N_2hop_addr;
								 row->Cells[2]->Value=Nodelist[6]._2hop_set[i].N_time;
								 seti->dataGridView3->Rows->Add(row);
							 }
						 }

						 //MPR Set
						 if((int)Nodelist[6].Mpr_set.size()>0)
						 {
							 seti->dataGridView4->Rows[0]->Cells[0]->Value=Nodelist[6].Mpr_set[0].MPR_main_addr;

							 for(i=1;i<(int)Nodelist[6].Mpr_set.size();i++)
							 {
								 row=gcnew DataGridViewRow();
								 row->CreateCells(seti->dataGridView4);
								 row->Cells[0]->Value=Nodelist[6].Mpr_set[i].MPR_main_addr;
								 seti->dataGridView4->Rows->Add(row);
							 }
						 }

						 //MS Set
						 if((int)Nodelist[6].MS_set.size()>0)
						 {
							 seti->dataGridView5->Rows[0]->Cells[0]->Value=Nodelist[6].MS_set[0].MS_main_addr;
							 seti->dataGridView5->Rows[0]->Cells[1]->Value=Nodelist[6].MS_set[0].MS_time;

							 for(i=1;i<(int)Nodelist[6].MS_set.size();i++)
							 {
								row=gcnew DataGridViewRow();
								row->CreateCells(seti->dataGridView5);
								row->Cells[0]->Value=Nodelist[6].MS_set[i].MS_main_addr;
								row->Cells[1]->Value=Nodelist[6].MS_set[i].MS_time;
								seti->dataGridView5->Rows->Add(row);
							 }
						 }

						 //Topology Set
						 if((int)Nodelist[6].T_set.size()>0)
						 {
							 seti->dataGridView6->Rows[0]->Cells[0]->Value=Nodelist[6].T_set[0].T_dest_addr;
							 seti->dataGridView6->Rows[0]->Cells[1]->Value=Nodelist[6].T_set[0].T_last_addr;
							 seti->dataGridView6->Rows[0]->Cells[2]->Value=Nodelist[6].T_set[0].T_time;

							 for(i=1;i<(int)Nodelist[6].T_set.size();i++)
							 {
								row=gcnew DataGridViewRow();
								row->CreateCells(seti->dataGridView6);
								row->Cells[0]->Value=Nodelist[6].T_set[i].T_dest_addr;
								row->Cells[1]->Value=Nodelist[6].T_set[i].T_last_addr;
								row->Cells[2]->Value=Nodelist[6].T_set[i].T_time;
								seti->dataGridView6->Rows->Add(row);
							 }
						 }

						 //Routing table
						 if((int)Nodelist[6].R_table.size()>0)
						 {
							 seti->dataGridView7->Rows[0]->Cells[0]->Value=Nodelist[6].R_table[0].R_dest_addr;
							 seti->dataGridView7->Rows[0]->Cells[1]->Value=Nodelist[6].R_table[0].R_next_addr;
							 seti->dataGridView7->Rows[0]->Cells[2]->Value=Nodelist[6].R_table[0].R_dist;
							 seti->dataGridView7->Rows[0]->Cells[3]->Value=Nodelist[6].R_table[0].R_iface_addr;

							 for(i=1;i<(int)Nodelist[6].R_table.size();i++)
							 {
								 row = gcnew DataGridViewRow();
								 row->CreateCells(seti->dataGridView7);
								 row->Cells[0]->Value=Nodelist[6].R_table[i].R_dest_addr;
								 row->Cells[1]->Value=Nodelist[6].R_table[i].R_next_addr;
								 row->Cells[2]->Value=Nodelist[6].R_table[i].R_dist;
								 row->Cells[3]->Value=Nodelist[6].R_table[i].R_iface_addr;
								 seti->dataGridView7->Rows->Add(row);
							 }
						 }

					  }

			private: System::Void pctBox8_Click(System::Object^  sender, System::EventArgs^  e)
					  {
						 Sets^ seti=gcnew Sets();
						 seti->Show();				 

						 DataGridViewRow^ row = gcnew DataGridViewRow();
						 int i=0;

						 //Link Set
						 if((int)Nodelist[7].L_set.size()>0)
						 {
							 seti->dataGridView2->Rows[0]->Cells[0]->Value=Nodelist[7].L_set[0].L_local_iface_addr;
							 seti->dataGridView2->Rows[0]->Cells[1]->Value=Nodelist[7].L_set[0].L_neighbor_iface_addr;
							 seti->dataGridView2->Rows[0]->Cells[2]->Value=Nodelist[7].L_set[0].L_SYM_time;
							 seti->dataGridView2->Rows[0]->Cells[3]->Value=Nodelist[7].L_set[0].L_ASYM_time;
							 seti->dataGridView2->Rows[0]->Cells[4]->Value=Nodelist[7].L_set[0].L_time;

							 for(i=1;i<(int)Nodelist[7].L_set.size();i++)
							 {
								 row = gcnew DataGridViewRow();
								 row->CreateCells(seti->dataGridView2);
								 row->Cells[0]->Value=Nodelist[7].L_set[i].L_local_iface_addr;
								 row->Cells[1]->Value=Nodelist[7].L_set[i].L_neighbor_iface_addr;
								 row->Cells[2]->Value=Nodelist[7].L_set[i].L_SYM_time;
								 row->Cells[3]->Value=Nodelist[7].L_set[i].L_ASYM_time;
								 row->Cells[4]->Value=Nodelist[7].L_set[i].L_time;
								 seti->dataGridView2->Rows->Add(row);
							 }
						 }

						 //Neighbor Set
						 if((int)Nodelist[7].N_set.size()>0)
						 {
							 seti->dataGridView1->Rows[0]->Cells[0]->Value=Nodelist[7].N_set[0].N_neighbor_main_addr;
							 seti->dataGridView1->Rows[0]->Cells[1]->Value=Nodelist[7].N_set[0].N_status;
							 seti->dataGridView1->Rows[0]->Cells[2]->Value=Nodelist[7].N_set[0].N_willingness;

							 for(i=1;i<(int)Nodelist[7].N_set.size();i++)
							 {
								 row = gcnew DataGridViewRow();
								 row->CreateCells(seti->dataGridView1);
								 row->Cells[0]->Value=Nodelist[7].N_set[i].N_neighbor_main_addr;
								 row->Cells[1]->Value=Nodelist[7].N_set[i].N_status;
								 row->Cells[2]->Value=Nodelist[7].N_set[i].N_willingness;
								 seti->dataGridView1->Rows->Add(row);
							 }
						 }

						 //2-hop Neighbor Set
						 if((int)Nodelist[7]._2hop_set.size()>0)
						 {
							 seti->dataGridView3->Rows[0]->Cells[0]->Value=Nodelist[7]._2hop_set[0].N_neighbor_main_addr;
							 seti->dataGridView3->Rows[0]->Cells[1]->Value=Nodelist[7]._2hop_set[0].N_2hop_addr;
							 seti->dataGridView3->Rows[0]->Cells[2]->Value=Nodelist[7]._2hop_set[0].N_time;

							 for(i=1;i<(int)Nodelist[7]._2hop_set.size();i++)
							 {
								 row=gcnew DataGridViewRow();
								 row->CreateCells(seti->dataGridView3);
								 row->Cells[0]->Value=Nodelist[7]._2hop_set[i].N_neighbor_main_addr;
								 row->Cells[1]->Value=Nodelist[7]._2hop_set[i].N_2hop_addr;
								 row->Cells[2]->Value=Nodelist[7]._2hop_set[i].N_time;
								 seti->dataGridView3->Rows->Add(row);
							 }
						 }

						 //MPR Set
						 if((int)Nodelist[7].Mpr_set.size()>0)
						 {
							 seti->dataGridView4->Rows[0]->Cells[0]->Value=Nodelist[7].Mpr_set[0].MPR_main_addr;

							 for(i=1;i<(int)Nodelist[7].Mpr_set.size();i++)
							 {
								 row=gcnew DataGridViewRow();
								 row->CreateCells(seti->dataGridView4);
								 row->Cells[0]->Value=Nodelist[7].Mpr_set[i].MPR_main_addr;
								 seti->dataGridView4->Rows->Add(row);
							 }
						 }

						 //MS Set
						 if((int)Nodelist[7].MS_set.size()>0)
						 {
							 seti->dataGridView5->Rows[0]->Cells[0]->Value=Nodelist[7].MS_set[0].MS_main_addr;
							 seti->dataGridView5->Rows[0]->Cells[1]->Value=Nodelist[7].MS_set[0].MS_time;

							 for(i=1;i<(int)Nodelist[7].MS_set.size();i++)
							 {
								row=gcnew DataGridViewRow();
								row->CreateCells(seti->dataGridView5);
								row->Cells[0]->Value=Nodelist[7].MS_set[i].MS_main_addr;
								row->Cells[1]->Value=Nodelist[7].MS_set[i].MS_time;
								seti->dataGridView5->Rows->Add(row);
							 }
						 }

						 //Topology Set
						 if((int)Nodelist[7].T_set.size()>0)
						 {
							 seti->dataGridView6->Rows[0]->Cells[0]->Value=Nodelist[7].T_set[0].T_dest_addr;
							 seti->dataGridView6->Rows[0]->Cells[1]->Value=Nodelist[7].T_set[0].T_last_addr;
							 seti->dataGridView6->Rows[0]->Cells[2]->Value=Nodelist[7].T_set[0].T_time;

							 for(i=1;i<(int)Nodelist[7].T_set.size();i++)
							 {
								row=gcnew DataGridViewRow();
								row->CreateCells(seti->dataGridView6);
								row->Cells[0]->Value=Nodelist[7].T_set[i].T_dest_addr;
								row->Cells[1]->Value=Nodelist[7].T_set[i].T_last_addr;
								row->Cells[2]->Value=Nodelist[7].T_set[i].T_time;
								seti->dataGridView6->Rows->Add(row);
							 }
						 }

						 //Routing table
						 if((int)Nodelist[7].R_table.size()>0)
						 {
							 seti->dataGridView7->Rows[0]->Cells[0]->Value=Nodelist[7].R_table[0].R_dest_addr;
							 seti->dataGridView7->Rows[0]->Cells[1]->Value=Nodelist[7].R_table[0].R_next_addr;
							 seti->dataGridView7->Rows[0]->Cells[2]->Value=Nodelist[7].R_table[0].R_dist;
							 seti->dataGridView7->Rows[0]->Cells[3]->Value=Nodelist[7].R_table[0].R_iface_addr;

							 for(i=1;i<(int)Nodelist[7].R_table.size();i++)
							 {
								 row = gcnew DataGridViewRow();
								 row->CreateCells(seti->dataGridView7);
								 row->Cells[0]->Value=Nodelist[7].R_table[i].R_dest_addr;
								 row->Cells[1]->Value=Nodelist[7].R_table[i].R_next_addr;
								 row->Cells[2]->Value=Nodelist[7].R_table[i].R_dist;
								 row->Cells[3]->Value=Nodelist[7].R_table[i].R_iface_addr;
								 seti->dataGridView7->Rows->Add(row);
							 }
						 }
					  }

			private: System::Void pctBox9_Click(System::Object^  sender, System::EventArgs^  e)
					  {
						 Sets^ seti=gcnew Sets();
						 seti->Show();				 

						 DataGridViewRow^ row = gcnew DataGridViewRow();
						 int i=0;

						 //Link Set
						 if((int)Nodelist[8].L_set.size()>0)
						 {
							 seti->dataGridView2->Rows[0]->Cells[0]->Value=Nodelist[8].L_set[0].L_local_iface_addr;
							 seti->dataGridView2->Rows[0]->Cells[1]->Value=Nodelist[8].L_set[0].L_neighbor_iface_addr;
							 seti->dataGridView2->Rows[0]->Cells[2]->Value=Nodelist[8].L_set[0].L_SYM_time;
							 seti->dataGridView2->Rows[0]->Cells[3]->Value=Nodelist[8].L_set[0].L_ASYM_time;
							 seti->dataGridView2->Rows[0]->Cells[4]->Value=Nodelist[8].L_set[0].L_time;

							 for(i=1;i<(int)Nodelist[8].L_set.size();i++)
							 {
								 row = gcnew DataGridViewRow();
								 row->CreateCells(seti->dataGridView2);
								 row->Cells[0]->Value=Nodelist[8].L_set[i].L_local_iface_addr;
								 row->Cells[1]->Value=Nodelist[8].L_set[i].L_neighbor_iface_addr;
								 row->Cells[2]->Value=Nodelist[8].L_set[i].L_SYM_time;
								 row->Cells[3]->Value=Nodelist[8].L_set[i].L_ASYM_time;
								 row->Cells[4]->Value=Nodelist[8].L_set[i].L_time;
								 seti->dataGridView2->Rows->Add(row);
							 }
						 }

						 //Neighbor Set
						 if((int)Nodelist[8].N_set.size()>0)
						 {
							 seti->dataGridView1->Rows[0]->Cells[0]->Value=Nodelist[8].N_set[0].N_neighbor_main_addr;
							 seti->dataGridView1->Rows[0]->Cells[1]->Value=Nodelist[8].N_set[0].N_status;
							 seti->dataGridView1->Rows[0]->Cells[2]->Value=Nodelist[8].N_set[0].N_willingness;

							 for(i=1;i<(int)Nodelist[8].N_set.size();i++)
							 {
								 row = gcnew DataGridViewRow();
								 row->CreateCells(seti->dataGridView1);
								 row->Cells[0]->Value=Nodelist[8].N_set[i].N_neighbor_main_addr;
								 row->Cells[1]->Value=Nodelist[8].N_set[i].N_status;
								 row->Cells[2]->Value=Nodelist[8].N_set[i].N_willingness;
								 seti->dataGridView1->Rows->Add(row);
							 }
						 }

						 //2-hop Neighbor Set
						 if((int)Nodelist[8]._2hop_set.size()>0)
						 {
							 seti->dataGridView3->Rows[0]->Cells[0]->Value=Nodelist[8]._2hop_set[0].N_neighbor_main_addr;
							 seti->dataGridView3->Rows[0]->Cells[1]->Value=Nodelist[8]._2hop_set[0].N_2hop_addr;
							 seti->dataGridView3->Rows[0]->Cells[2]->Value=Nodelist[8]._2hop_set[0].N_time;

							 for(i=1;i<(int)Nodelist[8]._2hop_set.size();i++)
							 {
								 row=gcnew DataGridViewRow();
								 row->CreateCells(seti->dataGridView3);
								 row->Cells[0]->Value=Nodelist[8]._2hop_set[i].N_neighbor_main_addr;
								 row->Cells[1]->Value=Nodelist[8]._2hop_set[i].N_2hop_addr;
								 row->Cells[2]->Value=Nodelist[8]._2hop_set[i].N_time;
								 seti->dataGridView3->Rows->Add(row);
							 }
						 }

						 //MPR Set
						 if((int)Nodelist[8].Mpr_set.size()>0)
						 {
							 seti->dataGridView4->Rows[0]->Cells[0]->Value=Nodelist[8].Mpr_set[0].MPR_main_addr;

							 for(i=1;i<(int)Nodelist[8].Mpr_set.size();i++)
							 {
								 row=gcnew DataGridViewRow();
								 row->CreateCells(seti->dataGridView4);
								 row->Cells[0]->Value=Nodelist[8].Mpr_set[i].MPR_main_addr;
								 seti->dataGridView4->Rows->Add(row);
							 }
						 }

						 //MS Set
						 if((int)Nodelist[8].MS_set.size()>0)
						 {
							 seti->dataGridView5->Rows[0]->Cells[0]->Value=Nodelist[8].MS_set[0].MS_main_addr;
							 seti->dataGridView5->Rows[0]->Cells[1]->Value=Nodelist[8].MS_set[0].MS_time;

							 for(i=1;i<(int)Nodelist[8].MS_set.size();i++)
							 {
								row=gcnew DataGridViewRow();
								row->CreateCells(seti->dataGridView5);
								row->Cells[0]->Value=Nodelist[8].MS_set[i].MS_main_addr;
								row->Cells[1]->Value=Nodelist[8].MS_set[i].MS_time;
								seti->dataGridView5->Rows->Add(row);
							 }
						 }

						 //Topology Set
						 if((int)Nodelist[8].T_set.size()>0)
						 {
							 seti->dataGridView6->Rows[0]->Cells[0]->Value=Nodelist[8].T_set[0].T_dest_addr;
							 seti->dataGridView6->Rows[0]->Cells[1]->Value=Nodelist[8].T_set[0].T_last_addr;
							 seti->dataGridView6->Rows[0]->Cells[2]->Value=Nodelist[8].T_set[0].T_time;

							 for(i=1;i<(int)Nodelist[8].T_set.size();i++)
							 {
								row=gcnew DataGridViewRow();
								row->CreateCells(seti->dataGridView6);
								row->Cells[0]->Value=Nodelist[8].T_set[i].T_dest_addr;
								row->Cells[1]->Value=Nodelist[8].T_set[i].T_last_addr;
								row->Cells[2]->Value=Nodelist[8].T_set[i].T_time;
								seti->dataGridView6->Rows->Add(row);
							 }
						 }

						 //Routing table
						 if((int)Nodelist[8].R_table.size()>0)
						 {
							 seti->dataGridView7->Rows[0]->Cells[0]->Value=Nodelist[8].R_table[0].R_dest_addr;
							 seti->dataGridView7->Rows[0]->Cells[1]->Value=Nodelist[8].R_table[0].R_next_addr;
							 seti->dataGridView7->Rows[0]->Cells[2]->Value=Nodelist[8].R_table[0].R_dist;
							 seti->dataGridView7->Rows[0]->Cells[3]->Value=Nodelist[8].R_table[0].R_iface_addr;

							 for(i=1;i<(int)Nodelist[8].R_table.size();i++)
							 {
								 row = gcnew DataGridViewRow();
								 row->CreateCells(seti->dataGridView7);
								 row->Cells[0]->Value=Nodelist[8].R_table[i].R_dest_addr;
								 row->Cells[1]->Value=Nodelist[8].R_table[i].R_next_addr;
								 row->Cells[2]->Value=Nodelist[8].R_table[i].R_dist;
								 row->Cells[3]->Value=Nodelist[8].R_table[i].R_iface_addr;
								 seti->dataGridView7->Rows->Add(row);
							 }
						 }
					  }

			private: System::Void pctBox10_Click(System::Object^  sender, System::EventArgs^  e)
					  {
						 Sets^ seti=gcnew Sets();
						 seti->Show();				 

						 DataGridViewRow^ row = gcnew DataGridViewRow();
						 int i=0;

						 //Link Set
						 if((int)Nodelist[9].L_set.size()>0)
						 {
							 seti->dataGridView2->Rows[0]->Cells[0]->Value=Nodelist[9].L_set[0].L_local_iface_addr;
							 seti->dataGridView2->Rows[0]->Cells[1]->Value=Nodelist[9].L_set[0].L_neighbor_iface_addr;
							 seti->dataGridView2->Rows[0]->Cells[2]->Value=Nodelist[9].L_set[0].L_SYM_time;
							 seti->dataGridView2->Rows[0]->Cells[3]->Value=Nodelist[9].L_set[0].L_ASYM_time;
							 seti->dataGridView2->Rows[0]->Cells[4]->Value=Nodelist[9].L_set[0].L_time;

							 for(i=1;i<(int)Nodelist[9].L_set.size();i++)
							 {
								 row = gcnew DataGridViewRow();
								 row->CreateCells(seti->dataGridView2);
								 row->Cells[0]->Value=Nodelist[9].L_set[i].L_local_iface_addr;
								 row->Cells[1]->Value=Nodelist[9].L_set[i].L_neighbor_iface_addr;
								 row->Cells[2]->Value=Nodelist[9].L_set[i].L_SYM_time;
								 row->Cells[3]->Value=Nodelist[9].L_set[i].L_ASYM_time;
								 row->Cells[4]->Value=Nodelist[9].L_set[i].L_time;
								 seti->dataGridView2->Rows->Add(row);
							 }
						 }

						 //Neighbor Set
						 if((int)Nodelist[9].N_set.size()>0)
						 {
							 seti->dataGridView1->Rows[0]->Cells[0]->Value=Nodelist[9].N_set[0].N_neighbor_main_addr;
							 seti->dataGridView1->Rows[0]->Cells[1]->Value=Nodelist[9].N_set[0].N_status;
							 seti->dataGridView1->Rows[0]->Cells[2]->Value=Nodelist[9].N_set[0].N_willingness;

							 for(i=1;i<(int)Nodelist[9].N_set.size();i++)
							 {
								 row = gcnew DataGridViewRow();
								 row->CreateCells(seti->dataGridView1);
								 row->Cells[0]->Value=Nodelist[9].N_set[i].N_neighbor_main_addr;
								 row->Cells[1]->Value=Nodelist[9].N_set[i].N_status;
								 row->Cells[2]->Value=Nodelist[9].N_set[i].N_willingness;
								 seti->dataGridView1->Rows->Add(row);
							 }
						 }

						 //2-hop Neighbor Set
						 if((int)Nodelist[9]._2hop_set.size()>0)
						 {
							 seti->dataGridView3->Rows[0]->Cells[0]->Value=Nodelist[9]._2hop_set[0].N_neighbor_main_addr;
							 seti->dataGridView3->Rows[0]->Cells[1]->Value=Nodelist[9]._2hop_set[0].N_2hop_addr;
							 seti->dataGridView3->Rows[0]->Cells[2]->Value=Nodelist[9]._2hop_set[0].N_time;

							 for(i=1;i<(int)Nodelist[9]._2hop_set.size();i++)
							 {
								 row=gcnew DataGridViewRow();
								 row->CreateCells(seti->dataGridView3);
								 row->Cells[0]->Value=Nodelist[9]._2hop_set[i].N_neighbor_main_addr;
								 row->Cells[1]->Value=Nodelist[9]._2hop_set[i].N_2hop_addr;
								 row->Cells[2]->Value=Nodelist[9]._2hop_set[i].N_time;
								 seti->dataGridView3->Rows->Add(row);
							 }
						 }

						 //MPR Set
						 if((int)Nodelist[9].Mpr_set.size()>0)
						 {
							 seti->dataGridView4->Rows[0]->Cells[0]->Value=Nodelist[9].Mpr_set[0].MPR_main_addr;

							 for(i=1;i<(int)Nodelist[9].Mpr_set.size();i++)
							 {
								 row=gcnew DataGridViewRow();
								 row->CreateCells(seti->dataGridView4);
								 row->Cells[0]->Value=Nodelist[9].Mpr_set[i].MPR_main_addr;
								 seti->dataGridView4->Rows->Add(row);
							 }
						 }

						 //MS Set
						 if((int)Nodelist[9].MS_set.size()>0)
						 {
							 seti->dataGridView5->Rows[0]->Cells[0]->Value=Nodelist[9].MS_set[0].MS_main_addr;
							 seti->dataGridView5->Rows[0]->Cells[1]->Value=Nodelist[9].MS_set[0].MS_time;

							 for(i=1;i<(int)Nodelist[9].MS_set.size();i++)
							 {
								row=gcnew DataGridViewRow();
								row->CreateCells(seti->dataGridView5);
								row->Cells[0]->Value=Nodelist[9].MS_set[i].MS_main_addr;
								row->Cells[1]->Value=Nodelist[9].MS_set[i].MS_time;
								seti->dataGridView5->Rows->Add(row);
							 }
						 }

						 //Topology Set
						 if((int)Nodelist[9].T_set.size()>0)
						 {
							 seti->dataGridView6->Rows[0]->Cells[0]->Value=Nodelist[9].T_set[0].T_dest_addr;
							 seti->dataGridView6->Rows[0]->Cells[1]->Value=Nodelist[9].T_set[0].T_last_addr;
							 seti->dataGridView6->Rows[0]->Cells[2]->Value=Nodelist[9].T_set[0].T_time;

							 for(i=1;i<(int)Nodelist[9].T_set.size();i++)
							 {
								row=gcnew DataGridViewRow();
								row->CreateCells(seti->dataGridView6);
								row->Cells[0]->Value=Nodelist[9].T_set[i].T_dest_addr;
								row->Cells[1]->Value=Nodelist[9].T_set[i].T_last_addr;
								row->Cells[2]->Value=Nodelist[9].T_set[i].T_time;
								seti->dataGridView6->Rows->Add(row);
							 }
						 }

						 //Routing table
						 if((int)Nodelist[9].R_table.size()>0)
						 {
							 seti->dataGridView7->Rows[0]->Cells[0]->Value=Nodelist[9].R_table[0].R_dest_addr;
							 seti->dataGridView7->Rows[0]->Cells[1]->Value=Nodelist[9].R_table[0].R_next_addr;
							 seti->dataGridView7->Rows[0]->Cells[2]->Value=Nodelist[9].R_table[0].R_dist;
							 seti->dataGridView7->Rows[0]->Cells[3]->Value=Nodelist[9].R_table[0].R_iface_addr;

							 for(i=1;i<(int)Nodelist[9].R_table.size();i++)
							 {
								 row = gcnew DataGridViewRow();
								 row->CreateCells(seti->dataGridView7);
								 row->Cells[0]->Value=Nodelist[9].R_table[i].R_dest_addr;
								 row->Cells[1]->Value=Nodelist[9].R_table[i].R_next_addr;
								 row->Cells[2]->Value=Nodelist[9].R_table[i].R_dist;
								 row->Cells[3]->Value=Nodelist[9].R_table[i].R_iface_addr;
								 seti->dataGridView7->Rows->Add(row);
							 }
						 }
					  }
					  
	private: System::Void Startsimulation_Click(System::Object^  sender, System::EventArgs^  e) {

				 //populam N_Set si MPR_set 
				 for(int i=0;i<(int)Nodelist.size();i++)
				 {
					 for(int a=0;a<(int)topologie.size();a++)
					 {
						 if(Nodelist[i].Main_addr==topologie[a].getX())
						 {
							bool ok=false;
							OLSR_protocol::Neighbor_Set aux;
							for(int b=0;b<(int)topologie.size();b++)
							{
								bool ret=false; //verifica daca vecinul exista deja in setul Neighbor Set
								
								for(int g=0;g<(int)Nodelist[i].N_set.size() && (int)Nodelist[i].N_set.size()>0 ;g++)
								{
									if(topologie[a].getY()==Nodelist[i].N_set[g].N_neighbor_main_addr)
										ret=true;
								}
								
								if(topologie[b].getX()==topologie[a].getY() && topologie[b].getY()==topologie[a].getX() && ret==false) //legatura bidirectionala
								{
									aux.N_neighbor_main_addr=topologie[b].getX();
									aux.N_status=SYM;
									aux.N_willingness=WILL_DEFAULT;
									Nodelist[i].N_set.push_back(aux);
									OLSR_protocol::MPR_Set mp;
									mp.MPR_main_addr=topologie[b].getX();
									Nodelist[i].Mpr_set.push_back(mp);
									ok=true;
									break;
								}
							}
							if(ok==false) //legatura unidirectionala
							{
								aux.N_neighbor_main_addr=topologie[a].getY();
								aux.N_status=NOT_SYM;
								aux.N_willingness=WILL_DEFAULT;
								Nodelist[i].N_set.push_back(aux);

								OLSR_protocol::Neighbor_Set aux1;
								aux1.N_neighbor_main_addr=topologie[a].getX();
								aux1.N_status=NOT_SYM;
								aux1.N_willingness=WILL_DEFAULT;
								Nodelist[topologie[a].getY()-1].N_set.push_back(aux1);
							}

						 }
					 }
				  }


				 //initial trimite fiecare mesaje HELLO goale
				 int jk=0,jh=0;

				 try
				 {
					 for(jk=0;jk<(int)Nodelist.size();jk++)
						{
							OLSR_protocol::HELLO_message *hello=Nodelist[jk].generate_HELLO();
							for( jh=0;jh<(int)Nodelist.size();jh++)
							 {
								 for(int k=0;k<(int)topologie.size();k++)
									 if(topologie[k].getX()==Nodelist[jk].Main_addr && topologie[k].getY()==Nodelist[jh].Main_addr)
											Nodelist[jh].process_HELLO(hello);
							 }
						 }
				 }
				 catch(exception ex)
				 {
					 ;
				 }

				 //apoi mai trimit mesaje HELLO 
				 try
				 {
					 for(jk=0;jk<(int)Nodelist.size();jk++)
						{
							//MessageBox::Show("nodul este "+Nodelist[jk].L_set.size());
							OLSR_protocol::HELLO_message *hello=Nodelist[jk].generate_HELLO();
							for( jh=0;jh<(int)Nodelist.size();jh++)
							 {
								 for(int k=0;k<(int)topologie.size();k++)
									 if(topologie[k].getX()==Nodelist[jk].Main_addr && topologie[k].getY()==Nodelist[jh].Main_addr)
											Nodelist[jh].process_HELLO(hello);
							 }
						 }
				 }
				 catch(exception ex)
				 {
					 ;
				 }

				 //tratarea mesajelor TC
				 try
				 {
					for(jk=0;jk<(int)Nodelist.size();jk++)
						{
							OLSR_protocol::TC_message *tc=Nodelist[jk].generate_TC();
							for( jh=0;jh<(int)Nodelist.size();jh++)
							 {
								 for(int k=0;k<(int)topologie.size();k++)
									 if(topologie[k].getX()==Nodelist[jk].Main_addr && topologie[k].getY()==Nodelist[jh].Main_addr)
											{
												Nodelist[jh].process_TC(tc);
												//voi retransmite nodurilor din setul MPR
												for(int y=0;y<(int)Nodelist[jh].Mpr_set.size();y++)
												{
													tc->Source_addr=Nodelist[jh].Main_addr;//schimb source address, altfel verificare gresita in procesare TC
													Nodelist[Nodelist[jh].Mpr_set[y].MPR_main_addr-1].process_TC(tc);
												}
												tc->Source_addr=Nodelist[jk].Main_addr;
											}

							 }
						 }
				 }
				catch(exception ex)
				{
					;
				}

				//creare tabele de rutare
				for(int i=0;i<(int)Nodelist.size();i++)
					Nodelist[i].Routing_table_creation();

			 }
};
}