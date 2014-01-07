// F# の詳細については、http://fsharp.net を参照してください
// 詳細については、'F# チュートリアル' プロジェクトを参照してください。

type Vector2D(dx:float,dy:float) = 
    let length = sqrt(dx*dx + dy*dy)
    member obj.Length = length
    member obj.DX = dx
    member obj.DY = dy
    member obj.Move(dx2,dy2) = Vector2D(dx+dx2,dy+dy2)

[<EntryPoint>]
let main argv = 
    printfn "test = \"%A\"" argv
    let results = [ for i in 0 .. 10 -> (i, i*i) ]
    printfn "results = %A" results
    let x = new Vector2D(dx=10., dy=20.)
    printfn "x.Length = %A" x.Length
    printfn "x.DX = %A" x.DX
    printfn "x.DY = %A" x.DY
    0 // 整数の終了コードを返します


