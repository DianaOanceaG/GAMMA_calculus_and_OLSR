#pragma once

namespace OLSR_network {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Sets
	/// </summary>
	public ref class Sets : public System::Windows::Forms::Form
	{
	public:
		Sets(void)
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
		~Sets()
		{
			if (components)
			{
				delete components;
			}
		}
	public: System::Windows::Forms::TabControl^  tabControl1;
	protected: 

	protected: 
	private: System::Windows::Forms::TabPage^  tabPage1;
	private: System::Windows::Forms::TabPage^  tabPage2;
	private: System::Windows::Forms::TabPage^  tabPage3;
	private: System::Windows::Forms::TabPage^  tabPage4;
	private: System::Windows::Forms::TabPage^  tabPage5;
	private: System::Windows::Forms::TabPage^  tabPage6;
	private: System::Windows::Forms::TabPage^  tabPage7;
	public: System::Windows::Forms::DataGridView^  dataGridView1;
	private: 


	public: System::Windows::Forms::DataGridView^  dataGridView2;
	public: System::Windows::Forms::DataGridView^  dataGridView3;
	public: System::Windows::Forms::DataGridView^  dataGridView4;
	public: System::Windows::Forms::DataGridView^  dataGridView5;
	private: 




	public: System::Windows::Forms::DataGridView^  dataGridView6;
	private: 





	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column2;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column3;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column4;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column5;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column6;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column7;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column8;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column9;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column10;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column11;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column12;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column13;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column14;
	public: System::Windows::Forms::DataGridView^  dataGridView7;
	private: 

	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column19;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column20;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column21;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column22;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column15;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column16;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column18;

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
			this->tabControl1 = (gcnew System::Windows::Forms::TabControl());
			this->tabPage1 = (gcnew System::Windows::Forms::TabPage());
			this->dataGridView2 = (gcnew System::Windows::Forms::DataGridView());
			this->Column1 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column2 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column3 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column4 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column5 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->tabPage2 = (gcnew System::Windows::Forms::TabPage());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->Column6 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column7 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column8 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->tabPage3 = (gcnew System::Windows::Forms::TabPage());
			this->dataGridView3 = (gcnew System::Windows::Forms::DataGridView());
			this->Column9 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column10 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column11 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->tabPage4 = (gcnew System::Windows::Forms::TabPage());
			this->dataGridView4 = (gcnew System::Windows::Forms::DataGridView());
			this->Column12 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->tabPage5 = (gcnew System::Windows::Forms::TabPage());
			this->dataGridView5 = (gcnew System::Windows::Forms::DataGridView());
			this->Column13 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column14 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->tabPage6 = (gcnew System::Windows::Forms::TabPage());
			this->dataGridView6 = (gcnew System::Windows::Forms::DataGridView());
			this->Column15 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column16 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column18 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->tabPage7 = (gcnew System::Windows::Forms::TabPage());
			this->dataGridView7 = (gcnew System::Windows::Forms::DataGridView());
			this->Column19 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column20 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column21 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column22 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->tabControl1->SuspendLayout();
			this->tabPage1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataGridView2))->BeginInit();
			this->tabPage2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataGridView1))->BeginInit();
			this->tabPage3->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataGridView3))->BeginInit();
			this->tabPage4->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataGridView4))->BeginInit();
			this->tabPage5->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataGridView5))->BeginInit();
			this->tabPage6->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataGridView6))->BeginInit();
			this->tabPage7->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataGridView7))->BeginInit();
			this->SuspendLayout();
			// 
			// tabControl1
			// 
			this->tabControl1->Controls->Add(this->tabPage1);
			this->tabControl1->Controls->Add(this->tabPage2);
			this->tabControl1->Controls->Add(this->tabPage3);
			this->tabControl1->Controls->Add(this->tabPage4);
			this->tabControl1->Controls->Add(this->tabPage5);
			this->tabControl1->Controls->Add(this->tabPage6);
			this->tabControl1->Controls->Add(this->tabPage7);
			this->tabControl1->Location = System::Drawing::Point(12, 3);
			this->tabControl1->Name = L"tabControl1";
			this->tabControl1->SelectedIndex = 0;
			this->tabControl1->Size = System::Drawing::Size(847, 283);
			this->tabControl1->TabIndex = 0;
			// 
			// tabPage1
			// 
			this->tabPage1->Controls->Add(this->dataGridView2);
			this->tabPage1->Location = System::Drawing::Point(4, 22);
			this->tabPage1->Name = L"tabPage1";
			this->tabPage1->Padding = System::Windows::Forms::Padding(3);
			this->tabPage1->Size = System::Drawing::Size(839, 257);
			this->tabPage1->TabIndex = 0;
			this->tabPage1->Text = L"Link Set";
			this->tabPage1->UseVisualStyleBackColor = true;
			// 
			// dataGridView2
			// 
			this->dataGridView2->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->dataGridView2->AutoSizeRowsMode = System::Windows::Forms::DataGridViewAutoSizeRowsMode::AllCells;
			this->dataGridView2->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView2->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(5) {this->Column1, 
				this->Column2, this->Column3, this->Column4, this->Column5});
			this->dataGridView2->Location = System::Drawing::Point(6, 6);
			this->dataGridView2->Name = L"dataGridView2";
			this->dataGridView2->Size = System::Drawing::Size(827, 147);
			this->dataGridView2->TabIndex = 0;
			this->dataGridView2->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &Sets::dataGridView2_CellContentClick);
			// 
			// Column1
			// 
			this->Column1->HeaderText = L"L_local_interface_address";
			this->Column1->Name = L"Column1";
			// 
			// Column2
			// 
			this->Column2->HeaderText = L"L_neighbor_interface_address";
			this->Column2->Name = L"Column2";
			// 
			// Column3
			// 
			this->Column3->HeaderText = L"L_SYM_time";
			this->Column3->Name = L"Column3";
			// 
			// Column4
			// 
			this->Column4->HeaderText = L"L_ASYM_time";
			this->Column4->Name = L"Column4";
			// 
			// Column5
			// 
			this->Column5->HeaderText = L"L_time";
			this->Column5->Name = L"Column5";
			// 
			// tabPage2
			// 
			this->tabPage2->Controls->Add(this->dataGridView1);
			this->tabPage2->Location = System::Drawing::Point(4, 22);
			this->tabPage2->Name = L"tabPage2";
			this->tabPage2->Padding = System::Windows::Forms::Padding(3);
			this->tabPage2->Size = System::Drawing::Size(839, 257);
			this->tabPage2->TabIndex = 1;
			this->tabPage2->Text = L"Neighbor Set";
			this->tabPage2->UseVisualStyleBackColor = true;
			// 
			// dataGridView1
			// 
			this->dataGridView1->AllowUserToOrderColumns = true;
			this->dataGridView1->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->dataGridView1->AutoSizeRowsMode = System::Windows::Forms::DataGridViewAutoSizeRowsMode::AllCells;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(3) {this->Column6, 
				this->Column7, this->Column8});
			this->dataGridView1->Location = System::Drawing::Point(3, 6);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->Size = System::Drawing::Size(694, 150);
			this->dataGridView1->TabIndex = 0;
			// 
			// Column6
			// 
			this->Column6->HeaderText = L"N_neighbor_main_address";
			this->Column6->Name = L"Column6";
			// 
			// Column7
			// 
			this->Column7->HeaderText = L"N_status";
			this->Column7->Name = L"Column7";
			// 
			// Column8
			// 
			this->Column8->HeaderText = L"N_willingness";
			this->Column8->Name = L"Column8";
			// 
			// tabPage3
			// 
			this->tabPage3->Controls->Add(this->dataGridView3);
			this->tabPage3->Location = System::Drawing::Point(4, 22);
			this->tabPage3->Name = L"tabPage3";
			this->tabPage3->Padding = System::Windows::Forms::Padding(3);
			this->tabPage3->Size = System::Drawing::Size(839, 257);
			this->tabPage3->TabIndex = 2;
			this->tabPage3->Text = L"2-hop Neighbor Set";
			this->tabPage3->UseVisualStyleBackColor = true;
			// 
			// dataGridView3
			// 
			this->dataGridView3->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->dataGridView3->AutoSizeRowsMode = System::Windows::Forms::DataGridViewAutoSizeRowsMode::AllCells;
			this->dataGridView3->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView3->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(3) {this->Column9, 
				this->Column10, this->Column11});
			this->dataGridView3->Location = System::Drawing::Point(3, 6);
			this->dataGridView3->Name = L"dataGridView3";
			this->dataGridView3->Size = System::Drawing::Size(694, 150);
			this->dataGridView3->TabIndex = 0;
			// 
			// Column9
			// 
			this->Column9->HeaderText = L"N_neighbor_main_address";
			this->Column9->Name = L"Column9";
			// 
			// Column10
			// 
			this->Column10->HeaderText = L"N_2-hop_neighbor_address";
			this->Column10->Name = L"Column10";
			// 
			// Column11
			// 
			this->Column11->HeaderText = L"N_time";
			this->Column11->Name = L"Column11";
			// 
			// tabPage4
			// 
			this->tabPage4->Controls->Add(this->dataGridView4);
			this->tabPage4->Location = System::Drawing::Point(4, 22);
			this->tabPage4->Name = L"tabPage4";
			this->tabPage4->Padding = System::Windows::Forms::Padding(3);
			this->tabPage4->Size = System::Drawing::Size(839, 257);
			this->tabPage4->TabIndex = 3;
			this->tabPage4->Text = L"MPR Set";
			this->tabPage4->UseVisualStyleBackColor = true;
			// 
			// dataGridView4
			// 
			this->dataGridView4->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->dataGridView4->AutoSizeRowsMode = System::Windows::Forms::DataGridViewAutoSizeRowsMode::AllCells;
			this->dataGridView4->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView4->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(1) {this->Column12});
			this->dataGridView4->Location = System::Drawing::Point(7, 7);
			this->dataGridView4->Name = L"dataGridView4";
			this->dataGridView4->Size = System::Drawing::Size(294, 150);
			this->dataGridView4->TabIndex = 0;
			// 
			// Column12
			// 
			this->Column12->HeaderText = L"MPR_main_address";
			this->Column12->Name = L"Column12";
			// 
			// tabPage5
			// 
			this->tabPage5->Controls->Add(this->dataGridView5);
			this->tabPage5->Location = System::Drawing::Point(4, 22);
			this->tabPage5->Name = L"tabPage5";
			this->tabPage5->Padding = System::Windows::Forms::Padding(3);
			this->tabPage5->Size = System::Drawing::Size(839, 257);
			this->tabPage5->TabIndex = 4;
			this->tabPage5->Text = L"MS Set";
			this->tabPage5->UseVisualStyleBackColor = true;
			// 
			// dataGridView5
			// 
			this->dataGridView5->AllowUserToOrderColumns = true;
			this->dataGridView5->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->dataGridView5->AutoSizeRowsMode = System::Windows::Forms::DataGridViewAutoSizeRowsMode::AllCells;
			this->dataGridView5->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView5->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(2) {this->Column13, 
				this->Column14});
			this->dataGridView5->Location = System::Drawing::Point(7, 7);
			this->dataGridView5->Name = L"dataGridView5";
			this->dataGridView5->Size = System::Drawing::Size(519, 150);
			this->dataGridView5->TabIndex = 0;
			// 
			// Column13
			// 
			this->Column13->HeaderText = L"MS_main_address";
			this->Column13->Name = L"Column13";
			// 
			// Column14
			// 
			this->Column14->HeaderText = L"MS_time";
			this->Column14->Name = L"Column14";
			// 
			// tabPage6
			// 
			this->tabPage6->Controls->Add(this->dataGridView6);
			this->tabPage6->Location = System::Drawing::Point(4, 22);
			this->tabPage6->Name = L"tabPage6";
			this->tabPage6->Padding = System::Windows::Forms::Padding(3);
			this->tabPage6->Size = System::Drawing::Size(839, 257);
			this->tabPage6->TabIndex = 5;
			this->tabPage6->Text = L"Topology Set";
			this->tabPage6->UseVisualStyleBackColor = true;
			// 
			// dataGridView6
			// 
			this->dataGridView6->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->dataGridView6->AutoSizeRowsMode = System::Windows::Forms::DataGridViewAutoSizeRowsMode::AllCells;
			this->dataGridView6->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView6->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(3) {this->Column15, 
				this->Column16, this->Column18});
			this->dataGridView6->Location = System::Drawing::Point(21, 6);
			this->dataGridView6->Name = L"dataGridView6";
			this->dataGridView6->Size = System::Drawing::Size(690, 150);
			this->dataGridView6->TabIndex = 0;
			// 
			// Column15
			// 
			this->Column15->HeaderText = L"T_destination address";
			this->Column15->Name = L"Column15";
			// 
			// Column16
			// 
			this->Column16->HeaderText = L"T_last_address";
			this->Column16->Name = L"Column16";
			// 
			// Column18
			// 
			this->Column18->HeaderText = L"T_time";
			this->Column18->Name = L"Column18";
			// 
			// tabPage7
			// 
			this->tabPage7->Controls->Add(this->dataGridView7);
			this->tabPage7->Location = System::Drawing::Point(4, 22);
			this->tabPage7->Name = L"tabPage7";
			this->tabPage7->Padding = System::Windows::Forms::Padding(3);
			this->tabPage7->Size = System::Drawing::Size(839, 257);
			this->tabPage7->TabIndex = 6;
			this->tabPage7->Text = L"Routing Table";
			this->tabPage7->UseVisualStyleBackColor = true;
			// 
			// dataGridView7
			// 
			this->dataGridView7->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->dataGridView7->AutoSizeRowsMode = System::Windows::Forms::DataGridViewAutoSizeRowsMode::AllCells;
			this->dataGridView7->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView7->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(4) {this->Column19, 
				this->Column20, this->Column21, this->Column22});
			this->dataGridView7->Location = System::Drawing::Point(7, 7);
			this->dataGridView7->Name = L"dataGridView7";
			this->dataGridView7->Size = System::Drawing::Size(693, 183);
			this->dataGridView7->TabIndex = 0;
			// 
			// Column19
			// 
			this->Column19->HeaderText = L"R_destination_address";
			this->Column19->Name = L"Column19";
			// 
			// Column20
			// 
			this->Column20->HeaderText = L"R_next_address";
			this->Column20->Name = L"Column20";
			// 
			// Column21
			// 
			this->Column21->HeaderText = L"R_distance";
			this->Column21->Name = L"Column21";
			// 
			// Column22
			// 
			this->Column22->HeaderText = L"R_interface_address";
			this->Column22->Name = L"Column22";
			// 
			// Sets
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(871, 298);
			this->Controls->Add(this->tabControl1);
			this->Name = L"Sets";
			this->Text = L"Sets";
			this->tabControl1->ResumeLayout(false);
			this->tabPage1->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataGridView2))->EndInit();
			this->tabPage2->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataGridView1))->EndInit();
			this->tabPage3->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataGridView3))->EndInit();
			this->tabPage4->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataGridView4))->EndInit();
			this->tabPage5->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataGridView5))->EndInit();
			this->tabPage6->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataGridView6))->EndInit();
			this->tabPage7->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataGridView7))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void tableLayoutPanel1_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {
			 }
private: System::Void dataGridView2_CellContentClick(System::Object^  sender, System::Windows::Forms::DataGridViewCellEventArgs^  e) {
		 }
};
}
