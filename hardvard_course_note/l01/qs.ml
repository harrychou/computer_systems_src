let rec qs = function
     | []    -> []
     | x::xs ->
           let left  = List.filter (fun y -> y < x)  xs
           and right = List.filter (fun y -> y >= x) xs
           in  (qs left) @ [x] @ (qs right);;
