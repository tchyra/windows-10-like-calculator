#pragma once

// standard libs
#include <iostream>
#include <stdlib.h>

// custom header files
#include "ICalculable.h"
#include "Expression.h"
#include "Exceptions.h"

using namespace System;

namespace zad9CLRedition
{
	using namespace std;
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	enum TokenTypes { Number, Operator, Function, LeftParenthesis, RightParenthesis, Equals };

	/// <summary>
	/// Formatka kalkulatora
	/// </summary>
	public ref class FrmCalculator : public System::Windows::Forms::Form
	{

	public:
		FrmCalculator(void)
		{

			InitializeComponent();

			// stop after initializing component to hopefully fix the winforms designer
			if (DesignMode) return;

			// only trigger a relayout once
			SuspendLayout();

			// set initial width and height
			Width = W;
			Height = H;

			ResumeLayout();

			// initialize UI, essentially, bit of a lazy way but this program is long enough as is
			Clear();
			SwitchTo1st();
			UpdateCurrentMemUI();
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~FrmCalculator()
		{
			if (components) delete components;
		}
	private: System::Windows::Forms::TableLayoutPanel^ _tlpSciButtons;
	protected:

#pragma region control variables



	private: System::Windows::Forms::Button^ _btn0;
	private: System::Windows::Forms::Button^ _btn1;
	private: System::Windows::Forms::Button^ _btn2;
	private: System::Windows::Forms::Button^ _btn3;
	private: System::Windows::Forms::Button^ _btn4;
	private: System::Windows::Forms::Button^ _btn5;
	private: System::Windows::Forms::Button^ _btn6;
	private: System::Windows::Forms::Button^ _btn9;
	private: System::Windows::Forms::Button^ _btn8;
	private: System::Windows::Forms::Button^ _btn7;
	private: System::Windows::Forms::Button^ _btnPoint;
	private: System::Windows::Forms::Button^ _btnPlusMinus;
	private: System::Windows::Forms::Button^ _btnMultiply;
	private: System::Windows::Forms::Button^ _btnMinus;

	private: System::Windows::Forms::Button^ _btnPlus;
	private: System::Windows::Forms::Button^ _btnEquals;
	private: System::Windows::Forms::Button^ _btnDivide;
	private: System::Windows::Forms::Button^ _btnSqrt;
	private: System::Windows::Forms::Button^ _btnSqr;

	private: System::Windows::Forms::Button^ _btnInvert;



	private: System::Windows::Forms::Button^ _btnBackspace;
	private: System::Windows::Forms::Button^ _btnPow;

	private: System::Windows::Forms::Button^ _btnCE;

	private: System::Windows::Forms::Label^ _lblCurrentNum;
	private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel2;
	private: System::Windows::Forms::Label^ _lblCurrentExpr;
	private: System::Windows::Forms::Button^ _btnModulo;
	private: System::Windows::Forms::Button^ _btn2ndOn;


	private: System::Windows::Forms::Button^ _btnExp;
	private: System::Windows::Forms::Button^ _btnAbs;

	private: System::Windows::Forms::Button^ _btnFactorial;
	private: System::Windows::Forms::Button^ _btnRightParenthesis;
	private: System::Windows::Forms::Button^ _btnLeftParenthesis;
	private: System::Windows::Forms::Button^ _btnE;
	private: System::Windows::Forms::Button^ _btnPi;
	private: System::Windows::Forms::Button^ _btn2ndOff;
	private: System::Windows::Forms::Button^ _btnCubeRoot;
	private: System::Windows::Forms::Button^ _btn2ToX;
	private: System::Windows::Forms::Button^ _btnEToX;
	private: System::Windows::Forms::Button^ _btnCube;
	private: System::Windows::Forms::Button^ _btn10ToX;
	private: System::Windows::Forms::Button^ _btnLog;
	private: System::Windows::Forms::Button^ _btnLn;
	private: System::Windows::Forms::Button^ _btnLogYX;
	private: System::Windows::Forms::Button^ _btnYRoot;
	private: System::Windows::Forms::TableLayoutPanel^ _tlpSciMemory;

	private: System::Windows::Forms::Button^ _btnMemDropdown;
	private: System::Windows::Forms::Button^ _btnMemStore;


	private: System::Windows::Forms::Button^ _btnMemMinus;
	private: System::Windows::Forms::Button^ _btnMemPlus;
	private: System::Windows::Forms::Button^ _btnMemRecall;
	private: System::Windows::Forms::Button^ _btnMemClear;
	private: System::Windows::Forms::Button^ _btnToggleFE;
	private: System::Windows::Forms::Button^ _btnModeStandard;
	private: System::Windows::Forms::Button^ _btnModeScientific;
	private: System::Windows::Forms::TableLayoutPanel^ _tlpStanButtons;
	private: System::Windows::Forms::Button^ _btnStan0;
	private: System::Windows::Forms::Button^ _btnStan1;


	private: System::Windows::Forms::Button^ _btnStan2;

	private: System::Windows::Forms::Button^ _btnStan3;
	private: System::Windows::Forms::Button^ _btnStan4;


	private: System::Windows::Forms::Button^ _btnStan5;

	private: System::Windows::Forms::Button^ _btnStan6;
	private: System::Windows::Forms::Button^ _btnStan9;
	private: System::Windows::Forms::Button^ _btnStan8;
	private: System::Windows::Forms::Button^ _btnStan7;




	private: System::Windows::Forms::Button^ _btnStanPoint;

	private: System::Windows::Forms::Button^ _btnStanPlusMinus;
	private: System::Windows::Forms::Button^ _btnStanMultiply;
	private: System::Windows::Forms::Button^ _btnStanMinus;
	private: System::Windows::Forms::Button^ _btnStanPlus;
	private: System::Windows::Forms::Button^ _btnStanEquals;





	private: System::Windows::Forms::Button^ _btnStanDivide;


	private: System::Windows::Forms::Button^ _btnStanBackspace;

	private: System::Windows::Forms::Button^ _btnStanCE;
	private: System::Windows::Forms::Button^ _btnStanInvert;




	private: System::Windows::Forms::Button^ _btnStanSqrt;
	private: System::Windows::Forms::Button^ _btnStanSqr;





















	private: System::Windows::Forms::TableLayoutPanel^ _tlpStanMemory;
	private: System::Windows::Forms::Button^ _btnStanMemDropdown;

	private: System::Windows::Forms::Button^ _btnStanMemStore;

	private: System::Windows::Forms::Button^ _btnStanMemMinus;

	private: System::Windows::Forms::Button^ _btnStanMemPlus;

	private: System::Windows::Forms::Button^ _btnStanMemRecall;

	private: System::Windows::Forms::Button^ _btnStanMemClear;
	private: System::Windows::Forms::Button^ _btnStanC;
	private: System::Windows::Forms::Button^ _btnStanPercent;


#pragma endregion

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
			this->_tlpSciButtons = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->_btn0 = (gcnew System::Windows::Forms::Button());
			this->_btn1 = (gcnew System::Windows::Forms::Button());
			this->_btn2 = (gcnew System::Windows::Forms::Button());
			this->_btn3 = (gcnew System::Windows::Forms::Button());
			this->_btn4 = (gcnew System::Windows::Forms::Button());
			this->_btn5 = (gcnew System::Windows::Forms::Button());
			this->_btn6 = (gcnew System::Windows::Forms::Button());
			this->_btn9 = (gcnew System::Windows::Forms::Button());
			this->_btn8 = (gcnew System::Windows::Forms::Button());
			this->_btn7 = (gcnew System::Windows::Forms::Button());
			this->_btnPoint = (gcnew System::Windows::Forms::Button());
			this->_btnPlusMinus = (gcnew System::Windows::Forms::Button());
			this->_btnMultiply = (gcnew System::Windows::Forms::Button());
			this->_btnMinus = (gcnew System::Windows::Forms::Button());
			this->_btnPlus = (gcnew System::Windows::Forms::Button());
			this->_btnEquals = (gcnew System::Windows::Forms::Button());
			this->_btnDivide = (gcnew System::Windows::Forms::Button());
			this->_btnBackspace = (gcnew System::Windows::Forms::Button());
			this->_btnModulo = (gcnew System::Windows::Forms::Button());
			this->_btnCE = (gcnew System::Windows::Forms::Button());
			this->_btnInvert = (gcnew System::Windows::Forms::Button());
			this->_btnExp = (gcnew System::Windows::Forms::Button());
			this->_btnAbs = (gcnew System::Windows::Forms::Button());
			this->_btnFactorial = (gcnew System::Windows::Forms::Button());
			this->_btnRightParenthesis = (gcnew System::Windows::Forms::Button());
			this->_btnLeftParenthesis = (gcnew System::Windows::Forms::Button());
			this->_btn2ndOn = (gcnew System::Windows::Forms::Button());
			this->_btnPow = (gcnew System::Windows::Forms::Button());
			this->_btnE = (gcnew System::Windows::Forms::Button());
			this->_btnPi = (gcnew System::Windows::Forms::Button());
			this->_btn2ndOff = (gcnew System::Windows::Forms::Button());
			this->_btnSqrt = (gcnew System::Windows::Forms::Button());
			this->_btnCubeRoot = (gcnew System::Windows::Forms::Button());
			this->_btn2ToX = (gcnew System::Windows::Forms::Button());
			this->_btnEToX = (gcnew System::Windows::Forms::Button());
			this->_btnSqr = (gcnew System::Windows::Forms::Button());
			this->_btnCube = (gcnew System::Windows::Forms::Button());
			this->_btn10ToX = (gcnew System::Windows::Forms::Button());
			this->_btnLog = (gcnew System::Windows::Forms::Button());
			this->_btnLn = (gcnew System::Windows::Forms::Button());
			this->_btnLogYX = (gcnew System::Windows::Forms::Button());
			this->_btnYRoot = (gcnew System::Windows::Forms::Button());
			this->tableLayoutPanel2 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->_lblCurrentNum = (gcnew System::Windows::Forms::Label());
			this->_lblCurrentExpr = (gcnew System::Windows::Forms::Label());
			this->_btnModeStandard = (gcnew System::Windows::Forms::Button());
			this->_btnModeScientific = (gcnew System::Windows::Forms::Button());
			this->_tlpSciMemory = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->_btnMemDropdown = (gcnew System::Windows::Forms::Button());
			this->_btnMemStore = (gcnew System::Windows::Forms::Button());
			this->_btnMemMinus = (gcnew System::Windows::Forms::Button());
			this->_btnMemPlus = (gcnew System::Windows::Forms::Button());
			this->_btnMemRecall = (gcnew System::Windows::Forms::Button());
			this->_btnMemClear = (gcnew System::Windows::Forms::Button());
			this->_btnToggleFE = (gcnew System::Windows::Forms::Button());
			this->_tlpStanButtons = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->_btnStan0 = (gcnew System::Windows::Forms::Button());
			this->_btnStan1 = (gcnew System::Windows::Forms::Button());
			this->_btnStan2 = (gcnew System::Windows::Forms::Button());
			this->_btnStan3 = (gcnew System::Windows::Forms::Button());
			this->_btnStan4 = (gcnew System::Windows::Forms::Button());
			this->_btnStan5 = (gcnew System::Windows::Forms::Button());
			this->_btnStan6 = (gcnew System::Windows::Forms::Button());
			this->_btnStan9 = (gcnew System::Windows::Forms::Button());
			this->_btnStan8 = (gcnew System::Windows::Forms::Button());
			this->_btnStan7 = (gcnew System::Windows::Forms::Button());
			this->_btnStanPoint = (gcnew System::Windows::Forms::Button());
			this->_btnStanPlusMinus = (gcnew System::Windows::Forms::Button());
			this->_btnStanMultiply = (gcnew System::Windows::Forms::Button());
			this->_btnStanMinus = (gcnew System::Windows::Forms::Button());
			this->_btnStanPlus = (gcnew System::Windows::Forms::Button());
			this->_btnStanEquals = (gcnew System::Windows::Forms::Button());
			this->_btnStanDivide = (gcnew System::Windows::Forms::Button());
			this->_btnStanInvert = (gcnew System::Windows::Forms::Button());
			this->_btnStanSqr = (gcnew System::Windows::Forms::Button());
			this->_btnStanSqrt = (gcnew System::Windows::Forms::Button());
			this->_btnStanBackspace = (gcnew System::Windows::Forms::Button());
			this->_btnStanCE = (gcnew System::Windows::Forms::Button());
			this->_btnStanC = (gcnew System::Windows::Forms::Button());
			this->_btnStanPercent = (gcnew System::Windows::Forms::Button());
			this->_tlpStanMemory = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->_btnStanMemDropdown = (gcnew System::Windows::Forms::Button());
			this->_btnStanMemStore = (gcnew System::Windows::Forms::Button());
			this->_btnStanMemMinus = (gcnew System::Windows::Forms::Button());
			this->_btnStanMemPlus = (gcnew System::Windows::Forms::Button());
			this->_btnStanMemRecall = (gcnew System::Windows::Forms::Button());
			this->_btnStanMemClear = (gcnew System::Windows::Forms::Button());
			this->_tlpSciButtons->SuspendLayout();
			this->tableLayoutPanel2->SuspendLayout();
			this->_tlpSciMemory->SuspendLayout();
			this->_tlpStanButtons->SuspendLayout();
			this->_tlpStanMemory->SuspendLayout();
			this->SuspendLayout();
			// 
			// _tlpSciButtons
			// 
			this->_tlpSciButtons->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left));
			this->_tlpSciButtons->ColumnCount = 6;
			this->_tlpSciButtons->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				16.66667F)));
			this->_tlpSciButtons->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				16.66667F)));
			this->_tlpSciButtons->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				16.66667F)));
			this->_tlpSciButtons->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				16.66667F)));
			this->_tlpSciButtons->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				16.66667F)));
			this->_tlpSciButtons->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				16.66667F)));
			this->_tlpSciButtons->Controls->Add(this->_btn0, 3, 6);
			this->_tlpSciButtons->Controls->Add(this->_btn1, 2, 5);
			this->_tlpSciButtons->Controls->Add(this->_btn2, 3, 5);
			this->_tlpSciButtons->Controls->Add(this->_btn3, 4, 5);
			this->_tlpSciButtons->Controls->Add(this->_btn4, 2, 4);
			this->_tlpSciButtons->Controls->Add(this->_btn5, 3, 4);
			this->_tlpSciButtons->Controls->Add(this->_btn6, 4, 4);
			this->_tlpSciButtons->Controls->Add(this->_btn9, 4, 3);
			this->_tlpSciButtons->Controls->Add(this->_btn8, 3, 3);
			this->_tlpSciButtons->Controls->Add(this->_btn7, 2, 3);
			this->_tlpSciButtons->Controls->Add(this->_btnPoint, 4, 6);
			this->_tlpSciButtons->Controls->Add(this->_btnPlusMinus, 2, 6);
			this->_tlpSciButtons->Controls->Add(this->_btnMultiply, 5, 3);
			this->_tlpSciButtons->Controls->Add(this->_btnMinus, 5, 4);
			this->_tlpSciButtons->Controls->Add(this->_btnPlus, 5, 5);
			this->_tlpSciButtons->Controls->Add(this->_btnEquals, 5, 6);
			this->_tlpSciButtons->Controls->Add(this->_btnDivide, 5, 2);
			this->_tlpSciButtons->Controls->Add(this->_btnBackspace, 5, 0);
			this->_tlpSciButtons->Controls->Add(this->_btnModulo, 5, 1);
			this->_tlpSciButtons->Controls->Add(this->_btnCE, 4, 0);
			this->_tlpSciButtons->Controls->Add(this->_btnInvert, 2, 1);
			this->_tlpSciButtons->Controls->Add(this->_btnExp, 4, 1);
			this->_tlpSciButtons->Controls->Add(this->_btnAbs, 3, 1);
			this->_tlpSciButtons->Controls->Add(this->_btnFactorial, 4, 2);
			this->_tlpSciButtons->Controls->Add(this->_btnRightParenthesis, 3, 2);
			this->_tlpSciButtons->Controls->Add(this->_btnLeftParenthesis, 2, 2);
			this->_tlpSciButtons->Controls->Add(this->_btn2ndOn, 1, 0);
			this->_tlpSciButtons->Controls->Add(this->_btnPow, 1, 3);
			this->_tlpSciButtons->Controls->Add(this->_btnE, 3, 0);
			this->_tlpSciButtons->Controls->Add(this->_btnPi, 2, 0);
			this->_tlpSciButtons->Controls->Add(this->_btn2ndOff, 0, 0);
			this->_tlpSciButtons->Controls->Add(this->_btnSqrt, 0, 1);
			this->_tlpSciButtons->Controls->Add(this->_btnCubeRoot, 0, 2);
			this->_tlpSciButtons->Controls->Add(this->_btn2ToX, 0, 4);
			this->_tlpSciButtons->Controls->Add(this->_btnEToX, 0, 6);
			this->_tlpSciButtons->Controls->Add(this->_btnSqr, 1, 1);
			this->_tlpSciButtons->Controls->Add(this->_btnCube, 1, 2);
			this->_tlpSciButtons->Controls->Add(this->_btn10ToX, 1, 4);
			this->_tlpSciButtons->Controls->Add(this->_btnLog, 1, 5);
			this->_tlpSciButtons->Controls->Add(this->_btnLn, 1, 6);
			this->_tlpSciButtons->Controls->Add(this->_btnLogYX, 0, 5);
			this->_tlpSciButtons->Controls->Add(this->_btnYRoot, 0, 3);
			this->_tlpSciButtons->Location = System::Drawing::Point(3, 199);
			this->_tlpSciButtons->Name = L"_tlpSciButtons";
			this->_tlpSciButtons->RowCount = 7;
			this->_tlpSciButtons->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 14.28571F)));
			this->_tlpSciButtons->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 14.28571F)));
			this->_tlpSciButtons->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 14.28571F)));
			this->_tlpSciButtons->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 14.28571F)));
			this->_tlpSciButtons->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 14.28571F)));
			this->_tlpSciButtons->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 14.28571F)));
			this->_tlpSciButtons->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 14.28571F)));
			this->_tlpSciButtons->Size = System::Drawing::Size(328, 339);
			this->_tlpSciButtons->TabIndex = 0;
			// 
			// _btn0
			// 
			this->_btn0->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->_btn0->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(51)), static_cast<System::Int32>(static_cast<System::Byte>(51)),
				static_cast<System::Int32>(static_cast<System::Byte>(51)));
			this->_btn0->FlatAppearance->BorderSize = 0;
			this->_btn0->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Black;
			this->_btn0->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(94)),
				static_cast<System::Int32>(static_cast<System::Byte>(94)), static_cast<System::Int32>(static_cast<System::Byte>(94)));
			this->_btn0->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->_btn0->Font = (gcnew System::Drawing::Font(L"Consolas", 11));
			this->_btn0->Location = System::Drawing::Point(165, 291);
			this->_btn0->Name = L"_btn0";
			this->_btn0->Size = System::Drawing::Size(48, 45);
			this->_btn0->TabIndex = 0;
			this->_btn0->TabStop = false;
			this->_btn0->Tag = L"alwaysactive";
			this->_btn0->Text = L"0";
			this->_btn0->UseVisualStyleBackColor = false;
			this->_btn0->Click += gcnew System::EventHandler(this, &FrmCalculator::_btnNumber_Click);
			// 
			// _btn1
			// 
			this->_btn1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->_btn1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(51)), static_cast<System::Int32>(static_cast<System::Byte>(51)),
				static_cast<System::Int32>(static_cast<System::Byte>(51)));
			this->_btn1->FlatAppearance->BorderSize = 0;
			this->_btn1->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Black;
			this->_btn1->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(94)),
				static_cast<System::Int32>(static_cast<System::Byte>(94)), static_cast<System::Int32>(static_cast<System::Byte>(94)));
			this->_btn1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->_btn1->Font = (gcnew System::Drawing::Font(L"Consolas", 11));
			this->_btn1->Location = System::Drawing::Point(111, 243);
			this->_btn1->Name = L"_btn1";
			this->_btn1->Size = System::Drawing::Size(48, 42);
			this->_btn1->TabIndex = 0;
			this->_btn1->TabStop = false;
			this->_btn1->Tag = L"alwaysactive";
			this->_btn1->Text = L"1";
			this->_btn1->UseVisualStyleBackColor = false;
			this->_btn1->Click += gcnew System::EventHandler(this, &FrmCalculator::_btnNumber_Click);
			// 
			// _btn2
			// 
			this->_btn2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->_btn2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(51)), static_cast<System::Int32>(static_cast<System::Byte>(51)),
				static_cast<System::Int32>(static_cast<System::Byte>(51)));
			this->_btn2->FlatAppearance->BorderSize = 0;
			this->_btn2->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Black;
			this->_btn2->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(94)),
				static_cast<System::Int32>(static_cast<System::Byte>(94)), static_cast<System::Int32>(static_cast<System::Byte>(94)));
			this->_btn2->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->_btn2->Font = (gcnew System::Drawing::Font(L"Consolas", 11));
			this->_btn2->Location = System::Drawing::Point(165, 243);
			this->_btn2->Name = L"_btn2";
			this->_btn2->Size = System::Drawing::Size(48, 42);
			this->_btn2->TabIndex = 0;
			this->_btn2->TabStop = false;
			this->_btn2->Tag = L"alwaysactive";
			this->_btn2->Text = L"2";
			this->_btn2->UseVisualStyleBackColor = false;
			this->_btn2->Click += gcnew System::EventHandler(this, &FrmCalculator::_btnNumber_Click);
			// 
			// _btn3
			// 
			this->_btn3->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->_btn3->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(51)), static_cast<System::Int32>(static_cast<System::Byte>(51)),
				static_cast<System::Int32>(static_cast<System::Byte>(51)));
			this->_btn3->FlatAppearance->BorderSize = 0;
			this->_btn3->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Black;
			this->_btn3->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(94)),
				static_cast<System::Int32>(static_cast<System::Byte>(94)), static_cast<System::Int32>(static_cast<System::Byte>(94)));
			this->_btn3->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->_btn3->Font = (gcnew System::Drawing::Font(L"Consolas", 11));
			this->_btn3->Location = System::Drawing::Point(219, 243);
			this->_btn3->Name = L"_btn3";
			this->_btn3->Size = System::Drawing::Size(48, 42);
			this->_btn3->TabIndex = 0;
			this->_btn3->TabStop = false;
			this->_btn3->Tag = L"alwaysactive";
			this->_btn3->Text = L"3";
			this->_btn3->UseVisualStyleBackColor = false;
			this->_btn3->Click += gcnew System::EventHandler(this, &FrmCalculator::_btnNumber_Click);
			// 
			// _btn4
			// 
			this->_btn4->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->_btn4->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(51)), static_cast<System::Int32>(static_cast<System::Byte>(51)),
				static_cast<System::Int32>(static_cast<System::Byte>(51)));
			this->_btn4->FlatAppearance->BorderSize = 0;
			this->_btn4->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Black;
			this->_btn4->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(94)),
				static_cast<System::Int32>(static_cast<System::Byte>(94)), static_cast<System::Int32>(static_cast<System::Byte>(94)));
			this->_btn4->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->_btn4->Font = (gcnew System::Drawing::Font(L"Consolas", 11));
			this->_btn4->Location = System::Drawing::Point(111, 195);
			this->_btn4->Name = L"_btn4";
			this->_btn4->Size = System::Drawing::Size(48, 42);
			this->_btn4->TabIndex = 0;
			this->_btn4->TabStop = false;
			this->_btn4->Tag = L"alwaysactive";
			this->_btn4->Text = L"4";
			this->_btn4->UseVisualStyleBackColor = false;
			this->_btn4->Click += gcnew System::EventHandler(this, &FrmCalculator::_btnNumber_Click);
			// 
			// _btn5
			// 
			this->_btn5->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->_btn5->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(51)), static_cast<System::Int32>(static_cast<System::Byte>(51)),
				static_cast<System::Int32>(static_cast<System::Byte>(51)));
			this->_btn5->FlatAppearance->BorderSize = 0;
			this->_btn5->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Black;
			this->_btn5->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(94)),
				static_cast<System::Int32>(static_cast<System::Byte>(94)), static_cast<System::Int32>(static_cast<System::Byte>(94)));
			this->_btn5->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->_btn5->Font = (gcnew System::Drawing::Font(L"Consolas", 11));
			this->_btn5->Location = System::Drawing::Point(165, 195);
			this->_btn5->Name = L"_btn5";
			this->_btn5->Size = System::Drawing::Size(48, 42);
			this->_btn5->TabIndex = 0;
			this->_btn5->TabStop = false;
			this->_btn5->Tag = L"alwaysactive";
			this->_btn5->Text = L"5";
			this->_btn5->UseVisualStyleBackColor = false;
			this->_btn5->Click += gcnew System::EventHandler(this, &FrmCalculator::_btnNumber_Click);
			// 
			// _btn6
			// 
			this->_btn6->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->_btn6->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(51)), static_cast<System::Int32>(static_cast<System::Byte>(51)),
				static_cast<System::Int32>(static_cast<System::Byte>(51)));
			this->_btn6->FlatAppearance->BorderSize = 0;
			this->_btn6->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Black;
			this->_btn6->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(94)),
				static_cast<System::Int32>(static_cast<System::Byte>(94)), static_cast<System::Int32>(static_cast<System::Byte>(94)));
			this->_btn6->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->_btn6->Font = (gcnew System::Drawing::Font(L"Consolas", 11));
			this->_btn6->Location = System::Drawing::Point(219, 195);
			this->_btn6->Name = L"_btn6";
			this->_btn6->Size = System::Drawing::Size(48, 42);
			this->_btn6->TabIndex = 0;
			this->_btn6->TabStop = false;
			this->_btn6->Tag = L"alwaysactive";
			this->_btn6->Text = L"6";
			this->_btn6->UseVisualStyleBackColor = false;
			this->_btn6->Click += gcnew System::EventHandler(this, &FrmCalculator::_btnNumber_Click);
			// 
			// _btn9
			// 
			this->_btn9->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->_btn9->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(51)), static_cast<System::Int32>(static_cast<System::Byte>(51)),
				static_cast<System::Int32>(static_cast<System::Byte>(51)));
			this->_btn9->FlatAppearance->BorderSize = 0;
			this->_btn9->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Black;
			this->_btn9->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(94)),
				static_cast<System::Int32>(static_cast<System::Byte>(94)), static_cast<System::Int32>(static_cast<System::Byte>(94)));
			this->_btn9->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->_btn9->Font = (gcnew System::Drawing::Font(L"Consolas", 11));
			this->_btn9->Location = System::Drawing::Point(219, 147);
			this->_btn9->Name = L"_btn9";
			this->_btn9->Size = System::Drawing::Size(48, 42);
			this->_btn9->TabIndex = 0;
			this->_btn9->TabStop = false;
			this->_btn9->Tag = L"alwaysactive";
			this->_btn9->Text = L"9";
			this->_btn9->UseVisualStyleBackColor = false;
			this->_btn9->Click += gcnew System::EventHandler(this, &FrmCalculator::_btnNumber_Click);
			// 
			// _btn8
			// 
			this->_btn8->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->_btn8->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(51)), static_cast<System::Int32>(static_cast<System::Byte>(51)),
				static_cast<System::Int32>(static_cast<System::Byte>(51)));
			this->_btn8->FlatAppearance->BorderSize = 0;
			this->_btn8->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Black;
			this->_btn8->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(94)),
				static_cast<System::Int32>(static_cast<System::Byte>(94)), static_cast<System::Int32>(static_cast<System::Byte>(94)));
			this->_btn8->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->_btn8->Font = (gcnew System::Drawing::Font(L"Consolas", 11));
			this->_btn8->Location = System::Drawing::Point(165, 147);
			this->_btn8->Name = L"_btn8";
			this->_btn8->Size = System::Drawing::Size(48, 42);
			this->_btn8->TabIndex = 0;
			this->_btn8->TabStop = false;
			this->_btn8->Tag = L"alwaysactive";
			this->_btn8->Text = L"8";
			this->_btn8->UseVisualStyleBackColor = false;
			this->_btn8->Click += gcnew System::EventHandler(this, &FrmCalculator::_btnNumber_Click);
			// 
			// _btn7
			// 
			this->_btn7->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->_btn7->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(51)), static_cast<System::Int32>(static_cast<System::Byte>(51)),
				static_cast<System::Int32>(static_cast<System::Byte>(51)));
			this->_btn7->FlatAppearance->BorderSize = 0;
			this->_btn7->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Black;
			this->_btn7->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(94)),
				static_cast<System::Int32>(static_cast<System::Byte>(94)), static_cast<System::Int32>(static_cast<System::Byte>(94)));
			this->_btn7->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->_btn7->Font = (gcnew System::Drawing::Font(L"Consolas", 11));
			this->_btn7->Location = System::Drawing::Point(111, 147);
			this->_btn7->Name = L"_btn7";
			this->_btn7->Size = System::Drawing::Size(48, 42);
			this->_btn7->TabIndex = 0;
			this->_btn7->TabStop = false;
			this->_btn7->Tag = L"alwaysactive";
			this->_btn7->Text = L"7";
			this->_btn7->UseVisualStyleBackColor = false;
			this->_btn7->Click += gcnew System::EventHandler(this, &FrmCalculator::_btnNumber_Click);
			// 
			// _btnPoint
			// 
			this->_btnPoint->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->_btnPoint->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(51)), static_cast<System::Int32>(static_cast<System::Byte>(51)),
				static_cast<System::Int32>(static_cast<System::Byte>(51)));
			this->_btnPoint->FlatAppearance->BorderSize = 0;
			this->_btnPoint->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Black;
			this->_btnPoint->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(94)),
				static_cast<System::Int32>(static_cast<System::Byte>(94)), static_cast<System::Int32>(static_cast<System::Byte>(94)));
			this->_btnPoint->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->_btnPoint->Font = (gcnew System::Drawing::Font(L"Consolas", 11));
			this->_btnPoint->Location = System::Drawing::Point(219, 291);
			this->_btnPoint->Name = L"_btnPoint";
			this->_btnPoint->Size = System::Drawing::Size(48, 45);
			this->_btnPoint->TabIndex = 0;
			this->_btnPoint->TabStop = false;
			this->_btnPoint->Text = L".";
			this->_btnPoint->UseVisualStyleBackColor = false;
			this->_btnPoint->Click += gcnew System::EventHandler(this, &FrmCalculator::_btnPoint_Click);
			// 
			// _btnPlusMinus
			// 
			this->_btnPlusMinus->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->_btnPlusMinus->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(51)), static_cast<System::Int32>(static_cast<System::Byte>(51)),
				static_cast<System::Int32>(static_cast<System::Byte>(51)));
			this->_btnPlusMinus->FlatAppearance->BorderSize = 0;
			this->_btnPlusMinus->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Black;
			this->_btnPlusMinus->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(94)),
				static_cast<System::Int32>(static_cast<System::Byte>(94)), static_cast<System::Int32>(static_cast<System::Byte>(94)));
			this->_btnPlusMinus->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->_btnPlusMinus->Font = (gcnew System::Drawing::Font(L"Consolas", 11));
			this->_btnPlusMinus->Location = System::Drawing::Point(111, 291);
			this->_btnPlusMinus->Name = L"_btnPlusMinus";
			this->_btnPlusMinus->Size = System::Drawing::Size(48, 45);
			this->_btnPlusMinus->TabIndex = 0;
			this->_btnPlusMinus->TabStop = false;
			this->_btnPlusMinus->Text = L"±";
			this->_btnPlusMinus->UseVisualStyleBackColor = false;
			this->_btnPlusMinus->Click += gcnew System::EventHandler(this, &FrmCalculator::_btnPlusMinus_Click);
			// 
			// _btnMultiply
			// 
			this->_btnMultiply->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->_btnMultiply->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(31)), static_cast<System::Int32>(static_cast<System::Byte>(31)),
				static_cast<System::Int32>(static_cast<System::Byte>(31)));
			this->_btnMultiply->FlatAppearance->BorderSize = 0;
			this->_btnMultiply->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Black;
			this->_btnMultiply->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(51)),
				static_cast<System::Int32>(static_cast<System::Byte>(51)), static_cast<System::Int32>(static_cast<System::Byte>(51)));
			this->_btnMultiply->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->_btnMultiply->Font = (gcnew System::Drawing::Font(L"Consolas", 14));
			this->_btnMultiply->Location = System::Drawing::Point(273, 147);
			this->_btnMultiply->Name = L"_btnMultiply";
			this->_btnMultiply->Size = System::Drawing::Size(52, 42);
			this->_btnMultiply->TabIndex = 0;
			this->_btnMultiply->TabStop = false;
			this->_btnMultiply->Text = L"×";
			this->_btnMultiply->UseVisualStyleBackColor = false;
			this->_btnMultiply->Click += gcnew System::EventHandler(this, &FrmCalculator::_btnMultiply_Click);
			// 
			// _btnMinus
			// 
			this->_btnMinus->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->_btnMinus->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(31)), static_cast<System::Int32>(static_cast<System::Byte>(31)),
				static_cast<System::Int32>(static_cast<System::Byte>(31)));
			this->_btnMinus->FlatAppearance->BorderSize = 0;
			this->_btnMinus->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Black;
			this->_btnMinus->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(51)),
				static_cast<System::Int32>(static_cast<System::Byte>(51)), static_cast<System::Int32>(static_cast<System::Byte>(51)));
			this->_btnMinus->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->_btnMinus->Font = (gcnew System::Drawing::Font(L"Consolas", 14));
			this->_btnMinus->Location = System::Drawing::Point(273, 195);
			this->_btnMinus->Name = L"_btnMinus";
			this->_btnMinus->Size = System::Drawing::Size(52, 42);
			this->_btnMinus->TabIndex = 0;
			this->_btnMinus->TabStop = false;
			this->_btnMinus->Text = L"−";
			this->_btnMinus->UseVisualStyleBackColor = false;
			this->_btnMinus->Click += gcnew System::EventHandler(this, &FrmCalculator::_btnMinus_Click);
			// 
			// _btnPlus
			// 
			this->_btnPlus->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->_btnPlus->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(31)), static_cast<System::Int32>(static_cast<System::Byte>(31)),
				static_cast<System::Int32>(static_cast<System::Byte>(31)));
			this->_btnPlus->FlatAppearance->BorderSize = 0;
			this->_btnPlus->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Black;
			this->_btnPlus->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(51)),
				static_cast<System::Int32>(static_cast<System::Byte>(51)), static_cast<System::Int32>(static_cast<System::Byte>(51)));
			this->_btnPlus->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->_btnPlus->Font = (gcnew System::Drawing::Font(L"Consolas", 14));
			this->_btnPlus->Location = System::Drawing::Point(273, 243);
			this->_btnPlus->Name = L"_btnPlus";
			this->_btnPlus->Size = System::Drawing::Size(52, 42);
			this->_btnPlus->TabIndex = 0;
			this->_btnPlus->TabStop = false;
			this->_btnPlus->Text = L"+";
			this->_btnPlus->UseVisualStyleBackColor = false;
			this->_btnPlus->Click += gcnew System::EventHandler(this, &FrmCalculator::_btnPlus_Click);
			// 
			// _btnEquals
			// 
			this->_btnEquals->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->_btnEquals->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(69)), static_cast<System::Int32>(static_cast<System::Byte>(98)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)));
			this->_btnEquals->FlatAppearance->BorderSize = 0;
			this->_btnEquals->FlatAppearance->MouseDownBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(24)),
				static_cast<System::Int32>(static_cast<System::Byte>(35)), static_cast<System::Int32>(static_cast<System::Byte>(46)));
			this->_btnEquals->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(91)),
				static_cast<System::Int32>(static_cast<System::Byte>(134)), static_cast<System::Int32>(static_cast<System::Byte>(179)));
			this->_btnEquals->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->_btnEquals->Font = (gcnew System::Drawing::Font(L"Consolas", 14));
			this->_btnEquals->Location = System::Drawing::Point(273, 291);
			this->_btnEquals->Name = L"_btnEquals";
			this->_btnEquals->Size = System::Drawing::Size(52, 45);
			this->_btnEquals->TabIndex = 0;
			this->_btnEquals->TabStop = false;
			this->_btnEquals->Tag = L"alwaysactive";
			this->_btnEquals->Text = L"=";
			this->_btnEquals->UseVisualStyleBackColor = false;
			this->_btnEquals->Click += gcnew System::EventHandler(this, &FrmCalculator::_btnEquals_Click);
			// 
			// _btnDivide
			// 
			this->_btnDivide->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->_btnDivide->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(31)), static_cast<System::Int32>(static_cast<System::Byte>(31)),
				static_cast<System::Int32>(static_cast<System::Byte>(31)));
			this->_btnDivide->FlatAppearance->BorderSize = 0;
			this->_btnDivide->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Black;
			this->_btnDivide->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(51)),
				static_cast<System::Int32>(static_cast<System::Byte>(51)), static_cast<System::Int32>(static_cast<System::Byte>(51)));
			this->_btnDivide->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->_btnDivide->Font = (gcnew System::Drawing::Font(L"Consolas", 14));
			this->_btnDivide->Location = System::Drawing::Point(273, 99);
			this->_btnDivide->Name = L"_btnDivide";
			this->_btnDivide->Size = System::Drawing::Size(52, 42);
			this->_btnDivide->TabIndex = 0;
			this->_btnDivide->TabStop = false;
			this->_btnDivide->Text = L"÷";
			this->_btnDivide->UseVisualStyleBackColor = false;
			this->_btnDivide->Click += gcnew System::EventHandler(this, &FrmCalculator::_btnDivide_Click);
			// 
			// _btnBackspace
			// 
			this->_btnBackspace->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->_btnBackspace->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(31)), static_cast<System::Int32>(static_cast<System::Byte>(31)),
				static_cast<System::Int32>(static_cast<System::Byte>(31)));
			this->_btnBackspace->FlatAppearance->BorderSize = 0;
			this->_btnBackspace->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Black;
			this->_btnBackspace->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(51)),
				static_cast<System::Int32>(static_cast<System::Byte>(51)), static_cast<System::Int32>(static_cast<System::Byte>(51)));
			this->_btnBackspace->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->_btnBackspace->Font = (gcnew System::Drawing::Font(L"Segoe UI", 11));
			this->_btnBackspace->Location = System::Drawing::Point(273, 3);
			this->_btnBackspace->Name = L"_btnBackspace";
			this->_btnBackspace->Size = System::Drawing::Size(52, 42);
			this->_btnBackspace->TabIndex = 0;
			this->_btnBackspace->TabStop = false;
			this->_btnBackspace->Tag = L"alwaysactive";
			this->_btnBackspace->Text = L"⌫";
			this->_btnBackspace->UseVisualStyleBackColor = false;
			this->_btnBackspace->Click += gcnew System::EventHandler(this, &FrmCalculator::_btnBackspace_Click);
			// 
			// _btnModulo
			// 
			this->_btnModulo->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->_btnModulo->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(31)), static_cast<System::Int32>(static_cast<System::Byte>(31)),
				static_cast<System::Int32>(static_cast<System::Byte>(31)));
			this->_btnModulo->FlatAppearance->BorderSize = 0;
			this->_btnModulo->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Black;
			this->_btnModulo->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(51)),
				static_cast<System::Int32>(static_cast<System::Byte>(51)), static_cast<System::Int32>(static_cast<System::Byte>(51)));
			this->_btnModulo->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->_btnModulo->Font = (gcnew System::Drawing::Font(L"Consolas", 11));
			this->_btnModulo->Location = System::Drawing::Point(273, 51);
			this->_btnModulo->Name = L"_btnModulo";
			this->_btnModulo->Size = System::Drawing::Size(52, 42);
			this->_btnModulo->TabIndex = 0;
			this->_btnModulo->TabStop = false;
			this->_btnModulo->Text = L"mod";
			this->_btnModulo->UseVisualStyleBackColor = false;
			this->_btnModulo->Click += gcnew System::EventHandler(this, &FrmCalculator::_btnModulo_Click);
			// 
			// _btnCE
			// 
			this->_btnCE->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->_btnCE->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(31)), static_cast<System::Int32>(static_cast<System::Byte>(31)),
				static_cast<System::Int32>(static_cast<System::Byte>(31)));
			this->_btnCE->FlatAppearance->BorderSize = 0;
			this->_btnCE->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Black;
			this->_btnCE->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(51)),
				static_cast<System::Int32>(static_cast<System::Byte>(51)), static_cast<System::Int32>(static_cast<System::Byte>(51)));
			this->_btnCE->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->_btnCE->Font = (gcnew System::Drawing::Font(L"Consolas", 11));
			this->_btnCE->Location = System::Drawing::Point(219, 3);
			this->_btnCE->Name = L"_btnCE";
			this->_btnCE->Size = System::Drawing::Size(48, 42);
			this->_btnCE->TabIndex = 0;
			this->_btnCE->TabStop = false;
			this->_btnCE->Tag = L"alwaysactive";
			this->_btnCE->Text = L"CE";
			this->_btnCE->UseVisualStyleBackColor = false;
			this->_btnCE->Click += gcnew System::EventHandler(this, &FrmCalculator::_btnCE_Click);
			// 
			// _btnInvert
			// 
			this->_btnInvert->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->_btnInvert->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(31)), static_cast<System::Int32>(static_cast<System::Byte>(31)),
				static_cast<System::Int32>(static_cast<System::Byte>(31)));
			this->_btnInvert->FlatAppearance->BorderSize = 0;
			this->_btnInvert->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Black;
			this->_btnInvert->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(51)),
				static_cast<System::Int32>(static_cast<System::Byte>(51)), static_cast<System::Int32>(static_cast<System::Byte>(51)));
			this->_btnInvert->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->_btnInvert->Font = (gcnew System::Drawing::Font(L"Consolas", 11));
			this->_btnInvert->Location = System::Drawing::Point(111, 51);
			this->_btnInvert->Name = L"_btnInvert";
			this->_btnInvert->Size = System::Drawing::Size(48, 42);
			this->_btnInvert->TabIndex = 0;
			this->_btnInvert->TabStop = false;
			this->_btnInvert->Text = L"1/x";
			this->_btnInvert->UseVisualStyleBackColor = false;
			this->_btnInvert->Click += gcnew System::EventHandler(this, &FrmCalculator::_btnInvert_Click);
			// 
			// _btnExp
			// 
			this->_btnExp->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->_btnExp->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(31)), static_cast<System::Int32>(static_cast<System::Byte>(31)),
				static_cast<System::Int32>(static_cast<System::Byte>(31)));
			this->_btnExp->FlatAppearance->BorderSize = 0;
			this->_btnExp->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Black;
			this->_btnExp->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(51)),
				static_cast<System::Int32>(static_cast<System::Byte>(51)), static_cast<System::Int32>(static_cast<System::Byte>(51)));
			this->_btnExp->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->_btnExp->Font = (gcnew System::Drawing::Font(L"Consolas", 11));
			this->_btnExp->Location = System::Drawing::Point(219, 51);
			this->_btnExp->Name = L"_btnExp";
			this->_btnExp->Size = System::Drawing::Size(48, 42);
			this->_btnExp->TabIndex = 0;
			this->_btnExp->TabStop = false;
			this->_btnExp->Text = L"exp";
			this->_btnExp->UseVisualStyleBackColor = false;
			this->_btnExp->Click += gcnew System::EventHandler(this, &FrmCalculator::_btnExp_Click);
			// 
			// _btnAbs
			// 
			this->_btnAbs->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->_btnAbs->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(31)), static_cast<System::Int32>(static_cast<System::Byte>(31)),
				static_cast<System::Int32>(static_cast<System::Byte>(31)));
			this->_btnAbs->FlatAppearance->BorderSize = 0;
			this->_btnAbs->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Black;
			this->_btnAbs->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(51)),
				static_cast<System::Int32>(static_cast<System::Byte>(51)), static_cast<System::Int32>(static_cast<System::Byte>(51)));
			this->_btnAbs->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->_btnAbs->Font = (gcnew System::Drawing::Font(L"Consolas", 11));
			this->_btnAbs->Location = System::Drawing::Point(165, 51);
			this->_btnAbs->Name = L"_btnAbs";
			this->_btnAbs->Size = System::Drawing::Size(48, 42);
			this->_btnAbs->TabIndex = 0;
			this->_btnAbs->TabStop = false;
			this->_btnAbs->Text = L"|x|";
			this->_btnAbs->UseVisualStyleBackColor = false;
			this->_btnAbs->Click += gcnew System::EventHandler(this, &FrmCalculator::_btnAbs_Click);
			// 
			// _btnFactorial
			// 
			this->_btnFactorial->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->_btnFactorial->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(31)), static_cast<System::Int32>(static_cast<System::Byte>(31)),
				static_cast<System::Int32>(static_cast<System::Byte>(31)));
			this->_btnFactorial->FlatAppearance->BorderSize = 0;
			this->_btnFactorial->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Black;
			this->_btnFactorial->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(51)),
				static_cast<System::Int32>(static_cast<System::Byte>(51)), static_cast<System::Int32>(static_cast<System::Byte>(51)));
			this->_btnFactorial->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->_btnFactorial->Font = (gcnew System::Drawing::Font(L"Consolas", 11));
			this->_btnFactorial->Location = System::Drawing::Point(219, 99);
			this->_btnFactorial->Name = L"_btnFactorial";
			this->_btnFactorial->Size = System::Drawing::Size(48, 42);
			this->_btnFactorial->TabIndex = 0;
			this->_btnFactorial->TabStop = false;
			this->_btnFactorial->Text = L"n!";
			this->_btnFactorial->UseVisualStyleBackColor = false;
			this->_btnFactorial->Click += gcnew System::EventHandler(this, &FrmCalculator::_btnFactorial_Click);
			// 
			// _btnRightParenthesis
			// 
			this->_btnRightParenthesis->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->_btnRightParenthesis->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(31)),
				static_cast<System::Int32>(static_cast<System::Byte>(31)), static_cast<System::Int32>(static_cast<System::Byte>(31)));
			this->_btnRightParenthesis->FlatAppearance->BorderSize = 0;
			this->_btnRightParenthesis->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Black;
			this->_btnRightParenthesis->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(51)),
				static_cast<System::Int32>(static_cast<System::Byte>(51)), static_cast<System::Int32>(static_cast<System::Byte>(51)));
			this->_btnRightParenthesis->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->_btnRightParenthesis->Font = (gcnew System::Drawing::Font(L"Consolas", 11));
			this->_btnRightParenthesis->Location = System::Drawing::Point(165, 99);
			this->_btnRightParenthesis->Name = L"_btnRightParenthesis";
			this->_btnRightParenthesis->Size = System::Drawing::Size(48, 42);
			this->_btnRightParenthesis->TabIndex = 0;
			this->_btnRightParenthesis->TabStop = false;
			this->_btnRightParenthesis->Text = L")";
			this->_btnRightParenthesis->UseVisualStyleBackColor = false;
			this->_btnRightParenthesis->Click += gcnew System::EventHandler(this, &FrmCalculator::_btnRightParenthesis_Click);
			// 
			// _btnLeftParenthesis
			// 
			this->_btnLeftParenthesis->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->_btnLeftParenthesis->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(31)),
				static_cast<System::Int32>(static_cast<System::Byte>(31)), static_cast<System::Int32>(static_cast<System::Byte>(31)));
			this->_btnLeftParenthesis->FlatAppearance->BorderSize = 0;
			this->_btnLeftParenthesis->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Black;
			this->_btnLeftParenthesis->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(51)),
				static_cast<System::Int32>(static_cast<System::Byte>(51)), static_cast<System::Int32>(static_cast<System::Byte>(51)));
			this->_btnLeftParenthesis->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->_btnLeftParenthesis->Font = (gcnew System::Drawing::Font(L"Consolas", 11));
			this->_btnLeftParenthesis->Location = System::Drawing::Point(111, 99);
			this->_btnLeftParenthesis->Name = L"_btnLeftParenthesis";
			this->_btnLeftParenthesis->Size = System::Drawing::Size(48, 42);
			this->_btnLeftParenthesis->TabIndex = 0;
			this->_btnLeftParenthesis->TabStop = false;
			this->_btnLeftParenthesis->Text = L"(";
			this->_btnLeftParenthesis->UseVisualStyleBackColor = false;
			this->_btnLeftParenthesis->Click += gcnew System::EventHandler(this, &FrmCalculator::_btnLeftParenthesis_Click);
			// 
			// _btn2ndOn
			// 
			this->_btn2ndOn->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->_btn2ndOn->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(31)), static_cast<System::Int32>(static_cast<System::Byte>(31)),
				static_cast<System::Int32>(static_cast<System::Byte>(31)));
			this->_btn2ndOn->FlatAppearance->BorderSize = 0;
			this->_btn2ndOn->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Black;
			this->_btn2ndOn->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(51)),
				static_cast<System::Int32>(static_cast<System::Byte>(51)), static_cast<System::Int32>(static_cast<System::Byte>(51)));
			this->_btn2ndOn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->_btn2ndOn->Font = (gcnew System::Drawing::Font(L"Segoe UI", 11));
			this->_btn2ndOn->Location = System::Drawing::Point(57, 3);
			this->_btn2ndOn->Name = L"_btn2ndOn";
			this->_btn2ndOn->Size = System::Drawing::Size(48, 42);
			this->_btn2ndOn->TabIndex = 0;
			this->_btn2ndOn->TabStop = false;
			this->_btn2ndOn->Text = L"2ᴺᴰ";
			this->_btn2ndOn->UseVisualStyleBackColor = false;
			this->_btn2ndOn->Click += gcnew System::EventHandler(this, &FrmCalculator::_btn2ndOn_Click);
			// 
			// _btnPow
			// 
			this->_btnPow->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->_btnPow->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(31)), static_cast<System::Int32>(static_cast<System::Byte>(31)),
				static_cast<System::Int32>(static_cast<System::Byte>(31)));
			this->_btnPow->FlatAppearance->BorderSize = 0;
			this->_btnPow->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Black;
			this->_btnPow->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(51)),
				static_cast<System::Int32>(static_cast<System::Byte>(51)), static_cast<System::Int32>(static_cast<System::Byte>(51)));
			this->_btnPow->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->_btnPow->Font = (gcnew System::Drawing::Font(L"Consolas", 11));
			this->_btnPow->Location = System::Drawing::Point(57, 147);
			this->_btnPow->Name = L"_btnPow";
			this->_btnPow->Size = System::Drawing::Size(48, 42);
			this->_btnPow->TabIndex = 0;
			this->_btnPow->TabStop = false;
			this->_btnPow->Text = L"xʸ";
			this->_btnPow->UseVisualStyleBackColor = false;
			this->_btnPow->Click += gcnew System::EventHandler(this, &FrmCalculator::_btnPow_Click);
			// 
			// _btnE
			// 
			this->_btnE->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->_btnE->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(31)), static_cast<System::Int32>(static_cast<System::Byte>(31)),
				static_cast<System::Int32>(static_cast<System::Byte>(31)));
			this->_btnE->FlatAppearance->BorderSize = 0;
			this->_btnE->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Black;
			this->_btnE->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(51)),
				static_cast<System::Int32>(static_cast<System::Byte>(51)), static_cast<System::Int32>(static_cast<System::Byte>(51)));
			this->_btnE->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->_btnE->Font = (gcnew System::Drawing::Font(L"Consolas", 11));
			this->_btnE->Location = System::Drawing::Point(165, 3);
			this->_btnE->Name = L"_btnE";
			this->_btnE->Size = System::Drawing::Size(48, 42);
			this->_btnE->TabIndex = 0;
			this->_btnE->TabStop = false;
			this->_btnE->Text = L"e";
			this->_btnE->UseVisualStyleBackColor = false;
			this->_btnE->Click += gcnew System::EventHandler(this, &FrmCalculator::_btnE_Click);
			// 
			// _btnPi
			// 
			this->_btnPi->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->_btnPi->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(31)), static_cast<System::Int32>(static_cast<System::Byte>(31)),
				static_cast<System::Int32>(static_cast<System::Byte>(31)));
			this->_btnPi->FlatAppearance->BorderSize = 0;
			this->_btnPi->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Black;
			this->_btnPi->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(51)),
				static_cast<System::Int32>(static_cast<System::Byte>(51)), static_cast<System::Int32>(static_cast<System::Byte>(51)));
			this->_btnPi->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->_btnPi->Font = (gcnew System::Drawing::Font(L"Consolas", 11));
			this->_btnPi->Location = System::Drawing::Point(111, 3);
			this->_btnPi->Name = L"_btnPi";
			this->_btnPi->Size = System::Drawing::Size(48, 42);
			this->_btnPi->TabIndex = 0;
			this->_btnPi->TabStop = false;
			this->_btnPi->Text = L"π";
			this->_btnPi->UseVisualStyleBackColor = false;
			this->_btnPi->Click += gcnew System::EventHandler(this, &FrmCalculator::_btnPi_Click);
			// 
			// _btn2ndOff
			// 
			this->_btn2ndOff->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->_btn2ndOff->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(69)), static_cast<System::Int32>(static_cast<System::Byte>(98)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)));
			this->_btn2ndOff->FlatAppearance->BorderSize = 0;
			this->_btn2ndOff->FlatAppearance->MouseDownBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(24)),
				static_cast<System::Int32>(static_cast<System::Byte>(35)), static_cast<System::Int32>(static_cast<System::Byte>(46)));
			this->_btn2ndOff->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(91)),
				static_cast<System::Int32>(static_cast<System::Byte>(134)), static_cast<System::Int32>(static_cast<System::Byte>(179)));
			this->_btn2ndOff->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->_btn2ndOff->Font = (gcnew System::Drawing::Font(L"Segoe UI", 11));
			this->_btn2ndOff->Location = System::Drawing::Point(3, 3);
			this->_btn2ndOff->Name = L"_btn2ndOff";
			this->_btn2ndOff->Size = System::Drawing::Size(48, 42);
			this->_btn2ndOff->TabIndex = 0;
			this->_btn2ndOff->TabStop = false;
			this->_btn2ndOff->Text = L"2ᴺᴰ";
			this->_btn2ndOff->UseVisualStyleBackColor = false;
			this->_btn2ndOff->Click += gcnew System::EventHandler(this, &FrmCalculator::_btn2ndOff_Click);
			// 
			// _btnSqrt
			// 
			this->_btnSqrt->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->_btnSqrt->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(31)), static_cast<System::Int32>(static_cast<System::Byte>(31)),
				static_cast<System::Int32>(static_cast<System::Byte>(31)));
			this->_btnSqrt->FlatAppearance->BorderSize = 0;
			this->_btnSqrt->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Black;
			this->_btnSqrt->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(51)),
				static_cast<System::Int32>(static_cast<System::Byte>(51)), static_cast<System::Int32>(static_cast<System::Byte>(51)));
			this->_btnSqrt->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->_btnSqrt->Font = (gcnew System::Drawing::Font(L"Consolas", 11));
			this->_btnSqrt->Location = System::Drawing::Point(3, 51);
			this->_btnSqrt->Name = L"_btnSqrt";
			this->_btnSqrt->Size = System::Drawing::Size(48, 42);
			this->_btnSqrt->TabIndex = 0;
			this->_btnSqrt->TabStop = false;
			this->_btnSqrt->Text = L"√x";
			this->_btnSqrt->UseVisualStyleBackColor = false;
			this->_btnSqrt->Click += gcnew System::EventHandler(this, &FrmCalculator::_btnSqrt_Click);
			// 
			// _btnCubeRoot
			// 
			this->_btnCubeRoot->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->_btnCubeRoot->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(31)), static_cast<System::Int32>(static_cast<System::Byte>(31)),
				static_cast<System::Int32>(static_cast<System::Byte>(31)));
			this->_btnCubeRoot->FlatAppearance->BorderSize = 0;
			this->_btnCubeRoot->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Black;
			this->_btnCubeRoot->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(51)),
				static_cast<System::Int32>(static_cast<System::Byte>(51)), static_cast<System::Int32>(static_cast<System::Byte>(51)));
			this->_btnCubeRoot->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->_btnCubeRoot->Font = (gcnew System::Drawing::Font(L"Consolas", 11));
			this->_btnCubeRoot->Location = System::Drawing::Point(3, 99);
			this->_btnCubeRoot->Name = L"_btnCubeRoot";
			this->_btnCubeRoot->Size = System::Drawing::Size(48, 42);
			this->_btnCubeRoot->TabIndex = 0;
			this->_btnCubeRoot->TabStop = false;
			this->_btnCubeRoot->Text = L"³√x";
			this->_btnCubeRoot->UseVisualStyleBackColor = false;
			this->_btnCubeRoot->Click += gcnew System::EventHandler(this, &FrmCalculator::_btnCubeRoot_Click);
			// 
			// _btn2ToX
			// 
			this->_btn2ToX->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->_btn2ToX->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(31)), static_cast<System::Int32>(static_cast<System::Byte>(31)),
				static_cast<System::Int32>(static_cast<System::Byte>(31)));
			this->_btn2ToX->FlatAppearance->BorderSize = 0;
			this->_btn2ToX->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Black;
			this->_btn2ToX->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(51)),
				static_cast<System::Int32>(static_cast<System::Byte>(51)), static_cast<System::Int32>(static_cast<System::Byte>(51)));
			this->_btn2ToX->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->_btn2ToX->Font = (gcnew System::Drawing::Font(L"Consolas", 11));
			this->_btn2ToX->Location = System::Drawing::Point(3, 195);
			this->_btn2ToX->Name = L"_btn2ToX";
			this->_btn2ToX->Size = System::Drawing::Size(48, 42);
			this->_btn2ToX->TabIndex = 0;
			this->_btn2ToX->TabStop = false;
			this->_btn2ToX->Text = L"2ˣ";
			this->_btn2ToX->UseVisualStyleBackColor = false;
			this->_btn2ToX->Click += gcnew System::EventHandler(this, &FrmCalculator::_btn2ToX_Click);
			// 
			// _btnEToX
			// 
			this->_btnEToX->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->_btnEToX->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(31)), static_cast<System::Int32>(static_cast<System::Byte>(31)),
				static_cast<System::Int32>(static_cast<System::Byte>(31)));
			this->_btnEToX->FlatAppearance->BorderSize = 0;
			this->_btnEToX->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Black;
			this->_btnEToX->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(51)),
				static_cast<System::Int32>(static_cast<System::Byte>(51)), static_cast<System::Int32>(static_cast<System::Byte>(51)));
			this->_btnEToX->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->_btnEToX->Font = (gcnew System::Drawing::Font(L"Consolas", 11));
			this->_btnEToX->Location = System::Drawing::Point(3, 291);
			this->_btnEToX->Name = L"_btnEToX";
			this->_btnEToX->Size = System::Drawing::Size(48, 45);
			this->_btnEToX->TabIndex = 0;
			this->_btnEToX->TabStop = false;
			this->_btnEToX->Text = L"eˣ";
			this->_btnEToX->UseVisualStyleBackColor = false;
			this->_btnEToX->Click += gcnew System::EventHandler(this, &FrmCalculator::_btnEToX_Click);
			// 
			// _btnSqr
			// 
			this->_btnSqr->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->_btnSqr->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(31)), static_cast<System::Int32>(static_cast<System::Byte>(31)),
				static_cast<System::Int32>(static_cast<System::Byte>(31)));
			this->_btnSqr->FlatAppearance->BorderSize = 0;
			this->_btnSqr->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Black;
			this->_btnSqr->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(51)),
				static_cast<System::Int32>(static_cast<System::Byte>(51)), static_cast<System::Int32>(static_cast<System::Byte>(51)));
			this->_btnSqr->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->_btnSqr->Font = (gcnew System::Drawing::Font(L"Consolas", 11));
			this->_btnSqr->Location = System::Drawing::Point(57, 51);
			this->_btnSqr->Name = L"_btnSqr";
			this->_btnSqr->Size = System::Drawing::Size(48, 42);
			this->_btnSqr->TabIndex = 0;
			this->_btnSqr->TabStop = false;
			this->_btnSqr->Text = L"x²";
			this->_btnSqr->UseVisualStyleBackColor = false;
			this->_btnSqr->Click += gcnew System::EventHandler(this, &FrmCalculator::_btnSqr_Click);
			// 
			// _btnCube
			// 
			this->_btnCube->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->_btnCube->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(31)), static_cast<System::Int32>(static_cast<System::Byte>(31)),
				static_cast<System::Int32>(static_cast<System::Byte>(31)));
			this->_btnCube->FlatAppearance->BorderSize = 0;
			this->_btnCube->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Black;
			this->_btnCube->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(51)),
				static_cast<System::Int32>(static_cast<System::Byte>(51)), static_cast<System::Int32>(static_cast<System::Byte>(51)));
			this->_btnCube->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->_btnCube->Font = (gcnew System::Drawing::Font(L"Consolas", 11));
			this->_btnCube->Location = System::Drawing::Point(57, 99);
			this->_btnCube->Name = L"_btnCube";
			this->_btnCube->Size = System::Drawing::Size(48, 42);
			this->_btnCube->TabIndex = 0;
			this->_btnCube->TabStop = false;
			this->_btnCube->Text = L"x³";
			this->_btnCube->UseVisualStyleBackColor = false;
			this->_btnCube->Click += gcnew System::EventHandler(this, &FrmCalculator::_btnCube_Click);
			// 
			// _btn10ToX
			// 
			this->_btn10ToX->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->_btn10ToX->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(31)), static_cast<System::Int32>(static_cast<System::Byte>(31)),
				static_cast<System::Int32>(static_cast<System::Byte>(31)));
			this->_btn10ToX->FlatAppearance->BorderSize = 0;
			this->_btn10ToX->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Black;
			this->_btn10ToX->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(51)),
				static_cast<System::Int32>(static_cast<System::Byte>(51)), static_cast<System::Int32>(static_cast<System::Byte>(51)));
			this->_btn10ToX->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->_btn10ToX->Font = (gcnew System::Drawing::Font(L"Consolas", 11));
			this->_btn10ToX->Location = System::Drawing::Point(57, 195);
			this->_btn10ToX->Name = L"_btn10ToX";
			this->_btn10ToX->Size = System::Drawing::Size(48, 42);
			this->_btn10ToX->TabIndex = 0;
			this->_btn10ToX->TabStop = false;
			this->_btn10ToX->Text = L"10ˣ";
			this->_btn10ToX->UseVisualStyleBackColor = false;
			this->_btn10ToX->Click += gcnew System::EventHandler(this, &FrmCalculator::_btn10ToX_Click);
			// 
			// _btnLog
			// 
			this->_btnLog->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->_btnLog->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(31)), static_cast<System::Int32>(static_cast<System::Byte>(31)),
				static_cast<System::Int32>(static_cast<System::Byte>(31)));
			this->_btnLog->FlatAppearance->BorderSize = 0;
			this->_btnLog->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Black;
			this->_btnLog->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(51)),
				static_cast<System::Int32>(static_cast<System::Byte>(51)), static_cast<System::Int32>(static_cast<System::Byte>(51)));
			this->_btnLog->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->_btnLog->Font = (gcnew System::Drawing::Font(L"Consolas", 11));
			this->_btnLog->Location = System::Drawing::Point(57, 243);
			this->_btnLog->Name = L"_btnLog";
			this->_btnLog->Size = System::Drawing::Size(48, 42);
			this->_btnLog->TabIndex = 0;
			this->_btnLog->TabStop = false;
			this->_btnLog->Text = L"log";
			this->_btnLog->UseVisualStyleBackColor = false;
			this->_btnLog->Click += gcnew System::EventHandler(this, &FrmCalculator::_btnLog_Click);
			// 
			// _btnLn
			// 
			this->_btnLn->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->_btnLn->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(31)), static_cast<System::Int32>(static_cast<System::Byte>(31)),
				static_cast<System::Int32>(static_cast<System::Byte>(31)));
			this->_btnLn->FlatAppearance->BorderSize = 0;
			this->_btnLn->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Black;
			this->_btnLn->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(51)),
				static_cast<System::Int32>(static_cast<System::Byte>(51)), static_cast<System::Int32>(static_cast<System::Byte>(51)));
			this->_btnLn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->_btnLn->Font = (gcnew System::Drawing::Font(L"Consolas", 11));
			this->_btnLn->Location = System::Drawing::Point(57, 291);
			this->_btnLn->Name = L"_btnLn";
			this->_btnLn->Size = System::Drawing::Size(48, 45);
			this->_btnLn->TabIndex = 0;
			this->_btnLn->TabStop = false;
			this->_btnLn->Text = L"ln";
			this->_btnLn->UseVisualStyleBackColor = false;
			this->_btnLn->Click += gcnew System::EventHandler(this, &FrmCalculator::_btnLn_Click);
			// 
			// _btnLogYX
			// 
			this->_btnLogYX->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->_btnLogYX->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(31)), static_cast<System::Int32>(static_cast<System::Byte>(31)),
				static_cast<System::Int32>(static_cast<System::Byte>(31)));
			this->_btnLogYX->FlatAppearance->BorderSize = 0;
			this->_btnLogYX->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Black;
			this->_btnLogYX->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(51)),
				static_cast<System::Int32>(static_cast<System::Byte>(51)), static_cast<System::Int32>(static_cast<System::Byte>(51)));
			this->_btnLogYX->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->_btnLogYX->Font = (gcnew System::Drawing::Font(L"Consolas", 11));
			this->_btnLogYX->Location = System::Drawing::Point(3, 243);
			this->_btnLogYX->Name = L"_btnLogYX";
			this->_btnLogYX->Size = System::Drawing::Size(48, 42);
			this->_btnLogYX->TabIndex = 0;
			this->_btnLogYX->TabStop = false;
			this->_btnLogYX->Text = L"logᵧx";
			this->_btnLogYX->UseVisualStyleBackColor = false;
			this->_btnLogYX->Click += gcnew System::EventHandler(this, &FrmCalculator::_btnLogYX_Click);
			// 
			// _btnYRoot
			// 
			this->_btnYRoot->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->_btnYRoot->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(31)), static_cast<System::Int32>(static_cast<System::Byte>(31)),
				static_cast<System::Int32>(static_cast<System::Byte>(31)));
			this->_btnYRoot->FlatAppearance->BorderSize = 0;
			this->_btnYRoot->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Black;
			this->_btnYRoot->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(51)),
				static_cast<System::Int32>(static_cast<System::Byte>(51)), static_cast<System::Int32>(static_cast<System::Byte>(51)));
			this->_btnYRoot->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->_btnYRoot->Font = (gcnew System::Drawing::Font(L"Consolas", 11));
			this->_btnYRoot->Location = System::Drawing::Point(3, 147);
			this->_btnYRoot->Name = L"_btnYRoot";
			this->_btnYRoot->Size = System::Drawing::Size(48, 42);
			this->_btnYRoot->TabIndex = 0;
			this->_btnYRoot->TabStop = false;
			this->_btnYRoot->Text = L"ʸ√x";
			this->_btnYRoot->UseVisualStyleBackColor = false;
			this->_btnYRoot->Click += gcnew System::EventHandler(this, &FrmCalculator::_btnYRoot_Click);
			// 
			// tableLayoutPanel2
			// 
			this->tableLayoutPanel2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->tableLayoutPanel2->ColumnCount = 2;
			this->tableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle()));
			this->tableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				50)));
			this->tableLayoutPanel2->Controls->Add(this->_lblCurrentNum, 0, 3);
			this->tableLayoutPanel2->Controls->Add(this->_lblCurrentExpr, 0, 2);
			this->tableLayoutPanel2->Controls->Add(this->_btnModeStandard, 0, 0);
			this->tableLayoutPanel2->Controls->Add(this->_btnModeScientific, 1, 0);
			this->tableLayoutPanel2->Location = System::Drawing::Point(3, 3);
			this->tableLayoutPanel2->Margin = System::Windows::Forms::Padding(0);
			this->tableLayoutPanel2->Name = L"tableLayoutPanel2";
			this->tableLayoutPanel2->RowCount = 5;
			this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 32)));
			this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle()));
			this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle()));
			this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableLayoutPanel2->Size = System::Drawing::Size(678, 123);
			this->tableLayoutPanel2->TabIndex = 1;
			// 
			// _lblCurrentNum
			// 
			this->_lblCurrentNum->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->_lblCurrentNum->AutoSize = true;
			this->tableLayoutPanel2->SetColumnSpan(this->_lblCurrentNum, 2);
			this->_lblCurrentNum->Font = (gcnew System::Drawing::Font(L"Consolas", 22, System::Drawing::FontStyle::Bold));
			this->_lblCurrentNum->Location = System::Drawing::Point(644, 69);
			this->_lblCurrentNum->Name = L"_lblCurrentNum";
			this->_lblCurrentNum->Size = System::Drawing::Size(31, 36);
			this->_lblCurrentNum->TabIndex = 1;
			this->_lblCurrentNum->Text = L"0";
			// 
			// _lblCurrentExpr
			// 
			this->_lblCurrentExpr->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->_lblCurrentExpr->AutoSize = true;
			this->tableLayoutPanel2->SetColumnSpan(this->_lblCurrentExpr, 2);
			this->_lblCurrentExpr->Font = (gcnew System::Drawing::Font(L"Consolas", 12));
			this->_lblCurrentExpr->Location = System::Drawing::Point(675, 50);
			this->_lblCurrentExpr->Name = L"_lblCurrentExpr";
			this->_lblCurrentExpr->Size = System::Drawing::Size(0, 19);
			this->_lblCurrentExpr->TabIndex = 1;
			// 
			// _btnModeStandard
			// 
			this->_btnModeStandard->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->_btnModeStandard->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(16)), static_cast<System::Int32>(static_cast<System::Byte>(16)),
				static_cast<System::Int32>(static_cast<System::Byte>(16)));
			this->_btnModeStandard->FlatAppearance->BorderSize = 0;
			this->_btnModeStandard->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Black;
			this->_btnModeStandard->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(51)),
				static_cast<System::Int32>(static_cast<System::Byte>(51)), static_cast<System::Int32>(static_cast<System::Byte>(51)));
			this->_btnModeStandard->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->_btnModeStandard->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->_btnModeStandard->Location = System::Drawing::Point(3, 3);
			this->_btnModeStandard->Name = L"_btnModeStandard";
			this->_btnModeStandard->Size = System::Drawing::Size(102, 25);
			this->_btnModeStandard->TabIndex = 0;
			this->_btnModeStandard->TabStop = false;
			this->_btnModeStandard->Tag = L"alwaysactive";
			this->_btnModeStandard->Text = L"Standard";
			this->_btnModeStandard->UseVisualStyleBackColor = false;
			this->_btnModeStandard->Click += gcnew System::EventHandler(this, &FrmCalculator::_btnModeStandard_Click);
			// 
			// _btnModeScientific
			// 
			this->_btnModeScientific->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->_btnModeScientific->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(69)),
				static_cast<System::Int32>(static_cast<System::Byte>(98)), static_cast<System::Int32>(static_cast<System::Byte>(128)));
			this->_btnModeScientific->FlatAppearance->BorderSize = 0;
			this->_btnModeScientific->FlatAppearance->MouseDownBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(24)),
				static_cast<System::Int32>(static_cast<System::Byte>(35)), static_cast<System::Int32>(static_cast<System::Byte>(46)));
			this->_btnModeScientific->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(91)),
				static_cast<System::Int32>(static_cast<System::Byte>(134)), static_cast<System::Int32>(static_cast<System::Byte>(179)));
			this->_btnModeScientific->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->_btnModeScientific->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->_btnModeScientific->Location = System::Drawing::Point(111, 3);
			this->_btnModeScientific->Name = L"_btnModeScientific";
			this->_btnModeScientific->Size = System::Drawing::Size(102, 25);
			this->_btnModeScientific->TabIndex = 0;
			this->_btnModeScientific->TabStop = false;
			this->_btnModeScientific->Tag = L"alwaysactive";
			this->_btnModeScientific->Text = L"Scientific";
			this->_btnModeScientific->UseVisualStyleBackColor = false;
			this->_btnModeScientific->Click += gcnew System::EventHandler(this, &FrmCalculator::_btnModeScientific_Click);
			// 
			// _tlpSciMemory
			// 
			this->_tlpSciMemory->ColumnCount = 6;
			this->_tlpSciMemory->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				16.66667F)));
			this->_tlpSciMemory->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				16.66667F)));
			this->_tlpSciMemory->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				16.66667F)));
			this->_tlpSciMemory->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				16.66667F)));
			this->_tlpSciMemory->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				16.66667F)));
			this->_tlpSciMemory->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				16.66667F)));
			this->_tlpSciMemory->Controls->Add(this->_btnMemDropdown, 5, 1);
			this->_tlpSciMemory->Controls->Add(this->_btnMemStore, 4, 1);
			this->_tlpSciMemory->Controls->Add(this->_btnMemMinus, 3, 1);
			this->_tlpSciMemory->Controls->Add(this->_btnMemPlus, 2, 1);
			this->_tlpSciMemory->Controls->Add(this->_btnMemRecall, 1, 1);
			this->_tlpSciMemory->Controls->Add(this->_btnMemClear, 0, 1);
			this->_tlpSciMemory->Controls->Add(this->_btnToggleFE, 0, 0);
			this->_tlpSciMemory->Location = System::Drawing::Point(3, 129);
			this->_tlpSciMemory->Name = L"_tlpSciMemory";
			this->_tlpSciMemory->RowCount = 2;
			this->_tlpSciMemory->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->_tlpSciMemory->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->_tlpSciMemory->Size = System::Drawing::Size(328, 64);
			this->_tlpSciMemory->TabIndex = 2;
			// 
			// _btnMemDropdown
			// 
			this->_btnMemDropdown->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->_btnMemDropdown->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(16)), static_cast<System::Int32>(static_cast<System::Byte>(16)),
				static_cast<System::Int32>(static_cast<System::Byte>(16)));
			this->_btnMemDropdown->FlatAppearance->BorderSize = 0;
			this->_btnMemDropdown->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Black;
			this->_btnMemDropdown->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(51)),
				static_cast<System::Int32>(static_cast<System::Byte>(51)), static_cast<System::Int32>(static_cast<System::Byte>(51)));
			this->_btnMemDropdown->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->_btnMemDropdown->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->_btnMemDropdown->Location = System::Drawing::Point(273, 35);
			this->_btnMemDropdown->Name = L"_btnMemDropdown";
			this->_btnMemDropdown->Size = System::Drawing::Size(52, 26);
			this->_btnMemDropdown->TabIndex = 0;
			this->_btnMemDropdown->TabStop = false;
			this->_btnMemDropdown->Text = L"M▾";
			this->_btnMemDropdown->UseVisualStyleBackColor = false;
			this->_btnMemDropdown->Click += gcnew System::EventHandler(this, &FrmCalculator::_btnMemDropdown_Click);
			// 
			// _btnMemStore
			// 
			this->_btnMemStore->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->_btnMemStore->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(16)), static_cast<System::Int32>(static_cast<System::Byte>(16)),
				static_cast<System::Int32>(static_cast<System::Byte>(16)));
			this->_btnMemStore->FlatAppearance->BorderSize = 0;
			this->_btnMemStore->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Black;
			this->_btnMemStore->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(51)),
				static_cast<System::Int32>(static_cast<System::Byte>(51)), static_cast<System::Int32>(static_cast<System::Byte>(51)));
			this->_btnMemStore->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->_btnMemStore->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->_btnMemStore->Location = System::Drawing::Point(219, 35);
			this->_btnMemStore->Name = L"_btnMemStore";
			this->_btnMemStore->Size = System::Drawing::Size(48, 26);
			this->_btnMemStore->TabIndex = 0;
			this->_btnMemStore->TabStop = false;
			this->_btnMemStore->Text = L"MS";
			this->_btnMemStore->UseVisualStyleBackColor = false;
			this->_btnMemStore->Click += gcnew System::EventHandler(this, &FrmCalculator::_btnMemStore_Click);
			// 
			// _btnMemMinus
			// 
			this->_btnMemMinus->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->_btnMemMinus->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(16)), static_cast<System::Int32>(static_cast<System::Byte>(16)),
				static_cast<System::Int32>(static_cast<System::Byte>(16)));
			this->_btnMemMinus->FlatAppearance->BorderSize = 0;
			this->_btnMemMinus->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Black;
			this->_btnMemMinus->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(51)),
				static_cast<System::Int32>(static_cast<System::Byte>(51)), static_cast<System::Int32>(static_cast<System::Byte>(51)));
			this->_btnMemMinus->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->_btnMemMinus->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->_btnMemMinus->Location = System::Drawing::Point(165, 35);
			this->_btnMemMinus->Name = L"_btnMemMinus";
			this->_btnMemMinus->Size = System::Drawing::Size(48, 26);
			this->_btnMemMinus->TabIndex = 0;
			this->_btnMemMinus->TabStop = false;
			this->_btnMemMinus->Text = L"M-";
			this->_btnMemMinus->UseVisualStyleBackColor = false;
			this->_btnMemMinus->Click += gcnew System::EventHandler(this, &FrmCalculator::_btnMemMinus_Click);
			// 
			// _btnMemPlus
			// 
			this->_btnMemPlus->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->_btnMemPlus->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(16)), static_cast<System::Int32>(static_cast<System::Byte>(16)),
				static_cast<System::Int32>(static_cast<System::Byte>(16)));
			this->_btnMemPlus->FlatAppearance->BorderSize = 0;
			this->_btnMemPlus->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Black;
			this->_btnMemPlus->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(51)),
				static_cast<System::Int32>(static_cast<System::Byte>(51)), static_cast<System::Int32>(static_cast<System::Byte>(51)));
			this->_btnMemPlus->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->_btnMemPlus->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->_btnMemPlus->Location = System::Drawing::Point(111, 35);
			this->_btnMemPlus->Name = L"_btnMemPlus";
			this->_btnMemPlus->Size = System::Drawing::Size(48, 26);
			this->_btnMemPlus->TabIndex = 0;
			this->_btnMemPlus->TabStop = false;
			this->_btnMemPlus->Text = L"M+";
			this->_btnMemPlus->UseVisualStyleBackColor = false;
			this->_btnMemPlus->Click += gcnew System::EventHandler(this, &FrmCalculator::_btnMemPlus_Click);
			// 
			// _btnMemRecall
			// 
			this->_btnMemRecall->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->_btnMemRecall->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(16)), static_cast<System::Int32>(static_cast<System::Byte>(16)),
				static_cast<System::Int32>(static_cast<System::Byte>(16)));
			this->_btnMemRecall->FlatAppearance->BorderSize = 0;
			this->_btnMemRecall->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Black;
			this->_btnMemRecall->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(51)),
				static_cast<System::Int32>(static_cast<System::Byte>(51)), static_cast<System::Int32>(static_cast<System::Byte>(51)));
			this->_btnMemRecall->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->_btnMemRecall->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->_btnMemRecall->Location = System::Drawing::Point(57, 35);
			this->_btnMemRecall->Name = L"_btnMemRecall";
			this->_btnMemRecall->Size = System::Drawing::Size(48, 26);
			this->_btnMemRecall->TabIndex = 0;
			this->_btnMemRecall->TabStop = false;
			this->_btnMemRecall->Text = L"MR";
			this->_btnMemRecall->UseVisualStyleBackColor = false;
			this->_btnMemRecall->Click += gcnew System::EventHandler(this, &FrmCalculator::_btnMemRecall_Click);
			// 
			// _btnMemClear
			// 
			this->_btnMemClear->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->_btnMemClear->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(16)), static_cast<System::Int32>(static_cast<System::Byte>(16)),
				static_cast<System::Int32>(static_cast<System::Byte>(16)));
			this->_btnMemClear->FlatAppearance->BorderSize = 0;
			this->_btnMemClear->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Black;
			this->_btnMemClear->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(51)),
				static_cast<System::Int32>(static_cast<System::Byte>(51)), static_cast<System::Int32>(static_cast<System::Byte>(51)));
			this->_btnMemClear->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->_btnMemClear->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->_btnMemClear->Location = System::Drawing::Point(3, 35);
			this->_btnMemClear->Name = L"_btnMemClear";
			this->_btnMemClear->Size = System::Drawing::Size(48, 26);
			this->_btnMemClear->TabIndex = 0;
			this->_btnMemClear->TabStop = false;
			this->_btnMemClear->Text = L"MC";
			this->_btnMemClear->UseVisualStyleBackColor = false;
			this->_btnMemClear->Click += gcnew System::EventHandler(this, &FrmCalculator::_btnMemClear_Click);
			// 
			// _btnToggleFE
			// 
			this->_btnToggleFE->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->_btnToggleFE->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(16)), static_cast<System::Int32>(static_cast<System::Byte>(16)),
				static_cast<System::Int32>(static_cast<System::Byte>(16)));
			this->_btnToggleFE->FlatAppearance->BorderSize = 0;
			this->_btnToggleFE->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Black;
			this->_btnToggleFE->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(51)),
				static_cast<System::Int32>(static_cast<System::Byte>(51)), static_cast<System::Int32>(static_cast<System::Byte>(51)));
			this->_btnToggleFE->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->_btnToggleFE->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->_btnToggleFE->Location = System::Drawing::Point(3, 3);
			this->_btnToggleFE->Name = L"_btnToggleFE";
			this->_btnToggleFE->Size = System::Drawing::Size(48, 26);
			this->_btnToggleFE->TabIndex = 0;
			this->_btnToggleFE->TabStop = false;
			this->_btnToggleFE->Text = L"F-E";
			this->_btnToggleFE->UseVisualStyleBackColor = false;
			this->_btnToggleFE->Click += gcnew System::EventHandler(this, &FrmCalculator::_btnToggleFE_Click);
			// 
			// _tlpStanButtons
			// 
			this->_tlpStanButtons->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Right));
			this->_tlpStanButtons->ColumnCount = 4;
			this->_tlpStanButtons->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				16.66667F)));
			this->_tlpStanButtons->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				16.66667F)));
			this->_tlpStanButtons->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				16.66667F)));
			this->_tlpStanButtons->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				16.66667F)));
			this->_tlpStanButtons->Controls->Add(this->_btnStan0, 1, 5);
			this->_tlpStanButtons->Controls->Add(this->_btnStan1, 0, 4);
			this->_tlpStanButtons->Controls->Add(this->_btnStan2, 1, 4);
			this->_tlpStanButtons->Controls->Add(this->_btnStan3, 2, 4);
			this->_tlpStanButtons->Controls->Add(this->_btnStan4, 0, 3);
			this->_tlpStanButtons->Controls->Add(this->_btnStan5, 1, 3);
			this->_tlpStanButtons->Controls->Add(this->_btnStan6, 2, 3);
			this->_tlpStanButtons->Controls->Add(this->_btnStan9, 2, 2);
			this->_tlpStanButtons->Controls->Add(this->_btnStan8, 1, 2);
			this->_tlpStanButtons->Controls->Add(this->_btnStan7, 0, 2);
			this->_tlpStanButtons->Controls->Add(this->_btnStanPoint, 2, 5);
			this->_tlpStanButtons->Controls->Add(this->_btnStanPlusMinus, 0, 5);
			this->_tlpStanButtons->Controls->Add(this->_btnStanMultiply, 3, 2);
			this->_tlpStanButtons->Controls->Add(this->_btnStanMinus, 3, 3);
			this->_tlpStanButtons->Controls->Add(this->_btnStanPlus, 3, 4);
			this->_tlpStanButtons->Controls->Add(this->_btnStanEquals, 3, 5);
			this->_tlpStanButtons->Controls->Add(this->_btnStanDivide, 3, 1);
			this->_tlpStanButtons->Controls->Add(this->_btnStanInvert, 0, 1);
			this->_tlpStanButtons->Controls->Add(this->_btnStanSqr, 1, 1);
			this->_tlpStanButtons->Controls->Add(this->_btnStanSqrt, 2, 1);
			this->_tlpStanButtons->Controls->Add(this->_btnStanBackspace, 3, 0);
			this->_tlpStanButtons->Controls->Add(this->_btnStanCE, 1, 0);
			this->_tlpStanButtons->Controls->Add(this->_btnStanC, 2, 0);
			this->_tlpStanButtons->Controls->Add(this->_btnStanPercent, 0, 0);
			this->_tlpStanButtons->Location = System::Drawing::Point(353, 167);
			this->_tlpStanButtons->Name = L"_tlpStanButtons";
			this->_tlpStanButtons->RowCount = 6;
			this->_tlpStanButtons->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 14.28571F)));
			this->_tlpStanButtons->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 14.28571F)));
			this->_tlpStanButtons->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 14.28571F)));
			this->_tlpStanButtons->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 14.28571F)));
			this->_tlpStanButtons->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 14.28571F)));
			this->_tlpStanButtons->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 14.28571F)));
			this->_tlpStanButtons->Size = System::Drawing::Size(328, 371);
			this->_tlpStanButtons->TabIndex = 0;
			this->_tlpStanButtons->Visible = false;
			// 
			// _btnStan0
			// 
			this->_btnStan0->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->_btnStan0->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(51)), static_cast<System::Int32>(static_cast<System::Byte>(51)),
				static_cast<System::Int32>(static_cast<System::Byte>(51)));
			this->_btnStan0->FlatAppearance->BorderSize = 0;
			this->_btnStan0->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Black;
			this->_btnStan0->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(94)),
				static_cast<System::Int32>(static_cast<System::Byte>(94)), static_cast<System::Int32>(static_cast<System::Byte>(94)));
			this->_btnStan0->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->_btnStan0->Font = (gcnew System::Drawing::Font(L"Consolas", 11));
			this->_btnStan0->Location = System::Drawing::Point(85, 308);
			this->_btnStan0->Name = L"_btnStan0";
			this->_btnStan0->Size = System::Drawing::Size(76, 60);
			this->_btnStan0->TabIndex = 0;
			this->_btnStan0->TabStop = false;
			this->_btnStan0->Tag = L"alwaysactive";
			this->_btnStan0->Text = L"0";
			this->_btnStan0->UseVisualStyleBackColor = false;
			this->_btnStan0->Click += gcnew System::EventHandler(this, &FrmCalculator::_btnNumber_Click);
			// 
			// _btnStan1
			// 
			this->_btnStan1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->_btnStan1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(51)), static_cast<System::Int32>(static_cast<System::Byte>(51)),
				static_cast<System::Int32>(static_cast<System::Byte>(51)));
			this->_btnStan1->FlatAppearance->BorderSize = 0;
			this->_btnStan1->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Black;
			this->_btnStan1->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(94)),
				static_cast<System::Int32>(static_cast<System::Byte>(94)), static_cast<System::Int32>(static_cast<System::Byte>(94)));
			this->_btnStan1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->_btnStan1->Font = (gcnew System::Drawing::Font(L"Consolas", 11));
			this->_btnStan1->Location = System::Drawing::Point(3, 247);
			this->_btnStan1->Name = L"_btnStan1";
			this->_btnStan1->Size = System::Drawing::Size(76, 55);
			this->_btnStan1->TabIndex = 0;
			this->_btnStan1->TabStop = false;
			this->_btnStan1->Tag = L"alwaysactive";
			this->_btnStan1->Text = L"1";
			this->_btnStan1->UseVisualStyleBackColor = false;
			this->_btnStan1->Click += gcnew System::EventHandler(this, &FrmCalculator::_btnNumber_Click);
			// 
			// _btnStan2
			// 
			this->_btnStan2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->_btnStan2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(51)), static_cast<System::Int32>(static_cast<System::Byte>(51)),
				static_cast<System::Int32>(static_cast<System::Byte>(51)));
			this->_btnStan2->FlatAppearance->BorderSize = 0;
			this->_btnStan2->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Black;
			this->_btnStan2->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(94)),
				static_cast<System::Int32>(static_cast<System::Byte>(94)), static_cast<System::Int32>(static_cast<System::Byte>(94)));
			this->_btnStan2->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->_btnStan2->Font = (gcnew System::Drawing::Font(L"Consolas", 11));
			this->_btnStan2->Location = System::Drawing::Point(85, 247);
			this->_btnStan2->Name = L"_btnStan2";
			this->_btnStan2->Size = System::Drawing::Size(76, 55);
			this->_btnStan2->TabIndex = 0;
			this->_btnStan2->TabStop = false;
			this->_btnStan2->Tag = L"alwaysactive";
			this->_btnStan2->Text = L"2";
			this->_btnStan2->UseVisualStyleBackColor = false;
			this->_btnStan2->Click += gcnew System::EventHandler(this, &FrmCalculator::_btnNumber_Click);
			// 
			// _btnStan3
			// 
			this->_btnStan3->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->_btnStan3->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(51)), static_cast<System::Int32>(static_cast<System::Byte>(51)),
				static_cast<System::Int32>(static_cast<System::Byte>(51)));
			this->_btnStan3->FlatAppearance->BorderSize = 0;
			this->_btnStan3->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Black;
			this->_btnStan3->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(94)),
				static_cast<System::Int32>(static_cast<System::Byte>(94)), static_cast<System::Int32>(static_cast<System::Byte>(94)));
			this->_btnStan3->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->_btnStan3->Font = (gcnew System::Drawing::Font(L"Consolas", 11));
			this->_btnStan3->Location = System::Drawing::Point(167, 247);
			this->_btnStan3->Name = L"_btnStan3";
			this->_btnStan3->Size = System::Drawing::Size(76, 55);
			this->_btnStan3->TabIndex = 0;
			this->_btnStan3->TabStop = false;
			this->_btnStan3->Tag = L"alwaysactive";
			this->_btnStan3->Text = L"3";
			this->_btnStan3->UseVisualStyleBackColor = false;
			this->_btnStan3->Click += gcnew System::EventHandler(this, &FrmCalculator::_btnNumber_Click);
			// 
			// _btnStan4
			// 
			this->_btnStan4->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->_btnStan4->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(51)), static_cast<System::Int32>(static_cast<System::Byte>(51)),
				static_cast<System::Int32>(static_cast<System::Byte>(51)));
			this->_btnStan4->FlatAppearance->BorderSize = 0;
			this->_btnStan4->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Black;
			this->_btnStan4->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(94)),
				static_cast<System::Int32>(static_cast<System::Byte>(94)), static_cast<System::Int32>(static_cast<System::Byte>(94)));
			this->_btnStan4->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->_btnStan4->Font = (gcnew System::Drawing::Font(L"Consolas", 11));
			this->_btnStan4->Location = System::Drawing::Point(3, 186);
			this->_btnStan4->Name = L"_btnStan4";
			this->_btnStan4->Size = System::Drawing::Size(76, 55);
			this->_btnStan4->TabIndex = 0;
			this->_btnStan4->TabStop = false;
			this->_btnStan4->Tag = L"alwaysactive";
			this->_btnStan4->Text = L"4";
			this->_btnStan4->UseVisualStyleBackColor = false;
			this->_btnStan4->Click += gcnew System::EventHandler(this, &FrmCalculator::_btnNumber_Click);
			// 
			// _btnStan5
			// 
			this->_btnStan5->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->_btnStan5->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(51)), static_cast<System::Int32>(static_cast<System::Byte>(51)),
				static_cast<System::Int32>(static_cast<System::Byte>(51)));
			this->_btnStan5->FlatAppearance->BorderSize = 0;
			this->_btnStan5->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Black;
			this->_btnStan5->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(94)),
				static_cast<System::Int32>(static_cast<System::Byte>(94)), static_cast<System::Int32>(static_cast<System::Byte>(94)));
			this->_btnStan5->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->_btnStan5->Font = (gcnew System::Drawing::Font(L"Consolas", 11));
			this->_btnStan5->Location = System::Drawing::Point(85, 186);
			this->_btnStan5->Name = L"_btnStan5";
			this->_btnStan5->Size = System::Drawing::Size(76, 55);
			this->_btnStan5->TabIndex = 0;
			this->_btnStan5->TabStop = false;
			this->_btnStan5->Tag = L"alwaysactive";
			this->_btnStan5->Text = L"5";
			this->_btnStan5->UseVisualStyleBackColor = false;
			this->_btnStan5->Click += gcnew System::EventHandler(this, &FrmCalculator::_btnNumber_Click);
			// 
			// _btnStan6
			// 
			this->_btnStan6->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->_btnStan6->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(51)), static_cast<System::Int32>(static_cast<System::Byte>(51)),
				static_cast<System::Int32>(static_cast<System::Byte>(51)));
			this->_btnStan6->FlatAppearance->BorderSize = 0;
			this->_btnStan6->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Black;
			this->_btnStan6->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(94)),
				static_cast<System::Int32>(static_cast<System::Byte>(94)), static_cast<System::Int32>(static_cast<System::Byte>(94)));
			this->_btnStan6->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->_btnStan6->Font = (gcnew System::Drawing::Font(L"Consolas", 11));
			this->_btnStan6->Location = System::Drawing::Point(167, 186);
			this->_btnStan6->Name = L"_btnStan6";
			this->_btnStan6->Size = System::Drawing::Size(76, 55);
			this->_btnStan6->TabIndex = 0;
			this->_btnStan6->TabStop = false;
			this->_btnStan6->Tag = L"alwaysactive";
			this->_btnStan6->Text = L"6";
			this->_btnStan6->UseVisualStyleBackColor = false;
			this->_btnStan6->Click += gcnew System::EventHandler(this, &FrmCalculator::_btnNumber_Click);
			// 
			// _btnStan9
			// 
			this->_btnStan9->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->_btnStan9->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(51)), static_cast<System::Int32>(static_cast<System::Byte>(51)),
				static_cast<System::Int32>(static_cast<System::Byte>(51)));
			this->_btnStan9->FlatAppearance->BorderSize = 0;
			this->_btnStan9->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Black;
			this->_btnStan9->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(94)),
				static_cast<System::Int32>(static_cast<System::Byte>(94)), static_cast<System::Int32>(static_cast<System::Byte>(94)));
			this->_btnStan9->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->_btnStan9->Font = (gcnew System::Drawing::Font(L"Consolas", 11));
			this->_btnStan9->Location = System::Drawing::Point(167, 125);
			this->_btnStan9->Name = L"_btnStan9";
			this->_btnStan9->Size = System::Drawing::Size(76, 55);
			this->_btnStan9->TabIndex = 0;
			this->_btnStan9->TabStop = false;
			this->_btnStan9->Tag = L"alwaysactive";
			this->_btnStan9->Text = L"9";
			this->_btnStan9->UseVisualStyleBackColor = false;
			this->_btnStan9->Click += gcnew System::EventHandler(this, &FrmCalculator::_btnNumber_Click);
			// 
			// _btnStan8
			// 
			this->_btnStan8->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->_btnStan8->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(51)), static_cast<System::Int32>(static_cast<System::Byte>(51)),
				static_cast<System::Int32>(static_cast<System::Byte>(51)));
			this->_btnStan8->FlatAppearance->BorderSize = 0;
			this->_btnStan8->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Black;
			this->_btnStan8->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(94)),
				static_cast<System::Int32>(static_cast<System::Byte>(94)), static_cast<System::Int32>(static_cast<System::Byte>(94)));
			this->_btnStan8->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->_btnStan8->Font = (gcnew System::Drawing::Font(L"Consolas", 11));
			this->_btnStan8->Location = System::Drawing::Point(85, 125);
			this->_btnStan8->Name = L"_btnStan8";
			this->_btnStan8->Size = System::Drawing::Size(76, 55);
			this->_btnStan8->TabIndex = 0;
			this->_btnStan8->TabStop = false;
			this->_btnStan8->Tag = L"alwaysactive";
			this->_btnStan8->Text = L"8";
			this->_btnStan8->UseVisualStyleBackColor = false;
			this->_btnStan8->Click += gcnew System::EventHandler(this, &FrmCalculator::_btnNumber_Click);
			// 
			// _btnStan7
			// 
			this->_btnStan7->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->_btnStan7->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(51)), static_cast<System::Int32>(static_cast<System::Byte>(51)),
				static_cast<System::Int32>(static_cast<System::Byte>(51)));
			this->_btnStan7->FlatAppearance->BorderSize = 0;
			this->_btnStan7->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Black;
			this->_btnStan7->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(94)),
				static_cast<System::Int32>(static_cast<System::Byte>(94)), static_cast<System::Int32>(static_cast<System::Byte>(94)));
			this->_btnStan7->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->_btnStan7->Font = (gcnew System::Drawing::Font(L"Consolas", 11));
			this->_btnStan7->Location = System::Drawing::Point(3, 125);
			this->_btnStan7->Name = L"_btnStan7";
			this->_btnStan7->Size = System::Drawing::Size(76, 55);
			this->_btnStan7->TabIndex = 0;
			this->_btnStan7->TabStop = false;
			this->_btnStan7->Tag = L"alwaysactive";
			this->_btnStan7->Text = L"7";
			this->_btnStan7->UseVisualStyleBackColor = false;
			this->_btnStan7->Click += gcnew System::EventHandler(this, &FrmCalculator::_btnNumber_Click);
			// 
			// _btnStanPoint
			// 
			this->_btnStanPoint->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->_btnStanPoint->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(51)), static_cast<System::Int32>(static_cast<System::Byte>(51)),
				static_cast<System::Int32>(static_cast<System::Byte>(51)));
			this->_btnStanPoint->FlatAppearance->BorderSize = 0;
			this->_btnStanPoint->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Black;
			this->_btnStanPoint->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(94)),
				static_cast<System::Int32>(static_cast<System::Byte>(94)), static_cast<System::Int32>(static_cast<System::Byte>(94)));
			this->_btnStanPoint->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->_btnStanPoint->Font = (gcnew System::Drawing::Font(L"Consolas", 11));
			this->_btnStanPoint->Location = System::Drawing::Point(167, 308);
			this->_btnStanPoint->Name = L"_btnStanPoint";
			this->_btnStanPoint->Size = System::Drawing::Size(76, 60);
			this->_btnStanPoint->TabIndex = 0;
			this->_btnStanPoint->TabStop = false;
			this->_btnStanPoint->Text = L".";
			this->_btnStanPoint->UseVisualStyleBackColor = false;
			this->_btnStanPoint->Click += gcnew System::EventHandler(this, &FrmCalculator::_btnPoint_Click);
			// 
			// _btnStanPlusMinus
			// 
			this->_btnStanPlusMinus->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->_btnStanPlusMinus->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(51)),
				static_cast<System::Int32>(static_cast<System::Byte>(51)), static_cast<System::Int32>(static_cast<System::Byte>(51)));
			this->_btnStanPlusMinus->FlatAppearance->BorderSize = 0;
			this->_btnStanPlusMinus->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Black;
			this->_btnStanPlusMinus->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(94)),
				static_cast<System::Int32>(static_cast<System::Byte>(94)), static_cast<System::Int32>(static_cast<System::Byte>(94)));
			this->_btnStanPlusMinus->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->_btnStanPlusMinus->Font = (gcnew System::Drawing::Font(L"Consolas", 11));
			this->_btnStanPlusMinus->Location = System::Drawing::Point(3, 308);
			this->_btnStanPlusMinus->Name = L"_btnStanPlusMinus";
			this->_btnStanPlusMinus->Size = System::Drawing::Size(76, 60);
			this->_btnStanPlusMinus->TabIndex = 0;
			this->_btnStanPlusMinus->TabStop = false;
			this->_btnStanPlusMinus->Text = L"±";
			this->_btnStanPlusMinus->UseVisualStyleBackColor = false;
			this->_btnStanPlusMinus->Click += gcnew System::EventHandler(this, &FrmCalculator::_btnPlusMinus_Click);
			// 
			// _btnStanMultiply
			// 
			this->_btnStanMultiply->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->_btnStanMultiply->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(31)), static_cast<System::Int32>(static_cast<System::Byte>(31)),
				static_cast<System::Int32>(static_cast<System::Byte>(31)));
			this->_btnStanMultiply->FlatAppearance->BorderSize = 0;
			this->_btnStanMultiply->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Black;
			this->_btnStanMultiply->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(51)),
				static_cast<System::Int32>(static_cast<System::Byte>(51)), static_cast<System::Int32>(static_cast<System::Byte>(51)));
			this->_btnStanMultiply->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->_btnStanMultiply->Font = (gcnew System::Drawing::Font(L"Consolas", 14));
			this->_btnStanMultiply->Location = System::Drawing::Point(249, 125);
			this->_btnStanMultiply->Name = L"_btnStanMultiply";
			this->_btnStanMultiply->Size = System::Drawing::Size(76, 55);
			this->_btnStanMultiply->TabIndex = 0;
			this->_btnStanMultiply->TabStop = false;
			this->_btnStanMultiply->Text = L"×";
			this->_btnStanMultiply->UseVisualStyleBackColor = false;
			this->_btnStanMultiply->Click += gcnew System::EventHandler(this, &FrmCalculator::_btnMultiply_Click);
			// 
			// _btnStanMinus
			// 
			this->_btnStanMinus->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->_btnStanMinus->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(31)), static_cast<System::Int32>(static_cast<System::Byte>(31)),
				static_cast<System::Int32>(static_cast<System::Byte>(31)));
			this->_btnStanMinus->FlatAppearance->BorderSize = 0;
			this->_btnStanMinus->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Black;
			this->_btnStanMinus->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(51)),
				static_cast<System::Int32>(static_cast<System::Byte>(51)), static_cast<System::Int32>(static_cast<System::Byte>(51)));
			this->_btnStanMinus->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->_btnStanMinus->Font = (gcnew System::Drawing::Font(L"Consolas", 14));
			this->_btnStanMinus->Location = System::Drawing::Point(249, 186);
			this->_btnStanMinus->Name = L"_btnStanMinus";
			this->_btnStanMinus->Size = System::Drawing::Size(76, 55);
			this->_btnStanMinus->TabIndex = 0;
			this->_btnStanMinus->TabStop = false;
			this->_btnStanMinus->Text = L"−";
			this->_btnStanMinus->UseVisualStyleBackColor = false;
			this->_btnStanMinus->Click += gcnew System::EventHandler(this, &FrmCalculator::_btnMinus_Click);
			// 
			// _btnStanPlus
			// 
			this->_btnStanPlus->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->_btnStanPlus->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(31)), static_cast<System::Int32>(static_cast<System::Byte>(31)),
				static_cast<System::Int32>(static_cast<System::Byte>(31)));
			this->_btnStanPlus->FlatAppearance->BorderSize = 0;
			this->_btnStanPlus->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Black;
			this->_btnStanPlus->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(51)),
				static_cast<System::Int32>(static_cast<System::Byte>(51)), static_cast<System::Int32>(static_cast<System::Byte>(51)));
			this->_btnStanPlus->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->_btnStanPlus->Font = (gcnew System::Drawing::Font(L"Consolas", 14));
			this->_btnStanPlus->Location = System::Drawing::Point(249, 247);
			this->_btnStanPlus->Name = L"_btnStanPlus";
			this->_btnStanPlus->Size = System::Drawing::Size(76, 55);
			this->_btnStanPlus->TabIndex = 0;
			this->_btnStanPlus->TabStop = false;
			this->_btnStanPlus->Text = L"+";
			this->_btnStanPlus->UseVisualStyleBackColor = false;
			this->_btnStanPlus->Click += gcnew System::EventHandler(this, &FrmCalculator::_btnPlus_Click);
			// 
			// _btnStanEquals
			// 
			this->_btnStanEquals->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->_btnStanEquals->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(69)), static_cast<System::Int32>(static_cast<System::Byte>(98)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)));
			this->_btnStanEquals->FlatAppearance->BorderSize = 0;
			this->_btnStanEquals->FlatAppearance->MouseDownBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(24)),
				static_cast<System::Int32>(static_cast<System::Byte>(35)), static_cast<System::Int32>(static_cast<System::Byte>(46)));
			this->_btnStanEquals->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(91)),
				static_cast<System::Int32>(static_cast<System::Byte>(134)), static_cast<System::Int32>(static_cast<System::Byte>(179)));
			this->_btnStanEquals->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->_btnStanEquals->Font = (gcnew System::Drawing::Font(L"Consolas", 14));
			this->_btnStanEquals->Location = System::Drawing::Point(249, 308);
			this->_btnStanEquals->Name = L"_btnStanEquals";
			this->_btnStanEquals->Size = System::Drawing::Size(76, 60);
			this->_btnStanEquals->TabIndex = 0;
			this->_btnStanEquals->TabStop = false;
			this->_btnStanEquals->Tag = L"alwaysactive";
			this->_btnStanEquals->Text = L"=";
			this->_btnStanEquals->UseVisualStyleBackColor = false;
			this->_btnStanEquals->Click += gcnew System::EventHandler(this, &FrmCalculator::_btnEquals_Click);
			// 
			// _btnStanDivide
			// 
			this->_btnStanDivide->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->_btnStanDivide->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(31)), static_cast<System::Int32>(static_cast<System::Byte>(31)),
				static_cast<System::Int32>(static_cast<System::Byte>(31)));
			this->_btnStanDivide->FlatAppearance->BorderSize = 0;
			this->_btnStanDivide->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Black;
			this->_btnStanDivide->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(51)),
				static_cast<System::Int32>(static_cast<System::Byte>(51)), static_cast<System::Int32>(static_cast<System::Byte>(51)));
			this->_btnStanDivide->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->_btnStanDivide->Font = (gcnew System::Drawing::Font(L"Consolas", 14));
			this->_btnStanDivide->Location = System::Drawing::Point(249, 64);
			this->_btnStanDivide->Name = L"_btnStanDivide";
			this->_btnStanDivide->Size = System::Drawing::Size(76, 55);
			this->_btnStanDivide->TabIndex = 0;
			this->_btnStanDivide->TabStop = false;
			this->_btnStanDivide->Text = L"÷";
			this->_btnStanDivide->UseVisualStyleBackColor = false;
			this->_btnStanDivide->Click += gcnew System::EventHandler(this, &FrmCalculator::_btnDivide_Click);
			// 
			// _btnStanInvert
			// 
			this->_btnStanInvert->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->_btnStanInvert->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(31)), static_cast<System::Int32>(static_cast<System::Byte>(31)),
				static_cast<System::Int32>(static_cast<System::Byte>(31)));
			this->_btnStanInvert->FlatAppearance->BorderSize = 0;
			this->_btnStanInvert->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Black;
			this->_btnStanInvert->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(51)),
				static_cast<System::Int32>(static_cast<System::Byte>(51)), static_cast<System::Int32>(static_cast<System::Byte>(51)));
			this->_btnStanInvert->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->_btnStanInvert->Font = (gcnew System::Drawing::Font(L"Consolas", 11));
			this->_btnStanInvert->Location = System::Drawing::Point(3, 64);
			this->_btnStanInvert->Name = L"_btnStanInvert";
			this->_btnStanInvert->Size = System::Drawing::Size(76, 55);
			this->_btnStanInvert->TabIndex = 0;
			this->_btnStanInvert->TabStop = false;
			this->_btnStanInvert->Text = L"1/x";
			this->_btnStanInvert->UseVisualStyleBackColor = false;
			this->_btnStanInvert->Click += gcnew System::EventHandler(this, &FrmCalculator::_btnInvert_Click);
			// 
			// _btnStanSqr
			// 
			this->_btnStanSqr->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->_btnStanSqr->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(31)), static_cast<System::Int32>(static_cast<System::Byte>(31)),
				static_cast<System::Int32>(static_cast<System::Byte>(31)));
			this->_btnStanSqr->FlatAppearance->BorderSize = 0;
			this->_btnStanSqr->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Black;
			this->_btnStanSqr->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(51)),
				static_cast<System::Int32>(static_cast<System::Byte>(51)), static_cast<System::Int32>(static_cast<System::Byte>(51)));
			this->_btnStanSqr->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->_btnStanSqr->Font = (gcnew System::Drawing::Font(L"Consolas", 11));
			this->_btnStanSqr->Location = System::Drawing::Point(85, 64);
			this->_btnStanSqr->Name = L"_btnStanSqr";
			this->_btnStanSqr->Size = System::Drawing::Size(76, 55);
			this->_btnStanSqr->TabIndex = 0;
			this->_btnStanSqr->TabStop = false;
			this->_btnStanSqr->Text = L"x²";
			this->_btnStanSqr->UseVisualStyleBackColor = false;
			this->_btnStanSqr->Click += gcnew System::EventHandler(this, &FrmCalculator::_btnSqr_Click);
			// 
			// _btnStanSqrt
			// 
			this->_btnStanSqrt->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->_btnStanSqrt->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(31)), static_cast<System::Int32>(static_cast<System::Byte>(31)),
				static_cast<System::Int32>(static_cast<System::Byte>(31)));
			this->_btnStanSqrt->FlatAppearance->BorderSize = 0;
			this->_btnStanSqrt->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Black;
			this->_btnStanSqrt->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(51)),
				static_cast<System::Int32>(static_cast<System::Byte>(51)), static_cast<System::Int32>(static_cast<System::Byte>(51)));
			this->_btnStanSqrt->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->_btnStanSqrt->Font = (gcnew System::Drawing::Font(L"Consolas", 11));
			this->_btnStanSqrt->Location = System::Drawing::Point(167, 64);
			this->_btnStanSqrt->Name = L"_btnStanSqrt";
			this->_btnStanSqrt->Size = System::Drawing::Size(76, 55);
			this->_btnStanSqrt->TabIndex = 0;
			this->_btnStanSqrt->TabStop = false;
			this->_btnStanSqrt->Text = L"√x";
			this->_btnStanSqrt->UseVisualStyleBackColor = false;
			this->_btnStanSqrt->Click += gcnew System::EventHandler(this, &FrmCalculator::_btnSqrt_Click);
			// 
			// _btnStanBackspace
			// 
			this->_btnStanBackspace->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->_btnStanBackspace->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(31)),
				static_cast<System::Int32>(static_cast<System::Byte>(31)), static_cast<System::Int32>(static_cast<System::Byte>(31)));
			this->_btnStanBackspace->FlatAppearance->BorderSize = 0;
			this->_btnStanBackspace->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Black;
			this->_btnStanBackspace->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(51)),
				static_cast<System::Int32>(static_cast<System::Byte>(51)), static_cast<System::Int32>(static_cast<System::Byte>(51)));
			this->_btnStanBackspace->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->_btnStanBackspace->Font = (gcnew System::Drawing::Font(L"Segoe UI", 11));
			this->_btnStanBackspace->Location = System::Drawing::Point(249, 3);
			this->_btnStanBackspace->Name = L"_btnStanBackspace";
			this->_btnStanBackspace->Size = System::Drawing::Size(76, 55);
			this->_btnStanBackspace->TabIndex = 0;
			this->_btnStanBackspace->TabStop = false;
			this->_btnStanBackspace->Tag = L"alwaysactive";
			this->_btnStanBackspace->Text = L"⌫";
			this->_btnStanBackspace->UseVisualStyleBackColor = false;
			this->_btnStanBackspace->Click += gcnew System::EventHandler(this, &FrmCalculator::_btnBackspace_Click);
			// 
			// _btnStanCE
			// 
			this->_btnStanCE->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->_btnStanCE->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(31)), static_cast<System::Int32>(static_cast<System::Byte>(31)),
				static_cast<System::Int32>(static_cast<System::Byte>(31)));
			this->_btnStanCE->FlatAppearance->BorderSize = 0;
			this->_btnStanCE->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Black;
			this->_btnStanCE->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(51)),
				static_cast<System::Int32>(static_cast<System::Byte>(51)), static_cast<System::Int32>(static_cast<System::Byte>(51)));
			this->_btnStanCE->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->_btnStanCE->Font = (gcnew System::Drawing::Font(L"Consolas", 11));
			this->_btnStanCE->Location = System::Drawing::Point(85, 3);
			this->_btnStanCE->Name = L"_btnStanCE";
			this->_btnStanCE->Size = System::Drawing::Size(76, 55);
			this->_btnStanCE->TabIndex = 0;
			this->_btnStanCE->TabStop = false;
			this->_btnStanCE->Tag = L"alwaysactive";
			this->_btnStanCE->Text = L"CE";
			this->_btnStanCE->UseVisualStyleBackColor = false;
			this->_btnStanCE->Click += gcnew System::EventHandler(this, &FrmCalculator::_btnStanCE_Click);
			// 
			// _btnStanC
			// 
			this->_btnStanC->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->_btnStanC->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(31)), static_cast<System::Int32>(static_cast<System::Byte>(31)),
				static_cast<System::Int32>(static_cast<System::Byte>(31)));
			this->_btnStanC->FlatAppearance->BorderSize = 0;
			this->_btnStanC->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Black;
			this->_btnStanC->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(51)),
				static_cast<System::Int32>(static_cast<System::Byte>(51)), static_cast<System::Int32>(static_cast<System::Byte>(51)));
			this->_btnStanC->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->_btnStanC->Font = (gcnew System::Drawing::Font(L"Consolas", 11));
			this->_btnStanC->Location = System::Drawing::Point(167, 3);
			this->_btnStanC->Name = L"_btnStanC";
			this->_btnStanC->Size = System::Drawing::Size(76, 55);
			this->_btnStanC->TabIndex = 0;
			this->_btnStanC->TabStop = false;
			this->_btnStanC->Tag = L"alwaysactive";
			this->_btnStanC->Text = L"C";
			this->_btnStanC->UseVisualStyleBackColor = false;
			this->_btnStanC->Click += gcnew System::EventHandler(this, &FrmCalculator::_btnStanC_Click);
			// 
			// _btnStanPercent
			// 
			this->_btnStanPercent->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->_btnStanPercent->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(31)), static_cast<System::Int32>(static_cast<System::Byte>(31)),
				static_cast<System::Int32>(static_cast<System::Byte>(31)));
			this->_btnStanPercent->FlatAppearance->BorderSize = 0;
			this->_btnStanPercent->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Black;
			this->_btnStanPercent->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(51)),
				static_cast<System::Int32>(static_cast<System::Byte>(51)), static_cast<System::Int32>(static_cast<System::Byte>(51)));
			this->_btnStanPercent->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->_btnStanPercent->Font = (gcnew System::Drawing::Font(L"Consolas", 11));
			this->_btnStanPercent->Location = System::Drawing::Point(3, 3);
			this->_btnStanPercent->Name = L"_btnStanPercent";
			this->_btnStanPercent->Size = System::Drawing::Size(76, 55);
			this->_btnStanPercent->TabIndex = 0;
			this->_btnStanPercent->TabStop = false;
			this->_btnStanPercent->Text = L"%";
			this->_btnStanPercent->UseVisualStyleBackColor = false;
			this->_btnStanPercent->Click += gcnew System::EventHandler(this, &FrmCalculator::_btnStanPercent_Click);
			// 
			// _tlpStanMemory
			// 
			this->_tlpStanMemory->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->_tlpStanMemory->ColumnCount = 6;
			this->_tlpStanMemory->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				16.66667F)));
			this->_tlpStanMemory->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				16.66667F)));
			this->_tlpStanMemory->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				16.66667F)));
			this->_tlpStanMemory->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				16.66667F)));
			this->_tlpStanMemory->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				16.66667F)));
			this->_tlpStanMemory->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				16.66667F)));
			this->_tlpStanMemory->Controls->Add(this->_btnStanMemDropdown, 5, 0);
			this->_tlpStanMemory->Controls->Add(this->_btnStanMemStore, 4, 0);
			this->_tlpStanMemory->Controls->Add(this->_btnStanMemMinus, 3, 0);
			this->_tlpStanMemory->Controls->Add(this->_btnStanMemPlus, 2, 0);
			this->_tlpStanMemory->Controls->Add(this->_btnStanMemRecall, 1, 0);
			this->_tlpStanMemory->Controls->Add(this->_btnStanMemClear, 0, 0);
			this->_tlpStanMemory->Location = System::Drawing::Point(353, 129);
			this->_tlpStanMemory->Name = L"_tlpStanMemory";
			this->_tlpStanMemory->RowCount = 1;
			this->_tlpStanMemory->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->_tlpStanMemory->Size = System::Drawing::Size(328, 32);
			this->_tlpStanMemory->TabIndex = 2;
			this->_tlpStanMemory->Visible = false;
			// 
			// _btnStanMemDropdown
			// 
			this->_btnStanMemDropdown->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->_btnStanMemDropdown->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(16)),
				static_cast<System::Int32>(static_cast<System::Byte>(16)), static_cast<System::Int32>(static_cast<System::Byte>(16)));
			this->_btnStanMemDropdown->FlatAppearance->BorderSize = 0;
			this->_btnStanMemDropdown->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Black;
			this->_btnStanMemDropdown->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(51)),
				static_cast<System::Int32>(static_cast<System::Byte>(51)), static_cast<System::Int32>(static_cast<System::Byte>(51)));
			this->_btnStanMemDropdown->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->_btnStanMemDropdown->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->_btnStanMemDropdown->Location = System::Drawing::Point(273, 3);
			this->_btnStanMemDropdown->Name = L"_btnStanMemDropdown";
			this->_btnStanMemDropdown->Size = System::Drawing::Size(52, 26);
			this->_btnStanMemDropdown->TabIndex = 0;
			this->_btnStanMemDropdown->TabStop = false;
			this->_btnStanMemDropdown->Text = L"M▾";
			this->_btnStanMemDropdown->UseVisualStyleBackColor = false;
			this->_btnStanMemDropdown->Click += gcnew System::EventHandler(this, &FrmCalculator::_btnMemDropdown_Click);
			// 
			// _btnStanMemStore
			// 
			this->_btnStanMemStore->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->_btnStanMemStore->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(16)), static_cast<System::Int32>(static_cast<System::Byte>(16)),
				static_cast<System::Int32>(static_cast<System::Byte>(16)));
			this->_btnStanMemStore->FlatAppearance->BorderSize = 0;
			this->_btnStanMemStore->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Black;
			this->_btnStanMemStore->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(51)),
				static_cast<System::Int32>(static_cast<System::Byte>(51)), static_cast<System::Int32>(static_cast<System::Byte>(51)));
			this->_btnStanMemStore->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->_btnStanMemStore->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->_btnStanMemStore->Location = System::Drawing::Point(219, 3);
			this->_btnStanMemStore->Name = L"_btnStanMemStore";
			this->_btnStanMemStore->Size = System::Drawing::Size(48, 26);
			this->_btnStanMemStore->TabIndex = 0;
			this->_btnStanMemStore->TabStop = false;
			this->_btnStanMemStore->Text = L"MS";
			this->_btnStanMemStore->UseVisualStyleBackColor = false;
			this->_btnStanMemStore->Click += gcnew System::EventHandler(this, &FrmCalculator::_btnMemStore_Click);
			// 
			// _btnStanMemMinus
			// 
			this->_btnStanMemMinus->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->_btnStanMemMinus->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(16)), static_cast<System::Int32>(static_cast<System::Byte>(16)),
				static_cast<System::Int32>(static_cast<System::Byte>(16)));
			this->_btnStanMemMinus->FlatAppearance->BorderSize = 0;
			this->_btnStanMemMinus->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Black;
			this->_btnStanMemMinus->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(51)),
				static_cast<System::Int32>(static_cast<System::Byte>(51)), static_cast<System::Int32>(static_cast<System::Byte>(51)));
			this->_btnStanMemMinus->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->_btnStanMemMinus->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->_btnStanMemMinus->Location = System::Drawing::Point(165, 3);
			this->_btnStanMemMinus->Name = L"_btnStanMemMinus";
			this->_btnStanMemMinus->Size = System::Drawing::Size(48, 26);
			this->_btnStanMemMinus->TabIndex = 0;
			this->_btnStanMemMinus->TabStop = false;
			this->_btnStanMemMinus->Text = L"M-";
			this->_btnStanMemMinus->UseVisualStyleBackColor = false;
			this->_btnStanMemMinus->Click += gcnew System::EventHandler(this, &FrmCalculator::_btnMemMinus_Click);
			// 
			// _btnStanMemPlus
			// 
			this->_btnStanMemPlus->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->_btnStanMemPlus->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(16)), static_cast<System::Int32>(static_cast<System::Byte>(16)),
				static_cast<System::Int32>(static_cast<System::Byte>(16)));
			this->_btnStanMemPlus->FlatAppearance->BorderSize = 0;
			this->_btnStanMemPlus->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Black;
			this->_btnStanMemPlus->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(51)),
				static_cast<System::Int32>(static_cast<System::Byte>(51)), static_cast<System::Int32>(static_cast<System::Byte>(51)));
			this->_btnStanMemPlus->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->_btnStanMemPlus->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->_btnStanMemPlus->Location = System::Drawing::Point(111, 3);
			this->_btnStanMemPlus->Name = L"_btnStanMemPlus";
			this->_btnStanMemPlus->Size = System::Drawing::Size(48, 26);
			this->_btnStanMemPlus->TabIndex = 0;
			this->_btnStanMemPlus->TabStop = false;
			this->_btnStanMemPlus->Text = L"M+";
			this->_btnStanMemPlus->UseVisualStyleBackColor = false;
			this->_btnStanMemPlus->Click += gcnew System::EventHandler(this, &FrmCalculator::_btnMemPlus_Click);
			// 
			// _btnStanMemRecall
			// 
			this->_btnStanMemRecall->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->_btnStanMemRecall->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(16)),
				static_cast<System::Int32>(static_cast<System::Byte>(16)), static_cast<System::Int32>(static_cast<System::Byte>(16)));
			this->_btnStanMemRecall->FlatAppearance->BorderSize = 0;
			this->_btnStanMemRecall->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Black;
			this->_btnStanMemRecall->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(51)),
				static_cast<System::Int32>(static_cast<System::Byte>(51)), static_cast<System::Int32>(static_cast<System::Byte>(51)));
			this->_btnStanMemRecall->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->_btnStanMemRecall->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->_btnStanMemRecall->Location = System::Drawing::Point(57, 3);
			this->_btnStanMemRecall->Name = L"_btnStanMemRecall";
			this->_btnStanMemRecall->Size = System::Drawing::Size(48, 26);
			this->_btnStanMemRecall->TabIndex = 0;
			this->_btnStanMemRecall->TabStop = false;
			this->_btnStanMemRecall->Text = L"MR";
			this->_btnStanMemRecall->UseVisualStyleBackColor = false;
			this->_btnStanMemRecall->Click += gcnew System::EventHandler(this, &FrmCalculator::_btnMemRecall_Click);
			// 
			// _btnStanMemClear
			// 
			this->_btnStanMemClear->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->_btnStanMemClear->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(16)), static_cast<System::Int32>(static_cast<System::Byte>(16)),
				static_cast<System::Int32>(static_cast<System::Byte>(16)));
			this->_btnStanMemClear->FlatAppearance->BorderSize = 0;
			this->_btnStanMemClear->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Black;
			this->_btnStanMemClear->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(51)),
				static_cast<System::Int32>(static_cast<System::Byte>(51)), static_cast<System::Int32>(static_cast<System::Byte>(51)));
			this->_btnStanMemClear->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->_btnStanMemClear->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->_btnStanMemClear->Location = System::Drawing::Point(3, 3);
			this->_btnStanMemClear->Name = L"_btnStanMemClear";
			this->_btnStanMemClear->Size = System::Drawing::Size(48, 26);
			this->_btnStanMemClear->TabIndex = 0;
			this->_btnStanMemClear->TabStop = false;
			this->_btnStanMemClear->Text = L"MC";
			this->_btnStanMemClear->UseVisualStyleBackColor = false;
			this->_btnStanMemClear->Click += gcnew System::EventHandler(this, &FrmCalculator::_btnMemClear_Click);
			// 
			// FrmCalculator
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(16)), static_cast<System::Int32>(static_cast<System::Byte>(16)),
				static_cast<System::Int32>(static_cast<System::Byte>(16)));
			this->ClientSize = System::Drawing::Size(684, 541);
			this->Controls->Add(this->_tlpStanMemory);
			this->Controls->Add(this->_tlpSciMemory);
			this->Controls->Add(this->_tlpStanButtons);
			this->Controls->Add(this->_tlpSciButtons);
			this->Controls->Add(this->tableLayoutPanel2);
			this->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(238)), static_cast<System::Int32>(static_cast<System::Byte>(238)),
				static_cast<System::Int32>(static_cast<System::Byte>(238)));
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->KeyPreview = true;
			this->MaximizeBox = false;
			this->Name = L"FrmCalculator";
			this->Padding = System::Windows::Forms::Padding(3);
			this->ShowIcon = false;
			this->Text = L"Calculator";
			this->_tlpSciButtons->ResumeLayout(false);
			this->tableLayoutPanel2->ResumeLayout(false);
			this->tableLayoutPanel2->PerformLayout();
			this->_tlpSciMemory->ResumeLayout(false);
			this->_tlpStanButtons->ResumeLayout(false);
			this->_tlpStanMemory->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion

	private:

		const int W = 350, H = 580;

		// global variables

		String^ _currentNum = L"0";
		String^ _currentExpr = L"";
		String^ _currentMem = L"";

		TokenTypes _lastToken = TokenTypes::Equals;

		// flags
		bool _hasE = false;					// set to true when the current num has an e (scientific notation)
		bool _FE = false;					// set to true when the user enabled forcing scientific notation
		bool _error = false;				// set to true when the last calc resulted in an error
		bool _scientificMode = true;		// set to true when the calculator is in scientific mode

