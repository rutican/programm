VERSION 1.0 CLASS
BEGIN
  MultiUse = -1  'True
  Persistable = 0  'NotPersistable
  DataBindingBehavior = 0  'vbNone
  DataSourceBehavior  = 0  'vbNone
  MTSTransactionMode  = 0  'NotAnMTSObject
END
Attribute VB_Name = "KartIgroka"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = True
Attribute VB_PredeclaredId = False
Attribute VB_Exposed = False
Option Explicit
'Private Declare Function PlaySound Lib "winmm.dll" Alias "PlaySoundA" (ByVal lpszName As String, ByVal hModule As Long, ByVal dwFlags As Long) As Long

Dim nKartIgroka As Collection
Function IgrokPodkidivaet() As Boolean

Dim i As Integer
Dim bKarta As Karta
Dim cKarta As Karta
Dim MognSxodCart As Boolean



'если нельзя подкинуть
If ((Form1.nKarta1K.COUNT + Form1.nKartKompa.COUNT) - Form1.nKarta1I.COUNT) = 0 _
Or Form1.nKartIgroka.COUNT = 0 _
Then IgrokPodkidivaet = False: Exit Function

    For Each bKarta In Form1.nKartIgroka
        For Each cKarta In Form1.nKarta1I
            If bKarta.Znachenie = cKarta.Znachenie Then
                MognSxodCart = True
            End If
        Next

        For Each cKarta In Form1.nKarta1K
            If bKarta.Znachenie = cKarta.Znachenie Then
                 MognSxodCart = True
            End If
        Next
            
            
    Next
'End If
    
    

IgrokPodkidivaet = MognSxodCart
End Function

Function ViigralIgrok() As Boolean

If Form1.nKoloda.COUNT = 0 And _
   Form1.nKartIgroka.COUNT = 0 Then
   
   MsgBox "Вы победили", vbInformation, "????????"
    
    
ViigralIgrok = True
Else
ViigralIgrok = False
End If

End Function

Function IgrokSnyal()
Dim nKarta As Karta
Dim i, j As Integer
'добавить в карты компа все ходившие карты

For i = 1 To Form1.nKarta1I.COUNT
        Set nKarta = Form1.nKarta1I(i)
        Form1.nKartIgroka.ADD nKarta.MAST, nKarta.Znachenie, _
        nKarta.ID, nKarta.NomImeg, nKarta.Xleft, nKarta.Ytop
        
    Form1.Image3(i - 1).Visible = False 'очищаю игровое поле
    Form1.Image4(i - 1).Visible = False
Next
    
For j = 1 To Form1.nKarta1K.COUNT
        Set nKarta = Form1.nKarta1K(j)
        Form1.nKartIgroka.ADD nKarta.MAST, nKarta.Znachenie, _
        nKarta.ID, nKarta.NomImeg, nKarta.Xleft, nKarta.Ytop
    
    Form1.Image3(j - 1).Visible = False 'очищаю игровое поле
    Form1.Image4(j - 1).Visible = False
Next

Set Form1.nKarta1I = Nothing
Set Form1.nKarta1K = Nothing
IgrokSnyal = 1
End Function

Function OtvetIgroka(Index) As Boolean 'ответил- 1. снял - 0

Dim bKarta As Karta
Dim cKarta As Karta
Dim i, j, k, m As Integer
Dim MognSxodCart As Boolean
'выдвижени карт - ход игрока

If Form1.nKarta1K.COUNT = Form1.nKarta1I.COUNT Then Exit Function

For Each bKarta In Form1.nKartIgroka
  
  If bKarta.NomImeg = Index Then
    
    If Form1.nKarta1K.COUNT <> 0 Then
    
    Set cKarta = Form1.nKarta1K.ITEM(Form1.nKarta1K.COUNT)
    
            If bKarta.Znachenie > cKarta.Znachenie _
                And bKarta.MAST = cKarta.MAST _
                Or bKarta.MAST = Form1.KOZIR Then
                MognSxodCart = True
            End If
            
            If bKarta.MAST = Form1.KOZIR And cKarta.MAST = Form1.KOZIR _
                And bKarta.Znachenie < cKarta.Znachenie Then
                MognSxodCart = False
            End If
        
    
    End If
    
    If MognSxodCart Then
    
        Unload Form1.Image1(bKarta.NomImeg)
        Form1.Image4(Form1.nKarta1I.COUNT).Picture = LoadResPicture(bKarta.MAST & bKarta.Znachenie, vbResBitmap)
         Form1.Image4(Form1.nKarta1I.COUNT).Visible = True
        Form1.Image4(Form1.nKarta1I.COUNT).Top = 2500
        Form1.Image4(Form1.nKarta1I.COUNT).Left = Form1.Image3(Form1.nKarta1K.COUNT - 1).Left '+ 150
            
        Form1.nKarta1I.ADD bKarta ', CStr(mKartIgroka.COUNT + 1)
        Form1.nKartIgroka.REMOVE (CStr(bKarta.ID))
    
    End If
    
    
    
  End If

