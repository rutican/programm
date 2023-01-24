VERSION 5.00
Begin VB.Form frmStatistic 
   BackColor       =   &H00808000&
   BorderStyle     =   4  'Fixed ToolWindow
   ClientHeight    =   3030
   ClientLeft      =   4185
   ClientTop       =   3630
   ClientWidth     =   4710
   LinkTopic       =   "Form4"
   MaxButton       =   0   'False
   MinButton       =   0   'False
   ScaleHeight     =   3030
   ScaleWidth      =   4710
   ShowInTaskbar   =   0   'False
   StartUpPosition =   2  'CenterScreen
   Begin VB.CommandButton Command1 
      Appearance      =   0  'Flat
      BackColor       =   &H00FFFF00&
      Caption         =   "Хорошо"
      BeginProperty Font 
         Name            =   "MS Sans Serif"
         Size            =   8.25
         Charset         =   204
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   375
      Left            =   1470
      MaskColor       =   &H00808000&
      TabIndex        =   0
      Top             =   2475
      Width           =   1770
   End
   Begin VB.Label Label4 
      Alignment       =   2  'Center
      BackStyle       =   0  'Transparent
      Caption         =   "Label4"
      BeginProperty Font 
         Name            =   "MS Sans Serif"
         Size            =   12
         Charset         =   204
         Weight          =   700
         Underline       =   0   'False
         Italic          =   -1  'True
         Strikethrough   =   0   'False
      EndProperty
      Height          =   360
      Left            =   735
      TabIndex        =   4
      Top             =   2100
      Width           =   3525
   End
   Begin VB.Label Label3 
      Alignment       =   2  'Center
      BackStyle       =   0  'Transparent
      Caption         =   "Label3"
      BeginProperty Font 
         Name            =   "MS Sans Serif"
         Size            =   12
         Charset         =   204
         Weight          =   700
         Underline       =   0   'False
         Italic          =   -1  'True
         Strikethrough   =   0   'False
      EndProperty
      Height          =   390
      Left            =   278
      TabIndex        =   3
      Top             =   1530
      Width           =   4155
   End
   Begin VB.Label Label2 
      Alignment       =   2  'Center
      BackStyle       =   0  'Transparent
      Caption         =   "Label2"
      BeginProperty Font 
         Name            =   "MS Sans Serif"
         Size            =   12
         Charset         =   204
         Weight          =   700
         Underline       =   0   'False
         Italic          =   -1  'True
         Strikethrough   =   0   'False
      EndProperty
      Height          =   390
      Left            =   735
      TabIndex        =   2
      Top             =   1005
      Width           =   3120
   End
   Begin VB.Label Label1 
      Alignment       =   2  'Center
      BackStyle       =   0  'Transparent
      BorderStyle     =   1  'Fixed Single
      BeginProperty Font 
         Name            =   "MS Sans Serif"
         Size            =   12
         Charset         =   204
         Weight          =   700
         Underline       =   0   'False
         Italic          =   -1  'True
         Strikethrough   =   0   'False
      EndProperty
      Height          =   360
      Left            =   1523
      TabIndex        =   1
      Top             =   330
      Width           =   1665
   End
End
Attribute VB_Name = "frmStatistic"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Option Explicit

Private Sub Command1_Click()
Unload Me
End Sub

Private Sub Form_Load()
Label1.Caption = Form1.ImyaIgroca
Label2.Caption = "Количество игр " & Form1.KolIgrIgroka
Label3.Caption = "Количество выигранных игр " & Form1.KolIgrViigranIgrokom

Label4.Caption = "Рейтинг " & Int((Form1.KolIgrViigranIgrokom / Form1.KolIgrIgroka) * 100)
End Sub
