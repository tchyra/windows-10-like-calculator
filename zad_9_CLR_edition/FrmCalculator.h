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
	private: System::Windows::Forms::TableLayoutPanel^ _tlpButtons;
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
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;






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
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
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
			this->_tlpButtons->Controls->Add(this->button1, 0, 5);
			this->_tlpButtons->Controls->Add(this->button2, 0, 3);
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
			this->_btn0->Font = (gcnew System::Drawing::Font(L"Consolas", 14, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->_btn0->Location = System::Drawing::Point(198, 255);
			this->_btn0->Name = L"_btn0";
			this->_btn0->Size = System::Drawing::Size(59, 39);
			this->_btn0->TabIndex = 0;
			this->_btn0->TabStop = false;
			this->_btn0->Text = L"0";
			this->_btn0->UseVisualStyleBackColor = true;
			this->_btn0->Click += gcnew System::EventHandler(this, &FrmCalculator::_btnNumber_Click);
			// 
			// _btn1
			// 
			this->_btn1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->_btn1->Font = (gcnew System::Drawing::Font(L"Consolas", 14, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->_btn1->Location = System::Drawing::Point(133, 213);
			this->_btn1->Name = L"_btn1";
			this->_btn1->Size = System::Drawing::Size(59, 36);
			this->_btn1->TabIndex = 0;
			this->_btn1->TabStop = false;
			this->_btn1->Text = L"1";
			this->_btn1->UseVisualStyleBackColor = true;
			this->_btn1->Click += gcnew System::EventHandler(this, &FrmCalculator::_btnNumber_Click);
			// 
			// _btn2
			// 
			this->_btn2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->_btn2->Font = (gcnew System::Drawing::Font(L"Consolas", 14, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->_btn2->Location = System::Drawing::Point(198, 213);
			this->_btn2->Name = L"_btn2";
			this->_btn2->Size = System::Drawing::Size(59, 36);
			this->_btn2->TabIndex = 0;
			this->_btn2->TabStop = false;
			this->_btn2->Text = L"2";
			this->_btn2->UseVisualStyleBackColor = true;
			this->_btn2->Click += gcnew System::EventHandler(this, &FrmCalculator::_btnNumber_Click);
			// 
			// _btn3
			// 
			this->_btn3->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->_btn3->Font = (gcnew System::Drawing::Font(L"Consolas", 14, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->_btn3->Location = System::Drawing::Point(263, 213);
			this->_btn3->Name = L"_btn3";
			this->_btn3->Size = System::Drawing::Size(59, 36);
			this->_btn3->TabIndex = 0;
			this->_btn3->TabStop = false;
			this->_btn3->Text = L"3";
			this->_btn3->UseVisualStyleBackColor = true;
			this->_btn3->Click += gcnew System::EventHandler(this, &FrmCalculator::_btnNumber_Click);
			// 
			// _btn4
			// 
			this->_btn4->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->_btn4->Font = (gcnew System::Drawing::Font(L"Consolas", 14, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->_btn4->Location = System::Drawing::Point(133, 171);
			this->_btn4->Name = L"_btn4";
			this->_btn4->Size = System::Drawing::Size(59, 36);
			this->_btn4->TabIndex = 0;
			this->_btn4->TabStop = false;
			this->_btn4->Text = L"4";
			this->_btn4->UseVisualStyleBackColor = true;
			this->_btn4->Click += gcnew System::EventHandler(this, &FrmCalculator::_btnNumber_Click);
			// 
			// _btn5
			// 
			this->_btn5->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->_btn5->Font = (gcnew System::Drawing::Font(L"Consolas", 14, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->_btn5->Location = System::Drawing::Point(198, 171);
			this->_btn5->Name = L"_btn5";
			this->_btn5->Size = System::Drawing::Size(59, 36);
			this->_btn5->TabIndex = 0;
			this->_btn5->TabStop = false;
			this->_btn5->Text = L"5";
			this->_btn5->UseVisualStyleBackColor = true;
			this->_btn5->Click += gcnew System::EventHandler(this, &FrmCalculator::_btnNumber_Click);
			// 
			// _btn6
			// 
			this->_btn6->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->_btn6->Font = (gcnew System::Drawing::Font(L"Consolas", 14, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->_btn6->Location = System::Drawing::Point(263, 171);
			this->_btn6->Name = L"_btn6";
			this->_btn6->Size = System::Drawing::Size(59, 36);
			this->_btn6->TabIndex = 0;
			this->_btn6->TabStop = false;
			this->_btn6->Text = L"6";
			this->_btn6->UseVisualStyleBackColor = true;
			this->_btn6->Click += gcnew System::EventHandler(this, &FrmCalculator::_btnNumber_Click);
			// 
			// _btn9
			// 
			this->_btn9->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->_btn9->Font = (gcnew System::Drawing::Font(L"Consolas", 14, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->_btn9->Location = System::Drawing::Point(263, 129);
			this->_btn9->Name = L"_btn9";
			this->_btn9->Size = System::Drawing::Size(59, 36);
			this->_btn9->TabIndex = 0;
			this->_btn9->TabStop = false;
			this->_btn9->Text = L"9";
			this->_btn9->UseVisualStyleBackColor = true;
			this->_btn9->Click += gcnew System::EventHandler(this, &FrmCalculator::_btnNumber_Click);
			// 
			// _btn8
			// 
			this->_btn8->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->_btn8->Font = (gcnew System::Drawing::Font(L"Consolas", 14, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->_btn8->Location = System::Drawing::Point(198, 129);
			this->_btn8->Name = L"_btn8";
			this->_btn8->Size = System::Drawing::Size(59, 36);
			this->_btn8->TabIndex = 0;
			this->_btn8->TabStop = false;
			this->_btn8->Text = L"8";
			this->_btn8->UseVisualStyleBackColor = true;
			this->_btn8->Click += gcnew System::EventHandler(this, &FrmCalculator::_btnNumber_Click);
			// 
			// _btn7
			// 
			this->_btn7->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->_btn7->Font = (gcnew System::Drawing::Font(L"Consolas", 14, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->_btn7->Location = System::Drawing::Point(133, 129);
			this->_btn7->Name = L"_btn7";
			this->_btn7->Size = System::Drawing::Size(59, 36);
			this->_btn7->TabIndex = 0;
			this->_btn7->TabStop = false;
			this->_btn7->Text = L"7";
			this->_btn7->UseVisualStyleBackColor = true;
			this->_btn7->Click += gcnew System::EventHandler(this, &FrmCalculator::_btnNumber_Click);
			// 
			// _btnPoint
			// 
			this->_btnPoint->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->_btnPoint->Font = (gcnew System::Drawing::Font(L"Consolas", 14, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->_btnPoint->Location = System::Drawing::Point(263, 255);
			this->_btnPoint->Name = L"_btnPoint";
			this->_btnPoint->Size = System::Drawing::Size(59, 39);
			this->_btnPoint->TabIndex = 0;
			this->_btnPoint->TabStop = false;
			this->_btnPoint->Text = L".";
			this->_btnPoint->UseVisualStyleBackColor = true;
			this->_btnPoint->Click += gcnew System::EventHandler(this, &FrmCalculator::_btnPoint_Click);
			// 
			// _btnPlusMinus
			// 
			this->_btnPlusMinus->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->_btnPlusMinus->Font = (gcnew System::Drawing::Font(L"Consolas", 14, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->_btnPlusMinus->Location = System::Drawing::Point(133, 255);
			this->_btnPlusMinus->Name = L"_btnPlusMinus";
			this->_btnPlusMinus->Size = System::Drawing::Size(59, 39);
			this->_btnPlusMinus->TabIndex = 0;
			this->_btnPlusMinus->TabStop = false;
			this->_btnPlusMinus->Text = L"±";
			this->_btnPlusMinus->UseVisualStyleBackColor = true;
			this->_btnPlusMinus->Click += gcnew System::EventHandler(this, &FrmCalculator::_btnPlusMinus_Click);
			// 
			// _btnMultiply
			// 
			this->_btnMultiply->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->_btnMultiply->Font = (gcnew System::Drawing::Font(L"Consolas", 14, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->_btnMultiply->Location = System::Drawing::Point(328, 129);
			this->_btnMultiply->Name = L"_btnMultiply";
			this->_btnMultiply->Size = System::Drawing::Size(61, 36);
			this->_btnMultiply->TabIndex = 0;
			this->_btnMultiply->TabStop = false;
			this->_btnMultiply->Text = L"×";
			this->_btnMultiply->UseVisualStyleBackColor = true;
			this->_btnMultiply->Click += gcnew System::EventHandler(this, &FrmCalculator::_btnMultiply_Click);
			// 
			// _btnMinus
			// 
			this->_btnMinus->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->_btnMinus->Font = (gcnew System::Drawing::Font(L"Consolas", 14, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->_btnMinus->Location = System::Drawing::Point(328, 171);
			this->_btnMinus->Name = L"_btnMinus";
			this->_btnMinus->Size = System::Drawing::Size(61, 36);
			this->_btnMinus->TabIndex = 0;
			this->_btnMinus->TabStop = false;
			this->_btnMinus->Text = L"−";
			this->_btnMinus->UseVisualStyleBackColor = true;
			this->_btnMinus->Click += gcnew System::EventHandler(this, &FrmCalculator::_btnMinus_Click);
			// 
			// _btnPlus
			// 
			this->_btnPlus->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->_btnPlus->Font = (gcnew System::Drawing::Font(L"Consolas", 14, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->_btnPlus->Location = System::Drawing::Point(328, 213);
			this->_btnPlus->Name = L"_btnPlus";
			this->_btnPlus->Size = System::Drawing::Size(61, 36);
			this->_btnPlus->TabIndex = 0;
			this->_btnPlus->TabStop = false;
			this->_btnPlus->Text = L"+";
			this->_btnPlus->UseVisualStyleBackColor = true;
			this->_btnPlus->Click += gcnew System::EventHandler(this, &FrmCalculator::_btnPlus_Click);
			// 
			// _btnEquals
			// 
			this->_btnEquals->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->_btnEquals->Font = (gcnew System::Drawing::Font(L"Consolas", 14, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->_btnEquals->Location = System::Drawing::Point(328, 255);
			this->_btnEquals->Name = L"_btnEquals";
			this->_btnEquals->Size = System::Drawing::Size(61, 39);
			this->_btnEquals->TabIndex = 0;
			this->_btnEquals->TabStop = false;
			this->_btnEquals->Text = L"=";
			this->_btnEquals->UseVisualStyleBackColor = true;
			this->_btnEquals->Click += gcnew System::EventHandler(this, &FrmCalculator::_btnEquals_Click);
			// 
			// _btnDivide
			// 
			this->_btnDivide->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->_btnDivide->Font = (gcnew System::Drawing::Font(L"Consolas", 14, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->_btnDivide->Location = System::Drawing::Point(328, 87);
			this->_btnDivide->Name = L"_btnDivide";
			this->_btnDivide->Size = System::Drawing::Size(61, 36);
			this->_btnDivide->TabIndex = 0;
			this->_btnDivide->TabStop = false;
			this->_btnDivide->Text = L"÷";
			this->_btnDivide->UseVisualStyleBackColor = true;
			this->_btnDivide->Click += gcnew System::EventHandler(this, &FrmCalculator::_btnDivide_Click);
			// 
			// _btnBackspace
			// 
			this->_btnBackspace->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->_btnBackspace->Font = (gcnew System::Drawing::Font(L"Consolas", 14, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->_btnBackspace->Location = System::Drawing::Point(328, 3);
			this->_btnBackspace->Name = L"_btnBackspace";
			this->_btnBackspace->Size = System::Drawing::Size(61, 36);
			this->_btnBackspace->TabIndex = 0;
			this->_btnBackspace->TabStop = false;
			this->_btnBackspace->Text = L"←";
			this->_btnBackspace->UseVisualStyleBackColor = true;
			this->_btnBackspace->Click += gcnew System::EventHandler(this, &FrmCalculator::_btnBackspace_Click);
			// 
			// _btnModulo
			// 
			this->_btnModulo->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->_btnModulo->Font = (gcnew System::Drawing::Font(L"Consolas", 14, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->_btnModulo->Location = System::Drawing::Point(328, 45);
			this->_btnModulo->Name = L"_btnModulo";
			this->_btnModulo->Size = System::Drawing::Size(61, 36);
			this->_btnModulo->TabIndex = 0;
			this->_btnModulo->TabStop = false;
			this->_btnModulo->Text = L"mod";
			this->_btnModulo->UseVisualStyleBackColor = true;
			this->_btnModulo->Click += gcnew System::EventHandler(this, &FrmCalculator::_btnModulo_Click);
			// 
			// _btnCE
			// 
			this->_btnCE->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->_btnCE->Font = (gcnew System::Drawing::Font(L"Consolas", 14, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->_btnCE->Location = System::Drawing::Point(263, 3);
			this->_btnCE->Name = L"_btnCE";
			this->_btnCE->Size = System::Drawing::Size(59, 36);
			this->_btnCE->TabIndex = 0;
			this->_btnCE->TabStop = false;
			this->_btnCE->Text = L"CE";
			this->_btnCE->UseVisualStyleBackColor = true;
			this->_btnCE->Click += gcnew System::EventHandler(this, &FrmCalculator::_btnCE_Click);
			// 
			// _btnInvert
			// 
			this->_btnInvert->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->_btnInvert->Font = (gcnew System::Drawing::Font(L"Consolas", 14, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->_btnInvert->Location = System::Drawing::Point(133, 45);
			this->_btnInvert->Name = L"_btnInvert";
			this->_btnInvert->Size = System::Drawing::Size(59, 36);
			this->_btnInvert->TabIndex = 0;
			this->_btnInvert->TabStop = false;
			this->_btnInvert->Text = L"^-1";
			this->_btnInvert->UseVisualStyleBackColor = true;
			this->_btnInvert->Click += gcnew System::EventHandler(this, &FrmCalculator::_btnInvert_Click);
			// 
			// _btnExp
			// 
			this->_btnExp->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->_btnExp->Font = (gcnew System::Drawing::Font(L"Consolas", 14, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->_btnExp->Location = System::Drawing::Point(263, 45);
			this->_btnExp->Name = L"_btnExp";
			this->_btnExp->Size = System::Drawing::Size(59, 36);
			this->_btnExp->TabIndex = 0;
			this->_btnExp->TabStop = false;
			this->_btnExp->Text = L"exp";
			this->_btnExp->UseVisualStyleBackColor = true;
			this->_btnExp->Click += gcnew System::EventHandler(this, &FrmCalculator::_btnExp_Click);
			// 
			// _btnAbs
			// 
			this->_btnAbs->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->_btnAbs->Font = (gcnew System::Drawing::Font(L"Consolas", 14, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->_btnAbs->Location = System::Drawing::Point(198, 45);
			this->_btnAbs->Name = L"_btnAbs";
			this->_btnAbs->Size = System::Drawing::Size(59, 36);
			this->_btnAbs->TabIndex = 0;
			this->_btnAbs->TabStop = false;
			this->_btnAbs->Text = L"|x|";
			this->_btnAbs->UseVisualStyleBackColor = true;
			this->_btnAbs->Click += gcnew System::EventHandler(this, &FrmCalculator::_btnAbs_Click);
			// 
			// _btnFactorial
			// 
			this->_btnFactorial->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->_btnFactorial->Font = (gcnew System::Drawing::Font(L"Consolas", 14, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->_btnFactorial->Location = System::Drawing::Point(263, 87);
			this->_btnFactorial->Name = L"_btnFactorial";
			this->_btnFactorial->Size = System::Drawing::Size(59, 36);
			this->_btnFactorial->TabIndex = 0;
			this->_btnFactorial->TabStop = false;
			this->_btnFactorial->Text = L"n!";
			this->_btnFactorial->UseVisualStyleBackColor = true;
			this->_btnFactorial->Click += gcnew System::EventHandler(this, &FrmCalculator::_btnFactorial_Click);
			// 
			// _btnRightParenthesis
			// 
			this->_btnRightParenthesis->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->_btnRightParenthesis->Font = (gcnew System::Drawing::Font(L"Consolas", 14, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->_btnRightParenthesis->Location = System::Drawing::Point(198, 87);
			this->_btnRightParenthesis->Name = L"_btnRightParenthesis";
			this->_btnRightParenthesis->Size = System::Drawing::Size(59, 36);
			this->_btnRightParenthesis->TabIndex = 0;
			this->_btnRightParenthesis->TabStop = false;
			this->_btnRightParenthesis->Text = L")";
			this->_btnRightParenthesis->UseVisualStyleBackColor = true;
			this->_btnRightParenthesis->Click += gcnew System::EventHandler(this, &FrmCalculator::_btnRightParenthesis_Click);
			// 
			// _btnLeftParenthesis
			// 
			this->_btnLeftParenthesis->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->_btnLeftParenthesis->Font = (gcnew System::Drawing::Font(L"Consolas", 14, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->_btnLeftParenthesis->Location = System::Drawing::Point(133, 87);
			this->_btnLeftParenthesis->Name = L"_btnLeftParenthesis";
			this->_btnLeftParenthesis->Size = System::Drawing::Size(59, 36);
			this->_btnLeftParenthesis->TabIndex = 0;
			this->_btnLeftParenthesis->TabStop = false;
			this->_btnLeftParenthesis->Text = L"(";
			this->_btnLeftParenthesis->UseVisualStyleBackColor = true;
			this->_btnLeftParenthesis->Click += gcnew System::EventHandler(this, &FrmCalculator::_btnLeftParenthesis_Click);
			// 
			// _btn2ndOn
			// 
			this->_btn2ndOn->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->_btn2ndOn->Font = (gcnew System::Drawing::Font(L"Consolas", 14, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->_btn2ndOn->Location = System::Drawing::Point(68, 3);
			this->_btn2ndOn->Name = L"_btn2ndOn";
			this->_btn2ndOn->Size = System::Drawing::Size(59, 36);
			this->_btn2ndOn->TabIndex = 0;
			this->_btn2ndOn->TabStop = false;
			this->_btn2ndOn->Text = L"2nd";
			this->_btn2ndOn->UseVisualStyleBackColor = true;
			this->_btn2ndOn->Click += gcnew System::EventHandler(this, &FrmCalculator::_btn2ndOn_Click);
			// 
			// _btnPow
			// 
			this->_btnPow->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->_btnPow->Font = (gcnew System::Drawing::Font(L"Consolas", 14, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->_btnPow->Location = System::Drawing::Point(68, 129);
			this->_btnPow->Name = L"_btnPow";
			this->_btnPow->Size = System::Drawing::Size(59, 36);
			this->_btnPow->TabIndex = 0;
			this->_btnPow->TabStop = false;
			this->_btnPow->Text = L"x^y";
			this->_btnPow->UseVisualStyleBackColor = true;
			this->_btnPow->Click += gcnew System::EventHandler(this, &FrmCalculator::_btnPow_Click);
			// 
			// _btnE
			// 
			this->_btnE->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->_btnE->Font = (gcnew System::Drawing::Font(L"Consolas", 14, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->_btnE->Location = System::Drawing::Point(198, 3);
			this->_btnE->Name = L"_btnE";
			this->_btnE->Size = System::Drawing::Size(59, 36);
			this->_btnE->TabIndex = 0;
			this->_btnE->TabStop = false;
			this->_btnE->Text = L"e";
			this->_btnE->UseVisualStyleBackColor = true;
			this->_btnE->Click += gcnew System::EventHandler(this, &FrmCalculator::_btnE_Click);
			// 
			// _btnPi
			// 
			this->_btnPi->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->_btnPi->Font = (gcnew System::Drawing::Font(L"Consolas", 14, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->_btnPi->Location = System::Drawing::Point(133, 3);
			this->_btnPi->Name = L"_btnPi";
			this->_btnPi->Size = System::Drawing::Size(59, 36);
			this->_btnPi->TabIndex = 0;
			this->_btnPi->TabStop = false;
			this->_btnPi->Text = L"π";
			this->_btnPi->UseVisualStyleBackColor = true;
			this->_btnPi->Click += gcnew System::EventHandler(this, &FrmCalculator::_btnPi_Click);
			// 
			// _btn2ndOff
			// 
			this->_btn2ndOff->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->_btn2ndOff->Font = (gcnew System::Drawing::Font(L"Consolas", 14, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->_btn2ndOff->Location = System::Drawing::Point(3, 3);
			this->_btn2ndOff->Name = L"_btn2ndOff";
			this->_btn2ndOff->Size = System::Drawing::Size(59, 36);
			this->_btn2ndOff->TabIndex = 0;
			this->_btn2ndOff->TabStop = false;
			this->_btn2ndOff->Text = L"1st";
			this->_btn2ndOff->UseVisualStyleBackColor = true;
			this->_btn2ndOff->Click += gcnew System::EventHandler(this, &FrmCalculator::_btn2ndOff_Click);
			// 
			// _btnSqrt
			// 
			this->_btnSqrt->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->_btnSqrt->Font = (gcnew System::Drawing::Font(L"Consolas", 14, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->_btnSqrt->Location = System::Drawing::Point(3, 45);
			this->_btnSqrt->Name = L"_btnSqrt";
			this->_btnSqrt->Size = System::Drawing::Size(59, 36);
			this->_btnSqrt->TabIndex = 0;
			this->_btnSqrt->TabStop = false;
			this->_btnSqrt->Text = L"^1/2";
			this->_btnSqrt->UseVisualStyleBackColor = true;
			this->_btnSqrt->Click += gcnew System::EventHandler(this, &FrmCalculator::_btnSqrt_Click);
			// 
			// _btnCubeRoot
			// 
			this->_btnCubeRoot->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->_btnCubeRoot->Font = (gcnew System::Drawing::Font(L"Consolas", 14, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->_btnCubeRoot->Location = System::Drawing::Point(3, 87);
			this->_btnCubeRoot->Name = L"_btnCubeRoot";
			this->_btnCubeRoot->Size = System::Drawing::Size(59, 36);
			this->_btnCubeRoot->TabIndex = 0;
			this->_btnCubeRoot->Text = L"^1/3";
			this->_btnCubeRoot->UseVisualStyleBackColor = true;
			this->_btnCubeRoot->Click += gcnew System::EventHandler(this, &FrmCalculator::_btnCubeRoot_Click);
			// 
			// _btn2ToX
			// 
			this->_btn2ToX->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->_btn2ToX->Font = (gcnew System::Drawing::Font(L"Consolas", 14, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->_btn2ToX->Location = System::Drawing::Point(3, 171);
			this->_btn2ToX->Name = L"_btn2ToX";
			this->_btn2ToX->Size = System::Drawing::Size(59, 36);
			this->_btn2ToX->TabIndex = 0;
			this->_btn2ToX->Text = L"2^x";
			this->_btn2ToX->UseVisualStyleBackColor = true;
			this->_btn2ToX->Click += gcnew System::EventHandler(this, &FrmCalculator::_btn2ToX_Click);
			// 
			// _btnEToX
			// 
			this->_btnEToX->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->_btnEToX->Font = (gcnew System::Drawing::Font(L"Consolas", 14, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->_btnEToX->Location = System::Drawing::Point(3, 255);
			this->_btnEToX->Name = L"_btnEToX";
			this->_btnEToX->Size = System::Drawing::Size(59, 39);
			this->_btnEToX->TabIndex = 0;
			this->_btnEToX->Text = L"e^x";
			this->_btnEToX->UseVisualStyleBackColor = true;
			this->_btnEToX->Click += gcnew System::EventHandler(this, &FrmCalculator::_btnEToX_Click);
			// 
			// _btnSqr
			// 
			this->_btnSqr->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->_btnSqr->Font = (gcnew System::Drawing::Font(L"Consolas", 14, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->_btnSqr->Location = System::Drawing::Point(68, 45);
			this->_btnSqr->Name = L"_btnSqr";
			this->_btnSqr->Size = System::Drawing::Size(59, 36);
			this->_btnSqr->TabIndex = 0;
			this->_btnSqr->TabStop = false;
			this->_btnSqr->Text = L"x^2";
			this->_btnSqr->UseVisualStyleBackColor = true;
			this->_btnSqr->Click += gcnew System::EventHandler(this, &FrmCalculator::_btnSqr_Click);
			// 
			// _btnCube
			// 
			this->_btnCube->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->_btnCube->Font = (gcnew System::Drawing::Font(L"Consolas", 14, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->_btnCube->Location = System::Drawing::Point(68, 87);
			this->_btnCube->Name = L"_btnCube";
			this->_btnCube->Size = System::Drawing::Size(59, 36);
			this->_btnCube->TabIndex = 0;
			this->_btnCube->TabStop = false;
			this->_btnCube->Text = L"x^3";
			this->_btnCube->UseVisualStyleBackColor = true;
			this->_btnCube->Click += gcnew System::EventHandler(this, &FrmCalculator::_btnCube_Click);
			// 
			// _btn10ToX
			// 
			this->_btn10ToX->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->_btn10ToX->Font = (gcnew System::Drawing::Font(L"Consolas", 14, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->_btn10ToX->Location = System::Drawing::Point(68, 171);
			this->_btn10ToX->Name = L"_btn10ToX";
			this->_btn10ToX->Size = System::Drawing::Size(59, 36);
			this->_btn10ToX->TabIndex = 0;
			this->_btn10ToX->TabStop = false;
			this->_btn10ToX->Text = L"10^x";
			this->_btn10ToX->UseVisualStyleBackColor = true;
			this->_btn10ToX->Click += gcnew System::EventHandler(this, &FrmCalculator::_btn10ToX_Click);
			// 
			// _btnLog
			// 
			this->_btnLog->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->_btnLog->Font = (gcnew System::Drawing::Font(L"Consolas", 14, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->_btnLog->Location = System::Drawing::Point(68, 213);
			this->_btnLog->Name = L"_btnLog";
			this->_btnLog->Size = System::Drawing::Size(59, 36);
			this->_btnLog->TabIndex = 0;
			this->_btnLog->TabStop = false;
			this->_btnLog->Text = L"log";
			this->_btnLog->UseVisualStyleBackColor = true;
			this->_btnLog->Click += gcnew System::EventHandler(this, &FrmCalculator::_btnLog_Click);
			// 
			// _btnLn
			// 
			this->_btnLn->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->_btnLn->Font = (gcnew System::Drawing::Font(L"Consolas", 14, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->_btnLn->Location = System::Drawing::Point(68, 255);
			this->_btnLn->Name = L"_btnLn";
			this->_btnLn->Size = System::Drawing::Size(59, 39);
			this->_btnLn->TabIndex = 0;
			this->_btnLn->TabStop = false;
			this->_btnLn->Text = L"ln";
			this->_btnLn->UseVisualStyleBackColor = true;
			this->_btnLn->Click += gcnew System::EventHandler(this, &FrmCalculator::_btnLn_Click);
			// 
			// button1
			// 
			this->button1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->button1->Font = (gcnew System::Drawing::Font(L"Consolas", 10, System::Drawing::FontStyle::Bold));
			this->button1->Location = System::Drawing::Point(3, 213);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(59, 36);
			this->button1->TabIndex = 0;
			this->button1->TabStop = false;
			this->button1->Text = L"logyx";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &FrmCalculator::button1_Click);
			// 
			// button2
			// 
			this->button2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->button2->Font = (gcnew System::Drawing::Font(L"Consolas", 14, System::Drawing::FontStyle::Bold));
			this->button2->Location = System::Drawing::Point(3, 129);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(59, 36);
			this->button2->TabIndex = 0;
			this->button2->TabStop = false;
			this->button2->Text = L"^1/y";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &FrmCalculator::button2_Click);
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
			this->ClientSize = System::Drawing::Size(408, 439);
			this->Controls->Add(this->_tlpButtons);
			this->Controls->Add(this->tableLayoutPanel2);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->KeyPreview = true;
			this->MaximizeBox = false;
			this->Name = L"FrmCalculator";
			this->Padding = System::Windows::Forms::Padding(8);
			this->Text = L"Epic gamer calculator 69 420";
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &FrmCalculator::FrmCalculator_KeyDown);
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

		ldbl GetCurrentNumDbl()
		{
			return ldbl::Parse(_currentNum);
		}

		// refresh UI for current num
		void UpdateCurrentNumLabel()
		{
			_lblCurrentNum->Text = _currentNum;
		}

		// refresh UI for current expr
		void UpdateCurrentExprLabel()
		{
			_lblCurrentExpr->Text = _currentExpr;
		}

		void SwitchTo2nd()
		{
			_tlpButtons->SuspendLayout();

			_tlpButtons->ColumnStyles[0]->Width = 16.67;
			_tlpButtons->ColumnStyles[1]->Width = 0;

			for each (Control^ control in _tlpButtons->Controls)
			{
				if (_tlpButtons->GetColumn(control) == 0)
					control->Show();
				else if (_tlpButtons->GetColumn(control) == 1)
					control->Hide();
			}

			_tlpButtons->ResumeLayout();
		}

		void SwitchTo1st()
		{
			_tlpButtons->ColumnStyles[0]->Width = 0;
			_tlpButtons->ColumnStyles[1]->Width = 16.67;

			for each (Control ^ control in _tlpButtons->Controls)
			{
				if (_tlpButtons->GetColumn(control) == 0)
					control->Hide();
				else if (_tlpButtons->GetColumn(control) == 1)
					control->Show();
			}
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

		bool GetExprEndsWithOperator()
		{
			// check every operator symbol
			for (int i = 0; i < IOperator::OperatorSymbols->Length; i++)
			{
				if (_currentExpr->EndsWith(IOperator::OperatorSymbols[i] + L" "))
					return true;
			}
		}

#pragma region commands

		void AppendDigit(System::String^ d)
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

		void AppendOperator(System::String^ op)
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
				// if the last input was a closing parenthesis, don't append the current number
				if (_lastToken != TokenTypes::RightParenthesis)
					_currentExpr += _currentNum;

				// always append the operator
				_currentExpr += L" " + op + L" ";
			}

			_lastToken = TokenTypes::Operator;

			UpdateCurrentExprLabel();
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
			_currentExpr += _currentNum + L")";
			_lastToken = TokenTypes::RightParenthesis;
			UpdateCurrentExprLabel();
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

				while (pos > 0 || (_currentExpr[pos] == L' ' && rtParCnt == 0))
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

			_lastToken = TokenTypes::Function;

			UpdateCurrentExprLabel();
		}

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
			// clear entry (current number)
			_currentNum = "0";
			UpdateCurrentNumLabel();
		}

		void Clear()
		{
			_currentExpr = L"";
			_currentNum = L"0";
			_lastToken = TokenTypes::Number;

			UpdateCurrentExprLabel();
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

			Expression^ expr;
			if (Expression::TryParse(_currentExpr, expr))
			{
				try
				{
					_currentNum = expr->Calc().ToString();
					_currentExpr += L" = ";
					_lastToken = TokenTypes::Equals;
				}
				catch (Exception^ ex)
				{
					_currentNum = ex->Message;
				}

				UpdateCurrentNumLabel();
				UpdateCurrentExprLabel();
			}
			else
			{
				MessageBox::Show(L"Parsing failed miserably, whoops");
			}


		}

#pragma endregion

#pragma region event handlers

	protected:

		virtual bool ProcessCmdKey(Message% msg, Keys k) override
		{
			if (k == (Keys::ShiftKey | Keys::Shift)) return true;

			// if the pressed key is backspace, erase the last character
			else if (k == Keys::Back)
				Backspace();

			else if (k == Keys::Delete)
				ClearEntry();

			else if (k == Keys::Escape)
				Clear();

			else if (k == Keys::Enter || k == Keys::Return)
				Calc();

			else if (k == Keys::Multiply || (k == (Keys::D8 | Keys::Shift)))
				AppendOperator(L"*");

			else if (k == Keys::Oemplus || k == Keys::Add || k == (Keys::Oemplus | Keys::Shift))
				AppendOperator(L"+");

			else if (k == Keys::OemMinus || k == Keys::Subtract)
				AppendOperator(L"-");

			else if (k == Keys::Divide)
				AppendOperator(L"/");

			else if (k == (Keys::D1 | Keys::Shift))
				AppendFunction(L"fact");

			else if (k == (Keys::D5 | Keys::Shift))
				AppendOperator(L"mod");

			else if (k == (Keys::D6 | Keys::Shift))
				AppendOperator(L"^");

			else if (k == (Keys::D9 | Keys::Shift))
				AppendLeftParenthesis();

			else if (k == (Keys::D0 | Keys::Shift))
				AppendRightParenthesis();

			// if the pressed key is a number key, append it
			else if (k >= Keys::D0 && k <= Keys::D9)
				AppendDigit(((int)(k - Keys::D0)).ToString());

			// make it also work for numpad keys
			else if (k >= Keys::NumPad0 && k <= Keys::NumPad9)
				AppendDigit(((int)(k - Keys::NumPad0)).ToString());

			// if the pressed key is comma or point, append a decimal point
			else if (k == Keys::OemPeriod || k == Keys::Oemcomma || k == Keys::Decimal)
				AppendPoint();

			return true;
		}

	private:

		// handle all key presses on the form
		System::Void FrmCalculator_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e)
		{
			if (e->KeyCode == Keys::ShiftKey) return;

			// if the pressed key is backspace, erase the last character
			else if (e->KeyCode == Keys::Back)
				Backspace();

			else if (e->KeyCode == Keys::Delete)
				ClearEntry();

			else if (e->KeyCode == Keys::Escape)
				Clear();

			else if (e->KeyCode == Keys::Enter || e->KeyCode == Keys::Return)
				Calc();

			else if (e->KeyCode == Keys::Multiply || (e->KeyCode == Keys::D8 && e->Modifiers.HasFlag(Keys::Shift)))
				AppendOperator(L"*");

			else if (e->KeyCode == Keys::Oemplus || e->KeyCode == Keys::Add)
				AppendOperator(L"+");

			else if (e->KeyCode == Keys::OemMinus || e->KeyCode == Keys::Subtract)
				AppendOperator(L"-");

			else if (e->KeyCode == Keys::Divide)
				AppendOperator(L"/");

			// if the pressed key is a number key, append it
			else if (e->KeyValue >= L'0' && e->KeyValue <= L'9')
				AppendDigit(((wchar_t)e->KeyValue).ToString());

			// make it also work for numpad keys
			else if (e->KeyCode >= Keys::NumPad0 && e->KeyCode <= Keys::NumPad9)
				AppendDigit(((int)(e->KeyCode - Keys::NumPad0)).ToString());

			// if the pressed key is comma or point, append a decimal point
			else if (e->KeyCode == Keys::OemPeriod || e->KeyCode == Keys::Oemcomma)
				AppendPoint();
		}

		System::Void _btnNumber_Click(System::Object^ sender, System::EventArgs^ e)
		{
			// get the clicked button
			Button^ b = safe_cast<Button^>(sender);

			AppendDigit(b->Text);
		}

		System::Void _btnPlusMinus_Click(System::Object^ sender, System::EventArgs^ e)
		{
			// do nothing if the number is 0
			if (_currentNum == "0") return;

			// if the first character is a minus, remove it
			if (_currentNum[0] == '-') _currentNum = _currentNum->Substring(1, _currentNum->Length - 1);

			// otherwise, add a minus to the start of the string
			else _currentNum = L'-' + _currentNum;

			UpdateCurrentNumLabel();
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
			ClearEntry();
		}

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

		System::Void _btnInvert_Click(System::Object^ sender, System::EventArgs^ e)
		{
		}

		System::Void _btnSqrt_Click(System::Object^ sender, System::EventArgs^ e)
		{
		}

		System::Void _btnEquals_Click(System::Object^ sender, System::EventArgs^ e)
		{
			Calc();
		}

		System::Void _btnLeftParenthesis_Click(System::Object^ sender, System::EventArgs^ e)
		{
			AppendLeftParenthesis();
		}

		System::Void _btnRightParenthesis_Click(System::Object^ sender, System::EventArgs^ e)
		{
			AppendRightParenthesis();
		}

		System::Void _btnFactorial_Click(System::Object^ sender, System::EventArgs^ e)
		{
			AppendFunction(L"fact");
		}

		System::Void _btnExp_Click(System::Object^ sender, System::EventArgs^ e)
		{
		}

		System::Void _btnModulo_Click(System::Object^ sender, System::EventArgs^ e)
		{
			AppendOperator("mod");
		}

		System::Void _btnAbs_Click(System::Object^ sender, System::EventArgs^ e)
		{
			AppendFunction("abs");
		}

		System::Void _btnE_Click(System::Object^ sender, System::EventArgs^ e)
		{
			SetCurrentNumToE();
		}

		System::Void _btnPi_Click(System::Object^ sender, System::EventArgs^ e)
		{
			SetCurrentNumToPi();
		}

		System::Void _btn2ndOn_Click(System::Object^ sender, System::EventArgs^ e)
		{
			SwitchTo2nd();
		}

		System::Void _btn2ndOff_Click(System::Object^ sender, System::EventArgs^ e)
		{
			SwitchTo1st();
		}

		System::Void _btnCubeRoot_Click(System::Object^ sender, System::EventArgs^ e)
		{
		}

		System::Void _btn2ToX_Click(System::Object^ sender, System::EventArgs^ e)
		{
		}

		System::Void _btnEToX_Click(System::Object^ sender, System::EventArgs^ e)
		{
		}

		System::Void _btnSqr_Click(System::Object^ sender, System::EventArgs^ e)
		{
		}

		System::Void _btnPow_Click(System::Object^ sender, System::EventArgs^ e)
		{
		}

		System::Void button2_Click(System::Object^ sender, System::EventArgs^ e)
		{
		}

		System::Void button1_Click(System::Object^ sender, System::EventArgs^ e)
		{
		}

		System::Void _btnLn_Click(System::Object^ sender, System::EventArgs^ e)
		{
		}

		System::Void _btnLog_Click(System::Object^ sender, System::EventArgs^ e)
		{
		}

		System::Void _btn10ToX_Click(System::Object^ sender, System::EventArgs^ e)
		{
		}

		System::Void _btnCube_Click(System::Object^ sender, System::EventArgs^ e)
		{
		}

#pragma endregion
	};
}
