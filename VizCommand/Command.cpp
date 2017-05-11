// 独自のヘッダ
#include "Command.h"	// コマンドクラス

// コマンドのセットSet.
BOOL CCommand::Set(tstring tstrCommandString){

	// 変数の宣言
	tstringstream tstrsrStream;	// 文字列ストリーム
	tstring token;	// トークン

	// 文字列ストリームを受け取る.
	tstrsrStream << tstrCommandString;

	// tstrsrStreamがEOFになるまでtokenをpush.
	while (!tstrsrStream.eof()) {
		tstring tmp;
		tstrsrStream >> tmp;
		if (tmp.size() > 0) {	// 最後の文字が空白類の連続の場合, EOFにならないのでこうしている.
			token = tmp;
			m_vectstrCommandToken.push_back(token);
		}
	}

	// 0番目をメインのコマンド名にする.
	if (m_vectstrCommandToken.size() > 0) {
		m_tstrCommandName = m_vectstrCommandToken[0];
	}

	// TRUEを返す.
	return TRUE;	// TRUE

}

void CCommand::Clear(){

	// クリア
	m_tstrCommandString.clear();
	m_vectstrCommandToken.clear();
	m_tstrCommandName.clear();

}

// コマンド名の取得GetCommandName.
const tstring CCommand::GetCommandName(){

	// コマンド名を返す.
	return m_tstrCommandName;

}

// パラメータの取得GetParam.
const tstring CCommand::GetParam(int index){

	// index番目のパラメータを返す.
	if (index < m_vectstrCommandToken.size()) {	// 引数のサイズより小さい場合.
		return m_vectstrCommandToken[index];	// index番目を返す.
	}
	else {
		return _T("");	// 範囲外なので空文字を返す。
	}

}
