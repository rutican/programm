VERSION 1.0 CLASS
BEGIN
  MultiUse = -1  'True
  Persistable = 0  'NotPersistable
  DataBindingBehavior = 0  'vbNone
  DataSourceBehavior  = 0  'vbNone
  MTSTransactionMode  = 0  'NotAnMTSObject
END
Attribute VB_Name = "KartKompa"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = True
Attribute VB_PredeclaredId = False
Attribute VB_Exposed = False
Option Explicit

Dim nKartKompa As Collection
Private Declare Function PlaySound Lib "winmm.dll" Alias "PlaySoundA" (ByVal lpszName As String, ByVal hModule As Long, ByVal dwFlags As Long) As Long


Function KompPodkidivaet() As Boolean '1 -подкидывает 0- нет

Dim i As Integer
Dim bKarta As Karta
Dim cKarta As Karta
Dim MognSxodCart As Boolean
Dim colDlyaPodkidivaniya As New Collection

'если нельзя подкинуть
If ((Form1.nKarta1I.COUNT + Form1.nKartIgroka.COUNT) - Form1.nKarta1K.COUNT) = 0 _
Then KompPodkidivaet = False: Exit Function


If Form1.nKarta1K.COUNT = 0 Then KompPodkidivaet = False: Exit Function
    For Each bKarta In Form1.nKartKompa
    
        For Each cKarta In Form1.nKarta1I
            If bKarta.Znachenie = cKarta.Znachenie _
            And bKarta.Znachenie <= 10 And bKarta.MAST <> Form1.KOZIR Then
                MognSxodCart = True
            End If
        Next

        For Each cKarta In Form1.nKarta1K
            If bKarta.Znachenie = cKarta.Znachenie _
            And bKarta.Znachenie <= 10 And bKarta.MAST <> Form1.KOZIR Then
                 MognSxodCart = True
            End If
        Next
                    
         colDlyaPodkidivaniya.ADD bKarta
    Next
    
  If MognSxodCart Then
    MsgBox "Я подкидываю!", vbInformation, "Компьютер"
  
  End If
  
Set colDlyaPodkidivaniya = Nothing
    

KompPodkidivaet = MognSxodCart

End Function
Function ViigralKomp() As Boolean

If Form1.nKoloda.COUNT = 0 And _
   Form1.nKartKompa.COUNT = 0 Then
   
   MsgBox "Вы проиграли!", vbInformation, "!!!!!!!!"
ViigralKomp = True
Else
ViigralKomp = False
End If
End Function

Sub UnishtogitKartiKompa()

Dim mKarta As Karta
Dim i As Integer


If Form1.nKartKompa.COUNT = 0 Then Exit Sub
'Exit Sub
For Each mKarta In Form1.nKartKompa
    i = i + 1
    Set mKarta = Form1.nKartKompa.ITEM(i)
    Unload Form1.Image2(mKarta.NomImeg)
Next

End Sub
Function KompShyal() As Boolean

Dim nKarta As Karta
Dim dKarta As Karta
Dim i, j As Integer

If Form1.nKarta1K.COUNT = Form1.nKarta1I.COUNT Then Exit Function
'/////////////////////otladka

'//////////////////
For i = 1 To Form1.nKarta1I.COUNT
    Set nKarta = Form1.nKarta1I(i)
    
          Form1.nKartKompa.ADD nKarta.MAST, nKarta.Znachenie, _
        nKarta.ID, nKarta.NomImeg, nKarta.Xleft, nKarta.Ytop
        
        Form1.Image3(i - 1).Visible = False 'очищаю игровое поле
        Form1.Image4(i - 1).Visible = False
     
Next

For j = 1 To Form1.nKarta1K.COUNT
    Set nKarta = Form1.nKarta1K(j)
    
    'Form1.ChtoMognoPodkinut.ADD nKarta 'cоздается для подкидывания
    
     Form1.nKartKompa.ADD nKarta.MAST, nKarta.Znachenie, _
    nKarta.ID, nKarta.NomImeg, nKarta.Xleft, nKarta.Ytop

    Form1.Image3(j - 1).Visible = False 'очищаю игровое поле
    Form1.Image4(j - 1).Visible = False
Next

Set Form1.nKarta1I = Nothing
Set Form1.nKarta1K = Nothing


KompShyal = True
Form1.Command1.Caption = ""
End Function

Function XodKompa() As Boolean 'возвр 1 если сходил, 0 елсли нет

