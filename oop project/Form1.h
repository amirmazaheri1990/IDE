#pragma once
#include <vector>
#include <string>
#include <cmath>
#include <fstream>
//#include "Editor_variable.h"
//#include "EDit_blocks.h"
#include "Editor_core.h"
using namespace std;

namespace oopproject {

	using namespace System;
	using namespace System::IO;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Text::RegularExpressions;
	using namespace std;
	/// <summary>
	/// Summary for Form1
	///
	/// WARNING: If you change the name of this class, you will need to change the
	///          'Resource File Name' property for the managed resource compiler tool
	///          associated with all .resx files this class depends on.  Otherwise,
	///          the designers will not be able to interact properly with localized
	///          resources associated with this form.
	/// </summary>
	string str1;
	string s = "";
	int IP;
	string address;

	void MarshalString ( String ^ s, string& os );

	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:

		int x;
		int Ipos;
		bool sf;
		Point sg;

	public: 
		int y;





	private: 
		bool m_bPaint;
		String^ m_strLine;
		int m_nContentLength;
		int m_nLineLength;
		int m_nLineStart;
		int m_nLineEnd;
		String^ m_strKeywords;


	private: System::Windows::Forms::MenuStrip^  menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^  fileToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  editToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  commentToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  uncommentToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  tabularToolStripMenuItem;


	private: System::Windows::Forms::ToolStripMenuItem^  openToolStripMenuItem;
	private: System::Windows::Forms::OpenFileDialog^  openFileDialog1;
	private: System::Windows::Forms::Label^  Line_numbers;
	private: System::Windows::Forms::ListBox^  listBox2;
	private: System::Windows::Forms::Button^  button4;
	private: System::Windows::Forms::RichTextBox^  textBox1;
	private: System::Windows::Forms::TabControl^  tabControl1;

	private: System::Windows::Forms::TextBox^  textBox3;
	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::TabPage^  tabPage2;
	private: System::Windows::Forms::ListBox^  listBox1;
	private: System::Windows::Forms::TabPage^  tabPage1;
	private: System::Windows::Forms::ToolStripMenuItem^  saveToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  saveAsToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  intellisenseToolStripMenuItem;
	private: System::Windows::Forms::SaveFileDialog^  saveFileDialog1;
	private: System::Windows::Forms::ToolTip^  toolTip1;








			 int m_nCurSelection;


	public: 
		void ProcessLine()
		{
			// Save the position and make the whole line black
			int nPosition = textBox1->SelectionStart;
			textBox1->SelectionStart = m_nLineStart;
			textBox1->SelectionLength = m_nLineLength;
			textBox1->SelectionColor = Color::Black;

			// Process the keywords
			ProcessRegex(m_strKeywords, Color::Blue);
			// Process numbers
			ProcessRegex("\\b(?:[0-9]*\\.)?[0-9]+\\b", Color::Red);
			ProcessRegex("\"[^\"\\\\\\r\\n]*(?:\\\\.[^\"\\\\\\r\\n]*)*\"", Color::Magenta);
			ProcessRegex("//" + ".*$", Color::LightGreen);

			textBox1->SelectionStart = nPosition;
			textBox1->SelectionLength = 0;
			textBox1->SelectionColor = Color::Black;

			m_nCurSelection = nPosition;
		}

		void ProcessRegex(String^ strRegex, Color color)
		{
			Regex^ regKeywords = gcnew Regex(strRegex, RegexOptions::IgnoreCase | RegexOptions::Compiled);
			Match^ regMatch;

			for (regMatch = regKeywords->Match(m_strLine); regMatch->Success; regMatch = regMatch->NextMatch())
			{
				// Process the words
				int nStart = m_nLineStart + regMatch->Index;
				int nLenght = regMatch->Length;
				textBox1->SelectionStart = nStart;
				textBox1->SelectionLength = nLenght;
				textBox1->SelectionColor = color;
			}

		}

		void ProcessAllLines()
		{
			int cPos = textBox1->SelectionStart;
			m_bPaint = false;

			int nStartPos = 0;
			int i = 0;
			int nOriginalPos = textBox1->SelectionStart;
			while (i < textBox1->Lines->Length)
			{
				m_strLine = textBox1->Lines[i];
				m_nLineStart = nStartPos;
				m_nLineEnd = m_nLineStart + m_strLine->Length;

				ProcessLine();
				i++;

				nStartPos += m_strLine->Length+1;
			}

			m_bPaint = true;
			textBox1->SelectionStart = cPos;
		}

