// 二重インクルード防止
#pragma once	// #pragma onceで二重インクルード防止.

// 既定のヘッダ
#include <string>			// std::string
#include <vector>			// std::vector
#include <sstream>			// std::stringstream
#include <windows.h>		// 標準WindowsAPI
#include <tchar.h>			// TCHAR型

// マクロの定義
// UNICODE切り替え
#ifdef UNICODE
#define tstring std::wstring
#define tstringstream std::wstringstream
#else
#define tstring std::string
#define tstringstream std::stringstream
#endif

// コマンドクラスCCommand
class CCommand {

	// privateメンバ
	private:

		// privateメンバ変数
		tstring m_tstrCommandString;	// コマンド文字列tstring型m_tstrCommandString.
		std::vector<tstring> m_vectstrCommandToken;	// コマンド文字列のトークンリストstd::vector<tstring>型m_vectstrCommandToken.
		tstring m_tstrCommandName;	// コマンド名tstring型m_tstrCommandName.

	// publicメンバ
	public:

		// publicメンバ関数
		BOOL Set(tstring tstrCommandString);	// コマンドのセットSet.
		void Clear();	// コマンドのクリアClear.
		const tstring GetCommandName();	// コマンド名の取得GetCommandName.
		const tstring GetParam(int index);	// パラメータの取得GetParam.

};