Dim bKarta As Karta
Dim cKarta As Karta

Dim KartaDlaXoda As New Karta
Dim EstChemXodit As Boolean
Dim MognSxodCart As Boolean
Dim OdniKoziri As Boolean ' 1- одни козыри

If Form1.nKartKompa.COUNT = 0 Then Exit Function 'карт нет у компа

If Form1.nKarta1K.COUNT = 0 Then
'Делает первый ход

    For Each bKarta In Form1.nKartKompa 'Выбираю любую не козырную карту
     If bKarta.MAST <> Form1.KOZIR Then
        Set KartaDlaXoda = bKarta
        OdniKoziri = False
        Exit For
     End If
     OdniKoziri = True
    Next
    
    If OdniKoziri Then ' все козыри - выбрать младший
        Set KartaDlaXoda = Form1.nKartKompa.ITEM(Form1.nKartKompa.COUNT)
        
        For Each bKarta In Form1.nKartKompa
        'Debug.Print bKarta.Znachenie & bKarta.MAST
            If bKarta.Znachenie < KartaDlaXoda.Znachenie Then
                Set KartaDlaXoda = bKarta
                MognSxodCart = True
            Else
                MognSxodCart = True
            End If
        Next
    
    
    Else 'не все козыри
        For Each bKarta In Form1.nKartKompa
        'Debug.Print bKarta.Znachenie & bKarta.MAST
            If bKarta.Znachenie < KartaDlaXoda.Znachenie _
              And bKarta.MAST <> Form1.KOZIR Then
                Set KartaDlaXoda = bKarta
                MognSxodCart = True
            Else
                MognSxodCart = True
            End If
        
        Next
    
    End If
End If
'///////////////Второй и остальные ходы
If Form1.nKarta1K.COUNT <> 0 Then

    For Each cKarta In Form1.nKartKompa

        For Each bKarta In Form1.nKarta1K
                If cKarta.Znachenie = bKarta.Znachenie _
                And cKarta.MAST <> Form1.KOZIR Then
                    MognSxodCart = True
                    Set KartaDlaXoda = cKarta
                End If
        Next

    For Each bKarta In Form1.nKarta1I
        If cKarta.Znachenie = bKarta.Znachenie _
        And cKarta.MAST <> Form1.KOZIR Then
            MognSxodCart = True
            Set KartaDlaXoda = cKarta
        End If
    Next

Next




End If
'//////////////////////////////////


'If Form1.nKarta1I.COUNT < Form1.nKarta1K.COUNT Then Exit Function 'не ходить, если
''If Form1.nKartKompa.COUNT = 0 Then Exit Sub
'
'Set KartaDlaXoda = Form1.nKartKompa.ITEM(Form1.nKartKompa.COUNT)
'
''KartaDlaXoda.Znachenie = 15
'
'For Each bKarta In Form1.nKartKompa
''Debug.Print bKarta.Znachenie & bKarta.MAST
'    If bKarta.Znachenie < KartaDlaXoda.Znachenie _
'    And bKarta.MAST <> Form1.KOZIR Then
'        Set KartaDlaXoda = bKarta
'         MognSxodCart = True
'    End If
'
'Next
'
'If EstChemXodit = False Then
'    For Each bKarta In Form1.nKartKompa
'        If bKarta.Znachenie <= KartaDlaXoda.Znachenie Then
'        Set KartaDlaXoda = bKarta
'         MognSxodCart = True
'         End If
'    Next
'End If
'
'
'If Form1.nKarta1K.COUNT <> 0 Then
'
'For Each cKarta In Form1.nKartKompa
'
'        For Each bKarta In Form1.nKarta1K
'                If cKarta.Znachenie = bKarta.Znachenie Then
'                    MognSxodCart = True
'                    Set KartaDlaXoda = cKarta
'                End If
'        Next
'
'    For Each bKarta In Form1.nKarta1I
'        If cKarta.Znachenie = bKarta.Znachenie Then
'            MognSxodCart = True
'            Set KartaDlaXoda = cKarta
'        End If
'    Next
'
'Next
'
'
'
'For Each cKarta In Form1.nKartKompa
'
'    For Each bKarta In Form1.nKarta1K
'        If cKarta.Znachenie = bKarta.Znachenie And _
'            cKarta.MAST <> Form1.KOZIR Then
'            MognSxodCart = True
'            Set KartaDlaXoda = cKarta
'        Else
'            MognSxodCart = False
'        End If
'
'
'    Next
'
'    For Each bKarta In Form1.nKarta1I
'        If cKarta.Znachenie = bKarta.Znachenie And _
'             cKarta.MAST <> Form1.KOZIR Then
'            MognSxodCart = True
'            Set KartaDlaXoda = cKarta
'        Else
'            'MognSxodCart = False
'        End If
'    Next
'Next
'
'    'If MognSxodCart = False Then Call Bito: Exit Sub
'
'End If


