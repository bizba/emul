object Form1: TForm1
  Left = 195
  Top = 107
  Width = 210
  Height = 504
  BorderIcons = [biSystemMenu]
  Caption = 'CVT'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 16
    Top = 48
    Width = 82
    Height = 13
    Caption = #1053#1077#1090' '#1089#1086#1077#1076#1080#1085#1077#1085#1080#1103
  end
  object Label3: TLabel
    Left = 80
    Top = 120
    Width = 3
    Height = 13
    Caption = '!'
  end
  object Label2: TLabel
    Left = 16
    Top = 120
    Width = 51
    Height = 13
    Caption = #1047#1085#1072#1095#1077#1085#1080#1077':'
  end
  object Button1: TButton
    Left = 8
    Top = 72
    Width = 75
    Height = 25
    Caption = 'Connect'
    TabOrder = 0
    OnClick = Button1Click
  end
  object Memo1: TMemo
    Left = 8
    Top = 144
    Width = 185
    Height = 281
    ScrollBars = ssVertical
    TabOrder = 1
  end
  object Button2: TButton
    Left = 88
    Top = 72
    Width = 75
    Height = 25
    Caption = 'Send'
    TabOrder = 2
    OnClick = Button2Click
  end
  object Button3: TButton
    Left = 8
    Top = 8
    Width = 75
    Height = 25
    Caption = 'File'
    TabOrder = 3
    OnClick = Button3Click
  end
  object ClientSocket1: TClientSocket
    Active = False
    ClientType = ctNonBlocking
    Host = '192.168.129.190'
    Port = 13344
    OnConnect = ClientSocket1Connect
    OnDisconnect = ClientSocket1Disconnect
    OnRead = ClientSocket1Read
    OnError = ClientSocket1Error
    Left = 40
    Top = 432
  end
  object Timer1: TTimer
    Interval = 100
    OnTimer = Timer1Timer
    Left = 8
    Top = 432
  end
  object OpenDialog1: TOpenDialog
    Left = 72
    Top = 432
  end
end
