#include "GameEngine.h"
#include "GameObject.h"
#include<windows.h>


int WINAPI WinMain( HINSTANCE hInstance, HINSTANCE hPrevInstance,
             LPSTR lpCmdLine, int nCmdShow )
{
	GameObjectPtr tmp = sGame->CreateGameObject();
	//tmp->GetComponent<SpriteRenderer, SpriteRendererPtr>();

 //   int GHandle ;
	//ChangeWindowMode(TRUE);
 //   if( DxLib_Init() == -1 )        // �c�w���C�u��������������
 //   {
 //        return -1;        // �G���[���N�����璼���ɏI��
 //   }

 //   // test1.bmp�̓ǂݍ���
 //   GHandle = LoadGraph( "Resources/test1.bmp" ) ;

 //   // �ǂ݂��񂾃O���t�B�b�N����ʍ���ɕ`��
 //   DrawGraph( 0 , 0 , GHandle , TRUE ) ;

 //   WaitKey() ;        // ���ʂ����邽�߂ɃL�[�҂�(�wWaitKey�x���g�p)

 //   DxLib_End() ;        // �c�w���C�u�����g�p�̏I������

    return 0 ;        // �\�t�g�̏I��
}