Next

OtvetIgroka = MognSxodCart

End Function

Sub RaspologKartIgroka()

Dim bKarta As Karta
Dim nKarta As Karta
Dim i, j As Integer
Dim NmKartIgroka As New Collection
Dim MastKartIgroka As New Collection

If Form1.PoMast.Checked Then
'/////////////////////////////////////////////
Do While Form1.nKartIgroka.COUNT <> 0
    If Form1.nKartIgroka.COUNT = 0 Then Exit Sub 'корректность

    Set nKarta = Form1.nKartIgroka.ITEM(1)
    
    For Each bKarta In Form1.nKartIgroka
        If nKarta.Znachenie > bKarta.Znachenie Then
'
            
            Set nKarta = bKarta
        ElseIf nKarta.Znachenie = bKarta.Znachenie Then
            If nKarta.MAST = "BUB" Then GoTo met1
            If bKarta.MAST = "BUB" Then Set nKarta = bKarta: GoTo met1
            If nKarta.MAST = "CHERV" Then GoTo met1
            If bKarta.MAST = "CHERV" Then Set nKarta = bKarta: GoTo met1
            If nKarta.MAST = "KREST" Then GoTo met1
            If bKarta.MAST = "KREST" Then Set nKarta = bKarta: GoTo met1
            If nKarta.MAST = "PIC" Then GoTo met1
            If bKarta.MAST = "PIC" Then Set nKarta = bKarta: GoTo met1

met1:
Else

        End If
        
    Next
'Debug.Print nKarta.MAST & nKarta.Znachenie '/////////???/

    NmKartIgroka.ADD nKarta
    Form1.nKartIgroka.REMOVE (CStr(nKarta.ID))
Loop
'Debug.Print vbCrLf
'теперь распологаю по мастям и по значениям

j = Form1.nKartIgroka.COUNT

For i = 1 To NmKartIgroka.COUNT
    Set nKarta = NmKartIgroka.ITEM(i)
    Form1.nKartIgroka.ADD nKarta.MAST, nKarta.Znachenie, nKarta.ID, _
    nKarta.NomImeg, nKarta.Xleft, nKarta.Ytop
Next

Set NmKartIgroka = Nothing

Dim k, n As Integer

Do While Form1.nKartIgroka.COUNT <> 0
k = 1
'n = n + 1

    Set nKarta = Form1.nKartIgroka.ITEM(1)

    For Each bKarta In Form1.nKartIgroka
    
        
        If nKarta.MAST = bKarta.MAST _
           And nKarta.Znachenie = bKarta.Znachenie Or _
           nKarta.MAST = bKarta.MAST _
           And nKarta.Znachenie < bKarta.Znachenie Then
           
           'Set nKarta = bKarta
            MastKartIgroka.ADD bKarta
            Form1.nKartIgroka.REMOVE (CStr(bKarta.ID))
           
            
        End If
        k = k + 1
    Next
Loop

j = Form1.nKartIgroka.COUNT

For i = 1 To MastKartIgroka.COUNT

    Set nKarta = MastKartIgroka.ITEM(i)
  '  MsgBox nKarta.MAST & nKarta.Znachenie

    Form1.nKartIgroka.ADD nKarta.MAST, nKarta.Znachenie, nKarta.ID, _
    nKarta.NomImeg, nKarta.Xleft, nKarta.Ytop
Next

Set MastKartIgroka = Nothing


Else 'Form1.PoZnach.Checked=false
'/////////////////////////////////////////////////
Do While Form1.nKartIgroka.COUNT <> 0
    If Form1.nKartIgroka.COUNT = 0 Then Exit Sub 'корректность

    Set nKarta = Form1.nKartIgroka.ITEM(1)
    
    For Each bKarta In Form1.nKartIgroka
        If nKarta.Znachenie > bKarta.Znachenie Then
'
            
            Set nKarta = bKarta
        ElseIf nKarta.Znachenie = bKarta.Znachenie Then
            If nKarta.MAST = "BUB" Then GoTo met
            If bKarta.MAST = "BUB" Then Set nKarta = bKarta: GoTo met
            If nKarta.MAST = "CHERV" Then GoTo met
            If bKarta.MAST = "CHERV" Then Set nKarta = bKarta: GoTo met
            If nKarta.MAST = "KREST" Then GoTo met
            If bKarta.MAST = "KREST" Then Set nKarta = bKarta: GoTo met
            If nKarta.MAST = "PIC" Then GoTo met
            If bKarta.MAST = "PIC" Then Set nKarta = bKarta: GoTo met

