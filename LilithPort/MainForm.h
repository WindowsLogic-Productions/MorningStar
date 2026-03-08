#pragma once

#include "stdafx.h"
#include "StartupForm.h"
#include "OptionForm.h"

namespace LilithPort {
#pragma region Namespace
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;
	using namespace System::Net::Sockets;
	using namespace System::Threading;
	using namespace System::Diagnostics;

	/// <summary>
	/// MainForm の概要
	///
	/// 警告: このクラスの名前を変更する場合、このクラスが依存するすべての .resx ファイルに関連付けられた
	///          マネージ リソース コンパイラ ツールに対して 'Resource File Name' プロパティを
	///          変更する必要があります。この変更を行わないと、
	///          デザイナと、このフォームに関連付けられたローカライズ済みリソースとが、
	///          正しく相互に利用できなくなります。
	/// </summary>
	public ref class MainForm : public System::Windows::Forms::Form
	{
	public:
		MainForm(void)
		{
			InitializeComponent();
			//
			// TODO: Add constructor code here
			//TODO: ここにコンストラクタ コードを追加します
			//

			// Add member to bookmarks
			// ブックマークをメニューに登録
			String^ tmpName;
			if(MTOPTION.BOOKMARK_COUNT > 0) {
				for(UINT i=0;i < MTOPTION.BOOKMARK_COUNT;i++) {
					tmpName = gcnew String(MTOPTION.BOOKMARK_SERVER_NAME[i]);
					
					toolStripMenuItemBookMark = (gcnew System::Windows::Forms::ToolStripMenuItem());
					toolStripMenuItemBookMarkMenu->DropDownItems->Add(toolStripMenuItemBookMark);
					toolStripMenuItemBookMark->Text = tmpName;
					toolStripMenuItemBookMark->Name = L"toolStripMenuItemBookMark" + i;
					toolStripMenuItemBookMark->Tag = i;
					toolStripMenuItemBookMark->Click += gcnew System::EventHandler(this, &MainForm::toolStripMenuItemBookMark_Click);
					
					toolStripMenuItemDelBookMark = (gcnew System::Windows::Forms::ToolStripMenuItem());
					toolStripMenuItemBookMark->DropDownItems->Add(toolStripMenuItemDelBookMark);
					toolStripMenuItemDelBookMark->Text = L"&Delete bookmark";
					toolStripMenuItemDelBookMark->Tag = L"toolStripMenuItemBookMark" + i;
					toolStripMenuItemDelBookMark->Click += gcnew System::EventHandler(this, &MainForm::toolStripMenuItemDelBookMark_Click);
				}
			}

			// Register combobox to profile
			// プロファイルをコンボボックスに登録
			for(int i=0; i < Profile::ProfileList->Count; i++){
				if(Profile::ProfileList[i] == gcnew String(MTOPTION.PROFILE)){
					toolStripDropDownButtonProfile->Text = Profile::ProfileList[i];			
				}
				toolStripDropDownButtonProfile->DropDownItems->Add(Profile::ProfileList[i]);
				toolStripDropDownButtonProfile->DropDownItems[i]->Click += gcnew System::EventHandler(this, &MainForm::toolStripDropDownItemProfile_Click);
			}
		}

	protected:
		/// <summary>
		/// 使用中のリソースをすべてクリーンアップします。 Clean up all used resources.
		/// </summary>
		~MainForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::MenuStrip^  menuStrip1;
	private: System::Windows::Forms::SplitContainer^  splitContainer1;
	private: System::Windows::Forms::ListBox^  listBoxMember;
	private: System::Windows::Forms::RichTextBox^  richTextBoxLog;
	private: System::Windows::Forms::TextBox^  textBoxInput;

	private: System::Windows::Forms::ToolStripMenuItem^  toolStripMenuItemFile;
	private: System::Windows::Forms::ToolStripMenuItem^  toolStripMenuItemSaveLog;
	private: System::Windows::Forms::ToolStripSeparator^  toolStripSeparator1;
	private: System::Windows::Forms::ToolStripMenuItem^  toolStripMenuItemExit;

	private: System::Windows::Forms::ToolStripMenuItem^  toolStripMenuItemOption;
	private: System::Windows::Forms::ToolStripMenuItem^  toolStripMenuItemSetting;
	private: System::Windows::Forms::ToolStripSeparator^  toolStripSeparator2;
	private: System::Windows::Forms::ToolStripMenuItem^  toolStripMenuItemDelay;
	private: System::Windows::Forms::ToolStripMenuItem^  toolStripMenuItemDelayAuto;
	private: System::Windows::Forms::ToolStripSeparator^  toolStripSeparator4;
	private: System::Windows::Forms::ToolStripMenuItem^  toolStripMenuItemDelay2;
	private: System::Windows::Forms::ToolStripMenuItem^  toolStripMenuItemDelay3;
	private: System::Windows::Forms::ToolStripMenuItem^  toolStripMenuItemDelay4;
	private: System::Windows::Forms::ToolStripMenuItem^  toolStripMenuItemDelay5;
	private: System::Windows::Forms::ToolStripMenuItem^  toolStripMenuItemDelay6;
	private: System::Windows::Forms::ToolStripMenuItem^  toolStripMenuItemDelay7;
	private: System::Windows::Forms::ToolStripMenuItem^  toolStripMenuItemDelay8;
	private: System::Windows::Forms::ToolStripMenuItem^  toolStripMenuItemDelay9;
	private: System::Windows::Forms::ToolStripSeparator^  toolStripSeparator3;
	private: System::Windows::Forms::ToolStripMenuItem^  toolStripMenuItemRecordReplay;
	private: System::Windows::Forms::ToolStripMenuItem^  toolStripMenuItemAllowSpectator;


	private: System::Windows::Forms::ToolStripMenuItem^  toolStripMenuItemHelp;
	private: System::Windows::Forms::ToolStripMenuItem^  toolStripMenuItemViewCommand;

	private: System::Windows::Forms::ToolStripSeparator^  toolStripSeparator5;
	private: System::Windows::Forms::ToolStripMenuItem^  toolStripMenuItemVersion;

	private: System::Windows::Forms::ContextMenuStrip^  contextMenuStripMember;
	private: System::Windows::Forms::ContextMenuStrip^  contextMenuStripLog;
	private: System::Windows::Forms::ToolStripMenuItem^  contextMenuItemCopy;

	private: System::Windows::Forms::ToolStripSeparator^  toolStripSeparator6;
	private: System::Windows::Forms::ToolStripMenuItem^  contxtMenuItemSaveLog;
	private: System::Windows::Forms::ToolStripMenuItem^  toolStripMenuItemVS;
	private: System::Windows::Forms::OpenFileDialog^  openFileDialog1;
	private: System::Windows::Forms::ToolTip^  toolTipMember;
	private: System::Windows::Forms::ToolStripMenuItem^  toolStripMenuItemPing;
	private: System::Windows::Forms::ToolStripMenuItem^  toolStripMenuItemReplay;

	private: System::Windows::Forms::ToolStripMenuItem^  toolStripMenuItemWatch;
	private: System::Windows::Forms::ToolStripSeparator^  toolStripSeparator7;
	private: System::Windows::Forms::ToolStripMenuItem^  toolStripMenuItemAfterRest;
	private: System::Windows::Forms::ToolStripMenuItem^  toolStripMenuItemChangeList;
	private: System::Windows::Forms::ToolStripMenuItem^  toolStripMenuItemDelay10;
	private: System::Windows::Forms::ToolStripMenuItem^  toolStripMenuItemDelay11;
	private: System::Windows::Forms::ToolStripMenuItem^  toolStripMenuItemDelay12;
	private: System::Windows::Forms::ToolStripMenuItem^  toolStripMenuItemBookMarkMenu;
	private: System::Windows::Forms::ToolStripMenuItem^  toolStripMenuItemAddBookMark;
	private: System::Windows::Forms::ToolStripMenuItem^  toolStripMenuItemBookMark;
	private: System::Windows::Forms::ToolStripMenuItem^  toolStripMenuItemDelBookMark;
	private: System::Windows::Forms::ToolStripSeparator^  toolStripSeparator8;

	private: System::Windows::Forms::ToolStripMenuItem^  CommandToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  GameStartToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  RestartToolStripMenuItem;
	private: System::Windows::Forms::ToolStripSeparator^  toolStripSeparator9;
	private: System::Windows::Forms::ToolStripMenuItem^  LeaveToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  RestToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  SeekToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  ClearToolStripMenuItem;
	private: System::Windows::Forms::ToolStripSeparator^  toolStripSeparator10;

private: System::Windows::Forms::ToolStripMenuItem^  ToggleHitJudgeToolStripMenuItem;
private: System::Windows::Forms::ToolStripMenuItem^  LogLockToolStripMenuItem;

private: System::Windows::Forms::ToolStripMenuItem^  GetIPToolStripMenuItem;
private: System::Windows::Forms::ToolStripSeparator^  toolStripSeparator11;
private: System::Windows::Forms::ToolStripMenuItem^  GameStartNoReplayToolStripMenuItem;
private: System::Windows::Forms::ToolStripSeparator^  toolStripSeparator12;
private: System::Windows::Forms::ToolStripMenuItem^  toolStripMenuItemKick;
private: System::Windows::Forms::StatusStrip^  statusStrip1;


private: System::Windows::Forms::ToolStripDropDownButton^  toolStripDropDownButtonProfile;
private: System::Windows::Forms::ToolStripMenuItem^  toolStripMenuItemSeek;
private: System::Windows::Forms::ToolStripMenuItem^  toolStripMenuItemAutoRest;
private: System::Windows::Forms::ToolStripMenuItem^  toolStripMenuItemAutoRestEnable;
private: System::Windows::Forms::ToolStripSeparator^  toolStripSeparator13;
private: System::Windows::Forms::ToolStripMenuItem^  toolStripMenuItemAutoRestTime5;
private: System::Windows::Forms::ToolStripMenuItem^  toolStripMenuItemAutoRestTime10;
private: System::Windows::Forms::ToolStripMenuItem^  toolStripMenuItemAutoRestTime15;
private: System::Windows::Forms::ToolStripMenuItem^  toolStripMenuItemAutoRestTime20;
private: System::Windows::Forms::ToolStripMenuItem^  toolStripMenuItemAutoRestTime30;
private: System::Windows::Forms::ToolStripMenuItem^  toolStripMenuItemAutoRestTime60;
private: System::Windows::Forms::ToolStripMenuItem^  toolStripMenuItemAutoRestTime120;
private: System::Windows::Forms::ToolStripMenuItem^  toolStripMenuItemWordWrap;
private: System::Windows::Forms::ToolStripMenuItem^  toolStripMenuItemClipBoardCopy;
private: System::Windows::Forms::ToolStripMenuItem^  restOnconnectToolStripMenuItem;
private: System::Windows::Forms::ToolStripMenuItem^  whatsNewToolStripMenuItem;
private: System::Windows::Forms::ToolStripStatusLabel^  toolStripStatusLabel1;
private: System::Windows::Forms::ContextMenuStrip^  contextMenuStripTextbox;
private: System::Windows::Forms::ToolStripMenuItem^  cutToolStripMenuItem;
private: System::Windows::Forms::ToolStripMenuItem^  toolStripMenuItemCopy;

private: System::Windows::Forms::ToolStripMenuItem^  pasteToolStripMenuItem;
private: System::Windows::Forms::ToolStripMenuItem^  toolStripMenuItemAutoRestTime8h;
private: System::Windows::Forms::ToolStripMenuItem^  toolStripMenuItem12h;
private: System::Windows::Forms::ToolStripMenuItem^  checkForUpdatesToolStripMenuItem;
private: System::Windows::Forms::ToolStripSeparator^  toolStripSeparator14;
private: System::Windows::Forms::NotifyIcon^  notifyIconSysTray;
private: System::Windows::Forms::ContextMenuStrip^  contextMenuStripSysTray;
private: System::Windows::Forms::ToolStripMenuItem^  restoreToolStripMenuItem;
private: System::Windows::Forms::ToolStripSeparator^  toolStripSeparator15;
private: System::Windows::Forms::ToolStripMenuItem^  startGameToolStripMenuItem;
private: System::Windows::Forms::ToolStripMenuItem^  startGamenoReplayToolStripMenuItem;
private: System::Windows::Forms::ToolStripSeparator^  toolStripSeparator16;
private: System::Windows::Forms::ToolStripMenuItem^  toggleRestModeToolStripMenuItem;
private: System::Windows::Forms::ToolStripMenuItem^  toggleSeekModeToolStripMenuItem;
private: System::Windows::Forms::ToolStripSeparator^  toolStripSeparator17;
private: System::Windows::Forms::ToolStripMenuItem^  settingsToolStripMenuItem;
private: System::Windows::Forms::ToolStripSeparator^  toolStripSeparator18;
private: System::Windows::Forms::ToolStripMenuItem^  exitToolStripMenuItem;
private: System::Windows::Forms::ToolStripMenuItem^  reconnectToolStripMenuItem;
private: System::Windows::Forms::ToolStripMenuItem^  dFighterMaker952ndDiscordServerToolStripMenuItem;
private: System::Windows::Forms::Button^  buttonRefresh;
private: System::Windows::Forms::Button^  buttonReconnect;
private: System::Windows::Forms::Button^  buttonRest;

private: System::Windows::Forms::Button^  buttonPlay;
private: System::Windows::Forms::Button^  buttonSeek;
private: System::Windows::Forms::Button^  buttonClear;







	private:
		/// <summary>
		/// •K—v‚ÈƒfƒUƒCƒi•Ï”‚Å‚·B
		/// </summary>
		System::ComponentModel::IContainer^  components;
#pragma endregion
#pragma region Windows Form Designer generated code
		/// <summary>
		/// ƒfƒUƒCƒi ƒTƒ|[ƒg‚É•K—v‚Èƒƒ\ƒbƒh‚Å‚·B‚±‚Ìƒƒ\ƒbƒh‚Ì“à—e‚ð
		/// ƒR[ƒh ƒGƒfƒBƒ^‚Å•ÏX‚µ‚È‚¢‚Å‚­‚¾‚³‚¢B
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::Windows::Forms::ToolStripMenuItem^  ReloadListToolStripMenuItem;
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(MainForm::typeid));
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->toolStripMenuItemFile = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripMenuItemReplay = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripMenuItemSaveLog = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripSeparator1 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->toolStripMenuItemExit = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->CommandToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->GameStartToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->GameStartNoReplayToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripSeparator9 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->RestartToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->LeaveToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->RestToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->SeekToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripSeparator10 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->ClearToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->ToggleHitJudgeToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripSeparator11 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->GetIPToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripMenuItemBookMarkMenu = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripMenuItemAddBookMark = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripSeparator8 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->toolStripMenuItemOption = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripMenuItemSetting = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripSeparator2 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->toolStripMenuItemDelay = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripMenuItemDelayAuto = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripSeparator4 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->toolStripMenuItemDelay2 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripMenuItemDelay3 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripMenuItemDelay4 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripMenuItemDelay5 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripMenuItemDelay6 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripMenuItemDelay7 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripMenuItemDelay8 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripMenuItemDelay9 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripMenuItemDelay10 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripMenuItemDelay11 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripMenuItemDelay12 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripSeparator3 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->toolStripMenuItemRecordReplay = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripMenuItemAllowSpectator = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripMenuItemWordWrap = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->LogLockToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripSeparator7 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->restOnconnectToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripMenuItemAfterRest = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripMenuItemAutoRest = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripMenuItemAutoRestEnable = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripSeparator13 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->toolStripMenuItemAutoRestTime5 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripMenuItemAutoRestTime10 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripMenuItemAutoRestTime15 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripMenuItemAutoRestTime20 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripMenuItemAutoRestTime30 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripMenuItemAutoRestTime60 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripMenuItemAutoRestTime120 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripMenuItemAutoRestTime8h = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripMenuItem12h = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripMenuItemHelp = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->dFighterMaker952ndDiscordServerToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripMenuItemViewCommand = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripMenuItemChangeList = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripSeparator5 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->checkForUpdatesToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->whatsNewToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripSeparator14 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->toolStripMenuItemVersion = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->splitContainer1 = (gcnew System::Windows::Forms::SplitContainer());
			this->listBoxMember = (gcnew System::Windows::Forms::ListBox());
			this->contextMenuStripMember = (gcnew System::Windows::Forms::ContextMenuStrip(this->components));
			this->toolStripMenuItemVS = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripMenuItemWatch = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripMenuItemSeek = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripMenuItemPing = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripMenuItemClipBoardCopy = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripSeparator12 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->toolStripMenuItemKick = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->textBoxInput = (gcnew System::Windows::Forms::TextBox());
			this->contextMenuStripTextbox = (gcnew System::Windows::Forms::ContextMenuStrip(this->components));
			this->cutToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripMenuItemCopy = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->pasteToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->richTextBoxLog = (gcnew System::Windows::Forms::RichTextBox());
			this->contextMenuStripLog = (gcnew System::Windows::Forms::ContextMenuStrip(this->components));
			this->contextMenuItemCopy = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripSeparator6 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->contxtMenuItemSaveLog = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->toolTipMember = (gcnew System::Windows::Forms::ToolTip(this->components));
			this->buttonReconnect = (gcnew System::Windows::Forms::Button());
			this->buttonRest = (gcnew System::Windows::Forms::Button());
			this->buttonPlay = (gcnew System::Windows::Forms::Button());
			this->buttonSeek = (gcnew System::Windows::Forms::Button());
			this->buttonClear = (gcnew System::Windows::Forms::Button());
			this->buttonRefresh = (gcnew System::Windows::Forms::Button());
			this->statusStrip1 = (gcnew System::Windows::Forms::StatusStrip());
			this->toolStripStatusLabel1 = (gcnew System::Windows::Forms::ToolStripStatusLabel());
			this->toolStripDropDownButtonProfile = (gcnew System::Windows::Forms::ToolStripDropDownButton());
			this->notifyIconSysTray = (gcnew System::Windows::Forms::NotifyIcon(this->components));
			this->contextMenuStripSysTray = (gcnew System::Windows::Forms::ContextMenuStrip(this->components));
			this->restoreToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripSeparator15 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->startGameToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->startGamenoReplayToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripSeparator16 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->reconnectToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toggleRestModeToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toggleSeekModeToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripSeparator17 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->settingsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripSeparator18 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->exitToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			ReloadListToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->menuStrip1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->splitContainer1))->BeginInit();
			this->splitContainer1->Panel1->SuspendLayout();
			this->splitContainer1->Panel2->SuspendLayout();
			this->splitContainer1->SuspendLayout();
			this->contextMenuStripMember->SuspendLayout();
			this->contextMenuStripTextbox->SuspendLayout();
			this->contextMenuStripLog->SuspendLayout();
			this->statusStrip1->SuspendLayout();
			this->contextMenuStripSysTray->SuspendLayout();
			this->SuspendLayout();
			// 
			// ReloadListToolStripMenuItem
			// 
			ReloadListToolStripMenuItem->Name = L"ReloadListToolStripMenuItem";
			ReloadListToolStripMenuItem->ShortcutKeys = System::Windows::Forms::Keys::F5;
			ReloadListToolStripMenuItem->Size = System::Drawing::Size(237, 22);
			ReloadListToolStripMenuItem->Text = L"Refresh &list";
			ReloadListToolStripMenuItem->Visible = false;
			ReloadListToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::ReloadListToolStripMenuItem_Click);
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(5) {this->toolStripMenuItemFile, 
				this->CommandToolStripMenuItem, this->toolStripMenuItemBookMarkMenu, this->toolStripMenuItemOption, this->toolStripMenuItemHelp});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->RenderMode = System::Windows::Forms::ToolStripRenderMode::System;
			this->menuStrip1->Size = System::Drawing::Size(784, 24);
			this->menuStrip1->TabIndex = 0;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// toolStripMenuItemFile
			// 
			this->toolStripMenuItemFile->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {this->toolStripMenuItemReplay, 
				this->toolStripMenuItemSaveLog, this->toolStripSeparator1, this->toolStripMenuItemExit});
			this->toolStripMenuItemFile->Name = L"toolStripMenuItemFile";
			this->toolStripMenuItemFile->Size = System::Drawing::Size(37, 20);
			this->toolStripMenuItemFile->Text = L"&File";
			// 
			// toolStripMenuItemReplay
			// 
			this->toolStripMenuItemReplay->Name = L"toolStripMenuItemReplay";
			this->toolStripMenuItemReplay->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::O));
			this->toolStripMenuItemReplay->Size = System::Drawing::Size(209, 22);
			this->toolStripMenuItemReplay->Text = L"&Open replay file...";
			this->toolStripMenuItemReplay->Click += gcnew System::EventHandler(this, &MainForm::toolStripMenuItemReplay_Click);
			// 
			// toolStripMenuItemSaveLog
			// 
			this->toolStripMenuItemSaveLog->Name = L"toolStripMenuItemSaveLog";
			this->toolStripMenuItemSaveLog->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::S));
			this->toolStripMenuItemSaveLog->Size = System::Drawing::Size(209, 22);
			this->toolStripMenuItemSaveLog->Text = L"&Save log";
			this->toolStripMenuItemSaveLog->Click += gcnew System::EventHandler(this, &MainForm::toolStripMenuItemSaveLog_Click);
			// 
			// toolStripSeparator1
			// 
			this->toolStripSeparator1->Name = L"toolStripSeparator1";
			this->toolStripSeparator1->Size = System::Drawing::Size(206, 6);
			// 
			// toolStripMenuItemExit
			// 
			this->toolStripMenuItemExit->Name = L"toolStripMenuItemExit";
			this->toolStripMenuItemExit->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Alt | System::Windows::Forms::Keys::F4));
			this->toolStripMenuItemExit->Size = System::Drawing::Size(209, 22);
			this->toolStripMenuItemExit->Text = L"E&xit";
			this->toolStripMenuItemExit->Click += gcnew System::EventHandler(this, &MainForm::toolStripMenuItemExit_Click);
			// 
			// CommandToolStripMenuItem
			// 
			this->CommandToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(13) {this->GameStartToolStripMenuItem, 
				this->GameStartNoReplayToolStripMenuItem, this->toolStripSeparator9, this->RestartToolStripMenuItem, this->LeaveToolStripMenuItem, 
				this->RestToolStripMenuItem, this->SeekToolStripMenuItem, ReloadListToolStripMenuItem, this->toolStripSeparator10, this->ClearToolStripMenuItem, 
				this->ToggleHitJudgeToolStripMenuItem, this->toolStripSeparator11, this->GetIPToolStripMenuItem});
			this->CommandToolStripMenuItem->Name = L"CommandToolStripMenuItem";
			this->CommandToolStripMenuItem->Size = System::Drawing::Size(81, 20);
			this->CommandToolStripMenuItem->Text = L"&Commands";
			// 
			// GameStartToolStripMenuItem
			// 
			this->GameStartToolStripMenuItem->BackColor = System::Drawing::SystemColors::Control;
			this->GameStartToolStripMenuItem->Name = L"GameStartToolStripMenuItem";
			this->GameStartToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::G));
			this->GameStartToolStripMenuItem->Size = System::Drawing::Size(237, 22);
			this->GameStartToolStripMenuItem->Text = L"Start &game";
			this->GameStartToolStripMenuItem->Visible = false;
			this->GameStartToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::GameStartToolStripMenuItem_Click);
			// 
			// GameStartNoReplayToolStripMenuItem
			// 
			this->GameStartNoReplayToolStripMenuItem->Name = L"GameStartNoReplayToolStripMenuItem";
			this->GameStartNoReplayToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::T));
			this->GameStartNoReplayToolStripMenuItem->Size = System::Drawing::Size(237, 22);
			this->GameStartNoReplayToolStripMenuItem->Text = L"S&tart game (no replay)";
			this->GameStartNoReplayToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::GameStartNoReplayToolStripMenuItem_Click);
			// 
			// toolStripSeparator9
			// 
			this->toolStripSeparator9->Name = L"toolStripSeparator9";
			this->toolStripSeparator9->Size = System::Drawing::Size(234, 6);
			// 
			// RestartToolStripMenuItem
			// 
			this->RestartToolStripMenuItem->Name = L"RestartToolStripMenuItem";
			this->RestartToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::R));
			this->RestartToolStripMenuItem->Size = System::Drawing::Size(237, 22);
			this->RestartToolStripMenuItem->Text = L"&Reconnect";
			this->RestartToolStripMenuItem->Visible = false;
			this->RestartToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::RestartToolStripMenuItem_Click);
			// 
			// LeaveToolStripMenuItem
			// 
			this->LeaveToolStripMenuItem->Name = L"LeaveToolStripMenuItem";
			this->LeaveToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::L));
			this->LeaveToolStripMenuItem->Size = System::Drawing::Size(237, 22);
			this->LeaveToolStripMenuItem->Text = L"&Leave";
			this->LeaveToolStripMenuItem->Visible = false;
			this->LeaveToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::LeaveToolStripMenuItem_Click);
			// 
			// RestToolStripMenuItem
			// 
			this->RestToolStripMenuItem->Name = L"RestToolStripMenuItem";
			this->RestToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Alt | System::Windows::Forms::Keys::R));
			this->RestToolStripMenuItem->Size = System::Drawing::Size(237, 22);
			this->RestToolStripMenuItem->Text = L"Toggle rest &mode";
			this->RestToolStripMenuItem->Visible = false;
			this->RestToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::RestToolStripMenuItem_Click);
			// 
			// SeekToolStripMenuItem
			// 
			this->SeekToolStripMenuItem->Name = L"SeekToolStripMenuItem";
			this->SeekToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>(((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::Alt) 
				| System::Windows::Forms::Keys::S));
			this->SeekToolStripMenuItem->Size = System::Drawing::Size(237, 22);
			this->SeekToolStripMenuItem->Text = L"Toggle &seek mode";
			this->SeekToolStripMenuItem->Visible = false;
			this->SeekToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::SeekToolStripMenuItem_Click);
			// 
			// toolStripSeparator10
			// 
			this->toolStripSeparator10->Name = L"toolStripSeparator10";
			this->toolStripSeparator10->Size = System::Drawing::Size(234, 6);
			this->toolStripSeparator10->Visible = false;
			// 
			// ClearToolStripMenuItem
			// 
			this->ClearToolStripMenuItem->Name = L"ClearToolStripMenuItem";
			this->ClearToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>(((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::Shift) 
				| System::Windows::Forms::Keys::C));
			this->ClearToolStripMenuItem->Size = System::Drawing::Size(237, 22);
			this->ClearToolStripMenuItem->Text = L"&Clear chat";
			this->ClearToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::ClearToolStripMenuItem_Click);
			// 
			// ToggleHitJudgeToolStripMenuItem
			// 
			this->ToggleHitJudgeToolStripMenuItem->Name = L"ToggleHitJudgeToolStripMenuItem";
			this->ToggleHitJudgeToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::D));
			this->ToggleHitJudgeToolStripMenuItem->Size = System::Drawing::Size(237, 22);
			this->ToggleHitJudgeToolStripMenuItem->Text = L"Toggle &debugging info";
			this->ToggleHitJudgeToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::ToggleHitJudgeToolStripMenuItem_Click);
			// 
			// toolStripSeparator11
			// 
			this->toolStripSeparator11->Name = L"toolStripSeparator11";
			this->toolStripSeparator11->Size = System::Drawing::Size(234, 6);
			// 
			// GetIPToolStripMenuItem
			// 
			this->GetIPToolStripMenuItem->Name = L"GetIPToolStripMenuItem";
			this->GetIPToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>(((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::Shift) 
				| System::Windows::Forms::Keys::I));
			this->GetIPToolStripMenuItem->Size = System::Drawing::Size(237, 22);
			this->GetIPToolStripMenuItem->Text = L"Get &IP address";
			this->GetIPToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::GetIPToolStripMenuItem_Click);
			// 
			// toolStripMenuItemBookMarkMenu
			// 
			this->toolStripMenuItemBookMarkMenu->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {this->toolStripMenuItemAddBookMark, 
				this->toolStripSeparator8});
			this->toolStripMenuItemBookMarkMenu->Name = L"toolStripMenuItemBookMarkMenu";
			this->toolStripMenuItemBookMarkMenu->Size = System::Drawing::Size(78, 20);
			this->toolStripMenuItemBookMarkMenu->Text = L"&Bookmarks";
			// 
			// toolStripMenuItemAddBookMark
			// 
			this->toolStripMenuItemAddBookMark->Name = L"toolStripMenuItemAddBookMark";
			this->toolStripMenuItemAddBookMark->ShortcutKeys = static_cast<System::Windows::Forms::Keys>(((System::Windows::Forms::Keys::Alt | System::Windows::Forms::Keys::Shift) 
				| System::Windows::Forms::Keys::S));
			this->toolStripMenuItemAddBookMark->Size = System::Drawing::Size(198, 22);
			this->toolStripMenuItemAddBookMark->Text = L"Add &server";
			this->toolStripMenuItemAddBookMark->Click += gcnew System::EventHandler(this, &MainForm::toolStripMenuItemAddBookMark_Click);
			// 
			// toolStripSeparator8
			// 
			this->toolStripSeparator8->Name = L"toolStripSeparator8";
			this->toolStripSeparator8->Size = System::Drawing::Size(195, 6);
			// 
			// toolStripMenuItemOption
			// 
			this->toolStripMenuItemOption->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(12) {this->toolStripMenuItemSetting, 
				this->toolStripSeparator2, this->toolStripMenuItemDelay, this->toolStripSeparator3, this->toolStripMenuItemRecordReplay, this->toolStripMenuItemAllowSpectator, 
				this->toolStripMenuItemWordWrap, this->LogLockToolStripMenuItem, this->toolStripSeparator7, this->restOnconnectToolStripMenuItem, 
				this->toolStripMenuItemAfterRest, this->toolStripMenuItemAutoRest});
			this->toolStripMenuItemOption->Name = L"toolStripMenuItemOption";
			this->toolStripMenuItemOption->Size = System::Drawing::Size(61, 20);
			this->toolStripMenuItemOption->Text = L"&Options";
			// 
			// toolStripMenuItemSetting
			// 
			this->toolStripMenuItemSetting->Name = L"toolStripMenuItemSetting";
			this->toolStripMenuItemSetting->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Alt | System::Windows::Forms::Keys::S));
			this->toolStripMenuItemSetting->Size = System::Drawing::Size(247, 22);
			this->toolStripMenuItemSetting->Text = L"&Settings...";
			this->toolStripMenuItemSetting->Click += gcnew System::EventHandler(this, &MainForm::toolStripMenuItemSetting_Click);
			// 
			// toolStripSeparator2
			// 
			this->toolStripSeparator2->Name = L"toolStripSeparator2";
			this->toolStripSeparator2->Size = System::Drawing::Size(244, 6);
			// 
			// toolStripMenuItemDelay
			// 
			this->toolStripMenuItemDelay->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(13) {this->toolStripMenuItemDelayAuto, 
				this->toolStripSeparator4, this->toolStripMenuItemDelay2, this->toolStripMenuItemDelay3, this->toolStripMenuItemDelay4, this->toolStripMenuItemDelay5, 
				this->toolStripMenuItemDelay6, this->toolStripMenuItemDelay7, this->toolStripMenuItemDelay8, this->toolStripMenuItemDelay9, this->toolStripMenuItemDelay10, 
				this->toolStripMenuItemDelay11, this->toolStripMenuItemDelay12});
			this->toolStripMenuItemDelay->Name = L"toolStripMenuItemDelay";
			this->toolStripMenuItemDelay->Size = System::Drawing::Size(247, 22);
			this->toolStripMenuItemDelay->Text = L"&Delay";
			this->toolStripMenuItemDelay->Click += gcnew System::EventHandler(this, &MainForm::toolStripMenuItemDelay_Click);
			// 
			// toolStripMenuItemDelayAuto
			// 
			this->toolStripMenuItemDelayAuto->Checked = true;
			this->toolStripMenuItemDelayAuto->CheckState = System::Windows::Forms::CheckState::Checked;
			this->toolStripMenuItemDelayAuto->Name = L"toolStripMenuItemDelayAuto";
			this->toolStripMenuItemDelayAuto->ShortcutKeys = static_cast<System::Windows::Forms::Keys>(((System::Windows::Forms::Keys::Alt | System::Windows::Forms::Keys::Shift) 
				| System::Windows::Forms::Keys::A));
			this->toolStripMenuItemDelayAuto->Size = System::Drawing::Size(170, 22);
			this->toolStripMenuItemDelayAuto->Text = L"Auto";
			this->toolStripMenuItemDelayAuto->Click += gcnew System::EventHandler(this, &MainForm::toolStripMenuItemDelayAuto_Click);
			// 
			// toolStripSeparator4
			// 
			this->toolStripSeparator4->Name = L"toolStripSeparator4";
			this->toolStripSeparator4->Size = System::Drawing::Size(167, 6);
			// 
			// toolStripMenuItemDelay2
			// 
			this->toolStripMenuItemDelay2->Name = L"toolStripMenuItemDelay2";
			this->toolStripMenuItemDelay2->ShortcutKeys = static_cast<System::Windows::Forms::Keys>(((System::Windows::Forms::Keys::Alt | System::Windows::Forms::Keys::Shift) 
				| System::Windows::Forms::Keys::D2));
			this->toolStripMenuItemDelay2->Size = System::Drawing::Size(170, 22);
			this->toolStripMenuItemDelay2->Text = L"2";
			this->toolStripMenuItemDelay2->Click += gcnew System::EventHandler(this, &MainForm::toolStripMenuItemDelay2_Click);
			// 
			// toolStripMenuItemDelay3
			// 
			this->toolStripMenuItemDelay3->Name = L"toolStripMenuItemDelay3";
			this->toolStripMenuItemDelay3->ShortcutKeys = static_cast<System::Windows::Forms::Keys>(((System::Windows::Forms::Keys::Alt | System::Windows::Forms::Keys::Shift) 
				| System::Windows::Forms::Keys::D3));
			this->toolStripMenuItemDelay3->Size = System::Drawing::Size(170, 22);
			this->toolStripMenuItemDelay3->Text = L"3";
			this->toolStripMenuItemDelay3->Click += gcnew System::EventHandler(this, &MainForm::toolStripMenuItemDelay3_Click);
			// 
			// toolStripMenuItemDelay4
			// 
			this->toolStripMenuItemDelay4->Name = L"toolStripMenuItemDelay4";
			this->toolStripMenuItemDelay4->ShortcutKeys = static_cast<System::Windows::Forms::Keys>(((System::Windows::Forms::Keys::Alt | System::Windows::Forms::Keys::Shift) 
				| System::Windows::Forms::Keys::D4));
			this->toolStripMenuItemDelay4->Size = System::Drawing::Size(170, 22);
			this->toolStripMenuItemDelay4->Text = L"4";
			this->toolStripMenuItemDelay4->Click += gcnew System::EventHandler(this, &MainForm::toolStripMenuItemDelay4_Click);
			// 
			// toolStripMenuItemDelay5
			// 
			this->toolStripMenuItemDelay5->Name = L"toolStripMenuItemDelay5";
			this->toolStripMenuItemDelay5->ShortcutKeys = static_cast<System::Windows::Forms::Keys>(((System::Windows::Forms::Keys::Alt | System::Windows::Forms::Keys::Shift) 
				| System::Windows::Forms::Keys::D5));
			this->toolStripMenuItemDelay5->Size = System::Drawing::Size(170, 22);
			this->toolStripMenuItemDelay5->Text = L"5";
			this->toolStripMenuItemDelay5->Click += gcnew System::EventHandler(this, &MainForm::toolStripMenuItemDelay5_Click);
			// 
			// toolStripMenuItemDelay6
			// 
			this->toolStripMenuItemDelay6->Name = L"toolStripMenuItemDelay6";
			this->toolStripMenuItemDelay6->ShortcutKeys = static_cast<System::Windows::Forms::Keys>(((System::Windows::Forms::Keys::Alt | System::Windows::Forms::Keys::Shift) 
				| System::Windows::Forms::Keys::D6));
			this->toolStripMenuItemDelay6->Size = System::Drawing::Size(170, 22);
			this->toolStripMenuItemDelay6->Text = L"6";
			this->toolStripMenuItemDelay6->Click += gcnew System::EventHandler(this, &MainForm::toolStripMenuItemDelay6_Click);
			// 
			// toolStripMenuItemDelay7
			// 
			this->toolStripMenuItemDelay7->Name = L"toolStripMenuItemDelay7";
			this->toolStripMenuItemDelay7->ShortcutKeys = static_cast<System::Windows::Forms::Keys>(((System::Windows::Forms::Keys::Alt | System::Windows::Forms::Keys::Shift) 
				| System::Windows::Forms::Keys::D7));
			this->toolStripMenuItemDelay7->Size = System::Drawing::Size(170, 22);
			this->toolStripMenuItemDelay7->Text = L"7";
			this->toolStripMenuItemDelay7->Click += gcnew System::EventHandler(this, &MainForm::toolStripMenuItemDelay7_Click);
			// 
			// toolStripMenuItemDelay8
			// 
			this->toolStripMenuItemDelay8->Name = L"toolStripMenuItemDelay8";
			this->toolStripMenuItemDelay8->ShortcutKeys = static_cast<System::Windows::Forms::Keys>(((System::Windows::Forms::Keys::Alt | System::Windows::Forms::Keys::Shift) 
				| System::Windows::Forms::Keys::D8));
			this->toolStripMenuItemDelay8->Size = System::Drawing::Size(170, 22);
			this->toolStripMenuItemDelay8->Text = L"8";
			this->toolStripMenuItemDelay8->Click += gcnew System::EventHandler(this, &MainForm::toolStripMenuItemDelay8_Click);
			// 
			// toolStripMenuItemDelay9
			// 
			this->toolStripMenuItemDelay9->Name = L"toolStripMenuItemDelay9";
			this->toolStripMenuItemDelay9->ShortcutKeys = static_cast<System::Windows::Forms::Keys>(((System::Windows::Forms::Keys::Alt | System::Windows::Forms::Keys::Shift) 
				| System::Windows::Forms::Keys::F9));
			this->toolStripMenuItemDelay9->Size = System::Drawing::Size(170, 22);
			this->toolStripMenuItemDelay9->Text = L"9";
			this->toolStripMenuItemDelay9->Click += gcnew System::EventHandler(this, &MainForm::toolStripMenuItemDelay9_Click);
			// 
			// toolStripMenuItemDelay10
			// 
			this->toolStripMenuItemDelay10->Name = L"toolStripMenuItemDelay10";
			this->toolStripMenuItemDelay10->ShortcutKeys = static_cast<System::Windows::Forms::Keys>(((System::Windows::Forms::Keys::Alt | System::Windows::Forms::Keys::Shift) 
				| System::Windows::Forms::Keys::F10));
			this->toolStripMenuItemDelay10->Size = System::Drawing::Size(170, 22);
			this->toolStripMenuItemDelay10->Text = L"10";
			this->toolStripMenuItemDelay10->Click += gcnew System::EventHandler(this, &MainForm::toolStripMenuItemDelay10_Click);
			// 
			// toolStripMenuItemDelay11
			// 
			this->toolStripMenuItemDelay11->Name = L"toolStripMenuItemDelay11";
			this->toolStripMenuItemDelay11->ShortcutKeys = static_cast<System::Windows::Forms::Keys>(((System::Windows::Forms::Keys::Alt | System::Windows::Forms::Keys::Shift) 
				| System::Windows::Forms::Keys::F11));
			this->toolStripMenuItemDelay11->Size = System::Drawing::Size(170, 22);
			this->toolStripMenuItemDelay11->Text = L"11";
			this->toolStripMenuItemDelay11->Click += gcnew System::EventHandler(this, &MainForm::toolStripMenuItemDelay11_Click);
			// 
			// toolStripMenuItemDelay12
			// 
			this->toolStripMenuItemDelay12->Name = L"toolStripMenuItemDelay12";
			this->toolStripMenuItemDelay12->ShortcutKeys = static_cast<System::Windows::Forms::Keys>(((System::Windows::Forms::Keys::Alt | System::Windows::Forms::Keys::Shift) 
				| System::Windows::Forms::Keys::F12));
			this->toolStripMenuItemDelay12->Size = System::Drawing::Size(170, 22);
			this->toolStripMenuItemDelay12->Text = L"12";
			this->toolStripMenuItemDelay12->Click += gcnew System::EventHandler(this, &MainForm::toolStripMenuItemDelay12_Click);
			// 
			// toolStripSeparator3
			// 
			this->toolStripSeparator3->Name = L"toolStripSeparator3";
			this->toolStripSeparator3->Size = System::Drawing::Size(244, 6);
			// 
			// toolStripMenuItemRecordReplay
			// 
			this->toolStripMenuItemRecordReplay->Checked = true;
			this->toolStripMenuItemRecordReplay->CheckState = System::Windows::Forms::CheckState::Checked;
			this->toolStripMenuItemRecordReplay->Name = L"toolStripMenuItemRecordReplay";
			this->toolStripMenuItemRecordReplay->ShortcutKeys = static_cast<System::Windows::Forms::Keys>(((System::Windows::Forms::Keys::Alt | System::Windows::Forms::Keys::Shift) 
				| System::Windows::Forms::Keys::R));
			this->toolStripMenuItemRecordReplay->Size = System::Drawing::Size(247, 22);
			this->toolStripMenuItemRecordReplay->Text = L"&Save replays";
			this->toolStripMenuItemRecordReplay->Click += gcnew System::EventHandler(this, &MainForm::toolStripMenuItemRecordReplay_Click);
			// 
			// toolStripMenuItemAllowSpectator
			// 
			this->toolStripMenuItemAllowSpectator->Checked = true;
			this->toolStripMenuItemAllowSpectator->CheckState = System::Windows::Forms::CheckState::Checked;
			this->toolStripMenuItemAllowSpectator->Name = L"toolStripMenuItemAllowSpectator";
			this->toolStripMenuItemAllowSpectator->ShortcutKeys = static_cast<System::Windows::Forms::Keys>(((System::Windows::Forms::Keys::Alt | System::Windows::Forms::Keys::Shift) 
				| System::Windows::Forms::Keys::A));
			this->toolStripMenuItemAllowSpectator->Size = System::Drawing::Size(247, 22);
			this->toolStripMenuItemAllowSpectator->Text = L"&Allow spectators";
			this->toolStripMenuItemAllowSpectator->Click += gcnew System::EventHandler(this, &MainForm::toolStripMenuItemAllowSpectator_Click);
			// 
			// toolStripMenuItemWordWrap
			// 
			this->toolStripMenuItemWordWrap->Checked = true;
			this->toolStripMenuItemWordWrap->CheckState = System::Windows::Forms::CheckState::Checked;
			this->toolStripMenuItemWordWrap->Name = L"toolStripMenuItemWordWrap";
			this->toolStripMenuItemWordWrap->ShortcutKeys = static_cast<System::Windows::Forms::Keys>(((System::Windows::Forms::Keys::Alt | System::Windows::Forms::Keys::Shift) 
				| System::Windows::Forms::Keys::W));
			this->toolStripMenuItemWordWrap->Size = System::Drawing::Size(247, 22);
			this->toolStripMenuItemWordWrap->Text = L"&Word wrap";
			this->toolStripMenuItemWordWrap->Click += gcnew System::EventHandler(this, &MainForm::toolStripMenuItemWordWrap_Click);
			// 
			// LogLockToolStripMenuItem
			// 
			this->LogLockToolStripMenuItem->Checked = true;
			this->LogLockToolStripMenuItem->CheckState = System::Windows::Forms::CheckState::Checked;
			this->LogLockToolStripMenuItem->Name = L"LogLockToolStripMenuItem";
			this->LogLockToolStripMenuItem->ShortcutKeys = System::Windows::Forms::Keys::F4;
			this->LogLockToolStripMenuItem->Size = System::Drawing::Size(247, 22);
			this->LogLockToolStripMenuItem->Text = L"Auto &scroll chat";
			this->LogLockToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::LogLockToolStripMenuItem_Click);
			// 
			// toolStripSeparator7
			// 
			this->toolStripSeparator7->Name = L"toolStripSeparator7";
			this->toolStripSeparator7->Size = System::Drawing::Size(244, 6);
			// 
			// restOnconnectToolStripMenuItem
			// 
			this->restOnconnectToolStripMenuItem->Name = L"restOnconnectToolStripMenuItem";
			this->restOnconnectToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>(((System::Windows::Forms::Keys::Alt | System::Windows::Forms::Keys::Shift) 
				| System::Windows::Forms::Keys::C));
			this->restOnconnectToolStripMenuItem->Size = System::Drawing::Size(247, 22);
			this->restOnconnectToolStripMenuItem->Text = L"Rest on &connect";
			this->restOnconnectToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::restOnconnectToolStripMenuItem_Click);
			// 
			// toolStripMenuItemAfterRest
			// 
			this->toolStripMenuItemAfterRest->Name = L"toolStripMenuItemAfterRest";
			this->toolStripMenuItemAfterRest->ShortcutKeys = static_cast<System::Windows::Forms::Keys>(((System::Windows::Forms::Keys::Alt | System::Windows::Forms::Keys::Shift) 
				| System::Windows::Forms::Keys::N));
			this->toolStripMenuItemAfterRest->Size = System::Drawing::Size(247, 22);
			this->toolStripMenuItemAfterRest->Text = L"Rest after &net battle";
			this->toolStripMenuItemAfterRest->Click += gcnew System::EventHandler(this, &MainForm::toolStripMenuItemAfterRest_Click);
			// 
			// toolStripMenuItemAutoRest
			// 
			this->toolStripMenuItemAutoRest->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(11) {this->toolStripMenuItemAutoRestEnable, 
				this->toolStripSeparator13, this->toolStripMenuItemAutoRestTime5, this->toolStripMenuItemAutoRestTime10, this->toolStripMenuItemAutoRestTime15, 
				this->toolStripMenuItemAutoRestTime20, this->toolStripMenuItemAutoRestTime30, this->toolStripMenuItemAutoRestTime60, this->toolStripMenuItemAutoRestTime120, 
				this->toolStripMenuItemAutoRestTime8h, this->toolStripMenuItem12h});
			this->toolStripMenuItemAutoRest->Name = L"toolStripMenuItemAutoRest";
			this->toolStripMenuItemAutoRest->Size = System::Drawing::Size(247, 22);
			this->toolStripMenuItemAutoRest->Text = L"Auto &rest after";
			// 
			// toolStripMenuItemAutoRestEnable
			// 
			this->toolStripMenuItemAutoRestEnable->Name = L"toolStripMenuItemAutoRestEnable";
			this->toolStripMenuItemAutoRestEnable->ShortcutKeys = static_cast<System::Windows::Forms::Keys>(((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::Shift) 
				| System::Windows::Forms::Keys::A));
			this->toolStripMenuItemAutoRestEnable->Size = System::Drawing::Size(190, 22);
			this->toolStripMenuItemAutoRestEnable->Text = L"Enabled";
			this->toolStripMenuItemAutoRestEnable->Click += gcnew System::EventHandler(this, &MainForm::toolStripMenuItemAutoRestEnable_Click);
			// 
			// toolStripSeparator13
			// 
			this->toolStripSeparator13->Name = L"toolStripSeparator13";
			this->toolStripSeparator13->Size = System::Drawing::Size(187, 6);
			// 
			// toolStripMenuItemAutoRestTime5
			// 
			this->toolStripMenuItemAutoRestTime5->Name = L"toolStripMenuItemAutoRestTime5";
			this->toolStripMenuItemAutoRestTime5->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Alt | System::Windows::Forms::Keys::D1));
			this->toolStripMenuItemAutoRestTime5->Size = System::Drawing::Size(190, 22);
			this->toolStripMenuItemAutoRestTime5->Text = L"5 minutes";
			this->toolStripMenuItemAutoRestTime5->Click += gcnew System::EventHandler(this, &MainForm::toolStripMenuItemAutoRestTime5_Click);
			// 
			// toolStripMenuItemAutoRestTime10
			// 
			this->toolStripMenuItemAutoRestTime10->Name = L"toolStripMenuItemAutoRestTime10";
			this->toolStripMenuItemAutoRestTime10->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Alt | System::Windows::Forms::Keys::D2));
			this->toolStripMenuItemAutoRestTime10->Size = System::Drawing::Size(190, 22);
			this->toolStripMenuItemAutoRestTime10->Text = L"10 minutes";
			this->toolStripMenuItemAutoRestTime10->Click += gcnew System::EventHandler(this, &MainForm::toolStripMenuItemAutoRestTime10_Click);
			// 
			// toolStripMenuItemAutoRestTime15
			// 
			this->toolStripMenuItemAutoRestTime15->Name = L"toolStripMenuItemAutoRestTime15";
			this->toolStripMenuItemAutoRestTime15->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Alt | System::Windows::Forms::Keys::D3));
			this->toolStripMenuItemAutoRestTime15->Size = System::Drawing::Size(190, 22);
			this->toolStripMenuItemAutoRestTime15->Text = L"15 minutes";
			this->toolStripMenuItemAutoRestTime15->Click += gcnew System::EventHandler(this, &MainForm::toolStripMenuItemAutoRestTime15_Click);
			// 
			// toolStripMenuItemAutoRestTime20
			// 
			this->toolStripMenuItemAutoRestTime20->Name = L"toolStripMenuItemAutoRestTime20";
			this->toolStripMenuItemAutoRestTime20->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Alt | System::Windows::Forms::Keys::D4));
			this->toolStripMenuItemAutoRestTime20->Size = System::Drawing::Size(190, 22);
			this->toolStripMenuItemAutoRestTime20->Text = L"20 minutes";
			this->toolStripMenuItemAutoRestTime20->Click += gcnew System::EventHandler(this, &MainForm::toolStripMenuItemAutoRestTime20_Click);
			// 
			// toolStripMenuItemAutoRestTime30
			// 
			this->toolStripMenuItemAutoRestTime30->Name = L"toolStripMenuItemAutoRestTime30";
			this->toolStripMenuItemAutoRestTime30->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Alt | System::Windows::Forms::Keys::D5));
			this->toolStripMenuItemAutoRestTime30->Size = System::Drawing::Size(190, 22);
			this->toolStripMenuItemAutoRestTime30->Text = L"30 minutes";
			this->toolStripMenuItemAutoRestTime30->Click += gcnew System::EventHandler(this, &MainForm::toolStripMenuItemAutoRestTime30_Click);
			// 
			// toolStripMenuItemAutoRestTime60
			// 
			this->toolStripMenuItemAutoRestTime60->Name = L"toolStripMenuItemAutoRestTime60";
			this->toolStripMenuItemAutoRestTime60->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Alt | System::Windows::Forms::Keys::D6));
			this->toolStripMenuItemAutoRestTime60->Size = System::Drawing::Size(190, 22);
			this->toolStripMenuItemAutoRestTime60->Text = L"1 hour";
			this->toolStripMenuItemAutoRestTime60->Click += gcnew System::EventHandler(this, &MainForm::toolStripMenuItemAutoRestTime60_Click);
			// 
			// toolStripMenuItemAutoRestTime120
			// 
			this->toolStripMenuItemAutoRestTime120->Name = L"toolStripMenuItemAutoRestTime120";
			this->toolStripMenuItemAutoRestTime120->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Alt | System::Windows::Forms::Keys::D7));
			this->toolStripMenuItemAutoRestTime120->Size = System::Drawing::Size(190, 22);
			this->toolStripMenuItemAutoRestTime120->Text = L"2 hours";
			this->toolStripMenuItemAutoRestTime120->Click += gcnew System::EventHandler(this, &MainForm::toolStripMenuItemAutoRestTime120_Click);
			// 
			// toolStripMenuItemAutoRestTime8h
			// 
			this->toolStripMenuItemAutoRestTime8h->Name = L"toolStripMenuItemAutoRestTime8h";
			this->toolStripMenuItemAutoRestTime8h->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Alt | System::Windows::Forms::Keys::D8));
			this->toolStripMenuItemAutoRestTime8h->Size = System::Drawing::Size(190, 22);
			this->toolStripMenuItemAutoRestTime8h->Text = L"8 hours";
			this->toolStripMenuItemAutoRestTime8h->Click += gcnew System::EventHandler(this, &MainForm::toolStripMenuItemAutoRestTime8h_Click);
			// 
			// toolStripMenuItem12h
			// 
			this->toolStripMenuItem12h->Name = L"toolStripMenuItem12h";
			this->toolStripMenuItem12h->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Alt | System::Windows::Forms::Keys::D9));
			this->toolStripMenuItem12h->Size = System::Drawing::Size(190, 22);
			this->toolStripMenuItem12h->Text = L"12 hours";
			this->toolStripMenuItem12h->Click += gcnew System::EventHandler(this, &MainForm::toolStripMenuItem12h_Click);
			// 
			// toolStripMenuItemHelp
			// 
			this->toolStripMenuItemHelp->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(8) {this->dFighterMaker952ndDiscordServerToolStripMenuItem, 
				this->toolStripMenuItemViewCommand, this->toolStripMenuItemChangeList, this->toolStripSeparator5, this->checkForUpdatesToolStripMenuItem, 
				this->whatsNewToolStripMenuItem, this->toolStripSeparator14, this->toolStripMenuItemVersion});
			this->toolStripMenuItemHelp->Name = L"toolStripMenuItemHelp";
			this->toolStripMenuItemHelp->ShortcutKeyDisplayString = L"Ctrl+L";
			this->toolStripMenuItemHelp->Size = System::Drawing::Size(44, 20);
			this->toolStripMenuItemHelp->Text = L"&Help";
			// 
			// dFighterMaker952ndDiscordServerToolStripMenuItem
			// 
			this->dFighterMaker952ndDiscordServerToolStripMenuItem->Name = L"dFighterMaker952ndDiscordServerToolStripMenuItem";
			this->dFighterMaker952ndDiscordServerToolStripMenuItem->Size = System::Drawing::Size(285, 22);
			this->dFighterMaker952ndDiscordServerToolStripMenuItem->Text = L"2D Fighter Maker 95/2nd. Discord Server";
			this->dFighterMaker952ndDiscordServerToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::dFighterMaker952ndDiscordServerToolStripMenuItem_Click);
			// 
			// toolStripMenuItemViewCommand
			// 
			this->toolStripMenuItemViewCommand->Name = L"toolStripMenuItemViewCommand";
			this->toolStripMenuItemViewCommand->ShortcutKeys = System::Windows::Forms::Keys::F1;
			this->toolStripMenuItemViewCommand->Size = System::Drawing::Size(285, 22);
			this->toolStripMenuItemViewCommand->Text = L"Shortcut and &command list";
			this->toolStripMenuItemViewCommand->Click += gcnew System::EventHandler(this, &MainForm::toolStripMenuItemViewCommand_Click);
			// 
			// toolStripMenuItemChangeList
			// 
			this->toolStripMenuItemChangeList->Name = L"toolStripMenuItemChangeList";
			this->toolStripMenuItemChangeList->ShortcutKeys = static_cast<System::Windows::Forms::Keys>(((System::Windows::Forms::Keys::Alt | System::Windows::Forms::Keys::Shift) 
				| System::Windows::Forms::Keys::L));
			this->toolStripMenuItemChangeList->Size = System::Drawing::Size(285, 22);
			this->toolStripMenuItemChangeList->Text = L"Toggle list &view";
			this->toolStripMenuItemChangeList->Click += gcnew System::EventHandler(this, &MainForm::toolStripMenuItemChangeList_Click);
			// 
			// toolStripSeparator5
			// 
			this->toolStripSeparator5->Name = L"toolStripSeparator5";
			this->toolStripSeparator5->Size = System::Drawing::Size(282, 6);
			// 
			// checkForUpdatesToolStripMenuItem
			// 
			this->checkForUpdatesToolStripMenuItem->Name = L"checkForUpdatesToolStripMenuItem";
			this->checkForUpdatesToolStripMenuItem->ShortcutKeys = System::Windows::Forms::Keys::F5;
			this->checkForUpdatesToolStripMenuItem->Size = System::Drawing::Size(285, 22);
			this->checkForUpdatesToolStripMenuItem->Text = L"Check for updates...";
			this->checkForUpdatesToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::checkForUpdatesToolStripMenuItem_Click);
			// 
			// whatsNewToolStripMenuItem
			// 
			this->whatsNewToolStripMenuItem->Name = L"whatsNewToolStripMenuItem";
			this->whatsNewToolStripMenuItem->ShortcutKeys = System::Windows::Forms::Keys::F3;
			this->whatsNewToolStripMenuItem->Size = System::Drawing::Size(285, 22);
			this->whatsNewToolStripMenuItem->Text = L"What\'s &new\?";
			this->whatsNewToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::whatsNewToolStripMenuItem_Click);
			// 
			// toolStripSeparator14
			// 
			this->toolStripSeparator14->Name = L"toolStripSeparator14";
			this->toolStripSeparator14->Size = System::Drawing::Size(282, 6);
			// 
			// toolStripMenuItemVersion
			// 
			this->toolStripMenuItemVersion->Name = L"toolStripMenuItemVersion";
			this->toolStripMenuItemVersion->ShortcutKeys = System::Windows::Forms::Keys::F2;
			this->toolStripMenuItemVersion->Size = System::Drawing::Size(285, 22);
			this->toolStripMenuItemVersion->Text = L"&About";
			this->toolStripMenuItemVersion->Click += gcnew System::EventHandler(this, &MainForm::toolStripMenuItemVersion_Click);
			// 
			// splitContainer1
			// 
			this->splitContainer1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
				| System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->splitContainer1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->splitContainer1->Location = System::Drawing::Point(0, 24);
			this->splitContainer1->Name = L"splitContainer1";
			// 
			// splitContainer1.Panel1
			// 
			this->splitContainer1->Panel1->Controls->Add(this->listBoxMember);
			// 
			// splitContainer1.Panel2
			// 
			this->splitContainer1->Panel2->Controls->Add(this->textBoxInput);
			this->splitContainer1->Panel2->Controls->Add(this->richTextBoxLog);
			this->splitContainer1->Size = System::Drawing::Size(784, 362);
			this->splitContainer1->SplitterDistance = 172;
			this->splitContainer1->TabIndex = 2;
			this->splitContainer1->TabStop = false;
			// 
			// listBoxMember
			// 
			this->listBoxMember->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->listBoxMember->ContextMenuStrip = this->contextMenuStripMember;
			this->listBoxMember->Dock = System::Windows::Forms::DockStyle::Fill;
			this->listBoxMember->DrawMode = System::Windows::Forms::DrawMode::OwnerDrawFixed;
			this->listBoxMember->FormattingEnabled = true;
			this->listBoxMember->ItemHeight = 12;
			this->listBoxMember->Location = System::Drawing::Point(0, 0);
			this->listBoxMember->Name = L"listBoxMember";
			this->listBoxMember->Size = System::Drawing::Size(170, 360);
			this->listBoxMember->TabIndex = 2;
			this->listBoxMember->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &MainForm::listBoxMember_MouseClick);
			this->listBoxMember->DrawItem += gcnew System::Windows::Forms::DrawItemEventHandler(this, &MainForm::listBoxMember_DrawItem);
			this->listBoxMember->MouseDoubleClick += gcnew System::Windows::Forms::MouseEventHandler(this, &MainForm::listBoxMember_MouseDoubleClick);
			// 
			// contextMenuStripMember
			// 
			this->contextMenuStripMember->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(7) {this->toolStripMenuItemVS, 
				this->toolStripMenuItemWatch, this->toolStripMenuItemSeek, this->toolStripMenuItemPing, this->toolStripMenuItemClipBoardCopy, 
				this->toolStripSeparator12, this->toolStripMenuItemKick});
			this->contextMenuStripMember->Name = L"contextMenuStrip1";
			this->contextMenuStripMember->RenderMode = System::Windows::Forms::ToolStripRenderMode::System;
			this->contextMenuStripMember->ShowImageMargin = false;
			this->contextMenuStripMember->Size = System::Drawing::Size(138, 142);
			this->contextMenuStripMember->Opening += gcnew System::ComponentModel::CancelEventHandler(this, &MainForm::contextMenuStripMember_Opening);
			// 
			// toolStripMenuItemVS
			// 
			this->toolStripMenuItemVS->Name = L"toolStripMenuItemVS";
			this->toolStripMenuItemVS->Size = System::Drawing::Size(137, 22);
			this->toolStripMenuItemVS->Text = L"Fight";
			this->toolStripMenuItemVS->Click += gcnew System::EventHandler(this, &MainForm::toolStripMenuItemVS_Click);
			// 
			// toolStripMenuItemWatch
			// 
			this->toolStripMenuItemWatch->Name = L"toolStripMenuItemWatch";
			this->toolStripMenuItemWatch->Size = System::Drawing::Size(137, 22);
			this->toolStripMenuItemWatch->Text = L"Spectate";
			this->toolStripMenuItemWatch->Click += gcnew System::EventHandler(this, &MainForm::toolStripMenuItemWatch_Click);
			// 
			// toolStripMenuItemSeek
			// 
			this->toolStripMenuItemSeek->Name = L"toolStripMenuItemSeek";
			this->toolStripMenuItemSeek->Size = System::Drawing::Size(137, 22);
			this->toolStripMenuItemSeek->Text = L"Seek / Challenge";
			this->toolStripMenuItemSeek->Click += gcnew System::EventHandler(this, &MainForm::toolStripMenuItemSeek_Click);
			// 
			// toolStripMenuItemPing
			// 
			this->toolStripMenuItemPing->Name = L"toolStripMenuItemPing";
			this->toolStripMenuItemPing->Size = System::Drawing::Size(137, 22);
			this->toolStripMenuItemPing->Text = L"Ping";
			this->toolStripMenuItemPing->Click += gcnew System::EventHandler(this, &MainForm::toolStripMenuItemPing_Click);
			// 
			// toolStripMenuItemClipBoardCopy
			// 
			this->toolStripMenuItemClipBoardCopy->Name = L"toolStripMenuItemClipBoardCopy";
			this->toolStripMenuItemClipBoardCopy->Size = System::Drawing::Size(137, 22);
			this->toolStripMenuItemClipBoardCopy->Text = L"Copy username";
			this->toolStripMenuItemClipBoardCopy->Click += gcnew System::EventHandler(this, &MainForm::toolStripMenuItemClipBoardCopy_Click);
			// 
			// toolStripSeparator12
			// 
			this->toolStripSeparator12->Name = L"toolStripSeparator12";
			this->toolStripSeparator12->Size = System::Drawing::Size(134, 6);
			// 
			// toolStripMenuItemKick
			// 
			this->toolStripMenuItemKick->Name = L"toolStripMenuItemKick";
			this->toolStripMenuItemKick->Size = System::Drawing::Size(137, 22);
			this->toolStripMenuItemKick->Text = L"Kick";
			this->toolStripMenuItemKick->Click += gcnew System::EventHandler(this, &MainForm::toolStripMenuItemKick_Click);
			// 
			// textBoxInput
			// 
			this->textBoxInput->BackColor = System::Drawing::SystemColors::Window;
			this->textBoxInput->ContextMenuStrip = this->contextMenuStripTextbox;
			this->textBoxInput->Dock = System::Windows::Forms::DockStyle::Bottom;
			this->textBoxInput->Location = System::Drawing::Point(0, 340);
			this->textBoxInput->MaxLength = 127;
			this->textBoxInput->Name = L"textBoxInput";
			this->textBoxInput->Size = System::Drawing::Size(606, 20);
			this->textBoxInput->TabIndex = 0;
			this->textBoxInput->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MainForm::textBoxInput_KeyDown);
			// 
			// contextMenuStripTextbox
			// 
			this->contextMenuStripTextbox->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {this->cutToolStripMenuItem, 
				this->toolStripMenuItemCopy, this->pasteToolStripMenuItem});
			this->contextMenuStripTextbox->Name = L"contextMenuStrip2";
			this->contextMenuStripTextbox->RenderMode = System::Windows::Forms::ToolStripRenderMode::System;
			this->contextMenuStripTextbox->ShowImageMargin = false;
			this->contextMenuStripTextbox->Size = System::Drawing::Size(120, 70);
			this->contextMenuStripTextbox->Opening += gcnew System::ComponentModel::CancelEventHandler(this, &MainForm::contextMenuStripTextbox_Opening);
			// 
			// cutToolStripMenuItem
			// 
			this->cutToolStripMenuItem->Name = L"cutToolStripMenuItem";
			this->cutToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::X));
			this->cutToolStripMenuItem->Size = System::Drawing::Size(119, 22);
			this->cutToolStripMenuItem->Text = L"C&ut";
			this->cutToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::cutToolStripMenuItem_Click);
			// 
			// toolStripMenuItemCopy
			// 
			this->toolStripMenuItemCopy->Name = L"toolStripMenuItemCopy";
			this->toolStripMenuItemCopy->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::C));
			this->toolStripMenuItemCopy->Size = System::Drawing::Size(119, 22);
			this->toolStripMenuItemCopy->Text = L"&Copy";
			this->toolStripMenuItemCopy->Click += gcnew System::EventHandler(this, &MainForm::toolStripMenuItemCopy_Click);
			// 
			// pasteToolStripMenuItem
			// 
			this->pasteToolStripMenuItem->Name = L"pasteToolStripMenuItem";
			this->pasteToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::V));
			this->pasteToolStripMenuItem->Size = System::Drawing::Size(119, 22);
			this->pasteToolStripMenuItem->Text = L"&Paste";
			this->pasteToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::pasteToolStripMenuItem_Click);
			// 
			// richTextBoxLog
			// 
			this->richTextBoxLog->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
				| System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->richTextBoxLog->BackColor = System::Drawing::SystemColors::Window;
			this->richTextBoxLog->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->richTextBoxLog->ContextMenuStrip = this->contextMenuStripLog;
			this->richTextBoxLog->Location = System::Drawing::Point(0, 0);
			this->richTextBoxLog->Name = L"richTextBoxLog";
			this->richTextBoxLog->ReadOnly = true;
			this->richTextBoxLog->Size = System::Drawing::Size(606, 339);
			this->richTextBoxLog->TabIndex = 0;
			this->richTextBoxLog->TabStop = false;
			this->richTextBoxLog->Text = L"";
			this->richTextBoxLog->WordWrap = false;
			this->richTextBoxLog->LinkClicked += gcnew System::Windows::Forms::LinkClickedEventHandler(this, &MainForm::richTextBoxLog_LinkClicked);
			// 
			// contextMenuStripLog
			// 
			this->contextMenuStripLog->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {this->contextMenuItemCopy, 
				this->toolStripSeparator6, this->contxtMenuItemSaveLog});
			this->contextMenuStripLog->Name = L"contextMenuStrip2";
			this->contextMenuStripLog->RenderMode = System::Windows::Forms::ToolStripRenderMode::System;
			this->contextMenuStripLog->ShowImageMargin = false;
			this->contextMenuStripLog->Size = System::Drawing::Size(134, 54);
			// 
			// contextMenuItemCopy
			// 
			this->contextMenuItemCopy->Name = L"contextMenuItemCopy";
			this->contextMenuItemCopy->Size = System::Drawing::Size(133, 22);
			this->contextMenuItemCopy->Text = L"&Copy";
			this->contextMenuItemCopy->Click += gcnew System::EventHandler(this, &MainForm::contextMenuItemCopy_Click);
			// 
			// toolStripSeparator6
			// 
			this->toolStripSeparator6->Name = L"toolStripSeparator6";
			this->toolStripSeparator6->Size = System::Drawing::Size(130, 6);
			// 
			// contxtMenuItemSaveLog
			// 
			this->contxtMenuItemSaveLog->Name = L"contxtMenuItemSaveLog";
			this->contxtMenuItemSaveLog->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::S));
			this->contxtMenuItemSaveLog->Size = System::Drawing::Size(133, 22);
			this->contxtMenuItemSaveLog->Text = L"&Save log";
			this->contxtMenuItemSaveLog->Click += gcnew System::EventHandler(this, &MainForm::toolStripMenuItemSaveLog_Click);
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->Filter = L"MT Replay file (*.mtr)|*.mtr";
			this->openFileDialog1->Title = L"MorningStar—p‚ÌƒŠƒvƒŒƒCƒtƒ@ƒCƒ‹";
			// 
			// buttonReconnect
			// 
			this->buttonReconnect->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->buttonReconnect->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"buttonReconnect.Image")));
			this->buttonReconnect->Location = System::Drawing::Point(177, 392);
			this->buttonReconnect->Name = L"buttonReconnect";
			this->buttonReconnect->Size = System::Drawing::Size(48, 25);
			this->buttonReconnect->TabIndex = 5;
			this->toolTipMember->SetToolTip(this->buttonReconnect, L"Reconnect or go to free play.");
			this->buttonReconnect->UseVisualStyleBackColor = true;
			this->buttonReconnect->Click += gcnew System::EventHandler(this, &MainForm::buttonReconnect_Click);
			// 
			// buttonRest
			// 
			this->buttonRest->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->buttonRest->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"buttonRest.Image")));
			this->buttonRest->Location = System::Drawing::Point(231, 392);
			this->buttonRest->Name = L"buttonRest";
			this->buttonRest->Size = System::Drawing::Size(48, 25);
			this->buttonRest->TabIndex = 6;
			this->toolTipMember->SetToolTip(this->buttonRest, L"Toggle rest mode.");
			this->buttonRest->UseVisualStyleBackColor = true;
			this->buttonRest->Click += gcnew System::EventHandler(this, &MainForm::button2_Click);
			// 
			// buttonPlay
			// 
			this->buttonPlay->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->buttonPlay->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"buttonPlay.Image")));
			this->buttonPlay->Location = System::Drawing::Point(285, 392);
			this->buttonPlay->Name = L"buttonPlay";
			this->buttonPlay->Size = System::Drawing::Size(48, 25);
			this->buttonPlay->TabIndex = 7;
			this->toolTipMember->SetToolTip(this->buttonPlay, L"Start single player mode.");
			this->buttonPlay->UseVisualStyleBackColor = true;
			this->buttonPlay->Click += gcnew System::EventHandler(this, &MainForm::buttonPlay_Click);
			// 
			// buttonSeek
			// 
			this->buttonSeek->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->buttonSeek->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"buttonSeek.Image")));
			this->buttonSeek->Location = System::Drawing::Point(339, 392);
			this->buttonSeek->Name = L"buttonSeek";
			this->buttonSeek->Size = System::Drawing::Size(48, 25);
			this->buttonSeek->TabIndex = 8;
			this->toolTipMember->SetToolTip(this->buttonSeek, L"Toggle seek mode.");
			this->buttonSeek->UseVisualStyleBackColor = true;
			this->buttonSeek->Click += gcnew System::EventHandler(this, &MainForm::buttonSeek_Click);
			// 
			// buttonClear
			// 
			this->buttonClear->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->buttonClear->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"buttonClear.Image")));
			this->buttonClear->Location = System::Drawing::Point(393, 392);
			this->buttonClear->Name = L"buttonClear";
			this->buttonClear->Size = System::Drawing::Size(48, 25);
			this->buttonClear->TabIndex = 9;
			this->toolTipMember->SetToolTip(this->buttonClear, L"Clear chat.");
			this->buttonClear->UseVisualStyleBackColor = true;
			this->buttonClear->Click += gcnew System::EventHandler(this, &MainForm::buttonClear_Click);
			// 
			// buttonRefresh
			// 
			this->buttonRefresh->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->buttonRefresh->Location = System::Drawing::Point(20, 393);
			this->buttonRefresh->Name = L"buttonRefresh";
			this->buttonRefresh->Size = System::Drawing::Size(138, 23);
			this->buttonRefresh->TabIndex = 4;
			this->buttonRefresh->Text = L"Refresh List";
			this->toolTipMember->SetToolTip(this->buttonRefresh, L"Update the member list if it\'s desynced from the server.");
			this->buttonRefresh->UseVisualStyleBackColor = true;
			this->buttonRefresh->Click += gcnew System::EventHandler(this, &MainForm::buttonRefresh_Click);
			// 
			// statusStrip1
			// 
			this->statusStrip1->BackColor = System::Drawing::Color::Transparent;
			this->statusStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {this->toolStripStatusLabel1, 
				this->toolStripDropDownButtonProfile});
			this->statusStrip1->Location = System::Drawing::Point(0, 419);
			this->statusStrip1->Name = L"statusStrip1";
			this->statusStrip1->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->statusStrip1->Size = System::Drawing::Size(784, 22);
			this->statusStrip1->TabIndex = 3;
			this->statusStrip1->Text = L"statusStrip1";
			// 
			// toolStripStatusLabel1
			// 
			this->toolStripStatusLabel1->ForeColor = System::Drawing::Color::Black;
			this->toolStripStatusLabel1->Name = L"toolStripStatusLabel1";
			this->toolStripStatusLabel1->Size = System::Drawing::Size(91, 17);
			this->toolStripStatusLabel1->Text = L"Selected profile:";
			// 
			// toolStripDropDownButtonProfile
			// 
			this->toolStripDropDownButtonProfile->Alignment = System::Windows::Forms::ToolStripItemAlignment::Right;
			this->toolStripDropDownButtonProfile->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Text;
			this->toolStripDropDownButtonProfile->ImageScaling = System::Windows::Forms::ToolStripItemImageScaling::None;
			this->toolStripDropDownButtonProfile->Name = L"toolStripDropDownButtonProfile";
			this->toolStripDropDownButtonProfile->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->toolStripDropDownButtonProfile->Size = System::Drawing::Size(13, 20);
			// 
			// notifyIconSysTray
			// 
			this->notifyIconSysTray->ContextMenuStrip = this->contextMenuStripSysTray;
			this->notifyIconSysTray->Icon = (cli::safe_cast<System::Drawing::Icon^  >(resources->GetObject(L"notifyIconSysTray.Icon")));
			this->notifyIconSysTray->Text = L"MorningStar";
			this->notifyIconSysTray->Visible = true;
			this->notifyIconSysTray->MouseDoubleClick += gcnew System::Windows::Forms::MouseEventHandler(this, &MainForm::notifyIconSysTray_MouseDoubleClick);
			// 
			// contextMenuStripSysTray
			// 
			this->contextMenuStripSysTray->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(12) {this->restoreToolStripMenuItem, 
				this->toolStripSeparator15, this->startGameToolStripMenuItem, this->startGamenoReplayToolStripMenuItem, this->toolStripSeparator16, 
				this->reconnectToolStripMenuItem, this->toggleRestModeToolStripMenuItem, this->toggleSeekModeToolStripMenuItem, this->toolStripSeparator17, 
				this->settingsToolStripMenuItem, this->toolStripSeparator18, this->exitToolStripMenuItem});
			this->contextMenuStripSysTray->Name = L"contextMenuStripSysTray";
			this->contextMenuStripSysTray->RenderMode = System::Windows::Forms::ToolStripRenderMode::System;
			this->contextMenuStripSysTray->Size = System::Drawing::Size(192, 204);
			// 
			// restoreToolStripMenuItem
			// 
			this->restoreToolStripMenuItem->Name = L"restoreToolStripMenuItem";
			this->restoreToolStripMenuItem->Size = System::Drawing::Size(191, 22);
			this->restoreToolStripMenuItem->Text = L"Restore";
			this->restoreToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::restoreToolStripMenuItem_Click);
			// 
			// toolStripSeparator15
			// 
			this->toolStripSeparator15->Name = L"toolStripSeparator15";
			this->toolStripSeparator15->Size = System::Drawing::Size(188, 6);
			// 
			// startGameToolStripMenuItem
			// 
			this->startGameToolStripMenuItem->Name = L"startGameToolStripMenuItem";
			this->startGameToolStripMenuItem->Size = System::Drawing::Size(191, 22);
			this->startGameToolStripMenuItem->Text = L"Start game";
			this->startGameToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::startGameToolStripMenuItem_Click);
			// 
			// startGamenoReplayToolStripMenuItem
			// 
			this->startGamenoReplayToolStripMenuItem->Name = L"startGamenoReplayToolStripMenuItem";
			this->startGamenoReplayToolStripMenuItem->Size = System::Drawing::Size(191, 22);
			this->startGamenoReplayToolStripMenuItem->Text = L"Start game (no replay)";
			this->startGamenoReplayToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::startGamenoReplayToolStripMenuItem_Click);
			// 
			// toolStripSeparator16
			// 
			this->toolStripSeparator16->Name = L"toolStripSeparator16";
			this->toolStripSeparator16->Size = System::Drawing::Size(188, 6);
			// 
			// reconnectToolStripMenuItem
			// 
			this->reconnectToolStripMenuItem->Name = L"reconnectToolStripMenuItem";
			this->reconnectToolStripMenuItem->Size = System::Drawing::Size(191, 22);
			this->reconnectToolStripMenuItem->Text = L"Reconnect";
			this->reconnectToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::reconnectToolStripMenuItem_Click);
			// 
			// toggleRestModeToolStripMenuItem
			// 
			this->toggleRestModeToolStripMenuItem->Name = L"toggleRestModeToolStripMenuItem";
			this->toggleRestModeToolStripMenuItem->Size = System::Drawing::Size(191, 22);
			this->toggleRestModeToolStripMenuItem->Text = L"Toggle rest mode";
			this->toggleRestModeToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::toggleRestModeToolStripMenuItem_Click);
			// 
			// toggleSeekModeToolStripMenuItem
			// 
			this->toggleSeekModeToolStripMenuItem->Name = L"toggleSeekModeToolStripMenuItem";
			this->toggleSeekModeToolStripMenuItem->Size = System::Drawing::Size(191, 22);
			this->toggleSeekModeToolStripMenuItem->Text = L"Toggle seek mode";
			this->toggleSeekModeToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::toggleSeekModeToolStripMenuItem_Click);
			// 
			// toolStripSeparator17
			// 
			this->toolStripSeparator17->Name = L"toolStripSeparator17";
			this->toolStripSeparator17->Size = System::Drawing::Size(188, 6);
			// 
			// settingsToolStripMenuItem
			// 
			this->settingsToolStripMenuItem->Name = L"settingsToolStripMenuItem";
			this->settingsToolStripMenuItem->Size = System::Drawing::Size(191, 22);
			this->settingsToolStripMenuItem->Text = L"Settings";
			this->settingsToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::settingsToolStripMenuItem_Click);
			// 
			// toolStripSeparator18
			// 
			this->toolStripSeparator18->Name = L"toolStripSeparator18";
			this->toolStripSeparator18->Size = System::Drawing::Size(188, 6);
			// 
			// exitToolStripMenuItem
			// 
			this->exitToolStripMenuItem->Name = L"exitToolStripMenuItem";
			this->exitToolStripMenuItem->Size = System::Drawing::Size(191, 22);
			this->exitToolStripMenuItem->Text = L"Exit";
			this->exitToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::exitToolStripMenuItem_Click);
			// 
			// MainForm
			// 
			this->AllowDrop = true;
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->ClientSize = System::Drawing::Size(784, 441);
			this->Controls->Add(this->buttonClear);
			this->Controls->Add(this->buttonSeek);
			this->Controls->Add(this->buttonPlay);
			this->Controls->Add(this->buttonRest);
			this->Controls->Add(this->buttonReconnect);
			this->Controls->Add(this->buttonRefresh);
			this->Controls->Add(this->menuStrip1);
			this->Controls->Add(this->statusStrip1);
			this->Controls->Add(this->splitContainer1);
			this->ForeColor = System::Drawing::SystemColors::ControlText;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^  >(resources->GetObject(L"$this.Icon")));
			this->MainMenuStrip = this->menuStrip1;
			this->MinimumSize = System::Drawing::Size(800, 480);
			this->Name = L"MainForm";
			this->Text = L"MorningStar";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &MainForm::MainForm_FormClosing);
			this->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &MainForm::MainForm_FormClosed);
			this->Load += gcnew System::EventHandler(this, &MainForm::MainForm_Load);
			this->Shown += gcnew System::EventHandler(this, &MainForm::MainForm_Shown);
			this->DragDrop += gcnew System::Windows::Forms::DragEventHandler(this, &MainForm::MainForm_DragDrop);
			this->DragEnter += gcnew System::Windows::Forms::DragEventHandler(this, &MainForm::MainForm_DragEnter);
			this->Resize += gcnew System::EventHandler(this, &MainForm::MainForm_Resize);
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->splitContainer1->Panel1->ResumeLayout(false);
			this->splitContainer1->Panel2->ResumeLayout(false);
			this->splitContainer1->Panel2->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->splitContainer1))->EndInit();
			this->splitContainer1->ResumeLayout(false);
			this->contextMenuStripMember->ResumeLayout(false);
			this->contextMenuStripTextbox->ResumeLayout(false);
			this->contextMenuStripLog->ResumeLayout(false);
			this->statusStrip1->ResumeLayout(false);
			this->statusStrip1->PerformLayout();
			this->contextMenuStripSysTray->ResumeLayout(false);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
