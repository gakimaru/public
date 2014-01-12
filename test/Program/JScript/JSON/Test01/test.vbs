'JSONテキストをロード
'Public Function loadJSON(ByVal file_path As String) As String
Public Function loadJSON(ByVal file_path)
    Dim json_text' As String
    'Const ForReading As Long = 1, ForWriting As Long = 2
    Const ForReading = 1, ForWriting = 2
    Dim fs' As Object 'ScriptingFileSystemObject
    Set fs = CreateObject("Scripting.FileSystemObject")
    Set file = fs.OpenTextFile(file_path, ForReading, True)
    json_text = file.ReadAll()
    file.Close
    loadJSON = json_text
End Function

'JSONテキストをパースしてJSONオブジェクトを返す
'Public Function parseJSON(ByVal json_text As String) As Object
Public Function parseJSON(ByVal json_text)' As String) As Object
    Dim scr_ctrl' As Object 'MSScriptControl.ScriptControl
    Set scr_ctrl = CreateObject("MSScriptControl.ScriptControl") '【？】なぜか不可
    scr_ctrl.Language = "JScript" 'スクリプトの言語にJScript（Microsoft独自拡張仕様版のJavaScript）を指定
    
    '「(」~「)」でJSONテキストを囲む必要がある
    Dim json_obj' As Object
    Set json_obj = scr_ctrl.Eval("(" + json_text + ")")
    'Set json_obj = Eval("(" + json_text + ")")'※【不可】VBScriptのeval()ではJSON解析不可
    Set parseJSON = json_obj
End Function

'JSONオブジェクトの配列を表示
'Public Sub printObjs(ByVal json_obj As Object)
Public Sub printObjs(ByVal json_obj)
    Dim idx' As Long
    Dim obj' As Object
    idx = 0
    For Each obj In json_obj.arr '.arr:オブジェクトのメンバーには直接アクセス可
        Debug.Print "[" & idx & "]{"
        Debug.Print vbTab & "id=" & CallByName(obj, "id", VbGet) '配列のオブジェクトには CallByName() でアクセスする必要あり
        Debug.Print vbTab & "name=""" & CallByName(obj, "name", VbGet) & """"
        Debug.Print vbTab & "param="
        Dim param_obj' As Object
        Set param_obj = CallByName(obj, "param", VbGet)
        Debug.Print vbTab & vbTab & "str=" & CallByName(param_obj, "str", VbGet) '"str"がIDE上で"Str"になってしまい、大文字小文字が不一致で値が取得できなくなるので、CallByName() を使用
        Debug.Print vbTab & vbTab & "vit=" & param_obj.vit 'オブジェクトのメンバーには直接アクセス可
        Debug.Print vbTab & vbTab & "ext=[" & CallByName(param_obj.ext, "0", VbGet) & ", " & CallByName(param_obj.ext, "1", VbGet) & ", " & CallByName(param_obj.ext, "2", VbGet) & "]" '配列の値へのアクセスにもやはり CallByName() が必要
        Debug.Print vbTab & vbTab & "is_boss=" & obj.param.is_boss
        Debug.Print "}"
        idx = idx + 1
    Next' obj
End Sub

'テストメイン
Public Sub testMain()
    Dim json_text' As String
    Dim json_obj' As Object
    json_text = loadJSON("test.json")
    Set json_obj = parseJSON(json_text)
    printObjs json_obj
End Sub

'実行
testMain
