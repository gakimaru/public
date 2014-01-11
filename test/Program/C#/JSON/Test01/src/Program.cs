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
            const string base_dir = "E:\\Work\\GitHub\\public\\test\\Program\\C#\\JSON\\Test01\\";
            const string json_path = base_dir + "dataFormatTest.i.json";
            StreamReader reader = new StreamReader(json_path, Encoding.UTF8);
            String json_text = reader.ReadToEnd();
            reader.Close();
            reader = null;
            //Console.WriteLine(json_text);

            JObject json_obj_org = JObject.Parse(json_text);
            dynamic json_obj = json_obj_org;

            Console.WriteLine("----------------------------------------");
            Console.WriteLine(json_obj);

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
                //C#
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

                CompilerParameters param = new CompilerParameters();
                param.GenerateExecutable = false; // exe を作らない
                param.GenerateInMemory = true;    // exe を作らない
                param.IncludeDebugInformation = false;  // デバッグ情報を付加しない
                param.ReferencedAssemblies.Add("System.dll");
                param.ReferencedAssemblies.Add("System.Core.dll");
                param.ReferencedAssemblies.Add("Microsoft.CSharp.dll");
                param.ReferencedAssemblies.Add("Newtonsoft.Json.dll");

                CSharpCodeProvider provider = new CSharpCodeProvider();
                CompilerResults result = provider.CompileAssemblyFromSource(param, cs_source);
                if (result.Errors.Count > 0)
                {
                    Console.WriteLine("コンパイルエラー数 = " + result.Errors.Count);
                    foreach (var err in result.Errors)
                    {
                        Console.WriteLine("コンパイルエラー:" + err.ToString());
                    }
                }
                else
                {
                    Type type = result.CompiledAssembly.GetType("CTest");
                    //Console.WriteLine(type.ToString());
                    dynamic script_obj = type.GetConstructors()[0].Invoke(new Object[0]);
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
                //Visual Basic
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

                CompilerParameters param = new CompilerParameters();
                param.GenerateExecutable = false; // exe を作らない
                param.GenerateInMemory = true;    // exe を作らない
                param.IncludeDebugInformation = false;  // デバッグ情報を付加しない
                param.ReferencedAssemblies.Add("System.dll");
                param.ReferencedAssemblies.Add("System.Core.dll");
                param.ReferencedAssemblies.Add("Microsoft.VisualBasic.dll");
                param.ReferencedAssemblies.Add("Newtonsoft.Json.dll");

                VBCodeProvider provider = new VBCodeProvider();
                CompilerResults result = provider.CompileAssemblyFromSource(param, vb_source);
                if (result.Errors.Count > 0)
                {
                    Console.WriteLine("コンパイルエラー数 = " + result.Errors.Count);
                    foreach (var err in result.Errors)
                    {
                        Console.WriteLine("コンパイルエラー:" + err.ToString());
                    }
                }
                else
                {
                    Type type = result.CompiledAssembly.GetType("CTest");
                    //Console.WriteLine(type.ToString());
                    dynamic script_obj = type.GetConstructors()[0].Invoke(new Object[0]);
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
    }
}