#pragma region Variables
	private:
		bool IsClipboardEmpty(){
        return Clipboard::GetDataObject() == nullptr;
		}

		static OptionForm^ Option;

		static bool IsFormClosing;
		static SERVER_MODE ServerMode;
		static LIST_VIEW ListView;
		static String^ ReplayFilePath;

		// ƒuƒbƒNƒ}[ƒN
		Object^ tmpIP;
		IntPtr BookMarkServerName;
		IntPtr BookMarkConnectIP;

		// ƒ`ƒƒƒbƒg—š—ð
		static int ChatHistoryNumber;
		static Generic::List<String^>^ ChatHistory;

		// ŠeF
		static array<Color>^ NameColor;
		static array<Color>^ StateRectColor;
		static Color TalkMessageColor;
		static Color SystemMessageColor;
		static Color ErrorMessageColor;
		static Color DebugMessageColor;
		static Color NoticeBackColor;
		static Color CommentBackColor;
		static Color SecretColor;

		delegate void WriteMessageDelegate(String^ msg, Color color);

		// MemberInfo‚³‚ñ‚Ístdafx.h‚É‚¨ˆø‰z‚µ‚µ‚Ü‚µ‚½
		static Generic::List<MemberInfo^>^ MemberList;
		static Generic::List<MemberInfoBackUp^>^ MemberListBackUp;
		static UINT16 IDCounter; // Max 3FFF(16383)
		static DWORD Ping;

		static Thread^ GameThread;
		static UdpClient^ UDP;
		static String^ ServerName;
		static String^ ConnectIP;
		static bool AfterCloseUDP; // ‘Îí’†‚ÌŽI—Ž‚¿‚ÉŠª‚«ž‚Ü‚ê‚È‚¢‚æ‚¤‚É

		// IPŽæ“¾—p
		static WebClient^ GetIPClient;
		static Uri^ GetIPUri = gcnew Uri("http://checkip.dyndns.org/");
		static Thread^ TimerGetIPThread;
		static bool    GetIPCancelled;
		static bool    GetIPSleeping;

		// ƒ`[ƒ€HPŽ‚¿‰z‚µ—p
		static Thread^ SetTeamHPThread;
		static UINT P_HP;
		static UINT Winner;

		// ‰ñü‚Ì¶Ž€”»’è
		static Thread^ SonarThread;
		static bool    Ranging;
		static bool    SonarSleeping;

		// ƒlƒbƒg‘ÎíŠÖ˜A
		ref struct VersusInfo
		{
			UINT           SEQUENCE;  // ‚â‚èŽæ‚è“¯Šú—p
			bool           SLEEPING;  // ƒXƒŒƒbƒh‘Ò‹@—p
			int            WAITING;   // ƒpƒPŽóM‘Ò‹@—p 1-:Wait ON 2:Sleep
			DWORD          START_UP;  // ‹N“®ŽžŠÔ
			IPEndPoint^    IP_EP;
			array<UINT>^   PING;
			array<UINT>^   PONG;
			UINT           DELAY;     // ƒfƒBƒŒƒC‚Í‘å‚«‚¢•û‚É‡‚í‚¹‚é
			UINT           INTERVAL;  // ‘—MŠÔŠu ¬:1f‚ ‚½‚è‚Ì“ü—Íƒf[ƒ^‘—M‰ñ”‚ð4‚É ’†:3‰ñ ‘å:2‰ñ
			UINT           INTERVAL2; // ‘—MŠÔŠuŒvŽZ—p
			array<BYTE>^   SEND;      // ‘—M—pƒoƒbƒtƒ@
			array<UINT16>^ LOCAL;     // ƒŠƒ“ƒOƒoƒbƒtƒ@
			UINT32         L_FRAME;   // ‘ƒtƒŒ[ƒ€”
			int            L_READ;    // “Ç‚ÝŽæ‚èˆÊ’u
			array<UINT16>^ REMOTE;    // ‚±‚Ì‚Q‚Â‚ÍƒL[‚Ì—š—ð‚ð•ÛŽ‚·‚é
			UINT32         R_FRAME;   // ‘ƒtƒŒ[ƒ€”
			int            R_READ;    // “Ç‚ÝŽæ‚èˆÊ’u
		};

		static Thread^ VersusThread;
		static VersusInfo^ NetVS;

		// ŠÏíŠÖ˜A
		ref struct SpectatorInfo
		{
			UINT16      ID;
			IPEndPoint^ IP_EP;
			UINT32      FRAME;
		};

		static Thread^ SpectacleThread;
		static Generic::List<SpectatorInfo^>^ SpectatorList;
		static bool           AllowWatch;      // ƒXƒŒƒbƒh§Œä
		static UINT           WaitingWatch;    // ƒpƒPƒbƒg‘Ò‚¿ 1:ŠJŽn‘Ò‚¿ 2:ƒf[ƒ^‘Ò‚¿
		static IPEndPoint^    WatchTarget;     // ŠÏí‘ÎÛ
		static UINT16         TargetID;
		static UINT16         P1ID, P2ID;      // P2‚ª0xFFFF‚ÅˆêlƒvƒŒƒC
		static UINT32         WatchFrame;      // “Ç‚ÝŽæ‚èˆÊ’u
		static array<UINT16>^ WatchHistory;    // ƒoƒbƒtƒ@ TIME_OUT/5 * 3 = 1800‚Ì900ƒtƒŒ[ƒ€•ª
		static UINT32         InputFrame;      // ‘‚«ž‚ÝˆÊ’u
		static array<UINT16>^ InputHistory;    // ƒoƒbƒtƒ@

		// Ž©“®‹xŒe
		static Thread^ AutoRestThread;
		static bool AutoRestRanging;
		static bool AutoRestSleeping;

		// MainForm.cpp‚É‹Lq
		void Begin();
		void TimerGetIP();
		void SetTeamHP();
		void RunSonar();
		void RunGame(Object^ obj);
		void RunVersus();
		void RunSpectacle();
		UINT16 LocalInput(UINT16 eax);
		UINT16 RemoteInput();
		UINT16 ReadReplayData(BinaryReader^ br, REPLAY_INFO& ri);
		void RecordInput(UINT16 eax, BinaryWriter^ bw, REPLAY_INFO& ri, bool as);
		void RunAutoRest();
		void ChangeSeek();
		void ChangeLogWordWrap();
		void ClearLog();
		void SaveLog();

		void PacketSendAllMember(array<BYTE>^% datagram, UINT received_id);
		static void SendPackets(IAsyncResult^ asyncResult);
		static void ReceivePackets(IAsyncResult^ asyncResult);

	protected:
		void LoadSettings(){
			if(Option == nullptr || Option->IsDisposed){
				toolStripDropDownButtonProfile->Enabled = false;
				Option = gcnew OptionForm;
				Option->Show(this);
			}
			else{
				Option->Activate();
			}
		}
		void StartGame(UINT type){
			// This function attempts to start the game executable and checks whether it is in fact an FM2K executable.
			try{
				FileVersionInfo^ info = FileVersionInfo::GetVersionInfo(gcnew String(MTOPTION.GAME_EXE));

				if(info->FileDescription != "２Ｄ格闘ツクール2nd." && info->FileDescription == "２Ｄ格闘ツクール９５" && info->FileDescription == "Fighting is Magic: Aurora"){
					throw gcnew Exception;
				}
				else{
					if(info->FileDescription == "Fighting is Magic: Aurora" || info->FileDescription == "２Ｄ格闘ツクール2nd." || info->LegalCopyright == "(C)2001 ENTERBRAIN,INC / OUTBACK"){
						MTINFO.KGT2K = true;
					}
					else{
						MTINFO.KGT2K = false;
					}
				}
			}
			catch(Exception^){
				WriteMessage("Replay could not be started.\n", ErrorMessageColor);
				WriteMessage("Executable is not a valid Fighter Maker game.\n", ErrorMessageColor);
				return;
			}

			if(MemberList[0]->STATE == MS_SEEK){
				QuitGame();
				GameThread = nullptr;
			}

			if(GameThread != nullptr && GameThread->IsAlive == false){
				GameThread = nullptr;
			}

			if(VersusThread != nullptr && VersusThread->IsAlive == false){
				VersusThread = nullptr;
			}

			if(NetVS != nullptr && MemberList[0]->STATE == MS_READY){
				if((timeGetTime() - NetVS->START_UP) > TIME_OUT*2 + 1000){
					MemberList[0]->STATE = MS_FREE;
					delete NetVS;
					NetVS = nullptr;
				}
			}

			if(GameThread == nullptr){
				ZeroMemory(MTINFO.P1_NAME, sizeof(MTINFO.P1_NAME));
				ZeroMemory(MTINFO.P2_NAME, sizeof(MTINFO.P2_NAME));

				if(type == RT_FREE){
					MTINFO.SEED          = XorShift();
					MTINFO.MAX_STAGE     = MTOPTION.MAX_STAGE;
					MTINFO.STAGE_SELECT  = MTOPTION.STAGE_SELECT;
					MTINFO.ROUND         = MTOPTION.ROUND;
					MTINFO.TIMER         = MTOPTION.TIMER;
					MTINFO.TEAM_ROUND_HP = MTOPTION.TEAM_ROUND_HP;

					P1ID = MemberList[0]->ID;
					P2ID = 0xFFFF;

					_tcscpy_s(MTINFO.P1_NAME, MTOPTION.NAME);
					MTINFO.CONTROL = 0;
				}
				else if(type == RT_VS){
					Monitor::Enter(MemberList);
					try{
						MemberList[0]->STATE = MS_READY;

						NetVS = gcnew VersusInfo;
						NetVS->SEQUENCE = VS_REQ;
						NetVS->SLEEPING = false;
						NetVS->WAITING  = false;
						NetVS->START_UP = timeGetTime();
						NetVS->IP_EP    = MemberList[listBoxMember->SelectedIndex]->IP_EP;
						NetVS->PING     = gcnew array<UINT>(5){ 0, 0, 0, 0, 0 };
						NetVS->PONG     = gcnew array<UINT>(5){ 0, 0, 0, 0, 0 };
						NetVS->SEND     = gcnew array<BYTE>(32){ PH_VS_DATA };
						NetVS->L_FRAME  = 0;
						NetVS->L_READ   = 0;
						NetVS->R_FRAME  = 0;
						NetVS->L_READ   = 0;

						// ŠÏí—pID
						P1ID = MemberList[listBoxMember->SelectedIndex]->ID;
						P2ID = MemberList[0]->ID;

						// –¼‘O
						ZeroMemory(MTINFO.P1_NAME, sizeof(MTINFO.P1_NAME));
						ZeroMemory(MTINFO.P2_NAME, sizeof(MTINFO.P2_NAME));

						if(ListView != LV_BLIND){
							IntPtr mp = Runtime::InteropServices::Marshal::StringToHGlobalAuto(MemberList[listBoxMember->SelectedIndex]->NAME);
							_tcscpy_s(MTINFO.P1_NAME, static_cast<PTCHAR>(mp.ToPointer()));
							Runtime::InteropServices::Marshal::FreeHGlobal(mp);

							_tcscpy_s(MTINFO.P2_NAME, MTOPTION.NAME);
						}

						// ‘Îí‰ñ”
						MemberList[listBoxMember->SelectedIndex]->NUM_VS++;

						// ƒlƒbƒg‘Îí€”õ—pƒXƒŒƒbƒh‚Ì‹N“®
						MTINFO.CONTROL = 1;
						VersusThread = gcnew Thread(gcnew ThreadStart(this, &MainForm::RunVersus));
						VersusThread->Start();
					}
					finally{
						Monitor::Exit(MemberList);
					}
					return;
				}
				else if(type == RT_PLAYBACK){
					if(ReplayFilePath == String::Empty){
						openFileDialog1->InitialDirectory = gcnew String(MTOPTION.REPLAY_FOLDER);

						if(openFileDialog1->ShowDialog() == ::DialogResult::OK){
							ReplayFilePath = openFileDialog1->FileName;
						}
						else{
							return;
						}
					}

					// ƒtƒH[ƒ}ƒbƒg‚ÌŠm”F
					TCHAR ver;
					array<TCHAR>^ header = gcnew array<TCHAR>{'T', 'Y', 'M', 'T', 'R'};
					BinaryReader^ br = gcnew BinaryReader(File::OpenRead(ReplayFilePath));

					try{
						// ヘッダ
						array<TCHAR>^ h = br->ReadChars(header->Length);
						for(int i = 0; i < h->Length; i++){
							if(h[i] != header[i]){
								WriteMessage("Not a valid replay file.\n", ErrorMessageColor);
								return;
							}
						}

						ver = br->ReadChar();

						if(ver < _T('1') || ver > _T('4')){
							WriteMessage("Not a valid replay version.\n", ErrorMessageColor);
							return;
						}
					}
					finally{
						br->Close();
					}
				}

				GameThread = gcnew Thread(gcnew ParameterizedThreadStart(this, &MainForm::RunGame));
				GameThread->Start(type);
			}
			else{
				if(_tcslen(MTINFO.ORIGINAL_TITLE) > 0){
					WriteMessage(String::Format("{0} is starting up.\n", gcnew String(MTINFO.ORIGINAL_TITLE)), SystemMessageColor);
				}
				else{
					WriteMessage("Another game is running.\n", SystemMessageColor);
				}
			}
		}
		void StartGameNoReplay(){
			bool primary = 0;
			// ƒŠƒvƒŒƒC•Û‘¶ON‚È‚çˆêŽž“I–³Œø‰» < TODO
			if(toolStripMenuItemRecordReplay->Checked == 1) {
				primary = 1;
				MTOPTION.RECORD_REPLAY = 0;
			}
			
			StartGame(RT_FREE);
			
			if(primary == 1) {
				// ‹N“®‘O‚É–ß‚µ‚Ä‚µ‚Ü‚¤‚Ì–hŽ~ < TODO
				Thread::Sleep(100);
				MTOPTION.RECORD_REPLAY = toolStripMenuItemRecordReplay->Checked;
			}
		}
		void QuitGame(){
			if(GameThread != nullptr && GameThread->IsAlive){
				if(MTINFO.DEBUG){
					WriteMessage("Closing game process.\n", DebugMessageColor);
				}
				try{
					Process::GetProcessById(MTINFO.PROCESS_ID)->CloseMainWindow();
				}
				catch(ArgumentException^){
					if(MTINFO.DEBUG){
						WriteMessage("Caught ArgumentException\n", DebugMessageColor);
					}
					GameThread->Abort();
					GameThread = nullptr;
				}
			}
			/*
			if(GameThread == nullptr){
				try{
					String^ game = Path::GetFileNameWithoutExtension(gcnew String(MTOPTION.GAME_EXE));
					array<Process^>^ ps = Process::GetProcessesByName(game);
					if(ps->Length > 0){
						for(int i=0; i < ps->Length; i++){
							if(ps[0]->MainWindowTitle == game){
								WriteMessage(String::Format("{0}‚ðI—¹‚µ‚Ü‚·B\n", ps[0]->MainWindowTitle), SystemMessageColor);
								ps[0]->CloseMainWindow();
							}
						}
					}else{
						WriteMessage(String::Format("I—¹‚·‚éƒQ[ƒ€\"{0}\"‚ªŒ©‚Â‚©‚è‚Ü‚¹‚ñ‚Å‚µ‚½B\nƒIƒvƒVƒ‡ƒ“‚ÌŽÀsƒtƒ@ƒCƒ‹‚ÌƒpƒXA‚Ü‚½‚Íƒvƒƒtƒ@ƒCƒ‹‚ª‡‚Á‚Ä‚¢‚é‚©Šm”F‚µ‚Ä‚­‚¾‚³‚¢B\n", game), ErrorMessageColor);
						return;
					}
				}
				catch(Exception^ e){
					WriteMessage("ƒQ[ƒ€‚ðI—¹‚Å‚«‚Ü‚¹‚ñ‚Å‚µ‚½B\n", ErrorMessageColor);
					if(MTINFO.DEBUG){
						WriteMessage(String::Format("{0}\n", e->ToString()), DebugMessageColor);
					}
				}
			}
			*/
		}

		void QuitWatch(bool send_packet){
			if(WaitingWatch > 0 && GameThread != nullptr && GameThread->IsAlive){
				bool w = WaitingWatch == 2 ? true : false;
				WaitingWatch = 0;

				if(w){
					Monitor::Enter(WatchHistory);
					try{
						Monitor::Pulse(WatchHistory);
					}
					finally{
						Monitor::Exit(WatchHistory);
					}
				}

				QuitGame();
			}

			if(WatchTarget != nullptr && UDP != nullptr){
				if(send_packet){
					array<BYTE>^ quit = gcnew array<BYTE>(3){ PH_WATCH_END };
					Array::Copy(BitConverter::GetBytes(MemberList[0]->ID), 0, quit, 1, 2);
					UDP->BeginSend(quit, quit->Length, WatchTarget, gcnew AsyncCallback(SendPackets), UDP);
				}

				delete WatchTarget;
				WatchTarget = nullptr;
			}

			int state = MemberList[0]->STATE;

			if(state == MS_WATCH) ChangeState((BYTE)MS_FREE);
			if(state == MS_COUCH) ChangeState((BYTE)MS_REST);

			toolStripMenuItemWatch->Text = gcnew String("ŠÏí‚·‚é");
		}

		void Restart(){
			// ƒtƒŠ[ƒvƒŒƒC‚¾‚¯‚Ç‘Îí’†
			if(AfterCloseUDP) return;

			CloseUdp(true);

			MemberList->Clear();
			listBoxMember->Items->Clear();

			// IPŽæ“¾‚ÌƒLƒƒƒ“ƒZƒ‹
			if(GetIPClient != nullptr){
				GetIPClient->CancelAsync();
			}
			if(TimerGetIPThread != nullptr && TimerGetIPThread->IsAlive){
				if(GetIPSleeping){
					TimerGetIPThread->Interrupt();
				}
				TimerGetIPThread->Join();
			}
			
			this->Text = gcnew String("MorningStar");

			StartupForm^ s = gcnew StartupForm;
			s->ShowDialog(this);
			

			ListView = LV_NAME;

			Begin();
		}

		void Reconnect(){
			if(MTOPTION.CONNECTION_TYPE == CT_SERVER) {
				if(MessageBox::Show("This will shut down the server and drop all players.\nAre you sure you want to do this?", "Reconnect", MessageBoxButtons::YesNo, MessageBoxIcon::Question) == ::DialogResult::Yes){
				}else{
					return;
				}
			}

			if(MTOPTION.CONNECTION_TYPE == CT_HOST || MTOPTION.CONNECTION_TYPE == CT_CLIENT){
				if(MessageBox::Show("This will disconnect you from the server.\nContinue?", "Reconnect", MessageBoxButtons::YesNo, MessageBoxIcon::Question) == ::DialogResult::Yes){
				}else{
					return;
				}
			}

			Restart();
		}
		void Leave(bool send_packet){
			CloseUdp(send_packet);

			Monitor::Enter(MemberList);
			try{
				listBoxMember->BeginUpdate();

				while(MemberList->Count > 1){
					MemberList->RemoveAt(1);
					listBoxMember->Items->RemoveAt(1);
				}

				listBoxMember->EndUpdate();
			}
			finally{
				Monitor::Exit(MemberList);
			}

			MTOPTION.CONNECTION_TYPE = CT_FREE;
			MemberList[0]->TYPE  = CT_FREE;
			MemberList[0]->STATE = MS_FREE;
			this->Text = gcnew String("MorningStar  [Free Play]");
			listBoxMember->Refresh();

		}

		void ChangeState(Object^ obj){
			if(MTOPTION.CONNECTION_TYPE == CT_FREE || UDP == nullptr) return;

			BYTE state = (BYTE)obj;

			array<BYTE>^ send = gcnew array<BYTE>(4){ PH_CHANGE_STATE, 0, 0, state };
			MemberList[0]->STATE = state;
			listBoxMember->Refresh();
			if(MemberList[0]->STATE == MS_FREE){
				if(MTOPTION.AUTO_REST){
					AutoRestThread = gcnew Thread(gcnew ThreadStart(this, &MainForm::RunAutoRest));
					AutoRestThread->Start();
				}
			}
			if(MemberList[0]->STATE == MS_REST){
				if(AutoRestThread != nullptr){
					AutoRestRanging = false;
					AutoRestThread->Abort();
					AutoRestThread = nullptr;
				}
			}
			

			if(MTOPTION.CONNECTION_TYPE == CT_SERVER){
				PacketSendAllMember(send, 0);
			}
			else{
				Array::Copy(BitConverter::GetBytes(MemberList[0]->ID), 0, send, 1, 2);
				UDP->BeginSend(send, send->Length, MemberList[1]->IP_EP, gcnew AsyncCallback(SendPackets), UDP);
			}
		}

		void CloseUdp(bool send_packet){
			if(UDP != nullptr){
				array<BYTE>^ quit;

				// ƒ\ƒi[’âŽ~
				if(SonarThread != nullptr && SonarThread->IsAlive && Ranging){
					Ranging = false;

					if(SonarSleeping){
						SonarThread->Interrupt();
					}

					SonarThread->Join();
				}
				// Ž©“®‹xŒeƒXƒŒƒbƒh’âŽ~
				if(AutoRestThread != nullptr && AutoRestThread->IsAlive && AutoRestRanging){
					AutoRestRanging = false;
					AutoRestThread->Abort();
					AutoRestThread = nullptr;
				}

				if(send_packet){
					// ‘ÞŽºƒƒbƒZ[ƒW‚ð‘—M
					if(MTOPTION.CONNECTION_TYPE == CT_SERVER){
						quit = gcnew array<BYTE>(3){ PH_QUIT, 0, 0 };
						PacketSendAllMember(quit, 0);
						IDCounter = 0;
					}
					else if(MemberList->Count > 1){
						array<BYTE>^ quit = gcnew array<BYTE>(3){ PH_QUIT };
						Array::Copy(BitConverter::GetBytes(MemberList[0]->ID), 0, quit, 1, 2);
						UDP->BeginSend(quit, quit->Length, MemberList[1]->IP_EP, gcnew AsyncCallback(SendPackets), UDP);
					}
				}

				if(GameThread != nullptr && GameThread->IsAlive){
					AfterCloseUDP = true;
				}
				else{
					UDP->Close();
				}
			}
		}

		void TalkMessage(UINT16 id, array<BYTE>^ msg){
			int i;
			String^ name;
			Color col;

			// ‘—ŽóM
			if(UDP != nullptr && MemberList->Count > 1){
				if(MTOPTION.CONNECTION_TYPE == CT_SERVER){
					// –{l‚Æ”­MŽÒˆÈŠO‚É‘—M
					PacketSendAllMember(msg, id);
				}
				else{
					// ŽóM‚Å‚È‚¯‚ê‚ÎAƒT[ƒo‚É‘—M
					if(id != 0xFFFF){
						UDP->BeginSend(msg, msg->Length, MemberList[1]->IP_EP, gcnew AsyncCallback(SendPackets), UDP);
					}
					else{
						// ŽóMƒtƒ‰ƒO‚ðƒNƒŠƒA
						id = BitConverter::ToUInt16(msg, 1);
					}
				}
			}

			// ƒƒ“ƒo[ŒŸõ
			Monitor::Enter(MemberList);
			try{
				for(i = 0; i < MemberList->Count; i++){
					if(id == MemberList[i]->ID){
						name = MemberList[i]->NAME;
						col  = NameColor[MemberList[i]->TYPE];
						break;
					}
				}

				if(i >= MemberList->Count && MTOPTION.CONNECTION_TYPE != CT_SERVER){
					name = gcnew String(String::Format("Unknown(ID:{0})", id));
					col  = ErrorMessageColor;

					// ƒƒ“ƒo[ƒŠƒXƒgŠO‚ÌID‚ª‚¢‚½‚Ì‚Å–â‚¢‡‚í‚¹
					array<BYTE>^ send = gcnew array<BYTE>(3){ PH_REQ_LIST };
					Array::Copy(BitConverter::GetBytes(id), 0, send, 1, 2);
					UDP->Send(send, 3, MemberList[1]->IP_EP);
				}
			}
			finally{
				Monitor::Exit(MemberList);
			}

			// Notify user on nickname mention.
			String ^tmpMsg = Encoding::Unicode->GetString(msg, 4, msg[3]);
			bool inname = 0;
			if(tmpMsg->Contains(gcnew String(MTOPTION.NAME))) {
				// –¼‘O‚ªŒÄ‚Î‚ê‚½‚çƒEƒBƒ“ƒhƒE“_–Å
				/*if(MTOPTION.NAME_FLASH) {
					WindowFlash();
				}*/
				if(MTOPTION.NAME_SOUND_ENABLE){
					inname = 1;
					try{
						/*Media::SoundPlayer^ wav = gcnew Media::SoundPlayer(gcnew String(MTOPTION.NAME_SOUND));
						wav->Play();*/
						WindowFlash();
						notifyIconSysTray->ShowBalloonTip(1, "MorningStar - Notification", "Your nickname (" + gcnew String(MTOPTION.NAME) + ") was mentioned.", ToolTipIcon::Info);
					}
					catch(Exception^){
					}
				}
			}
			// Notify user on keyword mention.
			bool inkeyword = 0;
			if(MTOPTION.KEYWORD_SOUND_ENABLE && !inname){
				// •ªŠ„ƒoƒbƒtƒ@
				TCHAR *tok, *next;
				TCHAR s1[MAX_KEYWORD];
				_tcscpy_s(s1, MTOPTION.KEYWORD);
				tok = wcstok_s(s1, _T(","), &next);
				while(tok != NULL){
					if(tmpMsg->Contains(gcnew String(tok))) {
						inkeyword = 1;
						try{
							/*Media::SoundPlayer^ wav = gcnew Media::SoundPlayer(gcnew String(MTOPTION.KEYWORD_SOUND));
							wav->Play();*/
							notifyIconSysTray->ShowBalloonTip(1, "MorningStar - Notification", "Keyword (" + gcnew String(tok) + ") was mentioned.", ToolTipIcon::Info);
						}
						catch(Exception^){
						}
						break;
					}
					tok = wcstok_s(NULL, _T(","), &next);
				}
			}
			// Play sound on chat message.
			if(MemberList[0]->ID != id && !inname) {
				/*if(MTOPTION.TALK_FLASH) {
					WindowFlash();
				}*/
				// ”­Œ¾‚Å‰¹‚ðÄ¶
				if(MTOPTION.TALK_SOUND_ENABLE && !inkeyword){
					try{
						/*Media::SoundPlayer^ wav = gcnew Media::SoundPlayer(gcnew String(MTOPTION.TALK_SOUND));
						wav->Play();*/
						WindowFlash();
						notifyIconSysTray->ShowBalloonTip(1, "MorningStar - Notification", "A new message was sent in the chat.", ToolTipIcon::Info);
					}
					catch(Exception^){
					}
				}
			}

			// ŽžŠÔ
			if(inname||inkeyword){
				WriteTime(1, DebugMessageColor);
			}else{
				WriteTime(1, SystemMessageColor);
			}
			// •\Ž¦
			WriteMessage(String::Format("[ {0} ] ", name), col);
			WriteMessage(String::Format("{0}\n", tmpMsg), TalkMessageColor);
		}

		void WriteMessage(String^ msg, Color color){
			if(richTextBoxLog->InvokeRequired){
				WriteMessageDelegate^ wmd = gcnew WriteMessageDelegate(this, &MainForm::WriteMessage);
				richTextBoxLog->Invoke(wmd, msg, color);
			}
			else{
				Monitor::Enter(richTextBoxLog);
				try{
					richTextBoxLog->SelectionStart = richTextBoxLog->Text->Length;

					richTextBoxLog->SelectionColor = color;
					richTextBoxLog->AppendText(msg);

					richTextBoxLog->SelectionStart = richTextBoxLog->Text->Length;

					if(!MTOPTION.LOG_LOCK) {
						richTextBoxLog->ScrollToCaret();
					}
				}
				finally{
					Monitor::Exit(richTextBoxLog);
				}
			}	
		}
		void WriteTime(bool f, Color color){
			if(f){
				WriteMessage(String::Format("[{0}]", DateTime::Now.ToString("HH:mm")), color);
			}else{
				WriteMessage(String::Format("[{0}] ", DateTime::Now.ToString("HH:mm")), color);
			}
		}
		void WriteNotice(String^ msg){
			// ‰¹‚Å‚¨’m‚ç‚¹
			if(MTOPTION.CONNECTION_TYPE != CT_SERVER){
				if(MTOPTION.NOTICE_SOUND_ENABLE){
					try{
						/*Media::SoundPlayer^ wav = gcnew Media::SoundPlayer(gcnew String(MTOPTION.NOTICE_SOUND));
						wav->Play();*/
						notifyIconSysTray->ShowBalloonTip(1, "MorningStar - Notification", gcnew String(msg), ToolTipIcon::Info);
					}
					catch(Exception^){
					}
				}
			}

			// \n‚Å‰üs
			msg = msg->Replace("\\n", "\n");

			Monitor::Enter(richTextBoxLog);
			try{
				richTextBoxLog->SelectionStart = richTextBoxLog->Text->Length;

				richTextBoxLog->SelectionFont = gcnew Drawing::Font(richTextBoxLog->Font->FontFamily, richTextBoxLog->Font->Size + 2);
				richTextBoxLog->SelectionColor = TalkMessageColor;
				richTextBoxLog->SelectionBackColor = NoticeBackColor;
				richTextBoxLog->AppendText(msg + "\n");

				richTextBoxLog->SelectionStart = richTextBoxLog->Text->Length;

				if(!MTOPTION.LOG_LOCK) {
					richTextBoxLog->ScrollToCaret();
				}
			}
			catch(Exception ^e){
				WriteErrorLog(e->ToString(), "RichTextBox");
			}
			finally{
				Monitor::Exit(richTextBoxLog);
			}

		}

		void WriteComment(String^ name, int type, String^ comment){
			if(ListView == LV_BLIND){
				return;
			}

			// Play a chosen sound on member join.
			if(MTOPTION.ENTER_SOUND_ENABLE){
				try{
					/*Media::SoundPlayer^ wav = gcnew Media::SoundPlayer(gcnew String(MTOPTION.ENTER_SOUND));
					wav->Play();*/
					notifyIconSysTray->ShowBalloonTip(1, "MorningStar - Notification", "A user joined the chat.", ToolTipIcon::Info);
				}
				catch(Exception^){
				}
			}

			if(comment->Length > 0){
				// ŽžŠÔ
				WriteTime(1, SystemMessageColor);
				Monitor::Enter(richTextBoxLog);
				try{
					richTextBoxLog->SelectionStart = richTextBoxLog->Text->Length;
					richTextBoxLog->SelectionColor = NameColor[type];
					richTextBoxLog->SelectionBackColor = CommentBackColor;
					richTextBoxLog->AppendText(String::Format("[ {0} ] ", name));

					richTextBoxLog->SelectionColor = TalkMessageColor;
					richTextBoxLog->SelectionBackColor = CommentBackColor;
					richTextBoxLog->AppendText(String::Format("{0}\n", comment));

					richTextBoxLog->SelectionStart = richTextBoxLog->Text->Length;
					if(!MTOPTION.LOG_LOCK) {
						richTextBoxLog->ScrollToCaret();
					}
				}
				catch(Exception ^e){
					WriteErrorLog(e->ToString(), "RichTextBox");
				}
				finally{
					Monitor::Exit(richTextBoxLog);
				}
			}
			else{
				WriteTime(0, SystemMessageColor);
				WriteMessage(String::Format("{0} has joined.\n", name), SystemMessageColor);
			}
		}

		void WriteCommandList(){
			WriteMessage(
				L"\n"
				L"Text Commands\n"
				L"\n"
				L"/help: Displays a full list of available commands.\n"
				L"/clear: Clears the chat log.\n"
				L"/log: Saves the log to an RTF file.\n"
				L"/vs: Challenge a random opponent!\n"
				L"/game: Starts the game.\n"
				L"/replay: Opens a replay file.\n"
				L"/quit: Closes the game during battle.\n"
				L"/reload: Reloads player list.\n"
				L"/restart: Reconnects to the last known server.\n"
				L"/rest: Toggles rest mode.\n"
				L"/seek: Toggles seek mode.\n"
				L"/list: Displays the player list.\n"
				L"/leave: Exits the server and enters Free Play mode.\n"
				L"/time: Displays the current date and time in the specified user colour.\n"
				L"/exit: Exits the program.\n"
				L"\n"
				L"Keyboard Shortcuts\n"
				L"\n"
				L"Ctrl+O: Open replay file\n"
				L"Ctrl+S: Save log\n"
				L"Alt+F4: Exit\n"
				L"Ctrl+G: Start game\n"
				L"Ctrl+T: Start game (no replay)\n"
				L"Ctrl+R: Reconnect\n"
				L"Ctrl+L: Leave\n"
				L"Alt+R: Toggle rest mode\n"
				L"Ctrl+Alt+S: Toggle seek mode\n"
				L"F5: Refresh list\n"
				L"Ctrl+Shift+C: Clear chat\n"
				L"Ctrl+D: Toggle debugging info\n"
				L"Ctrl+Shift+I: Get IP address\n"
				L"Alt+Shift+S: Bookmarks > Add server\n"
				L"Alt+S: Settings\n"
				L"Alt+Shift+A: Delay > Auto\n"
				L"Alt+Shift+F2: Delay > 2\n"
				L"Alt+Shift+F3: Delay > 3\n"
				L"Alt+Shift+F4: Delay > 4\n"
				L"Alt+Shift+F5: Delay > 5\n"
				L"Alt+Shift+F6: Delay > 6\n"
				L"Alt+Shift+F7: Delay > 7\n"
				L"Alt+Shift+F8: Delay > 8\n"
				L"Alt+Shift+F9: Delay > 9\n"
				L"Alt+Shift+F10: Delay > 10\n"
				L"Alt+Shift+F11: Delay > 11\n"
				L"Alt+Shift+F12: Delay > 12\n"
				L"Alt+Shift+R: Save replays\n"
				L"Alt+Shift+A: Allow spectators\n"
				L"Alt+Shift+W: Word wrap\n"
				L"F4: Auto scroll chat\n"
				L"Alt+Shift+C: Rest on connect\n"
				L"Alt+Shift+N: Rest after net fight\n"
				L"Ctrl+Shift+A: Auto rest after > Enabled\n"
				L"Alt+1: Auto rest after > 5 minutes\n"
				L"Alt+2: Auto rest after > 10 minutes\n"
				L"Alt+3: Auto rest after > 15 minutes\n"
				L"Alt+4: Auto rest after > 20 minutes\n"
				L"Alt+5: Auto rest after > 30 minutes\n"
				L"Alt+6: Auto rest after > 1 hour\n"
				L"Alt+7: Auto rest after > 2 hours\n"
				L"Alt+8: Auto rest after > 8 hours\n"
				L"Alt+9: Auto rest after > 12 hours\n"
				L"\n"
				L"MorningStar also supports drag-and-drop for replay files and for locating the FM executable.\n"
				L"\n", SystemMessageColor);
		}

		void WriteWhatsNew(){
			WriteMessage(
				L"\n"
				L"~.Version 2.1.0.0.~\n"
				L"\n"
				L"- Added native real-time notifications to replace every old sound alert setting.\n"
				L"- Reverted auto-scroll option back to a menu item due to causing an exception at runtime.\n"
				L"\n"
				L"~.Version 2.0.0.0.~\n"
				L"\n"
				L"- Fixed a bug where reconnecting would cause startup form to not choose any default connection option.\n"
				L"- Added mute checkboxes to volume settings.\n"
				L"- Added native real-time notifications.\n"
				L"- Moved options from 'Settings > Other' to 'Settings > General'.\n"
				L"- Added MorningStar logo to system tray icon.\n"
				L"- Redesigned main interface and removed clutter from menus.\n"
				L"\n"
				L"~.Version 1.1.0.5.~\n"
				L"\n"
				L"- Fixed a bug where Aurora versions would not start properly.\n"
				L"\n"
				L"~.Version 1.1.0.4.~\n"
				L"\n"
				L"- Fixed a bug where chat window would not resize to window size.\n"
				L"- Fixed a bug where chat colour buttons did not display the chosen colour.\n"
				L"- Fixed the 'MorningStar' label in 'Settings > IP Conversion' from clipping into text field.\n"
				L"\n"
				L"~.Version 1.1.0.3.~\n"
				L"\n"
				L"- Disabled dark mode option until it's complete.\n"
				L"- Added official MorningStar icon.\n"
				L"- Updated server set-up field to provide more context to what options do.\n"
				L"\n"
				L"~.Version 1.1.0.2.~\n"
				L"\n"
				L"Updated to .NET Framework 4.0 and Visual C++ 2010.\n"
				L"Added link to FM95/FM2K Discord server.\n"
				L"Fixed a bug which caused the region combobox to stay enabled even when displaying region on profile was disabled.\n"
				L"\n"
				L"~.Version 1.1.0.1.~\n"
				L"\n"
				L"- Removed comment option from 'MorningStar Settings' as it's redundant.\n"
				L"- Fixed end message tooltip.\n"
				L"\n"
				L"~.Version 1.1.0.0.~\n"
				L"\n"
				L"- Added username validation which stops certain special characters from connecting to the server (this might have caused crashes in the past).\n"
				L"- User list and chat log now fit to the window properly.\n"
				L"- Added 'Looking for' and 'Avoiding' profile options which appear on a user tooltip.\n"
				L"- Added 8 hour and 12 hour options for Auto-rest.\n"
				L"- Added semi-auto spectate voodoo ritual.\n"
				L"- Added Legacy Netcode Mode for connecting to servers that haven't updated yet.\n"
				L"- Fixed some system text not resulting in a new line after.\n"
				L"- Added rest on connect option to 'Welcome' window and main window.\n"
				L"- MorningStar now attempts to recover after an exception.\n"
				L"- Added region selection option which appears on a user tooltip.\n"
				L"- Added end of fight message settings which automatically make you say a ''gg message'' after a fight.\n"
				L"- Fixed a bug where connection type would not save.\n"
				L"\n"
				L"~.Version 1.0.9.1.~\n"
				L"\n"
				L"- Added animations to all buttons.\n"
				L"- Added support for Fighting is Magic: Aurora.\n"
				L"- Updated UPnP toggle so it is now a checkbox.\n"
				L"- Combined 'Connect' and 'OK' button into one on the 'Welcome' window.\n"
				L"- Added custom context menu for message text field.\n"
				L"- Fixed a bug where mousing over labels on the 'Welcome' window would underline them.\n"
				L"- Fixed a bug where the 'Address / IP' showed the wrong information.\n"
				L"\n"
				L"~.Version 1.0.9.0.~\n"
				L"\n"
				L"- Keyboard shortcuts added to perform tasks with a command rather than searching through menus.\n"
				L"- Added keyboard shortcuts to help.\n"
				L"- Added 'What's new?' option to show what's changed in the application.\n"
				L"- Added /time command with colour properties in 'MorningStar Settings'.\n"
				L"- Added check for blank name.\n"
				L"- Redesigned various dialogues so they are more coherent and easy to use.\n"
				L"\n", SystemMessageColor);
		}

		void RandomVersus(){
			if(ServerMode == SM_MIX){
				return;
			}

			if(MTOPTION.CONNECTION_TYPE != CT_FREE && MemberList[0]->STATE == MS_FREE){
				UINT n = 0;
				Generic::List<int>^ list = gcnew Generic::List<int>;

				Monitor::Enter(MemberList);
				try{
					for(int i = 1; i < MemberList->Count; i++){
						// ƒNƒ‰ƒCƒAƒ“ƒg‚à‘Îí‘ÎÛ
						if(MemberList[i]->STATE == MS_FREE || MemberList[i]->STATE == MS_SEEK){
						// if(MemberList[i]->STATE == MS_FREE && MemberList[i]->TYPE != CT_CLIENT){
							list->Add(i);
						}
					}

					if(list->Count > 0){
						n = list[XorShift() % list->Count];
					}
				}
				finally{
					Monitor::Exit(MemberList);
				}

				if(n > 0){
					listBoxMember->SelectedIndex = n;
					StartGame(RT_VS);
				}
				else{
					WriteMessage("‘Îí‚Å‚«‚é‘ŠŽè‚ª‚¢‚Ü‚¹‚ñ‚Å‚µ‚½B\n", SystemMessageColor);
				}
			}
		}

		void AnalyzeCommand(){
			if(textBoxInput->Text->StartsWith("/help", StringComparison::OrdinalIgnoreCase)){
				WriteCommandList();
			}
			else if(textBoxInput->Text->StartsWith("/clear", StringComparison::OrdinalIgnoreCase)){
				ClearLog();
			}
			else if(textBoxInput->Text->StartsWith("/log", StringComparison::OrdinalIgnoreCase)){
				SaveLog();
			}
			else if(textBoxInput->Text->StartsWith("/debug", StringComparison::OrdinalIgnoreCase)){
				MTINFO.DEBUG ^= 1;
				if(MTINFO.DEBUG){
					WriteMessage("Debug mode is now on.\n", SystemMessageColor);
				}
				else{
					WriteMessage("Debug mode is now off.\n", SystemMessageColor);
				}
			}
			else if(textBoxInput->Text->StartsWith("/vs", StringComparison::OrdinalIgnoreCase)){
				RandomVersus();
			}
			else if(textBoxInput->Text->StartsWith("/game", StringComparison::OrdinalIgnoreCase)){
				StartGame(RT_FREE);
			}
			else if(textBoxInput->Text->StartsWith("/replay", StringComparison::OrdinalIgnoreCase)){
				ReplayFilePath = String::Empty;
				StartGame(RT_PLAYBACK);
			}
			else if(textBoxInput->Text->StartsWith("/quit", StringComparison::OrdinalIgnoreCase)){
				QuitGame();
			}
			else if(textBoxInput->Text->StartsWith("/restart", StringComparison::OrdinalIgnoreCase)){
				Restart();
			}
			else if(textBoxInput->Text->StartsWith("/rest", StringComparison::OrdinalIgnoreCase)){
				if(MTOPTION.CONNECTION_TYPE == CT_FREE) return;

				if(MemberList[0]->STATE == MS_FREE){
					ChangeState((BYTE)MS_REST);
					WriteMessage("Changed rest state. > On\n", SystemMessageColor);
				}
				else if(MemberList[0]->STATE == MS_REST){
					ChangeState((BYTE)MS_FREE);
					WriteMessage("Changed rest state: > Off\n", SystemMessageColor);
				}
			}
			else if(textBoxInput->Text->StartsWith("/seek", StringComparison::OrdinalIgnoreCase)){
				ChangeSeek();
			}
			else if(textBoxInput->Text->StartsWith("/list", StringComparison::OrdinalIgnoreCase)){
				ChangeListView(true);	
			}
			else if(textBoxInput->Text->StartsWith("/time", StringComparison::OrdinalIgnoreCase)){
				WriteMessage(String::Format("{0} {1}\n", DateTime::Now.ToLongDateString(), DateTime::Now.ToLongTimeString()), SecretColor);
			}
			else if(textBoxInput->Text->StartsWith("/dice", StringComparison::OrdinalIgnoreCase)){
				if(MTOPTION.CONNECTION_TYPE == CT_SERVER){
					BYTE dice = (BYTE)(XorShift() % 101);

					array<BYTE>^ send = gcnew array<BYTE>(2){ PH_DICE, dice };
					PacketSendAllMember(send, 0);

					Monitor::Enter(richTextBoxLog);
					try{
						richTextBoxLog->SelectionStart = richTextBoxLog->Text->Length;

						richTextBoxLog->SelectionColor = TalkMessageColor;
						richTextBoxLog->SelectionBackColor = NoticeBackColor;
						richTextBoxLog->AppendText(Byte(dice).ToString() + "\n");

						richTextBoxLog->SelectionStart = richTextBoxLog->Text->Length;
						if(!MTOPTION.LOG_LOCK) {
							richTextBoxLog->ScrollToCaret();
						}
					}
					catch(Exception ^e){
						WriteErrorLog(e->ToString(), "RichTextBox");
					}
					finally{
						Monitor::Exit(richTextBoxLog);
					}
				}
			}
			else if(textBoxInput->Text->StartsWith("/leave", StringComparison::OrdinalIgnoreCase)){
				Leave(true);
			}
			else if(textBoxInput->Text->StartsWith("/exit", StringComparison::OrdinalIgnoreCase)){
				this->Close();
			}
			else if(textBoxInput->Text->StartsWith("/memberlist", StringComparison::OrdinalIgnoreCase)){
				// ƒfƒoƒbƒO—pƒRƒ}ƒ“ƒh
				if(UDP == nullptr){
					return;
				}
				if(MTINFO.DEBUG){
					WriteMessage("NAME / ID / IP_EP / TYPE\n", DebugMessageColor);
					for(int i = 0; i < MemberList->Count; i++){
						// TYPE 0:Server 1:Host 2:Client	
						WriteMessage(String::Format("{0} / {1} / {2} / {3}\n", MemberList[i]->NAME, MemberList[i]->ID, MemberList[i]->IP_EP, MemberList[i]->TYPE), DebugMessageColor);
					}
				}
			}
			else if(textBoxInput->Text->StartsWith("/memberhistory", StringComparison::OrdinalIgnoreCase)){
				// ƒfƒoƒbƒO—pƒRƒ}ƒ“ƒh
				if(MTOPTION.CONNECTION_TYPE != CT_SERVER || UDP == nullptr){
					return;
				}
				if(MTINFO.DEBUG){
					WriteMessage("ID / IP_EP\n", DebugMessageColor);
					for(int i = 0; i < MemberListBackUp->Count; i++){
						WriteMessage(String::Format("{0} / {1}\n", MemberListBackUp[i]->ID, MemberListBackUp[i]->IP_EP), DebugMessageColor);
					}
				}
			}
			else if(textBoxInput->Text->StartsWith("/reload")){
				ReloadList();
			}
			else if(textBoxInput->Text->StartsWith("/test", StringComparison::OrdinalIgnoreCase)){
				// ƒfƒoƒbƒO—pƒRƒ}ƒ“ƒh

				//Debug::WriteLine("test");
				//Thread::Sleep(100 * 1000);
				//ChangeState((BYTE)MS_FREE);

				
			}
		}

		void AddListView(MemberInfo^% info){
			switch(ListView){
			case LV_NAME:
				listBoxMember->Items->Add(info->NAME);
				break;

			case LV_COMMENT:
				if(info->COMMENT->Length > 0){
					listBoxMember->Items->Add(info->COMMENT);
					listBoxMember->Items->Add(info->LOOKING);
					listBoxMember->Items->Add(info->AVOIDING);
					listBoxMember->Items->Add(info->REGION);
				}
				else{
					listBoxMember->Items->Add(gcnew String("?"));
				}
				break;

			case LV_BLIND:
				listBoxMember->Items->Add(gcnew String("?"));
				break;
			}
		}

		void ChangeListView(bool auto_change){
			listBoxMember->SelectedIndex = -1;

			if(ListView == LV_BLIND){
				return;
			}

			// –¼‘O‚ÆƒRƒƒ“ƒg‚ÌŽ©“®Ø‚è‘Ö‚¦
			if(auto_change){
				switch(ListView){
				case LV_NAME:
					ListView = LV_COMMENT;
					break;

				case LV_COMMENT:
					ListView = LV_NAME;
					break;

				case LV_BLIND:
					break;
				}
			}

			Monitor::Enter(MemberList);
			try{
				for(int i = 0; i < listBoxMember->Items->Count; i++){
					switch(ListView){
					case LV_NAME:
						listBoxMember->Items[i] = MemberList[i]->NAME;
						break;

					case LV_COMMENT:
						if(MemberList[i]->COMMENT->Length > 0){
							listBoxMember->Items[i] = MemberList[i]->COMMENT;
						}
						else{
							listBoxMember->Items[i] = gcnew String("?");
						}
						break;

					case LV_BLIND:
						listBoxMember->Items[i] = gcnew String("?");
						break;
					}
				}
			}
			finally{
				Monitor::Exit(MemberList);
			}
		}

		void ResetDelay(UINT value){
			toolStripMenuItemDelayAuto->Checked = false;
			toolStripMenuItemDelay2->Checked    = false;
			toolStripMenuItemDelay3->Checked    = false;
			toolStripMenuItemDelay4->Checked    = false;
			toolStripMenuItemDelay5->Checked    = false;
			toolStripMenuItemDelay6->Checked    = false;
			toolStripMenuItemDelay7->Checked    = false;
			toolStripMenuItemDelay8->Checked    = false;
			toolStripMenuItemDelay9->Checked    = false;
			toolStripMenuItemDelay10->Checked   = false;
			toolStripMenuItemDelay11->Checked   = false;
			toolStripMenuItemDelay12->Checked   = false;

			switch(value){
			case 0:
			default:
				toolStripMenuItemDelayAuto->Checked = true;
				MTOPTION.DELAY = 0;
				break;
			case 2:
				toolStripMenuItemDelay2->Checked = true;
				MTOPTION.DELAY = 2;
				break;
			case 3:
				toolStripMenuItemDelay3->Checked = true;
				MTOPTION.DELAY = 3;
				break;
			case 4:
				toolStripMenuItemDelay4->Checked = true;
				MTOPTION.DELAY = 4;
				break;
			case 5:
				toolStripMenuItemDelay5->Checked = true;
				MTOPTION.DELAY = 5;
				break;
			case 6:
				toolStripMenuItemDelay6->Checked = true;
				MTOPTION.DELAY = 6;
				break;
			case 7:
				toolStripMenuItemDelay7->Checked = true;
				MTOPTION.DELAY = 7;
				break;
			case 8:
				toolStripMenuItemDelay8->Checked = true;
				MTOPTION.DELAY = 8;
				break;
			case 9:
				toolStripMenuItemDelay9->Checked = true;
				MTOPTION.DELAY = 9;
				break;
			case 10:
				toolStripMenuItemDelay10->Checked = true;
				MTOPTION.DELAY = 10;
				break;
			case 11:
				toolStripMenuItemDelay11->Checked = true;
				MTOPTION.DELAY = 11;
				break;
			case 12:
				toolStripMenuItemDelay12->Checked = true;
				MTOPTION.DELAY = 12;
				break;
			}
		}


		void ReloadList(){
			// ƒƒ“ƒo[ƒŠƒXƒgXV
			if(MTOPTION.CONNECTION_TYPE == CT_SERVER || UDP == nullptr){
				return;
			}
			int count = MemberList->Count;
			if(count > 1){
				for(int i = 2; i < count; i++){
					MemberList->RemoveAt(2);
					listBoxMember->Items->RemoveAt(2);
				}
			}
			array<BYTE>^ send = gcnew array<BYTE>(3){ PH_REQ_LIST };
			Array::Copy(BitConverter::GetBytes(0), 0, send, 1, 2);
			UDP->Send(send, 3, MemberList[1]->IP_EP);

			WriteMessage("The member list has been updated.\n", SystemMessageColor);
		}
		void WriteStatus(String^ msg){
			//toolStripStatusLabel->Text = msg;
		}
	public:

		// IPŽæ“¾Š®—¹
		void GetIPOpenReadCompleted(System::Object^ sender, System::Net::OpenReadCompletedEventArgs^ e) {

			// I—¹—p
			if(GetIPClient == nullptr) return;
			if(GetIPCancelled == true) {
				GetIPCancelled = false;
				GetIPClient = nullptr;
				return;
			}
			// TimerGetIPƒ^ƒCƒ€ƒAƒEƒg
			if(e->Cancelled) {
				WriteMessage("The request to obtain an IP address was canceled due to a timeout.\n", ErrorMessageColor);
				if(MTINFO.DEBUG){
					WriteMessage(e->ToString() + "\n", DebugMessageColor);
				}
				GetIPClient = nullptr;
				return;
			}
			// ƒAƒhƒŒƒX‚Ì’Šo
			String^ html;
			_int64 Global_address;
			array<String^> ^s1, ^s2, ^s3;
			Stream^ reply = nullptr;
			StreamReader^ sr = nullptr;
			try{
				reply = dynamic_cast<Stream^>(e->Result);
				sr = gcnew StreamReader(reply);
				html = sr->ReadToEnd();
				s1 = html->Split(':');
				s2 = s1[1]->Split('<');
				s3 = s2[0]->Split(' ');
				Global_address = Int64(Net::IPAddress::Parse(s3[1])->Address);
			}
			catch(Exception^ e) {
				Global_address = 0;
				WriteMessage("ERROR: Failed to extract IP address information. This version of MorningStar may be outdated.\n", ErrorMessageColor);

				if(MTINFO.DEBUG){
					WriteMessage(e->ToString() + "\n", DebugMessageColor);
				}
			}
			finally{
				// Stream‚Í‚µ‚Á‚©‚èŠJ•ú
				if(sr != nullptr) sr->Close();
				if(reply != nullptr) reply->Close();
			}
			if(Global_address > 0) {
				WriteMessage(String::Format("IP Address Obtained\n", s3[1]), SystemMessageColor);
				WriteMessage("[Converted Address]\nMorningStar: ", SystemMessageColor);

				richTextBoxLog->SelectionColor = TalkMessageColor;
				richTextBoxLog->SelectionBackColor = NoticeBackColor;
				richTextBoxLog->AppendText(String::Format("{0}:{1}\n", EncryptionIP(s3[1]), MTOPTION.OPEN_PORT));
				
				//WriteMessage("MTSP—p > ", SystemMessageColor);
				//richTextBoxLog->SelectionColor = TalkMessageColor;
				//richTextBoxLog->SelectionBackColor = NoticeBackColor;
				//richTextBoxLog->AppendText(String::Format("{0}:{1}\n", MTEncryptionIP(s3[1]), MTOPTION.OPEN_PORT));


				WriteMessage("-------------------------------\n", SystemMessageColor);
			}
			GetIPClient = nullptr;
		}

		void ChangeComment(String^ comment){
			if(UDP == nullptr || (MTOPTION.CONNECTION_TYPE != CT_FREE && ServerMode >= SM_MATCH)){
				return;
			}

			MemberList[0]->COMMENT = comment;

			if(ListView == LV_COMMENT){
				if(comment->Length > 0){
					listBoxMember->Items[0] = comment;
				}
				else{
					listBoxMember->Items[0] = gcnew String("Ÿ");
				}
			}

			BYTE len = (BYTE)(comment->Length * 2);
			array<BYTE>^ send = gcnew array<BYTE>(4 + len);

			send[0] = PH_CHANGE_COMMENT;
			Array::Copy(BitConverter::GetBytes(MemberList[0]->ID), 0, send, 1, 2);
			send[3] = len;
			Array::Copy(Encoding::Unicode->GetBytes(comment), 0, send, 4, len);

			if(MTOPTION.CONNECTION_TYPE == CT_SERVER){
				PacketSendAllMember(send, 0);
			}
			else{
				UDP->BeginSend(send, send->Length, MemberList[1]->IP_EP, gcnew AsyncCallback(SendPackets), UDP);
			}
		}

		void ResetColor(){
			NameColor = gcnew array<Color>{
				Color::FromArgb(MTCOLOR.SERVER_NAME),
				Color::FromArgb(MTCOLOR.HOST_NAME),
				Color::FromArgb(MTCOLOR.CLIENT_NAME),
				SystemColors::WindowText,
			};

			StateRectColor = gcnew array<Color>{
				Color::FromArgb(MTCOLOR.REST_STATE),
				Color::FromArgb(MTCOLOR.VS_STATE),
				Color::FromArgb(MTCOLOR.WATCH_STATE),
				Color::FromArgb(MTCOLOR.SEEK_STATE),
			};

			TalkMessageColor   = SystemColors::WindowText;
			SystemMessageColor = Color::FromArgb(MTCOLOR.SYSTEM_MESSAGE);
			ErrorMessageColor  = Color::FromArgb(MTCOLOR.ERROR_MESSAGE);
			DebugMessageColor  = Color::FromArgb(MTCOLOR.DEBUG_MESSAGE);
			NoticeBackColor    = Color::FromArgb(MTCOLOR.NOTICE_BACK);
			CommentBackColor   = Color::FromArgb(MTCOLOR.COMMENT_BACK);
			SecretColor        = Color::FromArgb(MTCOLOR.SECRET);
		}

		void GetIPAddress(){
			if(GetIPClient == nullptr){
				// ƒOƒ[ƒoƒ‹IP‚ÌŽæ“¾
				GetIPClient = gcnew WebClient();
				GetIPClient->OpenReadCompleted += gcnew OpenReadCompletedEventHandler(this, &MainForm::GetIPOpenReadCompleted);

				// ƒ^ƒCƒ€ƒAƒEƒgƒ^ƒCƒ}[
				WriteMessage("Obtaining IP address from http://checkip.dyndns.org/ \n", SystemMessageColor);
				TimerGetIPThread = gcnew Thread(gcnew ThreadStart(this, &MainForm::TimerGetIP));
				TimerGetIPThread->Start();
				try{
					GetIPClient->OpenReadAsync(GetIPUri);
				}
				catch(WebException^ e) {
					WriteMessage("ERROR: Could not obtain IP address.\n", ErrorMessageColor);

					if(MTINFO.DEBUG){
						WriteMessage(e->ToString() + "\n", DebugMessageColor);
					}
				}
			}
		}
		void ChangeProfileEnabled(){
			// ƒvƒƒtƒ@ƒCƒ‹ƒhƒƒbƒvƒ_ƒEƒ“XV
			toolStripDropDownButtonProfile->DropDownItems->Clear();
			for(int i=0; i < Profile::ProfileList->Count; i++){
				if(Profile::ProfileList[i] == gcnew String(MTOPTION.PROFILE)){
					toolStripDropDownButtonProfile->Text = Profile::ProfileList[i];			
				}
				toolStripDropDownButtonProfile->DropDownItems->Add(Profile::ProfileList[i]);
				toolStripDropDownButtonProfile->DropDownItems[i]->Click += gcnew System::EventHandler(this, &MainForm::toolStripDropDownItemProfile_Click);
			}
			toolStripDropDownButtonProfile->Enabled = true;
		}
		void SetAutoRestTime(UINT time){
			MTOPTION.AUTO_REST_TIME = time;
			toolStripMenuItemAutoRestTime5->Checked = 0;
			toolStripMenuItemAutoRestTime10->Checked = 0;
			toolStripMenuItemAutoRestTime15->Checked = 0;
			toolStripMenuItemAutoRestTime20->Checked = 0;
			toolStripMenuItemAutoRestTime30->Checked = 0;
			toolStripMenuItemAutoRestTime60->Checked = 0;
			toolStripMenuItemAutoRestTime120->Checked = 0;
			toolStripMenuItemAutoRestTime8h->Checked = 0;
			toolStripMenuItem12h->Checked = 0;
		}

		void ToggleRest(){
			if(MTOPTION.CONNECTION_TYPE == CT_FREE) return;

			if(MemberList[0]->STATE == MS_FREE){
				ChangeState((BYTE)MS_REST);
				WriteMessage("Rest mode is now ON.\n", SystemMessageColor);
			}
			else if(MemberList[0]->STATE == MS_REST){
				ChangeState((BYTE)MS_FREE);
				WriteMessage("Rest mode is now OFF.\n", SystemMessageColor);
			}
		}

	private:
#pragma endregion
#pragma region Load Settings
		System::Void MainForm_Load(System::Object^  sender, System::EventArgs^  e) {
			// sŠÔ‚ð‹l‚ß‚é
			richTextBoxLog->LanguageOption = RichTextBoxLanguageOptions::UIFonts;

			// ƒXƒŒƒbƒhŠÔ‚ÌŒÄ‚Ño‚µŠm”F‚ð–³Œø‚É‚·‚é
			Control::CheckForIllegalCrossThreadCalls = false;

			if(MTWS.LEFT > 0 && MTWS.TOP > 0){
				this->StartPosition = FormStartPosition::Manual;
				this->Location = System::Drawing::Point(MTWS.LEFT, MTWS.TOP);
			}

			if(MTWS.WIDTH > 0 && MTWS.HEIGHT > 0){
				this->ClientSize = System::Drawing::Size(MTWS.WIDTH, MTWS.HEIGHT);
			}

			if(MTWS.SPLITTER > 0){
				splitContainer1->SplitterDistance = MTWS.SPLITTER;
			}

			ResetDelay(MTOPTION.DELAY);
			ResetColor();

			toolStripMenuItemRecordReplay->Checked   = MTOPTION.RECORD_REPLAY;
			toolStripMenuItemAllowSpectator->Checked = MTOPTION.ALLOW_SPECTATOR;
			LogLockToolStripMenuItem->Checked        = MTOPTION.LOG_LOCK;
			toolStripMenuItemWordWrap->Checked       = MTOPTION.LOG_WORDWRAP;
			richTextBoxLog->WordWrap				 = MTOPTION.LOG_WORDWRAP;
			toolStripMenuItemAfterRest->Checked      = MTOPTION.AFTER_REST;
			toolStripMenuItemAutoRestEnable->Checked = MTOPTION.AUTO_REST;
			switch(MTOPTION.AUTO_REST_TIME){
				case 5:
					toolStripMenuItemAutoRestTime5->Checked = 1;
					break;
				case 10:
					toolStripMenuItemAutoRestTime10->Checked = 1;
					break;
				case 15:
					toolStripMenuItemAutoRestTime15->Checked = 1;
					break;
				case 20:
					toolStripMenuItemAutoRestTime20->Checked = 1;
					break;
				case 30:
					toolStripMenuItemAutoRestTime30->Checked = 1;
					break;
				case 60:
					toolStripMenuItemAutoRestTime60->Checked = 1;
					break;
				case 120:
					toolStripMenuItemAutoRestTime120->Checked = 1;
					break;
				case 480:
					toolStripMenuItemAutoRestTime8h->Checked = 1;
					break;
				case 720:
					toolStripMenuItem12h->Checked = 1;
					break;
			}

			IsFormClosing = false;
			ListView = LV_NAME;

			ChatHistoryNumber = 0;
			ChatHistory = gcnew Generic::List<String^>;

			UDP = nullptr;

			MemberList          = gcnew Generic::List<MemberInfo^>;
			MemberListBackUp    = gcnew Generic::List<MemberInfoBackUp^>;
			SpectatorList       = gcnew Generic::List<SpectatorInfo^>;
			WatchHistory        = gcnew array<UINT16>(TIME_OUT/5 * 3);
			InputHistory        = gcnew array<UINT16>(TIME_OUT/5 * 3);

			// richtextbox‚ÌƒfƒtƒHƒ‹ƒgfalseƒoƒO‘Îô
			richTextBoxLog->AutoWordSelection = true;
			richTextBoxLog->AutoWordSelection = false;

			timeBeginPeriod(1);
		}

		System::Void MainForm_Shown(System::Object^  sender, System::EventArgs^  e) {
			textBoxInput->Focus();

			this->toolStripMenuItemVersion_Click(nullptr, nullptr);

			if(MTINFO.SERVER_MODE){
				// Initiates server mode.
				MTOPTION.CONNECTION_TYPE = CT_SERVER;
				if(MTINFO.SERVER_MODE_PORT > 0){
					MTOPTION.OPEN_PORT = MTINFO.SERVER_MODE_PORT;
				}
			}else{
				StartupForm^ s = gcnew StartupForm;
				s->ShowDialog(this);

				if(!File::Exists(gcnew String(MTOPTION.GAME_EXE))){
					MessageBox::Show("Please set the path to the Fighter Maker executable file.", "No game file found");

					OptionForm^ o = gcnew OptionForm;
					o->GameExePathError = true;
					o->ShowDialog(this);
				}
			}

			Begin();
		}
