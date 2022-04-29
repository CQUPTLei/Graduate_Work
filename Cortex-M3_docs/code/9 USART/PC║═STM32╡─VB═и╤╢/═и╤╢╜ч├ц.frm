VERSION 5.00
Object = "{648A5603-2C6E-101B-82B6-000000000014}#1.1#0"; "MSCOMM32.OCX"
Begin VB.Form Form1 
   Caption         =   "单片机与PC机通讯"
   ClientHeight    =   9015
   ClientLeft      =   120
   ClientTop       =   450
   ClientWidth     =   13695
   Icon            =   "通讯界面.frx":0000
   LinkTopic       =   "Form1"
   MaxButton       =   0   'False
   ScaleHeight     =   9015
   ScaleWidth      =   13695
   StartUpPosition =   3  '窗口缺省
   Begin VB.Timer Timer1 
      Interval        =   1000
      Left            =   12600
      Top             =   8160
   End
   Begin VB.ComboBox cboPort 
      BeginProperty Font 
         Name            =   "宋体"
         Size            =   10.5
         Charset         =   134
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   330
      Left            =   10680
      TabIndex        =   22
      Text            =   "Combo1"
      Top             =   1560
      Width           =   1575
   End
   Begin VB.TextBox Text1 
      BeginProperty Font 
         Name            =   "宋体"
         Size            =   15
         Charset         =   134
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      ForeColor       =   &H000000FF&
      Height          =   615
      Index           =   0
      Left            =   2160
      TabIndex        =   18
      Top             =   1440
      Width           =   2535
   End
   Begin VB.CommandButton Command3 
      Caption         =   "发送时间"
      BeginProperty Font 
         Name            =   "宋体"
         Size            =   14.25
         Charset         =   134
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   735
      Left            =   9840
      TabIndex        =   17
      Top             =   7920
      Width           =   1935
   End
   Begin VB.CommandButton Command2 
      Caption         =   "退出"
      BeginProperty Font 
         Name            =   "宋体"
         Size            =   15.75
         Charset         =   134
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   735
      Left            =   5880
      TabIndex        =   16
      Top             =   7920
      Width           =   2055
   End
   Begin VB.CommandButton Command1 
      Caption         =   "保存"
      BeginProperty Font 
         Name            =   "宋体"
         Size            =   15.75
         Charset         =   134
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   735
      Left            =   2160
      TabIndex        =   15
      Top             =   7920
      Width           =   2055
   End
   Begin MSCommLib.MSComm MSComm1 
      Left            =   360
      Top             =   7920
      _ExtentX        =   1005
      _ExtentY        =   1005
      _Version        =   393216
      DTREnable       =   -1  'True
   End
   Begin VB.CheckBox Check1 
      Caption         =   "继电器 5"
      BeginProperty Font 
         Name            =   "宋体"
         Size            =   15.75
         Charset         =   134
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      ForeColor       =   &H00FF0000&
      Height          =   855
      Index           =   4
      Left            =   5520
      TabIndex        =   14
      Top             =   6360
      Width           =   2295
   End
   Begin VB.CheckBox Check1 
      Caption         =   "继电器 4"
      BeginProperty Font 
         Name            =   "宋体"
         Size            =   15.75
         Charset         =   134
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      ForeColor       =   &H00FF0000&
      Height          =   855
      Index           =   3
      Left            =   5520
      TabIndex        =   13
      Top             =   5100
      Width           =   2415
   End
   Begin VB.CheckBox Check1 
      Caption         =   "继电器 3"
      BeginProperty Font 
         Name            =   "宋体"
         Size            =   15.75
         Charset         =   134
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      ForeColor       =   &H00FF0000&
      Height          =   855
      Index           =   2
      Left            =   5520
      TabIndex        =   12
      Top             =   3840
      Width           =   2055
   End
   Begin VB.CheckBox Check1 
      Caption         =   "继电器 2"
      BeginProperty Font 
         Name            =   "宋体"
         Size            =   15.75
         Charset         =   134
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      ForeColor       =   &H00FF0000&
      Height          =   855
      Index           =   1
      Left            =   5520
      TabIndex        =   11
      Top             =   2580
      Width           =   2175
   End
   Begin VB.CheckBox Check1 
      Caption         =   "继电器 1"
      BeginProperty Font 
         Name            =   "宋体"
         Size            =   15.75
         Charset         =   134
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      ForeColor       =   &H00FF0000&
      Height          =   855
      Index           =   0
      Left            =   5520
      TabIndex        =   9
      Top             =   1320
      Width           =   1935
   End
   Begin VB.TextBox Text1 
      BeginProperty Font 
         Name            =   "宋体"
         Size            =   15
         Charset         =   134
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      ForeColor       =   &H000000FF&
      Height          =   615
      Index           =   4
      Left            =   2160
      TabIndex        =   3
      Top             =   6480
      Width           =   2535
   End
   Begin VB.TextBox Text1 
      BeginProperty Font 
         Name            =   "宋体"
         Size            =   15
         Charset         =   134
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      ForeColor       =   &H000000FF&
      Height          =   615
      Index           =   3
      Left            =   2160
      TabIndex        =   2
      Top             =   5220
      Width           =   2535
   End
   Begin VB.TextBox Text1 
      BeginProperty Font 
         Name            =   "宋体"
         Size            =   15
         Charset         =   134
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      ForeColor       =   &H000000FF&
      Height          =   615
      Index           =   2
      Left            =   2160
      TabIndex        =   1
      Top             =   3960
      Width           =   2535
   End
   Begin VB.TextBox Text1 
      BeginProperty Font 
         Name            =   "宋体"
         Size            =   15
         Charset         =   134
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      ForeColor       =   &H000000FF&
      Height          =   615
      Index           =   1
      Left            =   2160
      TabIndex        =   0
      Top             =   2700
      Width           =   2535
   End
   Begin VB.Label Label13 
      Caption         =   "当前时间"
      BeginProperty Font 
         Name            =   "宋体"
         Size            =   42
         Charset         =   134
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      ForeColor       =   &H000000C0&
      Height          =   1095
      Left            =   8640
      TabIndex        =   25
      Top             =   5040
      Width           =   4335
   End
   Begin VB.Label Label11 
      Caption         =   "当前时间："
      BeginProperty Font 
         Name            =   "宋体"
         Size            =   15.75
         Charset         =   134
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      ForeColor       =   &H00C00000&
      Height          =   375
      Left            =   9480
      TabIndex        =   24
      Top             =   3960
      Width           =   1695
   End
   Begin VB.Label cmdOpenCom 
      Caption         =   "串行状态"
      BeginProperty Font 
         Name            =   "宋体"
         Size            =   14.25
         Charset         =   134
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      ForeColor       =   &H00FF0000&
      Height          =   375
      Left            =   10680
      TabIndex        =   23
      Top             =   2760
      Width           =   1695
   End
   Begin VB.Shape shpCOM 
      BorderStyle     =   3  'Dot
      FillColor       =   &H00FFFFFF&
      FillStyle       =   0  'Solid
      Height          =   495
      Left            =   9120
      Shape           =   3  'Circle
      Top             =   2640
      Width           =   615
   End
   Begin VB.Label Label9 
      Caption         =   "可用串口："
      BeginProperty Font 
         Name            =   "宋体"
         Size            =   14.25
         Charset         =   134
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      ForeColor       =   &H00C00000&
      Height          =   375
      Left            =   8760
      TabIndex        =   21
      Top             =   1560
      Width           =   1335
   End
   Begin VB.Label Label8 
      Caption         =   "串行通讯"
      BeginProperty Font 
         Name            =   "宋体"
         Size            =   21.75
         Charset         =   134
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   615
      Left            =   9360
      TabIndex        =   20
      Top             =   240
      Width           =   2175
   End
   Begin VB.Label Label1 
      Caption         =   "通道1:"
      BeginProperty Font 
         Name            =   "宋体"
         Size            =   15.75
         Charset         =   134
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      ForeColor       =   &H00C00000&
      Height          =   495
      Left            =   600
      TabIndex        =   19
      Top             =   1515
      Width           =   1335
   End
   Begin VB.Label Label7 
      Caption         =   "远程控制"
      BeginProperty Font 
         Name            =   "宋体"
         Size            =   21.75
         Charset         =   134
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   615
      Left            =   5280
      TabIndex        =   10
      Top             =   240
      Width           =   2175
   End
   Begin VB.Label Label6 
      Caption         =   "数据采集"
      BeginProperty Font 
         Name            =   "宋体"
         Size            =   21.75
         Charset         =   134
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   615
      Left            =   1440
      TabIndex        =   8
      Top             =   240
      Width           =   2175
   End
   Begin VB.Label Label5 
      Caption         =   "通道5:"
      BeginProperty Font 
         Name            =   "宋体"
         Size            =   15.75
         Charset         =   134
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      ForeColor       =   &H00C00000&
      Height          =   495
      Left            =   600
      TabIndex        =   7
      Top             =   6600
      Width           =   1215
   End
   Begin VB.Label Label4 
      Caption         =   "通道4:"
      BeginProperty Font 
         Name            =   "宋体"
         Size            =   15.75
         Charset         =   134
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      ForeColor       =   &H00C00000&
      Height          =   615
      Left            =   600
      TabIndex        =   6
      Top             =   5205
      Width           =   1455
   End
   Begin VB.Label Label3 
      Caption         =   "通道3:"
      BeginProperty Font 
         Name            =   "宋体"
         Size            =   15.75
         Charset         =   134
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      ForeColor       =   &H00C00000&
      Height          =   375
      Left            =   600
      TabIndex        =   5
      Top             =   4050
      Width           =   1335
   End
   Begin VB.Label Label2 
      Caption         =   "通道2:"
      BeginProperty Font 
         Name            =   "宋体"
         Size            =   15.75
         Charset         =   134
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      ForeColor       =   &H00C00000&
      Height          =   495
      Left            =   600
      TabIndex        =   4
      Top             =   2790
      Width           =   1335
   End
