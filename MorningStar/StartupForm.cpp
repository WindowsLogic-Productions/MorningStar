#include "stdafx.h"
#include "Mainform.h"

using namespace LilithPort;

bool StartupForm::CheckValidate() {
	// 入力チェック
	IntPtr mp;
	TCHAR p1[MAX_ARRAY];
	TCHAR *p2;
	if(radioButtonServer->Checked){
		MTOPTION.CONNECTION_TYPE = CT_SERVER;

		// サーバ名チェック
		if(textBoxServerName->Text->Length == 0){
			MessageBox::Show("Please enter the server name.\n\nTo start in Server mode, you must enter a server name.", "Server Mode Error", MessageBoxButtons::OK, MessageBoxIcon::Exclamation);
			return false;
		}
		mp = Runtime::InteropServices::Marshal::StringToHGlobalAuto(textBoxServerName->Text);
		_tcscpy_s(p1, static_cast<PTCHAR>(mp.ToPointer()));
		Runtime::InteropServices::Marshal::FreeHGlobal(mp);
		p2 = _tcschr(p1, _T(','));
		if (p2 != NULL){
			MessageBox::Show("The server name contains an invalid character (,).\nPlease check the server name.", "Server Mode Error", MessageBoxButtons::OK, MessageBoxIcon::Exclamation);
			return false;
		}
	}
	else if(radioButtonHost->Checked){
		MTOPTION.CONNECTION_TYPE = CT_HOST;
	}
	else if(radioButtonClient->Checked){
		MTOPTION.CONNECTION_TYPE = CT_CLIENT;
	}
	else{
		MTOPTION.CONNECTION_TYPE = CT_FREE;
	}
	
	// サーバ名
	if(MTOPTION.CONNECTION_TYPE == CT_SERVER){
		mp = Runtime::InteropServices::Marshal::StringToHGlobalAuto(textBoxServerName->Text);
		_tcscpy_s(MTOPTION.SERVER_NAME, static_cast<PTCHAR>(mp.ToPointer()));
		Runtime::InteropServices::Marshal::FreeHGlobal(mp);
	}

	// アドレス入力チェック
	if(MTOPTION.CONNECTION_TYPE == CT_HOST || MTOPTION.CONNECTION_TYPE == CT_CLIENT) {
		if(textBoxIP->Text->Length == 0){
			MessageBox::Show("Please enter the destination address. \n\nTo start in HOST, CLIENT mode,\n you must enter the destination address.", "HOST, CLIENT mode error", MessageBoxButtons::OK, MessageBoxIcon::Exclamation);
			return false;
		}
		mp = Runtime::InteropServices::Marshal::StringToHGlobalAuto(textBoxIP->Text);
		_tcscpy_s(p1, static_cast<PTCHAR>(mp.ToPointer()));
		p2 = _tcschr(p1, _T(','));
		if (p2 != NULL){
			MessageBox::Show("The destination address contains an invalid character (,). \nPlease check the destination address.", "HOST, CLIENT mode error", MessageBoxButtons::OK, MessageBoxIcon::Exclamation);
			return false;
		}

		// 接続アドレス
		mp = Runtime::InteropServices::Marshal::StringToHGlobalAuto(textBoxIP->Text);
		_tcscpy_s(MTOPTION.CONNECTION_IP, static_cast<PTCHAR>(mp.ToPointer()));
		Runtime::InteropServices::Marshal::FreeHGlobal(mp);

	}

	// 名前チェック
	if(textBoxName->Text->Length == 0){
		textBoxName->Text = gcnew String(MTOPTION.NAME);

		if(textBoxName->Text->Length == 0){
			textBoxName->Text = gcnew String("");
		}
	}

	mp = Runtime::InteropServices::Marshal::StringToHGlobalAuto(textBoxName->Text);
	_tcscpy_s(MTOPTION.NAME, static_cast<PTCHAR>(mp.ToPointer()));
	Runtime::InteropServices::Marshal::FreeHGlobal(mp);

	MTOPTION.OPEN_PORT      = (UINT)numericUpDownOpenPort->Value;

	mp = Runtime::InteropServices::Marshal::StringToHGlobalAuto(textBoxComment->Text);
	_tcscpy_s(MTOPTION.COMMENT, static_cast<PTCHAR>(mp.ToPointer()));
	Runtime::InteropServices::Marshal::FreeHGlobal(mp);

	mp = Runtime::InteropServices::Marshal::StringToHGlobalAuto(textBoxLooking->Text);
	_tcscpy_s(MTOPTION.LOOKING, static_cast<PTCHAR>(mp.ToPointer()));
	Runtime::InteropServices::Marshal::FreeHGlobal(mp);

	mp = Runtime::InteropServices::Marshal::StringToHGlobalAuto(textBoxAvoiding->Text);
	_tcscpy_s(MTOPTION.AVOIDING, static_cast<PTCHAR>(mp.ToPointer()));
	Runtime::InteropServices::Marshal::FreeHGlobal(mp);

	mp = Runtime::InteropServices::Marshal::StringToHGlobalAuto(comboBoxRegion->Text);
	_tcscpy_s(MTOPTION.REGION, static_cast<PTCHAR>(mp.ToPointer()));
	Runtime::InteropServices::Marshal::FreeHGlobal(mp);

	mp = Runtime::InteropServices::Marshal::StringToHGlobalAuto(textBoxGG->Text);
	_tcscpy_s(MTOPTION.GG, static_cast<PTCHAR>(mp.ToPointer()));
	Runtime::InteropServices::Marshal::FreeHGlobal(mp);

	mp = Runtime::InteropServices::Marshal::StringToHGlobalAuto(textBoxWelcome->Text);
	_tcscpy_s(MTOPTION.WELCOME, static_cast<PTCHAR>(mp.ToPointer()));
	Runtime::InteropServices::Marshal::FreeHGlobal(mp);

	return true;
}