#pragma endregion
#pragma region Functions
		System::Void MainForm_FormClosing(System::Object^  sender, System::Windows::Forms::FormClosingEventArgs^  e) {
			if(IsFormClosing == false && GameThread != nullptr && GameThread->IsAlive){
				IsFormClosing = true;

				QuitGame();

				e->Cancel = true;
				return;
			}

			if(MTOPTION.CONNECTION_TYPE == CT_SERVER && MTINFO.ERRORED == false){
				if(MessageBox::Show(L"If you close MorningStar, the server will be closed and all players will be kicked.\nShut down the server?", L"Confirm Server Shutdown", MessageBoxButtons::YesNo, MessageBoxIcon::Question) == ::DialogResult::No){
					IsFormClosing = false;
					e->Cancel = true;
					return;
				}
			}

			QuitWatch(true);
			CloseUdp(true);

			// IPŽæ“¾‚ÌƒLƒƒƒ“ƒZƒ‹
			if(GetIPClient != nullptr){
				GetIPCancelled = true;
				GetIPClient->CancelAsync();
			}
			if(TimerGetIPThread != nullptr && TimerGetIPThread->IsAlive){
				if(GetIPSleeping){
					TimerGetIPThread->Interrupt();
				}
				TimerGetIPThread->Join();
			}

			// ”O‚Ì‚½‚ß
			Thread::Sleep(500);
		}

		System::Void MainForm_FormClosed(System::Object^  sender, System::Windows::Forms::FormClosedEventArgs^  e) {
			MTWS.LEFT     = this->Location.X;
			MTWS.TOP      = this->Location.Y;
			MTWS.WIDTH    = this->ClientSize.Width;
			MTWS.HEIGHT   = this->ClientSize.Height;
			MTWS.SPLITTER = splitContainer1->SplitterDistance;

			timeEndPeriod(1);
		}