met:
Else

        End If
        
    Next
    
    NmKartIgroka.ADD nKarta
    Form1.nKartIgroka.REMOVE (CStr(nKarta.ID))
Loop

j = Form1.nKartIgroka.COUNT

For i = 1 To NmKartIgroka.COUNT
    Set nKarta = NmKartIgroka.ITEM(i)
    Form1.nKartIgroka.ADD nKarta.MAST, nKarta.Znachenie, nKarta.ID, _
    nKarta.NomImeg, nKarta.Xleft, nKarta.Ytop
Next

Set NmKartIgroka = Nothing

End If

End Sub
Sub UnichtogitKartiIgroka()
Dim mKarta As Karta
Dim i As Integer

For Each mKarta In Form1.nKartIgroka
    i = i + 1
    Set mKarta = Form1.nKartIgroka.ITEM(i)
    'MsgBox mKarta.MAST & mKarta.Znachenie
    
    Unload Form1.Image1(mKarta.NomImeg)
  
Next
End Sub
'
'
Function XodIgroka(Index As Integer) As Boolean '1 -игрок сходил, 0 - игрок не сходил
Dim bKarta As Karta
Dim cKarta As Karta
Dim i, j, k, m As Integer
Dim MognSxodCart As Boolean

'выдвижени карт - ход игрока
'MsgBox Form1.nKartIgroka.COUNT
 
For Each bKarta In Form1.nKartIgroka
 
 'MsgBox bKarta.MAST & bKarta.Znachenie
   'Выход если уже 6 раз сходил
 If Form1.nKarta1I.COUNT = 6 Then Exit For
 
  If bKarta.NomImeg = Index Then
    
    If Form1.nKarta1I.COUNT <> 0 Then

       

        For Each cKarta In Form1.nKarta1I
            If bKarta.Znachenie = cKarta.Znachenie Then
                MognSxodCart = True
            End If
        Next

        For Each cKarta In Form1.nKarta1K
            If bKarta.Znachenie = cKarta.Znachenie Then
                 MognSxodCart = True
            End If
        Next
        
        If MognSxodCart = False Then Exit Function
    End If

    
    'удаляю карту игрока, создаю карту игрового поля
    
     Unload Form1.Image1(bKarta.NomImeg)
    ' Load Form1.Image3(bKarta.NomImeg)
      Form1.Image3(Form1.nKarta1I.COUNT).Picture = LoadResPicture(bKarta.MAST & bKarta.Znachenie, vbResBitmap)
     Form1.Image3(Form1.nKarta1I.COUNT).Visible = True
     Form1.Image3(Form1.nKarta1I.COUNT).Top = 2500
        
       Select Case Form1.nKarta1I.COUNT
            Case Is = 0
                Form1.Image3(Form1.nKarta1I.COUNT).Left = 1200 + 100
            Case Is = 1
                Form1.Image3(Form1.nKarta1I.COUNT).Left = 2265 + 100
            Case Is = 2
                Form1.Image3(Form1.nKarta1I.COUNT).Left = 3330 + 100
            Case Is = 3
                Form1.Image3(Form1.nKarta1I.COUNT).Left = 4395 + 100
            Case Is = 4
                Form1.Image3(Form1.nKarta1I.COUNT).Left = 5460 + 100
            Case Is = 5
                Form1.Image3(Form1.nKarta1I.COUNT).Left = 6525 + 100
        End Select
        
        Form1.nKarta1I.ADD bKarta
        Form1.nKartIgroka.REMOVE (CStr(bKarta.ID))
   'Call PlaySound(App.Path & "\Zvuki\CUCKOO01", 0&, 3)


    End If

XodIgroka = MognSxodCart

Next


End Function
Sub PokazatKartiIgroka()

Dim KolKartRazdIgr As Integer
Dim mKarta As Karta
Dim i, j As Integer
Dim nL, nT, L, T As Integer 'координаты карт
Dim ZnahDlyaRasprKart As Integer
Dim LmegKart As Integer
Dim k As Double
nL = 120
nT = 2025

L = 1200
T = 4300

If Form1.nKartIgroka.COUNT = 0 Then Exit Sub 'корректность

ZnahDlyaRasprKart = (Form1.nKartIgroka.COUNT - 1)
If ZnahDlyaRasprKart = 0 Then ZnahDlyaRasprKart = 1
LmegKart = 5325 / ZnahDlyaRasprKart

