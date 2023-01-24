VERSION 5.00
Begin VB.Form Form1 
   BackColor       =   &H00008000&
   BorderStyle     =   1  'Fixed Single
   Caption         =   " Дурак"
   ClientHeight    =   6060
   ClientLeft      =   45
   ClientTop       =   1980
   ClientWidth     =   9015
   Icon            =   "Form1.frx":0000
   LinkTopic       =   "Form1"
   LockControls    =   -1  'True
   MaxButton       =   0   'False
   ScaleHeight     =   6060
   ScaleWidth      =   9015
   StartUpPosition =   2  'CenterScreen
   Begin VB.CommandButton Command1 
      Height          =   465
      Left            =   8025
      TabIndex        =   0
      Top             =   3690
      Visible         =   0   'False
      Width           =   810
   End
   Begin VB.Label Label1 
      BackStyle       =   0  'Transparent
      Caption         =   "Ваш ход >>"
      BeginProperty Font 
         Name            =   "MS Sans Serif"
         Size            =   8.25
         Charset         =   204
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      ForeColor       =   &H00C00000&
      Height          =   270
      Left            =   60
      TabIndex        =   1
      Top             =   5040
      Visible         =   0   'False
      Width           =   1050
   End
   Begin VB.Image Image4 
      Height          =   975
      Index           =   5
      Left            =   6540
      Top             =   1380
      Width           =   690
   End
   Begin VB.Image Image4 
      Height          =   975
      Index           =   4
      Left            =   5580
      Top             =   1350
      Width           =   690
   End
   Begin VB.Image Image4 
      Height          =   975
      Index           =   3
      Left            =   4695
      Top             =   1290
      Width           =   690
   End
   Begin VB.Image Image4 
      Height          =   975
      Index           =   2
      Left            =   3735
      Top             =   1365
      Width           =   690
   End
   Begin VB.Image Image4 
      Height          =   975
      Index           =   1
      Left            =   2910
      Top             =   1410
      Width           =   690
   End
   Begin VB.Image Image4 
      Height          =   975
      Index           =   0
      Left            =   2040
      Top             =   1440
      Width           =   690
   End
   Begin VB.Image Image3 
      Height          =   1035
      Index           =   5
      Left            =   3975
      Top             =   2625
      Width           =   660
   End
   Begin VB.Image Image3 
      Height          =   1035
      Index           =   4
      Left            =   3600
      Top             =   2760
      Width           =   660
   End
   Begin VB.Image Image3 
      Height          =   1035
      Index           =   3
      Left            =   3135
      Top             =   3090
      Width           =   660
   End
   Begin VB.Image Image3 
      Height          =   1035
      Index           =   2
      Left            =   2790
      Top             =   3270
      Width           =   660
   End
   Begin VB.Image Image3 
      Height          =   1035
      Index           =   1
      Left            =   2280
      Top             =   2985
      Width           =   660
   End
   Begin VB.Image Image3 
      Height          =   1035
      Index           =   0
      Left            =   1860
      Top             =   3120
      Width           =   660
   End
   Begin VB.Image Image1 
      Height          =   1500
      Index           =   1
      Left            =   1305
      Top             =   90
      Width           =   1095
   End
   Begin VB.Image Image2 
      Height          =   1515
      Index           =   1
      Left            =   7830
      Top             =   4335
      Width           =   1125
   End
   Begin VB.Line Line2 
      Visible         =   0   'False
      X1              =   285
      X2              =   8265
      Y1              =   4185
      Y2              =   4185
   End
   Begin VB.Line Line1 
      Visible         =   0   'False
      X1              =   150
      X2              =   8175
      Y1              =   1710
      Y2              =   1710
   End
   Begin VB.Image Image2 
      Height          =   1515
      Index           =   0
      Left            =   7815
      Top             =   2025
      Visible         =   0   'False
      Width           =   1125
   End
   Begin VB.Image Image1 
      Height          =   1500
      Index           =   0
      Left            =   120
      Top             =   2025
      Width           =   1095
   End
   Begin VB.Image Image5 
      Height          =   1245
      Left            =   105
      Top             =   2715
      Width           =   1125
   End
   Begin VB.Image Image6 
      Height          =   480
      Left            =   435
      Picture         =   "Form1.frx":0442
      Top             =   2640
      Visible         =   0   'False
      Width           =   480
   End
   Begin VB.Shape Shape1 
      BorderWidth     =   4
      Height          =   870
      Left            =   315
      Top             =   2430
      Visible         =   0   'False
      Width           =   735
   End
   Begin VB.Menu Igra 
      Caption         =   "Игра"
      Begin VB.Menu New 
         Caption         =   "&Новая"
      End
      Begin VB.Menu рго 
         Caption         =   "-"
      End
      Begin VB.Menu quit 
         Caption         =   "Выход"
      End
   End
   Begin VB.Menu Opcii 
      Caption         =   "Опции"
      Begin VB.Menu Rubashka 
         Caption         =   "Рубашка"
      End
      Begin VB.Menu RaspKart 
         Caption         =   "Расположение карт"
         WindowList      =   -1  'True
         Begin VB.Menu PoZnach 
            Caption         =   "По значениям"
            Checked         =   -1  'True
         End
         Begin VB.Menu PoMast 
            Caption         =   "По мастям"
            Checked         =   -1  'True
         End
      End
      Begin VB.Menu Inteval 
         Caption         =   "Скорость раздачи"
         Begin VB.Menu nol 
            Caption         =   "0"
            Checked         =   -1  'True
         End
         Begin VB.Menu odin 
            Caption         =   "1"
         End
         Begin VB.Menu dva 
            Caption         =   "2"
         End
      End
   End
   Begin VB.Menu help 
      Caption         =   "Помощь"
   End
   Begin VB.Menu Oproge 
      Caption         =   ".. О программе"
   End
