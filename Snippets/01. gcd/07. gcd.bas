$Debug


Dim x As Integer
Dim y As Integer
Dim z As Integer

x = 2500
y = 45
z = gcd(x, y)

Print "GCD of" + Str$(x) + " and " + Str$(y) + " =" + Str$(z) + "."


Function gcd (u, v)
    Dim t As Integer
    While (u > 0)
        If (u < v) Then
            t = u
            u = v
            v = t
        End If
        u = u - v
    Wend
    gcd = v
End Function
