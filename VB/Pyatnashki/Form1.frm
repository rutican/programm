VERSION 5.00
Begin VB.Form Form1 
   BorderStyle     =   1  'Fixed Single
   Caption         =   "           Пятнашки"
   ClientHeight    =   4530
   ClientLeft      =   4200
   ClientTop       =   2325
   ClientWidth     =   4515
   Icon            =   "Form1.frx":0000
   LinkTopic       =   "Form1"
   LockControls    =   -1  'True
   MaxButton       =   0   'False
   MinButton       =   0   'False
   ScaleHeight     =   4530
   ScaleWidth      =   4515
   StartUpPosition =   2  'CenterScreen
   Begin VB.Frame Frame1 
      BackColor       =   &H0000FF00&
      BorderStyle     =   0  'None
      Height          =   4400
      Left            =   60
      TabIndex        =   0
      Top             =   60
      Width           =   4400
      Begin VB.CommandButton Command1 
         BackColor       =   &H0000FF00&
         BeginProperty Font 
            Name            =   "MS Sans Serif"
            Size            =   24
            Charset         =   204
            Weight          =   700
            Underline       =   0   'False
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         Height          =   1100
         Index           =   16
         Left            =   3345
         MaskColor       =   &H00FFFFFF&
         Style           =   1  'Graphical
         TabIndex        =   16
         TabStop         =   0   'False
         Top             =   3300
         Width           =   1100
      End
      Begin VB.CommandButton Command1 
         BackColor       =   &H80000003&
         Caption         =   "15"
         BeginProperty Font 
            Name            =   "MS Sans Serif"
            Size            =   24
            Charset         =   204
            Weight          =   700
            Underline       =   0   'False
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         Height          =   1100
         Index           =   15
         Left            =   2220
         MaskColor       =   &H000000C0&
         Style           =   1  'Graphical
         TabIndex        =   15
         TabStop         =   0   'False
         Top             =   3300
         Width           =   1100
      End
      Begin VB.CommandButton Command1 
         BackColor       =   &H80000003&
         Caption         =   "4"
         BeginProperty Font 
            Name            =   "MS Sans Serif"
            Size            =   24
            Charset         =   204
            Weight          =   700
            Underline       =   0   'False
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         Height          =   1100
         Index           =   4
         Left            =   3300
         MaskColor       =   &H000000C0&
         Style           =   1  'Graphical
         TabIndex        =   4
         TabStop         =   0   'False
         Top             =   0
         Width           =   1100
      End
      Begin VB.CommandButton Command1 
         BackColor       =   &H80000003&
         Caption         =   "14"
         BeginProperty Font 
            Name            =   "MS Sans Serif"
            Size            =   24
            Charset         =   204
            Weight          =   700
            Underline       =   0   'False
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         Height          =   1100
         Index           =   14
         Left            =   1110
         MaskColor       =   &H000000C0&
         Style           =   1  'Graphical
         TabIndex        =   14
         TabStop         =   0   'False
         Top             =   3300
         Width           =   1100
      End
      Begin VB.CommandButton Command1 
         BackColor       =   &H80000003&
         Caption         =   "13"
         BeginProperty Font 
            Name            =   "MS Sans Serif"
            Size            =   24
            Charset         =   204
            Weight          =   700
            Underline       =   0   'False
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         Height          =   1100
         Index           =   13
         Left            =   0
         MaskColor       =   &H000000C0&
         Style           =   1  'Graphical
         TabIndex        =   13
         TabStop         =   0   'False
         Top             =   3300
         Width           =   1100
      End
      Begin VB.CommandButton Command1 
         BackColor       =   &H80000003&
         Caption         =   "12"
         BeginProperty Font 
            Name            =   "MS Sans Serif"
            Size            =   24
            Charset         =   204
            Weight          =   700
            Underline       =   0   'False
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         Height          =   1100
         Index           =   12
         Left            =   3315
         MaskColor       =   &H000000C0&
         Style           =   1  'Graphical
         TabIndex        =   12
         TabStop         =   0   'False
         Top             =   2205
         Width           =   1100
      End
      Begin VB.CommandButton Command1 
         BackColor       =   &H80000003&
         Caption         =   "11"
         BeginProperty Font 
            Name            =   "MS Sans Serif"
            Size            =   24
            Charset         =   204
            Weight          =   700
            Underline       =   0   'False
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         Height          =   1100
         Index           =   11
         Left            =   2205
         MaskColor       =   &H00FFFFFF&
         Style           =   1  'Graphical
         TabIndex        =   11
         TabStop         =   0   'False
         Top             =   2205
         Width           =   1100
      End
      Begin VB.CommandButton Command1 
         BackColor       =   &H80000003&
         Caption         =   "10"
         BeginProperty Font 
            Name            =   "MS Sans Serif"
            Size            =   24
            Charset         =   204
            Weight          =   700
            Underline       =   0   'False
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         Height          =   1100
         Index           =   10
         Left            =   1095
         MaskColor       =   &H000000C0&
         Style           =   1  'Graphical
         TabIndex        =   10
         TabStop         =   0   'False
         Top             =   2205
         Width           =   1100
      End
      Begin VB.CommandButton Command1 
         BackColor       =   &H80000003&
         Caption         =   "9"
         BeginProperty Font 
            Name            =   "MS Sans Serif"
            Size            =   24
            Charset         =   204
            Weight          =   700
            Underline       =   0   'False
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         Height          =   1100
         Index           =   9
         Left            =   -15
         MaskColor       =   &H000000C0&
         Style           =   1  'Graphical
         TabIndex        =   9
         TabStop         =   0   'False
         Top             =   2205
         Width           =   1100
      End
      Begin VB.CommandButton Command1 
         BackColor       =   &H80000003&
         Caption         =   "8"
         BeginProperty Font 
            Name            =   "MS Sans Serif"
            Size            =   24
            Charset         =   204
            Weight          =   700
            Underline       =   0   'False
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         Height          =   1100
         Index           =   8
         Left            =   3300
         MaskColor       =   &H000000C0&
         Style           =   1  'Graphical
         TabIndex        =   8
         TabStop         =   0   'False
         Top             =   1095
         Width           =   1100
      End
      Begin VB.CommandButton Command1 
         BackColor       =   &H80000003&
         Caption         =   "7"
         BeginProperty Font 
            Name            =   "MS Sans Serif"
            Size            =   24
            Charset         =   204
            Weight          =   700
            Underline       =   0   'False
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         Height          =   1100
         Index           =   7
         Left            =   2190
         MaskColor       =   &H000000C0&
         Style           =   1  'Graphical
         TabIndex        =   7
         TabStop         =   0   'False
         Top             =   1095
         Width           =   1100
      End
      Begin VB.CommandButton Command1 
         BackColor       =   &H80000003&
         Caption         =   "6"
         BeginProperty Font 
            Name            =   "MS Sans Serif"
            Size            =   24
            Charset         =   204
            Weight          =   700
            Underline       =   0   'False
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         Height          =   1100
         Index           =   6
         Left            =   1080
         MaskColor       =   &H000000C0&
         Style           =   1  'Graphical
         TabIndex        =   6
         TabStop         =   0   'False
         Top             =   1095
         Width           =   1100
      End
      Begin VB.CommandButton Command1 
         BackColor       =   &H80000003&
         Caption         =   "5"
         BeginProperty Font 
            Name            =   "MS Sans Serif"
            Size            =   24
            Charset         =   204
            Weight          =   700
            Underline       =   0   'False
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         Height          =   1100
         Index           =   5
         Left            =   0
         MaskColor       =   &H000000C0&
         Style           =   1  'Graphical
         TabIndex        =   5
         TabStop         =   0   'False
         Top             =   1095
         Width           =   1100
      End
      Begin VB.CommandButton Command1 
         BackColor       =   &H80000003&
         Caption         =   "3"
         BeginProperty Font 
            Name            =   "MS Sans Serif"
            Size            =   24
            Charset         =   204
            Weight          =   700
            Underline       =   0   'False
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         Height          =   1100
         Index           =   3
         Left            =   2190
         MaskColor       =   &H000000C0&
         Style           =   1  'Graphical
         TabIndex        =   3
         TabStop         =   0   'False
         Top             =   0
         Width           =   1100
      End
      Begin VB.CommandButton Command1 
         BackColor       =   &H80000003&
         Caption         =   "2"
         BeginProperty Font 
            Name            =   "MS Sans Serif"
            Size            =   24
            Charset         =   204
            Weight          =   700
            Underline       =   0   'False
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         Height          =   1100
         Index           =   2
         Left            =   1080
         MaskColor       =   &H000000C0&
         Style           =   1  'Graphical
         TabIndex        =   2
         TabStop         =   0   'False
         Top             =   0
         Width           =   1100
      End
      Begin VB.CommandButton Command1 
         BackColor       =   &H80000003&
         Caption         =   "1"
         DragIcon        =   "Form1.frx":0442
         BeginProperty Font 
            Name            =   "MS Sans Serif"
            Size            =   24
            Charset         =   204
            Weight          =   700
            Underline       =   0   'False
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         Height          =   1100
         Index           =   1
         Left            =   -15
         MaskColor       =   &H000000C0&
         Style           =   1  'Graphical
         TabIndex        =   1
         TabStop         =   0   'False
         Top             =   0
         Width           =   1100
      End
   End
   Begin VB.Line Line2 
      BorderWidth     =   3
      Index           =   1
      X1              =   15
      X2              =   4485
      Y1              =   4485
      Y2              =   4485
   End
   Begin VB.Line Line2 
      BorderWidth     =   3
      Index           =   0
      X1              =   30
      X2              =   4485
      Y1              =   15
      Y2              =   15
   End
   Begin VB.Line Line1 
      BorderWidth     =   3
      Index           =   1
      X1              =   4485
      X2              =   4485
      Y1              =   30
      Y2              =   4455
   End
   Begin VB.Line Line1 
      BorderWidth     =   3
      Index           =   0
      X1              =   30
      X2              =   30
      Y1              =   30
      Y2              =   4500
   End
   Begin VB.Menu igra 
      Caption         =   "Игра"
      Begin VB.Menu newG 
         Caption         =   "Новая игра"
      End
      Begin VB.Menu Qit 
         Caption         =   "Выход"
      End
   End
   Begin VB.Menu Oprog 
      Caption         =   "О программе..."
   End
   Begin VB.Menu Help 
      Caption         =   "Помощь"
   End
