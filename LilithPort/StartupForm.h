#pragma once

#include "stdafx.h"

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
using namespace System::Text;


namespace LilithPort {
#pragma region Namespace
	/// <summary>
	/// StartupForm の概要
	///
	/// 警告: このクラスの名前を変更する場合、このクラスが依存するすべての .resx ファイルに関連付けられた
	///          マネージ リソース コンパイラ ツールに対して 'Resource File Name' プロパティを
	///          変更する必要があります。この変更を行わないと、
	///          デザイナと、このフォームに関連付けられたローカライズ済みリソースとが、
	///          正しく相互に利用できなくなります。
	/// </summary>
	public ref class StartupForm : public System::Windows::Forms::Form
	{
	public:
		StartupForm(void)
		{
			InitializeComponent();
			//
			//TODO: ここにコンストラクタ コードを追加します
			//
		}

	protected:
		/// <summary>
		/// 使用中のリソースをすべてクリーンアップします。
		/// </summary>
		~StartupForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::RadioButton^  radioButtonServer;
	private: System::Windows::Forms::RadioButton^  radioButtonHost;
	private: System::Windows::Forms::RadioButton^  radioButtonClient;
	private: System::Windows::Forms::Label^  labelServerName;
	private: System::Windows::Forms::TextBox^  textBoxIP;
	private: System::Windows::Forms::Label^  labelOpenPort;
	private: System::Windows::Forms::NumericUpDown^  numericUpDownOpenPort;
	private: System::Windows::Forms::Button^  buttonOK;
	private: System::Windows::Forms::Button^  buttonCancel;
	private: System::Windows::Forms::GroupBox^  groupBoxStartMode;
	private: System::Windows::Forms::TextBox^  textBoxServerName;
	private: System::Windows::Forms::GroupBox^  groupBoxConnection;
	private: System::Windows::Forms::GroupBox^  groupBoxWelcome;
	private: System::Windows::Forms::RichTextBox^  textBoxWelcome;
	private: System::Windows::Forms::ToolTip^  toolTipStartupForm;
	private: System::Windows::Forms::Button^  buttonConnect;
	private: System::Windows::Forms::TabControl^  startupTabs;
	private: System::Windows::Forms::TabPage^  tabPage1;
	private: System::Windows::Forms::TabPage^  tabPage2;
	private: System::Windows::Forms::Label^  labelComment;
	private: System::Windows::Forms::Label^  labelName;
	private: System::Windows::Forms::TextBox^  textBoxComment;
	private: System::Windows::Forms::TextBox^  textBoxName;
	private: System::Windows::Forms::TabPage^  tabPage3;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::GroupBox^  groupBoxUser;
	private: System::Windows::Forms::Label^  labelAvoiding;
	private: System::Windows::Forms::TextBox^  textBoxAvoiding;
	private: System::Windows::Forms::Label^  labelLooking;
	private: System::Windows::Forms::TextBox^  textBoxLooking;
	private: System::Windows::Forms::CheckBox^  checkBoxUpnp;
	private: System::Windows::Forms::CheckBox^  checkBoxLegacy;
	private: System::Windows::Forms::CheckBox^  checkBoxRestConnect;
	private: System::Windows::Forms::Label^  labelRegion;
	private: System::Windows::Forms::ComboBox^  comboBoxRegion;
	private: System::Windows::Forms::CheckBox^  checkBoxRegion;
	private: System::Windows::Forms::TextBox^  textBoxGG;
	private: System::Windows::Forms::GroupBox^  groupBoxGG;
	private: System::Windows::Forms::CheckBox^  checkBoxGG;
	private: System::Windows::Forms::Label^  labelGG;










	private: System::ComponentModel::IContainer^  components;
	private:
		/// <summary>
		/// 必要なデザイナ変数です。
		/// </summary>
#pragma endregion
#pragma region Windows Form Designer generated code
		/// <summary>
		/// デザイナ サポートに必要なメソッドです。このメソッドの内容を
		/// コード エディタで変更しないでください。
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(StartupForm::typeid));
			this->radioButtonServer = (gcnew System::Windows::Forms::RadioButton());
			this->radioButtonHost = (gcnew System::Windows::Forms::RadioButton());
			this->radioButtonClient = (gcnew System::Windows::Forms::RadioButton());
			this->labelServerName = (gcnew System::Windows::Forms::Label());
			this->textBoxIP = (gcnew System::Windows::Forms::TextBox());
			this->labelOpenPort = (gcnew System::Windows::Forms::Label());
			this->numericUpDownOpenPort = (gcnew System::Windows::Forms::NumericUpDown());
			this->buttonOK = (gcnew System::Windows::Forms::Button());
			this->buttonCancel = (gcnew System::Windows::Forms::Button());
			this->groupBoxStartMode = (gcnew System::Windows::Forms::GroupBox());
			this->checkBoxUpnp = (gcnew System::Windows::Forms::CheckBox());
			this->textBoxServerName = (gcnew System::Windows::Forms::TextBox());
			this->groupBoxConnection = (gcnew System::Windows::Forms::GroupBox());
			this->checkBoxLegacy = (gcnew System::Windows::Forms::CheckBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->groupBoxWelcome = (gcnew System::Windows::Forms::GroupBox());
			this->textBoxWelcome = (gcnew System::Windows::Forms::RichTextBox());
			this->toolTipStartupForm = (gcnew System::Windows::Forms::ToolTip(this->components));
			this->buttonConnect = (gcnew System::Windows::Forms::Button());
			this->labelLooking = (gcnew System::Windows::Forms::Label());
			this->labelAvoiding = (gcnew System::Windows::Forms::Label());
			this->checkBoxRestConnect = (gcnew System::Windows::Forms::CheckBox());
			this->labelRegion = (gcnew System::Windows::Forms::Label());
			this->labelGG = (gcnew System::Windows::Forms::Label());
			this->labelComment = (gcnew System::Windows::Forms::Label());
			this->labelName = (gcnew System::Windows::Forms::Label());
			this->textBoxName = (gcnew System::Windows::Forms::TextBox());
			this->textBoxComment = (gcnew System::Windows::Forms::TextBox());
			this->textBoxGG = (gcnew System::Windows::Forms::TextBox());
			this->startupTabs = (gcnew System::Windows::Forms::TabControl());
			this->tabPage2 = (gcnew System::Windows::Forms::TabPage());
			this->tabPage1 = (gcnew System::Windows::Forms::TabPage());
			this->groupBoxGG = (gcnew System::Windows::Forms::GroupBox());
			this->checkBoxGG = (gcnew System::Windows::Forms::CheckBox());
			this->groupBoxUser = (gcnew System::Windows::Forms::GroupBox());
			this->checkBoxRegion = (gcnew System::Windows::Forms::CheckBox());
			this->comboBoxRegion = (gcnew System::Windows::Forms::ComboBox());
			this->textBoxAvoiding = (gcnew System::Windows::Forms::TextBox());
			this->textBoxLooking = (gcnew System::Windows::Forms::TextBox());
			this->tabPage3 = (gcnew System::Windows::Forms::TabPage());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDownOpenPort))->BeginInit();
			this->groupBoxStartMode->SuspendLayout();
			this->groupBoxConnection->SuspendLayout();
			this->groupBoxWelcome->SuspendLayout();
			this->startupTabs->SuspendLayout();
			this->tabPage2->SuspendLayout();
			this->tabPage1->SuspendLayout();
			this->groupBoxGG->SuspendLayout();
			this->groupBoxUser->SuspendLayout();
			this->tabPage3->SuspendLayout();
			this->SuspendLayout();
			// 
			// radioButtonServer
			// 
			this->radioButtonServer->AutoSize = true;
			this->radioButtonServer->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->radioButtonServer->Location = System::Drawing::Point(6, 6);
			this->radioButtonServer->Name = L"radioButtonServer";
			this->radioButtonServer->Size = System::Drawing::Size(62, 18);
			this->radioButtonServer->TabIndex = 0;
			this->radioButtonServer->Text = L"Server";
			this->toolTipStartupForm->SetToolTip(this->radioButtonServer, L"Set up a server and wait for other connections.\r\nThe specified listening port (UD" 
				L"P) must be open.");
			this->radioButtonServer->UseVisualStyleBackColor = true;
			this->radioButtonServer->CheckedChanged += gcnew System::EventHandler(this, &StartupForm::radioButtonServer_CheckedChanged);
			// 
			// radioButtonHost
			// 
			this->radioButtonHost->AutoSize = true;
			this->radioButtonHost->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->radioButtonHost->Location = System::Drawing::Point(6, 29);
			this->radioButtonHost->Name = L"radioButtonHost";
			this->radioButtonHost->Size = System::Drawing::Size(53, 18);
			this->radioButtonHost->TabIndex = 1;
			this->radioButtonHost->Text = L"Host";
			this->toolTipStartupForm->SetToolTip(this->radioButtonHost, L"Connect to the server. \r\nThe specified listening port (UDP) will be used for comm" 
				L"unication. \r\n(Opening the port will ensure stable operation.)");
			this->radioButtonHost->UseVisualStyleBackColor = true;
			this->radioButtonHost->CheckedChanged += gcnew System::EventHandler(this, &StartupForm::radioButtonHost_CheckedChanged);
			// 
			// radioButtonClient
			// 
			this->radioButtonClient->AutoSize = true;
			this->radioButtonClient->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->radioButtonClient->Location = System::Drawing::Point(6, 52);
			this->radioButtonClient->Name = L"radioButtonClient";
			this->radioButtonClient->Size = System::Drawing::Size(57, 18);
			this->radioButtonClient->TabIndex = 2;
			this->radioButtonClient->Text = L"Client";
			this->toolTipStartupForm->SetToolTip(this->radioButtonClient, L"Connect to the server. \r\nThe port will be assigned automatically. \r\n(You can conn" 
				L"ect without opening the port, but the operation will be slightly unstable.)");
			this->radioButtonClient->UseVisualStyleBackColor = true;
			this->radioButtonClient->CheckedChanged += gcnew System::EventHandler(this, &StartupForm::radioButtonClient_CheckedChanged);
			// 
			// labelServerName
			// 
			this->labelServerName->AutoSize = true;
			this->labelServerName->Location = System::Drawing::Point(9, 27);
			this->labelServerName->Name = L"labelServerName";
			this->labelServerName->Size = System::Drawing::Size(54, 13);
			this->labelServerName->TabIndex = 0;
			this->labelServerName->Text = L"Server IP:";
			this->toolTipStartupForm->SetToolTip(this->labelServerName, L"Set the IP address your server will use.\r\nDo not include the port number in this " 
				L"field.");
			// 
			// textBoxIP
			// 
			this->textBoxIP->Location = System::Drawing::Point(81, 25);
			this->textBoxIP->Name = L"textBoxIP";
			this->textBoxIP->Size = System::Drawing::Size(256, 20);
			this->textBoxIP->TabIndex = 6;
			this->textBoxIP->WordWrap = false;
			// 
			// labelOpenPort
			// 
			this->labelOpenPort->AutoSize = true;
			this->labelOpenPort->Location = System::Drawing::Point(9, 56);
			this->labelOpenPort->Name = L"labelOpenPort";
			this->labelOpenPort->Size = System::Drawing::Size(62, 13);
			this->labelOpenPort->TabIndex = 0;
			this->labelOpenPort->Text = L"Server port:";
			this->toolTipStartupForm->SetToolTip(this->labelOpenPort, L"Set the server port from 1024 - 65535. Default port is 7500.\r\nWhen a server port " 
				L"is set, users will need to enter \"<url/obfuscated ip>:<port>\".");
			// 
			// numericUpDownOpenPort
			// 
			this->numericUpDownOpenPort->Location = System::Drawing::Point(77, 54);
			this->numericUpDownOpenPort->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {65535, 0, 0, 0});
			this->numericUpDownOpenPort->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) {1024, 0, 0, 0});
			this->numericUpDownOpenPort->Name = L"numericUpDownOpenPort";
			this->numericUpDownOpenPort->Size = System::Drawing::Size(53, 20);
			this->numericUpDownOpenPort->TabIndex = 4;
			this->numericUpDownOpenPort->Tag = L"";
			this->numericUpDownOpenPort->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) {7500, 0, 0, 0});
			// 
			// buttonOK
			// 
			this->buttonOK->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->buttonOK->Location = System::Drawing::Point(272, 279);
			this->buttonOK->Name = L"buttonOK";
			this->buttonOK->Size = System::Drawing::Size(80, 26);
			this->buttonOK->TabIndex = 0;
			this->buttonOK->Text = L"OK";
			this->toolTipStartupForm->SetToolTip(this->buttonOK, L"Confirm the settings you\'ve chosen above.");
			this->buttonOK->UseVisualStyleBackColor = true;
			this->buttonOK->Click += gcnew System::EventHandler(this, &StartupForm::buttonOK_Click);
			// 
			// buttonCancel
			// 
			this->buttonCancel->DialogResult = System::Windows::Forms::DialogResult::Cancel;
			this->buttonCancel->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->buttonCancel->Location = System::Drawing::Point(358, 279);
			this->buttonCancel->Name = L"buttonCancel";
			this->buttonCancel->Size = System::Drawing::Size(80, 26);
			this->buttonCancel->TabIndex = 1;
			this->buttonCancel->Text = L"Cancel";
			this->toolTipStartupForm->SetToolTip(this->buttonCancel, L"Switch to offline free play mode.");
			this->buttonCancel->UseVisualStyleBackColor = true;
			this->buttonCancel->Click += gcnew System::EventHandler(this, &StartupForm::buttonCancel_Click);
			// 
			// groupBoxStartMode
			// 
			this->groupBoxStartMode->Controls->Add(this->checkBoxUpnp);
			this->groupBoxStartMode->Controls->Add(this->textBoxServerName);
			this->groupBoxStartMode->Controls->Add(this->labelOpenPort);
			this->groupBoxStartMode->Controls->Add(this->labelServerName);
			this->groupBoxStartMode->Controls->Add(this->numericUpDownOpenPort);
			this->groupBoxStartMode->Location = System::Drawing::Point(68, 6);
			this->groupBoxStartMode->Name = L"groupBoxStartMode";
			this->groupBoxStartMode->Size = System::Drawing::Size(343, 105);
			this->groupBoxStartMode->TabIndex = 8;
			this->groupBoxStartMode->TabStop = false;
			this->groupBoxStartMode->Text = L"Server";
			// 
			// checkBoxUpnp
			// 
			this->checkBoxUpnp->AutoSize = true;
			this->checkBoxUpnp->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->checkBoxUpnp->Location = System::Drawing::Point(12, 80);
			this->checkBoxUpnp->Name = L"checkBoxUpnp";
			this->checkBoxUpnp->Size = System::Drawing::Size(96, 18);
			this->checkBoxUpnp->TabIndex = 5;
			this->checkBoxUpnp->Text = L"Enable UPnP";
			this->checkBoxUpnp->UseVisualStyleBackColor = true;
			this->checkBoxUpnp->CheckedChanged += gcnew System::EventHandler(this, &StartupForm::checkBoxUpnp_CheckedChanged);
			// 
			// textBoxServerName
			// 
			this->textBoxServerName->Location = System::Drawing::Point(77, 23);
			this->textBoxServerName->Name = L"textBoxServerName";
			this->textBoxServerName->Size = System::Drawing::Size(260, 20);
			this->textBoxServerName->TabIndex = 3;
			this->textBoxServerName->WordWrap = false;
			// 
			// groupBoxConnection
			// 
			this->groupBoxConnection->Controls->Add(this->checkBoxLegacy);
			this->groupBoxConnection->Controls->Add(this->label1);
			this->groupBoxConnection->Controls->Add(this->textBoxIP);
			this->groupBoxConnection->Location = System::Drawing::Point(68, 117);
			this->groupBoxConnection->Name = L"groupBoxConnection";
			this->groupBoxConnection->Size = System::Drawing::Size(343, 74);
			this->groupBoxConnection->TabIndex = 9;
			this->groupBoxConnection->TabStop = false;
			this->groupBoxConnection->Text = L"Client";
			this->toolTipStartupForm->SetToolTip(this->groupBoxConnection, resources->GetString(L"groupBoxConnection.ToolTip"));
			// 
			// checkBoxLegacy
			// 
			this->checkBoxLegacy->AutoSize = true;
			this->checkBoxLegacy->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->checkBoxLegacy->Location = System::Drawing::Point(6, 51);
			this->checkBoxLegacy->Name = L"checkBoxLegacy";
			this->checkBoxLegacy->Size = System::Drawing::Size(141, 18);
			this->checkBoxLegacy->TabIndex = 7;
			this->checkBoxLegacy->Text = L"Enable legacy netcode";
			this->toolTipStartupForm->SetToolTip(this->checkBoxLegacy, L"Allows connection to servers running 1.0.9.x or earlier.");
			this->checkBoxLegacy->UseVisualStyleBackColor = true;
			this->checkBoxLegacy->CheckedChanged += gcnew System::EventHandler(this, &StartupForm::checkBoxLegacy_CheckedChanged);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(6, 28);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(69, 13);
			this->label1->TabIndex = 11;
			this->label1->Text = L"Address / IP:";
			this->toolTipStartupForm->SetToolTip(this->label1, L"Specify the server address or IP you want to connect to.\r\n[<address/ip>:<port>]");
			// 
			// groupBoxWelcome
			// 
			this->groupBoxWelcome->Controls->Add(this->textBoxWelcome);
			this->groupBoxWelcome->Location = System::Drawing::Point(6, 6);
			this->groupBoxWelcome->Name = L"groupBoxWelcome";
			this->groupBoxWelcome->Size = System::Drawing::Size(409, 223);
			this->groupBoxWelcome->TabIndex = 11;
			this->groupBoxWelcome->TabStop = false;
			this->groupBoxWelcome->Text = L"Server Welcome Message";
			this->toolTipStartupForm->SetToolTip(this->groupBoxWelcome, L"This Welcome message will be shown when players join your server.");
			// 
			// textBoxWelcome
			// 
			this->textBoxWelcome->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->textBoxWelcome->Location = System::Drawing::Point(6, 19);
			this->textBoxWelcome->MaxLength = 254;
			this->textBoxWelcome->Name = L"textBoxWelcome";
			this->textBoxWelcome->Size = System::Drawing::Size(397, 198);
			this->textBoxWelcome->TabIndex = 0;
			this->textBoxWelcome->Text = L"";
			this->toolTipStartupForm->SetToolTip(this->textBoxWelcome, L"When running a server, this message will appear to everyone who joins.");
			this->textBoxWelcome->WordWrap = false;
			// 
			// toolTipStartupForm
			// 
			this->toolTipStartupForm->AutomaticDelay = 0;
			this->toolTipStartupForm->AutoPopDelay = 30000;
			this->toolTipStartupForm->InitialDelay = 0;
			this->toolTipStartupForm->ReshowDelay = 0;
			this->toolTipStartupForm->UseAnimation = false;
			this->toolTipStartupForm->UseFading = false;
			// 
			// buttonConnect
			// 
			this->buttonConnect->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->buttonConnect->Location = System::Drawing::Point(272, 279);
			this->buttonConnect->Name = L"buttonConnect";
			this->buttonConnect->Size = System::Drawing::Size(80, 26);
			this->buttonConnect->TabIndex = 8;
			this->buttonConnect->Text = L"Connect";
			this->toolTipStartupForm->SetToolTip(this->buttonConnect, L"Start an online connection.");
			this->buttonConnect->UseVisualStyleBackColor = true;
			this->buttonConnect->Click += gcnew System::EventHandler(this, &StartupForm::buttonOK_Click);
			// 
			// labelLooking
			// 
			this->labelLooking->AutoSize = true;
			this->labelLooking->Location = System::Drawing::Point(11, 78);
			this->labelLooking->Name = L"labelLooking";
			this->labelLooking->Size = System::Drawing::Size(63, 13);
			this->labelLooking->TabIndex = 10;
			this->labelLooking->Text = L"Looking for:";
			this->toolTipStartupForm->SetToolTip(this->labelLooking, L"Specify what you\'re looking for in players.");
			// 
			// labelAvoiding
			// 
			this->labelAvoiding->AutoSize = true;
			this->labelAvoiding->Location = System::Drawing::Point(23, 104);
			this->labelAvoiding->Name = L"labelAvoiding";
			this->labelAvoiding->Size = System::Drawing::Size(51, 13);
			this->labelAvoiding->TabIndex = 12;
			this->labelAvoiding->Text = L"Avoiding:";
			this->toolTipStartupForm->SetToolTip(this->labelAvoiding, L"Specify what you\'re avoiding in players.");
			// 
			// checkBoxRestConnect
			// 
			this->checkBoxRestConnect->AutoSize = true;
			this->checkBoxRestConnect->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->checkBoxRestConnect->Location = System::Drawing::Point(68, 197);
			this->checkBoxRestConnect->Name = L"checkBoxRestConnect";
			this->checkBoxRestConnect->Size = System::Drawing::Size(253, 18);
			this->checkBoxRestConnect->TabIndex = 8;
			this->checkBoxRestConnect->Text = L"On connection, automatically go into rest mode";
			this->toolTipStartupForm->SetToolTip(this->checkBoxRestConnect, L"Automatically toggles you to rest mode when you initialise a server or join anoth" 
				L"er server as a host or client.");
			this->checkBoxRestConnect->UseVisualStyleBackColor = true;
			this->checkBoxRestConnect->CheckedChanged += gcnew System::EventHandler(this, &StartupForm::checkBoxRestConnect_CheckedChanged);
			// 
			// labelRegion
			// 
			this->labelRegion->AutoSize = true;
			this->labelRegion->Location = System::Drawing::Point(30, 130);
			this->labelRegion->Name = L"labelRegion";
			this->labelRegion->Size = System::Drawing::Size(44, 13);
			this->labelRegion->TabIndex = 13;
			this->labelRegion->Text = L"Region:";
			this->toolTipStartupForm->SetToolTip(this->labelRegion, L"Specify a region to show on your profile.");
			// 
			// labelGG
			// 
			this->labelGG->AutoSize = true;
			this->labelGG->Location = System::Drawing::Point(11, 28);
			this->labelGG->Name = L"labelGG";
			this->labelGG->Size = System::Drawing::Size(74, 13);
			this->labelGG->TabIndex = 16;
			this->labelGG->Text = L"End message:";
			this->toolTipStartupForm->SetToolTip(this->labelGG, L"Specify a message to type in chat after a fight.");
			// 
			// labelComment
			// 
			this->labelComment->AutoSize = true;
			this->labelComment->Location = System::Drawing::Point(20, 52);
			this->labelComment->Name = L"labelComment";
			this->labelComment->Size = System::Drawing::Size(54, 13);
			this->labelComment->TabIndex = 8;
			this->labelComment->Text = L"Comment:";
			this->toolTipStartupForm->SetToolTip(this->labelComment, L"You will automatically say this message when you join.");
			// 
			// labelName
			// 
			this->labelName->AutoSize = true;
			this->labelName->Location = System::Drawing::Point(36, 25);
			this->labelName->Name = L"labelName";
			this->labelName->Size = System::Drawing::Size(38, 13);
			this->labelName->TabIndex = 5;
			this->labelName->Text = L"Name:";
			this->toolTipStartupForm->SetToolTip(this->labelName, L"Your username. You cannot use special characters.");
			// 
			// textBoxName
			// 
			this->textBoxName->Location = System::Drawing::Point(80, 22);
			this->textBoxName->Name = L"textBoxName";
			this->textBoxName->Size = System::Drawing::Size(323, 20);
			this->textBoxName->TabIndex = 0;
			this->textBoxName->WordWrap = false;
			// 
			// textBoxComment
			// 
			this->textBoxComment->Location = System::Drawing::Point(80, 49);
			this->textBoxComment->Name = L"textBoxComment";
			this->textBoxComment->Size = System::Drawing::Size(323, 20);
			this->textBoxComment->TabIndex = 1;
			this->textBoxComment->WordWrap = false;
			// 
			// textBoxGG
			// 
			this->textBoxGG->Enabled = false;
			this->textBoxGG->Location = System::Drawing::Point(91, 25);
			this->textBoxGG->Name = L"textBoxGG";
			this->textBoxGG->Size = System::Drawing::Size(189, 20);
			this->textBoxGG->TabIndex = 6;
			// 
			// startupTabs
			// 
			this->startupTabs->Controls->Add(this->tabPage2);
			this->startupTabs->Controls->Add(this->tabPage1);
			this->startupTabs->Controls->Add(this->tabPage3);
			this->startupTabs->Location = System::Drawing::Point(9, 12);
			this->startupTabs->Name = L"startupTabs";
			this->startupTabs->SelectedIndex = 0;
			this->startupTabs->Size = System::Drawing::Size(429, 261);
			this->startupTabs->TabIndex = 15;
			// 
			// tabPage2
			// 
			this->tabPage2->Controls->Add(this->checkBoxRestConnect);
			this->tabPage2->Controls->Add(this->groupBoxStartMode);
			this->tabPage2->Controls->Add(this->radioButtonServer);
			this->tabPage2->Controls->Add(this->groupBoxConnection);
			this->tabPage2->Controls->Add(this->radioButtonHost);
			this->tabPage2->Controls->Add(this->radioButtonClient);
			this->tabPage2->Location = System::Drawing::Point(4, 22);
			this->tabPage2->Name = L"tabPage2";
			this->tabPage2->Padding = System::Windows::Forms::Padding(3);
			this->tabPage2->Size = System::Drawing::Size(421, 235);
			this->tabPage2->TabIndex = 1;
			this->tabPage2->Text = L"Connection";
			this->tabPage2->UseVisualStyleBackColor = true;
			// 
			// tabPage1
			// 
			this->tabPage1->Controls->Add(this->groupBoxGG);
			this->tabPage1->Controls->Add(this->groupBoxUser);
			this->tabPage1->Location = System::Drawing::Point(4, 22);
			this->tabPage1->Name = L"tabPage1";
			this->tabPage1->Padding = System::Windows::Forms::Padding(3);
			this->tabPage1->Size = System::Drawing::Size(421, 235);
			this->tabPage1->TabIndex = 0;
			this->tabPage1->Text = L"User Profile";
			this->tabPage1->UseVisualStyleBackColor = true;
			// 
			// groupBoxGG
			// 
			this->groupBoxGG->Controls->Add(this->checkBoxGG);
			this->groupBoxGG->Controls->Add(this->labelGG);
			this->groupBoxGG->Controls->Add(this->textBoxGG);
			this->groupBoxGG->Location = System::Drawing::Point(6, 173);
			this->groupBoxGG->Name = L"groupBoxGG";
			this->groupBoxGG->Size = System::Drawing::Size(409, 56);
			this->groupBoxGG->TabIndex = 17;
			this->groupBoxGG->TabStop = false;
			this->groupBoxGG->Text = L"Fight End Message Settings";
			// 
			// checkBoxGG
			// 
			this->checkBoxGG->AutoSize = true;
			this->checkBoxGG->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->checkBoxGG->Location = System::Drawing::Point(286, 27);
			this->checkBoxGG->Name = L"checkBoxGG";
			this->checkBoxGG->Size = System::Drawing::Size(131, 18);
			this->checkBoxGG->TabIndex = 7;
			this->checkBoxGG->Text = L"Enable end message";
			this->checkBoxGG->UseVisualStyleBackColor = true;
			this->checkBoxGG->CheckedChanged += gcnew System::EventHandler(this, &StartupForm::checkBoxGG_CheckedChanged);
			// 
			// groupBoxUser
			// 
			this->groupBoxUser->Controls->Add(this->checkBoxRegion);
			this->groupBoxUser->Controls->Add(this->comboBoxRegion);
			this->groupBoxUser->Controls->Add(this->labelRegion);
			this->groupBoxUser->Controls->Add(this->labelAvoiding);
			this->groupBoxUser->Controls->Add(this->textBoxAvoiding);
			this->groupBoxUser->Controls->Add(this->labelLooking);
			this->groupBoxUser->Controls->Add(this->textBoxLooking);
			this->groupBoxUser->Controls->Add(this->labelName);
			this->groupBoxUser->Controls->Add(this->labelComment);
			this->groupBoxUser->Controls->Add(this->textBoxName);
			this->groupBoxUser->Controls->Add(this->textBoxComment);
			this->groupBoxUser->Location = System::Drawing::Point(6, 6);
			this->groupBoxUser->Name = L"groupBoxUser";
			this->groupBoxUser->Size = System::Drawing::Size(409, 161);
			this->groupBoxUser->TabIndex = 9;
			this->groupBoxUser->TabStop = false;
			this->groupBoxUser->Text = L"User Profile Settings";
			// 
			// checkBoxRegion
			// 
			this->checkBoxRegion->AutoSize = true;
			this->checkBoxRegion->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->checkBoxRegion->Location = System::Drawing::Point(239, 130);
			this->checkBoxRegion->Name = L"checkBoxRegion";
			this->checkBoxRegion->Size = System::Drawing::Size(144, 18);
			this->checkBoxRegion->TabIndex = 5;
			this->checkBoxRegion->Text = L"Display region on profile";
			this->checkBoxRegion->UseVisualStyleBackColor = true;
			this->checkBoxRegion->CheckedChanged += gcnew System::EventHandler(this, &StartupForm::checkBoxRegion_CheckedChanged);
			// 
			// comboBoxRegion
			// 
			this->comboBoxRegion->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->comboBoxRegion->Enabled = false;
			this->comboBoxRegion->FormattingEnabled = true;
			this->comboBoxRegion->Items->AddRange(gcnew cli::array< System::Object^  >(10) {L"North America", L"Europe", L"Russia", L"Asia", 
				L"South America", L"Africa", L"Middle East", L"Australia", L"New Zealand", L"Antarctica"});
			this->comboBoxRegion->Location = System::Drawing::Point(80, 127);
			this->comboBoxRegion->Name = L"comboBoxRegion";
			this->comboBoxRegion->Size = System::Drawing::Size(153, 21);
			this->comboBoxRegion->TabIndex = 4;
			// 
			// textBoxAvoiding
			// 
			this->textBoxAvoiding->Location = System::Drawing::Point(80, 101);
			this->textBoxAvoiding->Name = L"textBoxAvoiding";
			this->textBoxAvoiding->Size = System::Drawing::Size(323, 20);
			this->textBoxAvoiding->TabIndex = 3;
			this->textBoxAvoiding->WordWrap = false;
			// 
			// textBoxLooking
			// 
			this->textBoxLooking->Location = System::Drawing::Point(80, 75);
			this->textBoxLooking->Name = L"textBoxLooking";
			this->textBoxLooking->Size = System::Drawing::Size(323, 20);
			this->textBoxLooking->TabIndex = 2;
			this->textBoxLooking->WordWrap = false;
			// 
			// tabPage3
			// 
			this->tabPage3->Controls->Add(this->groupBoxWelcome);
			this->tabPage3->Location = System::Drawing::Point(4, 22);
			this->tabPage3->Name = L"tabPage3";
			this->tabPage3->Padding = System::Windows::Forms::Padding(3);
			this->tabPage3->Size = System::Drawing::Size(421, 235);
			this->tabPage3->TabIndex = 2;
			this->tabPage3->Text = L"Welcome Message";
			this->tabPage3->UseVisualStyleBackColor = true;
			// 
			// StartupForm
			// 
			this->AcceptButton = this->buttonOK;
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::Black;
			this->CancelButton = this->buttonCancel;
			this->ClientSize = System::Drawing::Size(450, 317);
			this->ControlBox = false;
			this->Controls->Add(this->startupTabs);
			this->Controls->Add(this->buttonOK);
			this->Controls->Add(this->buttonCancel);
			this->Controls->Add(this->buttonConnect);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^  >(resources->GetObject(L"$this.Icon")));
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"StartupForm";
			this->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->ShowInTaskbar = false;
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
			this->Text = L"MorningStar - Welcome";
			this->TopMost = true;
			this->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &StartupForm::StartupForm_FormClosed);
			this->Load += gcnew System::EventHandler(this, &StartupForm::StartupForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDownOpenPort))->EndInit();
			this->groupBoxStartMode->ResumeLayout(false);
			this->groupBoxStartMode->PerformLayout();
			this->groupBoxConnection->ResumeLayout(false);
			this->groupBoxConnection->PerformLayout();
			this->groupBoxWelcome->ResumeLayout(false);
			this->startupTabs->ResumeLayout(false);
			this->tabPage2->ResumeLayout(false);
			this->tabPage2->PerformLayout();
			this->tabPage1->ResumeLayout(false);
			this->groupBoxGG->ResumeLayout(false);
			this->groupBoxGG->PerformLayout();
			this->groupBoxUser->ResumeLayout(false);
			this->groupBoxUser->PerformLayout();
			this->tabPage3->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion
