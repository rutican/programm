VERSION 5.00
Object = "{5E9E78A0-531B-11CF-91F6-C2863C385E30}#1.0#0"; "Msflxgrd.ocx"
Begin VB.Form Form3 
   BackColor       =   &H00FF0000&
   BorderStyle     =   1  'Fixed Single
   Caption         =   "Выбор игрока"
   ClientHeight    =   2955
   ClientLeft      =   3750
   ClientTop       =   3015
   ClientWidth     =   5220
   Icon            =   "Form3.frx":0000
   LinkTopic       =   "Form3"
   LockControls    =   -1  'True
   MaxButton       =   0   'False
   MinButton       =   0   'False
   ScaleHeight     =   2955
   ScaleWidth      =   5220
   Begin VB.Frame Frame1 
      BackColor       =   &H00FF8080&
      Height          =   2775
      Left            =   30
      TabIndex        =   0
      Top             =   105
      Width           =   5115
      Begin VB.CommandButton Command4 
         Caption         =   "Удалить"
         Height          =   480
         Left            =   3345
         TabIndex        =   5
         Top             =   1515
         Width           =   1425
      End
      Begin VB.CommandButton Command3 
         Caption         =   "Выход"
         Height          =   480
         Left            =   3330
         TabIndex        =   4
         Top             =   2175
         Width           =   1440
      End
      Begin VB.CommandButton Command2 
         Caption         =   "Новый игрок"
         Height          =   480
         Left            =   3345
         TabIndex        =   3
         Top             =   900
         Width           =   1440
      End
      Begin VB.CommandButton Command1 
         Caption         =   "Игра"
         Height          =   480
         Left            =   3345
         TabIndex        =   2
         Top             =   240
         Width           =   1440
      End
      Begin MSFlexGridLib.MSFlexGrid MSFlexGrid1 
         Height          =   2145
         Left            =   120
         TabIndex        =   1
         Top             =   345
         Width           =   2970
         _ExtentX        =   5239
         _ExtentY        =   3784
         _Version        =   393216
         Rows            =   6
         FixedCols       =   0
         FocusRect       =   2
         GridLines       =   3
         ScrollBars      =   2
         SelectionMode   =   1
         Appearance      =   0
         BeginProperty Font {0BE35203-8F91-11CE-9DE3-00AA004BB851} 
            Name            =   "MS Sans Serif"
            Size            =   12
            Charset         =   204
            Weight          =   700
            Underline       =   0   'False
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
      End
      Begin VB.Line Line3 
         BorderColor     =   &H80000004&
         X1              =   3090
         X2              =   5190
         Y1              =   2040
         Y2              =   2040
      End
      Begin VB.Line Line2 
         BorderColor     =   &H80000004&
         X1              =   3045
         X2              =   5115
         Y1              =   1425
         Y2              =   1425
      End
      Begin VB.Line Line1 
         BorderColor     =   &H80000004&
         X1              =   3045
         X2              =   5085
         Y1              =   810
         Y2              =   810
      End
   End
End
Attribute VB_Name = "Form3"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Option Explicit

Dim Igroki As Variant
Dim NomYacheiki As Integer
Dim masMSFG(10, 2) As String 'Для проверки игроков
Public NameIgroka As String
Public ReitingIgroka As Integer

Private Sub Command1_Click() 'игра
Dim i As Integer




Form3.Visible = False
Form1.NovayaIgra
Unload Me
Form1.Timer1.Interval = 0

    Form1.Igra.Enabled = True
    Form1.Rubashka.Enabled = True
    Form1.RaspKart.Enabled = True
    Form1.Igroki.Enabled = False
     Form1.statist.Enabled = True
     
If Not IsEmpty(Igroki) Then
    For i = 0 To UBound(Igroki)
        If Igroki(i, 0) = Form1.ImyaIgroca And _
        Igroki(i, 1) <> "" Then
        Form1.KolIgrIgroka = Right(Igroki(i, 1), InStr(1, Igroki(i, 1), "*") - 1)
        Form1.KolIgrViigranIgrokom = Left(Igroki(i, 1), InStr(1, Igroki(i, 1), "*") - 1)
        
        End If
    Next
End If

End Sub

Private Sub Command2_Click() 'новый игрок
Dim i As Integer


For i = 0 To 4
   If masMSFG(i, 0) = "" Then Exit For
Next i

If i > 3 Then _
 MsgBox "Чтобы ввести свое имя, " & vbCrLf & _
"удалите одного из игроков!", vbInformation, "Кмпьютер": Exit Sub


NameIgroka = InputBox("Введите свое имя!", "")
If NameIgroka = "" Then Exit Sub
'SaveSetting "Durak", "Igroci", NameIgroka, ""
'
SaveSetting "Durak", "Igroci", NameIgroka, ""

Select Case i

Case Is = 0
    MSFlexGrid1.TextArray(4) = NameIgroka
    masMSFG(i, 0) = NameIgroka
Case Is = 1
    MSFlexGrid1.TextArray(6) = NameIgroka
      masMSFG(i, 0) = NameIgroka
Case Is = 2
    MSFlexGrid1.TextArray(8) = NameIgroka
      masMSFG(i, 0) = NameIgroka
Case Is = 3
    MSFlexGrid1.TextArray(10) = NameIgroka
      masMSFG(i, 0) = NameIgroka
End Select


End Sub

Private Sub Command3_Click()


Unload Me
End Sub