End
Attribute VB_Name = "Form1"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False

Dim Chanel As Byte
Dim HourNum As Byte
Dim MinuteNum As Byte
Dim SecondNum As Byte

Private Declare Sub Sleep Lib "kernel32.DLL" (ByVal dwMilliseconds As Long)

Private Sub Command2_Click()

End

End Sub

Private Sub Command3_Click()
Dim UsartData(1 To 3) As Byte
If MSComm1.PortOpen = False Then MSComm1.PortOpen = True
HourNum = Val(Hour(Now))
MinuteNum = Val(Minute(Now))
SecondNum = Val(Second(Now))
UsartData(1) = HourNum
UsartData(2) = MinuteNum
UsartData(3) = SecondNum
MSComm1.Output = UsartData
'MSComm1.PortOpen = False

End Sub

Private Sub Form_Load()
 '此处代码为寻找有效的串口，并自动打开，来源网络
 j = 0
    For i = 1 To 16 Step 1
    If MSComm1.PortOpen = True Then                  '先关闭串口
    MSComm1.PortOpen = False
    End If
    MSComm1.CommPort = i
    On Error Resume Next                            '说明当一个运行时错误发生时，控件转到紧接着发生错误的语句之后的语句，并在此继续运行。访问对象时要使用这种形式而不使用 On Error GoTo。
    MSComm1.PortOpen = True
    If Err.Number <> 8002 Then                      '无效的串口号。这样可以检测到虚拟串口，如果用Err.Number = 0的话检测不到虚拟串口
    If j = 0 Then
    j = i
    End If
    cboPort.AddItem "COM" & i                   '生成串口选择列表
    End If
    MSComm1.PortOpen = False
    Next i
    If j >= 1 Then
    cboPort.Text = "COM" & j                        '自动打开可用的最小串口号
    MSComm1.CommPort = j
    MSComm1.PortOpen = True
    cmdOpenCom.Caption = "串口已打开"
    shpCOM.FillColor = vbGreen
    If Err.Number = 8005 Then                       '串口已打开,vbExclamation '
    MSComm1.PortOpen = False
    cboPort.Text = ""
    cmdOpenCom.Caption = "串口已关闭"
    shpCOM.FillColor = vbRed
    End If
    End If
    
MSComm1.Settings = "9600,n,8,1"
MSComm1.InputMode = comInputModeBinary

'此处也比较重要，如果数据长度设置的不对，可能会导致下面的数组越界
MSComm1.InputLen = 3

MSComm1.SThreshold = 1

'每收到多少个字符产生一个事件
'此处数值应该设置小于等于实际每次缓冲区收到的数据个数
MSComm1.RThreshold = 1

'此处非常重要，必须要设置为无效，才不会让系统强制复位。
MSComm1.DTREnable = False
MSComm1.RTSEnable = False


End Sub


Private Sub MSComm1_OnComm()
'Dim InData As VariantTypeConstants
Dim a() As Byte

Select Case MSComm1.CommEvent
    Case comEvReceive
    '需要重新申明数组
    ReDim a(5) As Byte
    a = MSComm1.Input
    '从此处执行效果来看，缓冲区的三个数据应该是一起到来的
    Text1(Chanel).Text = Str(a(0)) + Str(a(1)) + Str(a(2))
    Chanel = (Chanel + 1) Mod 5
    MSComm1.RThreshold = 1
End Select

MSComm1.InBufferCount = 0

End Sub

Private Sub Timer1_Timer()
'Label12.Caption = Date
Label13.Caption = Time
End Sub