		bool hoverstart;
		Form1(void)
		{
			InitializeComponent();
			//

			m_bPaint = true;
			m_strLine = L"";
			m_nContentLength = 0;
			m_nLineLength = 0;
			m_nLineStart = 0;
			m_nLineEnd = 0;
			m_strKeywords = L"";
			m_nCurSelection = 0;

			array<String^,1>^ keywords = gcnew array<String^,1>{L"int", L"float", L"double", L"char", L"void", L"if", L"for", L"while"};

			for (int i = 0; i < keywords->Length; i++)
			{
				if (i == keywords->Length-1)
					m_strKeywords += "\\b" + keywords[i] + "\\b";
				else
					m_strKeywords += "\\b" + keywords[i] + "\\b|";
			}

			hoverstart=0;
			sf=false;
			//TODO: Add the constructor code herext
			textBox1_TextChanged(textBox1,gcnew EventArgs());

			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}

	protected: 
		Editor_core* editor;
	private: System::ComponentModel::IContainer^  components;
	protected: 


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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Form1::typeid));
			this->toolTip1 = (gcnew System::Windows::Forms::ToolTip(this->components));
			this->listBox2 = (gcnew System::Windows::Forms::ListBox());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->fileToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->openToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->saveToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->saveAsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->editToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->commentToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->uncommentToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->tabularToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->intellisenseToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->Line_numbers = (gcnew System::Windows::Forms::Label());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::RichTextBox());
			this->tabControl1 = (gcnew System::Windows::Forms::TabControl());
			this->tabPage1 = (gcnew System::Windows::Forms::TabPage());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->tabPage2 = (gcnew System::Windows::Forms::TabPage());
			this->listBox1 = (gcnew System::Windows::Forms::ListBox());
			this->saveFileDialog1 = (gcnew System::Windows::Forms::SaveFileDialog());
			this->menuStrip1->SuspendLayout();
			this->tabControl1->SuspendLayout();
			this->tabPage1->SuspendLayout();
			this->SuspendLayout();
			// 
			// toolTip1
			// 
			this->toolTip1->AutomaticDelay = 0;
			this->toolTip1->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->toolTip1->UseAnimation = false;
			this->toolTip1->UseFading = false;
			// 
			// listBox2
			// 
			this->listBox2->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->listBox2->FormattingEnabled = true;
			this->listBox2->HorizontalScrollbar = true;
			this->listBox2->Location = System::Drawing::Point(608, 51);
			this->listBox2->Name = L"listBox2";
			this->listBox2->Size = System::Drawing::Size(217, 290);
			this->listBox2->TabIndex = 8;
			this->toolTip1->SetToolTip(this->listBox2, L"METHOD GENERATION BOX");
			this->listBox2->DoubleClick += gcnew System::EventHandler(this, &Form1::listBox2_DoubleClick);
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {this->fileToolStripMenuItem, 
				this->editToolStripMenuItem});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(845, 24);
			this->menuStrip1->TabIndex = 7;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// fileToolStripMenuItem
			// 
			this->fileToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {this->openToolStripMenuItem, 
				this->saveToolStripMenuItem, this->saveAsToolStripMenuItem});
			this->fileToolStripMenuItem->Name = L"fileToolStripMenuItem";
			this->fileToolStripMenuItem->Size = System::Drawing::Size(37, 20);
			this->fileToolStripMenuItem->Text = L"File";
			// 
			// openToolStripMenuItem
			// 
			this->openToolStripMenuItem->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"openToolStripMenuItem.Image")));
			this->openToolStripMenuItem->Name = L"openToolStripMenuItem";
			this->openToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::O));
			this->openToolStripMenuItem->Size = System::Drawing::Size(195, 22);
			this->openToolStripMenuItem->Text = L"Open";
			this->openToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::openToolStripMenuItem_Click);
			// 
			// saveToolStripMenuItem
			// 
			this->saveToolStripMenuItem->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"saveToolStripMenuItem.Image")));
			this->saveToolStripMenuItem->Name = L"saveToolStripMenuItem";
			this->saveToolStripMenuItem->ShortcutKeyDisplayString = L"";
			this->saveToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::S));
			this->saveToolStripMenuItem->Size = System::Drawing::Size(195, 22);
			this->saveToolStripMenuItem->Text = L"Save";
			this->saveToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::saveToolStripMenuItem_Click);
			// 
			// saveAsToolStripMenuItem
			// 
			this->saveAsToolStripMenuItem->Name = L"saveAsToolStripMenuItem";
			this->saveAsToolStripMenuItem->ShortcutKeyDisplayString = L"";
			this->saveAsToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>(((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::Shift) 
				| System::Windows::Forms::Keys::S));
			this->saveAsToolStripMenuItem->Size = System::Drawing::Size(195, 22);
			this->saveAsToolStripMenuItem->Text = L"Save As...";
			this->saveAsToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::saveAsToolStripMenuItem_Click);
			// 
			// editToolStripMenuItem
			// 
			this->editToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {this->commentToolStripMenuItem, 
				this->uncommentToolStripMenuItem, this->tabularToolStripMenuItem, this->intellisenseToolStripMenuItem});
			this->editToolStripMenuItem->Name = L"editToolStripMenuItem";
			this->editToolStripMenuItem->Size = System::Drawing::Size(39, 20);
			this->editToolStripMenuItem->Text = L"Edit";
			// 
			// commentToolStripMenuItem
			// 
			this->commentToolStripMenuItem->Name = L"commentToolStripMenuItem";
			this->commentToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::C));
			this->commentToolStripMenuItem->Size = System::Drawing::Size(197, 22);
			this->commentToolStripMenuItem->Text = L"Comment";
			this->commentToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::commentToolStripMenuItem_Click);
			// 
			// uncommentToolStripMenuItem
			// 
			this->uncommentToolStripMenuItem->Name = L"uncommentToolStripMenuItem";
			this->uncommentToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::U));
			this->uncommentToolStripMenuItem->Size = System::Drawing::Size(197, 22);
			this->uncommentToolStripMenuItem->Text = L"Uncomment";
			this->uncommentToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::uncommentToolStripMenuItem_Click);
			// 
			// tabularToolStripMenuItem
			// 
			this->tabularToolStripMenuItem->Name = L"tabularToolStripMenuItem";
			this->tabularToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::F));
			this->tabularToolStripMenuItem->Size = System::Drawing::Size(197, 22);
			this->tabularToolStripMenuItem->Text = L"Tabular";
			this->tabularToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::tabularToolStripMenuItem_Click);
			// 
			// intellisenseToolStripMenuItem
			// 
			this->intellisenseToolStripMenuItem->Name = L"intellisenseToolStripMenuItem";
			this->intellisenseToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::Space));
			this->intellisenseToolStripMenuItem->Size = System::Drawing::Size(197, 22);
			this->intellisenseToolStripMenuItem->Text = L"Intellisense";
			this->intellisenseToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::intellisenseToolStripMenuItem_Click);
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"openFileDialog1";
			// 
			// Line_numbers
			// 
			this->Line_numbers->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->Line_numbers->BackColor = System::Drawing::SystemColors::ControlDark;
			this->Line_numbers->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(178)));
			this->Line_numbers->ForeColor = System::Drawing::SystemColors::ControlText;
			this->Line_numbers->Location = System::Drawing::Point(10, 54);
			this->Line_numbers->Name = L"Line_numbers";
			this->Line_numbers->Size = System::Drawing::Size(27, 322);
			this->Line_numbers->TabIndex = 5;
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(608, 347);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(217, 27);
			this->button4->TabIndex = 9;
			this->button4->Text = L"Generate";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &Form1::button4_Click);
			// 
			// textBox1
			// 
			this->textBox1->AcceptsTab = true;
			this->textBox1->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->textBox1->Location = System::Drawing::Point(40, 51);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(562, 322);
			this->textBox1->TabIndex = 4;
			this->textBox1->Text = L"//jhg\r\nint k;for(){ if()  }";
			this->textBox1->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &Form1::textBox1_KeyDown);
			this->textBox1->VScroll += gcnew System::EventHandler(this, &Form1::textBox1_VScroll);
			this->textBox1->MouseEnter += gcnew System::EventHandler(this, &Form1::textBox1_MouseEnter);
			this->textBox1->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::textBox1_MouseMove);
			this->textBox1->MouseHover += gcnew System::EventHandler(this, &Form1::textBox1_MouseHover);
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &Form1::textBox1_TextChanged);
			// 
			// tabControl1
			// 
			this->tabControl1->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->tabControl1->Controls->Add(this->tabPage1);
			this->tabControl1->Controls->Add(this->tabPage2);
			this->tabControl1->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->tabControl1->Location = System::Drawing::Point(40, 392);
			this->tabControl1->Name = L"tabControl1";
			this->tabControl1->SelectedIndex = 0;
			this->tabControl1->Size = System::Drawing::Size(562, 137);
			this->tabControl1->TabIndex = 10;
			// 
			// tabPage1
			// 
			this->tabPage1->BackColor = System::Drawing::SystemColors::ControlLight;
			this->tabPage1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->tabPage1->Controls->Add(this->textBox3);
			this->tabPage1->Controls->Add(this->textBox2);
			this->tabPage1->Location = System::Drawing::Point(4, 22);
			this->tabPage1->Name = L"tabPage1";
			this->tabPage1->Padding = System::Windows::Forms::Padding(3);
			this->tabPage1->Size = System::Drawing::Size(554, 111);
			this->tabPage1->TabIndex = 0;
			this->tabPage1->Text = L"Console";
			// 
			// textBox3
			// 
			this->textBox3->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->textBox3->Location = System::Drawing::Point(3, 6);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(548, 20);
			this->textBox3->TabIndex = 1;
			// 
			// textBox2
			// 
			this->textBox2->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->textBox2->Location = System::Drawing::Point(3, 30);
			this->textBox2->Multiline = true;
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(548, 80);
			this->textBox2->TabIndex = 0;
			// 
			// tabPage2
			// 
			this->tabPage2->Location = System::Drawing::Point(4, 22);
			this->tabPage2->Name = L"tabPage2";
			this->tabPage2->Padding = System::Windows::Forms::Padding(3);
			this->tabPage2->Size = System::Drawing::Size(554, 111);
			this->tabPage2->TabIndex = 1;
			this->tabPage2->Text = L"Watch";
			this->tabPage2->UseVisualStyleBackColor = true;
			// 
			// listBox1
			// 
			this->listBox1->FormattingEnabled = true;
			this->listBox1->Location = System::Drawing::Point(208, 128);
			this->listBox1->Name = L"listBox1";
			this->listBox1->Size = System::Drawing::Size(183, 147);
			this->listBox1->TabIndex = 6;
			this->listBox1->Visible = false;
			this->listBox1->SelectedIndexChanged += gcnew System::EventHandler(this, &Form1::listBox1_SelectedIndexChanged);
			this->listBox1->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &Form1::listBox1_KeyDown);
			// 
			// Form1
			// 
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::None;
			this->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->BackColor = System::Drawing::SystemColors::ControlDark;
			this->ClientSize = System::Drawing::Size(845, 541);
			this->Controls->Add(this->listBox1);
			this->Controls->Add(this->tabControl1);
			this->Controls->Add(this->menuStrip1);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->listBox2);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->Line_numbers);
			this->MainMenuStrip = this->menuStrip1;
			this->MaximizeBox = false;
			this->Name = L"Form1";
			this->Text = L"Form1";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->tabControl1->ResumeLayout(false);
			this->tabPage1->ResumeLayout(false);
			this->tabPage1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: System::Void textBox1_TextChanged(System::Object^  sender, System::EventArgs^  e) {
				 /*int c = textBox1->SelectionStart;
				 Regex^ r = gcnew Regex("\\n");
				 array<String^,1>^ lines = r->Split(textBox1->Text); 
				 textBox1->Clear();
				 for(int i = 0; i < lines->Length; i++)
					{
					ParseLine(lines[i]);
					} 
					textBox1->SelectionStart = c;
					textBox1->Text = textBox1->Text->Trim();*/

				 /* ******* */
				 m_nContentLength = textBox1->TextLength;

				 int te = textBox1->SelectionStart;
				 int nCurrentSelectionStart = textBox1->SelectionStart;
				 int nCurrentSelectionLength = textBox1->SelectionLength;

				 m_bPaint = false;

				 // Find the start of the current line.
				 m_nLineStart = nCurrentSelectionStart;
				 while ((m_nLineStart > 0) && (textBox1->Text[m_nLineStart - 1] != '\n'))
					 m_nLineStart--;
				 // Find the end of the current line.
				 m_nLineEnd = nCurrentSelectionStart;
				 while ((m_nLineEnd < textBox1->Text->Length) && (textBox1->Text[m_nLineEnd] != '\n'))
					 m_nLineEnd++;
				 // Calculate the length of the line.
				 m_nLineLength = m_nLineEnd - m_nLineStart;
				 // Get the current line.
				 m_strLine = textBox1->Text->Substring(m_nLineStart, m_nLineLength);

				 // Process this line.
				 ProcessLine();

				 m_bPaint = true;

				 /* ******* */
				 int length = 
					 hoverstart=1;				
				 str1="";
				 String^ s1="";
				 s1=this->textBox1->Text->ToString();
				 for(int i=0;i<this->textBox1->TextLength;i++){
					 str1+=s1[i];
				 }
				 delete editor;
				 Numbering();
				 textBox1->Focus();
				 textBox1->Select(te, 0);
				 textBox1->SelectionStart = te;
				 editor=new Editor_core(str1);
				 this->listBox2->Items->Clear();
				 for(int i=0;i<this->editor->called_methods.size();i++){
					 string  amirmaz="";
					 if (this->editor->called_methods[i]->function==NULL){
						 amirmaz=this->editor->called_methods[i]->myreturn+" "+this->editor->called_methods[i]->word->name+" "+"("+" ";
						 for(int j=0;j<this->editor->called_methods[i]->parantes->variables.size();j++){
							 amirmaz+=" "+this->editor->called_methods[i]->parantes->variables[j]->type+" "
								 +"a";
							 amirmaz.push_back(48+j);
							 amirmaz.push_back(' ');
							 amirmaz.push_back(',');
						 }
						 amirmaz[amirmaz.length()-1]=')';
						 amirmaz+=" { return ";
						 if(this->editor->called_methods[i]->myreturn=="int"||this->editor->called_methods[i]->myreturn=="float"||this->editor->called_methods[i]->myreturn=="double"){
							amirmaz+="1";
						 }
						 else if(this->editor->called_methods[i]->myreturn=="char"){
							amirmaz+="'A'";
						 }
						 amirmaz.push_back(';');
						 amirmaz+=" }";
						 amirmaz+="\r\n";
						 String^ mystr= gcnew String(amirmaz.c_str());
						 this->listBox2->Items->Add(mystr);
					 }
				 }
			 }
	private: System::Void textBox1_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) {


			 }
	private: System::Void textBox1_MouseHover(System::Object^  sender, System::EventArgs^  e) {
				
			 }
	private: System::Void textBox1_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
				 x=e->X;
				 y=e->Y;
				  for(int k=-1;k<2;k++){
					 int index=this->textBox1->GetCharIndexFromPosition(Point(x,y));
					 index+=k;
					 if (index==this->textBox1->Text->Length-1) continue;
					 bool found=0;
					 EDit_blocks* block=NULL;
					 string name="";
					 String^ s1="";
					 Editor_variable* variable=NULL;
					 if(index<this->textBox1->Text->Length-1&&hoverstart==1){///block ra miabim
						 for(int i=0;i<this->editor->blocks.size();i++){
							 if(this->editor->blocks[i]->getstart_b()<index&&this->editor->blocks[i]->getend_b()>index){
								 block=this->editor->blocks[i];
								 break;
							 }
						 }

						 for(int i=0;i<this->editor->words.size();i++){///kalame ra miabim va mifahmim be kodam variable shabih ast....
							 if(this->editor->words[i]->getstartindex()<=index&&this->editor->words[i]->getendindex()>=index){
								 for(int j=0;j<this->editor->variable.size();j++){
									 if(((this->editor->words[i]->block!=NULL&&this->editor->variable[j]->block!=NULL&&
										 (this->editor->words[i]->block->getstart_b()>=this->editor->variable[j]->block->getstart_b()
										 &&this->editor->words[i]->block->getend_b()<=this->editor->variable[j]->block->getend_b()))
										 ||this->editor->words[i]->block==this->editor->variable[j]->block)
										 &&this->editor->words[i]->name==this->editor->variable[j]->name){
										 variable=this->editor->variable[j];
										 break;
									 }
								 }
								 break;
							 }
						 }	

						 if(variable!=NULL){
							 string sadjad = variable->type+" "+variable->name;
							 s1=gcnew String(sadjad.c_str());
							 if(sqrt(pow(textBox1->MousePosition.X - sg.X, 2.0) + pow(textBox1->MousePosition.Y - sg.Y, 2.0)) > 2)
								this->toolTip1->Show(s1,this->textBox1,x,y);
							 found=1;
							 sg = Point(textBox1->MousePosition);
							 break;
						 }

						 if(found==0){
							 for(int i=0;i<this->editor->words.size();i++){
								 if(this->editor->words[i]->getstartindex()<=index&&this->editor->words[i]->getendindex()>=index){
									 for(int j=0;j<this->editor->variable.size();j++){
										 if(this->editor->variable[j]->block==NULL&&this->editor->words[i]->name==this->editor->variable[j]->name){
											 variable=this->editor->variable[j];
											 break;
										 }
									 }
									 break;
								 }
							 }	
							 if(variable!=NULL){
								 string sadjad = variable->type+" "+variable->name;
								 s1=gcnew String(sadjad.c_str());
								 if(sqrt(pow(textBox1->MousePosition.X - sg.X, 2.0) + pow(textBox1->MousePosition.Y - sg.Y, 2.0)) > 2)
									this->toolTip1->Show(s1,this->textBox1,x,y);
								 found=1;
								 sg = Point(textBox1->MousePosition);
								 break;
							 }
						 }

					 }
					 if(variable==NULL&&hoverstart==1){
						 for(int i=0;i<this->editor->functions.size();i++){
							 if(hoverstart==1&&this->editor->functions[i]->word->getstartindex()<=index&&this->editor->functions[i]->word->getendindex()>=index){
								 string amirmaz=this->editor->functions[i]->returntype->type+" "+this->editor->functions[i]->word->name+"("+" ";
								 for(int j=0;j<this->editor->functions[i]->parantes->variables.size();j++){
									 amirmaz+=" "+this->editor->functions[i]->parantes->variables[j]->type+" "+this->editor->functions[i]->parantes->variables[j]->name+",";
								 }
								 amirmaz[amirmaz.length() - 1] = ')';
								 s1=gcnew String(amirmaz.c_str());
								 found=1;
								 if(sqrt(pow(textBox1->MousePosition.X - sg.X, 2.0) + pow(textBox1->MousePosition.Y - sg.Y, 2.0)) > 2)
									 this->toolTip1->Show(s1,this->textBox1,x,y);
								 sg = Point(textBox1->MousePosition);
								 break;
							 }
						 }
						 if(found==0){
							 for(int i=0;i<this->editor->called_methods.size();i++){
								 if(this->editor->called_methods[i]->function!=NULL){
									 if(this->editor->called_methods[i]->word->getstartindex()<=index&&this->editor->called_methods[i]->word->getendindex()>=index){
										 string amirmaz=this->editor->called_methods[i]->function->returntype->type+" "+this->editor->called_methods[i]->function->word->name+" "+"("+" ";
										 for(int j=0;j<this->editor->called_methods[i]->function->parantes->variables.size();j++){
											 amirmaz+=" "+this->editor->called_methods[i]->function->parantes->variables[j]->type+" "+this->editor->called_methods[i]->function->parantes->variables[j]->name+",";
										 }											
										 amirmaz[amirmaz.length() -1]= ')';
										 s1= gcnew String(amirmaz.c_str());
										 found=1;
										 if(sqrt(pow(textBox1->MousePosition.X - sg.X, 2.0) + pow(textBox1->MousePosition.Y - sg.Y, 2.0)) > 2)										
											 this->toolTip1->Show(s1,this->textBox1,x,y);
										 sg=Point(textBox1->MousePosition);
										 break;

									 }
								 }
							 }	
						 }
					 }
					 if(found==0&&hoverstart==1){
						 for(int i=0;i<editor->paranteses.size();i++){
							 for(int j=0;j<editor->paranteses[i]->variables.size();j++){
								 if(index>=editor->paranteses[i]->variables[j]->getstartindex()&&index<=editor->paranteses[i]->variables[j]->getendindex()){
									 string amirmaz=editor->paranteses[i]->variables[j]->type+" "+editor->paranteses[i]->variables[j]->name;
									 s1=gcnew String(amirmaz.c_str());
									 found=1;
									 if(sqrt(pow(textBox1->MousePosition.X - sg.X, 2.0) + pow(textBox1->MousePosition.Y - sg.Y, 2.0)) > 2)
										this->toolTip1->Show(s1,this->textBox1,x,y);
									 sg=Point(textBox1->MousePosition);
									 break;
								 }
							 }
						 }
					 }
				 }
				 if(sqrt(pow(textBox1->MousePosition.X - sg.X, 2.0) + pow(textBox1->MousePosition.Y - sg.Y, 2.0)) > 10){
					 toolTip1->Hide(this->textBox1);
				 }
			 }
	private: System::Void textBox1_MouseEnter(System::Object^  sender, System::EventArgs^  e) {
				 //this->toolTip1->Hide(this->textBox1);
			 }

	private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) {
			 }

	private:
		void Numbering()
		{
			Point c(0,0);
			int lStart = textBox1->GetLineFromCharIndex(textBox1->GetCharIndexFromPosition(c));
			c.X = textBox1->Width;
			c.Y = textBox1->Height;
			int lEnd = textBox1->GetLineFromCharIndex(textBox1->GetCharIndexFromPosition(c));

			c = textBox1->GetPositionFromCharIndex(textBox1->GetCharIndexFromPosition(c));
			Line_numbers->Text = "";
			for(int i = lStart; i <= lEnd +1; i++)
			{
				Line_numbers->Text += i + 1 + "\n";
			}
		}
	private: System::Void textBox1_VScroll(System::Object^  sender, System::EventArgs^  e) {
				 Numbering();
			 }
	private: System::Void listBox1_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
							 int j;
			 if( listBox1->Visible == true && e->KeyCode == Keys::Enter )
			 {
				//string s = "";
				//for( j = 0; j < editor->words.size(); j++ )
				//{
					//MessageBox::Show(gcnew String(editor->words[j]->getendindex().ToString()));
					//MessageBox::Show(gcnew String(textBox1->SelectionStart.ToString()));
				//	if( textBox1->SelectionStart == editor->words[j]->getendindex()+1 )
				//	{
				//		 s = editor->words[j]->name;
				//		 break;
				//	}
				//}
				//for( int k = 0; k < s.size(); k++ )
				//{
				//	str1.erase( str1.begin() + editor->words[j]->getstartindex() );
				//}
				 int a = s.size();
				 int b = IP;
				 string ss = str1;
				if( s.size() != 0 )
					str1.erase(IP - s.size(), s.size() );
				ss = str1;
				listBox1->Visible = false;
				IP = IP - s.size();
				textBox1->SelectionStart = IP; 
				 //str1.insert( editor->words[j]->getstartindex(), listBox1->SelectedItem->ToString() );
			 	 textBox1->Text = (gcnew String(str1.c_str()));
				 textBox1->SelectionStart = IP;
				 textBox1->Text = textBox1->Text->Insert(textBox1->SelectionStart , listBox1->SelectedItem->ToString());
				 IP = IP + listBox1->SelectedItem->ToString()->Length; 
				 textBox1->Focus();
				 textBox1->SelectionStart = IP;
				 this->tabularToolStripMenuItem->PerformClick();
			 }
			 }
	private: System::Void textBox1_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
			 if( listBox1->Visible == true && (e->KeyCode == Keys::Down || e->KeyCode == Keys::Up ))
			 {
				 listBox1->SelectedIndex = 0;
				 listBox1->Focus();
			 }
			 else
			 {
			 listBox1->Visible = false;
			 }
			 }
			 /*private: System::Void listBox1_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			 }*/
	private: System::Void button4_Click(System::Object^  sender, System::EventArgs^  e) {			
				 if(this->listBox2->SelectedIndex!=-1){	
					 String^ amirmaz=this->listBox2->SelectedItem->ToString();
					 String^ amirmaz2=this->textBox1->Text->ToString();
					 amirmaz=amirmaz+amirmaz2;
					 this->textBox1->Text=amirmaz;
					 textBox1_TextChanged(textBox1,gcnew EventArgs());
					 this->tabularToolStripMenuItem->PerformClick();
				 }		 
			 }
			 /*private: System::Void Line_numbers_Click(System::Object^  sender, System::EventArgs^  e) {
			 }*/
	private: System::Void commentToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
				 int te = textBox1->SelectionStart;
				 int from = textBox1->GetLineFromCharIndex(textBox1->SelectionStart);
				 int to = textBox1->GetLineFromCharIndex(textBox1->SelectionStart + textBox1->SelectionLength );
				 int tabs = editor->Comment_multiline(from, to, str1);
				 textBox1->Text = (gcnew String(str1.c_str()));
				 textBox1->SelectionStart = te + tabs;
				 ProcessAllLines();
			 }
	private: System::Void uncommentToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 int te = textBox1->SelectionStart, tl = textBox1->SelectionLength;
			 int tabs = 0;
			 if( str1[te] == '/' && str1[te + 1] == '*' && str1[te + tl - 1] == '/' && str1[te + tl - 2] == '*' )
			 {
				 //str1.erase( str1.begin() + te + tl - 1 );
				 //str1[te + tl - 2] = ' ';
				 //str1.erase( str1.begin() + te + tl - 2 );
				 str1.erase(te + tl - 2 ,2);
				 //MessageBox::Show(((char)str1[te+tl-2]).ToString());
				 str1.erase( str1.begin() + te + 1 );
				 str1.erase( str1.begin() + te );
			 }
			 else
			 {
				 int from = textBox1->GetLineFromCharIndex(textBox1->SelectionStart);
			 	 int to = textBox1->GetLineFromCharIndex(textBox1->SelectionStart + textBox1->SelectionLength);
				 //int tabs = 0;
				editor->Uncomment_multiline(from, to, str1);
			 }
			 textBox1->Text = (gcnew String(str1.c_str()));
			 textBox1->SelectionStart = te;
			 ProcessAllLines();
				 //int te = textBox1->SelectionStart;
				 //int from = textBox1->GetLineFromCharIndex(textBox1->SelectionStart);
				 //int to = textBox1->GetLineFromCharIndex(textBox1->SelectionStart + textBox1->SelectionLength);
				 ////int tabs = 0;
				 //editor->Uncomment_multiline(from, to, str1);
				 //textBox1->Text = (gcnew String(str1.c_str()));
				 //textBox1->SelectionStart = te;
				 //ProcessAllLines();
			 }

	private: System::Void tabularToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
				 int te = textBox1->SelectionStart;
				 int tabs = editor->tabular(str1);
				 textBox1->Text = (gcnew String(str1.c_str()));
				 if(te+tabs>-1)
					textBox1->SelectionStart = te + tabs;
				 ProcessAllLines();	
			 }