#pragma region Variables
	protected:

		// StartupForm.cpp
		bool StartupForm::CheckValidate();

	private:

		// Loads startup settings.
		static bool ConnectionStart = false;
#pragma endregion
#pragma region Load Settings
		System::Void StartupForm_Load(System::Object^  sender, System::EventArgs^  e) {
			ConnectionStart = false;

			textBoxServerName->MaxLength      = MAX_NAME;
			textBoxIP->MaxLength              = MAX_ARRAY;
			textBoxName->MaxLength            = MAX_NAME;
			textBoxComment->MaxLength         = MAX_NAME;

			switch(MTOPTION.CONNECTION_TYPE){
			case 0:
				radioButtonServer->Checked = true;
				checkBoxLegacy->Checked = false;

				break;
			case 1:
				radioButtonHost->Checked = true;

				break;
			case 3:
				radioButtonClient->Checked = true;

				numericUpDownOpenPort->Enabled = false;
				break;
			default:
				radioButtonClient->Checked = true;

				numericUpDownOpenPort->Enabled = false;
				break;
			}

			textBoxServerName->Text = gcnew String(MTOPTION.SERVER_NAME);
			textBoxIP->Text = gcnew String(MTOPTION.CONNECTION_IP);
			
			numericUpDownOpenPort->Value = MTOPTION.OPEN_PORT;
			textBoxName->Text = gcnew String(MTOPTION.NAME);
			checkBoxLegacy->Checked = MTOPTION.LEGACY_SERVER;
			checkBoxRestConnect->Checked = MTOPTION.REST_CONNECT;

			textBoxComment->Text = gcnew String(MTOPTION.COMMENT);
			textBoxLooking->Text = gcnew String(MTOPTION.LOOKING);
			textBoxAvoiding->Text = gcnew String(MTOPTION.AVOIDING);
			comboBoxRegion->Text = gcnew String(MTOPTION.REGION);
			checkBoxRegion->Checked = MTOPTION.SHOW_REGION;

			textBoxGG->Text = gcnew String(MTOPTION.GG);
			checkBoxGG->Checked = MTOPTION.GG_ENABLE;
			// タブを改行に
			ReplaceWelcomeTab(true);
			textBoxWelcome->Text = gcnew String(MTOPTION.WELCOME);
		}