#pragma region utils

		// misc utilities

		// get a double string but run through double parsing and back to string, trailing zeroes and scientific notation unless FE is enabled
		String^ GetProcessedDouble(String^ num)
		{
			if (_FE)
			{
				// force current num to be in scientific notation if FE is enabled and format it manually because the win10 calculator's formatting is weird
				String^ res = double::Parse(num).ToString(L"0.###########################e+0", System::Globalization::CultureInfo::InvariantCulture);

				int pos = 0;
				bool foundPoint = false;
				while (res[pos] != L'e' && pos < res->Length) // the second condition is just a backup, it should never trigger
				{
					if (res[pos] == L'.') return res; // cut the processing short if there already is a decimal point in there
					pos++;
				}

				return res->Substring(0, pos) + L"." + res->Substring(pos, res->Length - pos);
			}
			else
				// otherwise parse the number normally
				return double::Parse(num).ToString()->ToLower();
		}

		String^ GetCurrentNumProcessed()
		{
			return GetProcessedDouble(_currentNum);
		}

		int GetUnclosedParenthesisCount()
		{
			int ltParCnt;
			for (int i = 0; i < _currentExpr->Length; i++)
			{
				if (_currentExpr[i] == L'(')
					ltParCnt++;
				else if (_currentExpr[i] == L')')
					ltParCnt--;
			}

			return ltParCnt;
		}

		// returs true if the current expression ends with an operator
		bool GetExprEndsWithOperator()
		{
			// check every operator symbol
			for (int i = 0; i < IOperator::OperatorSymbols->Length; i++)
			{
				if (_currentExpr->EndsWith(IOperator::OperatorSymbols[i] + L" "))
					return true;
			}
		}

		// calculates the value of the last token, use this to set _currentNum after an operator is added
		// can throw a CalcException on div by 0 and other math heresies
		String^ CalcLastToken()
		{
			String^ token = L"";
			int pos = _currentExpr->Length - 1;
			int rtParCnt = 0;

			while (pos >= 0 && (_currentExpr[pos] != L' ' || rtParCnt > 0))
			{
				if (_currentExpr[pos] == L')')
					rtParCnt++;
				else if (_currentExpr[pos] == L'(')
					rtParCnt--;

				token = _currentExpr[pos] + token;

				pos--;
			}

			Expression^ expr;

			if (Expression::TryParse(token, expr))
			{
				// this might throw a CalcException, if it does, it's the parent job to catch it
				return GetProcessedDouble(expr->Calc().ToString());
			}
			else
				return _currentNum;
		}

		String^ FindLastTopLevelOp()
		{
			String^ token = L"";
			int pos = _currentExpr->Length - 1;
			int rtParCnt = 0;

			while (pos >= 0)
			{
				if (_currentExpr[pos] == L')')
					rtParCnt++;
				else if (_currentExpr[pos] == L'(')
					rtParCnt--;

				if (_currentExpr[pos] == L' ' && rtParCnt == 0)
					if (Array::IndexOf(IOperator::OperatorSymbols, token) >= 0)
						return token;
					else
						token = L"";
				else
					token = _currentExpr[pos] + token;


				pos--;
			}

			return L"";
		}

		void EraseLastToken()
		{
			int pos = _currentExpr->Length - 1;
			int rtParCnt = 0;

			while (pos >= 0 && (_currentExpr[pos] != L' ' || rtParCnt > 0))
			{
				if (_currentExpr[pos] == L')')
					rtParCnt++;
				else if (_currentExpr[pos] == L'(')
					rtParCnt--;

				pos--;
			}

			// don't erase if there is only one token, another quirk
			if (pos > 0)
			{
				_currentExpr = _currentExpr->Substring(0, pos + 1);
				UpdateCurrentExprLabel();
			}
		}


		// UI related

		void SetScientificMode(bool mode)
		{
			// do nothing if the mode is not being switched
			if (_scientificMode == mode) return;

			// set the flag
			_scientificMode = mode;

			// suspend layout to make the transition as smooth as possible
			SuspendLayout();

			// show and hide proper panels
			_tlpSciButtons->Visible = mode;
			_tlpSciMemory->Visible = mode;
			_tlpStanButtons->Visible = !mode;
			_tlpStanMemory->Visible = !mode;

			// activate/deactivate proper top buttons
			SetButtonActive(_btnModeScientific, mode);
			SetButtonActive(_btnModeStandard, !mode);

			// do a full clear to make it seem like we're actually switching modes and not just changing the ui layout a bit
			Clear();
			MemClear();

			ResumeLayout();
		}

		// refresh UI for current num
		void UpdateCurrentNumLabel()
		{
			// current num string should have a decimal separator every 3 digits

			String^ textToShow = _currentNum;

			// try to start at point
			int pos = textToShow->IndexOf(L".") - 3;

			// if point was not found (indexof returned -1), try to start 3 characters from the end instead
			if (pos == -4) pos = textToShow->Length - 3;

			// insert decimal separators backwards every 3 digits from pos to start
			while (pos > 0)
			{
				textToShow = textToShow->Insert(pos, L",");
				pos -= 3;
			}

			_lblCurrentNum->Text = textToShow;

			_btnCE->Text = _currentNum == L"0" ? L"C" : L"CE";
		}

		// refresh UI for current expr
		void UpdateCurrentExprLabel()
		{
			_lblCurrentExpr->Text = _currentExpr;
		}

		// refresh UI for current mem
		void UpdateCurrentMemUI()
		{
			// scientific mode buttons
			SetButtonEnabled(_btnMemRecall, _currentMem != L"");
			SetButtonEnabled(_btnMemClear, _currentMem != L"");
			SetButtonEnabled(_btnMemDropdown, _currentMem != L"");

			// standard mode buttons
			SetButtonEnabled(_btnStanMemRecall, _currentMem != L"");
			SetButtonEnabled(_btnStanMemClear, _currentMem != L"");
			SetButtonEnabled(_btnStanMemDropdown, _currentMem != L"");
		}

		// switch to 2nd button pane
		void SwitchTo2nd()
		{
			_tlpSciButtons->SuspendLayout();

			_tlpSciButtons->ColumnStyles[0]->Width = 16.67;
			_tlpSciButtons->ColumnStyles[1]->Width = 0;

			for each (Control ^ control in _tlpSciButtons->Controls)
			{
				if (_tlpSciButtons->GetColumn(control) == 0)
					control->Show();
				else if (_tlpSciButtons->GetColumn(control) == 1)
					control->Hide();
			}

			_tlpSciButtons->ResumeLayout();
		}

		// return to the 1st pane
		void SwitchTo1st()
		{
			_tlpSciButtons->SuspendLayout();

			_tlpSciButtons->ColumnStyles[0]->Width = 0;
			_tlpSciButtons->ColumnStyles[1]->Width = 16.67;

			for each (Control ^ control in _tlpSciButtons->Controls)
			{
				if (_tlpSciButtons->GetColumn(control) == 0)
					control->Hide();
				else if (_tlpSciButtons->GetColumn(control) == 1)
					control->Show();
			}

			_tlpSciButtons->ResumeLayout();
		}

		// custom function to disable buttons and keep the text colour, but the keep text colour part doesn't work
		void SetButtonEnabled(Button^ btn, bool enabled)
		{
			btn->Enabled = enabled;
			btn->ForeColor = enabled ? Color::White : Color::Red;
		}

		// custom function to simplify setting buttons to be coloured or back to normal, intended to be used with the mode buttons
		void SetButtonActive(Button^ btn, bool active)
		{
			btn->BackColor = active ? Color::FromArgb(69, 98, 128) : Color::FromArgb(16, 16, 16);
			btn->FlatAppearance->MouseOverBackColor = active ? Color::FromArgb(91, 134, 179) : Color::FromArgb(51, 51, 51);
			btn->FlatAppearance->MouseDownBackColor = active ? Color::FromArgb(24, 35, 46) : Color::FromArgb(0, 0, 0);
		}

		void DisplayError(String^ message)
		{
			// bypass the label update function as that would add commas every 3 letters
			_lblCurrentNum->Text = message;
			_error = true; // set the error flag

			SuspendLayout(); // pause UI updates
			ActiveControl = _lblCurrentExpr; // set the active control to the label so there's no red focus outline
			SetChildButtonsEnabled(this, !_error); // enable or disable all controls
			ResumeLayout(); // resume UI updates
		}

		void SetChildButtonsEnabled(Control^ container, bool enabled)
		{
			for each (Control ^ control in container->Controls)
			{
				// try to cast the control handle to a button handle
				Button^ btn = dynamic_cast<Button^>(control);

				if (btn != nullptr)
					// if cast succeeded, set button enabled
					SetButtonEnabled(btn, enabled || btn->Tag == L"alwaysactive");
				else
					// otherwise disable all child buttons
					SetChildButtonsEnabled(control, enabled);
			}
		}

