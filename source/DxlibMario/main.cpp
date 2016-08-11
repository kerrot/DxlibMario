#include "DxLib.h"

int WINAPI WinMain( HINSTANCE hInstance, HINSTANCE hPrevInstance,
             LPSTR lpCmdLine, int nCmdShow )
{
    int GHandle ;
	ChangeWindowMode(TRUE);
    if( DxLib_Init() == -1 )        // ＤＸライブラリ初期化処理
    {
         return -1;        // エラーが起きたら直ちに終了
    }

    // test1.bmpの読み込み
    GHandle = LoadGraph( "Resources/test1.bmp" ) ;

    // 読みこんだグラフィックを画面左上に描画
    DrawGraph( 0 , 0 , GHandle , TRUE ) ;

    WaitKey() ;        // 結果を見るためにキー待ち(『WaitKey』を使用)

    DxLib_End() ;        // ＤＸライブラリ使用の終了処理

    return 0 ;        // ソフトの終了
}