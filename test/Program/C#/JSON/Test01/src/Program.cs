using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

using System.IO;

using Newtonsoft.Json;
using Newtonsoft.Json.Linq;

using Microsoft.CSharp;
using Microsoft.VisualBasic;
using System.CodeDom.Compiler;
using System.Reflection;

namespace Test01
{
    class Program
    {
        static void Main(string[] args)
        {
            testParser();
            testScript();
            
            const string base_dir = "E:\\Work\\GitHub\\public\\test\\Program\\C#\\JSON\\Test01\\";
            const string json_path = base_dir + "dataFormatTest.i.json";
            StreamReader reader = new StreamReader(json_path, Encoding.UTF8);
            String json_text = reader.ReadToEnd();
            reader.Close();
            reader = null;
            //Console.WriteLine(json_text);

            JObject json_obj_org = JObject.Parse(json_text);
            dynamic json_obj = json_obj_org;

            Console.WriteLine();
            Console.WriteLine("----------------------------------------");
            Console.WriteLine(json_obj);

            Console.WriteLine();
            Console.WriteLine("----------------------------------------");
            Console.WriteLine("json_obj.name = \"" + json_obj.name + "\"");
            Console.WriteLine("json_obj.mainStruct.name = \"" + json_obj.mainStruct.name + "\"");
            Console.WriteLine("json_obj.mainStruct.members[0].name = \"" + json_obj.mainStruct.members[0].name + "\"");
            Console.WriteLine("json_obj.subStructs[0].name = \"" + json_obj.subStructs[0].name + "\"");
            Console.WriteLine("json_obj.subStructs[0].members[0].name = \"" + json_obj.subStructs[0].members[0].name + "\"");
            Console.WriteLine("json_obj.rules[0].rule = \"" + json_obj.rules[0].rule + "\"");

#if true
            //Eval
            {
                Microsoft.JScript.Vsa.VsaEngine ve = Microsoft.JScript.Vsa.VsaEngine.CreateEngine();
                dynamic result = Microsoft.JScript.Eval.JScriptEvaluate("\"abc\" + \"def\"", ve);
                Console.WriteLine("eval() = " + result.ToString());
            }
#endif

#if true
            //C# Compiler
            {
                //C#スクリプト
                string cs_source = @"
                    using System;
                    using Newtonsoft.Json;
                    using Newtonsoft.Json.Linq;
                    public class CTest
                    {
                        public string checkRule001(JObject json_obj_org)
                        {
                            dynamic json_obj = json_obj_org;
                            System.Console.WriteLine(""Hello C# World!"");
                            //System.Console.WriteLine(obj.ToString());
                            System.Console.WriteLine(""json_obj_org.name=\"""" + json_obj_org.GetValue(""name"").ToString() + ""\"""");
                            System.Console.WriteLine(""json_obj.name=\"""" + json_obj.name + ""\"""");
                            var name = json_obj.name;
                            System.Console.WriteLine(""var name=\"""" + name + ""\"""");
                            json_obj.name = ""Update from CSharp"";
                            return ""エラーメッセージテスト！"";
                            //return null;
                        }
                    }
                ";

                //コンパイラパラメータ生成
                CompilerParameters param = new CompilerParameters();
                
                //コンパイラパラメータ設定
                param.GenerateExecutable = false;      // 実行ファイル（.exe）を作らない
                param.GenerateInMemory = true;         // メモリ上にプログラム（スクリプト）を生成
                param.IncludeDebugInformation = false; // デバッグ情報を付加しない
                
                //スクリプト内で使用する.Netアセンブリをコンパイラパラメータに追加
                //※以下の設定により、JSON.Net と dynamic 型が使用可能になる
                param.ReferencedAssemblies.Add("System.dll");
                param.ReferencedAssemblies.Add("System.Core.dll");
                param.ReferencedAssemblies.Add("Microsoft.CSharp.dll");
                param.ReferencedAssemblies.Add("Newtonsoft.Json.dll");

                //C#コンパイラ生成
                CSharpCodeProvider provider = new CSharpCodeProvider();
                
                //C#スクリプトをコンパイル
                CompilerResults result = provider.CompileAssemblyFromSource(param, cs_source);
                if (result.Errors.Count > 0)
                {
                    //コンパイルエラーあり
                    Console.WriteLine("コンパイルエラー数 = " + result.Errors.Count);
                    foreach (var err in result.Errors)
                    {
                        Console.WriteLine("コンパイルエラー:" + err.ToString());
                    }
                }
                else
                {
                    //コンパイルエラーなし
                    
                    //スクリプト内の型（クラス）情報を取得
                    Type type = result.CompiledAssembly.GetType("CTest");
                    //Console.WriteLine(type.ToString());

                    //インスタンスを生成（コンストラクタ呼び出し）
                    dynamic script_obj = type.GetConstructors()[0].Invoke(new Object[0]);
                    
                    //メソッド呼び出し
                    string message = script_obj.checkRule001(json_obj);
                    if(message != null)
                    {
                        Console.WriteLine("エラー！:\"{0}\"", message);
                    }
                }
            }
#endif

#if true
            //VB Compiler
            {
                //Visual Basicスクリプト
                string vb_source = @"
                    Imports System
                    Imports Newtonsoft.Json
                    Imports Newtonsoft.Json.Linq
                    Public Class CTest
                        public Function checkRule001(ByVal json_obj_org As JObject) As String
                            Dim json_obj As Object = json_obj_org
                            System.Console.WriteLine(""Hello VB World!"")
                            'System.Console.WriteLine(obj.ToString())
                            System.Console.WriteLine(""json_obj_org.name="""""" + json_obj_org.GetValue(""name"").ToString() + """""""")
                            'System.Console.WriteLine(""json_obj.name="""""" + json_obj.name + """""""")
                            'Dim name = json_obj.name;
                            'System.Console.WriteLine(""Dim name=\"""" + name + ""\"""");
                            'json_obj.name = ""Update from VBCodeProvider""
                            Return ""エラーメッセージテスト！""
                            'Return Nothing
                        End Function
                    End Class
                ";

                //コンパイラパラメータ生成
                CompilerParameters param = new CompilerParameters();
                
                //コンパイラパラメータ設定
                param.GenerateExecutable = false;      // 実行ファイル（.exe）を作らない
                param.GenerateInMemory = true;         // メモリ上にプログラム（スクリプト）を生成
                param.IncludeDebugInformation = false; // デバッグ情報を付加しない
                
                //スクリプト内で使用する.Netアセンブリをコンパイラパラメータに追加
                //※以下の設定により、JSON.Net が使用可能になる
                param.ReferencedAssemblies.Add("System.dll");
                param.ReferencedAssemblies.Add("System.Core.dll");
                param.ReferencedAssemblies.Add("Microsoft.VisualBasic.dll");
                param.ReferencedAssemblies.Add("Newtonsoft.Json.dll");

                //Visual Basicコンパイラ生成
                VBCodeProvider provider = new VBCodeProvider();
                
                //Visual Basicスクリプトをコンパイル
                CompilerResults result = provider.CompileAssemblyFromSource(param, vb_source);
                if (result.Errors.Count > 0)
                {
                    //コンパイルエラーあり
                    Console.WriteLine("コンパイルエラー数 = " + result.Errors.Count);
                    foreach (var err in result.Errors)
                    {
                        Console.WriteLine("コンパイルエラー:" + err.ToString());
                    }
                }
                else
                {
                    //コンパイルエラーなし
                    
                    //スクリプト内の型（クラス）情報を取得
                    Type type = result.CompiledAssembly.GetType("CTest");
                    //Console.WriteLine(type.ToString());
                    
                    //インスタンスを生成（コンストラクタ呼び出し）
                    dynamic script_obj = type.GetConstructors()[0].Invoke(new Object[0]);
                    
                    //メソッド呼び出し
                    string message = script_obj.checkRule001(json_obj);
                    if (message != null)
                    {
                        Console.WriteLine("エラー！:\"{0}\"", message);
                    }
                }
            }
#endif

#if false
            {
                PropertyInfo pi = json_obj.GetProperty("name");
                MethodInfo o = pi.GetGetMethod();
                Console.WriteLine(o.Invoke(o, null));
            }
#endif
        }

        //JSONパーサーテスト
        static void testParser()
        {
            //JSONテキスト
            string json_text = @"
                    {
                        ""data1"":
                        [
                            { ""id"": ""c0010"", ""name"": ""田中"", },
                            { ""id"": ""c0020"", ""name"": ""山田"", },
                            { ""id"": ""c0030"", ""name"": ""佐藤"", },
                        ],
                        ""data2"":
                        [
                            [1, 2, 3],
                            [4, 5, 6],
                            [7, 8, 9, 10],
                        ]
                    }
                    ";

            //JSONテキストを解析
            //※本来は JObject 型を返すが、dynamic型（動的型付け）でないと、
            //　遅延バインディングが行われないため、コンパイル時にエラーになってしまう。
            dynamic json_obj = JObject.Parse(json_text);

            //dynamic型を使用することにより、型宣言せずに、
            //JSON内で定義されたメンバーに直接アクセスが可能
            Console.WriteLine();
            Console.WriteLine("data1[0].id=\"{0}\"", json_obj.data1[0].id);
            Console.WriteLine("data1[2].name=\"{0}\"", json_obj.data1[2].name);
            Console.WriteLine("data2[2][3]={0}", json_obj.data2[2][3]);

            //foreach も使用可
            Console.WriteLine();
            Console.WriteLine("data1=[");
            foreach (dynamic rec in json_obj.data1)
            {
                Console.WriteLine(" {{ id=\"{0}\", name=\"{1}\" }},", rec.id, rec.name);
            }
            Console.WriteLine("]");

            //foreach のネストも使用可
            Console.WriteLine();
            Console.WriteLine("data2=[");
            foreach (dynamic array1 in json_obj.data2)
            {
                Console.Write(" [");
                foreach (dynamic array2 in array1)
                {
                    Console.Write(array2 + ",");
                }
                Console.WriteLine("]");
            }
            Console.WriteLine("]");
        }

        //C#スクリプト＋JSON＋dynamic型テスト
        static void testScript()
        {
            //JSONテキスト
            string json_text = @"
                    {
                     ""name"": ""田中"",
                     ""data"": 10
                    }
                ";

            //JSONオブジェクト生成
            dynamic json_obj = JObject.Parse(json_text);

            //C#スクリプト
            string cs_source = @"
                    using System;
                    using Newtonsoft.Json;
                    using Newtonsoft.Json.Linq;
                    public class CScriptTest
                    {
                        public string checkJSONData(dynamic json_obj)
                        {
                            //スクリプト内で直接JSON解析済みオブジェクトにアクセス
                            string msg = ""スクリプト内のメッセージテキスト("" + json_obj.data + "")"";
                            json_obj.name += ""さん"";
                            json_obj.data += 1;
                            return msg;
                        }
                    }
                ";

            //コンパイラパラメータ生成
            CompilerParameters param = new CompilerParameters();

            //コンパイラパラメータ設定
            param.GenerateExecutable = false;      // 実行ファイル（.exe）を作らない
            param.GenerateInMemory = true;         // メモリ上にプログラム（スクリプト）を生成
            param.IncludeDebugInformation = false; // デバッグ情報を付加しない

            //スクリプト内で使用する.Netアセンブリをコンパイラパラメータに追加
            //※以下の設定により、JSON.Net と dynamic 型が使用可能になる
            param.ReferencedAssemblies.Add("System.dll");
            param.ReferencedAssemblies.Add("System.Core.dll");
            param.ReferencedAssemblies.Add("Microsoft.CSharp.dll");
            param.ReferencedAssemblies.Add("Newtonsoft.Json.dll");

            //C#コンパイラ生成
            CSharpCodeProvider provider = new CSharpCodeProvider();

            //C#スクリプトをコンパイル
            CompilerResults script_prog = provider.CompileAssemblyFromSource(param, cs_source);
            if (script_prog.Errors.Count > 0)
            {
                //コンパイルエラーあり
                Console.WriteLine("コンパイルエラー数 = " + script_prog.Errors.Count);
                foreach (var err in script_prog.Errors)
                {
                    Console.WriteLine("コンパイルエラー:" + err.ToString());
                }
            }
            else
            {
                //コンパイルエラーなし

                //スクリプト内の型（クラス）情報を取得
                Type script_class = script_prog.CompiledAssembly.GetType("CScriptTest");
                
                //インスタンスを生成（コンストラクタ呼び出し：パラメータなしコンストラクタ呼び出しのケース）
                dynamic script_obj = script_class.GetConstructors()[0].Invoke(new Object[0]);

                //実行前状態表示
                Console.WriteLine();
                Console.WriteLine("実行前：json_objd.name=\"{0}\", .data={1}", json_obj.name, json_obj.data);

                //スクリプト内のメソッド呼び出し　※JSONテキスト解析済みオブジェクトを受け渡し
                string ret_msg = script_obj.checkJSONData(json_obj);

                //実行後結果表示
                Console.WriteLine();
                Console.WriteLine("実行後：json_objd.name=\"{0}\", .data={1}", json_obj.name, json_obj.data);
                if(ret_msg != null)
                {
                    Console.WriteLine("  戻り値=\"{0}\"", ret_msg);
                }
            }
        }
    }
}
