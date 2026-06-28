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

	private: System::Windows::Forms::TextBox^  textBoxIP;

	private: System::Windows::Forms::NumericUpDown^  numericUpDownOpenPort;
	private: System::Windows::Forms::Button^  buttonOK;
	private: System::Windows::Forms::Button^  buttonCancel;

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
	internal: System::Windows::Forms::Label^  TitleLabel;
	internal: System::Windows::Forms::PictureBox^  PictureBox1;
	internal: System::Windows::Forms::Button^  btnUser;

	internal: System::Windows::Forms::Button^  btnConnection;
	internal: System::Windows::Forms::Button^  btnWelcome;
	private: System::Windows::Forms::Panel^  pnlConnection;
	internal: 
	private: System::Windows::Forms::Panel^  pnlUser;
	private: System::Windows::Forms::Panel^  pnlWelcome;
	internal: System::Windows::Forms::Label^  label3;
	private: 
	internal: System::Windows::Forms::Label^  lblCD;
	internal: System::Windows::Forms::Label^  lblC;
	internal: System::Windows::Forms::Label^  lblSD;
	internal: System::Windows::Forms::Label^  lblS;
	internal: System::Windows::Forms::PictureBox^  pictureBox2;
	internal: System::Windows::Forms::Label^  label4;
	internal: System::Windows::Forms::Label^  label2;
	internal: System::Windows::Forms::Label^  lblCTD;
	internal: System::Windows::Forms::Label^  lblCT;


	private: 










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
			this->textBoxIP = (gcnew System::Windows::Forms::TextBox());
			this->numericUpDownOpenPort = (gcnew System::Windows::Forms::NumericUpDown());
			this->buttonOK = (gcnew System::Windows::Forms::Button());
			this->buttonCancel = (gcnew System::Windows::Forms::Button());
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
			this->TitleLabel = (gcnew System::Windows::Forms::Label());
			this->PictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->btnUser = (gcnew System::Windows::Forms::Button());
			this->btnConnection = (gcnew System::Windows::Forms::Button());
			this->btnWelcome = (gcnew System::Windows::Forms::Button());
			this->pnlConnection = (gcnew System::Windows::Forms::Panel());
			this->pnlUser = (gcnew System::Windows::Forms::Panel());
			this->pnlWelcome = (gcnew System::Windows::Forms::Panel());
			this->lblCT = (gcnew System::Windows::Forms::Label());
			this->lblCTD = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->lblSD = (gcnew System::Windows::Forms::Label());
			this->lblS = (gcnew System::Windows::Forms::Label());
			this->lblCD = (gcnew System::Windows::Forms::Label());
			this->lblC = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDownOpenPort))->BeginInit();
			this->groupBoxConnection->SuspendLayout();
			this->groupBoxWelcome->SuspendLayout();
			this->startupTabs->SuspendLayout();
			this->tabPage2->SuspendLayout();
			this->tabPage1->SuspendLayout();
			this->groupBoxGG->SuspendLayout();
			this->groupBoxUser->SuspendLayout();
			this->tabPage3->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->PictureBox1))->BeginInit();
			this->pnlConnection->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox2))->BeginInit();
			this->SuspendLayout();
			// 
			// radioButtonServer
			// 
			this->radioButtonServer->AutoSize = true;
			this->radioButtonServer->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->radioButtonServer->ForeColor = System::Drawing::Color::White;
			this->radioButtonServer->Location = System::Drawing::Point(422, 34);
			this->radioButtonServer->Name = L"radioButtonServer";
			this->radioButtonServer->Size = System::Drawing::Size(63, 21);
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
			this->radioButtonHost->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->radioButtonHost->ForeColor = System::Drawing::Color::White;
			this->radioButtonHost->Location = System::Drawing::Point(491, 34);
			this->radioButtonHost->Name = L"radioButtonHost";
			this->radioButtonHost->Size = System::Drawing::Size(53, 21);
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
			this->radioButtonClient->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->radioButtonClient->ForeColor = System::Drawing::Color::White;
			this->radioButtonClient->Location = System::Drawing::Point(550, 34);
			this->radioButtonClient->Name = L"radioButtonClient";
			this->radioButtonClient->Size = System::Drawing::Size(58, 21);
			this->radioButtonClient->TabIndex = 2;
			this->radioButtonClient->Text = L"Client";
			this->toolTipStartupForm->SetToolTip(this->radioButtonClient, L"Connect to the server. \r\nThe port will be assigned automatically. \r\n(You can conn" 
				L"ect without opening the port, but the operation will be slightly unstable.)");
			this->radioButtonClient->UseVisualStyleBackColor = true;
			this->radioButtonClient->CheckedChanged += gcnew System::EventHandler(this, &StartupForm::radioButtonClient_CheckedChanged);
			// 
			// textBoxIP
			// 
			this->textBoxIP->Location = System::Drawing::Point(81, 25);
			this->textBoxIP->Name = L"textBoxIP";
			this->textBoxIP->Size = System::Drawing::Size(256, 22);
			this->textBoxIP->TabIndex = 6;
			this->textBoxIP->WordWrap = false;
			// 
			// numericUpDownOpenPort
			// 
			this->numericUpDownOpenPort->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->numericUpDownOpenPort->Location = System::Drawing::Point(555, 106);
			this->numericUpDownOpenPort->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {65535, 0, 0, 0});
			this->numericUpDownOpenPort->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) {1024, 0, 0, 0});
			this->numericUpDownOpenPort->Name = L"numericUpDownOpenPort";
			this->numericUpDownOpenPort->Size = System::Drawing::Size(53, 25);
			this->numericUpDownOpenPort->TabIndex = 4;
			this->numericUpDownOpenPort->Tag = L"";
			this->numericUpDownOpenPort->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) {7500, 0, 0, 0});
			// 
			// buttonOK
			// 
			this->buttonOK->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->buttonOK->Location = System::Drawing::Point(723, 12);
			this->buttonOK->Name = L"buttonOK";
			this->buttonOK->Size = System::Drawing::Size(75, 23);
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
			this->buttonCancel->Location = System::Drawing::Point(723, 41);
			this->buttonCancel->Name = L"buttonCancel";
			this->buttonCancel->Size = System::Drawing::Size(75, 23);
			this->buttonCancel->TabIndex = 1;
			this->buttonCancel->Text = L"Cancel";
			this->toolTipStartupForm->SetToolTip(this->buttonCancel, L"Switch to offline free play mode.");
			this->buttonCancel->UseVisualStyleBackColor = true;
			this->buttonCancel->Click += gcnew System::EventHandler(this, &StartupForm::buttonCancel_Click);
			// 
			// checkBoxUpnp
			// 
			this->checkBoxUpnp->AutoSize = true;
			this->checkBoxUpnp->BackColor = System::Drawing::Color::Black;
			this->checkBoxUpnp->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->checkBoxUpnp->ForeColor = System::Drawing::Color::White;
			this->checkBoxUpnp->Location = System::Drawing::Point(508, 137);
			this->checkBoxUpnp->Name = L"checkBoxUpnp";
			this->checkBoxUpnp->Size = System::Drawing::Size(100, 21);
			this->checkBoxUpnp->TabIndex = 5;
			this->checkBoxUpnp->Text = L"Enable UPnP";
			this->checkBoxUpnp->UseVisualStyleBackColor = false;
			this->checkBoxUpnp->CheckedChanged += gcnew System::EventHandler(this, &StartupForm::checkBoxUpnp_CheckedChanged);
			// 
			// textBoxServerName
			// 
			this->textBoxServerName->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->textBoxServerName->Location = System::Drawing::Point(272, 105);
			this->textBoxServerName->Name = L"textBoxServerName";
			this->textBoxServerName->Size = System::Drawing::Size(260, 25);
			this->textBoxServerName->TabIndex = 3;
			this->textBoxServerName->WordWrap = false;
			// 
			// groupBoxConnection
			// 
			this->groupBoxConnection->Controls->Add(this->checkBoxLegacy);
			this->groupBoxConnection->Controls->Add(this->label1);
			this->groupBoxConnection->Controls->Add(this->textBoxIP);
			this->groupBoxConnection->Location = System::Drawing::Point(65, 33);
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
			this->checkBoxLegacy->Size = System::Drawing::Size(147, 18);
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
			this->label1->Size = System::Drawing::Size(70, 13);
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
			this->buttonConnect->Location = System::Drawing::Point(362, 322);
			this->buttonConnect->Name = L"buttonConnect";
			this->buttonConnect->Size = System::Drawing::Size(80, 23);
			this->buttonConnect->TabIndex = 8;
			this->buttonConnect->Text = L"Connect";
			this->toolTipStartupForm->SetToolTip(this->buttonConnect, L"Start an online connection.");
			this->buttonConnect->UseVisualStyleBackColor = true;
			this->buttonConnect->Visible = false;
			this->buttonConnect->Click += gcnew System::EventHandler(this, &StartupForm::buttonOK_Click);
			// 
			// labelLooking
			// 
			this->labelLooking->AutoSize = true;
			this->labelLooking->Location = System::Drawing::Point(11, 78);
			this->labelLooking->Name = L"labelLooking";
			this->labelLooking->Size = System::Drawing::Size(70, 13);
			this->labelLooking->TabIndex = 10;
			this->labelLooking->Text = L"Looking for:";
			this->toolTipStartupForm->SetToolTip(this->labelLooking, L"Specify what you\'re looking for in players.");
			// 
			// labelAvoiding
			// 
			this->labelAvoiding->AutoSize = true;
			this->labelAvoiding->Location = System::Drawing::Point(23, 104);
			this->labelAvoiding->Name = L"labelAvoiding";
			this->labelAvoiding->Size = System::Drawing::Size(56, 13);
			this->labelAvoiding->TabIndex = 12;
			this->labelAvoiding->Text = L"Avoiding:";
			this->toolTipStartupForm->SetToolTip(this->labelAvoiding, L"Specify what you\'re avoiding in players.");
			// 
			// checkBoxRestConnect
			// 
			this->checkBoxRestConnect->AutoSize = true;
			this->checkBoxRestConnect->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->checkBoxRestConnect->Location = System::Drawing::Point(99, 138);
			this->checkBoxRestConnect->Name = L"checkBoxRestConnect";
			this->checkBoxRestConnect->Size = System::Drawing::Size(278, 18);
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
			this->labelRegion->Size = System::Drawing::Size(47, 13);
			this->labelRegion->TabIndex = 13;
			this->labelRegion->Text = L"Region:";
			this->toolTipStartupForm->SetToolTip(this->labelRegion, L"Specify a region to show on your profile.");
			// 
			// labelGG
			// 
			this->labelGG->AutoSize = true;
			this->labelGG->Location = System::Drawing::Point(11, 28);
			this->labelGG->Name = L"labelGG";
			this->labelGG->Size = System::Drawing::Size(77, 13);
			this->labelGG->TabIndex = 16;
			this->labelGG->Text = L"End message:";
			this->toolTipStartupForm->SetToolTip(this->labelGG, L"Specify a message to type in chat after a fight.");
			// 
			// labelComment
			// 
			this->labelComment->AutoSize = true;
			this->labelComment->Location = System::Drawing::Point(20, 52);
			this->labelComment->Name = L"labelComment";
			this->labelComment->Size = System::Drawing::Size(59, 13);
			this->labelComment->TabIndex = 8;
			this->labelComment->Text = L"Comment:";
			this->toolTipStartupForm->SetToolTip(this->labelComment, L"You will automatically say this message when you join.");
			// 
			// labelName
			// 
			this->labelName->AutoSize = true;
			this->labelName->Location = System::Drawing::Point(36, 25);
			this->labelName->Name = L"labelName";
			this->labelName->Size = System::Drawing::Size(39, 13);
			this->labelName->TabIndex = 5;
			this->labelName->Text = L"Name:";
			this->toolTipStartupForm->SetToolTip(this->labelName, L"Your username. You cannot use special characters.");
			// 
			// textBoxName
			// 
			this->textBoxName->Location = System::Drawing::Point(80, 22);
			this->textBoxName->Name = L"textBoxName";
			this->textBoxName->Size = System::Drawing::Size(323, 22);
			this->textBoxName->TabIndex = 0;
			this->textBoxName->WordWrap = false;
			// 
			// textBoxComment
			// 
			this->textBoxComment->Location = System::Drawing::Point(80, 49);
			this->textBoxComment->Name = L"textBoxComment";
			this->textBoxComment->Size = System::Drawing::Size(323, 22);
			this->textBoxComment->TabIndex = 1;
			this->textBoxComment->WordWrap = false;
			// 
			// textBoxGG
			// 
			this->textBoxGG->Enabled = false;
			this->textBoxGG->Location = System::Drawing::Point(91, 25);
			this->textBoxGG->Name = L"textBoxGG";
			this->textBoxGG->Size = System::Drawing::Size(189, 22);
			this->textBoxGG->TabIndex = 6;
			// 
			// startupTabs
			// 
			this->startupTabs->Controls->Add(this->tabPage2);
			this->startupTabs->Controls->Add(this->tabPage1);
			this->startupTabs->Controls->Add(this->tabPage3);
			this->startupTabs->Location = System::Drawing::Point(195, 247);
			this->startupTabs->Name = L"startupTabs";
			this->startupTabs->SelectedIndex = 0;
			this->startupTabs->Size = System::Drawing::Size(429, 261);
			this->startupTabs->TabIndex = 15;
			// 
			// tabPage2
			// 
			this->tabPage2->Controls->Add(this->checkBoxRestConnect);
			this->tabPage2->Controls->Add(this->groupBoxConnection);
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
			this->checkBoxGG->Size = System::Drawing::Size(137, 18);
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
			this->checkBoxRegion->Size = System::Drawing::Size(160, 18);
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
			this->textBoxAvoiding->Size = System::Drawing::Size(323, 22);
			this->textBoxAvoiding->TabIndex = 3;
			this->textBoxAvoiding->WordWrap = false;
			// 
			// textBoxLooking
			// 
			this->textBoxLooking->Location = System::Drawing::Point(80, 75);
			this->textBoxLooking->Name = L"textBoxLooking";
			this->textBoxLooking->Size = System::Drawing::Size(323, 22);
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
			// TitleLabel
			// 
			this->TitleLabel->AutoSize = true;
			this->TitleLabel->Font = (gcnew System::Drawing::Font(L"Segoe UI", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->TitleLabel->ForeColor = System::Drawing::Color::White;
			this->TitleLabel->Location = System::Drawing::Point(25, 33);
			this->TitleLabel->Name = L"TitleLabel";
			this->TitleLabel->Size = System::Drawing::Size(99, 30);
			this->TitleLabel->TabIndex = 16;
			this->TitleLabel->Text = L"Welcome";
			// 
			// PictureBox1
			// 
			this->PictureBox1->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"PictureBox1.Image")));
			this->PictureBox1->Location = System::Drawing::Point(62, 86);
			this->PictureBox1->Name = L"PictureBox1";
			this->PictureBox1->Size = System::Drawing::Size(546, 10);
			this->PictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->PictureBox1->TabIndex = 17;
			this->PictureBox1->TabStop = false;
			// 
			// btnUser
			// 
			this->btnUser->BackColor = System::Drawing::Color::Transparent;
			this->btnUser->FlatAppearance->BorderSize = 0;
			this->btnUser->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Black;
			this->btnUser->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(82)), 
				static_cast<System::Int32>(static_cast<System::Byte>(82)), static_cast<System::Int32>(static_cast<System::Byte>(82)));
			this->btnUser->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnUser->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->btnUser->ForeColor = System::Drawing::Color::White;
			this->btnUser->Location = System::Drawing::Point(0, 125);
			this->btnUser->Name = L"btnUser";
			this->btnUser->Size = System::Drawing::Size(161, 36);
			this->btnUser->TabIndex = 19;
			this->btnUser->Text = L"User Profile";
			this->btnUser->UseVisualStyleBackColor = false;
			// 
			// btnConnection
			// 
			this->btnConnection->BackColor = System::Drawing::Color::Transparent;
			this->btnConnection->FlatAppearance->BorderSize = 0;
			this->btnConnection->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Black;
			this->btnConnection->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(82)), 
				static_cast<System::Int32>(static_cast<System::Byte>(82)), static_cast<System::Int32>(static_cast<System::Byte>(82)));
			this->btnConnection->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnConnection->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->btnConnection->ForeColor = System::Drawing::Color::White;
			this->btnConnection->Location = System::Drawing::Point(0, 89);
			this->btnConnection->Name = L"btnConnection";
			this->btnConnection->Size = System::Drawing::Size(161, 36);
			this->btnConnection->TabIndex = 18;
			this->btnConnection->Text = L"Connection";
			this->btnConnection->UseVisualStyleBackColor = false;
			// 
			// btnWelcome
			// 
			this->btnWelcome->BackColor = System::Drawing::Color::Transparent;
			this->btnWelcome->FlatAppearance->BorderSize = 0;
			this->btnWelcome->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Black;
			this->btnWelcome->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(82)), 
				static_cast<System::Int32>(static_cast<System::Byte>(82)), static_cast<System::Int32>(static_cast<System::Byte>(82)));
			this->btnWelcome->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnWelcome->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->btnWelcome->ForeColor = System::Drawing::Color::White;
			this->btnWelcome->Location = System::Drawing::Point(0, 161);
			this->btnWelcome->Name = L"btnWelcome";
			this->btnWelcome->Size = System::Drawing::Size(161, 36);
			this->btnWelcome->TabIndex = 20;
			this->btnWelcome->Text = L"Welcome Message";
			this->btnWelcome->UseVisualStyleBackColor = false;
			// 
			// pnlConnection
			// 
			this->pnlConnection->BackColor = System::Drawing::Color::Black;
			this->pnlConnection->Controls->Add(this->label3);
			this->pnlConnection->Controls->Add(this->lblCD);
			this->pnlConnection->Controls->Add(this->lblC);
			this->pnlConnection->Controls->Add(this->lblSD);
			this->pnlConnection->Controls->Add(this->lblS);
			this->pnlConnection->Controls->Add(this->pictureBox2);
			this->pnlConnection->Controls->Add(this->checkBoxUpnp);
			this->pnlConnection->Controls->Add(this->label4);
			this->pnlConnection->Controls->Add(this->label2);
			this->pnlConnection->Controls->Add(this->textBoxServerName);
			this->pnlConnection->Controls->Add(this->numericUpDownOpenPort);
			this->pnlConnection->Controls->Add(this->lblCTD);
			this->pnlConnection->Controls->Add(this->startupTabs);
			this->pnlConnection->Controls->Add(this->lblCT);
			this->pnlConnection->Controls->Add(this->buttonConnect);
			this->pnlConnection->Controls->Add(this->radioButtonServer);
			this->pnlConnection->Controls->Add(this->radioButtonHost);
			this->pnlConnection->Controls->Add(this->PictureBox1);
			this->pnlConnection->Controls->Add(this->radioButtonClient);
			this->pnlConnection->Location = System::Drawing::Point(160, 89);
			this->pnlConnection->Name = L"pnlConnection";
			this->pnlConnection->Size = System::Drawing::Size(650, 370);
			this->pnlConnection->TabIndex = 21;
			// 
			// pnlUser
			// 
			this->pnlUser->BackColor = System::Drawing::Color::Black;
			this->pnlUser->Location = System::Drawing::Point(160, 90);
			this->pnlUser->Name = L"pnlUser";
			this->pnlUser->Size = System::Drawing::Size(650, 370);
			this->pnlUser->TabIndex = 22;
			// 
			// pnlWelcome
			// 
			this->pnlWelcome->BackColor = System::Drawing::Color::Black;
			this->pnlWelcome->Location = System::Drawing::Point(160, 89);
			this->pnlWelcome->Name = L"pnlWelcome";
			this->pnlWelcome->Size = System::Drawing::Size(650, 370);
			this->pnlWelcome->TabIndex = 22;
			// 
			// lblCT
			// 
			this->lblCT->AutoSize = true;
			this->lblCT->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->lblCT->ForeColor = System::Drawing::Color::White;
			this->lblCT->Location = System::Drawing::Point(59, 36);
			this->lblCT->Name = L"lblCT";
			this->lblCT->Size = System::Drawing::Size(109, 17);
			this->lblCT->TabIndex = 31;
			this->lblCT->Text = L"Connection type";
			// 
			// lblCTD
			// 
			this->lblCTD->AutoSize = true;
			this->lblCTD->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->lblCTD->ForeColor = System::Drawing::Color::White;
			this->lblCTD->Location = System::Drawing::Point(59, 61);
			this->lblCTD->Name = L"lblCTD";
			this->lblCTD->Size = System::Drawing::Size(252, 17);
			this->lblCTD->TabIndex = 32;
			this->lblCTD->Text = L"Select how you want to start MorningStar.";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label2->ForeColor = System::Drawing::Color::White;
			this->label2->Location = System::Drawing::Point(245, 108);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(21, 17);
			this->label2->TabIndex = 34;
			this->label2->Text = L"IP:";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label4->ForeColor = System::Drawing::Color::White;
			this->label4->Location = System::Drawing::Point(538, 108);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(11, 17);
			this->label4->TabIndex = 35;
			this->label4->Text = L":";
			// 
			// pictureBox2
			// 
			this->pictureBox2->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox2.Image")));
			this->pictureBox2->Location = System::Drawing::Point(62, 164);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(546, 10);
			this->pictureBox2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox2->TabIndex = 36;
			this->pictureBox2->TabStop = false;
			// 
			// lblSD
			// 
			this->lblSD->AutoSize = true;
			this->lblSD->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->lblSD->ForeColor = System::Drawing::Color::White;
			this->lblSD->Location = System::Drawing::Point(59, 133);
			this->lblSD->Name = L"lblSD";
			this->lblSD->Size = System::Drawing::Size(138, 17);
			this->lblSD->TabIndex = 39;
			this->lblSD->Text = L"Configure your server.";
			// 
			// lblS
			// 
			this->lblS->AutoSize = true;
			this->lblS->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->lblS->ForeColor = System::Drawing::Color::White;
			this->lblS->Location = System::Drawing::Point(59, 108);
			this->lblS->Name = L"lblS";
			this->lblS->Size = System::Drawing::Size(47, 17);
			this->lblS->TabIndex = 38;
			this->lblS->Text = L"Server";
			// 
			// lblCD
			// 
			this->lblCD->AutoSize = true;
			this->lblCD->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->lblCD->ForeColor = System::Drawing::Color::White;
			this->lblCD->Location = System::Drawing::Point(59, 212);
			this->lblCD->Name = L"lblCD";
			this->lblCD->Size = System::Drawing::Size(138, 17);
			this->lblCD->TabIndex = 41;
			this->lblCD->Text = L"Configure your server.";
			// 
			// lblC
			// 
			this->lblC->AutoSize = true;
			this->lblC->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->lblC->ForeColor = System::Drawing::Color::White;
			this->lblC->Location = System::Drawing::Point(59, 187);
			this->lblC->Name = L"lblC";
			this->lblC->Size = System::Drawing::Size(47, 17);
			this->lblC->TabIndex = 40;
			this->lblC->Text = L"Server";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label3->ForeColor = System::Drawing::Color::White;
			this->label3->Location = System::Drawing::Point(261, 187);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(21, 17);
			this->label3->TabIndex = 42;
			this->label3->Text = L"IP:";
			// 
			// StartupForm
			// 
			this->AcceptButton = this->buttonOK;
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(43)), static_cast<System::Int32>(static_cast<System::Byte>(44)), 
				static_cast<System::Int32>(static_cast<System::Byte>(49)));
			this->CancelButton = this->buttonCancel;
			this->ClientSize = System::Drawing::Size(810, 460);
			this->ControlBox = false;
			this->Controls->Add(this->btnUser);
			this->Controls->Add(this->btnConnection);
			this->Controls->Add(this->btnWelcome);
			this->Controls->Add(this->TitleLabel);
			this->Controls->Add(this->pnlConnection);
			this->Controls->Add(this->pnlUser);
			this->Controls->Add(this->pnlWelcome);
			this->Controls->Add(this->buttonOK);
			this->Controls->Add(this->buttonCancel);
			this->Font = (gcnew System::Drawing::Font(L"Segoe UI", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
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
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->PictureBox1))->EndInit();
			this->pnlConnection->ResumeLayout(false);
			this->pnlConnection->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox2))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

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