End
Attribute VB_Name = "Form1"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Option Explicit
Dim mColKnopok As New ColKnopok
Dim mKnopka As Knopka
Dim VICTORY(16, 1) As Integer
Private Declare Function MessageBeep Lib "user32" (ByVal wType As Long) As Long


Private Sub Command1_Click(Index As Integer)
Dim X1, Y1, X0, Y0 As Integer
Dim PrVic As Boolean
Dim i As Integer
'For Each mKnopka In mColKnopok
'If mKnopka.ID = Index Then
'MsgBox mKnopka.ID & " " & _
'mKnopka.KorZentCnopX & " " & _
'mKnopka.KorZentCnopY
'End If
'Next


Set mKnopka = mColKnopok.ITEM(CStr(16))
X1 = mKnopka.KorZentCnopX
Y1 = mKnopka.KorZentCnopY

Set mKnopka = mColKnopok.ITEM(CStr(Index))
X0 = mKnopka.KorZentCnopX
Y0 = mKnopka.KorZentCnopY

    If X1 = X0 Or Y1 = Y0 Then

        If Abs(X1 - X0) = 1100 Or _
        Abs(Y1 - Y0) = 1100 Then


        Command1(Index).Move X1, Y1
        mColKnopok.REMOVE (CStr(Index))
        mColKnopok.ADD X1, Y1, Index
        
        
        Command1(16).Move X0, Y0
        mColKnopok.REMOVE (CStr(16))
        mColKnopok.ADD X0, Y0, 16
        
  '      MessageBeep (64)
    Else
