/*
   Javascript Workflow

   - It could be leaner, but I think this is a nice realistic example

   - package.json -- NPM is used to install all dependecies
     The only global installed is for editor support

   - bsconfig.json -- where Bucklescript finds the source

   - webpack.config.js -- bundles the javascript

 */
/*
  Reason supports the JSX syntax
 */
let text s => ReactRe.stringToElement s;

let coolDiv s => <div className="not-so-cool"> <span> (text s) </span> </div>;

/*
   Let's look at some generated Javascript

   - Readable output
   - Generate CommonJs modules
   - Easy to interop and bundle together with other Javascript

 */
let basicList = [1, 2, 3, 4];

/* Javascript Runtime representation for List is
     Arrays with head/tail
   */
let added = [99, ...basicList];

let value = {
  let localA = 12;
  let localB = 24;
  localA + localB
};

let myFun ::x ::y => String.sub "Other stuff, man" x y;

let arr = [|5.0, 63.0, 18.0|];

let incer x :float => x +. 20.;

let y = {
  let x = "interpolated";
  {j|a very
         this one is multi-lined yeahhh!
         weird $(x) string|j}
};
