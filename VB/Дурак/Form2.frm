VERSION 5.00
Begin VB.Form Form2 
   Caption         =   "Карты компа"
   ClientHeight    =   6210
   ClientLeft      =   8790
   ClientTop       =   1050
   ClientWidth     =   3570
   LinkTopic       =   "Form2"
   ScaleHeight     =   6210
   ScaleWidth      =   3570
   Begin VB.CommandButton Command5 
      Caption         =   "Очистить"
      Height          =   675
      Left            =   195
      TabIndex        =   6
      Top             =   4815
      Width           =   3045
   End
   Begin VB.CommandButton Command4 
      Caption         =   "Отладка"
      Height          =   525
      Left            =   240
      TabIndex        =   5
      Top             =   3840
      Width           =   3000
   End
   Begin VB.CommandButton Command3 
      Caption         =   "Уничтожить колоду"
      Height          =   540
      Left            =   240
      TabIndex        =   4
      Top             =   3015
      Width           =   3030
   End
   Begin VB.CommandButton Command2 
      Caption         =   "Колода"
      Height          =   420
      Left            =   2325
      TabIndex        =   3
      Top             =   2400
      Width           =   1155
   End
   Begin VB.ListBox List2 
      Height          =   450
      Left            =   240
      TabIndex        =   2
      Top             =   2370
      Width           =   1830
   End
   Begin VB.CommandButton Command1 
      Caption         =   "Обновить"
      Height          =   495
      Left            =   2400
      TabIndex        =   1
      Top             =   360
      Width           =   1065
   End
   Begin VB.ListBox List1 
      BeginProperty Font 
         Name            =   "MS Sans Serif"
         Size            =   8.25
         Charset         =   204
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   1815
      Left            =   255
      TabIndex        =   0
      Top             =   300
      Width           =   1860
   End
End
Attribute VB_Name = "Form2"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Option Explicit

Private Sub Command1_Click()
Dim nKarta As Karta
List1.Clear
For Each nKarta In Form1.nKartKompa
List1.AddItem nKarta.Znachenie & nKarta.MAST
Next
End Sub

Private Sub Command2_Click()
List2.Clear
List2.AddItem Form1.nKoloda.COUNT
End Sub

Private Sub Command3_Click()
Set Form1.nKoloda = Nothing
End Sub

Private Sub Command4_Click() 'отладка
Form1.CheiXod = True
Form1.Label1.Visible = True
  
'Command1.Caption = ""

Form1.IgraPodbrocIgroka = True 'игра а не подброс


Form1.nKoloda.ColodaDlyaOtladki
Form1.nKoloda.OpredKozirya
Form1.nKoloda.PokazatKolodu
Form1.nKoloda.PokazatKozir


'MsgBox KOZIR
Form1.nKartKompa.RazdatKartiCompu

Form1.nKartKompa.PokazatKartiKompa

Form1.nKartIgroka.RazdatKartiIgrocu
Form1.nKartIgroka.RaspologKartIgroka
Form1.nKartIgroka.PokazatKartiIgroka

End Sub

Private Sub Command5_Click() 'очистить
Dim i As Integer

For i = 0 To 5
    Form1.Image3(i).Visible = False
    Form1.Image4(i).Visible = False
Next i

Form1.Image6.Visible = True
          Form1.Command1.Visible = True
Form1.nKartIgroka.UnichtogitKartiIgroka
Form1.nKartKompa.UnishtogitKartiKompa


Form1.nBita.OchistitBito
Form1.nKoloda.UnichtogitKolodu

Set Form1.nKarta1K = Nothing
Set Form1.nKartIgroka = Nothing
Set Form1.nKoloda = Nothing

Set Form1.nKarta1I = Nothing
Set Form1.nKartKompa = Nothing
Set Form1.nBita = Nothing

End Sub
