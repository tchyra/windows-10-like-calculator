#pragma once

// standard libs
#include <iostream>
#include <stdlib.h>

// custom classes
#include "defs.h"
#include "ICalculable.h"
#include "Expression.h"

using namespace System;
using namespace System::Runtime::InteropServices;

// this file contains the main form for the scientific calculator variant

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
			SwitchTo1st();
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~FrmCalculator()
		{
			if (components) delete components;
		}

#pragma region control variables

	private: System::Windows::Forms::TableLayoutPanel^ _tlpButtons;

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
			this->_tlpButtons = (gcnew System::Windows::Forms::TableLayoutPanel());
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
			this->_tlpButtons->SuspendLayout();
			this->tableLayoutPanel2->SuspendLayout();
			this->SuspendLayout();
			// 
			// _tlpButtons
			// 
			this->_tlpButtons->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->_tlpButtons->ColumnCount = 6;
			this->_tlpButtons->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 16.66667F)));
			this->_tlpButtons->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 16.66667F)));
			this->_tlpButtons->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 16.66667F)));
			this->_tlpButtons->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 16.66667F)));
			this->_tlpButtons->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 16.66667F)));
			this->_tlpButtons->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 16.66667F)));
			this->_tlpButtons->Controls->Add(this->_btn0, 3, 6);
			this->_tlpButtons->Controls->Add(this->_btn1, 2, 5);
			this->_tlpButtons->Controls->Add(this->_btn2, 3, 5);
			this->_tlpButtons->Controls->Add(this->_btn3, 4, 5);
			this->_tlpButtons->Controls->Add(this->_btn4, 2, 4);
			this->_tlpButtons->Controls->Add(this->_btn5, 3, 4);
			this->_tlpButtons->Controls->Add(this->_btn6, 4, 4);
			this->_tlpButtons->Controls->Add(this->_btn9, 4, 3);
			this->_tlpButtons->Controls->Add(this->_btn8, 3, 3);
			this->_tlpButtons->Controls->Add(this->_btn7, 2, 3);
			this->_tlpButtons->Controls->Add(this->_btnPoint, 4, 6);
			this->_tlpButtons->Controls->Add(this->_btnPlusMinus, 2, 6);
			this->_tlpButtons->Controls->Add(this->_btnMultiply, 5, 3);
			this->_tlpButtons->Controls->Add(this->_btnMinus, 5, 4);
			this->_tlpButtons->Controls->Add(this->_btnPlus, 5, 5);
			this->_tlpButtons->Controls->Add(this->_btnEquals, 5, 6);
			this->_tlpButtons->Controls->Add(this->_btnDivide, 5, 2);
			this->_tlpButtons->Controls->Add(this->_btnBackspace, 5, 0);
			this->_tlpButtons->Controls->Add(this->_btnModulo, 5, 1);
			this->_tlpButtons->Controls->Add(this->_btnCE, 4, 0);
			this->_tlpButtons->Controls->Add(this->_btnInvert, 2, 1);
			this->_tlpButtons->Controls->Add(this->_btnExp, 4, 1);
			this->_tlpButtons->Controls->Add(this->_btnAbs, 3, 1);
			this->_tlpButtons->Controls->Add(this->_btnFactorial, 4, 2);
			this->_tlpButtons->Controls->Add(this->_btnRightParenthesis, 3, 2);
			this->_tlpButtons->Controls->Add(this->_btnLeftParenthesis, 2, 2);
			this->_tlpButtons->Controls->Add(this->_btn2ndOn, 1, 0);
			this->_tlpButtons->Controls->Add(this->_btnPow, 1, 3);
			this->_tlpButtons->Controls->Add(this->_btnE, 3, 0);
			this->_tlpButtons->Controls->Add(this->_btnPi, 2, 0);
			this->_tlpButtons->Controls->Add(this->_btn2ndOff, 0, 0);
			this->_tlpButtons->Controls->Add(this->_btnSqrt, 0, 1);
			this->_tlpButtons->Controls->Add(this->_btnCubeRoot, 0, 2);
			this->_tlpButtons->Controls->Add(this->_btn2ToX, 0, 4);
			this->_tlpButtons->Controls->Add(this->_btnEToX, 0, 6);
			this->_tlpButtons->Controls->Add(this->_btnSqr, 1, 1);
			this->_tlpButtons->Controls->Add(this->_btnCube, 1, 2);
			this->_tlpButtons->Controls->Add(this->_btn10ToX, 1, 4);
			this->_tlpButtons->Controls->Add(this->_btnLog, 1, 5);
			this->_tlpButtons->Controls->Add(this->_btnLn, 1, 6);
			this->_tlpButtons->Controls->Add(this->_btnLogYX, 0, 5);
			this->_tlpButtons->Controls->Add(this->_btnYRoot, 0, 3);
			this->_tlpButtons->Location = System::Drawing::Point(8, 134);
			this->_tlpButtons->Name = L"_tlpButtons";
			this->_tlpButtons->RowCount = 7;
			this->_tlpButtons->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 14.28571F)));
			this->_tlpButtons->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 14.28571F)));
			this->_tlpButtons->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 14.28571F)));
			this->_tlpButtons->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 14.28571F)));
			this->_tlpButtons->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 14.28571F)));
			this->_tlpButtons->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 14.28571F)));
			this->_tlpButtons->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 14.28571F)));
			this->_tlpButtons->Size = System::Drawing::Size(392, 297);
			this->_tlpButtons->TabIndex = 0;
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
			this->_btn0->Font = (gcnew System::Drawing::Font(L"Segoe UI", 14, System::Drawing::FontStyle::Bold));
			this->_btn0->Location = System::Drawing::Point(198, 255);
			this->_btn0->Name = L"_btn0";
			this->_btn0->Size = System::Drawing::Size(59, 39);
			this->_btn0->TabIndex = 0;
			this->_btn0->TabStop = false;
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
			this->_btn1->Font = (gcnew System::Drawing::Font(L"Segoe UI", 14, System::Drawing::FontStyle::Bold));
			this->_btn1->Location = System::Drawing::Point(133, 213);
			this->_btn1->Name = L"_btn1";
			this->_btn1->Size = System::Drawing::Size(59, 36);
			this->_btn1->TabIndex = 0;
			this->_btn1->TabStop = false;
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
			this->_btn2->Font = (gcnew System::Drawing::Font(L"Segoe UI", 14, System::Drawing::FontStyle::Bold));
			this->_btn2->Location = System::Drawing::Point(198, 213);
			this->_btn2->Name = L"_btn2";
			this->_btn2->Size = System::Drawing::Size(59, 36);
			this->_btn2->TabIndex = 0;
			this->_btn2->TabStop = false;
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
			this->_btn3->Font = (gcnew System::Drawing::Font(L"Segoe UI", 14, System::Drawing::FontStyle::Bold));
			this->_btn3->Location = System::Drawing::Point(263, 213);
			this->_btn3->Name = L"_btn3";
			this->_btn3->Size = System::Drawing::Size(59, 36);
			this->_btn3->TabIndex = 0;
			this->_btn3->TabStop = false;
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
			this->_btn4->Font = (gcnew System::Drawing::Font(L"Segoe UI", 14, System::Drawing::FontStyle::Bold));
			this->_btn4->Location = System::Drawing::Point(133, 171);
			this->_btn4->Name = L"_btn4";
			this->_btn4->Size = System::Drawing::Size(59, 36);
			this->_btn4->TabIndex = 0;
			this->_btn4->TabStop = false;
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
			this->_btn5->Font = (gcnew System::Drawing::Font(L"Segoe UI", 14, System::Drawing::FontStyle::Bold));
			this->_btn5->Location = System::Drawing::Point(198, 171);
			this->_btn5->Name = L"_btn5";
			this->_btn5->Size = System::Drawing::Size(59, 36);
			this->_btn5->TabIndex = 0;
			this->_btn5->TabStop = false;
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
			this->_btn6->Font = (gcnew System::Drawing::Font(L"Segoe UI", 14, System::Drawing::FontStyle::Bold));
			this->_btn6->Location = System::Drawing::Point(263, 171);
			this->_btn6->Name = L"_btn6";
			this->_btn6->Size = System::Drawing::Size(59, 36);
			this->_btn6->TabIndex = 0;
			this->_btn6->TabStop = false;
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
			this->_btn9->Font = (gcnew System::Drawing::Font(L"Segoe UI", 14, System::Drawing::FontStyle::Bold));
			this->_btn9->Location = System::Drawing::Point(263, 129);
			this->_btn9->Name = L"_btn9";
			this->_btn9->Size = System::Drawing::Size(59, 36);
			this->_btn9->TabIndex = 0;
			this->_btn9->TabStop = false;
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
			this->_btn8->Font = (gcnew System::Drawing::Font(L"Segoe UI", 14, System::Drawing::FontStyle::Bold));
			this->_btn8->Location = System::Drawing::Point(198, 129);
			this->_btn8->Name = L"_btn8";
			this->_btn8->Size = System::Drawing::Size(59, 36);
			this->_btn8->TabIndex = 0;
			this->_btn8->TabStop = false;
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
			this->_btn7->Font = (gcnew System::Drawing::Font(L"Segoe UI", 14, System::Drawing::FontStyle::Bold));
			this->_btn7->Location = System::Drawing::Point(133, 129);
			this->_btn7->Name = L"_btn7";
			this->_btn7->Size = System::Drawing::Size(59, 36);
			this->_btn7->TabIndex = 0;
			this->_btn7->TabStop = false;
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
			this->_btnPoint->Font = (gcnew System::Drawing::Font(L"Segoe UI", 14, System::Drawing::FontStyle::Bold));
			this->_btnPoint->Location = System::Drawing::Point(263, 255);
			this->_btnPoint->Name = L"_btnPoint";
			this->_btnPoint->Size = System::Drawing::Size(59, 39);
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
			this->_btnPlusMinus->Font = (gcnew System::Drawing::Font(L"Segoe UI", 14, System::Drawing::FontStyle::Bold));
			this->_btnPlusMinus->Location = System::Drawing::Point(133, 255);
			this->_btnPlusMinus->Name = L"_btnPlusMinus";
			this->_btnPlusMinus->Size = System::Drawing::Size(59, 39);
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
			this->_btnMultiply->Font = (gcnew System::Drawing::Font(L"Segoe UI", 14));
			this->_btnMultiply->Location = System::Drawing::Point(328, 129);
			this->_btnMultiply->Name = L"_btnMultiply";
			this->_btnMultiply->Size = System::Drawing::Size(61, 36);
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
			this->_btnMinus->Font = (gcnew System::Drawing::Font(L"Segoe UI", 14));
			this->_btnMinus->Location = System::Drawing::Point(328, 171);
			this->_btnMinus->Name = L"_btnMinus";
			this->_btnMinus->Size = System::Drawing::Size(61, 36);
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
			this->_btnPlus->Font = (gcnew System::Drawing::Font(L"Segoe UI", 14));
			this->_btnPlus->Location = System::Drawing::Point(328, 213);
			this->_btnPlus->Name = L"_btnPlus";
			this->_btnPlus->Size = System::Drawing::Size(61, 36);
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
			this->_btnEquals->Font = (gcnew System::Drawing::Font(L"Segoe UI", 14));
			this->_btnEquals->Location = System::Drawing::Point(328, 255);
			this->_btnEquals->Name = L"_btnEquals";
			this->_btnEquals->Size = System::Drawing::Size(61, 39);
			this->_btnEquals->TabIndex = 0;
			this->_btnEquals->TabStop = false;
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
			this->_btnDivide->Font = (gcnew System::Drawing::Font(L"Segoe UI", 14));
			this->_btnDivide->Location = System::Drawing::Point(328, 87);
			this->_btnDivide->Name = L"_btnDivide";
			this->_btnDivide->Size = System::Drawing::Size(61, 36);
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
			this->_btnBackspace->Location = System::Drawing::Point(328, 3);
			this->_btnBackspace->Name = L"_btnBackspace";
			this->_btnBackspace->Size = System::Drawing::Size(61, 36);
			this->_btnBackspace->TabIndex = 0;
			this->_btnBackspace->TabStop = false;
			this->_btnBackspace->Text = L"←";
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
			this->_btnModulo->Font = (gcnew System::Drawing::Font(L"Segoe UI", 11));
			this->_btnModulo->Location = System::Drawing::Point(328, 45);
			this->_btnModulo->Name = L"_btnModulo";
			this->_btnModulo->Size = System::Drawing::Size(61, 36);
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
			this->_btnCE->Font = (gcnew System::Drawing::Font(L"Segoe UI", 11));
			this->_btnCE->Location = System::Drawing::Point(263, 3);
			this->_btnCE->Name = L"_btnCE";
			this->_btnCE->Size = System::Drawing::Size(59, 36);
			this->_btnCE->TabIndex = 0;
			this->_btnCE->TabStop = false;
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
			this->_btnInvert->Font = (gcnew System::Drawing::Font(L"Segoe UI", 11));
			this->_btnInvert->Location = System::Drawing::Point(133, 45);
			this->_btnInvert->Name = L"_btnInvert";
			this->_btnInvert->Size = System::Drawing::Size(59, 36);
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
			this->_btnExp->Font = (gcnew System::Drawing::Font(L"Segoe UI", 11));
			this->_btnExp->Location = System::Drawing::Point(263, 45);
			this->_btnExp->Name = L"_btnExp";
			this->_btnExp->Size = System::Drawing::Size(59, 36);
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
			this->_btnAbs->Font = (gcnew System::Drawing::Font(L"Segoe UI", 11));
			this->_btnAbs->Location = System::Drawing::Point(198, 45);
			this->_btnAbs->Name = L"_btnAbs";
			this->_btnAbs->Size = System::Drawing::Size(59, 36);
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
			this->_btnFactorial->Font = (gcnew System::Drawing::Font(L"Segoe UI", 11));
			this->_btnFactorial->Location = System::Drawing::Point(263, 87);
			this->_btnFactorial->Name = L"_btnFactorial";
			this->_btnFactorial->Size = System::Drawing::Size(59, 36);
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
			this->_btnRightParenthesis->Font = (gcnew System::Drawing::Font(L"Segoe UI", 11));
			this->_btnRightParenthesis->Location = System::Drawing::Point(198, 87);
			this->_btnRightParenthesis->Name = L"_btnRightParenthesis";
			this->_btnRightParenthesis->Size = System::Drawing::Size(59, 36);
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
			this->_btnLeftParenthesis->Font = (gcnew System::Drawing::Font(L"Segoe UI", 11));
			this->_btnLeftParenthesis->Location = System::Drawing::Point(133, 87);
			this->_btnLeftParenthesis->Name = L"_btnLeftParenthesis";
			this->_btnLeftParenthesis->Size = System::Drawing::Size(59, 36);
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
			this->_btn2ndOn->Location = System::Drawing::Point(68, 3);
			this->_btn2ndOn->Name = L"_btn2ndOn";
			this->_btn2ndOn->Size = System::Drawing::Size(59, 36);
			this->_btn2ndOn->TabIndex = 0;
			this->_btn2ndOn->TabStop = false;
			this->_btn2ndOn->Text = L"2nd";
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
			this->_btnPow->Font = (gcnew System::Drawing::Font(L"Segoe UI", 11));
			this->_btnPow->Location = System::Drawing::Point(68, 129);
			this->_btnPow->Name = L"_btnPow";
			this->_btnPow->Size = System::Drawing::Size(59, 36);
			this->_btnPow->TabIndex = 0;
			this->_btnPow->TabStop = false;
			this->_btnPow->Text = L"x^y";
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
			this->_btnE->Font = (gcnew System::Drawing::Font(L"Segoe UI", 11));
			this->_btnE->Location = System::Drawing::Point(198, 3);
			this->_btnE->Name = L"_btnE";
			this->_btnE->Size = System::Drawing::Size(59, 36);
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
			this->_btnPi->Font = (gcnew System::Drawing::Font(L"Segoe UI", 11));
			this->_btnPi->Location = System::Drawing::Point(133, 3);
			this->_btnPi->Name = L"_btnPi";
			this->_btnPi->Size = System::Drawing::Size(59, 36);
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
			this->_btn2ndOff->Size = System::Drawing::Size(59, 36);
			this->_btn2ndOff->TabIndex = 0;
			this->_btn2ndOff->TabStop = false;
			this->_btn2ndOff->Text = L"2nd";
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
			this->_btnSqrt->Font = (gcnew System::Drawing::Font(L"Segoe UI", 11));
			this->_btnSqrt->Location = System::Drawing::Point(3, 45);
			this->_btnSqrt->Name = L"_btnSqrt";
			this->_btnSqrt->Size = System::Drawing::Size(59, 36);
			this->_btnSqrt->TabIndex = 0;
			this->_btnSqrt->TabStop = false;
			this->_btnSqrt->Text = L"^1/2";
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
			this->_btnCubeRoot->Font = (gcnew System::Drawing::Font(L"Segoe UI", 11));
			this->_btnCubeRoot->Location = System::Drawing::Point(3, 87);
			this->_btnCubeRoot->Name = L"_btnCubeRoot";
			this->_btnCubeRoot->Size = System::Drawing::Size(59, 36);
			this->_btnCubeRoot->TabIndex = 0;
			this->_btnCubeRoot->TabStop = false;
			this->_btnCubeRoot->Text = L"^1/3";
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
			this->_btn2ToX->Font = (gcnew System::Drawing::Font(L"Segoe UI", 11));
			this->_btn2ToX->Location = System::Drawing::Point(3, 171);
			this->_btn2ToX->Name = L"_btn2ToX";
			this->_btn2ToX->Size = System::Drawing::Size(59, 36);
			this->_btn2ToX->TabIndex = 0;
			this->_btn2ToX->TabStop = false;
			this->_btn2ToX->Text = L"2^x";
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
			this->_btnEToX->Font = (gcnew System::Drawing::Font(L"Segoe UI", 11));
			this->_btnEToX->Location = System::Drawing::Point(3, 255);
			this->_btnEToX->Name = L"_btnEToX";
			this->_btnEToX->Size = System::Drawing::Size(59, 39);
			this->_btnEToX->TabIndex = 0;
			this->_btnEToX->TabStop = false;
			this->_btnEToX->Text = L"e^x";
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
			this->_btnSqr->Font = (gcnew System::Drawing::Font(L"Segoe UI", 11));
			this->_btnSqr->Location = System::Drawing::Point(68, 45);
			this->_btnSqr->Name = L"_btnSqr";
			this->_btnSqr->Size = System::Drawing::Size(59, 36);
			this->_btnSqr->TabIndex = 0;
			this->_btnSqr->TabStop = false;
			this->_btnSqr->Text = L"x^2";
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
			this->_btnCube->Font = (gcnew System::Drawing::Font(L"Segoe UI", 11));
			this->_btnCube->Location = System::Drawing::Point(68, 87);
			this->_btnCube->Name = L"_btnCube";
			this->_btnCube->Size = System::Drawing::Size(59, 36);
			this->_btnCube->TabIndex = 0;
			this->_btnCube->TabStop = false;
			this->_btnCube->Text = L"x^3";
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
			this->_btn10ToX->Font = (gcnew System::Drawing::Font(L"Segoe UI", 11));
			this->_btn10ToX->Location = System::Drawing::Point(68, 171);
			this->_btn10ToX->Name = L"_btn10ToX";
			this->_btn10ToX->Size = System::Drawing::Size(59, 36);
			this->_btn10ToX->TabIndex = 0;
			this->_btn10ToX->TabStop = false;
			this->_btn10ToX->Text = L"10^x";
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
			this->_btnLog->Font = (gcnew System::Drawing::Font(L"Segoe UI", 11));
			this->_btnLog->Location = System::Drawing::Point(68, 213);
			this->_btnLog->Name = L"_btnLog";
			this->_btnLog->Size = System::Drawing::Size(59, 36);
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
			this->_btnLn->Font = (gcnew System::Drawing::Font(L"Segoe UI", 11));
			this->_btnLn->Location = System::Drawing::Point(68, 255);
			this->_btnLn->Name = L"_btnLn";
			this->_btnLn->Size = System::Drawing::Size(59, 39);
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
			this->_btnLogYX->Font = (gcnew System::Drawing::Font(L"Segoe UI", 11));
			this->_btnLogYX->Location = System::Drawing::Point(3, 213);
			this->_btnLogYX->Name = L"_btnLogYX";
			this->_btnLogYX->Size = System::Drawing::Size(59, 36);
			this->_btnLogYX->TabIndex = 0;
			this->_btnLogYX->TabStop = false;
			this->_btnLogYX->Text = L"logyx";
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
			this->_btnYRoot->Font = (gcnew System::Drawing::Font(L"Segoe UI", 11));
			this->_btnYRoot->Location = System::Drawing::Point(3, 129);
			this->_btnYRoot->Name = L"_btnYRoot";
			this->_btnYRoot->Size = System::Drawing::Size(59, 36);
			this->_btnYRoot->TabIndex = 0;
			this->_btnYRoot->TabStop = false;
			this->_btnYRoot->Text = L"^1/y";
			this->_btnYRoot->UseVisualStyleBackColor = false;
			this->_btnYRoot->Click += gcnew System::EventHandler(this, &FrmCalculator::_btnYRoot_Click);
			// 
			// tableLayoutPanel2
			// 
			this->tableLayoutPanel2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->tableLayoutPanel2->ColumnCount = 1;
			this->tableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				100)));
			this->tableLayoutPanel2->Controls->Add(this->_lblCurrentNum, 0, 2);
			this->tableLayoutPanel2->Controls->Add(this->_lblCurrentExpr, 0, 1);
			this->tableLayoutPanel2->Location = System::Drawing::Point(8, 8);
			this->tableLayoutPanel2->Margin = System::Windows::Forms::Padding(0);
			this->tableLayoutPanel2->Name = L"tableLayoutPanel2";
			this->tableLayoutPanel2->RowCount = 4;
			this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle()));
			this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle()));
			this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableLayoutPanel2->Size = System::Drawing::Size(392, 123);
			this->tableLayoutPanel2->TabIndex = 1;
			// 
			// _lblCurrentNum
			// 
			this->_lblCurrentNum->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->_lblCurrentNum->AutoSize = true;
			this->_lblCurrentNum->Font = (gcnew System::Drawing::Font(L"Consolas", 24, System::Drawing::FontStyle::Bold));
			this->_lblCurrentNum->Location = System::Drawing::Point(354, 52);
			this->_lblCurrentNum->Name = L"_lblCurrentNum";
			this->_lblCurrentNum->Size = System::Drawing::Size(35, 37);
			this->_lblCurrentNum->TabIndex = 1;
			this->_lblCurrentNum->Text = L"0";
			// 
			// _lblCurrentExpr
			// 
			this->_lblCurrentExpr->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->_lblCurrentExpr->AutoSize = true;
			this->_lblCurrentExpr->Font = (gcnew System::Drawing::Font(L"Consolas", 12));
			this->_lblCurrentExpr->Location = System::Drawing::Point(389, 33);
			this->_lblCurrentExpr->Name = L"_lblCurrentExpr";
			this->_lblCurrentExpr->Size = System::Drawing::Size(0, 19);
			this->_lblCurrentExpr->TabIndex = 1;
			// 
			// FrmCalculator
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(16)), static_cast<System::Int32>(static_cast<System::Byte>(16)),
				static_cast<System::Int32>(static_cast<System::Byte>(16)));
			this->ClientSize = System::Drawing::Size(408, 439);
			this->Controls->Add(this->_tlpButtons);
			this->Controls->Add(this->tableLayoutPanel2);
			this->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(238)), static_cast<System::Int32>(static_cast<System::Byte>(238)),
				static_cast<System::Int32>(static_cast<System::Byte>(238)));
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->KeyPreview = true;
			this->MaximizeBox = false;
			this->Name = L"FrmCalculator";
			this->Padding = System::Windows::Forms::Padding(8);
			this->Text = L"Epic gamer calculator 69 420";
			this->_tlpButtons->ResumeLayout(false);
			this->tableLayoutPanel2->ResumeLayout(false);
			this->tableLayoutPanel2->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion

	private:
		System::String^ _currentNum = L"0";
		System::String^ _currentExpr = L"";

		TokenTypes _lastToken = TokenTypes::Number;
		String^ _lastOperator = "";

		ldbl GetCurrentNumDbl()
		{
			return ldbl::Parse(_currentNum);
		}

		// refresh UI for current num
		void UpdateCurrentNumLabel()
		{
			_lblCurrentNum->Text = _currentNum;

			_btnCE->Text = _currentNum == L"0" ? L"C" : L"CE";
		}

		// refresh UI for current expr
		void UpdateCurrentExprLabel()
		{
			_lblCurrentExpr->Text = _currentExpr;
		}

		// switch to 2nd button pane
		void SwitchTo2nd()
		{
			_tlpButtons->SuspendLayout();

			_tlpButtons->ColumnStyles[0]->Width = 16.67;
			_tlpButtons->ColumnStyles[1]->Width = 0;

			for each (Control ^ control in _tlpButtons->Controls)
			{
				if (_tlpButtons->GetColumn(control) == 0)
					control->Show();
				else if (_tlpButtons->GetColumn(control) == 1)
					control->Hide();
			}

			_tlpButtons->ResumeLayout();
		}

		// return to the 1st pane
		void SwitchTo1st()
		{
			_tlpButtons->SuspendLayout();

			_tlpButtons->ColumnStyles[0]->Width = 0;
			_tlpButtons->ColumnStyles[1]->Width = 16.67;

			for each (Control ^ control in _tlpButtons->Controls)
			{
				if (_tlpButtons->GetColumn(control) == 0)
					control->Hide();
				else if (_tlpButtons->GetColumn(control) == 1)
					control->Show();
			}

			_tlpButtons->ResumeLayout();
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
				return expr->Calc().ToString();
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

#pragma region commands

		// appending

		void AppendDigit(String^ d)
		{
			if (_lastToken == TokenTypes::Equals) Clear();
			else if (_lastToken != TokenTypes::Number) _currentNum = L"0";

			// if the number is 0, replace it with the clicked number
			if (_currentNum == L"0" || _currentNum == L"-0") _currentNum = _currentNum->Replace(L"0", d);

			// otherwise append the clicked button's text to the number
			else _currentNum += d;

			_lastToken = TokenTypes::Number;

			// refresh UI
			UpdateCurrentNumLabel();
		}

		void AppendPoint()
		{
			if (_lastToken == TokenTypes::Equals) Clear();
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
					_currentExpr = _currentNum;

				// if the last input was a closing parenthesis (normal or of a function), don't append the current number
				else if (_lastToken != TokenTypes::RightParenthesis && _lastToken != TokenTypes::Function)
					_currentExpr += _currentNum;

				// always append the operator
				_currentExpr += L" " + op + L" ";
			}

			_lastOperator = op;
			_lastToken = TokenTypes::Operator;

			UpdateCurrentExprLabel();
			UpdateCurrentNumLabel();
		}

		void AppendLeftParenthesis()
		{
			if (_lastToken == TokenTypes::Equals) Clear();

			_currentExpr += L"(";
			_lastToken = TokenTypes::LeftParenthesis;
			UpdateCurrentExprLabel();
		}

		void AppendRightParenthesis()
		{
			// don't append if there are no unclosed parentheses
			if (GetUnclosedParenthesisCount() == 0) return;

			// only append the current number if the last input was not an ending parenthesis
			if (_lastToken != TokenTypes::RightParenthesis && _lastToken != TokenTypes::Function)
				_currentExpr += _currentNum;
			
			_currentExpr += L")";

			// set the current num to the result of this parenthesis
			_currentNum = CalcLastToken();

			_lastToken = TokenTypes::RightParenthesis;

			UpdateCurrentExprLabel();
			UpdateCurrentNumLabel();
		}

		void AppendFunction(String^ func)
		{
			// if the previous operation calculated a result, execute the function on that result
			if (_lastToken == TokenTypes::Equals)
				_currentExpr = func + L"(" + _currentNum + L")";

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
				_currentExpr += func + L"(" + _currentNum + L")";
			}

			// set the current num to the result of this function
			_currentNum = CalcLastToken();

			_lastToken = TokenTypes::Function;

			UpdateCurrentExprLabel();
			UpdateCurrentNumLabel();
		}

		// setting

		void SetCurrentNumToE()
		{
			_currentNum = Math::E.ToString();

			_lastToken = TokenTypes::Number;

			UpdateCurrentNumLabel();
		}

		void SetCurrentNumToPi()
		{
			_currentNum = Math::PI.ToString();
			_lastToken = TokenTypes::Number;
			UpdateCurrentNumLabel();
		}


		// erasing

		void Backspace()
		{
			// if the current number only has one digit with or without a minus, set the current number to 0
			if (_currentNum[0] == '-' && _currentNum->Length <= 2 || _currentNum->Length <= 1) _currentNum = "0";

			// otherwise delete the last character from the string
			else _currentNum = _currentNum->Substring(0, _currentNum->Length - 1);

			UpdateCurrentNumLabel();
		}

		void ClearEntry()
		{
			// if the last input was an equals, do a full clear
			if (_lastToken == TokenTypes::Equals)
			{
				Clear();
			}

			// clear entry (current number)
			_currentNum = "0";
			UpdateCurrentNumLabel();
		}

		void Clear()
		{
			_currentExpr = L"";
			_currentNum = L"0";
			_lastToken = TokenTypes::Number;
			_lastOperator = "";

			UpdateCurrentExprLabel();
			UpdateCurrentNumLabel();
		}

		void CEButton()
		{
			if (_currentNum == L"0" || _lastToken == TokenTypes::Equals) Clear();
			else ClearEntry();
		}


		// misc

		void Negate()
		{
			// if the last input was a closing parenthesis or a function, negate the whole parenthesis/function
			if (_lastToken == TokenTypes::RightParenthesis || _lastToken == TokenTypes::Function)
			{
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

			// if the last input was an operator or the current expression ends with an operator, append the current number after that operator
			if (_lastToken == TokenTypes::Operator || GetExprEndsWithOperator())
				_currentExpr += _currentNum;

			// if the current expression is empty or ends with a parenthesis and the last input was a number, set the expression to the current number
			else if (_currentExpr == L"" || (_currentExpr->EndsWith(L")") && _lastToken == TokenTypes::Number))
				_currentExpr = _currentNum;


			int unclosedCount = GetUnclosedParenthesisCount();

			// close missing parentheses
			for (int i = 0; i < unclosedCount; i++)
				_currentExpr += L")";

			// handle consecutive equals presses
			if (_lastToken == TokenTypes::Equals)
			{
				String^ lastTopLevelOp = FindLastTopLevelOp();
				if (lastTopLevelOp == L"")
					_currentExpr = _currentNum;
				else
					_currentExpr = _currentNum + L" " + lastTopLevelOp + L" " + CalcLastToken();
			}

			UpdateCurrentExprLabel();

			Expression^ expr;
			if (Expression::TryParse(_currentExpr, expr))
			{
				try
				{
					_currentNum = expr->Calc().ToString();
					_lblCurrentExpr->Text += L" = ";
					_lastToken = TokenTypes::Equals;
				}
				catch (Exception^ ex)
				{
					_currentNum = "Invalid input!";
				}

				UpdateCurrentNumLabel();
			}
			else
			{
				MessageBox::Show(L"Parsing failed miserably, whoops");
			}


		}

#pragma endregion


#pragma region event handlers

	protected:

		// handle all key presses on the form
		virtual bool ProcessCmdKey(Message% msg, Keys k) override
		{

			// list of shortcuts here:
			// https://support.microsoft.com/en-us/help/13805/windows-keyboard-shortcuts-in-apps

			// here so breakpoints during debug time don't trigger on just shift being pressed, should be commented out later
			if (k == (Keys::ShiftKey | Keys::Shift)) return true;


			// special keys

			else if (k == Keys::Back)
				Backspace();

			else if (k == Keys::Delete)
				ClearEntry(); // delete always clears entry instead of pressing the CE button

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

			else if (k == Keys::Divide)
				AppendOperator(L"/");

			else if (k == Keys::OemPipe | k == (Keys::OemBackslash | Keys::Shift) | k == (Keys::Oem5 | Keys::Shift))
				AppendFunction(L"abs");


			// letter keys + modifiers

			else if (k == (Keys::E | Keys::Shift))
				SetCurrentNumToE();

			else if (k == (Keys::G | Keys::Control))
				AppendFunction(L"10^");

			else if (k == (Keys::N | Keys::Control))
				AppendFunction(L"e^");

			else if (k == (Keys::Y | Keys::Control))
				AppendFunction(L"yroot");


			// letter keys

			else if (k == Keys::L)
				AppendFunction(L"log");

			else if (k == Keys::N)
				AppendFunction(L"ln");

			else if (k == Keys::P)
				SetCurrentNumToPi();

			else if (k == Keys::Q)
				AppendFunction(L"sqrt");

			else if (k == Keys::Q)
				AppendFunction(L"1/");

			else if (k == Keys::Y)
				AppendOperator(L"^");


			// function keys

			else if (k == Keys::F9)
				Negate();


			// number keys + shift

			else if (k == (Keys::D1 | Keys::Shift)) // !
				AppendFunction(L"fact");

			else if (k == (Keys::D2 | Keys::Shift)) // @ (shift + 2)
				AppendFunction(L"sqrt");

			else if (k == (Keys::D3 | Keys::Shift)) // #
				AppendFunction(L"cube");

			else if (k == (Keys::D5 | Keys::Shift)) // %
				AppendOperator(L"mod");

			else if (k == (Keys::D6 | Keys::Shift)) // ^
				AppendOperator(L"^");

			else if (k == (Keys::D9 | Keys::Shift))	// (
				AppendLeftParenthesis();

			else if (k == (Keys::D0 | Keys::Shift)) // )
				AppendRightParenthesis();


			// number keys
			else if (k >= Keys::D0 && k <= Keys::D9)
				AppendDigit(((int)(k - Keys::D0)).ToString());

			// numpad number keys
			else if (k >= Keys::NumPad0 && k <= Keys::NumPad9)
				AppendDigit(((int)(k - Keys::NumPad0)).ToString());

			// decimal point keys
			else if (k == Keys::OemPeriod || k == Keys::Oemcomma || k == Keys::Decimal)
				AppendPoint();

			return true;
		}

	private:

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


		// switch panes

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

#pragma endregion

	};
}