#pragma endregion
#pragma region Functions
		// Radio buttons for selecting a mode on startup. 
		System::Void radioButtonServer_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
			numericUpDownOpenPort->Enabled = true;
			labelOpenPort->Enabled         = true;
			labelServerName->Enabled       = true;
			textBoxServerName->Enabled     = true;
			textBoxIP->Enabled             = false;
			groupBoxConnection->Enabled    = false;
			groupBoxWelcome->Enabled       = true;
			checkBoxUpnp->Enabled          = true;
			checkBoxLegacy->Checked = false;
		}
		System::Void radioButtonHost_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
			numericUpDownOpenPort->Enabled = true;
			labelOpenPort->Enabled         = true;
			labelServerName->Enabled       = false;
			textBoxServerName->Enabled     = false;
			textBoxIP->Enabled             = true;
			groupBoxConnection->Enabled    = true;
			groupBoxWelcome->Enabled       = false;
			checkBoxUpnp->Enabled          = true;
		}
		System::Void radioButtonClient_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
			numericUpDownOpenPort->Enabled = false;
			labelOpenPort->Enabled         = false;
			labelServerName->Enabled       = false;
			textBoxServerName->Enabled     = false;
			textBoxIP->Enabled             = true;
			groupBoxConnection->Enabled    = true;
			groupBoxWelcome->Enabled       = false;
			checkBoxUpnp->Enabled          = false;
		}
		//Checkbox for enabling/disabling UPnP.
		System::Void checkBoxUpnp_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
			if(checkBoxUpnp->Checked == true)
			{
				MTOPTION.OPEN_PORT = (UINT)numericUpDownOpenPort->Value;
				UPnP_PortOpenClose(true, false);
			}
			else
			{
				MTOPTION.OPEN_PORT = (UINT)numericUpDownOpenPort->Value;
				UPnP_PortOpenClose(false, false);
			}
		}
		// Checkbox for enabling/disabling legacy netcode.
		System::Void checkBoxLegacy_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
			if (checkBoxLegacy->Checked == true){
				MTOPTION.LEGACY_SERVER = true;
				textBoxLooking->Enabled = false;
				textBoxAvoiding->Enabled = false;
				comboBoxRegion->Enabled = false;
				checkBoxRegion->Enabled = false;

			}else{
				MTOPTION.LEGACY_SERVER = false;
				textBoxLooking->Enabled = true;
				textBoxAvoiding->Enabled = true;
				if (checkBoxRegion->Checked == true){
					comboBoxRegion->Enabled = true;
				}else{
					comboBoxRegion->Enabled = false;
				}
				checkBoxRegion->Enabled = true;
			}
		 }
		System::Void checkBoxRestConnect_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
			if (checkBoxRestConnect->Checked == true){
				MTOPTION.REST_CONNECT = true;
			}else{
				MTOPTION.REST_CONNECT = false;
			}
		}
		System::Void checkBoxRegion_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
			if (checkBoxRegion->Checked == true){
				MTOPTION.SHOW_REGION = true;
				comboBoxRegion->Enabled = true;
			}else{
				MTOPTION.SHOW_REGION = false;
				comboBoxRegion->Enabled = false;
			}
		 }
		System::Void checkBoxGG_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
			if (checkBoxGG->Checked == true){
				MTOPTION.GG_ENABLE = true;
				textBoxGG->Enabled = true;
			}else{
				MTOPTION.GG_ENABLE = false;
				textBoxGG->Enabled = false;
			}
		}
		System::Void StartupForm_FormClosed(System::Object^  sender, System::Windows::Forms::FormClosedEventArgs^  e) {
			if(!ConnectionStart){
				MTOPTION.CONNECTION_TYPE = CT_FREE;
			}
		}