End
Attribute VB_Name = "Form1"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Option Explicit

Public nKoloda     As New Koloda
Public nKartIgroka As New KartIgroka
Public nKartKompa  As New KartKompa
Public nBita       As New Bita

Public nKarta1I    As New Collection
Public nKarta1K    As New Collection
Public IgraPodbrocIgroka As Boolean  ' 1- игра, 0 - подброс

Public KOZIR As String
Public KtoXoditPervim As Boolean ' 1- ход игрока, 0- ход компа
Public CheiXod As Boolean ' 1- ход игрока, 0- ход компа
Public Rubaska As Boolean '1-101, 0-102

Public ImyaIgroca As String
Public KolIgrIgroka As Integer
Public KolIgrViigranIgrokom As Integer
Public IntervalRazdachiKart As Double


Public Sub NovayaIgra()
Dim i As Integer

For i = 0 To 5
    Image3(i).Visible = False
    Image4(i).Visible = False
Next i

Image6.Visible = True
            Command1.Visible = True
nKartIgroka.UnichtogitKartiIgroka
nKartKompa.UnishtogitKartiKompa


nBita.OchistitBito
nKoloda.UnichtogitKolodu

Set nKarta1K = Nothing
Set nKartIgroka = Nothing
Set nKoloda = Nothing

Set nKarta1I = Nothing
Set nKartKompa = Nothing
Set nBita = Nothing


nKoloda.PeretasovkaKolodi
nKoloda.OpredKozirya
nKoloda.PokazatKolodu
nKoloda.PokazatKozir



nKartIgroka.RazdatKartiIgrocu
nKartIgroka.RaspologKartIgroka
nKartIgroka.PokazatKartiIgroka

nKartKompa.RazdatKartiCompu
nKartKompa.PokazatKartiKompa

If CheiXod = False Then
    nKartKompa.XodKompa
    Command1.Caption = "Снять"
    Label1.Visible = True
Else
    Command1.Caption = ""
    Label1.Visible = True
End If
Shape1.Visible = True

End Sub

Private Sub Command1_Click()
Dim i As Integer

If Command1.Caption = "Бито" Then
    nBita.SozdatBito
    nKartIgroka.UnichtogitKartiIgroka
    nKartIgroka.RazdatKartiIgrocu
    nKartIgroka.RaspologKartIgroka
    nKartIgroka.PokazatKartiIgroka
    
    nKartKompa.UnishtogitKartiKompa
    nKartKompa.RazdatKartiCompu
    nKartKompa.PokazatKartiKompa
    
    If nKoloda.ConchilasKoloda Then
          nKoloda.UnichtogitKolodu
    End If
    
    CheiXod = False
    nKartKompa.XodKompa
'<<<<<<<<<< Проверить выигрышь компа  >>>>>>>>>>>
    If nKartKompa.ViigralKomp Then
        CheiXod = False
        Call BudetIgra
        Exit Sub
  End If

    
