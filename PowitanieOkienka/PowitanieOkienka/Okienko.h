#pragma once

namespace PowitanieOkienka {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Podsumowanie informacji o Okienko
	/// </summary>
	public ref class Okienko : public System::Windows::Forms::Form
	{
	public:
		Okienko(void)
		{
			InitializeComponent();
			//
			//TODO: W tym miejscu dodaj kod konstruktora
			//
		}

	protected:
		/// <summary>
		/// Wyczyœæ wszystkie u¿ywane zasoby.
		/// </summary>
		~Okienko()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::PictureBox^  pictureBox1;
	private: System::Windows::Forms::TextBox^  txt;

	private: System::Windows::Forms::Button^  przycisk;
	protected:

	private:
		/// <summary>
		/// Wymagana zmienna projektanta.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Metoda wymagana do obs³ugi projektanta — nie nale¿y modyfikowaæ
		/// jej zawartoœci w edytorze kodu.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Okienko::typeid));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->txt = (gcnew System::Windows::Forms::TextBox());
			this->przycisk = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::Lime;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->label1->Location = System::Drawing::Point(12, 201);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(159, 25);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Witaj w kursie";
			this->label1->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			this->label1->Visible = false;
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackColor = System::Drawing::Color::Transparent;
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(17, 12);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(288, 175);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->pictureBox1->TabIndex = 1;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->Visible = false;
			this->pictureBox1->Click += gcnew System::EventHandler(this, &Okienko::pictureBox1_Click);
			// 
			// txt
			// 
			this->txt->Location = System::Drawing::Point(99, 32);
			this->txt->Name = L"txt";
			this->txt->Size = System::Drawing::Size(100, 20);
			this->txt->TabIndex = 2;
			// 
			// przycisk
			// 
			this->przycisk->Location = System::Drawing::Point(108, 74);
			this->przycisk->Name = L"przycisk";
			this->przycisk->Size = System::Drawing::Size(75, 23);
			this->przycisk->TabIndex = 3;
			this->przycisk->Text = L"Powitanie";
			this->przycisk->UseVisualStyleBackColor = true;
			this->przycisk->Click += gcnew System::EventHandler(this, &Okienko::przycisk_Click);
			// 
			// Okienko
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::Khaki;
			this->ClientSize = System::Drawing::Size(320, 260);
			this->Controls->Add(this->przycisk);
			this->Controls->Add(this->txt);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->label1);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"Okienko";
			this->Text = L"Okienko";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void pictureBox1_Click(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void przycisk_Click(System::Object^  sender, System::EventArgs^  e) {

		txt->Visible = false;
		przycisk->Visible = false;
		label1->Visible = true;
		pictureBox1->Visible = true;

		label1->Text = "Witaj " + txt -> Text + " w Kursie C++";
	}
};
}
