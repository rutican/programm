VERSION 1.0 CLASS
BEGIN
  MultiUse = -1  'True
  Persistable = 0  'NotPersistable
  DataBindingBehavior = 0  'vbNone
  DataSourceBehavior  = 0  'vbNone
  MTSTransactionMode  = 0  'NotAnMTSObject
END
Attribute VB_Name = "Koloda"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = True
Attribute VB_PredeclaredId = False
Attribute VB_Exposed = False
Option Explicit
Dim nKoloda As Collection
Dim KozirKolodoUnih As Integer

Sub UnichtogitKolodu()

Form1.Image1(0).Visible = False
Form1.Image5.Visible = False
End Sub

 Function ConchilasKoloda() As Boolean 'сообщает кончилась ли колода
Dim DaNet As Boolean
If Form1.nKoloda.COUNT = 0 Then
    DaNet = True
Else
    DaNet = False
End If
    
ConchilasKoloda = DaNet
End Function


Sub PokazatKozir()
Dim mKarta As Karta
Set mKarta = Form1.nKoloda.ITEM(CStr(1))


    
    Form1.Image5.Top = 2500
    'Form1.Image1(mKarta.NomImeg).Left = L
    Form1.Image5.Picture = LoadResPicture(mKarta.MAST & mKarta.Znachenie, vbResBitmap)
    Form1.Image5.Visible = True
   

End Sub

Sub PokazatKolodu()
Dim NRub As Integer

If Form1.Rubaska Then
    NRub = 101
Else
    NRub = 102
End If

    Form1.Image1(0).Picture = LoadResPicture(NRub, vbResBitmap)
     Form1.Image1(0).Visible = True
    
End Sub

Sub OpredKozirya()

Dim NomBmpKOz As Integer
Dim mKarta As Karta
Dim koz As Integer

If Form1.nKoloda.COUNT = 0 Then Stop: Exit Sub

Set mKarta = Form1.nKoloda.ITEM(CStr(1)) ' измен для толадки

'Image1(mKarta.NomImeg).Top = 2500
Form1.KOZIR = mKarta.MAST
KozirKolodoUnih = mKarta.NomImeg

Select Case Form1.KOZIR
Case Is = "BUB"
koz = 105
Case Is = "CHERV"
koz = 103
Case Is = "KREST"
koz = 104
Case Is = "PIC"
koz = 106
End Select

Form1.Image6.Picture = LoadResPicture(koz, vbResBitmap)

'выбор загружаемого козыря
'Set mKarta = Nothing
'Select Case Form1.KOZIR
'Case Is = "BUB"
'NomBmpKOz = 103
'Case Is = "CHERV"
'NomBmpKOz = 101
'Case Is = "KREST"
'NomBmpKOz = 102
'Case Is = "PIC"
'NomBmpKOz = 104
'End Select

End Sub
Public Sub PeretasovkaKolodi()
Randomize
Dim i As Integer
Dim j As Integer
Dim k As Integer
Dim MAST As String
Dim Znachenie As Integer
Dim MAS() As Integer
Dim n As Integer
Dim Bilo As Boolean
Dim nKarta As Karta

ReDim MAS(0)

Do While UBound(MAS) < 36
Bilo = False
i = CInt(Rnd * 36)
    For n = 0 To UBound(MAS)
        If MAS(n) = i Then
        Bilo = Bilo + True
    End If
    Next n
        
        If Not Bilo Then
        ReDim Preserve MAS(UBound(MAS) + 1)
        MAS(n - 1) = i
        End If
    
Loop
'//////////////делаю нужную мне колоду






'////////////////////////////////
For i = 1 To 36 ' изменяю для отладки
k = i - 1

'Image1(i).Left = 105
'Image1(i).Top = 2000
'Image1(i).Visible = True

Select Case i
Case 1 To 4
Znachenie = 6
If i = 1 Then MAST = "BUB"
If i = 2 Then MAST = "CHERV"
If i = 3 Then MAST = "KREST"
If i = 4 Then MAST = "PIC"

Case 5 To 8
Znachenie = 7
If i = 5 Then MAST = "BUB"
If i = 6 Then MAST = "CHERV"
If i = 7 Then MAST = "KREST"
If i = 8 Then MAST = "PIC"

Case 9 To 12
Znachenie = 8
If i = 9 Then MAST = "BUB"
If i = 10 Then MAST = "CHERV"
If i = 11 Then MAST = "KREST"
If i = 12 Then MAST = "PIC"


Case 13 To 16
Znachenie = 9
If i = 13 Then MAST = "BUB"
If i = 14 Then MAST = "CHERV"
If i = 15 Then MAST = "KREST"
If i = 16 Then MAST = "PIC"


