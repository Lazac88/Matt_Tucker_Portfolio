#pragma once
#include "GameManager.h"

namespace RogueLike {

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
	private: System::ComponentModel::IContainer^  components;
	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


	private:
		GameManager^ controller;
		Bitmap^ offScreenBitmap;
		Graphics^ offScreenCanvas;
		Graphics^ mainCanvas;
		Brush^ myBrush;
		Rectangle backGroundRect;
	private: System::Windows::Forms::Timer^  timer1;
	private: System::Windows::Forms::Label^  heroReviveLbl;
	private: System::Windows::Forms::Label^  StatsLbl;
	private: System::Windows::Forms::Label^  AttackLbl;
	private: System::Windows::Forms::Label^  StrengthLbl;
	private: System::Windows::Forms::Label^  DefenceLbl;
	private: System::Windows::Forms::Label^  EnduranceLbl;
	private: System::Windows::Forms::Label^  LuckLbl;
	private: System::Windows::Forms::Label^  AttackUpdateLbl;
	private: System::Windows::Forms::Label^  StrengthUpdateLbl;
	private: System::Windows::Forms::Label^  DefenceUpdateLbl;
	private: System::Windows::Forms::Label^  EnduranceUpdateLbl;
	private: System::Windows::Forms::Label^  LuckUpdateLbl;
	private: System::Windows::Forms::Label^  ScoreLbl;
	private: System::Windows::Forms::Label^  ScoreUpdateLbl;