ElseIf Command1.Caption = "Снять" Then
    '//////////komp podkidivaet
    
    If Form1.nKartKompa.KompPodkidivaet Then
        Form1.nKartKompa.XodKompa
        'проверка на выигрыш
            If nKartKompa.ViigralKomp = True Then
                CheiXod = False
                Call BudetIgra
                Exit Sub
            End If
        
        Command1.Caption = "Снять"
        Exit Sub
    End If
    '//////////
    nKartIgroka.UnichtogitKartiIgroka
   
    
    nKartIgroka.IgrokSnyal
    nKartIgroka.RaspologKartIgroka
    nKartIgroka.PokazatKartiIgroka
        
    nKartKompa.UnishtogitKartiKompa
    nKartKompa.RazdatKartiCompu
    nKartKompa.PokazatKartiKompa
    
    If nKoloda.ConchilasKoloda Then
          nKoloda.UnichtogitKolodu
    End If
  
     nKartKompa.XodKompa
     If nKartKompa.ViigralKomp = True Then
            CheiXod = False
            Call BudetIgra
            Exit Sub
     End If
  
 
Else 'кнопка без названья
    Beep
End If

End Sub



Private Sub Form_Load()
Dim RaspolKart As Boolean   '
'/////////////////////////отладка///////]

'Form2.Show
'//////////////////////del/////
'Dim b As Boolean
'/////////////////////Делаю установки в реестре если первый запуск программы
If GetSetting("Durak", "Opcii", "Rubaska") = "" Then
Rubaska = True
Else
Rubaska = CBool(GetSetting("Durak", "Opcii", "Rubaska"))
End If

If GetSetting("Durak", "Opcii", "RaspolKart") = "" Then
RaspolKart = True
Else
RaspolKart = CBool(GetSetting("Durak", "Opcii", "RaspolKart"))
End If


'SaveSetting "Durak", "Opcii", "Rubaska", True
'SaveSetting "Durak", "Opcii", "RaspolKart", True ' тоPoMast.Checked = True

'////////////////
'сохранить установки в реестре и здесь их считать для проверки
If RaspolKart Then
    PoMast.Checked = True 'False
    PoZnach.Checked = False ' True
Else
PoMast.Checked = False 'False
    PoZnach.Checked = True ' True
End If
'|||||||||||||||||||
IgraPodbrocIgroka = True
CheiXod = True
'NovayaIgra
'||||||||||||||||||||||
'Тоже самое для рубашки
'Тоже самое для определения хода,пока ходит игрок
'CheiXod = True
'Label1.Visible = True
'
'Command1.Caption = ""
'
'IgraPodbrocIgroka = True 'игра а не подброс
'
'
'nKoloda.PeretasovkaKolodi
'nKoloda.OpredKozirya
'nKoloda.PokazatKolodu
'nKoloda.PokazatKozir
'
'
'MsgBox KOZIR
'nKartIgroka.RazdatKartiIgrocu
'nKartIgroka.RaspologKartIgroka
'nKartIgroka.PokazatKartiIgroka

'nKartKompa.RazdatKartiCompu
'
'nKartKompa.PokazatKartiKompa
End Sub

Private Sub Form_Unload(Cancel As Integer)
'///////////////
'Unload Form2
'////////////////del

If Form1.KolIgrIgroka = 0 Then
If ImyaIgroca = "" Then Exit Sub
DeleteSetting "Durak", "Igroci", ImyaIgroca
End If

End Sub

Private Sub help_Click()
MsgBox "Чем можно помочь" & vbCrLf & _
" в этой дурацкой игре?", vbQuestion, "Компьютер"
End Sub




Private Sub Igroki_Click()
Form1.Timer1.Interval = 400
End Sub

Private Sub Image1_MouseDown(Index As Integer, Button As Integer, Shift As Integer, X As Single, Y As Single)
Dim bKarta As Karta
Dim i As Integer



If Button = 2 Then ' выдвинуть карту
    For Each bKarta In nKartIgroka
        If bKarta.NomImeg = Index Then
            If Image1(Index).Top = 4000 Then _
            Image1(Index).Top = 4300: Exit Sub
                Image1(Index).Top = 4000
        End If
    Next

'///////////////////////////////////////////////
'//////////////////////////СТРАТЕГИЯ////////////////////
ElseIf Button = 1 Then  ' игра
''''''''''''''
'определяю игра 1 или подброс 0
If Not IgraPodbrocIgroka Then
' подброс>>

    Call PodbrosIgrokom(Index)
        CheiXod = True
    If nKartIgroka.ViigralIgrok Then
        CheiXod = True
        Call BudetIgra
        Exit Sub
    End If