#pragma endregion
#pragma region Chat & Client
		System::Void textBoxInput_KeyDown( Object^ sender, System::Windows::Forms::KeyEventArgs^ e ) {
			// Event when typing in the message box.
			if(ChatHistory->Count > 0){
				if(e->KeyCode == Keys::Up){
					ChatHistoryNumber--;
					if(ChatHistoryNumber < 0){
						ChatHistoryNumber = 0;
					}

					textBoxInput->Text = ChatHistory[ChatHistoryNumber];
					textBoxInput->SelectAll();
					e->SuppressKeyPress = true;
				}
				else if(e->KeyCode == Keys::Down){
					ChatHistoryNumber++;
					if(ChatHistoryNumber > ChatHistory->Count){
						ChatHistoryNumber = ChatHistory->Count;
					}

					if(ChatHistoryNumber == ChatHistory->Count){
						textBoxInput->Clear();
					}
					else{
						textBoxInput->Text = ChatHistory[ChatHistoryNumber];
						textBoxInput->SelectAll();
						e->SuppressKeyPress = true;
					}
				}
			}

			// Event when pressing enter on the message box (usually sends the message).
			if(e->KeyCode == Keys::Enter && textBoxInput->Text->Length > 0){
				// ƒ`ƒƒƒbƒg—š—ðXV
				if(ChatHistoryNumber < ChatHistory->Count){
					if(ChatHistory[ChatHistoryNumber] != textBoxInput->Text){
						ChatHistory->Add(textBoxInput->Text);
					}
				}
				else{
					ChatHistory->Add(textBoxInput->Text);
				}

				if(MTOPTION.CHAT_HISTORY > 0 && (UINT)ChatHistory->Count > MTOPTION.CHAT_HISTORY){
					ChatHistory->RemoveAt(0);
				}
				ChatHistoryNumber = ChatHistory->Count;

				try{
					if(e->Control && MTOPTION.CONNECTION_TYPE == CT_SERVER){
						// ’m
						BYTE len = (BYTE)(textBoxInput->Text->Length * 2);
						array<BYTE>^ msg = gcnew array<BYTE>(2 + len);

						msg[0] = PH_NOTICE;
						msg[1] = len;
						Array::Copy(Encoding::Unicode->GetBytes(textBoxInput->Text), 0, msg, 2, len);

						PacketSendAllMember(msg, 0);
	
						WriteMessage("[MOTD]---------------------\n", SystemMessageColor);
						WriteNotice(textBoxInput->Text);
						WriteMessage("-------------------------------\n", SystemMessageColor);
					}
					else if(textBoxInput->Text[0] == '/'){
						AnalyzeCommand();
					}
					else if(UDP != nullptr && ServerMode >= SM_MATCH){
						WriteMessage("Chat is disabled on this server.\n", SystemMessageColor);
					}
					else if(UDP != nullptr){
						// ƒ`ƒƒƒbƒg”­Œ¾
						BYTE len = (BYTE)(textBoxInput->Text->Length * 2);
						array<BYTE>^ msg = gcnew array<BYTE>(4 + len);

						msg[0] = PH_MESSAGE;
						Array::Copy(BitConverter::GetBytes(MemberList[0]->ID), 0, msg, 1, 2);
						msg[3] = len;
						Array::Copy(Encoding::Unicode->GetBytes(textBoxInput->Text), 0, msg, 4, len);

						TalkMessage(MemberList[0]->ID, msg);
					}
					else{
						WriteMessage(textBoxInput->Text + "\n", TalkMessageColor);
					}
				}
				catch(Exception^ e){
					if(MTINFO.DEBUG){
						WriteMessage(String::Format("{0}\n", e->ToString()), DebugMessageColor);
					}
				}

				textBoxInput->Clear();
				e->SuppressKeyPress = true;
			}
		}

		System::Void listBoxMember_DrawItem(System::Object^  sender, System::Windows::Forms::DrawItemEventArgs^  e) {
			if(e->Index == -1) return;
			try{
				UINT state = MemberList[e->Index]->STATE;
				Brush^ b = gcnew SolidBrush(NameColor[MemberList[e->Index]->TYPE]);

				switch(state){
				case MS_REST:
					e->Graphics->FillRectangle(gcnew SolidBrush(StateRectColor[0]), e->Bounds);
					break;

				case MS_VS:
					e->Graphics->FillRectangle(gcnew SolidBrush(StateRectColor[1]), e->Bounds);
					break;

				case MS_WATCH:
				case MS_COUCH:
					e->Graphics->FillRectangle(gcnew SolidBrush(StateRectColor[2]), e->Bounds);
					break;
				case MS_SEEK:
					e->Graphics->FillRectangle(gcnew SolidBrush(StateRectColor[3]), e->Bounds);
					break;
				default:
					e->DrawBackground();
				}

				e->Graphics->DrawString(listBoxMember->Items[e->Index]->ToString(), e->Font, b, e->Bounds);
				e->DrawFocusRectangle();
			}
			catch(ArgumentOutOfRangeException^){
			}
		}

		System::Void listBoxMember_MouseDoubleClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
			int index = listBoxMember->IndexFromPoint(e->X, e->Y);

			if(index == -1){
				ChangeListView(true);
			}

			if(MTOPTION.CONNECTION_TYPE == CT_FREE){
				return;
			}

			if(index == 0){
				int state = MemberList[0]->STATE;

				// ‹xŒeó‘Ô‚Ì•ÏX
				if(state == MS_FREE){
					ChangeState((BYTE)MS_REST);
					WriteMessage("Rest mode is now ON.\n", SystemMessageColor);
				}
				else if(state == MS_REST){
					ChangeState((BYTE)MS_FREE);
					WriteMessage("Rest mode is now OFF.\n", SystemMessageColor);
				}
				else if(state == MS_VS){
					WriteMessage("Ending match.\n", SystemMessageColor);
					QuitGame();
				}
				else if(state == MS_WATCH || state == MS_COUCH){
					WriteMessage("Ending spectate.\n", SystemMessageColor);
					QuitWatch(true);
				}
			}
			else if(index > 0 && UDP != nullptr){
				// ó‘Ô‚ÌÄŽæ“¾
				array<BYTE>^ send = gcnew array<BYTE>(3){ PH_REQ_STATE };
				Array::Copy(BitConverter::GetBytes(MemberList[index]->ID), 0, send, 1, 2);

				if(MTOPTION.CONNECTION_TYPE == CT_SERVER){
					UDP->BeginSend(send, send->Length, MemberList[index]->IP_EP, gcnew AsyncCallback(SendPackets), UDP);
				}
				else{
					UDP->BeginSend(send, send->Length, MemberList[1]->IP_EP, gcnew AsyncCallback(SendPackets), UDP);
				}

				// Ping
				this->toolStripMenuItemPing_Click(nullptr, nullptr);
			}
		}
		// When clicked, shows information about the selected user, including a comment, what they're looking for, or what they're avoiding.
		// Also shows region if enabled.
		System::Void listBoxMember_MouseClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
			int index = listBoxMember->IndexFromPoint(e->X, e->Y);

			if(index == -1 || MTOPTION.CONNECTION_TYPE == CT_FREE || ListView == LV_BLIND){
				toolTipMember->Active = false;
				return;
			}
			else{
				toolTipMember->Active = true;
			}
			String^ cap = String::Format("ID = {0}", MemberList[index]->ID);
			if(index > 0){
				cap += String::Format(", VS = {0}", MemberList[index]->NUM_VS);
			}
			if(ListView == LV_NAME){
				if(MemberList[index]->COMMENT->Length > 0){
					cap += "\n" + "Comment: " + MemberList[index]->COMMENT;
					
					// Ignore new feature strings if using legacy netcode feature.
					if(MTOPTION.LEGACY_SERVER == true){
					}else{
						cap += "\n" + "Looking for: " + MemberList[index]->LOOKING;
						cap += "\n" + "Avoiding: " + MemberList[index]->AVOIDING;
						if (MTOPTION.SHOW_REGION == false){
							cap += "\n" + "Region: N/A";
						}else{
							cap += "\n" + "Region: " + MemberList[index]->REGION;
						}
					}
				}
			}
			else if(ListView == LV_COMMENT){
				cap += "\n" + MemberList[index]->NAME;
			}
			toolTipMember->SetToolTip(listBoxMember, cap);
		}
