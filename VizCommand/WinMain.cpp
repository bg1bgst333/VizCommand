// ヘッダのインクルード
// 既定のヘッダ
#include <windows.h>	// 標準WindowsAPI
#include <tchar.h>		// TCHAR型

// 関数のプロトタイプ宣言
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);	// 独自のウィンドウプロシージャWindowProc.

// _tWinMain関数
int WINAPI _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nShowCmd) {

	// 変数の宣言
	HWND hWnd;		// HWND型ウィンドウハンドルhWnd
	MSG msg;		// MSG型ウィンドウメッセージ構造体msg
	WNDCLASS wc;	// WNDCLASS型ウィンドウクラス構造体wc

	// ウィンドウクラスの設定
	wc.lpszClassName = _T("VizCommand_MainWindow");			// 独自に定義したウィンドウクラス"VizCommand_MainWindow".
	wc.style = CS_HREDRAW | CS_VREDRAW;						// とりあえずCS_HREDRAW | CS_VREDRAW.
	wc.lpfnWndProc = WindowProc;							// 独自に定義したウィンドウプロシージャWindowProc.
	wc.hInstance = hInstance;								// WinMainの引数のインスタンスハンドルhInstanceを指定.
	wc.hIcon = LoadIcon(hInstance, IDI_APPLICATION);		// アプリケーション既定アイコンIDI_APPLICATION.
	wc.hCursor = LoadCursor(hInstance, IDC_ARROW);			// システム既定の矢印カーソルIDC_ARROW.
	wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);	// 背景は白(WHITE_BRUSH).
	wc.lpszMenuName = NULL;									// とりあえずNULL.
	wc.cbClsExtra = 0;										// とりあえず0でいい.
	wc.cbWndExtra = 0;										// とりあえず0でいい.

	// ウィンドウクラスの登録
	if (!RegisterClass(&wc)) {	// RegisterClassにwcをセットして登録.

		// エラー処理
		MessageBox(NULL, _T("ウィンドウクラスの登録に失敗しました."), _T("VizCommand"), MB_OK | MB_ICONHAND);	// MessageBoxで"ウィンドウクラスの登録に失敗しました!"と表示.
		return -1;	// 異常終了(-1)を返す.

	}

	// ウィンドウクラスの作成
	hWnd = CreateWindow(wc.lpszClassName, _T("VizCommand"), WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL, NULL, hInstance, NULL);	// CreateWindowで"VizCommand_MainWindow"ウィンドウクラスのウィンドウ"VizCommand"を作成.
	if (hWnd == NULL) {

		// エラー処理
		MessageBox(NULL, _T("ウィンドウの作成に失敗しました!"), _T("VizCommand"), MB_OK | MB_ICONHAND);	// MessageBoxで"ウィンドウの作成に失敗しました!"と表示.
		return -2;	// 異常終了(-2)を返す.

	}

	// ウィンドウの表示
	ShowWindow(hWnd, SW_SHOW);	// ShowWindowでhWndを表示.

	// メッセージループ
	while (GetMessage(&msg, NULL, 0, 0) > 0) {	// GetMessageでメッセージ取得.

		// ウィンドウメッセージの送出
		DispatchMessage(&msg);	// DispatchMessageでウィンドウプロシージャに送出.
		TranslateMessage(&msg);	// TranslateMessageで仮想キーメッセージを文字へ変換.

	}

	// プログラムの終了
	return (int)msg.wParam;	// 終了コードとしてmsg.wParamを返す.

}

// ウィンドウプロシージャWindowProc関数
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {

	// ウィンドウメッセージ処理
	switch (uMsg) {

		// ウィンドウの作成が開始された時.
		case WM_CREATE:

			// WM_CREATEブロック
			{

				// ウィンドウ作成成功
				return 0;	// 成功なら0を返す.

			}

			// 既定の処理へ向かう.
			break;	// 抜けてDefWindowProcに向かう.

		// ウィンドウが破棄された時.
		case WM_DESTROY:

			// WM_DESTROYブロック
			{

				// メッセージループ終了.
				PostQuitMessage(0);	// PostQuitMessageでメッセージループを抜けさせる.

			}

			// 既定の処理へ向かう.
			break;	// 抜けてDefWindowProcに向かう.

		// それ以外の時.
		default:

			// 既定の処理へ向かう.
			break;	// 抜けてDefWindowProcに向かう.

	}

	// 既定の処理
	return DefWindowProc(hwnd, uMsg, wParam, lParam);	// DefWindowProcに任せる.

}