'''''''''''''
Else
'игра>>
'"""""""""""""""""""""""""""
 If CheiXod Then  'игрок ходит 1
   nKartIgroka.XodIgroka (Index)
   Label1.Visible = False
   
  If nKartIgroka.ViigralIgrok Then  '2
    CheiXod = True
    Call BudetIgra
    Exit Sub
    Exit Sub
  End If '22
  '!!!!!!!!!после хода игрока отвечает комп!!!!!!!!!
        If nKartKompa.OtvetKompa Then  ' если Не будет снимать
    '///////после ответа комп мог уже выиграть - проверить
            If nKartKompa.ViigralKomp Then
               CheiXod = False
               Call BudetIgra
               Exit Sub
            End If
        
             Command1.Caption = "Бито" '2
             Label1.Visible = True
        Else 'комп не сходил в ответ на ход игрока - значит снимает
           
           '///////////////////////////
           If nKartIgroka.IgrokPodkidivaet Then
            If MsgBox("Вы будете подбрасывать Компьтеру?", vbQuestion + vbOKCancel, "Компютер") = vbOK Then
                IgraPodbrocIgroka = False
                Exit Sub
            End If
            
            End If
           '/////////////////
           
           nKartKompa.UnishtogitKartiKompa
            If nKartKompa.KompShyal Then '3
                    
                    nKartIgroka.UnichtogitKartiIgroka
                    nKartIgroka.RazdatKartiIgrocu
                    nKartIgroka.RaspologKartIgroka
                    
                    If nKoloda.ConchilasKoloda Then '4
                        nKoloda.UnichtogitKolodu
                    End If                  '44
                    
                    nKartIgroka.PokazatKartiIgroka
                    
                    nKartKompa.RazdatKartiCompu
                    nKartKompa.PokazatKartiKompa
'                    Command1.Caption = ""
                     Label1.Visible = True
            End If '33
        End If '22
    '/////////////////////////////////////
Else 'CheiXod=False'если ходил комп, теперь отвечает игрок
   
    If nKartIgroka.OtvetIgroka(Index) = True Then '2
     Label1.Visible = False
        
        If nKartIgroka.ViigralIgrok = True Then '3 возвращ 1 если будет играть снова
            CheiXod = True
            Call BudetIgra
            Exit Sub
       End If '22
       
       If Not nKartKompa.XodKompa Then
       '2 если комп не може ходить (подкидывать)
            
            nBita.SozdatBito
            nKartIgroka.UnichtogitKartiIgroka
            nKartIgroka.RazdatKartiIgrocu
            nKartIgroka.RaspologKartIgroka
            
             If nKoloda.ConchilasKoloda Then
                    nKoloda.UnichtogitKolodu
             End If
            
            nKartIgroka.PokazatKartiIgroka
            
            nKartKompa.UnishtogitKartiKompa
            nKartKompa.RazdatKartiCompu
            nKartKompa.PokazatKartiKompa
            
            CheiXod = True
'            Command1.Caption = ""
            Label1.Visible = True
            
        Else 'комп сходил и надо проверить его победу
        
        '////////////////////
            If nKartKompa.ViigralKomp Then
                CheiXod = False
                Call BudetIgra
                Exit Sub
            End If
         '/////////////
        End If '22
       
    End If '11
    
  End If


 End If

End If ' конец проверки на игру или подброс игрока

End Sub


Private Sub New_Click()
NovayaIgra
End Sub



Private Sub nol_Click()
nol.Checked = True
dva.Checked = False
odin.Checked = False
IntervalRazdachiKart = 0
End Sub

Private Sub odin_Click()
odin.Checked = True
nol.Checked = False
dva.Checked = False
IntervalRazdachiKart = 1999999
End Sub
Private Sub dva_Click()
dva.Checked = True
nol.Checked = False
odin.Checked = False
IntervalRazdachiKart = 4999999
End Sub

Private Sub Oproge_Click()
MsgBox "    <Игра в ДУРАКА> " & vbCrLf & _
  "        Version " & App.Major & "." & App.Minor & "." & App.Revision & vbCrLf & _
"            Туев С.В." & vbCrLf _
& "         5.08.2003", , "Информация"

End Sub

Private Sub PoMast_Click()
PoZnach.Checked = False
PoMast.Checked = True
nKartIgroka.UnichtogitKartiIgroka
nKartIgroka.RaspologKartIgroka
nKartIgroka.PokazatKartiIgroka
SaveSetting "Durak", "Opcii", "RaspolKart", True
End Sub

Private Sub PoZnach_Click()
PoMast.Checked = False
PoZnach.Checked = True
nKartIgroka.UnichtogitKartiIgroka
nKartIgroka.RaspologKartIgroka
nKartIgroka.PokazatKartiIgroka
SaveSetting "Durak", "Opcii", "RaspolKart", False
End Sub

Private Sub quit_Click()
Set nKarta1K = Nothing
Set nKartIgroka = Nothing
Set nKoloda = Nothing