#pragma endregion
#pragma region Main Menu
#pragma region File
		//Allows you to open a .mtr replay file.
		System::Void toolStripMenuItemReplay_Click(System::Object^  sender, System::EventArgs^  e) {
			ReplayFilePath = String::Empty;
			StartGame(RT_PLAYBACK);
		}
		// Saves the current chat log to the MorningStar directory.
		System::Void toolStripMenuItemSaveLog_Click(System::Object^  sender, System::EventArgs^  e) {
			SaveLog();
		}
		//Ends the MorningStar process.
		System::Void toolStripMenuItemExit_Click(System::Object^  sender, System::EventArgs^  e) {
			this->Close();
		}
#pragma endregion
#pragma region Commands
		// Opens the MorningStar Settings form.
		System::Void toolStripMenuItemSetting_Click(System::Object^  sender, System::EventArgs^  e) {
			LoadSettings();
		}
#pragma endregion
#pragma region Options

#pragma endregion
#pragma endregion
		
		// Get a comprehensive command and shortcut list.
		System::Void toolStripMenuItemViewCommand_Click(System::Object^  sender, System::EventArgs^  e) {
			WriteCommandList();
		}
		// Change the username list on the left-hand side of the main window.
		System::Void toolStripMenuItemChangeList_Click(System::Object^  sender, System::EventArgs^  e) {
			ChangeListView(true);
		}
		// Get the version string of MorningStar.
		System::Void toolStripMenuItemVersion_Click(System::Object^  sender, System::EventArgs^  e) {
			WriteMessage("MorningStar 2.0.0.0 by WindowsLogic Productions.\n", SystemMessageColor);
			WriteMessage("Donate towards development: https://paypal.me/windowslogic \n\n", SystemMessageColor);
		}

		// Adds the current server to your bookmarks with a maximum of 10.
		System::Void toolStripMenuItemAddBookMark_Click(System::Object^  sender, System::EventArgs^  e) {
			if((MTOPTION.BOOKMARK_COUNT - MTOPTION.BOOKMARK_DELETED_COUNT) > 10) {
				MessageBox::Show(L"You can only have up to 10 bookmarks. Please free up some space by deleting some bookmarks.", L"Add Bookmark", MessageBoxButtons::OK, MessageBoxIcon::Exclamation);
				return;
			}
			if(MTOPTION.CONNECTION_TYPE == CT_SERVER || MTOPTION.CONNECTION_TYPE == CT_FREE ){
				MessageBox::Show(L"You can't add anything to the bookmarks list while in Free Play mode or in Server mode!", L"Add Bookmark", MessageBoxButtons::OK, MessageBoxIcon::Exclamation);
				return;
			}

			String^ tmpName = ServerName;
			String^ tmpIP = ConnectIP;
			UINT tmpInt = MTOPTION.BOOKMARK_COUNT;

			toolStripMenuItemBookMark = (gcnew System::Windows::Forms::ToolStripMenuItem());
			toolStripMenuItemBookMarkMenu->DropDownItems->Add(toolStripMenuItemBookMark);
			toolStripMenuItemBookMark->Text = ServerName;
			toolStripMenuItemBookMark->Name = L"toolStripMenuItemBookMark" + MTOPTION.BOOKMARK_COUNT;
			toolStripMenuItemBookMark->Tag = MTOPTION.BOOKMARK_COUNT;
			toolStripMenuItemBookMark->Click += gcnew System::EventHandler(this, &MainForm::toolStripMenuItemBookMark_Click);

			// Configure delete bookmark menu item.
			toolStripMenuItemDelBookMark = (gcnew System::Windows::Forms::ToolStripMenuItem());
			toolStripMenuItemBookMark->DropDownItems->Add(toolStripMenuItemDelBookMark);
			toolStripMenuItemDelBookMark->Text = L"&Delete bookmark";
			toolStripMenuItemDelBookMark->Tag = L"toolStripMenuItemBookMark" + MTOPTION.BOOKMARK_COUNT;
			toolStripMenuItemDelBookMark->Click += gcnew System::EventHandler(this, &MainForm::toolStripMenuItemDelBookMark_Click);
			
			BookMarkServerName = Runtime::InteropServices::Marshal::StringToHGlobalAuto(tmpName);
			_tcscpy_s(MTOPTION.BOOKMARK_SERVER_NAME[tmpInt], static_cast<PTCHAR>(BookMarkServerName.ToPointer()));
			Runtime::InteropServices::Marshal::FreeHGlobal(BookMarkServerName);

			BookMarkConnectIP = Runtime::InteropServices::Marshal::StringToHGlobalAuto(tmpIP);
			_tcscpy_s(MTOPTION.BOOKMARK_CONNECTION_IP[tmpInt], static_cast<PTCHAR>(BookMarkConnectIP.ToPointer()));
			Runtime::InteropServices::Marshal::FreeHGlobal(BookMarkConnectIP);

			_itot_s(MTOPTION.CONNECTION_TYPE, MTOPTION.BOOKMARK_CONNECTION_TYPE[tmpInt], 10);
			_itot_s(MTOPTION.OPEN_PORT,       MTOPTION.BOOKMARK_PORT[tmpInt],            10);

			MTOPTION.BOOKMARK_COUNT++;

			SaveMTOption();
		}
		// Reconnects the client with the selected address appearing in the "Address / IP" area so you can connect to that server.
		System::Void toolStripMenuItemBookMark_Click(System::Object^ sender, System::EventArgs^ e) {
			UINT tmpInt = (UINT)((ToolStripMenuItem^)sender)->Tag;

			if(MessageBox::Show(((ToolStripMenuItem^)sender)->Text+" Selected", "Connect to Bookmark?", MessageBoxButtons::YesNo, MessageBoxIcon::Question) == ::DialogResult::Yes){
			}else{
				return;
			}

			_tcscpy_s(MTOPTION.CONNECTION_IP,   MTOPTION.BOOKMARK_CONNECTION_IP[tmpInt]);
			MTOPTION.CONNECTION_TYPE = (UINT)_ttoi(MTOPTION.BOOKMARK_CONNECTION_TYPE[tmpInt]);
			MTOPTION.OPEN_PORT       = (UINT)_ttoi(MTOPTION.BOOKMARK_PORT[tmpInt]);

			Restart();
		}
		// Deletes the selected bookmark.
		System::Void toolStripMenuItemDelBookMark_Click(System::Object^ sender, System::EventArgs^ e) {
			Object^ tmpTag;
			tmpTag = ((ToolStripMenuItem^)sender)->Tag;
			UINT tmpInt = (UINT)toolStripMenuItemBookMarkMenu->DropDownItems[(String^)tmpTag]->Tag;
			if(MessageBox::Show((String^)toolStripMenuItemBookMarkMenu->DropDownItems[(String^)tmpTag]->Text+" Select. Are you sure you want to delete this bookmark from the bookmarks menu?", "Delete Bookmark", MessageBoxButtons::YesNo, MessageBoxIcon::Question) == ::DialogResult::Yes){
				toolStripMenuItemBookMarkMenu->DropDownItems->Remove(toolStripMenuItemBookMarkMenu->DropDownItems[(String^)tmpTag]);
				MTOPTION.BOOKMARK_DELETED_COUNT++;

				ZeroMemory(MTOPTION.BOOKMARK_SERVER_NAME[tmpInt], sizeof(MTOPTION.BOOKMARK_SERVER_NAME[tmpInt]));
				ZeroMemory(MTOPTION.BOOKMARK_CONNECTION_IP[tmpInt], sizeof(MTOPTION.BOOKMARK_CONNECTION_IP[tmpInt]));
				ZeroMemory(MTOPTION.BOOKMARK_CONNECTION_TYPE[tmpInt], sizeof(MTOPTION.BOOKMARK_CONNECTION_TYPE[tmpInt]));
				ZeroMemory(MTOPTION.BOOKMARK_PORT[tmpInt], sizeof(MTOPTION.BOOKMARK_PORT[tmpInt]));

				SaveMTOption();
			}
		}

		// Starts the selected game executable in a single player simulation.
		System::Void GameStartToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			StartGame(RT_FREE);			
		}
		// Starts the selected game executable in a single player simulation (without replay).
		System::Void GameStartNoReplayToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			StartGameNoReplay();
		}
		// Ä‹N“®
		System::Void RestartToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			Reconnect();
		}

		// Leaves as the server, shutting it down and dropping all players.
		System::Void LeaveToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			if(MTOPTION.CONNECTION_TYPE == CT_SERVER) {
				if(MessageBox::Show("This will shut down the server and drop all players.\nAre you sure you want to do this?", "Leave", MessageBoxButtons::YesNo, MessageBoxIcon::Question) == ::DialogResult::Yes){
				}else{
					return;
				}
			}
			// Leaves the server, dropping you to Free Play mode.
			if(MTOPTION.CONNECTION_TYPE == CT_HOST || MTOPTION.CONNECTION_TYPE == CT_CLIENT){
				if(MessageBox::Show("This will disconnect you from the server.\nContinue?", "Leave", MessageBoxButtons::YesNo, MessageBoxIcon::Question) == ::DialogResult::Yes){
				}else{
					return;
				}
			}

			Leave(true);
		}

		// Sets and unsets user in rest mode which stops players from fighting them.
		System::Void RestToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			ToggleRest();
		}

		// Makes your name glow blue to indicate you are seeking a fight with another user.
		System::Void SeekToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			ChangeSeek();
		}

		// Clears the entire chat log.
		System::Void ClearToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			ClearLog();
		}

		// Toggles whether hit boxes and other debugging information appears when the game executable is ran.
		System::Void ToggleHitJudgeToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			MTOPTION.HIT_JUDGE ^= 1;
			if(MTINFO.INITIALIZED && MTINFO.PROCESS != NULL){
				DWORD b = MTOPTION.HIT_JUDGE;

				if(MTINFO.KGT2K){
					WriteProcessMemory(MTINFO.PROCESS, (LPVOID)HIT_JUDGE, &b, 4, NULL);
				}
				else{
					WriteProcessMemory(MTINFO.PROCESS, (LPVOID)HIT_JUDGE_95, &b, 4, NULL);
				}
			}
		}
		
		// If checked, saves replays into the user's desired directory, referenced in the MorningStar Settings.
		System::Void toolStripMenuItemRecordReplay_Click(System::Object^  sender, System::EventArgs^  e) {
			toolStripMenuItemRecordReplay->Checked ^= 1;

			MTOPTION.RECORD_REPLAY = toolStripMenuItemRecordReplay->Checked;
		}
		
		System::Void toolStripMenuItemAllowSpectator_Click(System::Object^  sender, System::EventArgs^  e) {
			toolStripMenuItemAllowSpectator->Checked ^= 1;

			MTOPTION.ALLOW_SPECTATOR = toolStripMenuItemAllowSpectator->Checked;

			if(toolStripMenuItemAllowSpectator->Checked == false && UDP != nullptr){
				array<BYTE>^ send = gcnew array<BYTE>(3){ PH_WATCH_END };

				Monitor::Enter(InputHistory);
				try{
					for(int i = 0; i < SpectatorList->Count; i++){
						Array::Copy(BitConverter::GetBytes(SpectatorList[i]->ID), 0, send, 1, 2);
						UDP->BeginSend(send, send->Length, SpectatorList[i]->IP_EP, gcnew AsyncCallback(SendPackets), UDP);
					}

					SpectatorList->Clear();
				}
				finally{
					Monitor::Exit(InputHistory);
				}
			}
		}

		// Retrieves your outside IP address.
		System::Void GetIPToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			GetIPAddress();
		}
		// Enables or disables chat auto-scrolling whenever there's a new message.
		System::Void LogLockToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			LogLockToolStripMenuItem->Checked ^= 1;
			MTOPTION.LOG_LOCK = LogLockToolStripMenuItem->Checked;
		}
		// Reloads the list of users connected to the server. Useful if join packets are lost.
		System::Void ReloadListToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			ReloadList();
		}
		// Enables or disables resting after a netplay fight.
		System::Void toolStripMenuItemAfterRest_Click(System::Object^  sender, System::EventArgs^  e) {
			toolStripMenuItemAfterRest->Checked ^= 1;
			MTOPTION.AFTER_REST = toolStripMenuItemAfterRest->Checked;
		}
		// Sets the delay in a single player simulation environment.
		System::Void toolStripMenuItemDelayAuto_Click(System::Object^  sender, System::EventArgs^  e) {
			ResetDelay(0);
		}

		System::Void toolStripMenuItemDelay2_Click(System::Object^  sender, System::EventArgs^  e) {
			ResetDelay(2);
		}

		System::Void toolStripMenuItemDelay3_Click(System::Object^  sender, System::EventArgs^  e) {
			ResetDelay(3);
		}

		System::Void toolStripMenuItemDelay4_Click(System::Object^  sender, System::EventArgs^  e) {
			ResetDelay(4);
		}

		System::Void toolStripMenuItemDelay5_Click(System::Object^  sender, System::EventArgs^  e) {
			ResetDelay(5);
		}

		System::Void toolStripMenuItemDelay6_Click(System::Object^  sender, System::EventArgs^  e) {
			ResetDelay(6);
		}

		System::Void toolStripMenuItemDelay7_Click(System::Object^  sender, System::EventArgs^  e) {
			ResetDelay(7);
		}

		System::Void toolStripMenuItemDelay8_Click(System::Object^  sender, System::EventArgs^  e) {
			ResetDelay(8);
		}

		System::Void toolStripMenuItemDelay9_Click(System::Object^  sender, System::EventArgs^  e) {
			ResetDelay(9);
		}

		System::Void toolStripMenuItemDelay10_Click(System::Object^  sender, System::EventArgs^  e) {
			ResetDelay(10);
		}

		System::Void toolStripMenuItemDelay11_Click(System::Object^  sender, System::EventArgs^  e) {
			ResetDelay(11);
		}

		System::Void toolStripMenuItemDelay12_Click(System::Object^  sender, System::EventArgs^  e) {
			ResetDelay(12);
		}

		System::Void contextMenuItemCopy_Click(System::Object^  sender, System::EventArgs^  e) {
			richTextBoxLog->Copy();
		}

		System::Void richTextBoxLog_LinkClicked(System::Object^  sender, System::Windows::Forms::LinkClickedEventArgs^  e) {
			// ‹­§I—¹‘Îô
			try{
				Process::Start(e->LinkText);
			}
			catch(Exception^){
				WriteMessage("Invalid string link.\n", ErrorMessageColor);
			}
		}

		System::Void toolStripMenuItemVS_Click(System::Object^  sender, System::EventArgs^  e) {
			if(listBoxMember->SelectedIndex == -1){
				return;
			}

			if(ListView == LV_BLIND){
				RandomVersus();
			}
			else if(MTOPTION.CONNECTION_TYPE == CT_FREE || listBoxMember->SelectedIndex == 0){
				StartGame(RT_FREE);
			}
			else{
				StartGame(RT_VS);
			}

		}

		// “_–ÅŠÖ”
		System::Void WindowFlash() {
			// ƒEƒBƒ“ƒhƒE“_–Å
			FLASHWINFO stfi;
			ZeroMemory(&stfi, sizeof(FLASHWINFO));
			stfi.cbSize = sizeof(FLASHWINFO);
			stfi.hwnd = reinterpret_cast<HWND&>(this->Handle);
			stfi.dwFlags = FLASHW_ALL;
			stfi.uCount = 3;
			stfi.dwTimeout = 0;
			FlashWindowEx(&stfi);
		}

		System::Void toolStripMenuItemWatch_Click(System::Object^  sender, System::EventArgs^  e) {
			
			if(listBoxMember->SelectedIndex == -1){return;}

			int state = MemberList[0]->STATE;
			array<BYTE>^ send = gcnew array<BYTE>(3);

			if(state == MS_FREE || state == MS_REST){
				StartGame(RT_FREE);

				this->TopMost = true;

				MessageBox::Show("Please close the game window that just appeared.","Spectate Mode");

				this->TopMost = false;

				// ŠÏíŠJŽn
				if(state == MS_FREE) ChangeState((BYTE)MS_WATCH);
				if(state == MS_REST) ChangeState((BYTE)MS_COUCH);

				WatchTarget = MemberList[listBoxMember->SelectedIndex]->IP_EP;
				TargetID    = MemberList[listBoxMember->SelectedIndex]->ID;
				WatchFrame  = 0;

				send[0] = PH_REQ_WATCH;
				Array::Copy(BitConverter::GetBytes(MemberList[0]->ID), 0, send, 1, 2);
				UDP->BeginSend(send, send->Length, WatchTarget, gcnew AsyncCallback(SendPackets), UDP);

				toolStripMenuItemWatch->Text = gcnew String("Stop spectating");
			}
			else{
				QuitWatch(true);
			}
		}

		System::Void toolStripMenuItemPing_Click(System::Object^  sender, System::EventArgs^  e) {
			if(listBoxMember->SelectedIndex == -1){return;}

			int si = listBoxMember->SelectedIndex;
			array<BYTE>^ ping = gcnew array<BYTE>(1){ PH_PING };

			Ping = timeGetTime();
			UDP->BeginSend(ping, 1, MemberList[si]->IP_EP, gcnew AsyncCallback(SendPackets), UDP);
		}

		// –¼‘O‚ðƒRƒs[
		System::Void toolStripMenuItemClipBoardCopy_Click(System::Object^  sender, System::EventArgs^  e) {
			if(listBoxMember->SelectedIndex == -1){return;}

			int si = listBoxMember->SelectedIndex;
			System::Windows::Forms::Clipboard::SetDataObject(MemberList[si]->NAME, true);
		}

		// ƒLƒbƒN
		System::Void toolStripMenuItemKick_Click(System::Object^  sender, System::EventArgs^  e) {
			if(listBoxMember->SelectedIndex == -1 || MTOPTION.CONNECTION_TYPE != CT_SERVER){return;}

			int index = listBoxMember->SelectedIndex;
			int id = MemberList[index]->ID;

			if(MessageBox::Show(String::Format("[ {0} ](ID:{1}) will be kicked.\nAre you sure you want to kick?", MemberList[index]->NAME, MemberList[index]->ID), "KICK", MessageBoxButtons::YesNo, MessageBoxIcon::Question) == ::DialogResult::Yes){
			}else{
				return;
			}
			
			try{
				// –{l‚É’Ê’m
				array<BYTE>^ send = gcnew array<BYTE>(3){ PH_LOST, 0xFF, 0xFF };
				UDP->BeginSend(send, send->Length, MemberList[index]->IP_EP, gcnew AsyncCallback(SendPackets), UDP);

				if(ListView != LV_BLIND){
					WriteTime(0, SystemMessageColor);
					WriteMessage(String::Format("{0}(ID:{1}) was kicked.\n", MemberList[index]->NAME, MemberList[index]->ID), SystemMessageColor);
				}
				if(MemberList[0]->STATE == MS_WATCH || MemberList[0]->STATE == MS_COUCH){
					if(TargetID == MemberList[index]->ID){
						QuitWatch(false);
					}
				}

				// ƒOƒbƒoƒC
				MemberList->RemoveAt(index);
				listBoxMember->Items->RemoveAt(index);

				// ‘¼‚Ìƒƒ“ƒo[‚É’Ê’m
				array<BYTE>^ quit = gcnew array<BYTE>(3){ PH_QUIT };
				Array::Copy(BitConverter::GetBytes(id), 0, quit, 1, 2);

				for(int i = 1; i < MemberList->Count; i++){
					UDP->BeginSend(quit, quit->Length, MemberList[i]->IP_EP, gcnew AsyncCallback(SendPackets), UDP);
					if(MTINFO.DEBUG){
						WriteMessage(String::Format("{0} was notified.\n", MemberList[i]->ID), DebugMessageColor);
					}
				}
			}
			catch(Exception^ e){
				if(MTINFO.DEBUG){
					WriteMessage(String::Format("{0}\n", e->ToString()), DebugMessageColor);
				}
			}
			
		}

		System::Void contextMenuStripMember_Opening(System::Object^  sender, System::ComponentModel::CancelEventArgs^  e) {
			
			toolStripMenuItemKick->Enabled     = false;

			if(listBoxMember->SelectedIndex == -1){
				toolStripMenuItemVS->Enabled			= false;
				toolStripMenuItemWatch->Enabled			= false;
				toolStripMenuItemPing->Enabled			= false;
				toolStripMenuItemClipBoardCopy->Enabled	= false;
				return;
			}

			int state = MemberList[listBoxMember->SelectedIndex]->STATE;

			toolStripMenuItemVS->Enabled			= false;
			toolStripMenuItemWatch->Enabled			= true;
			toolStripMenuItemPing->Enabled			= true;
			toolStripMenuItemClipBoardCopy->Enabled	= true;

			if(( ( state == MS_FREE || state == MS_SEEK) && ( MemberList[0]->STATE == MS_FREE || MemberList[0]->STATE == MS_SEEK )) || ListView == LV_BLIND){
				toolStripMenuItemVS->Enabled       = true;
			}
			if(listBoxMember->SelectedIndex == 0){
				if(state != MS_WATCH && state != MS_COUCH){
					toolStripMenuItemWatch->Enabled = false;
				}
				toolStripMenuItemPing->Enabled = false;
				toolStripMenuItemKick->Enabled = false;
			}else if(MemberList[listBoxMember->SelectedIndex]->TYPE == CT_SERVER || MTOPTION.CONNECTION_TYPE != CT_SERVER){
				toolStripMenuItemKick->Enabled = false;
			}else {
				toolStripMenuItemKick->Enabled = true;
			}

		}

		System::Void MainForm_DragEnter(System::Object^  sender, System::Windows::Forms::DragEventArgs^  e) {
			e->Effect = DragDropEffects::None;

			if(e->Data->GetDataPresent(DataFormats::FileDrop)){
				array<String^>^ file = safe_cast<array<String^>^>(e->Data->GetData(DataFormats::FileDrop, false));
				String^ extension = Path::GetExtension(file[0])->ToLower();
				FileVersionInfo^ info = FileVersionInfo::GetVersionInfo(file[0]);

				if(extension == ".mtr" || (extension == ".exe" && (info->LegalCopyright == "(C)2001 ENTERBRAIN,INC / OUTBACK" || info->FileDescription == "２Ｄ格闘ツクール2nd." || info->FileDescription == "２Ｄ格闘ツクール９５" || info->FileDescription == "Fighting is Magic: Aurora"))){
					e->Effect = DragDropEffects::All;
				}
			}
		}

		System::Void MainForm_DragDrop(System::Object^  sender, System::Windows::Forms::DragEventArgs^  e) {
			if(e->Data->GetDataPresent(DataFormats::FileDrop)){
				array<String^>^ file = safe_cast<array<String^>^>(e->Data->GetData(DataFormats::FileDrop, false));
				String^ extension = Path::GetExtension(file[0])->ToLower();

				if(extension == ".mtr"){
					ReplayFilePath = safe_cast<array<String^>^>(e->Data->GetData(DataFormats::FileDrop, false))[0];
					StartGame(RT_PLAYBACK);
				}
				else if(extension == ".exe"){
					if(Option == nullptr || Option->IsDisposed){
						FileVersionInfo^ info = FileVersionInfo::GetVersionInfo(file[0]);
						bool b2nd;

						IntPtr mp = Runtime::InteropServices::Marshal::StringToHGlobalAuto(file[0]);
						_tcscpy_s(MTOPTION.GAME_EXE, static_cast<PTCHAR>(mp.ToPointer()));
						Runtime::InteropServices::Marshal::FreeHGlobal(mp);

						// ini‚ÌƒpƒX‚ð’²‚×‚é
						TCHAR ini[_MAX_PATH], dir[_MAX_PATH], drive[_MAX_DRIVE];

						_tsplitpath_s(MTOPTION.GAME_EXE, drive, _MAX_DRIVE, dir, _MAX_DIR, NULL, 0, NULL, 0);

						if(info->FileDescription != "２Ｄ格闘ツクール９５"){
							b2nd = true;
							_stprintf_s(ini, _T("%s%sgame.ini"), drive, dir);
						}
						else{
							b2nd = false;
							_stprintf_s(ini, _T("%s%s２Ｄ格闘ツクール９５.ini"), drive, dir);
						}

						if(File::Exists(gcnew String(ini))){
							if(b2nd){
								MTOPTION.MAX_STAGE = GetPrivateProfileInt(_T("GamePlay"), _T("Editor.TestPlay.StageNb"), 0, ini) + 1;
								MTOPTION.ROUND     = GetPrivateProfileInt(_T("GamePlay"), _T("Editor.TestPlay.VSSinglePlay"), 0, ini);
								MTOPTION.TIMER     = GetPrivateProfileInt(_T("GamePlay"), _T("Editor.TestPlay.time"), 0, ini);
							}
							else{
								MTOPTION.MAX_STAGE = GetPrivateProfileInt(_T("ゲーム設定"), _T("Editer.TestPlay.BackGroundNb"), 0, ini) + 1;
								MTOPTION.ROUND     = 2;
								MTOPTION.TIMER     = GetPrivateProfileInt(_T("ゲーム設定"), _T("Editer.TestPlay.time"), 0, ini);
							}

							MTOPTION.STAGE_SELECT = MTOPTION.MAX_STAGE == 1 ? 1 : 0;
						}

						WriteMessage(String::Format("The game you are playing has been changed to \"{0}\".\n", Path::GetFileNameWithoutExtension(file[0])), SystemMessageColor);
					}
					else{
						Option->SetGameExePath(file[0]);
					}
				}
			}
		}

		// ƒvƒƒtƒ@ƒCƒ‹•ÏX
		System::Void toolStripDropDownItemProfile_Click(System::Object^ sender, System::EventArgs^ e) {
			if(((ToolStripDropDownItem^)sender)->Text == gcnew String(MTOPTION.PROFILE)){
				return;
			}
			String^ buf = ((ToolStripDropDownItem^)sender)->Text;

			IntPtr mp = Runtime::InteropServices::Marshal::StringToHGlobalAuto(buf);
			_tcscpy_s(MTOPTION.PROFILE, static_cast<PTCHAR>(mp.ToPointer()));
			Runtime::InteropServices::Marshal::FreeHGlobal(mp);

			toolStripDropDownButtonProfile->Text = buf;

			LoadMTOption();
		}
		System::Void toolStripMenuItemSeek_Click(System::Object^ sender, System::EventArgs^ e) {
			this->SeekToolStripMenuItem_Click(nullptr, nullptr);
		}
		// If checked, enables auto resting after a specified period of time.
		System::Void toolStripMenuItemAutoRestEnable_Click(System::Object^  sender, System::EventArgs^  e) {
			toolStripMenuItemAutoRestEnable->Checked ^= 1;
			MTOPTION.AUTO_REST = toolStripMenuItemAutoRestEnable->Checked;
			if(MTOPTION.AUTO_REST){
				if(UDP != nullptr && AutoRestThread == nullptr && MemberList[0]->STATE == MS_FREE){
					AutoRestThread = gcnew Thread(gcnew ThreadStart(this, &MainForm::RunAutoRest));
					AutoRestThread->Start();
				}
			}else{
				if(AutoRestThread != nullptr && AutoRestThread->IsAlive){
					AutoRestRanging = false;
					AutoRestThread->Abort();
					AutoRestThread = nullptr;
				}
			}
		}
		// Auto rest after 5 minutes.
		System::Void toolStripMenuItemAutoRestTime5_Click(System::Object^  sender, System::EventArgs^  e) {
			SetAutoRestTime(5);
			toolStripMenuItemAutoRestTime5->Checked = 1;
		}
		// Auto rest after 10 minutes.
		System::Void toolStripMenuItemAutoRestTime10_Click(System::Object^  sender, System::EventArgs^  e) {
			SetAutoRestTime(10);
			toolStripMenuItemAutoRestTime10->Checked = 1;
		}
		// Auto rest after 15 minutes.
		System::Void toolStripMenuItemAutoRestTime15_Click(System::Object^  sender, System::EventArgs^  e) {
			SetAutoRestTime(15);
			toolStripMenuItemAutoRestTime15->Checked = 1;
		}
		// Auto rest after 20 minutes.
		System::Void toolStripMenuItemAutoRestTime20_Click(System::Object^  sender, System::EventArgs^  e) {
			SetAutoRestTime(20);
			toolStripMenuItemAutoRestTime20->Checked = 1;
		}
		// Auto rest after 30 minutes.
		System::Void toolStripMenuItemAutoRestTime30_Click(System::Object^  sender, System::EventArgs^  e) {
			SetAutoRestTime(30);
			toolStripMenuItemAutoRestTime30->Checked = 1;
		}
		// Auto rest after 60 minutes.
		System::Void toolStripMenuItemAutoRestTime60_Click(System::Object^  sender, System::EventArgs^  e) {
			SetAutoRestTime(60);
			toolStripMenuItemAutoRestTime60->Checked = 1;
		}
		// Auto rest after 120 minutes.
		System::Void toolStripMenuItemAutoRestTime120_Click(System::Object^  sender, System::EventArgs^  e) {
			SetAutoRestTime(120);
			toolStripMenuItemAutoRestTime120->Checked = 1;
		}
		System::Void toolStripMenuItemAutoRestTime8h_Click(System::Object^  sender, System::EventArgs^  e) {
			SetAutoRestTime(480);
			toolStripMenuItemAutoRestTime8h->Checked = 1;
		 }
		System::Void toolStripMenuItem12h_Click(System::Object^  sender, System::EventArgs^  e) {
			SetAutoRestTime(720);
			toolStripMenuItem12h->Checked = 1;
		 }
		// Determines if the log text should be wrapped at the end of the window or not.·
		System::Void toolStripMenuItemWordWrap_Click(System::Object^ sender, System::EventArgs^  e) {
			ChangeLogWordWrap();
		}
		System::Void toolStripMenuItemDelay_Click(System::Object^  sender, System::EventArgs^  e) {
			 }
		// Writes the update log of the application to the chat log.
		System::Void whatsNewToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 WriteWhatsNew();
			 }

		// Toggles rest as soon as the server initialises or you join another server as a host/client.
		System::Void restOnconnectToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			restOnconnectToolStripMenuItem->Checked ^= 1;
			MTOPTION.REST_CONNECT = restOnconnectToolStripMenuItem->Checked;
		}

		// Below is code specifically for the custom context menu on the message box.
		System::Void contextMenuStripTextbox_Opening(System::Object^  sender, System::ComponentModel::CancelEventArgs^  e) {
			if (textBoxInput->SelectedText == ""){
				cutToolStripMenuItem->Enabled = false;
				toolStripMenuItemCopy->Enabled = false;
			}else{
				cutToolStripMenuItem->Enabled = true;
				toolStripMenuItemCopy->Enabled = true;
				return;
			}

			if (IsClipboardEmpty()){
				pasteToolStripMenuItem->Enabled = false;
			}else{
				pasteToolStripMenuItem->Enabled = true;
			}
		}
		System::Void cutToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			textBoxInput->Cut();
		 }
		System::Void toolStripMenuItemCopy_Click(System::Object^  sender, System::EventArgs^  e) {
			textBoxInput->Copy();
		 }
		
		System::Void pasteToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 textBoxInput->Paste();
		 }
		// Sends user to GitHub releases page so they can see if there's a new update.
		System::Void checkForUpdatesToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			Process::Start("https://github.com/windowslogic-productions/M0rningStar/releases");
		 }
		// Sends user to FM95/FM2K server invite link.
		System::Void dFighterMaker952ndDiscordServerToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			Process::Start("https://discord.gg/5W73Qe9ucp");
		 }
