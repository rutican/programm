VERSION 5.00
Begin VB.Form frmRubashka 
   BorderStyle     =   1  'Fixed Single
   Caption         =   "Выбор рубашки"
   ClientHeight    =   2835
   ClientLeft      =   9210
   ClientTop       =   600
   ClientWidth     =   3225
   Icon            =   "frmRubashka.frx":0000
   LinkTopic       =   "Form2"
   LockControls    =   -1  'True
   MaxButton       =   0   'False
   MinButton       =   0   'False
   ScaleHeight     =   2835
   ScaleWidth      =   3225
   StartUpPosition =   2  'CenterScreen
   Begin VB.CommandButton Command1 
      Caption         =   "OK"
      Height          =   375
      Left            =   600
      TabIndex        =   0
      Top             =   2280
      Width           =   2055
   End
   Begin VB.Image Image1 
      Height          =   1440
      Index           =   1
      Left            =   360
      Top             =   480
      Width           =   1065
   End
   Begin VB.Image Image1 
      Height          =   1440
      Index           =   0
      Left            =   1800
      Top             =   495
      Width           =   1065
   End
End
Attribute VB_Name = "frmRubashka"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Private Sub Command1_Click()
'меняю рубашки у карт
Dim nKarta As Karta

If Image1(0).BorderStyle = 1 Then
    Form1.Rubaska = True ' 101
    Form1.Image1(0).Picture = LoadResPicture(101, vbBitmap)
    Form1.Image2(0).Picture = LoadResPicture(101, vbBitmap)

    For Each nKarta In Form1.nKartKompa
    
        Form1.Image2(nKarta.NomImeg).Picture = LoadResPicture(101, vbBitmap)

    Next
    
Else
    Form1.Rubaska = False
    Form1.Image1(0).Picture = LoadResPicture(102, vbBitmap)
    Form1.Image2(0).Picture = LoadResPicture(102, vbBitmap)

     For Each nKarta In Form1.nKartKompa
      Form1.Image2(nKarta.NomImeg).Picture = LoadResPicture(102, vbBitmap)
    Next
End If

Unload frmRubashka

End Sub

Private Sub Form_Load()
Image1(0).Picture = LoadResPicture(101, vbResBitmap)
Image1(1).Picture = LoadResPicture(102, vbResBitmap)

If Form1.Rubaska = True Then
Image1(0).BorderStyle = 1
    Image1(1).BorderStyle = 0
Else
Image1(1).BorderStyle = 1
    Image1(0).BorderStyle = 0
End If

End Sub

Private Sub Image1_Click(Index As Integer)
Select Case Index

    Case Is = 0
    Image1(0).BorderStyle = 1
    Image1(1).BorderStyle = 0
    Form1.Rubaska = True ' 101
   SaveSetting "Durak", "Opcii", "Rubaska", True
    Case Is = 1
    Image1(1).BorderStyle = 1
    Image1(0).BorderStyle = 0
    Form1.Rubaska = False ' 102
    SaveSetting "Durak", "Opcii", "Rubaska", False

End Select



End Sub
