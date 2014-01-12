//JSONテキストをロード
function loadJSON(file_path)
{
	var ForReading = 1, ForWriting = 2;
	var fs = new ActiveXObject("Scripting.FileSystemObject");
	var file = fs.OpenTextFile(file_path, ForReading, true);
	var json_text = file.ReadAll();
	file.Close();
	return json_text;
}

//JSONテキストをパースしてJSONオブジェクトを返す
function parseJSON(json_text)
{
	//eval() 実行の際、JSONテキストを「(」～「)」で囲む必要がある
	var json_obj = eval("(" + json_text + ")");
	return json_obj;
}

//JSONオブジェクトの配列を表示
function printObjs(json_obj)
{
	for(idx in json_obj.arr)
	{
		var obj = json_obj.arr[idx];
		WScript.echo("[" + idx + "]{");
		WScript.echo("\tid=" + obj.id);
		WScript.echo("\tname=\"" + obj.name + "\"");
		WScript.echo("\tparam=");
		WScript.echo("\t\tstr=" + obj.param.str);
		WScript.echo("\t\tvit=" + obj.param.vit);
		WScript.echo("\t\text=[" + obj.param.ext[0] + ", " + obj.param.ext[1] + ", " + obj.param.ext[2] + "]");
		WScript.echo("\t\tis_boss=" + obj.param.is_boss);
		WScript.echo("}");
	}
}

//テストメイン
function testMain()
{
	var json_text = loadJSON("test.json");
	var json_obj = parseJSON(json_text);
	printObjs(json_obj);
}

//実行
testMain();