Case 17 To 20
Znachenie = 10
If i = 17 Then MAST = "BUB"
If i = 18 Then MAST = "CHERV"
If i = 19 Then MAST = "KREST"
If i = 20 Then MAST = "PIC"


Case 21 To 24
Znachenie = 11
If i = 21 Then MAST = "BUB"
If i = 22 Then MAST = "CHERV"
If i = 23 Then MAST = "KREST"
If i = 24 Then MAST = "PIC"


Case 25 To 28
Znachenie = 12
If i = 25 Then MAST = "BUB"
If i = 26 Then MAST = "CHERV"
If i = 27 Then MAST = "KREST"
If i = 28 Then MAST = "PIC"


Case 29 To 32
Znachenie = 13
If i = 29 Then MAST = "BUB"
If i = 30 Then MAST = "CHERV"
If i = 31 Then MAST = "KREST"
If i = 32 Then MAST = "PIC"


Case 33 To 36
Znachenie = 14
If i = 33 Then MAST = "BUB"
If i = 34 Then MAST = "CHERV"
If i = 35 Then MAST = "KREST"
If i = 36 Then MAST = "PIC"

End Select
'Debug.Print Mas(k) & "   " & k
'If Mas(k) = 16 Then Image1(k).Top = 3000

Form1.nKoloda.ADD MAST, Znachenie, CInt(MAS(k)), _
i + 1, 1, 2 ', Image1(i).Left, Image1(i).Top

Next


End Sub


Private Sub Class_Initialize()
Set nKoloda = New Collection
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
nKoloda.ADD nKarta, CStr(.ID)

End With
End Function

Public Function ITEM(Index)
Set ITEM = nKoloda.ITEM(Index)
End Function

Public Property Get NewEnum() As IUnknown
Attribute NewEnum.VB_UserMemId = -4
Attribute NewEnum.VB_MemberFlags = "40"
    Set NewEnum = nKoloda.[_NewEnum]
End Property
Public Function COUNT()
COUNT = nKoloda.COUNT
End Function
Public Function REMOVE(Index)
nKoloda.REMOVE (Index)
End Function
Sub ColodaDlyaOtladki()

Dim i, k, Znachenie As Integer
Dim MAST As String
Dim MAS(36)
For i = 1 To 12 ' изменяю для отладки
k = i - 1

'Image1(i).Left = 105
'Image1(i).Top = 2000
'Image1(i).Visible = True

Select Case i
Case 1 To 4
Znachenie = 6
If i = 1 Then MAST = "BUB"
If i = 2 Then MAST = "CHERV"
If i = 3 Then MAST = "KREST"
If i = 4 Then MAST = "PIC"

Case 5 To 8
Znachenie = 7
If i = 5 Then MAST = "BUB"
If i = 6 Then MAST = "CHERV"
If i = 7 Then MAST = "KREST"
If i = 8 Then MAST = "PIC"

Case 9 To 12
Znachenie = 8
If i = 9 Then MAST = "BUB"
If i = 10 Then MAST = "CHERV"
If i = 11 Then MAST = "KREST"
If i = 12 Then MAST = "PIC"


Case 13 To 16
Znachenie = 9
If i = 13 Then MAST = "BUB"
If i = 14 Then MAST = "CHERV"
If i = 15 Then MAST = "KREST"
If i = 16 Then MAST = "PIC"


Case 17 To 20
Znachenie = 10
If i = 17 Then MAST = "BUB"
If i = 18 Then MAST = "CHERV"
If i = 19 Then MAST = "KREST"
If i = 20 Then MAST = "PIC"


Case 21 To 24
Znachenie = 11
If i = 21 Then MAST = "BUB"
If i = 22 Then MAST = "CHERV"
If i = 23 Then MAST = "KREST"
If i = 24 Then MAST = "PIC"


Case 25 To 28
Znachenie = 12
If i = 25 Then MAST = "BUB"
If i = 26 Then MAST = "CHERV"
If i = 27 Then MAST = "KREST"
If i = 28 Then MAST = "PIC"


Case 29 To 32
Znachenie = 13
If i = 29 Then MAST = "BUB"
If i = 30 Then MAST = "CHERV"
If i = 31 Then MAST = "KREST"
If i = 32 Then MAST = "PIC"


Case 33 To 36
Znachenie = 14
If i = 33 Then MAST = "BUB"
If i = 34 Then MAST = "CHERV"
If i = 35 Then MAST = "KREST"
If i = 36 Then MAST = "PIC"

End Select
'Debug.Print Mas(k) & "   " & k
'If Mas(k) = 16 Then Image1(k).Top = 3000

Form1.nKoloda.ADD MAST, Znachenie, CInt(i), _
i + 1, 1, 2 ', Image1(i).Left, Image1(i).Top

Next i

End Sub
