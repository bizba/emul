//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include "math.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------

void __fastcall TForm1::Button1Click(TObject *Sender)
{
  if (flag)
   {
      Button1->Caption="Disconnect";
      ClientSocket1->Open();
      flag=!flag;
    }
    else
     {
      Button1->Caption="Connect";
      ClientSocket1->Close();
      flag=!flag;
     }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::ClientSocket1Connect(TObject *Sender,
      TCustomWinSocket *Socket)
{
  Label1->Caption="Есть соединение" ;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormCreate(TObject *Sender)
{
  int i;
  fl=false;
  flag=true;

  d=0;
  for (i=0;i<2000;i++) buffer[i]=1;

}
//---------------------------------------------------------------------------
void __fastcall TForm1::ClientSocket1Disconnect(TObject *Sender,
      TCustomWinSocket *Socket)
{
  Label1->Caption="no connect" ;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button2Click(TObject *Sender)
{

 // отправляем длину пакета

  ClientSocket1->Socket->SendBuf(paketl,3);

}
//---------------------------------------------------------------------------
void __fastcall TForm1::Timer1Timer(TObject *Sender)
{
  float f;

  f=100*sin(d)+200;
  Label3->Caption=FloatToStr(f);
  d=d+0.01;
  if (d>(2*M_PI)) d=0;
  memcpy(&ch,&f,4);

}
//---------------------------------------------------------------------------
void __fastcall TForm1::ClientSocket1Read(TObject *Sender,
      TCustomWinSocket *Socket)
{
   //bool tr;
   int i,v;

   //tr=true;

   

     if (ClientSocket1->Active == true)
      if (Socket->Connected == true)
        {
                Memo1->Lines->Add( AnsiString("(Server) ") +Socket->ReceiveText());

                        // формируем пакет

                if(fl)
                 {
                       // отправляем длину пакета

                        ClientSocket1->Socket->SendBuf(paketl,3);
                        fl=false;
                  }
                 else
                  {
                      fl=true;
        // отправляем пакет

                        v=16;
                         for(i=0;i<paketl[1]+(256*paketl[0]);i++)
                                {
        // sin
                                  buffer[v]=ch[1];
                                  buffer[v+1]=ch[0];
                                  buffer[v+2]=1+ch[3];
                                  buffer[v+3]=ch[2];
                                  v=v+22;

                                }

                   ClientSocket1->Socket->SendBuf(buffer,22*(paketl[1]+(256*paketl[0]))); // послать длину пакета

                 }
      }
//   Socket->SendBuf(buffer,sizeof(buffer));
//  ShowMessage("ON Read");
}

//---------------------------------------------------------------------------
void __fastcall TForm1::ClientSocket1Error(TObject *Sender,
      TCustomWinSocket *Socket, TErrorEvent ErrorEvent, int &ErrorCode)
{
   ShowMessage("err");
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button3Click(TObject *Sender)
{
  int iFileHandle;
  int j;
  int l;

  int iFileLength;
  int iBytesRead;
  char *pszBuffer;
  if (OpenDialog1->Execute())
  {
    try
    {
      iFileHandle = FileOpen(OpenDialog1->FileName, fmOpenRead);
      iFileLength = FileSeek(iFileHandle,0,2);
      FileSeek(iFileHandle,0,0);
      pszBuffer = new char[iFileLength+1];
      iBytesRead = FileRead(iFileHandle, pszBuffer, iFileLength);
      FileClose(iFileHandle);

      j=0;
      l=0;
      paketl[0]=0;
      paketl[1]=0;

      for (int i=0;i<iBytesRead;i++)
      {
        if((int)pszBuffer[i]==13 | (int)pszBuffer[i]==10)
                {
                  i=i++;
                  if (l!=0)
                        {

                              if(paketl[1]+1>255)
                                {
                                 paketl[1]=0;
                                 paketl[0]=paketl[0]+1;
                                }
                               else paketl[1]=paketl[1]+1;

                              buffer[j+21-l]=l; // 22...
                              j=j+22-l;
                              l=0;
                        }

                }
         else
          {
             buffer[j]=pszBuffer[i];
             l++;
             j++;
           }

      }
      delete [] pszBuffer;
    }
    catch(...)
    {
      Application->MessageBox("Can't perform one of the following file operations: Open, Seek, Read, Close.", "File Error", IDOK);
    }
  }
 //paketl[2]=0;
}
//---------------------------------------------------------------------------