'/////////////////////////////////////////

    If MognSxodCart = True Then
    
       Unload Form1.Image2(KartaDlaXoda.NomImeg)
       Form1.Image3(Form1.nKarta1K.COUNT).Picture = LoadResPicture(KartaDlaXoda.MAST & KartaDlaXoda.Znachenie, vbResBitmap)
       Form1.Image3(Form1.nKarta1K.COUNT).Visible = True
       Form1.Image3(Form1.nKarta1K.COUNT).Top = 2000
         
         Select Case Form1.nKarta1K.COUNT
               Case Is = 0
                  Form1.Image3(Form1.nKarta1K.COUNT).Left = 1200
               Case Is = 1
                   Form1.Image3(Form1.nKarta1K.COUNT).Left = 2220
               Case Is = 2
                   Form1.Image3(Form1.nKarta1K.COUNT).Left = 3240
               Case Is = 3
                 Form1.Image3(Form1.nKarta1K.COUNT).Left = 4260
               Case Is = 4
                   Form1.Image3(Form1.nKarta1K.COUNT).Left = 5280
               Case Is = 5
                  Form1.Image3(Form1.nKarta1K.COUNT).Left = 6300
           End Select
       
        '  Call PlaySound(App.Path & "\Zvuki\POP003", 0&, 3)

       Form1.nKarta1K.ADD KartaDlaXoda ', CStr(mKartKompa.COUNT + 1)
       Form1.nKartKompa.REMOVE (CStr(KartaDlaXoda.ID))

    End If
If MognSxodCart Then _
Form1.Command1.Caption = "Снять"

XodKompa = MognSxodCart
End Function

'
Function OtvetKompa() As Boolean 'возвращает 1 если сходил 0- если нет
Dim bKarta As Karta
Dim iKarta As Karta ' карта чтобы вытаскивать из коллекции ходов игрока
Dim KartaDlaXoda As Karta

Dim BilOtvetIgroku As Boolean
Dim i, j As Integer
Dim KartDlyaBitya As New KartKompa
Dim EstLiChemOtvetit As Boolean

'ход компа
If Form1.nKarta1I.COUNT = Form1.nKarta1K.COUNT _
Then OtvetKompa = True: Exit Function 'не ходить, если

'//////////////////////////
'cоздаю коллекцию с картами, которыми можно бить
Set iKarta = Form1.nKarta1I(Form1.nKarta1I.COUNT)

For Each bKarta In Form1.nKartKompa
    If bKarta.MAST = iKarta.MAST _
        And bKarta.Znachenie > iKarta.Znachenie Then
        
        KartDlyaBitya.ADD bKarta.MAST, bKarta.Znachenie _
        , bKarta.ID, bKarta.NomImeg, 0, 0
        
    End If
Next

If KartDlyaBitya.COUNT > 0 Then

    For Each bKarta In KartDlyaBitya
        Set KartaDlaXoda = bKarta
        Exit For
    Next
    
    For Each bKarta In KartDlyaBitya
        'Debug.Print bKarta.Znachenie & bKarta.MAST
            If bKarta.Znachenie > KartaDlaXoda.Znachenie _
              And bKarta.MAST <> Form1.KOZIR Then
                Set KartaDlaXoda = bKarta
                BilOtvetIgroku = True
            Else
                BilOtvetIgroku = True
            End If
            '/////////////
            
    Next

Else 'выбрать для битья козыри, если нечем бить из простых карт

    For Each bKarta In Form1.nKartKompa
        If bKarta.MAST = Form1.KOZIR Then
            KartDlyaBitya.ADD bKarta.MAST, bKarta.Znachenie _
            , bKarta.ID, bKarta.NomImeg, 0, 0
        End If
    Next
    
    For Each bKarta In KartDlyaBitya
        Set KartaDlaXoda = bKarta
        Exit For
    Next
    