#pragma region System Tray
		// Everything under here is to do with the system tray menu.
		void SysTrayRestore(){
			try{
				this->Visible = true;
				this->WindowState = FormWindowState::Normal;
				notifyIconSysTray->Visible = true;
			}catch (Exception^ ex){
				MessageBox::Show(ex->Message);
			}
		}
		System::Void notifyIconSysTray_MouseDoubleClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
			SysTrayRestore();
		 }
		System::Void MainForm_Resize(System::Object^  sender, System::EventArgs^  e) {
			if (MTOPTION.SYS_TRAY == true){
				if (WindowState == FormWindowState::Minimized){
					this->Visible = false;
					notifyIconSysTray->Visible = true;
					notifyIconSysTray->ShowBalloonTip(1, "MorningStar - Notification", "MorningStar is now running in the background.", ToolTipIcon::Info);
					}
			}else{
				
			}
		 }
		System::Void restoreToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			SysTrayRestore();
		 }
		System::Void startGameToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			StartGame(RT_FREE);
		 }
		System::Void startGamenoReplayToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			StartGameNoReplay();
		 }
		System::Void reconnectToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			Reconnect();
		 }
		System::Void toggleRestModeToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 ToggleRest();
		 }
		System::Void toggleSeekModeToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			ChangeSeek();
		 }
		System::Void settingsToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			LoadSettings();
		 }
		System::Void exitToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 this->Close();
		 }
#pragma endregion
#pragma region Action Bar
		System::Void buttonRefresh_Click(System::Object^  sender, System::EventArgs^  e) {
			ReloadList();
		 }
		System::Void buttonReconnect_Click(System::Object^  sender, System::EventArgs^  e) {
			Reconnect();
		 }
		System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
			ToggleRest();
		 }
		System::Void buttonPlay_Click(System::Object^  sender, System::EventArgs^  e) {
			StartGame(RT_FREE);
		 }
		System::Void buttonSeek_Click(System::Object^  sender, System::EventArgs^  e) {
			ChangeSeek();
		 }
		System::Void buttonClear_Click(System::Object^  sender, System::EventArgs^  e) {
			ClearLog();
		 }
#pragma endregion
};
}
