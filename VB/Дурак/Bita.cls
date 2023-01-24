VERSION 1.0 CLASS
BEGIN
  MultiUse = -1  'True
  Persistable = 0  'NotPersistable
  DataBindingBehavior = 0  'vbNone
  DataSourceBehavior  = 0  'vbNone
  MTSTransactionMode  = 0  'NotAnMTSObject
END
Attribute VB_Name = "Bita"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = True
Attribute VB_PredeclaredId = False
Attribute VB_Exposed = False
Option Explicit

Dim nBita As Collection
Sub OchistitBito()
Form1.Image2(0).Visible = False
Set Form1.nBita = Nothing
End Sub

Sub SozdatBito()
'БИТО
Dim i, j As Integer
Dim cKarta As Karta
Dim iKarta As Karta
Dim NRub As Integer
If Form1.nKarta1I.COUNT <> Form1.nKarta1K.COUNT Then Exit Sub

If Form1.Rubaska Then
NRub = 101
Else
NRub = 102
End If
 Form1.Image2(0).Picture = LoadResPicture(NRub, vbResBitmap)
 Form1.Image2(0).Visible = True
    
' проверить бы, можно ли положить в Бита

For i = 1 To Form1.nKarta1I.COUNT
    Set iKarta = Form1.nKarta1I(i)
    
    Form1.nBita.ADD iKarta.MAST, iKarta.Znachenie, iKarta.ID, _
    iKarta.NomImeg, iKarta.Xleft, iKarta.Ytop
    Form1.Image3(i - 1).Visible = False
    
'    Image1(iKarta.NomImeg).Left = 8000
'    Image1(iKarta.NomImeg).Top = 2000
'
    Set cKarta = Form1.nKarta1K(i)
    'MsgBox Form1.nKarta1K.COUNT
    
    Form1.nBita.ADD cKarta.MAST, cKarta.Znachenie, cKarta.ID, _
    cKarta.NomImeg, cKarta.Xleft, cKarta.Ytop
    Form1.Image4(i - 1).Visible = False
    
'    Image1(cKarta.NomImeg).Left = 8000
'    Image1(cKarta.NomImeg).Top = 2000

Next

Set Form1.nKarta1I = Nothing
Set Form1.nKarta1K = Nothing

Form1.Command1.Caption = ""



End Sub
Private Sub Class_Initialize()
Set nBita = New Collection
End Sub
Public Function ADD(ByVal MAST _
As String, ByVal Znachenie As Integer, _
ID As Integer, NomImeg As Integer, Xleft, Ytop)
Dim nKarta As Karta
Set nKarta = New Karta

With nKarta
.Xleft = Xleft
.Ytop = Ytop
.NomImeg = NomImeg
.ID = ID
.MAST = MAST
.Znachenie = Znachenie
nBita.ADD nKarta, CStr(.ID)

End With
End Function

Public Function ITEM(Index)
Set ITEM = nBita.ITEM(Index)
End Function

Public Property Get NewEnum() As IUnknown
    Set NewEnum = nBita.[_NewEnum]
End Property
Public Function COUNT()
COUNT = nBita.COUNT
End Function
Public Function REMOVE(Index)
nBita.REMOVE (Index)
End Function