'/////////////Проверить какую карту бить козырную или простую

     Set iKarta = Form1.nKarta1I(Form1.nKarta1I.COUNT)
  If iKarta.MAST = Form1.KOZIR Then
     
     For Each bKarta In KartDlyaBitya
        'Debug.Print bKarta.Znachenie & bKarta.MAST
            If iKarta.Znachenie < bKarta.Znachenie _
               Then
                Set KartaDlaXoda = bKarta
                BilOtvetIgroku = True
            End If
    Next
     
  Else   ' Бью некозырную карту
    For Each bKarta In KartDlyaBitya
        'Debug.Print bKarta.Znachenie & bKarta.MAST
            If bKarta.Znachenie < KartaDlaXoda.Znachenie _
               Then
                Set KartaDlaXoda = bKarta
                BilOtvetIgroku = True
            Else
                BilOtvetIgroku = True
            End If
    Next
 End If ' конец проверки карты козырь-некозырь
End If

'//////////////////////////////////
' Set iKarta = Form1.nKarta1I(Form1.nKarta1I.COUNT) 'CStr(1))
'
'For Each bKarta In Form1.nKartKompa
'
'    If bKarta.MAST = iKarta.MAST _
'        And bKarta.Znachenie > iKarta.Znachenie Then
'
'        Unload Form1.Image2(bKarta.NomImeg)
'        Form1.Image4(Form1.nKarta1K.COUNT).Picture = LoadResPicture(bKarta.MAST & bKarta.Znachenie, vbResBitmap)
'        Form1.Image4(Form1.nKarta1K.COUNT).Visible = True
'        Form1.Image4(Form1.nKarta1K.COUNT).Top = 2000
'        Form1.Image4(Form1.nKarta1K.COUNT).Left = Form1.Image3(Form1.nKarta1I.COUNT - 1).Left '+ 50
'
'        Form1.nKarta1K.ADD bKarta ', CStr(mKartKompa.COUNT + 1)
'        Form1.nKartKompa.REMOVE (CStr(bKarta.ID))
'        'находит перв карту и выходит
'        BilOtvetIgroku = True
'        Exit For
'    End If
'
'Next
'
'If Not BilOtvetIgroku Then ' ответа не было
'
'For Each bKarta In Form1.nKartKompa
' ' Set iKarta = nKarta1I(6 - mKartIgroka.COUNT) 'CStr(1))
'
'    If bKarta.MAST = Form1.KOZIR And iKarta.MAST <> Form1.KOZIR Or _
'        bKarta.MAST = Form1.KOZIR And bKarta.Znachenie > iKarta.Znachenie _
'        And iKarta.MAST = Form1.KOZIR Then
'
'    Unload Form1.Image2(bKarta.NomImeg)
'
'    Form1.Image4(Form1.nKarta1K.COUNT).Picture = LoadResPicture(bKarta.MAST & bKarta.Znachenie, vbResBitmap)
'    Form1.Image4(Form1.nKarta1K.COUNT).Visible = True
'    Form1.Image4(Form1.nKarta1K.COUNT).Top = 2000
'    Form1.Image4(Form1.nKarta1K.COUNT).Left = Form1.Image3(Form1.nKarta1I.COUNT - 1).Left + 50
'   ' Form1.Image4(Form1.nKarta1K.COUNT).Visible = True
'    Form1.nKarta1K.ADD bKarta ', CStr(mKartKompa.COUNT + 1)
'    Form1.nKartKompa.REMOVE (CStr(bKarta.ID))
'
'        'находит перв карту и выходит
'        BilOtvetIgroku = True
'        Exit For
'    End If
'
'Next
'
'End If

'/////////////////////////////////////
If BilOtvetIgroku Then
        Unload Form1.Image2(KartaDlaXoda.NomImeg)
        Form1.Image4(Form1.nKarta1K.COUNT).Picture = LoadResPicture(KartaDlaXoda.MAST & KartaDlaXoda.Znachenie, vbResBitmap)
        Form1.Image4(Form1.nKarta1K.COUNT).Visible = True
        Form1.Image4(Form1.nKarta1K.COUNT).Top = 2000
        Form1.Image4(Form1.nKarta1K.COUNT).Left = Form1.Image3(Form1.nKarta1I.COUNT - 1).Left '+ 50

        Form1.nKarta1K.ADD KartaDlaXoda ', CStr(mKartKompa.COUNT + 1)
        '///////////