Set nKarta1I = Nothing
Set nKartKompa = Nothing
Set nBita = Nothing
Unload Me
End Sub

Private Sub Rubashka_Click()
frmRubashka.Show vbModal
End Sub

Function PodbrosIgrokom(Index) As Boolean
'1 - будет подброс 0 - не будет

nKartIgroka.XodIgroka (Index)

If nKartIgroka.COUNT = 0 Then Exit Function 'нечего подбросить
If nKartIgroka.IgrokPodkidivaet Then
    'Если игрок может подкинуть то
    If MsgBox("Вы будете подбрасывать Компьтеру?", vbQuestion + vbOKCancel, "Компютер") = vbCancel Then
   'если игрок  не хочет подбрасывать (больше)
   '::::::::::::небуду::::::::::::::::::::::::::::::
             IgraPodbrocIgroka = True
             nKartKompa.UnishtogitKartiKompa
             nKartKompa.KompShyal  '3
                    
                    nKartIgroka.UnichtogitKartiIgroka
                    nKartIgroka.RazdatKartiIgrocu
                    nKartIgroka.RaspologKartIgroka
                    
                    If nKoloda.ConchilasKoloda Then '4
                        nKoloda.UnichtogitKolodu
                    End If
                    
                    nKartIgroka.PokazatKartiIgroka
                    
                    nKartKompa.RazdatKartiCompu
                    nKartKompa.PokazatKartiKompa
                    'Command1.Caption = ""
                     Label1.Visible = True
                Exit Function ' комп снял и игроку надо ходить
    End If
    '  игрок согласился подбросить
    IgraPodbrocIgroka = False 'подброс
Else
    '<<<<<<<<< игроку нечего подбрасывать >>>>>>>>
    nKartKompa.UnishtogitKartiKompa
    nKartKompa.KompShyal
                    
    nKartIgroka.UnichtogitKartiIgroka
    nKartIgroka.RazdatKartiIgrocu
    nKartIgroka.RaspologKartIgroka
     
    If nKoloda.ConchilasKoloda Then '4
        nKoloda.UnichtogitKolodu
    End If

    nKartIgroka.PokazatKartiIgroka
    nKartKompa.RazdatKartiCompu
    nKartKompa.PokazatKartiKompa
'                    Command1.Caption = ""
        Label1.Visible = True
             
            IgraPodbrocIgroka = True 'игра
    Exit Function
End If

End Function

Function PodbrosKompom()

End Function

Function BudetIgra() As Boolean '1 - дальше игра
                    '0 - закончить игру]
Dim i As Integer
Dim Reitinr

'<<<<<<<<<<<  записать в реестр результаты игры >>>>>>>>>>
KolIgrIgroka = KolIgrIgroka + 1


'If CheiXod Then
'            'выиграл игрок
' KolIgrViigranIgrokom = KolIgrViigranIgrokom + 1
' SaveSetting "Durak", "Igroci", ImyaIgroca, KolIgrViigranIgrokom & "*" & KolIgrIgroka
'Else
'            'выиграл комп
'  SaveSetting "Durak", "Igroci", ImyaIgroca, KolIgrViigranIgrokom & "*" & KolIgrIgroka
'End If


        If MsgBox("Хотите еще поиграть ?", vbQuestion + vbOKCancel, "Компьютер") = vbOK Then
             'дальше игра
            Call NovayaIgra
            
            If CheiXod Then
            'ход игрока
                Label1.Visible = False
            Else
            'Ход компа
                ''nKartKompa.XodKompa
                Label1.Visible = True
    '            Command1.Caption = "Снять"
            End If
            BudetIgra = True
        Else
            'закончить игру
'               Command1.Caption = ""
            For i = 0 To 5
                Image3(i).Visible = False
                Image4(i).Visible = False
            Next i
            Image6.Visible = False
            Command1.Visible = False
            Shape1.Visible = False
            Label1.Visible = False
            
            nKartIgroka.UnichtogitKartiIgroka
            nKartKompa.UnishtogitKartiKompa
            
            nBita.OchistitBito
            nKoloda.UnichtogitKolodu

            Set nKarta1K = Nothing
            Set nKartIgroka = Nothing
            Set nKoloda = Nothing

            Set nKarta1I = Nothing
            Set nKartKompa = Nothing
            Set nBita = Nothing
            
            BudetIgra = False
'            Exit Function
        End If
End Function

Private Sub statist_Click()
frmStatistic.Show vbModal
End Sub


Private Sub Timer1_Timer()

End Sub

Private Sub Timer2_Timer()

End Sub