#pragma endregion

#pragma region commands

		// appending

		void AppendDigit(String^ d)
		{
			// number inputs after an equals or error should clear
			if (_lastToken == TokenTypes::Equals || _error) Clear(false);

			// if the last token ends a parenthesis, erase it - another interesting quirk
			else if (_lastToken == TokenTypes::Function || _lastToken == TokenTypes::RightParenthesis) EraseLastToken();

			// do this even if the above conditions triggered
			if (_lastToken != TokenTypes::Number) _currentNum = L"0";

			// when the current num has an e, only one digit after it and that digit is 0, remove that digit so the added number replaces it
			if (_hasE && (_currentNum->EndsWith(L"e+0") || _currentNum->EndsWith(L"e-0")))
				_currentNum = _currentNum->Substring(0, _currentNum->Length - 1);

			// if the number is 0, remove it so the added number replaces it
			if (_currentNum == L"0" || _currentNum == L"-0") _currentNum = _currentNum->Substring(0, _currentNum->Length - 1);

			// append the clicked button's text to the number
			_currentNum += d;

			_lastToken = TokenTypes::Number;

			// refresh UI
			UpdateCurrentNumLabel();
		}

		void AppendPoint()
		{
			// number inputs after an equals or error should clear
			if (_lastToken == TokenTypes::Equals || _error) Clear();

			// if the last token ends a parenthesis, erase it - another interesting quirk
			else if (_lastToken == TokenTypes::Function || _lastToken == TokenTypes::RightParenthesis) EraseLastToken();

			// do this even if the above conditions triggered
			if (_lastToken != TokenTypes::Number) _currentNum = L"0";

			// do nothing if the number already contains a decimal point
			if (_currentNum->Contains(".")) return;

			// append a decimal point
			_currentNum += L'.';

			_lastToken = TokenTypes::Number;

			UpdateCurrentNumLabel();
		}

		void AppendOperator(String^ op)
		{
			// do nothing if there was an error
			if (_error) return;

			// if the last input was an operator, replace that operator with the current one
			if (_lastToken == TokenTypes::Operator)
			{
				int pos = _currentExpr->Length - 2;
				// find space before last operator
				while (_currentExpr[pos] != L' ') pos--;
				_currentExpr = _currentExpr->Substring(0, pos + 1) + op + L" ";
			}

			else
			{
				// if the last input was equals, set the expression to the current number
				if (_lastToken == TokenTypes::Equals)
					_currentExpr = GetCurrentNumProcessed();

				// if the last input was a closing parenthesis (normal or of a function), don't append the current number
				else if (_lastToken != TokenTypes::RightParenthesis && _lastToken != TokenTypes::Function)
					_currentExpr += GetCurrentNumProcessed();

				// always append the operator
				_currentExpr += L" " + op + L" ";
			}

			_currentNum = GetCurrentNumProcessed();

			_lastToken = TokenTypes::Operator;

			UpdateCurrentExprLabel();
			UpdateCurrentNumLabel();
		}

		void AppendLeftParenthesis()
		{
			// do nothing if there was an error
			if (_error) return;

			// clear after an equals
			if (_lastToken == TokenTypes::Equals) Clear();

			// if the last token ends a parenthesis, erase it - another interesting quirk
			else if (_lastToken == TokenTypes::Function || _lastToken == TokenTypes::RightParenthesis) EraseLastToken();

			_currentExpr += L"(";
			_lastToken = TokenTypes::LeftParenthesis;
			UpdateCurrentExprLabel();
		}

		void AppendRightParenthesis()
		{
			// do nothing if there was an error
			if (_error) return;

			// don't append if there are no unclosed parentheses
			if (GetUnclosedParenthesisCount() == 0) return;

			// only append the current number if the last input was not an ending parenthesis
			if (_lastToken != TokenTypes::RightParenthesis && _lastToken != TokenTypes::Function)
				_currentExpr += _currentNum;

			_currentExpr += L")";

			// set the current num to the result of this parenthesis
			try
			{
				_currentNum = CalcLastToken();
			}
			catch (CalcException^ ex)
			{
				// div by 0 or some other mathematical heresy
				DisplayError(ex->DisplayMessage);
				return;
			}

			_lastToken = TokenTypes::RightParenthesis;

			UpdateCurrentExprLabel();
			UpdateCurrentNumLabel();
		}

		void AppendFunction(String^ func)
		{
			// do nothing if there was an error
			if (_error) return;

			// if the previous operation calculated a result, execute the function on that result
			if (_lastToken == TokenTypes::Equals)
				_currentExpr = func + L"(" + GetCurrentNumProcessed() + L")";

			// if the last character is a closing parenthesis, append the function before the opening parenthesis or function name
			else if (_currentExpr->Length > 2 && _currentExpr->EndsWith(L")"))
			{
				// go left to find the starting parenthesis
				int pos = _currentExpr->Length - 1;
				int rtParCnt = 0;

				while (pos >= 0 && !(_currentExpr[pos] == L' ' && rtParCnt == 0))
				{
					if (_currentExpr[pos] == L')') rtParCnt++;
					if (_currentExpr[pos] == L'(') rtParCnt--;

					pos--;
				}

				// current expression ends in a parenthesis, append function name in front of it
				if (_currentExpr[pos + 1] == L'(' || (pos == 0 && _currentExpr[pos] == L'('))
					_currentExpr = _currentExpr->Insert(pos + (pos == 0 ? 0 : 1), func);

				// current expression ends in a function, wrap it in another function
				else
					_currentExpr = _currentExpr->Insert(pos + (pos == 0 ? 0 : 1), func + L"(") + ")";
			}

			// otherwise append the function at the end with the current number as argument
			else
			{
				_currentExpr += func + L"(" + GetCurrentNumProcessed() + L")";
			}

			// update expr label before calculating and checking for errors
			UpdateCurrentExprLabel();

			// set the current num to the result of this function
			try
			{
				_currentNum = CalcLastToken();
			}
			catch (CalcException^ ex)
			{
				// div by 0 or some other mathematical heresy
				DisplayError(ex->DisplayMessage);
				return;
			}

			_lastToken = TokenTypes::Function;

			UpdateCurrentNumLabel();
		}

		void AppendE()
		{
			// do nothing if there was an error
			if (_error) return;

			// don't append if there already is an e
			if (_hasE) return;

			// ensure the number has a decimal point, the windows calculator does this so I will too
			AppendPoint();

			_currentNum += "e+0";
			_hasE = true;

			UpdateCurrentNumLabel();
		}


		// setting

		void SetCurrentNumToE()
		{
			// do nothing if there was an error
			if (_error) return;

			_currentNum = Math::E.ToString();

			_lastToken = TokenTypes::Number;

			UpdateCurrentNumLabel();
		}

		void SetCurrentNumToPi()
		{
			// do nothing if there was an error
			if (_error) return;

			_currentNum = Math::PI.ToString();
			_lastToken = TokenTypes::Number;
			UpdateCurrentNumLabel();
		}


		// erasing

		void Backspace()
		{
			// do a full clear if there was an error
			if (_error)
			{
				Clear();
				return;
			}

			// after clicking an operator backspace does nothing
			if (_lastToken == TokenTypes::Operator) return;

			// after clicking equals backspace should clear the expression but not the current number
			else if (_lastToken == TokenTypes::Equals)
			{
				_currentExpr = L"";
				UpdateCurrentExprLabel();
				return;
			}

			// handle situations when the current number has an e
			if (_hasE)
			{
				// check if the number after the e only has one digit
				if (_currentNum[_currentNum->Length - 2] == L'-' || _currentNum[_currentNum->Length - 2] == L'+')
				{
					// check if that one digit is a 0
					if (_currentNum->EndsWith(L"0"))
					{
						// remove the whole e part of the current number
						_currentNum = _currentNum->Substring(0, _currentNum->Length - 3);
						_hasE = false; // mark that e has been removed
					}

					// some other digit
					else
					{
						// set the number after e to 0 and the symbol to a plus
						_currentNum = _currentNum->Substring(0, _currentNum->Length - 2) + L"+0";
					}
				}

				// otherwise delete the last character from the string
				else
				{
					_currentNum = _currentNum->Substring(0, _currentNum->Length - 1);
				}
			}

			// handle normal number
			else
			{
				// if the current number only has one digit with or without a minus, set the current number to 0
				if (_currentNum[0] == '-' && _currentNum->Length <= 2 || _currentNum->Length <= 1) _currentNum = "0";

				// otherwise delete the last character from the string
				else _currentNum = _currentNum->Substring(0, _currentNum->Length - 1);
			}

			UpdateCurrentNumLabel();
		}

		void ClearEntry()
		{
			// the last input was an equals or there was an error, do a full clear
			if (_lastToken == TokenTypes::Equals || _error)
			{
				Clear();
			}
			else
			{
				// clear entry (current number)
				_currentNum = "0";
				UpdateCurrentNumLabel();
			}
		}

		void Clear()
		{
			// by default, clear and disable FE
			Clear(true);
		}

		void Clear(bool disableFE)
		{
			// clear error if present
			if (_error)
			{
				_error = false;
				SuspendLayout(); // pause UI updates

				ActiveControl = _lblCurrentExpr; // set the active control to the label so there's no red focus outline
				SetChildButtonsEnabled(this, true); // reenable all UI buttons
				UpdateCurrentMemUI(); // reenable proper parts of the memory UI

				ResumeLayout(); // resume UI updates
			}

			// reset stuffs
			_currentExpr = L"";
			_currentNum = L"0";
			_lastToken = TokenTypes::Equals;
			_hasE = false;

			if (_FE && disableFE) ToggleFE(); // disable FE if it's enabled

			UpdateCurrentExprLabel();
			UpdateCurrentNumLabel();
		}

		void CEButton()
		{
			if (_currentNum == L"0" || _lastToken == TokenTypes::Equals || _error) Clear();
			else ClearEntry();
		}


		// memory

		void MemStore()
		{
			// do nothing if there was an error
			if (_error) return;

			_currentMem = _currentNum;
			UpdateCurrentMemUI();
		}

		void MemAdd()
		{
			// do nothing if there was an error
			if (_error) return;

			// if current memory is empty, set it to the current number
			if (_currentMem == L"")
				_currentMem = _currentNum;

			else
				_currentMem = (Double::Parse(_currentMem) + Double::Parse(_currentNum)).ToString()->ToLower();

			UpdateCurrentMemUI();
		}

		void MemSubstract()
		{
			// do nothing if there was an error
			if (_error) return;

			if (_currentMem == L"")
				if (_currentNum->StartsWith(L"-"))
					_currentMem = _currentNum->Substring(1, _currentNum->Length - 1);
				else
					_currentMem = L"-" + _currentNum;
			else
				_currentMem = (Double::Parse(_currentMem) - Double::Parse(_currentNum)).ToString()->ToLower();

			UpdateCurrentMemUI();
		}

		void MemRecall()
		{
			// do nothing if there was an error
			if (_error) return;

			// don't do anything if the current memory is empty
			if (_currentMem == L"") return;

			_currentNum = _currentMem;
			UpdateCurrentNumLabel();
		}

		void MemClear()
		{
			// do nothing if there was an error
			if (_error) return;

			_currentMem = L"";
			UpdateCurrentMemUI();
		}

		void MemDisplay()
		{
			// do nothing if there was an error
			if (_error) return;

			MessageBox::Show(_currentMem == L"" ? L"Nothing in memory." : _currentMem, L"Memory");
		}

		// misc

		void ToggleFE()
		{
			// do nothing if there was an error
			if (_error) return;

			_FE = !_FE;

			// give the current number a new format
			_currentNum = GetCurrentNumProcessed();
			UpdateCurrentNumLabel();

			// update the hasE flag
			_hasE = _FE;

			SetButtonActive(_btnToggleFE, _FE);
		}

		void PercentButton()
		{
			// do nothing if there was an error
			if (_error) return;

			if (GetExprEndsWithOperator())
			{
				String^ op = FindLastTopLevelOp();
				double currNum = Double::Parse(_currentNum);

				if (op == L"/" || op == L"*")
				{
					// the current expression ends in multiplication or division, append the current number but divided by 100
					_currentExpr += (currNum / 100).ToString();
				}
				else if (op == L"+" || op == L"-")
				{
					// if the current expression ends in addition or substraction, evaluate the current expression, then multiply it times 100 +/- currentNum / 100
					Expression^ expr;
					if (Expression::TryParse(_currentExpr->Substring(0, _currentExpr->Length - 3), expr))
					{
						// set the current num to the result of this parenthesis
						try
						{
							double val = expr->Calc();
							_currentExpr += (val * currNum / 100).ToString();
							_currentNum = (val * currNum / 100).ToString();
						}
						catch (CalcException^ ex)
						{
							// div by 0 or some other mathematical heresy
							DisplayError(ex->DisplayMessage);
							return;
						}

					}
				}

				_lastToken = TokenTypes::Function;

				UpdateCurrentNumLabel();
				UpdateCurrentExprLabel();
			}

			// if the current expression ends in anything else, set the current expression and num to 0 because that's how the win10 calculator does it
		}

		void Negate()
		{
			// do nothing if there was an error
			if (_error) return;

			// if the last input was a closing parenthesis or a function, negate the whole parenthesis/function
			if (_lastToken == TokenTypes::RightParenthesis || _lastToken == TokenTypes::Function || _lastToken == TokenTypes::Equals)
			{
				// only set the expression to the current number after an equals
				if (_lastToken == TokenTypes::Equals)
					_currentExpr = GetCurrentNumProcessed();

				AppendFunction(L"-");
				return;
			}

			// do nothing if the number is 0
			if (_currentNum == L"0") return;

			// if the first character is a minus, remove it
			if (_currentNum[0] == L'-') _currentNum = _currentNum->Substring(1, _currentNum->Length - 1);

			// otherwise, add a minus to the start of the number
			else _currentNum = L'-' + _currentNum;

			UpdateCurrentNumLabel();
		}

		void Calc()
		{
			// clear if there was an error
			if (_error) { Clear(); return; }

			// if the last input was an operator or the current expression ends with an operator, append the current number after that operator
			if (_lastToken == TokenTypes::Operator || GetExprEndsWithOperator())
				_currentExpr += GetCurrentNumProcessed();

			// if the current expression is empty or ends with a parenthesis and the last input was a number, set the expression to the current number
			else if (_currentExpr == L"" || (_currentExpr->EndsWith(L")") && _lastToken == TokenTypes::Number))
				_currentExpr = GetCurrentNumProcessed();


			int unclosedCount = GetUnclosedParenthesisCount();

			// close missing parentheses
			for (int i = 0; i < unclosedCount; i++)
				_currentExpr += L")";

			// handle consecutive equals presses
			if (_lastToken == TokenTypes::Equals)
			{
				String^ lastTopLevelOp = FindLastTopLevelOp();
				if (lastTopLevelOp == L"") // if there was no operator just repeat the current number forever
					_currentExpr = GetCurrentNumProcessed();
				else
				{
					String^ lastTokenVal;
					// set the current num to the result of this parenthesis
					try
					{
						lastTokenVal = CalcLastToken();
					}
					catch (CalcException^ ex)
					{
						// div by 0 or some other mathematical heresy
						DisplayError(ex->DisplayMessage);
						return;
					}

					_currentExpr = GetCurrentNumProcessed() + L" " + lastTopLevelOp + L" " + lastTokenVal;
				}
			}

			UpdateCurrentExprLabel();

			Expression^ expr;
			if (Expression::TryParse(_currentExpr, expr))
			{
				try
				{
					_currentNum = GetProcessedDouble(expr->Calc().ToString());
					_lblCurrentExpr->Text += L" = ";

					_lastToken = TokenTypes::Equals;

					UpdateCurrentNumLabel();
				}
				catch (CalcException^ ex)
				{
					DisplayError(ex->DisplayMessage);
				}
				catch (Exception^ ex)
				{
					DisplayError(L"Unknown error");
				}

			}
			else
			{
				// display a message if parsing fails, this shouldn't be possible but oh well
				MessageBox::Show(L"Parsing failed - congrats, you found a programming mistake.");
			}
		}