Private Sub Command4_Click() ' удалить
Dim i, j As Integer


Command1.Enabled = False
Form1.ImyaIgroca = ""
'MSFlexGrid1.TextArray(NomYacheiki + 2) = ""
'MSFlexGrid1.TextArray(NomYacheiki + 3) = ""

DeleteSetting "Durak", "Igroci", masMSFG(NomYacheiki, 0)
masMSFG(NomYacheiki, 0) = ""
masMSFG(NomYacheiki, 1) = ""

'перезаписать ленту стереть
For i = 4 To 10
    MSFlexGrid1.TextArray(i) = ""
Next i

j = 4
For i = 0 To 6
    If masMSFG(i, 0) <> "" Then
        MSFlexGrid1.TextArray(j) = masMSFG(i, 0)
        MSFlexGrid1.TextArray(j + 1) = masMSFG(i, 1)
         j = j + 2
    End If
Next i


j = 4
For i = 0 To 3
    masMSFG(i, 0) = MSFlexGrid1.TextArray(j)
    masMSFG(i, 1) = MSFlexGrid1.TextArray(j + 1)
    j = j + 2
Next i

Command4.Enabled = False
End Sub

Private Sub Form_Load()
Dim i, j, k As Integer


'считать из реестра игроков и рейтинг
'//////////////////////
Igroki = GetAllSettings("Durak", "Igroci")

If Not IsEmpty(Igroki) Then

    'формирую массив записей
    For i = 0 To UBound(Igroki)
        
            masMSFG(i, 0) = Igroki(i, 0)
            If Igroki(i, 1) = "" Then
              masMSFG(i, 1) = 0
            Else
            masMSFG(i, 1) = Format(Left(Igroki(i, 1), InStr(1, Igroki(i, 1), "*") - 1) / _
            Right(Igroki(i, 1), InStr(1, Igroki(i, 1), "*") - 1) * 100, "### ")
       
'           masMSFG(i, 1) = Format(Left(Igroki(i, 1), InStr(1, Igroki(i, 1), "*") - 1) / _
'           Right(Igroki(i, 1), InStr(1, Igroki(i, 1), "*")) * 100, "### ")
            End If
    Next i


    'Записываю в ленту
    k = 4 'первое имя
    For i = 0 To UBound(Igroki)
        MSFlexGrid1.TextArray(k) = masMSFG(i, 0)
        MSFlexGrid1.TextArray(k + 1) = masMSFG(i, 1)
        k = k + 2
    Next i

End If

'//////////////////////
Command1.Enabled = False
Command4.Enabled = False

MSFlexGrid1.TextArray(0) = "Имя игрока"
MSFlexGrid1.ColWidth(0) = 150 * CInt(Len(MSFlexGrid1.TextArray(0)))

MSFlexGrid1.TextArray(1) = "Рейтинг"
MSFlexGrid1.Font.Bold = False
MSFlexGrid1.TextArray(2) = "Сергей"
MSFlexGrid1.TextArray(3) = 57




End Sub







Private Sub Form_Unload(Cancel As Integer)
Form1.Timer1.Interval = 0

If Form1.ImyaIgroca = "" Then
    Form1.Igra.Enabled = False
    Form1.Rubashka.Enabled = False
    Form1.RaspKart.Enabled = False
    Form1.Igroki.Enabled = True
    Form1.statist.Enabled = False
End If



End Sub

Private Sub MSFlexGrid1_MouseDown(Button As Integer, Shift As Integer, X As Single, Y As Single)
'MsgBox "x= " & x & " y= " & y
Select Case Y

Case 333 To 666
'11111111MsgBox "Первая строка"
   ' NomYacheiki = 8
    Command4.Enabled = False
    Command1.Enabled = False
    Form1.ImyaIgroca = ""
'    If MSFlexGrid1.TextArray(2) <> "" Then
'        'Command1.Enabled = True
'    Else
'
'    End If


Case 666 To 999
'2222222222MsgBox "Вторая строка"
NomYacheiki = 0
    If MSFlexGrid1.TextArray(4) <> "" Then
        Command1.Enabled = True
        Command4.Enabled = True
    Else
        Command1.Enabled = False
        Command4.Enabled = False
    End If
Form1.ImyaIgroca = MSFlexGrid1.TextArray(4)

Case 999 To 1332
'333333333
NomYacheiki = 1
    If MSFlexGrid1.TextArray(6) <> "" Then
        Command1.Enabled = True
        Command4.Enabled = True
    Else
        Command1.Enabled = False
         Command4.Enabled = False
    End If
Form1.ImyaIgroca = MSFlexGrid1.TextArray(6)

Case 1332 To 1665
'44444444
    NomYacheiki = 2
    If MSFlexGrid1.TextArray(8) <> "" Then
        Command1.Enabled = True
        Command4.Enabled = True
    Else
        Command1.Enabled = False
         Command4.Enabled = False
    End If
    Form1.ImyaIgroca = MSFlexGrid1.TextArray(8)

Case 1665 To 1998
'5555555555
NomYacheiki = 3

    If MSFlexGrid1.TextArray(10) <> "" Then
        Command1.Enabled = True
        Command4.Enabled = True
    Else
        Command1.Enabled = False
         Command4.Enabled = False
    End If
Form1.ImyaIgroca = MSFlexGrid1.TextArray(10)
'Case 1998 To 2331
'66666666

End Select

End Sub

Private Sub MSHFlexGrid1_Click()

End Sub
