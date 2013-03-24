//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Sockets.hpp>
#include <ScktComp.hpp>
#include <ExtCtrls.hpp>
#include <Dialogs.hpp>
#include <Grids.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
        TButton *Button1;
        TClientSocket *ClientSocket1;
        TLabel *Label1;
        TTimer *Timer1;
        TMemo *Memo1;
        TButton *Button2;
        TButton *Button3;
        TOpenDialog *OpenDialog1;
        TLabel *Label3;
        TLabel *Label2;
        void __fastcall Button1Click(TObject *Sender);
        void __fastcall ClientSocket1Connect(TObject *Sender,
          TCustomWinSocket *Socket);
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall ClientSocket1Disconnect(TObject *Sender,
          TCustomWinSocket *Socket);
        void __fastcall Button2Click(TObject *Sender);
        void __fastcall Timer1Timer(TObject *Sender);
        void __fastcall ClientSocket1Read(TObject *Sender,
          TCustomWinSocket *Socket);
        void __fastcall ClientSocket1Error(TObject *Sender,
          TCustomWinSocket *Socket, TErrorEvent ErrorEvent,
          int &ErrorCode);
        void __fastcall Button3Click(TObject *Sender);
private:
        unsigned char buffer[2000];
        unsigned char paketl[2];
        char ch[4];
        bool fl, flag;
        double d;
        int r;	// User declarations
public:		// User declarations
        __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