#pragma endregion

#pragma region event handlers

	protected:

		// handle all key presses on the form
		virtual bool ProcessCmdKey(Message% msg, Keys k) override
		{

			// list of all win10 calculator shortcuts:
			// https://support.microsoft.com/en-us/help/13805/windows-keyboard-shortcuts-in-apps

			// here so breakpoints during debug time don't trigger on just shift being pressed, should be commented out later
			//if (k == (Keys::ShiftKey | Keys::Shift)) return true;
			if (false) {} // this line does nothing on it's own but it makes the other else ifs line up nicer and makes it easier to comment/uncomment the line above

			// special keys

			else if (k == Keys::Back)
				Backspace();

			else if (k == Keys::Delete)
				ClearEntry(); // delete always clears entry instead of pressing the scientific CE button in scientific mode, just another quirk of the win10 calculator

			else if (k == Keys::Escape)
				Clear();

			else if (k == Keys::Enter || k == Keys::Return)
				Calc();


			// operator keys

			else if (k == Keys::Multiply || (k == (Keys::D8 | Keys::Shift)))
				AppendOperator(L"*");

			else if (k == Keys::Oemplus || k == Keys::Add || k == (Keys::Oemplus | Keys::Shift))
				AppendOperator(L"+");

			else if (k == Keys::OemMinus || k == Keys::Subtract)
				AppendOperator(L"-");

			else if (k == Keys::Oem2 || k == Keys::Divide) // Oem2 is the main keyboard slash key. go figure.
				AppendOperator(L"/");

			else if ((k == Keys::OemPipe | k == (Keys::OemBackslash | Keys::Shift) | k == (Keys::Oem5 | Keys::Shift)) && _scientificMode) // only available in scientific mode
				AppendFunction(L"abs");


			// letter keys + modifiers

			else if (k == (Keys::E | Keys::Shift) && _scientificMode) // only available in scientific mode
				SetCurrentNumToE();

			else if (k == (Keys::G | Keys::Control) && _scientificMode) // only available in scientific mode
				AppendFunction(L"10^");

			else if (k == (Keys::L | Keys::Control))
				MemClear();

			else if (k == (Keys::M | Keys::Control))
				MemStore();

			else if (k == (Keys::N | Keys::Control))
				AppendFunction(L"e^");

			else if (k == (Keys::P | Keys::Control))
				MemAdd();

			else if (k == (Keys::Q | Keys::Control))
				MemSubstract();

			else if (k == (Keys::R | Keys::Control))
				MemRecall();

			else if (k == (Keys::Y | Keys::Control) && _scientificMode) // only available in scientific mode
				AppendFunction(L"yroot");


			// letter keys

			else if (k == Keys::E && _scientificMode) // only available in scientific mode
				AppendE();

			else if (k == Keys::L && _scientificMode) // only available in scientific mode
				AppendFunction(L"log");

			else if (k == Keys::N && _scientificMode) // only available in scientific mode
				AppendFunction(L"ln");

			else if (k == Keys::P && _scientificMode) // only available in scientific mode
				SetCurrentNumToPi();

			else if (k == Keys::Q)
				AppendFunction(L"sqr");

			else if (k == Keys::R)
				AppendFunction(L"1/");

			else if (k == Keys::V && _scientificMode) // only available in scientific mode
				ToggleFE();

			else if (k == Keys::Y && _scientificMode) // only available in scientific mode
				AppendOperator(L"^");


			// function keys

			else if (k == Keys::F9)
				Negate();


			// number keys + shift

			else if (k == (Keys::D1 | Keys::Shift) && _scientificMode) // !, scientific mode only
				AppendFunction(L"fact");

			else if (k == (Keys::D2 | Keys::Shift)) // @ (shift + 2)
				AppendFunction(L"sqrt");

			else if (k == (Keys::D3 | Keys::Shift) && _scientificMode) // #, scientific mode only
				AppendFunction(L"cube");

			else if (k == (Keys::D5 | Keys::Shift) && _scientificMode) // % in scientific mode
				AppendOperator(L"mod");

			else if (k == (Keys::D5 | Keys::Shift) && !_scientificMode) // % in standard mode, the && is unnecessary but left for clarity
				PercentButton();

			else if (k == (Keys::D6 | Keys::Shift) && _scientificMode) // ^, scientific mode only
				AppendOperator(L"^");

			else if (k == (Keys::D9 | Keys::Shift) && _scientificMode) // (, scientific mode only
				AppendLeftParenthesis();

			else if (k == (Keys::D0 | Keys::Shift) && _scientificMode) // ), scientific mode only
				AppendRightParenthesis();


			// other keys

			// number keys
			else if (k >= Keys::D0 && k <= Keys::D9)
				AppendDigit(((int)(k - Keys::D0)).ToString());

			// numpad number keys
			else if (k >= Keys::NumPad0 && k <= Keys::NumPad9)
				AppendDigit(((int)(k - Keys::NumPad0)).ToString());

			// decimal point keys
			else if (k == Keys::OemPeriod || k == Keys::Oemcomma || k == Keys::Decimal)
				AppendPoint();

			else if (k == (Keys::Alt | Keys::D1))
				SetScientificMode(false);

			else if (k == (Keys::Alt | Keys::D2))
				SetScientificMode(true);

			// no conditions hit, mark this event as unhandled
			else
				return false;

			// a condition was hit, mark this event as handled
			return true;
		}

	private:

		// handle mode switching 

		System::Void _btnModeScientific_Click(System::Object^ sender, System::EventArgs^ e)
		{
			SetScientificMode(true);
		}

		System::Void _btnModeStandard_Click(System::Object^ sender, System::EventArgs^ e)
		{
			SetScientificMode(false);
		}


		// handle the equals button
		System::Void _btnEquals_Click(System::Object^ sender, System::EventArgs^ e)
		{
			Calc();
		}


		// handle basic input and erasing

		System::Void _btnNumber_Click(System::Object^ sender, System::EventArgs^ e)
		{
			// get the clicked button
			Button^ b = safe_cast<Button^>(sender);
			AppendDigit(b->Text);
		}

		System::Void _btnPlusMinus_Click(System::Object^ sender, System::EventArgs^ e)
		{
			Negate();
		}

		System::Void _btnBackspace_Click(System::Object^ sender, System::EventArgs^ e)
		{
			Backspace();
		}

		System::Void _btnPoint_Click(System::Object^ sender, System::EventArgs^ e)
		{
			AppendPoint();
		}

		System::Void _btnCE_Click(System::Object^ sender, System::EventArgs^ e)
		{
			CEButton();
		}

		System::Void _btnModulo_Click(System::Object^ sender, System::EventArgs^ e)
		{
			AppendOperator("mod");
		}


		// handle standard mode erasing

		System::Void _btnStanC_Click(System::Object^ sender, System::EventArgs^ e)
		{
			Clear();
		}

		System::Void _btnStanCE_Click(System::Object^ sender, System::EventArgs^ e)
		{
			ClearEntry();
		}


		// handle basic operators

		System::Void _btnPlus_Click(System::Object^ sender, System::EventArgs^ e)
		{
			AppendOperator(L"+");
		}

		System::Void _btnMinus_Click(System::Object^ sender, System::EventArgs^ e)
		{
			AppendOperator(L"-");
		}

		System::Void _btnMultiply_Click(System::Object^ sender, System::EventArgs^ e)
		{
			AppendOperator(L"*");
		}

		System::Void _btnDivide_Click(System::Object^ sender, System::EventArgs^ e)
		{
			AppendOperator(L"/");
		}


		// handle parentheses

		System::Void _btnLeftParenthesis_Click(System::Object^ sender, System::EventArgs^ e)
		{
			AppendLeftParenthesis();
		}

		System::Void _btnRightParenthesis_Click(System::Object^ sender, System::EventArgs^ e)
		{
			AppendRightParenthesis();
		}


		// handle other functions

		System::Void _btnStanPercent_Click(System::Object^ sender, System::EventArgs^ e)
		{
			PercentButton();
		}

		System::Void _btnInvert_Click(System::Object^ sender, System::EventArgs^ e)
		{
			AppendFunction("1/");
		}

		System::Void _btnFactorial_Click(System::Object^ sender, System::EventArgs^ e)
		{
			AppendFunction(L"fact");
		}

		System::Void _btnExp_Click(System::Object^ sender, System::EventArgs^ e)
		{
			AppendE();
		}

		System::Void _btnAbs_Click(System::Object^ sender, System::EventArgs^ e)
		{
			AppendFunction(L"abs");
		}

		System::Void _btnE_Click(System::Object^ sender, System::EventArgs^ e)
		{
			SetCurrentNumToE();
		}

		System::Void _btnPi_Click(System::Object^ sender, System::EventArgs^ e)
		{
			SetCurrentNumToPi();
		}


		// handle switching panes in scientific mode

		System::Void _btn2ndOn_Click(System::Object^ sender, System::EventArgs^ e)
		{
			SwitchTo2nd();
		}

		System::Void _btn2ndOff_Click(System::Object^ sender, System::EventArgs^ e)
		{
			SwitchTo1st();
		}


		// handle 1st pane functions

		System::Void _btnSqr_Click(System::Object^ sender, System::EventArgs^ e)
		{
			AppendFunction(L"sqr");
		}

		System::Void _btnCube_Click(System::Object^ sender, System::EventArgs^ e)
		{
			AppendFunction(L"cube");
		}

		System::Void _btnPow_Click(System::Object^ sender, System::EventArgs^ e)
		{
			AppendOperator(L"^");
		}

		System::Void _btn10ToX_Click(System::Object^ sender, System::EventArgs^ e)
		{
			AppendFunction(L"10^");
		}

		System::Void _btnLog_Click(System::Object^ sender, System::EventArgs^ e)
		{
			AppendFunction(L"log");
		}

		System::Void _btnLn_Click(System::Object^ sender, System::EventArgs^ e)
		{
			AppendFunction(L"ln");
		}


		// handle 2nd pane functions

		System::Void _btnSqrt_Click(System::Object^ sender, System::EventArgs^ e)
		{
			AppendFunction(L"sqrt");
		}

		System::Void _btnCubeRoot_Click(System::Object^ sender, System::EventArgs^ e)
		{
			AppendFunction(L"cuberoot");
		}

		System::Void _btnYRoot_Click(System::Object^ sender, System::EventArgs^ e)
		{
			AppendOperator("yroot");
		}

		System::Void _btn2ToX_Click(System::Object^ sender, System::EventArgs^ e)
		{
			AppendFunction("2^");
		}

		System::Void _btnLogYX_Click(System::Object^ sender, System::EventArgs^ e)
		{
			AppendOperator(L"base_log");
		}

		System::Void _btnEToX_Click(System::Object^ sender, System::EventArgs^ e)
		{
			AppendFunction("e^");
		}


		// handle memory functions

		System::Void _btnMemDropdown_Click(System::Object^ sender, System::EventArgs^ e)
		{
			MemDisplay();
		}

		System::Void _btnMemRecall_Click(System::Object^ sender, System::EventArgs^ e)
		{
			MemRecall();
		}

		System::Void _btnMemPlus_Click(System::Object^ sender, System::EventArgs^ e)
		{
			MemAdd();
		}

		System::Void _btnMemMinus_Click(System::Object^ sender, System::EventArgs^ e)
		{
			MemSubstract();
		}

		System::Void _btnMemStore_Click(System::Object^ sender, System::EventArgs^ e)
		{
			MemStore();
		}

		System::Void _btnMemClear_Click(System::Object^ sender, System::EventArgs^ e)
		{
			MemClear();
		}

		System::Void _btnToggleFE_Click(System::Object^ sender, System::EventArgs^ e)
		{
			ToggleFE();
		}

#pragma endregion

	};
}