			 Random^ rand;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->heroReviveLbl = (gcnew System::Windows::Forms::Label());
			this->StatsLbl = (gcnew System::Windows::Forms::Label());
			this->AttackLbl = (gcnew System::Windows::Forms::Label());
			this->StrengthLbl = (gcnew System::Windows::Forms::Label());
			this->DefenceLbl = (gcnew System::Windows::Forms::Label());
			this->EnduranceLbl = (gcnew System::Windows::Forms::Label());
			this->LuckLbl = (gcnew System::Windows::Forms::Label());
			this->AttackUpdateLbl = (gcnew System::Windows::Forms::Label());
			this->StrengthUpdateLbl = (gcnew System::Windows::Forms::Label());
			this->DefenceUpdateLbl = (gcnew System::Windows::Forms::Label());
			this->EnduranceUpdateLbl = (gcnew System::Windows::Forms::Label());
			this->LuckUpdateLbl = (gcnew System::Windows::Forms::Label());
			this->ScoreLbl = (gcnew System::Windows::Forms::Label());
			this->ScoreUpdateLbl = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Tick += gcnew System::EventHandler(this, &MyForm::timer1_Tick);
			// 
			// heroReviveLbl
			// 
			this->heroReviveLbl->AutoSize = true;
			this->heroReviveLbl->BackColor = System::Drawing::Color::Black;
			this->heroReviveLbl->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->heroReviveLbl->ForeColor = System::Drawing::Color::White;
			this->heroReviveLbl->Location = System::Drawing::Point(1060, 647);
			this->heroReviveLbl->Name = L"heroReviveLbl";
			this->heroReviveLbl->Size = System::Drawing::Size(25, 25);
			this->heroReviveLbl->TabIndex = 0;
			this->heroReviveLbl->Text = L"0";
			// 
			// StatsLbl
			// 
			this->StatsLbl->AutoSize = true;
			this->StatsLbl->BackColor = System::Drawing::Color::Black;
			this->StatsLbl->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Underline)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->StatsLbl->ForeColor = System::Drawing::Color::Red;
			this->StatsLbl->Location = System::Drawing::Point(1290, 36);
			this->StatsLbl->Name = L"StatsLbl";
			this->StatsLbl->Size = System::Drawing::Size(54, 24);
			this->StatsLbl->TabIndex = 1;
			this->StatsLbl->Text = L"Stats";
			// 
			// AttackLbl
			// 
			this->AttackLbl->AutoSize = true;
			this->AttackLbl->BackColor = System::Drawing::Color::Black;
			this->AttackLbl->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->AttackLbl->ForeColor = System::Drawing::Color::Red;
			this->AttackLbl->Location = System::Drawing::Point(1280, 84);
			this->AttackLbl->Name = L"AttackLbl";
			this->AttackLbl->Size = System::Drawing::Size(38, 20);
			this->AttackLbl->TabIndex = 2;
			this->AttackLbl->Text = L"Att:";
			// 
			// StrengthLbl
			// 
			this->StrengthLbl->AutoSize = true;
			this->StrengthLbl->BackColor = System::Drawing::Color::Black;
			this->StrengthLbl->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->StrengthLbl->ForeColor = System::Drawing::Color::Red;
			this->StrengthLbl->Location = System::Drawing::Point(1280, 117);
			this->StrengthLbl->Name = L"StrengthLbl";
			this->StrengthLbl->Size = System::Drawing::Size(38, 20);
			this->StrengthLbl->TabIndex = 3;
			this->StrengthLbl->Text = L"Str:";
			// 
			// DefenceLbl
			// 
			this->DefenceLbl->AutoSize = true;
			this->DefenceLbl->BackColor = System::Drawing::Color::Black;
			this->DefenceLbl->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->DefenceLbl->ForeColor = System::Drawing::Color::Red;
			this->DefenceLbl->Location = System::Drawing::Point(1280, 150);
			this->DefenceLbl->Name = L"DefenceLbl";
			this->DefenceLbl->Size = System::Drawing::Size(43, 20);
			this->DefenceLbl->TabIndex = 4;
			this->DefenceLbl->Text = L"Def:";
			// 
			// EnduranceLbl
			// 
			this->EnduranceLbl->AutoSize = true;
			this->EnduranceLbl->BackColor = System::Drawing::Color::Black;
			this->EnduranceLbl->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->EnduranceLbl->ForeColor = System::Drawing::Color::Red;
			this->EnduranceLbl->Location = System::Drawing::Point(1280, 183);
			this->EnduranceLbl->Name = L"EnduranceLbl";
			this->EnduranceLbl->Size = System::Drawing::Size(46, 20);
			this->EnduranceLbl->TabIndex = 5;
			this->EnduranceLbl->Text = L"End:";
			// 
			// LuckLbl
			// 
			this->LuckLbl->AutoSize = true;
			this->LuckLbl->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->LuckLbl->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->LuckLbl->ForeColor = System::Drawing::Color::Red;
			this->LuckLbl->Location = System::Drawing::Point(1280, 216);
			this->LuckLbl->Name = L"LuckLbl";
			this->LuckLbl->Size = System::Drawing::Size(42, 20);
			this->LuckLbl->TabIndex = 6;
			this->LuckLbl->Text = L"Lck:";
			// 
			// AttackUpdateLbl
			// 
			this->AttackUpdateLbl->AutoSize = true;
			this->AttackUpdateLbl->BackColor = System::Drawing::Color::Black;
			this->AttackUpdateLbl->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->AttackUpdateLbl->ForeColor = System::Drawing::Color::Red;
			this->AttackUpdateLbl->Location = System::Drawing::Point(1332, 84);
			this->AttackUpdateLbl->Name = L"AttackUpdateLbl";
			this->AttackUpdateLbl->Size = System::Drawing::Size(19, 20);
			this->AttackUpdateLbl->TabIndex = 7;
			this->AttackUpdateLbl->Text = L"0";
			// 
			// StrengthUpdateLbl
			// 
			this->StrengthUpdateLbl->AutoSize = true;
			this->StrengthUpdateLbl->BackColor = System::Drawing::Color::Black;
			this->StrengthUpdateLbl->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->StrengthUpdateLbl->ForeColor = System::Drawing::Color::Red;
			this->StrengthUpdateLbl->Location = System::Drawing::Point(1332, 117);
			this->StrengthUpdateLbl->Name = L"StrengthUpdateLbl";
			this->StrengthUpdateLbl->Size = System::Drawing::Size(19, 20);
			this->StrengthUpdateLbl->TabIndex = 8;
			this->StrengthUpdateLbl->Text = L"0";
			// 
			// DefenceUpdateLbl
			// 
			this->DefenceUpdateLbl->AutoSize = true;
			this->DefenceUpdateLbl->BackColor = System::Drawing::Color::Black;
			this->DefenceUpdateLbl->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->DefenceUpdateLbl->ForeColor = System::Drawing::Color::Red;
			this->DefenceUpdateLbl->Location = System::Drawing::Point(1332, 150);
			this->DefenceUpdateLbl->Name = L"DefenceUpdateLbl";
			this->DefenceUpdateLbl->Size = System::Drawing::Size(19, 20);
			this->DefenceUpdateLbl->TabIndex = 9;
			this->DefenceUpdateLbl->Text = L"0";
			// 
			// EnduranceUpdateLbl
			// 
			this->EnduranceUpdateLbl->AutoSize = true;
			this->EnduranceUpdateLbl->BackColor = System::Drawing::Color::Black;
			this->EnduranceUpdateLbl->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->EnduranceUpdateLbl->ForeColor = System::Drawing::Color::Red;
			this->EnduranceUpdateLbl->Location = System::Drawing::Point(1332, 183);
			this->EnduranceUpdateLbl->Name = L"EnduranceUpdateLbl";
			this->EnduranceUpdateLbl->Size = System::Drawing::Size(19, 20);
			this->EnduranceUpdateLbl->TabIndex = 10;
			this->EnduranceUpdateLbl->Text = L"0";
			// 
			// LuckUpdateLbl
			// 
			this->LuckUpdateLbl->AutoSize = true;
			this->LuckUpdateLbl->BackColor = System::Drawing::Color::Black;
			this->LuckUpdateLbl->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->LuckUpdateLbl->ForeColor = System::Drawing::Color::Red;
			this->LuckUpdateLbl->Location = System::Drawing::Point(1332, 216);
			this->LuckUpdateLbl->Name = L"LuckUpdateLbl";
			this->LuckUpdateLbl->Size = System::Drawing::Size(19, 20);
			this->LuckUpdateLbl->TabIndex = 11;
			this->LuckUpdateLbl->Text = L"0";
			// 
			// ScoreLbl
			// 
			this->ScoreLbl->AutoSize = true;
			this->ScoreLbl->BackColor = System::Drawing::Color::Black;
			this->ScoreLbl->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Underline)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->ScoreLbl->ForeColor = System::Drawing::Color::Red;
			this->ScoreLbl->Location = System::Drawing::Point(1285, 310);
			this->ScoreLbl->Name = L"ScoreLbl";
			this->ScoreLbl->Size = System::Drawing::Size(65, 24);
			this->ScoreLbl->TabIndex = 12;
			this->ScoreLbl->Text = L"Score";
			// 
			// ScoreUpdateLbl
			// 
			this->ScoreUpdateLbl->AutoSize = true;
			this->ScoreUpdateLbl->BackColor = System::Drawing::Color::Black;
			this->ScoreUpdateLbl->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->ScoreUpdateLbl->ForeColor = System::Drawing::Color::Red;
			this->ScoreUpdateLbl->Location = System::Drawing::Point(1300, 349);
			this->ScoreUpdateLbl->Name = L"ScoreUpdateLbl";
			this->ScoreUpdateLbl->Size = System::Drawing::Size(21, 24);
			this->ScoreUpdateLbl->TabIndex = 13;
			this->ScoreUpdateLbl->Text = L"0";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1362, 681);
			this->Controls->Add(this->ScoreUpdateLbl);
			this->Controls->Add(this->ScoreLbl);
			this->Controls->Add(this->LuckUpdateLbl);
			this->Controls->Add(this->EnduranceUpdateLbl);
			this->Controls->Add(this->DefenceUpdateLbl);
			this->Controls->Add(this->StrengthUpdateLbl);
			this->Controls->Add(this->AttackUpdateLbl);
			this->Controls->Add(this->LuckLbl);
			this->Controls->Add(this->EnduranceLbl);
			this->Controls->Add(this->DefenceLbl);
			this->Controls->Add(this->StrengthLbl);
			this->Controls->Add(this->AttackLbl);
			this->Controls->Add(this->StatsLbl);
			this->Controls->Add(this->heroReviveLbl);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::MyForm_KeyDown);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e) 
	{
		myBrush = gcnew SolidBrush(Color::Black);
		backGroundRect = Rectangle(0, 0, 1450, 720);
				 
		//How to make the panel the mainCanvas area
		mainCanvas = CreateGraphics();

		//Creating an offscreen Bitmap
		offScreenBitmap = gcnew Bitmap(Width, Height);
		//Creating an offscreen Canvas using the Bitmap above
		offScreenCanvas = Graphics::FromImage(offScreenBitmap);
		rand = gcnew Random();

		//Creating the controller
		controller = gcnew GameManager(offScreenCanvas, rand);

		//Set up dungeon
		controller->NewLevel();
	}
	private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) 
	{
				 
				 offScreenCanvas->FillRectangle(myBrush, backGroundRect);
				 controller->ClearFog();
				 controller->DrawMap();
				 controller->DrawItems();
				 controller->DrawPortal();
				 controller->UpdateLists();
				 controller->MoveFireballs();
				 controller->DrawFireBalls();				 
				 controller->MoveMonsters();
				 controller->DrawMonsters();

				 controller->RunHero();
				 controller->DrawHero();
				 //Display Revives
				 String^ myRevives = System::Convert::ToString(controller->getHeroRevive());
				 heroReviveLbl->Text = "Revives: " + myRevives;
				 //Display hero stats
				 String^ myAttack = System::Convert::ToString(controller->getHeroAttack());
				 AttackUpdateLbl->Text = myAttack;
				 String^ myStrength = System::Convert::ToString(controller->getHeroStrength());
				 StrengthUpdateLbl->Text = myStrength;
				 String^ myDefence = System::Convert::ToString(controller->getHeroDefence());
				 DefenceUpdateLbl->Text = myDefence;
				 String^ myEndurance = System::Convert::ToString(controller->getHeroEndurance());
				 EnduranceUpdateLbl->Text = myEndurance;
				 String^ myLuck = System::Convert::ToString(controller->getHeroLuck());
				 LuckUpdateLbl->Text = myLuck;
				 String^ myScore = System::Convert::ToString(controller->getHeroScore());
				 ScoreUpdateLbl->Text = myScore;
			

				 //draw the offscreen Bitmap to the panels canvas
				 mainCanvas->DrawImage(offScreenBitmap, 0, 0);
	}
	
private: System::Void MyForm_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) 
{
			 if (e->KeyData == Keys::Left)
			 {

				 controller->MoveHero(EDirection::WEST);
			 }

			 if (e->KeyData == Keys::Right)
			 {
				 controller->MoveHero(EDirection::EAST);
			 }

			 if (e->KeyData == Keys::Up)
			 {
				 controller->MoveHero(EDirection::NORTH);
			 }

			 if (e->KeyData == Keys::Down)
			 {
				 controller->MoveHero(EDirection::SOUTH);
			 }

			 if (e->KeyData == Keys::Space)
			 {
				 controller->ShootFireball();
			 }
}
};
}