private: System::Void openToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 openFileDialog1->Filter = "C files|*.c|All Files|*.*";
			 openFileDialog1->FileName = "";
			 if(openFileDialog1->ShowDialog()==System::Windows::Forms::DialogResult::OK);				 
			 {
				 this->textBox1->Text="";
				 StreamReader^ mystr = gcnew StreamReader(openFileDialog1->OpenFile());
				 string fileName;
				 MarshalString(openFileDialog1->FileName,fileName);
				 address=fileName;
				 try{
					 this->textBox1->Text = mystr->ReadToEnd();
					 mystr->Close();
				 }
				 catch(Exception^ e){
					 MessageBox::Show("OH SHIT!!!!","OPEN FILE ERROR");
				 }
			 }
			 this->tabularToolStripMenuItem->PerformClick();
		 }			 
private: System::Void i(System::Object^  sender, System::ComponentModel::CancelEventArgs^  e) {
		 }
private: System::Void listBox2_DoubleClick(System::Object^  sender, System::EventArgs^  e) {
			 button4->PerformClick();
		 }
private: System::Void intellisenseToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {

			 listBox1->Items->Clear();
			 s="";
			 IP = textBox1->SelectionStart;
			 //int gs, ge;
			 for( int j = 0; j < editor->words.size(); j++ )
			 {
				 //MessageBox::Show(gcnew String(editor->variable[j]->getendindex().ToString()));
				 //MessageBox::Show(gcnew String(textBox1->SelectionStart.ToString()));
				 if( textBox1->SelectionStart == editor->words[j]->getendindex() + 1 )
				 {
					 s = editor->words[j]->name;
					 //MessageBox::Show( gcnew String(s.c_str()) );
					 break;
				 }
			 }
			 ////////////////////////////////////////////////////////////////////////////////////
			 ///////////////////////////////////////////////////////////////////////////////////
			 bool amirmaz_found=1;			
			 for(int amir=0;amir<editor->functions.size();amir++){
				 amirmaz_found=1;
				 if(s.size()==0){ 
					 this->listBox1->Items->Add(gcnew String(editor->functions[amir]->word->name.c_str()));
					 amirmaz_found=0;
				 }			
				 for(int amirmaz=0;amirmaz<s.size();amirmaz++){
					 if(editor->functions[amir]->word->name[amirmaz]!=s[amirmaz]){
						 amirmaz_found=0;
						 break;
					 }
				 }
				 if (amirmaz_found==1){
						 this->listBox1->Items->Add(gcnew String(editor->functions[amir]->word->name.c_str()));
					 }
			 }
			 //////////////////////////////////////////////////////////////////////////////////
			 //////////////////////////////////////////////////////////////////////////////////
			 EDit_blocks* intelBlock = new EDit_blocks(0,0);
			 for( int i = 0; i < editor->blocks.size(); i++ )
			 {
				 if( editor->blocks[i]->getend_b() >= IP && 
					 editor->blocks[i]->getstart_b() <= IP )
				 {
					 intelBlock = editor->blocks[i];
					 break;
				 }
			 }
			 for( int j = 0; j < editor->variable.size() ; j++ )
			 {
				 if( (editor->variable[j]->block == NULL || editor->variable[j]->block == intelBlock
					 || (editor->variable[j]->block->getstart_b() == 0 && editor->variable[j]->block->getend_b() == 0)) )
				 {
						 if( s == "" )
							 listBox1->Items->Add( gcnew String(editor->variable[j]->name.c_str()) );
						 else if( s == editor->variable[j]->name )
							 continue;
						 else
						 {
							 for( int k = 0; k < s.size(); k++ )
							 {
								 if( s[k] != editor->variable[j]->name[k] )
									 break;
								 if( k == s.size() - 1 )
									 listBox1->Items->Add( gcnew String(editor->variable[j]->name.c_str()) );
							 }
						 }
				 }
			 }
			 //listBox1->SelectedItem->ToString();
			 //listBox1->Items->Add(L"Sadjad");
			 listBox1->Top = textBox1->Top + textBox1->GetPositionFromCharIndex(textBox1->SelectionStart).Y + 15;
			 listBox1->Left = textBox1->Left + textBox1->GetPositionFromCharIndex(textBox1->SelectionStart).X;
			 listBox1->Visible = true;
			 


		 }

private: System::Void saveAsToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 saveFileDialog1->Filter="c files (*.c)|*.c|All files (*.*)|*.*";
			 saveFileDialog1->FilterIndex=1;
			 if ( saveFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK){
				string fileName;
				MarshalString(saveFileDialog1->FileName,fileName);
				address=fileName;
				ofstream out(fileName.c_str(),ios::out);
				out << str1;
				out.close();
			 }


		 }


private: System::Void saveToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 if(address=="")
				 saveAsToolStripMenuItem->PerformClick();
			 else
			 {
				ofstream out(address.c_str(),ios::out);
				out << str1;
				out.close();
			 }
		 }
private: System::Void listBox1_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
		 }
};
void MarshalString ( String ^ s, string& os ) {
	using namespace Runtime::InteropServices;
	const char* chars = (const char*)(Marshal::StringToHGlobalAnsi(s)).ToPointer();
	os = chars;
	Marshal::FreeHGlobal(IntPtr((void*)chars));
}
}

