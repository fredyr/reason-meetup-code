/*
   Reason

   - Everything is an expression
   - Expressions are terminated with a semicolon;

 */
/* Integer literals and arithmetics
    - : int
   */
1 + 3 * 5 / 2;

/* Float literals and float arithmetics have different operators
   No overloaded operators
   - : float
   */
1.0 +. 3.0 *. 5.0 /. 2.0;

/* No automatic coercions */
1. +. 3.3 -. float_of_int (1 + 3 * 5 / 2);

/* String literals and concatenation, not overloading +, uses ^ instead
   - : string
   */
"Strings " ^ " to be " ^ "concatenated";

/* Booleans
   - : bool
   */
true && false || 3 > 2;

/* Structural equality */
"String" == "String";

[[1], [3, 3]] == [[1], [3, 3]];

/* Referential equality (same object?) */
1 === 1;

let a = [1, 2, 3];

a === a;

/*
   LISTS

   - Immutable
   - Homogeneous
   - Lists are linked lists, that can be accessed from the front
   - : list int, list string etc

 */
/* Run the following three in JS */
let myList = [3, 14, 15, 92, 65, 35];

/* List prepend, O(1) - constant time */
let biggerList = [55, 66, ...myList];

/*
   Destructure a list

   - Warning because it will fail on empty lists
     => Use pattern matching instead



 */
let [hello, ...world] = myList;

/* List.hd, List.tl */
List.hd biggerList;

List.length biggerList;

/* We'll skip past Arrays and Tuples and only just mention them */
/*
   ARRAYS

   Arrays support random access
   and are mutable!

   - : array int
   - : array float
   etc
 */
let arr = [|3, 14, 15|];

/* Access element */
let first = arr.(1);

/* Update in place */
arr.(1) = 15;

/*
   TUPLES

   - Immutable
   - Heterogeneous
   - Ordered
   - Fixed size

 */
/* Triple of int, string, list float
   - : (int, string, list float)
   */
let t = (1, "two", [3.0]);

/*
   They can be destructured similarly.
   No direct access to one of the elems
 */
let (x, y, z) = t;

/*
   RECORDS

   - Immutable by default
   - Requires a type definition
 */
type book = {author: string, title: string};

let b = {author: "Umberto Eco", title: "Foucault's pendulum"};

/* Access as you would expect */
let title = b.title;

/* Spread operator to create new records */
let anotherBook = {...b, title: "Ill nome della rosa"};

/*
   DESTRUCTURING

   - The first part of pattern matching syntax
   - Taking a structure apart and create named bindings
 */
let {title: t, author: a} = anotherBook;

/*
   Nested destructuring,
   _ (underscore) can be used when you don't want to name something
 */
let listOfBooks = [b, {author: "whatever", title: "Da Vinci Code"}, anotherBook];

/* let [{title: t1}, _, {title: t2}] = listOfBooks; */
/*

   PATTERN MATCHING

   - combination of a switch/case and destructuring
   - when you need to cover different cases of destructuring

   Name punning
   - {title} is short for {title: title}
 */
let rec titles books =>
  switch books {
  | [] => []
  | [{title}, ...remainingBooks] => [title, ...titles remainingBooks]
  };

List.map (fun t => t.title) listOfBooks;

titles listOfBooks;

/* Name punning can be used for creating records */
let author = "Peter F. Hamilton";

let commonwealth = {title: "Pandora's Star", author};