Beep
    End If

 Else
Beep
End If

PrVic = True

For Each mKnopka In mColKnopok
    If VICTORY(mKnopka.ID, 0) = mKnopka.KorZentCnopX And _
        VICTORY(mKnopka.ID, 1) = mKnopka.KorZentCnopY Then
    
    Else
        PrVic = False
        Exit For
    End If
Next

If PrVic Then
MsgBox "  Поздравляю ВАС                 " & vbCrLf & _
"         ПОБЕДА!!! ", vbInformation, " !!!!!!!!!!!!!!!!!!!!!!!!!!!!! "

i = MsgBox(" Хотите начать новую игру ? ", vbQuestion + vbYesNoCancel, "")

If i = 6 Then
Exit Sub
newG.Visible = True
ElseIf i = 7 Then
Frame1.Visible = False
Else
Unload Me
End If
End If
End Sub

Private Sub Command1_MouseDown(Index As Integer, Button As Integer, Shift As Integer, X As Single, Y As Single)
'Select Case Index
'Case Is = 1
'Command1(Index).DragMode = 0
'Command1(Index).Drag vbBeginDrag
'
'End Select

End Sub

Private Sub Form_Load()
Randomize
Call RazmKnop

End Sub

Sub RazmKnop()
Dim i As Integer
Dim j As Integer
Dim k As Integer
Dim Mas() As Integer
Dim n As Integer
Dim Bilo As Boolean