'        Dim oKarta As Karta
'        Set oKarta = Form1.nKarta1K.ITEM(1)
'        MsgBox oKarta.MAST & oKarta.Znachenie
        '////////
        Form1.nKartKompa.REMOVE (CStr(KartaDlaXoda.ID))
End If

    OtvetKompa = BilOtvetIgroku

If Not OtvetKompa Then _
MsgBox "Я снимаю!", vbInformation, "Компьютер"

End Function

Sub PokazatKartiKompa()

Dim KolKartRazdKompu As Integer
Dim mKarta As Karta
Dim i As Integer
Dim nL, nT, L, T As Integer 'координаты карт
Dim NRub As Integer
Dim LmegKart As Integer
Dim ZnahDlyaRasprKart As Integer
Dim k As Double

If Form1.Rubaska Then
    NRub = 101
Else
    NRub = 102
End If

nL = 120
nT = 2025

L = 1200
T = 150
   
'???/If Form1.nKartIgroka.COUNT = 0 Then Exit Sub 'корректность

ZnahDlyaRasprKart = (Form1.nKartKompa.COUNT - 1)
If ZnahDlyaRasprKart = 0 Then ZnahDlyaRasprKart = 1

LmegKart = 5325 / ZnahDlyaRasprKart

For Each mKarta In Form1.nKartKompa
    'i = i + 1
     
    KolKartRazdKompu = Form1.nKartKompa.COUNT
    'Set mKarta = Form1.nKartKompa.ITEM(i)
    
   
    Load Form1.Image2(mKarta.NomImeg)
    'LmegKart = Form1.Image2(mKarta.NomImeg).Width * 6 / KolKartRazdKompu
  
    Form1.Image2(mKarta.NomImeg).Top = nT
    Form1.Image2(mKarta.NomImeg).Left = nL
    Form1.Image2(mKarta.NomImeg).Picture = LoadResPicture(NRub, vbResBitmap)
    Form1.Image2(mKarta.NomImeg).Visible = True
    
'    If Form1.dva.Checked Then
'    Call PlaySound(App.Path & "\Zvuki\CUCKOO01", 0&, 3)
'    End If
    
    Form1.Image2(mKarta.NomImeg).Move L, T
    
    
    For k = 0 To Form1.IntervalRazdachiKart
    Next k
    
            L = L + LmegKart
    
Next

End Sub

Sub RazdatKartiCompu()

Dim i As Integer
Dim mKarta As Karta
Dim KolKartRazdKompu As Integer

'If Form1.nKartKompa.COUNT > 6 Then
'MsgBox "Form1.nKartKompa.COUNT > 6"
'End If


If 6 - Form1.nKartKompa.COUNT > 0 Then 'сколько _
карт нужно раздать компьютеру
    KolKartRazdKompu = 6 - Form1.nKartKompa.COUNT
Else
    KolKartRazdKompu = 0
End If

For i = KolKartRazdKompu To 1 Step -1
'MsgBox Form1.nKoloda.COUNT
If Form1.nKoloda.COUNT = 0 Then Exit Sub

    Set mKarta = Form1.nKoloda.ITEM(CStr(Form1.nKoloda.COUNT))
    Form1.nKoloda.REMOVE (CStr(Form1.nKoloda.COUNT))
    Form1.nKartKompa.ADD mKarta.MAST, mKarta.Znachenie, mKarta.ID, _
    mKarta.NomImeg, mKarta.Xleft, mKarta.Ytop
'Debug.Print mKarta.Znachenie & mKarta.MAST
Next
'//////////////////////////
'Dim dKarta As Karta
'Form2.List1.Clear
'For Each dKarta In Form1.nKartKompa
'Form2.List1.AddItem dKarta.Znachenie & dKarta.MAST
'Next
'del//////////////

End Sub
Private Sub Class_Initialize()
Set nKartKompa = New Collection
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
nKartKompa.ADD nKarta, CStr(.ID)

End With
End Function

Public Function ITEM(Index)
Set ITEM = nKartKompa.ITEM(Index)
End Function

Public Property Get NewEnum() As IUnknown
Attribute NewEnum.VB_UserMemId = -4
Attribute NewEnum.VB_MemberFlags = "40"
    Set NewEnum = nKartKompa.[_NewEnum]
End Property
Public Function COUNT()
COUNT = nKartKompa.COUNT
End Function
Public Function REMOVE(Index)
nKartKompa.REMOVE (Index)
End Function

