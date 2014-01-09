function loadJSON(file_path)
{
	var ForReading = 1, ForWriting = 2;
	var fs = new ActiveXObject("Scripting.FileSystemObject");
	var file = fs.OpenTextFile(file_path, ForReading, true);
	var json = file.ReadAll();
	file.Close();
	return json;
}

function parseJSON(json)
{
	var obj = eval("(" + json + ")");
	return obj;
}

function printObjs(objs)
{
	for(no in objs)
	{
		var obj = objs[no];
		WScript.echo("[" + no + "]{");
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

function testMain()
{
	var json = loadJSON("test.json");
	var objs = parseJSON(json);
	printObjs(objs);
}

testMain();