#pragma endregion
#pragma region Buttons
		// Checks if name textbox is null or has invalid characters.
		// Then checks if the server name is null or invalid.
		// After which it then either connects you as the server or as a host/client to another server.
		System::Void buttonOK_Click(System::Object^  sender, System::EventArgs^  e) {
			String^ text = textBoxName->Text;
			array<Char>^ charactersToFind = { '<', '>', ':', '/', '|', '?', '*', '!', '@', '\\' };

			if (String::IsNullOrEmpty(textBoxName->Text)){
				MessageBox::Show("Your username cannot be blank.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Exclamation);
				return;
			}
			
			for each (Char character in charactersToFind) {
				String^ charAsString = gcnew String(&character, 0, 1);
				if (text->Contains(charAsString)) {
					MessageBox::Show("Your username cannot contain special characters <, >, :, |, ?, *, !, @, \\.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Exclamation);
					return;
				}
			}

			if(!CheckValidate()){
				return;
			}
			ConnectionStart = true;
			
			

			this->Close();
		}
		// Closes the 'Welcome' dialogue and sends the user to Free Play mode, skipping any type of connection. Effectively "offline" mode.
		System::Void buttonCancel_Click(System::Object^  sender, System::EventArgs^  e) {
			MTOPTION.CONNECTION_TYPE = CT_FREE;
			ConnectionStart = false;

			this->Close();
		}
#pragma endregion
};
}