For Each mKarta In Form1.nKartIgroka
'//////////Делаю расположен по маст по месту//////
    'выбор места по масти
'If Form1.PoMast.Checked = True Then
'
'End If
'/////////////
    Load Form1.Image1(mKarta.NomImeg)

    Form1.Image1(mKarta.NomImeg).Top = nT
    Form1.Image1(mKarta.NomImeg).Left = nL
    Form1.Image1(mKarta.NomImeg).Picture = LoadResPicture(mKarta.MAST & mKarta.Znachenie, vbResBitmap)
    Form1.Image1(mKarta.NomImeg).Visible = True
'<<<<<<<< move karti >>>>>>>>
 ''For i = 0 To (L - nL) Step L / nL
' j = j + (T - nT) / (L / nL)

'    If Form1.dva.Checked Then
'      Call PlaySound(App.Path & "\Zvuki\CUCKOO01", 0&, 3)
'    End If
'
    Form1.Image1(mKarta.NomImeg).Move L, T
    
    
    For k = 0 To Form1.IntervalRazdachiKart
    Next k
    
      
      
'' Next i
            L = L + LmegKart

Next

Exit Sub
'er1:
'MsgBox mKarta.MAST & mKarta.Znachenie
'Resume Next

End Sub

 Sub RazdatKartiIgrocu()
Dim i As Integer
Dim mKarta As Karta
Dim KolKartRazdIgr As Integer

'If Form1.nKartIgroka.COUNT >= 6 Then
'MsgBox "Form1.nKartKompa.COUNT > =6"
'End If


If 6 - Form1.nKartIgroka.COUNT > 0 Then 'сколько _
карт нужно раздать игроку
    KolKartRazdIgr = 6 - Form1.nKartIgroka.COUNT
Else
    KolKartRazdIgr = 0
End If



For i = KolKartRazdIgr To 1 Step -1

    If Form1.nKoloda.COUNT = 0 Then Exit Sub
    
    Set mKarta = Form1.nKoloda.ITEM(CStr(Form1.nKoloda.COUNT))
    Form1.nKoloda.REMOVE (CStr(Form1.nKoloda.COUNT))
    
    Form1.nKartIgroka.ADD mKarta.MAST, mKarta.Znachenie, mKarta.ID, _
    mKarta.NomImeg, mKarta.Xleft, mKarta.Ytop

Next i

End Sub

Private Sub Class_Initialize()
Set nKartIgroka = New Collection
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
nKartIgroka.ADD nKarta, CStr(.ID)

End With
End Function

Public Function ITEM(Index)
Set ITEM = nKartIgroka.ITEM(Index)
End Function

Public Property Get NewEnum() As IUnknown
Attribute NewEnum.VB_UserMemId = -4
Attribute NewEnum.VB_MemberFlags = "40"
    Set NewEnum = nKartIgroka.[_NewEnum]
End Property
Public Function COUNT()
COUNT = nKartIgroka.COUNT
End Function
Public Function REMOVE(Index)
nKartIgroka.REMOVE (Index)
End Function
'Sub PokazatKartiIgroka()
'
'Dim KolKartRazdIgr As Integer
'Dim mKarta As Karta
'Dim i As Integer
'Dim L, T As Integer 'координаты карт
'Dim ZnahDlyaRasprKart As Integer
'Dim LmegKart As Integer
'
'L = 1200
'T = 4300
'
'If Form1.nKartIgroka.COUNT = 0 Then Exit Sub 'корректность
'
'ZnahDlyaRasprKart = (Form1.nKartIgroka.COUNT - 1)
'If ZnahDlyaRasprKart = 0 Then ZnahDlyaRasprKart = 1
'LmegKart = 5325 / ZnahDlyaRasprKart
'
'For Each mKarta In Form1.nKartIgroka
''//////////Делаю расположен по маст по месту//////
'    'выбор места по масти
''If Form1.PoMast.Checked = True Then
''
''
''End If
'
''/////////////
'    Load Form1.Image1(mKarta.NomImeg)
'
'    Form1.Image1(mKarta.NomImeg).Top = T
'    Form1.Image1(mKarta.NomImeg).Left = L
'    Form1.Image1(mKarta.NomImeg).Picture = LoadResPicture(mKarta.MAST & mKarta.Znachenie, vbResBitmap)
'    Form1.Image1(mKarta.NomImeg).Visible = True
'            L = L + LmegKart
'
'Next
'
'Exit Sub
''er1:
''MsgBox mKarta.MAST & mKarta.Znachenie
''Resume Next
'
'End Sub
'

