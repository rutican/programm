VERSION 1.0 CLASS
BEGIN
  MultiUse = -1  'True
  Persistable = 0  'NotPersistable
  DataBindingBehavior = 0  'vbNone
  DataSourceBehavior  = 0  'vbNone
  MTSTransactionMode  = 0  'NotAnMTSObject
END
Attribute VB_Name = "ColKnopok"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = True
Attribute VB_PredeclaredId = False
Attribute VB_Exposed = False
Option Explicit
Dim nColKnopok As Collection

Private Sub Class_Initialize()
Set nColKnopok = New Collection
End Sub
Public Function ADD(ByVal KorZentCnopX As Integer, ByVal KorZentCnopY As Integer, ID As Integer)
Dim nKnopka As Knopka
Set nKnopka = New Knopka

With nKnopka

.ID = ID
.KorZentCnopX = KorZentCnopX
.KorZentCnopY = KorZentCnopY
nColKnopok.ADD nKnopka, CStr(.ID)

End With
End Function

Public Function ITEM(Index)
Set ITEM = nColKnopok.ITEM(Index)
End Function

Public Property Get NewEnum() As IUnknown
Attribute NewEnum.VB_UserMemId = -4
Attribute NewEnum.VB_MemberFlags = "40"
    Set NewEnum = nColKnopok.[_NewEnum]
End Property
Public Function COUNT()
COUNT = nColKnopok.COUNT
End Function
Public Function REMOVE(Index)
nColKnopok.REMOVE (Index)
End Function