j = 1
k = 1
n = 0
Randomize
ReDim Mas(0)

Do While UBound(Mas) < 16
Bilo = False
i = CInt(Rnd * 16)
    For n = 0 To UBound(Mas)
        If Mas(n) = i Then
        Bilo = Bilo + True
    End If
    Next n
        
        If Not Bilo Then
        ReDim Preserve Mas(UBound(Mas) + 1)
        Mas(n - 1) = i
        End If
           
Loop

For n = 0 To UBound(Mas) - 1
i = Mas(n)
      
      VICTORY(n + 1, 0) = (Frame1.Width / 8 * j - Command1(i).Width / 2)
      VICTORY(n + 1, 1) = (Frame1.Height / 8 * k - Command1(i).Height / 2)
'Debug.Print n & " - " & VICTORY(n, 0) & "    " & VICTORY(n, 1)

Command1(i).Move (Frame1.Width / 8 * j - Command1(i).Width / 2) _
, (Frame1.Height / 8 * k - Command1(i).Height / 2)

mColKnopok.ADD (Frame1.Width / 8 * j - Command1(i).Width / 2), _
(Frame1.Height / 8 * k - Command1(i).Height / 2), i

If j = 7 Then
    j = 1
     k = k + 2
Else
    j = j + 2
End If

Next n

End Sub

Private Sub Help_Click()
MsgBox "Цель игры:" & vbCrLf & _
vbCrLf & "Выстроить квадраты в порядке возрастания их номеров." & vbCrLf _
& "Зеленый квадрат должен оказаться в правом нижнем углу." & vbCrLf & _
vbCrLf & "Стратегия игры:" & vbCrLf & _
vbCrLf & "Передвигая синие нумерованные квадраты, " & _
vbCrLf & "щелкая на них мышкой, выстроить заданный порядок.", , "Использовать согласно инструкции."

End Sub

Private Sub newG_Click()
Set mColKnopok = Nothing
Frame1.Visible = True
Randomize
Call RazmKnop
End Sub

Private Sub Oprog_Click()

MsgBox "  <Игра в ПЯТНАШКИ>       " & vbCrLf & _
  "        Version " & App.Major & "." & App.Minor & "." & App.Revision & vbCrLf & _
"            Туев С.В." & vbCrLf _
& "         05.05.2003", , "Информация"

End Sub

Private Sub Qit_Click()
Set mColKnopok = Nothing
Set mKnopka = Nothing
Unload Me
'frmRED.Visible = True

End Sub
