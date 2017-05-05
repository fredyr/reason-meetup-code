/*
   TYPES

   - Reason is strongly typed

     meaning that the type of every variable and every expression in a
     program is determined at compile-time. Programs that pass the type
     checker are safe

  - No automatic coercion of types, explicit conversion
  - Not even same operators for int/float
  - Types are automatically inferred, but always there, and checked by the compiler
  - You can provide them when convenient

 */
let i: int = 3;

let f: float = 1.0;

let l: list int = [1, 2, 3];

/*
   LET BINDINGS

   - scopes

 */
let a = 12;

let b = a + 1;

/*
   Lexical scope
   localA and localB can't be referenced from outside of the block
 */
let value = {
  /* Warning because value is shadowed below */
  let localA = 12;
  let localB = 24;
  localA + localB
};

/* Bindings are immutable, but can be shadowed */
let value = 3;

/*
   FUNCTIONS

   - First class values

 */
/*
   Anonymous function
   - In JS, arrow function expression
      ((x) => x + 1)(3);

 */
(fun x => x + 1) 3;

/*
   Named function
   - Sugar for
     let fx = fun x => x + 1;
 */
let fx x => x + 1;

let sumOfSquares x y => {
  let x2 = x * x;
  let y2 = y * y;
  x2 + y2
};

/* Version with written out type signature */
let sumOfSquaresTypeSig (x: int) (y: int) :int => sumOfSquares x y;

/*
    NAMED ARGUMENTS AND DEFAULTS

   `labeled arguments`
 */
let ceci = "Ceci n'est pas une string";

/* Code completion and documentation using Merlin */
String.sub ceci 2 6;

let subs s start::x len::y => String.sub s x y;

/* You can still apply as ordered args, but get a warning */
subs ceci 2 6;

subs ceci start::2 len::6;

/* ::start is short for start::start */
let subs s ::start ::len => String.sub s start len;

/*
   Use start=0 as default

   An optional argument must always be followed by an anonymous argument which is
   used to mark the end optional arguments

 */
let subsWithDefault ::start=0 ::len s => String.sub s start len;

subsWithDefault ceci len::10;

/*
   VARIANT TYPES
   - Sum types
   - Algebraic data type
   The value is either this or that.
 */
type size =
  | Small
  | Medium
  | Large;

/*
  Alternatives are given with capital initial letter separated by
  pipes.

  Small, Medium etc are called constructors.

  You can think of them as functions (in this case it doesn't take any arguments) and return a value of type size

 */
let swedishPreference = Medium;

/* Pattern match on variant types using switch */
let price (s: size) =>
  switch s {
  | Small => 10.0
  | Medium => 15.0
  | Large => 30.0
  };
/* Remove the Large pattern */
/*

    This concludes the language intro section
    Questions so far?

 */
