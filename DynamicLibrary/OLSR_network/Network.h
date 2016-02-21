#pragma once
#include "Form2.h"


namespace OLSR_network {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	

	/// <summary>
	/// Summary for Network
	/// </summary>
	public ref class Network : public System::Windows::Forms::Form
	{
	public:
		Network(void)
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
		~Network()
		{
			if (components)
			{
				delete components;
			}
		}


	private: 
	protected: 


	private: System::Windows::Forms::PictureBox^  pictureBox1;
	public: System::Windows::Forms::Timer^  Timer;
	private: 

	private: 

	private: System::ComponentModel::IContainer^  components;



	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Network::typeid));
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->Timer = (gcnew System::Windows::Forms::Timer(this->components));
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(0, -3);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(390, 385);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox1->TabIndex = 3;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->Click += gcnew System::EventHandler(this, &Network::pictureBox1_Click);
			// 
			// Timer
			// 
			this->Timer->Interval = 5000;
			this->Timer->Tick += gcnew System::EventHandler(this, &Network::Timer_Tick);
			// 
			// Network
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(388, 378);
			this->Controls->Add(this->pictureBox1);
			this->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->Margin = System::Windows::Forms::Padding(4);
			this->Name = L"Network";
			this->Text = L"GAMMA Simulator";
			this->Load += gcnew System::EventHandler(this, &Network::Network_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void Network_Load(System::Object^  sender, System::EventArgs^  e) {
				 Timer->Enabled=true;
			 }


private: System::Void Go_Click(System::Object^  sender, System::EventArgs^  e) {
	 // this->Close();
			 Form2^ form=gcnew Form2();
			 //form->data=Convert::ToInt32(textBox1->Text,10);
			 this->Hide();

			// if(form->data>=5)
			 form->ShowDialog(this);
			// else
			// this->Show();
	
			 this->Show();
		 }
private: System::Void pictureBox1_Click(System::Object^  sender, System::EventArgs^  e) {
			
		 }


private: System::Void Timer_Tick(System::Object^  sender, System::EventArgs^  e) {

			 Timer->Enabled=false;
			 Timer->Stop();
			 this->Hide();
			 Form2^ form=gcnew Form2();
			 form->ShowDialog(); 
			 this->Show();
		 }
};
}
