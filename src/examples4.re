/*
   Javascript Interop is very simple

   - Describe the type signature, and the name bindings
   - In this case, both the module and function name

   - Conversely is similarly simple to call a Reason function
     from Javascript, see example5.re

 */
external incBy3 : int => int = "incBy3" [@@bs.module "interop"];

Js.log ("From Reason: " ^ string_of_int (incBy3 7));

Js.log @@ Js_date.now ();
